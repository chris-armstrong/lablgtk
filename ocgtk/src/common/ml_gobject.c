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

/* Full GObject C bindings for ocgtk 
 *
 * This file provides comprehensive GObject functionality:
 * - Object reference counting
 * - Type system queries
 * - GValue handling (all standard types)
 * - Property get/set
 * - Signal connection/disconnection
 * - Closure marshalling
 */

#include <string.h>
#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>

#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/custom.h>

#include "wrappers.h"
#include "value_kinds.h"

/* ==================================================================== */
/* GObject Reference Counting */
/* ==================================================================== */

CAMLprim value ml_g_object_ref(value obj)
{
    CAMLparam1(obj);

    if (obj == Val_unit || ml_gobject_ext_of_val(obj) == NULL)
        caml_invalid_argument("g_object_ref: NULL object");

    g_object_ref(GObject_ext_of_val(obj));
    CAMLreturn(Val_unit);
}

CAMLprim value ml_g_object_unref(value obj)
{
    CAMLparam1(obj);

    if (obj == Val_unit || ml_gobject_ext_of_val(obj) == NULL)
        CAMLreturn(Val_unit);

    g_object_unref(GObject_ext_of_val(obj));
    CAMLreturn(Val_unit);
}

CAMLprim value ml_g_object_get_ref_count(value obj)
{
    CAMLparam1(obj);

    if (obj == Val_unit || ml_gobject_ext_of_val(obj) == NULL)
        caml_invalid_argument("g_object_get_ref_count: NULL object");

    GObject *gobj = GObject_ext_of_val(obj);
    /* Direct struct access: g_object_get_ref_count() isn't reliably available
     * in packaged GLib builds; ref_count is public API in GObject's struct. */
    CAMLreturn(Val_int(gobj->ref_count));
}


/* ==================================================================== */
/* Type System Queries */
/* ==================================================================== */

CAMLprim value ml_g_object_get_type(value obj)
{
    CAMLparam1(obj);
    GObject *gobj;

    if (obj == Val_unit || ml_gobject_ext_of_val(obj) == NULL)
        caml_invalid_argument("g_object_get_type: NULL object");

    gobj = G_OBJECT(ml_gobject_ext_of_val(obj));
    CAMLreturn(Val_long(G_OBJECT_TYPE(gobj)));
}

CAMLprim value ml_g_type_name(value type)
{
    CAMLparam1(type);
    CAMLlocal1(result);

    const char *name = g_type_name(Long_val(type));
    if (name == NULL)
        result = caml_copy_string("<invalid type>");
    else
        result = caml_copy_string(name);

    CAMLreturn(result);
}

CAMLprim value ml_g_type_from_name(value name)
{
    CAMLparam1(name);
    GType type = g_type_from_name(String_val(name));
    CAMLreturn(Val_long(type));
}

CAMLprim value ml_g_type_parent(value type)
{
    CAMLparam1(type);
    GType parent = g_type_parent(Long_val(type));
    CAMLreturn(Val_long(parent));
}

CAMLprim value ml_g_type_is_a(value type, value is_a_type)
{
    CAMLparam2(type, is_a_type);
    gboolean result = g_type_is_a(Long_val(type), Long_val(is_a_type));
    CAMLreturn(Val_bool(result));
}

CAMLprim value ml_g_type_of_fundamental(value fund_int)
{
    CAMLparam1(fund_int);
    int fund = Int_val(fund_int);
    GType type = G_TYPE_INVALID;

    switch (fund) {
        case 0: type = G_TYPE_INVALID; break;
        case 1: type = G_TYPE_NONE; break;
        case 2: type = G_TYPE_INTERFACE; break;
        case 3: type = G_TYPE_CHAR; break;
        case 4: type = G_TYPE_UCHAR; break;
        case 5: type = G_TYPE_BOOLEAN; break;
        case 6: type = G_TYPE_INT; break;
        case 7: type = G_TYPE_UINT; break;
        case 8: type = G_TYPE_LONG; break;
        case 9: type = G_TYPE_ULONG; break;
        case 10: type = G_TYPE_INT64; break;
        case 11: type = G_TYPE_UINT64; break;
        case 12: type = G_TYPE_ENUM; break;
        case 13: type = G_TYPE_FLAGS; break;
        case 14: type = G_TYPE_FLOAT; break;
        case 15: type = G_TYPE_DOUBLE; break;
        case 16: type = G_TYPE_STRING; break;
        case 17: type = G_TYPE_POINTER; break;
        case 18: type = G_TYPE_BOXED; break;
        case 19: type = G_TYPE_PARAM; break;
        case 20: type = G_TYPE_OBJECT; break;
    }

    CAMLreturn(Val_long(type));
}

