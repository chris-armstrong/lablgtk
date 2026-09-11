/* GENERATED CODE - DO NOT EDIT */
/* C bindings for UnixFDList */

#include <gio/gio.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gio/gio.h>
/* Include library-specific type conversions and forward declarations */
#include "gio_decls.h"


#if GLIB_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_g_unix_fd_list_new(value unit)
{
CAMLparam1(unit);

GUnixFDList *obj = g_unix_fd_list_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GUnixFDList(obj));
}
#else

CAMLexport CAMLprim value ml_g_unix_fd_list_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("UnixFDList requires GLib >= 2.24");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_g_unix_fd_list_new_from_array(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
    int arg1_length = Wosize_val(arg1);
    gint* c_arg1 = (gint*)g_malloc(sizeof(gint) * arg1_length);
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = Int_val(Field(arg1, i));
    }

GUnixFDList *obj = g_unix_fd_list_new_from_array(c_arg1, Int_val(arg2));
if (obj) g_object_ref_sink(obj);

    g_free(c_arg1);
CAMLreturn(Val_GUnixFDList(obj));
}
#else

CAMLexport CAMLprim value ml_g_unix_fd_list_new_from_array(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("UnixFDList requires GLib >= 2.24");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_g_unix_fd_list_steal_fds(value self)
{
CAMLparam1(self);
gint out1;

gint* result = g_unix_fd_list_steal_fds(GUnixFDList_val(self), &out1);
    int result_length = out1;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, Val_int(result[i]));
    }
    g_free(result);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_result);
    Store_field(ret, 1, Val_int(out1));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_g_unix_fd_list_steal_fds(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("UnixFDList requires GLib >= 2.24");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_g_unix_fd_list_peek_fds(value self)
{
CAMLparam1(self);
gint out1;

const gint* result = g_unix_fd_list_peek_fds(GUnixFDList_val(self), &out1);
    int result_length = out1;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, Val_int(result[i]));
    }
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_result);
    Store_field(ret, 1, Val_int(out1));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_g_unix_fd_list_peek_fds(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("UnixFDList requires GLib >= 2.24");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_g_unix_fd_list_get_length(value self)
{
CAMLparam1(self);

gint result = g_unix_fd_list_get_length(GUnixFDList_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_g_unix_fd_list_get_length(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("UnixFDList requires GLib >= 2.24");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_g_unix_fd_list_get(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gint result = g_unix_fd_list_get(GUnixFDList_val(self), Int_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_int(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_unix_fd_list_get(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("UnixFDList requires GLib >= 2.24");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_g_unix_fd_list_append(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gint result = g_unix_fd_list_append(GUnixFDList_val(self), Int_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_int(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_unix_fd_list_append(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("UnixFDList requires GLib >= 2.24");
return Val_unit;
}
#endif

GType g_unix_fd_list_get_type (void);


CAMLprim value ml_gio_unix_fd_list_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_unix_fd_list_get_type()));
}
