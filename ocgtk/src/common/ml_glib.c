/**************************************************************************/
/*                ocgtk - OCaml bindings for GTK4                         */
/*                                                                        */
/*    This program is free software; you can redistribute it              */
/*    and/or modify it under the terms of the GNU Library General         */
/*    Public License version 2, as published by the           */
/*    Free Software Foundation with the exception described in file       */
/*    COPYING which comes with the library.                               */
/*                                                                        */
/*    Based on lablgtk3 /https://github.com/garrigue/lablgtk/             */
/*                                                                        */
/**************************************************************************/

/* Minimal GLib C bindings for ocgtk
 *
 * This file provides basic GLib functionality needed for GTK4:
 * - Application name get/set
 * - Program name get/set
 * - List conversions (GList/GSList <-> OCaml list)
 * - Error handling (GError)
 *
 * Additional GLib bindings (main loop, I/O channels, etc.) will be
 * added in Phase 2.
 */

#include <string.h>
#include <locale.h>
#include <glib.h>
#include <gtk/gtk.h>

#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/threads.h>

#include "wrappers.h"

/* ==================================================================== */
/* GLib Initialization */
/* ==================================================================== */

CAMLprim value ml_glib_init(value unit)
{
    CAMLparam1(unit);
    /* Initialize GLib error domain mappings */
    /* More error domains will be registered as needed */
    CAMLreturn(Val_unit);
}

/* ==================================================================== */
/* Application/Program Name Functions */
/* ==================================================================== */

CAMLprim value ml_g_get_prgname(value unit)
{
    CAMLparam1(unit);
    CAMLlocal1(res);

    const char *name = g_get_prgname();
    if (name == NULL)
        CAMLreturn(Val_int(0)); /* None */
    else {
        res = caml_alloc(1, 0); /* Some */
        Store_field(res, 0, caml_copy_string(name));
        CAMLreturn(res);
    }
}

CAMLprim value ml_g_set_prgname(value name)
{
    CAMLparam1(name);
    g_set_prgname(String_val(name));
    CAMLreturn(Val_unit);
}

CAMLprim value ml_g_get_application_name(value unit)
{
    CAMLparam1(unit);
    CAMLlocal1(res);

    const char *name = g_get_application_name();
    if (name == NULL)
        CAMLreturn(Val_int(0)); /* None */
    else {
        res = caml_alloc(1, 0); /* Some */
        Store_field(res, 0, caml_copy_string(name));
        CAMLreturn(res);
    }
}

CAMLprim value ml_g_set_application_name(value name)
{
    CAMLparam1(name);
    g_set_application_name(String_val(name));
    CAMLreturn(Val_unit);
}

/* ==================================================================== */
/* List Conversion Utilities */
/* ==================================================================== */

/* Convert GList to OCaml list */
CAMLprim value Val_GList(GList *list, value (*func)(gpointer))
{
    CAMLparam0();
    CAMLlocal3(res, cons, tmp);

    res = Val_emptylist;
    GList *tmp_list = g_list_last(list);

    while (tmp_list != NULL) {
        tmp = func(tmp_list->data);
        cons = caml_alloc_small(2, 0);
        Field(cons, 0) = tmp;
        Field(cons, 1) = res;
        res = cons;
        tmp_list = tmp_list->prev;
    }

    CAMLreturn(res);
}

/* Convert GList to OCaml list and free the GList */
CAMLprim value Val_GList_free(GList *list, value (*func)(gpointer))
{
    CAMLparam0();
    CAMLlocal1(res);

    res = Val_GList(list, func);
    g_list_free(list);
    CAMLreturn(res);
}

/* Convert OCaml list to GList */
CAMLprim GList *GList_val(value list, gpointer (*func)(value))
{
    GList *res = NULL;

    while (list != Val_emptylist) {
        /* Validate list cell structure */
        if (!Is_block(list) || Wosize_val(list) < 2) {
            g_list_free(res);
            caml_invalid_argument("GList_val: malformed list");
        }
        res = g_list_prepend(res, func(Field(list, 0)));
        list = Field(list, 1);
    }

    return g_list_reverse(res);
}

/* Convert GSList to OCaml list
 * Note: GSList is a singly-linked list (no ->prev pointer)
 */
CAMLprim value Val_GSList(GSList *list, value (*func)(gpointer))
{
    CAMLparam0();
    CAMLlocal3(res, cons, tmp);

    res = Val_emptylist;

    /* Build list in reverse by collecting elements first */
    GList *glist = NULL;
    GSList *tmp_list = list;
    while (tmp_list != NULL) {
        glist = g_list_prepend(glist, tmp_list->data);
        tmp_list = tmp_list->next;
    }

    /* Now convert in reverse order */
    GList *g = glist;
    while (g != NULL) {
        tmp = func(g->data);
        cons = caml_alloc_small(2, 0);
        Field(cons, 0) = tmp;
        Field(cons, 1) = res;
        res = cons;
        g = g->next;
    }

    g_list_free(glist);
    CAMLreturn(res);
}