/* ==================================================================== */
/* GValue Handling */
/* ==================================================================== */

/* Wrapper to track GValue initialization state */
typedef struct {
    GValue gvalue;
    int initialized;
} ml_gvalue;

/* Custom block operations for GValue */
static void finalize_gvalue(value val)
{
    ml_gvalue *mlgv = (ml_gvalue *)Data_custom_val(val);
    /* Only unset if the GValue has been initialized */
    if (mlgv->initialized) {
        g_value_unset(&mlgv->gvalue);
        mlgv->initialized = 0;
    }
}

struct custom_operations ocgtk_gvalue_ops = {
    "ocgtk.gvalue",
    finalize_gvalue,
    custom_compare_default,
    custom_hash_default,
    custom_serialize_default,
    custom_deserialize_default,
    custom_compare_ext_default,
    custom_fixed_length_default
};

CAMLprim value ml_g_value_new(void)
{
    CAMLparam0();
    CAMLlocal1(val);

    val = caml_alloc_custom(&ocgtk_gvalue_ops, sizeof(ml_gvalue), 0, 1);
    ml_gvalue *mlgv = (ml_gvalue *)Data_custom_val(val);
    memset(&mlgv->gvalue, 0, sizeof(GValue));
    mlgv->initialized = 0;

    CAMLreturn(val);
}

GValue *GValue_val(value val)
{
    ml_gvalue *mlgv = (ml_gvalue *)Data_custom_val(val);
    return &mlgv->gvalue;
}

CAMLprim value ml_g_value_init_gtype(value val, value gtype)
{
    CAMLparam2(val, gtype);
    ml_gvalue *mlgv = (ml_gvalue *)Data_custom_val(val);
    g_value_init(&mlgv->gvalue, (GType)Long_val(gtype));
    mlgv->initialized = 1;
    CAMLreturn(Val_unit);
}

CAMLprim value ml_g_value_reset(value val)
{
    CAMLparam1(val);
    ml_gvalue *mlgv = (ml_gvalue *)Data_custom_val(val);
    if (mlgv->initialized) {
        g_value_reset(&mlgv->gvalue);
    }
    CAMLreturn(Val_unit);
}

CAMLprim value ml_g_value_get_gtype(value val)
{
    CAMLparam1(val);
    GValue *gv = GValue_val(val);
    CAMLreturn(Val_long(G_VALUE_TYPE(gv)));
}

/* Type-specific getters/setters */

CAMLprim value ml_g_value_get_int(value val)
{
    CAMLparam1(val);
    GValue *gv = GValue_val(val);
    if (!G_VALUE_HOLDS_INT(gv))
        caml_invalid_argument("g_value_get_int: not an int");
    CAMLreturn(Val_int(g_value_get_int(gv)));
}

CAMLprim value ml_g_value_set_int(value val, value i)
{
    CAMLparam2(val, i);
    GValue *gv = GValue_val(val);
    g_value_set_int(gv, Int_val(i));
    CAMLreturn(Val_unit);
}

CAMLprim value ml_g_value_get_uint(value val)
{
    CAMLparam1(val);
    GValue *gv = GValue_val(val);
    if (!G_VALUE_HOLDS_UINT(gv))
        caml_invalid_argument("g_value_get_uint: not a uint");
    CAMLreturn(Val_int(g_value_get_uint(gv)));
}

