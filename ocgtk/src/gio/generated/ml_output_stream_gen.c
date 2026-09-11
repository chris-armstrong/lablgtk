/* GENERATED CODE - DO NOT EDIT */
/* C bindings for OutputStream */

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


#if GLIB_CHECK_VERSION(2,60,0)

CAMLexport CAMLprim value ml_g_output_stream_writev_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;
gsize out2;

gboolean result = g_output_stream_writev_finish(GOutputStream_val(self), GAsyncResult_val(arg1), &out2, &error);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_gsize(out2));
    if (error == NULL) CAMLreturn(Res_Ok(ret)); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_output_stream_writev_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("OutputStream requires GLib >= 2.60");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,60,0)

CAMLexport CAMLprim value ml_g_output_stream_writev_all_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;
gsize out2;

gboolean result = g_output_stream_writev_all_finish(GOutputStream_val(self), GAsyncResult_val(arg1), &out2, &error);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_gsize(out2));
    if (error == NULL) CAMLreturn(Res_Ok(ret)); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_output_stream_writev_all_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("OutputStream requires GLib >= 2.60");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,60,0)

CAMLexport CAMLprim value ml_g_output_stream_writev_all(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GError *error = NULL;
    int arg1_length = Wosize_val(arg1);
    GOutputVector* c_arg1 = (GOutputVector*)g_malloc(sizeof(GOutputVector) * arg1_length);
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = *GOutputVector_val(Field(arg1, i));
    }
gsize out3;

gboolean result = g_output_stream_writev_all(GOutputStream_val(self), c_arg1, Gsize_val(arg2), &out3, Option_val(arg3, GCancellable_val, NULL), &error);
    g_free(c_arg1);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_gsize(out3));
    if (error == NULL) CAMLreturn(Res_Ok(ret)); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_output_stream_writev_all(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("OutputStream requires GLib >= 2.60");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,60,0)

CAMLexport CAMLprim value ml_g_output_stream_writev(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GError *error = NULL;
    int arg1_length = Wosize_val(arg1);
    GOutputVector* c_arg1 = (GOutputVector*)g_malloc(sizeof(GOutputVector) * arg1_length);
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = *GOutputVector_val(Field(arg1, i));
    }
gsize out3;

gboolean result = g_output_stream_writev(GOutputStream_val(self), c_arg1, Gsize_val(arg2), &out3, Option_val(arg3, GCancellable_val, NULL), &error);
    g_free(c_arg1);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_gsize(out3));
    if (error == NULL) CAMLreturn(Res_Ok(ret)); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_output_stream_writev(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("OutputStream requires GLib >= 2.60");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_output_stream_write_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gssize result = g_output_stream_write_finish(GOutputStream_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_long(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_output_stream_write_bytes_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gssize result = g_output_stream_write_bytes_finish(GOutputStream_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_long(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_output_stream_write_bytes(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gssize result = g_output_stream_write_bytes(GOutputStream_val(self), GBytes_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_long(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if GLIB_CHECK_VERSION(2,44,0)

CAMLexport CAMLprim value ml_g_output_stream_write_all_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;
gsize out2;

gboolean result = g_output_stream_write_all_finish(GOutputStream_val(self), GAsyncResult_val(arg1), &out2, &error);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_gsize(out2));
    if (error == NULL) CAMLreturn(Res_Ok(ret)); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_output_stream_write_all_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("OutputStream requires GLib >= 2.44");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_output_stream_splice_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gssize result = g_output_stream_splice_finish(GOutputStream_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_long(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_output_stream_splice(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GError *error = NULL;

gssize result = g_output_stream_splice(GOutputStream_val(self), GInputStream_val(arg1), GioOutputStreamSpliceFlags_val(arg2), Option_val(arg3, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_long(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_output_stream_set_pending(value self)
{
CAMLparam1(self);
GError *error = NULL;

gboolean result = g_output_stream_set_pending(GOutputStream_val(self), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if GLIB_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_g_output_stream_is_closing(value self)
{
CAMLparam1(self);

gboolean result = g_output_stream_is_closing(GOutputStream_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_output_stream_is_closing(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("OutputStream requires GLib >= 2.24");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_output_stream_is_closed(value self)
{
CAMLparam1(self);

gboolean result = g_output_stream_is_closed(GOutputStream_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_output_stream_has_pending(value self)
{
CAMLparam1(self);

gboolean result = g_output_stream_has_pending(GOutputStream_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_output_stream_flush_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_output_stream_flush_finish(GOutputStream_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_output_stream_flush(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_output_stream_flush(GOutputStream_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_output_stream_close_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_output_stream_close_finish(GOutputStream_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_output_stream_close(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_output_stream_close(GOutputStream_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_output_stream_clear_pending(value self)
{
CAMLparam1(self);

g_output_stream_clear_pending(GOutputStream_val(self));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gio_output_stream_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_output_stream_get_type()));
}