/* Convert GSList to OCaml list and free the GSList */
CAMLprim value Val_GSList_free(GSList *list, value (*func)(gpointer))
{
    CAMLparam0();
    CAMLlocal1(res);

    res = Val_GSList(list, func);
    g_slist_free(list);
    CAMLreturn(res);
}

/* Convert OCaml list to GSList */
CAMLprim GSList *GSList_val(value list, gpointer (*func)(value))
{
    GSList *res = NULL;

    while (list != Val_emptylist) {
        /* Validate list cell structure */
        if (!Is_block(list) || Wosize_val(list) < 2) {
            g_slist_free(res);
            caml_invalid_argument("GSList_val: malformed list");
        }
        res = g_slist_prepend(res, func(Field(list, 0)));
        list = Field(list, 1);
    }

    return g_slist_reverse(res);
}

/* ==================================================================== */
/* Error Handling (GError) */
/* ==================================================================== */

/* Raise OCaml exception from GError */
CAMLprim void ml_raise_gerror(GError *err)
{
    static const value *exn = NULL;
    CAMLparam0();
    CAMLlocal1(arg);

    if (exn == NULL)
        exn = caml_named_value("gerror");

    /* caml_alloc (not caml_alloc_small) + Store_field: caml_alloc_small leaves
     * the fields uninitialized, so the caml_copy_string below — which
     * allocates, and can therefore trigger a minor collection — would have the
     * GC scan field 1 as a garbage value. This is the same crash class as the
     * naked GValue* in ml_closure_marshal, here on the GError path.
     * caml_alloc fills scannable blocks with Val_unit before returning. */
    if (err) {
        arg = caml_alloc(2, 0);
        Store_field(arg, 0, Val_int(err->code));
        Store_field(arg, 1, caml_copy_string(err->message));
        g_error_free(err);
    } else {
        arg = caml_alloc(2, 0);
        Store_field(arg, 0, Val_int(0));
        Store_field(arg, 1, caml_copy_string("Unknown GLib error"));
    }

    caml_raise_with_arg(*exn, arg);
    CAMLreturn0;
}

/* ==================================================================== */
/* String Utilities */
/* ==================================================================== */

/* Copy a NULL-terminated array of strings to OCaml string list */
value copy_string_v(const gchar * const *v)
{
    CAMLparam0();
    CAMLlocal4(h, p, c, s);

    h = p = Val_emptylist;
    while (*v != NULL) {
        s = caml_copy_string(*v);
        c = caml_alloc_small(2, 0);
        Field(c, 0) = s;
        Field(c, 1) = Val_emptylist;
        if (p == Val_emptylist)
            h = c;
        else
            Store_field(p, 1, c);
        p = c;
        v++;
    }

    CAMLreturn(h);
}

/* Copy a string and free it with g_free */
CAMLprim value copy_string_g_free(char *str)
{
    CAMLparam0();
    CAMLlocal1(res);

    res = caml_copy_string(str != NULL ? str : "");
    g_free(str);
    CAMLreturn(res);
}

/* Check if string is NULL and copy appropriately */
value copy_string_check(const char *str)
{
    if (str == NULL)
        return caml_copy_string("");
    else
        return caml_copy_string(str);
}

/* ==================================================================== */
/* Main Event Loop */
/* ==================================================================== */

/* Helper: Wrap GMainLoop pointer in OCaml abstract block.
 * Uses a 1-word Abstract block; reader and writer both use Data_abstract_val
 * for consistency (the old reader used Field(val,0) which happened to coincide
 * on 64-bit but was technically incorrect). */
static value Val_GMainLoop(GMainLoop *loop)
{
    CAMLparam0();
    CAMLlocal1(val);
    val = caml_alloc(1, Abstract_tag);
    *((GMainLoop **)Data_abstract_val(val)) = loop;
    CAMLreturn(val);
}

/* Helper: Extract GMainLoop pointer from OCaml abstract block */
static GMainLoop *GMainLoop_val(value val)
{
    return *((GMainLoop **)Data_abstract_val(val));
}

/* Create a new main loop */
CAMLprim value ml_g_main_new(value is_running)
{
    CAMLparam1(is_running);
    GMainLoop *loop = g_main_loop_new(NULL, Bool_val(is_running));
    if (loop == NULL)
        caml_failwith("g_main_loop_new: failed to create main loop");
    CAMLreturn(Val_GMainLoop(loop));
}