CAMLprim value ml_g_value_set_uint(value val, value i)
{
    CAMLparam2(val, i);
    GValue *gv = GValue_val(val);
    g_value_set_uint(gv, Int_val(i));
    CAMLreturn(Val_unit);
}

CAMLprim value ml_g_value_get_boolean(value val)
{
    CAMLparam1(val);
    GValue *gv = GValue_val(val);
    if (!G_VALUE_HOLDS_BOOLEAN(gv))
        caml_invalid_argument("g_value_get_boolean: not a boolean");
    CAMLreturn(Val_bool(g_value_get_boolean(gv)));
}

CAMLprim value ml_g_value_set_boolean(value val, value b)
{
    CAMLparam2(val, b);
    GValue *gv = GValue_val(val);
    g_value_set_boolean(gv, Bool_val(b));
    CAMLreturn(Val_unit);
}

CAMLprim value ml_g_value_get_string(value val)
{
    CAMLparam1(val);
    CAMLlocal1(result);

    GValue *gv = GValue_val(val);
    if (!G_VALUE_HOLDS_STRING(gv))
        caml_invalid_argument("g_value_get_string: not a string");

    const char *str = g_value_get_string(gv);
    if (str == NULL)
        result = caml_copy_string("");
    else
        result = caml_copy_string(str);

    CAMLreturn(result);
}

CAMLprim value ml_g_value_set_string(value val, value str)
{
    CAMLparam2(val, str);
    GValue *gv = GValue_val(val);
    g_value_set_string(gv, String_val(str));
    CAMLreturn(Val_unit);
}

CAMLprim value ml_g_value_get_float(value val)
{
    CAMLparam1(val);
    CAMLlocal1(result);

    GValue *gv = GValue_val(val);
    if (!G_VALUE_HOLDS_FLOAT(gv))
        caml_invalid_argument("g_value_get_float: not a float");

    result = caml_copy_double(g_value_get_float(gv));
    CAMLreturn(result);
}

CAMLprim value ml_g_value_set_float(value val, value f)
{
    CAMLparam2(val, f);
    GValue *gv = GValue_val(val);
    g_value_set_float(gv, (float)Double_val(f));
    CAMLreturn(Val_unit);
}

CAMLprim value ml_g_value_get_double(value val)
{
    CAMLparam1(val);
    CAMLlocal1(result);

    GValue *gv = GValue_val(val);
    if (!G_VALUE_HOLDS_DOUBLE(gv))
        caml_invalid_argument("g_value_get_double: not a double");

    result = caml_copy_double(g_value_get_double(gv));
    CAMLreturn(result);
}

CAMLprim value ml_g_value_set_double(value val, value d)
{
    CAMLparam2(val, d);
    GValue *gv = GValue_val(val);
    g_value_set_double(gv, Double_val(d));
    CAMLreturn(Val_unit);
}

CAMLprim value ml_g_value_get_object(value val)
{
    CAMLparam1(val);
    GValue *gv = GValue_val(val);
    if (!G_VALUE_HOLDS_OBJECT(gv))
        caml_invalid_argument("g_value_get_object: not an object");

    GObject *obj = g_value_get_object(gv);
    if (obj == NULL)
        caml_failwith("g_value_get_object: NULL object");

    /* g_value_get_object returns a borrowed (transfer-none) pointer, but
       ml_gobject_val_of_ext's finalizer unconditionally g_object_unrefs
       whatever it wraps once the OCaml wrapper is collected. Without this
       ref, that unref has no matching ref of its own: it silently steals
       one from whoever else owns the object (e.g. the widget's parent),
       eventually destroying a still-live, still-displayed widget out from
       under the running UI. */
    g_object_ref(obj);

    CAMLreturn(ml_gobject_val_of_ext(obj));
}

CAMLprim value ml_g_value_set_object(value val, value obj)
{
    CAMLparam2(val, obj);
    GValue *gv = GValue_val(val);
    GObject *gobj = NULL;

    if (obj != Val_unit && ml_gobject_ext_of_val(obj) != NULL)
        gobj = G_OBJECT(ml_gobject_ext_of_val(obj));

    g_value_set_object(gv, gobj);
    CAMLreturn(Val_unit);
}

CAMLprim value ml_g_value_set_object_null(value val)
{
    CAMLparam1(val);
    GValue *gv = GValue_val(val);
    if (!G_VALUE_HOLDS_OBJECT(gv))
        caml_invalid_argument("g_value_set_object_null: not an object");
    g_value_set_object(gv, NULL);
    CAMLreturn(Val_unit);
}

/* --- int64 --- */

CAMLprim value ml_g_value_get_int64(value val)
{
    CAMLparam1(val);
    GValue *gv = GValue_val(val);
    if (!G_VALUE_HOLDS_INT64(gv))
        caml_invalid_argument("g_value_get_int64: not an int64");
    CAMLreturn(caml_copy_int64(g_value_get_int64(gv)));
}

CAMLprim value ml_g_value_set_int64(value val, value v)
{
    CAMLparam2(val, v);
    GValue *gv = GValue_val(val);
    if (!G_VALUE_HOLDS_INT64(gv))
        caml_invalid_argument("g_value_set_int64: not an int64 value");
    g_value_set_int64(gv, Int64_val(v));
    CAMLreturn(Val_unit);
}

/* --- GVariant --- */

CAMLprim value ml_g_value_get_variant(value val)
{
    CAMLparam1(val);
    CAMLlocal1(result);

    GValue *gv = GValue_val(val);
    if (!G_VALUE_HOLDS_VARIANT(gv))
        caml_invalid_argument("g_value_get_variant: not a variant");

    GVariant *p = g_value_get_variant(gv);
    /* g_value_get_variant returns a borrowed pointer; ref to take ownership */
    if (p == NULL)
        caml_failwith("g_value_get_variant: NULL variant");
    result = Val_GVariant(g_variant_ref(p));

    CAMLreturn(result);
}

CAMLprim value ml_g_value_set_variant(value val, value v)
{
    CAMLparam2(val, v);
    GValue *gv = GValue_val(val);
    if (!G_VALUE_HOLDS_VARIANT(gv))
        caml_invalid_argument("g_value_set_variant: not a variant value");
    /* transfer-none: GValue takes its own reference */
    g_value_set_variant(gv, GVariant_val(v));
    CAMLreturn(Val_unit);
}

/* --- enum (raw int round-trip) --- */

CAMLprim value ml_g_value_get_enum_int(value val)
{
    CAMLparam1(val);
    GValue *gv = GValue_val(val);
    if (!G_VALUE_HOLDS_ENUM(gv))
        caml_invalid_argument("g_value_get_enum_int: not an enum");
    CAMLreturn(Val_int(g_value_get_enum(gv)));
}

CAMLprim value ml_g_value_set_enum_int(value val, value v)
{
    CAMLparam2(val, v);
    GValue *gv = GValue_val(val);
    if (!G_VALUE_HOLDS_ENUM(gv))
        caml_invalid_argument("g_value_set_enum_int: not an enum");
    g_value_set_enum(gv, Int_val(v));
    CAMLreturn(Val_unit);
}

/* --- flags (raw int round-trip) --- */

CAMLprim value ml_g_value_get_flags_int(value val)
{
    CAMLparam1(val);
    GValue *gv = GValue_val(val);
    if (!G_VALUE_HOLDS_FLAGS(gv))
        caml_invalid_argument("g_value_get_flags_int: not a flags value");
    CAMLreturn(Val_int((int)g_value_get_flags(gv)));
}

CAMLprim value ml_g_value_set_flags_int(value val, value v)
{
    CAMLparam2(val, v);
    GValue *gv = GValue_val(val);
    if (!G_VALUE_HOLDS_FLAGS(gv))
        caml_invalid_argument("g_value_set_flags_int: not a flags value");
    g_value_set_flags(gv, (guint)Int_val(v));
    CAMLreturn(Val_unit);
}