/* Run a main loop */
CAMLprim value ml_g_main_run(value loop)
{
    CAMLparam1(loop);
    g_main_loop_run(GMainLoop_val(loop));
    CAMLreturn(Val_unit);
}

/* Check if main loop is running */
CAMLprim value ml_g_main_is_running(value loop)
{
    CAMLparam1(loop);
    CAMLreturn(Val_bool(g_main_loop_is_running(GMainLoop_val(loop))));
}

/* Quit a main loop */
CAMLprim value ml_g_main_quit(value loop)
{
    CAMLparam1(loop);
    g_main_loop_quit(GMainLoop_val(loop));
    CAMLreturn(Val_unit);
}

/* Destroy/unref a main loop */
CAMLprim value ml_g_main_destroy(value loop)
{
    CAMLparam1(loop);
    g_main_loop_unref(GMainLoop_val(loop));
    CAMLreturn(Val_unit);
}

/* Run one iteration of the main context (updated for GTK4/GLib 2.66+) */
CAMLprim value ml_g_main_iteration(value may_block)
{
    CAMLparam1(may_block);
    gboolean result;
    /* Don't release runtime - callbacks need it, and non-blocking is fast */
    result = g_main_context_iteration(NULL, Bool_val(may_block));
    CAMLreturn(Val_bool(result));
}

/* Check if events are pending (updated for GTK4/GLib 2.66+) */
CAMLprim value ml_g_main_pending(value unit)
{
    CAMLparam1(unit);
    CAMLreturn(Val_bool(g_main_context_pending(NULL)));
}

/* ==================================================================== */
/* Timeout and Idle Callbacks */
/* ==================================================================== */

/* Callback data structure for timeout/idle */
typedef struct {
    value closure;
} ml_callback_data;

/* Generic callback function for timeout/idle */
static gboolean ml_callback_func(gpointer data)
{
    CAMLparam0();
    CAMLlocal1(ret);
    ml_callback_data *cbd = (ml_callback_data *)data;

    ret = caml_callback(cbd->closure, Val_unit);

    CAMLreturnT(gboolean, Bool_val(ret));
}

/* Destroy notify for callback data */
static void ml_callback_destroy(gpointer data)
{
    ml_callback_data *cbd = (ml_callback_data *)data;
    caml_remove_global_root(&cbd->closure);
    g_free(cbd);
}

/* Add a timeout callback */
CAMLprim value ml_g_timeout_add(value o_prio, value interval, value clos)
{
    CAMLparam3(o_prio, interval, clos);
    ml_callback_data *cbd = g_new(ml_callback_data, 1);
    guint id;

    /* Check allocation success */
    if (cbd == NULL) {
        caml_raise_out_of_memory();
    }

    cbd->closure = clos;
    caml_register_global_root(&cbd->closure);

    if (o_prio == Val_none) {
        id = g_timeout_add_full(G_PRIORITY_DEFAULT,
                                 Int_val(interval),
                                 ml_callback_func,
                                 cbd,
                                 ml_callback_destroy);
    } else {
        id = g_timeout_add_full(Int_val(Some_val(o_prio)),
                                 Int_val(interval),
                                 ml_callback_func,
                                 cbd,
                                 ml_callback_destroy);
    }

    CAMLreturn(Val_int(id));
}

/* Remove a timeout */
CAMLprim value ml_g_timeout_remove(value id)
{
    CAMLparam1(id);
    CAMLreturn(Val_bool(g_source_remove(Int_val(id))));
}

/* Add an idle callback */
CAMLprim value ml_g_idle_add(value o_prio, value clos)
{
    CAMLparam2(o_prio, clos);
    ml_callback_data *cbd = g_new(ml_callback_data, 1);
    guint id;

    /* Check allocation success */
    if (cbd == NULL) {
        caml_raise_out_of_memory();
    }

    cbd->closure = clos;
    caml_register_global_root(&cbd->closure);

    if (o_prio == Val_none) {
        id = g_idle_add_full(G_PRIORITY_DEFAULT_IDLE,
                              ml_callback_func,
                              cbd,
                              ml_callback_destroy);
    } else {
        id = g_idle_add_full(Int_val(Some_val(o_prio)),
                              ml_callback_func,
                              cbd,
                              ml_callback_destroy);
    }

    CAMLreturn(Val_int(id));
}

/* Remove an idle callback */
CAMLprim value ml_g_idle_remove(value id)
{
    CAMLparam1(id);
    CAMLreturn(Val_bool(g_source_remove(Int_val(id))));
}

/* ==================================================================== */
/* UTF-8 and String Conversion */
/* ==================================================================== */