/* --- boxed record bridge ---
 * get_boxed: copies the boxed value out of the GValue via g_boxed_copy and
 * wraps it in a gir_record custom block (ocgtk_gir_record_ops).  The
 * existing finalizer (finalize_gir_record in wrappers.c) dispatches on
 * G_TYPE_IS_BOXED and calls g_boxed_free, so the copy is freed correctly
 * when the OCaml block is collected.
 *
 * set_boxed: extracts the pointer from the gir_record custom block and
 * passes it to g_value_set_boxed (transfer-none; the GValue copies
 * internally via g_boxed_copy).
 */

CAMLprim value ml_g_value_get_boxed(value val)
{
    CAMLparam1(val);
    CAMLlocal1(result);

    GValue *gv = GValue_val(val);

    /* GTK sometimes wraps signal parameters in a G_TYPE_VALUE container
       (a nested GValue). Unwrap it so we operate on the inner value. */
    if (G_VALUE_TYPE(gv) == G_TYPE_VALUE) {
        const GValue *inner = g_value_get_boxed(gv);
        if (inner == NULL)
            caml_failwith("g_value_get_boxed: NULL inner GValue");
        gv = (GValue *)inner;
    }

    if (!G_VALUE_HOLDS_BOXED(gv))
        caml_invalid_argument("g_value_get_boxed: not a boxed value");

    void *p = g_value_get_boxed(gv);
    if (p == NULL)
        caml_failwith("g_value_get_boxed: NULL boxed pointer");

    /* Take an owned copy so OCaml controls the lifetime via gir_record_box */
    void *copy = g_boxed_copy(G_VALUE_TYPE(gv), p);
    result = ml_gir_record_val_ptr_with_type(G_VALUE_TYPE(gv), copy);

    CAMLreturn(result);
}

/* Wrap a borrowed const GValue* into an owned Gobject.Value.t by copying its
   contents.  The returned custom block uses ocgtk_gvalue_ops whose finalizer
   calls g_value_unset, so the copy is cleaned up correctly when OCaml GC
   collects the block.  Never call this with a NULL src — the caller (generated
   C stubs) guards with Val_option which handles NULL. */
value Val_GValue_copy(const GValue *src)
{
    CAMLparam0();
    CAMLlocal1(result);
    result = caml_alloc_custom(&ocgtk_gvalue_ops, sizeof(ml_gvalue), 0, 1);
    ml_gvalue *mlgv = (ml_gvalue *)Data_custom_val(result);
    memset(&mlgv->gvalue, 0, sizeof(GValue));
    g_value_init(&mlgv->gvalue, G_VALUE_TYPE(src));
    g_value_copy(src, &mlgv->gvalue);
    mlgv->initialized = 1;
    CAMLreturn(result);
}

CAMLprim value ml_g_value_set_boxed(value val, value v)
{
    CAMLparam2(val, v);
    GValue *gv = GValue_val(val);
    if (!G_VALUE_HOLDS_BOXED(gv))
        caml_invalid_argument("g_value_set_boxed: not a boxed value");
    /* transfer-none: GValue takes its own copy via g_boxed_copy internally */
    const void *ptr = ml_gir_record_ptr_val(v, "set_boxed");
    g_value_set_boxed(gv, ptr);
    CAMLreturn(Val_unit);
}

/* ==================================================================== */
/* Property Operations */
/* ==================================================================== */

CAMLprim value ml_g_object_get_property(value obj, value prop_name, value val)
{
    CAMLparam3(obj, prop_name, val);
    GObject *gobj = G_OBJECT(ml_gobject_ext_of_val(obj));
    GValue *gv = GValue_val(val);
    const char *name = String_val(prop_name);

    g_object_get_property(gobj, name, gv);
    CAMLreturn(Val_unit);
}

CAMLprim value ml_g_object_set_property(value obj, value prop_name, value val)
{
    CAMLparam3(obj, prop_name, val);
    GObject *gobj = G_OBJECT(ml_gobject_ext_of_val(obj));
    GValue *gv = GValue_val(val);
    const char *name = String_val(prop_name);

    g_object_set_property(gobj, name, gv);
    CAMLreturn(Val_unit);
}

CAMLprim value ml_g_object_get_property_type(value obj, value prop_name)
{
    CAMLparam2(obj, prop_name);
    GObject *gobj = G_OBJECT(ml_gobject_ext_of_val(obj));
    const char *name = String_val(prop_name);

    GParamSpec *pspec = g_object_class_find_property(
        G_OBJECT_GET_CLASS(gobj), name);

    if (pspec == NULL) {
        char msg[256];
        snprintf(msg, sizeof(msg), "Property '%s' not found", name);
        caml_invalid_argument(msg);
    }

    CAMLreturn(Val_long(pspec->value_type));
}

CAMLprim value ml_g_object_freeze_notify(value obj)
{
    CAMLparam1(obj);
    g_object_freeze_notify(G_OBJECT(ml_gobject_ext_of_val(obj)));
    CAMLreturn(Val_unit);
}

CAMLprim value ml_g_object_thaw_notify(value obj)
{
    CAMLparam1(obj);
    g_object_thaw_notify(G_OBJECT(ml_gobject_ext_of_val(obj)));
    CAMLreturn(Val_unit);
}

CAMLprim value ml_g_object_notify(value obj, value prop_name)
{
    CAMLparam2(obj, prop_name);
    g_object_notify(G_OBJECT(ml_gobject_ext_of_val(obj)), String_val(prop_name));
    CAMLreturn(Val_unit);
}

/* ==================================================================== */
/* Exception-escape observation flag (forward declaration) */
/* ==================================================================== */

int ml_closure_exception_flag = 0;

/* ==================================================================== */
/* Closure Support */
/* ==================================================================== */

/* GClosure integration with OCaml callbacks
 *
 * This implementation stores the OCaml closure value directly in the
 * GClosure->data field and registers it as a global root to protect it
 * from garbage collection. This is the standard approach used in lablgtk3.
 *
 * When the GClosure is destroyed, the invalidate notifier removes the
 * global root, allowing the OCaml closure to be collected.
 */

void finalise_gclosure(value v) {
    GClosure *closure = GClosure_val(v);
    g_closure_unref(closure);
}


struct custom_operations ocgtk_gclosure_ops = {
    "ocgtk.gclosure",
    finalise_gclosure,
    custom_compare_default,
    custom_hash_default,
    custom_serialize_default,
    custom_deserialize_default,
    custom_compare_ext_default,
    custom_fixed_length_default
};

/* Wrap GClosure with ref and sink */
static value Val_GClosure_sink(GClosure *closure)
{
    CAMLparam0();
    CAMLlocal1(ret);

    if (!closure) {
        caml_failwith("Val_GClosure_sink: NULL closure");
    }

    /* Ref and sink the closure */
    g_closure_ref(closure);
    g_closure_sink(closure);

    /* Create custom block WITHOUT finalizer */
    ret = caml_alloc_custom(&ocgtk_gclosure_ops, sizeof(GClosure*), 0, 1);
    GClosure_val(ret) = closure;

    CAMLreturn(ret);
}

/* Invalidate notifier - called when GLib destroys the closure
 * Removes the global root to allow the OCaml closure to be collected
 */
static void ml_closure_invalidate(gpointer data, GClosure *closure)
{
    /* closure->data contains the OCaml closure value */
    caml_remove_global_root((value*)&closure->data);
}