/* Validate UTF-8 string */
CAMLprim value ml_g_utf8_validate(value str)
{
    CAMLparam1(str);
    const char *s = String_val(str);
    gsize len = caml_string_length(str);
    CAMLreturn(Val_bool(g_utf8_validate(s, len, NULL)));
}

/* Convert string between character sets */
CAMLprim value ml_g_convert(value str, value to_codeset, value from_codeset)
{
    CAMLparam3(str, to_codeset, from_codeset);
    CAMLlocal1(result);
    GError *err = NULL;
    gchar *converted;
    gsize bytes_read, bytes_written;

    converted = g_convert(String_val(str),
                          caml_string_length(str),
                          String_val(to_codeset),
                          String_val(from_codeset),
                          &bytes_read,
                          &bytes_written,
                          &err);

    if (err != NULL) {
        ml_raise_gerror(err);
    }

    result = caml_copy_string(converted != NULL ? converted : "");
    g_free(converted);

    CAMLreturn(result);
}

/* Convert locale to UTF-8 */
CAMLprim value ml_g_locale_to_utf8(value str)
{
    CAMLparam1(str);
    CAMLlocal1(result);
    GError *err = NULL;
    gchar *converted;
    gsize bytes_read, bytes_written;

    converted = g_locale_to_utf8(String_val(str),
                                   caml_string_length(str),
                                   &bytes_read,
                                   &bytes_written,
                                   &err);

    if (err != NULL) {
        ml_raise_gerror(err);
    }

    result = caml_copy_string(converted != NULL ? converted : "");
    g_free(converted);

    CAMLreturn(result);
}

/* Convert UTF-8 to locale */
CAMLprim value ml_g_locale_from_utf8(value str)
{
    CAMLparam1(str);
    CAMLlocal1(result);
    GError *err = NULL;
    gchar *converted;
    gsize bytes_read, bytes_written;

    converted = g_locale_from_utf8(String_val(str),
                                     caml_string_length(str),
                                     &bytes_read,
                                     &bytes_written,
                                     &err);

    if (err != NULL) {
        ml_raise_gerror(err);
    }

    result = caml_copy_string(converted != NULL ? converted : "");
    g_free(converted);

    CAMLreturn(result);
}

/* Convert filename to UTF-8 */
CAMLprim value ml_g_filename_to_utf8(value str)
{
    CAMLparam1(str);
    CAMLlocal1(result);
    GError *err = NULL;
    gchar *converted;
    gsize bytes_read, bytes_written;

    converted = g_filename_to_utf8(String_val(str),
                                     caml_string_length(str),
                                     &bytes_read,
                                     &bytes_written,
                                     &err);

    if (err != NULL) {
        ml_raise_gerror(err);
    }

    result = caml_copy_string(converted != NULL ? converted : "");
    g_free(converted);

    CAMLreturn(result);
}

/* Convert UTF-8 to filename */
CAMLprim value ml_g_filename_from_utf8(value str)
{
    CAMLparam1(str);
    CAMLlocal1(result);
    GError *err = NULL;
    gchar *converted;
    gsize bytes_read, bytes_written;

    converted = g_filename_from_utf8(String_val(str),
                                       caml_string_length(str),
                                       &bytes_read,
                                       &bytes_written,
                                       &err);

    if (err != NULL) {
        ml_raise_gerror(err);
    }

    result = caml_copy_string(converted != NULL ? converted : "");
    g_free(converted);

    CAMLreturn(result);
}

/* Get current charset */
CAMLprim value ml_g_get_charset(value unit)
{
    CAMLparam1(unit);
    CAMLlocal1(result);
    const char *charset;
    gboolean is_utf8;

    is_utf8 = g_get_charset(&charset);

    result = caml_alloc_tuple(2);
    Store_field(result, 0, Val_bool(is_utf8));
    Store_field(result, 1, caml_copy_string(charset));

    CAMLreturn(result);
}

/* Priority conversion helper
 * Note: Polymorphic variants are ordered alphabetically:
 * `DEFAULT, `DEFAULT_IDLE, `HIGH, `HIGH_IDLE, `LOW
 */
CAMLprim value ml_g_int_of_priority(value prio)
{
    CAMLparam1(prio);
    int result;
    switch (Int_val(prio)) {
        case 0: result = G_PRIORITY_DEFAULT; break;        /* `DEFAULT (alphabetically first) */
        case 1: result = G_PRIORITY_DEFAULT_IDLE; break;   /* `DEFAULT_IDLE */
        case 2: result = G_PRIORITY_HIGH; break;           /* `HIGH */
        case 3: result = G_PRIORITY_HIGH_IDLE; break;      /* `HIGH_IDLE */
        case 4: result = G_PRIORITY_LOW; break;            /* `LOW */
        default: result = G_PRIORITY_DEFAULT; break;
    }
    CAMLreturn(Val_int(result));
}