/* Marshaller that invokes OCaml callback */
static void ml_closure_marshal(GClosure *closure,
                                 GValue *return_value,
                                 guint n_params,
                                 const GValue *param_values,
                                 gpointer invocation_hint,
                                 gpointer marshal_data)
{
    CAMLparam0();
    CAMLlocal5(argv_val, result_val, callback_val, result, exn);

    /* Get the OCaml callback directly from closure->data */
    callback_val = (value)closure->data;

    /* Create argv record: { result; nargs; args } */
    argv_val = caml_alloc(3, 0);

    /* Wrap return_value - create an ml_gvalue wrapper */
    result_val = ml_g_value_new();
    ml_gvalue *mlgv = (ml_gvalue *)Data_custom_val(result_val);

    if (return_value != NULL && G_IS_VALUE(return_value)) {
        /* Properly initialize and deep copy the GValue */
        g_value_init(&mlgv->gvalue, G_VALUE_TYPE(return_value));
        g_value_copy(return_value, &mlgv->gvalue);
        mlgv->initialized = 1;
    }
    Store_field(argv_val, 0, result_val);

    /* nargs */
    Store_field(argv_val, 1, Val_int(n_params));

    /* args - store pointer to param_values array directly as a value
     * IMPORTANT: This pointer is only valid during this marshaller callback.
     * The OCaml callback MUST NOT store argv_val for later use - it must
     * access all parameters synchronously during the callback invocation.
     * Storing and accessing argv_val later will cause use-after-free.
     */
    Store_field(argv_val, 2, (value)param_values);

    /* Call OCaml callback with exception handling */
    result = caml_callback_exn(callback_val, argv_val);

    /* Check for exceptions */
    if (Is_exception_result(result)) {
        exn = Extract_exception(result);
        ml_closure_exception_flag = 1;
        /* Format and log the exception so closure failures are visible */
        const value *exn_to_string = caml_named_value("Printexc.to_string");
        if (exn_to_string != NULL) {
            value msg = caml_callback_exn(*exn_to_string, exn);
            if (!Is_exception_result(msg)) {
                g_warning("OCaml closure exception: %s", String_val(msg));
            } else {
                g_warning("OCaml closure exception (could not format)");
            }
        } else {
            g_warning("OCaml closure exception (Printexc.to_string not registered)");
        }
    }

    /* Copy result back if needed */
    if (return_value != NULL && G_IS_VALUE(return_value)) {
        ml_gvalue *result_mlgv = (ml_gvalue *)Data_custom_val(result_val);
        if (result_mlgv->initialized && G_IS_VALUE(&result_mlgv->gvalue)) {
            g_value_copy(&result_mlgv->gvalue, return_value);
        }
    }

    CAMLreturn0;
}

CAMLprim value ml_g_closure_new(value callback_val)
{
    CAMLparam1(callback_val);

    /* Create GClosure with the OCaml closure as data
     * The closure value is stored directly in closure->data
     */
    GClosure *closure = g_closure_new_simple(sizeof(GClosure), (gpointer)callback_val);

    /* Register the OCaml value as a global root to protect it from GC
     * This is required because closure->data is C-allocated memory
     */
    caml_register_global_root((value*)&closure->data);

    /* Set up invalidate notifier to remove global root when closure is destroyed */
    g_closure_add_invalidate_notifier(closure, NULL, ml_closure_invalidate);

    /* Set up marshaller */
    g_closure_set_marshal(closure, ml_closure_marshal);

    /* Wrap with custom block */
    CAMLreturn(Val_GClosure_sink(closure));
}

/* Access closure arguments
 * WARNING: argv_val contains a pointer to param_values which is only valid
 * during the marshaller callback. This function MUST only be called from
 * within the closure callback, never after the callback has returned.
 */
CAMLprim value ml_g_closure_get_arg(value argv_val, value pos)
{
    CAMLparam2(argv_val, pos);
    CAMLlocal1(result);

    const GValue *param_values = (const GValue *)Field(argv_val, 2);
    int index = Int_val(pos);
    int nargs = Int_val(Field(argv_val, 1));

    /* Validate pointer is not NULL (basic sanity check) */
    if (param_values == NULL)
        caml_invalid_argument("closure_get_arg: invalid argv (param_values is NULL)");

    if (index < 0 || index >= nargs)
        caml_invalid_argument("closure_get_arg: index out of bounds");

    /* Create OCaml GValue wrapper and copy the parameter */
    result = ml_g_value_new();
    ml_gvalue *mlgv = (ml_gvalue *)Data_custom_val(result);

    /* Initialize the destination GValue with the same type */
    g_value_init(&mlgv->gvalue, G_VALUE_TYPE(&param_values[index]));

    /* Deep copy the GValue contents */
    g_value_copy(&param_values[index], &mlgv->gvalue);

    mlgv->initialized = 1;  /* Mark as initialized */

    CAMLreturn(result);
}

CAMLprim value ml_g_closure_get_result(value argv_val)
{
    CAMLparam1(argv_val);
    CAMLreturn(Field(argv_val, 0));
}

CAMLprim value ml_g_closure_get_result_type(value argv_val)
{
    CAMLparam1(argv_val);
    GValue *gv = GValue_val(Field(argv_val, 0));
    CAMLreturn(Val_long(G_VALUE_TYPE(gv)));
}

CAMLprim value ml_g_closure_get_arg_type(value argv_val, value pos)
{
    CAMLparam2(argv_val, pos);
    const GValue *param_values = (const GValue *)(Field(argv_val, 2));
    int index = Int_val(pos);
    int nargs = Int_val(Field(argv_val, 1));

    if (param_values == NULL)
        caml_invalid_argument("closure_get_arg_type: invalid argv (param_values is NULL)");
    if (index < 0 || index >= nargs)
        caml_invalid_argument("closure_get_arg_type: index out of bounds");

    CAMLreturn(Val_long(G_VALUE_TYPE(&param_values[index])));
}

CAMLprim value ml_g_closure_set_result(value argv_val, value new_result)
{
    CAMLparam2(argv_val, new_result);
    GValue *result_gv = GValue_val(Field(argv_val, 0));
    GValue *new_gv = GValue_val(new_result);

    if (G_IS_VALUE(result_gv) && G_IS_VALUE(new_gv)) {
        g_value_copy(new_gv, result_gv);
    }

    CAMLreturn(Val_unit);
}

/* ==================================================================== */
/* Signal Operations */
/* ==================================================================== */

CAMLprim value ml_g_signal_connect_closure(value obj, value signal_name,
                                            value closure, value after)
{
    CAMLparam4(obj, signal_name, closure, after);
    GObject *gobj = G_OBJECT(ml_gobject_ext_of_val(obj));
    GClosure *gclosure = GClosure_val(closure);
    const char *name = String_val(signal_name);
    gboolean after_flag = Bool_val(after);

    gulong handler_id = g_signal_connect_closure(gobj, name, gclosure, after_flag);

    CAMLreturn(Val_long(handler_id));
}

CAMLprim value ml_g_signal_handler_disconnect(value obj, value handler_id)
{
    CAMLparam2(obj, handler_id);
    g_signal_handler_disconnect(G_OBJECT(ml_gobject_ext_of_val(obj)), Long_val(handler_id));
    CAMLreturn(Val_unit);
}

CAMLprim value ml_g_signal_handler_block(value obj, value handler_id)
{
    CAMLparam2(obj, handler_id);
    g_signal_handler_block(G_OBJECT(ml_gobject_ext_of_val(obj)), Long_val(handler_id));
    CAMLreturn(Val_unit);
}

CAMLprim value ml_g_signal_handler_unblock(value obj, value handler_id)
{
    CAMLparam2(obj, handler_id);
    g_signal_handler_unblock(G_OBJECT(ml_gobject_ext_of_val(obj)), Long_val(handler_id));
    CAMLreturn(Val_unit);
}

CAMLprim value ml_g_signal_handler_is_connected(value obj, value handler_id)
{
    CAMLparam2(obj, handler_id);
    gboolean connected = g_signal_handler_is_connected(
        G_OBJECT(ml_gobject_ext_of_val(obj)), Long_val(handler_id));
    CAMLreturn(Val_bool(connected));
}

CAMLprim value ml_g_signal_emit_by_name(value obj, value signal_name)
{
    CAMLparam2(obj, signal_name);
    g_signal_emit_by_name(G_OBJECT(ml_gobject_ext_of_val(obj)), String_val(signal_name));
    CAMLreturn(Val_unit);
}

/* ==================================================================== */
/* Object Creation (from Phase 1) */
/* ==================================================================== */

CAMLprim value ml_g_object_new(value type)
{
    CAMLparam1(type);
    GObject *obj;

    obj = g_object_new(Long_val(type), NULL);
    if (obj == NULL)
        caml_failwith("g_object_new: failed to create object");

    CAMLreturn(ml_gobject_val_of_ext(obj));
}
