/* GENERATED CODE - DO NOT EDIT */
/* C bindings for InputStream */

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


CAMLexport CAMLprim value ml_g_input_stream_skip_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gssize result = g_input_stream_skip_finish(GInputStream_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_long(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_input_stream_skip(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gssize result = g_input_stream_skip(GInputStream_val(self), Gsize_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_long(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_input_stream_set_pending(value self)
{
CAMLparam1(self);
GError *error = NULL;

gboolean result = g_input_stream_set_pending(GInputStream_val(self), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_input_stream_read_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gssize result = g_input_stream_read_finish(GInputStream_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_long(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_input_stream_read_bytes_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GBytes* result = g_input_stream_read_bytes_finish(GInputStream_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GBytes(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_input_stream_read_bytes_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("InputStream requires GLib >= 2.34");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_input_stream_read_bytes(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

GBytes* result = g_input_stream_read_bytes(GInputStream_val(self), Gsize_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GBytes(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_input_stream_read_bytes(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("InputStream requires GLib >= 2.34");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,44,0)

CAMLexport CAMLprim value ml_g_input_stream_read_all_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;
gsize out2;

gboolean result = g_input_stream_read_all_finish(GInputStream_val(self), GAsyncResult_val(arg1), &out2, &error);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_gsize(out2));
    if (error == NULL) CAMLreturn(Res_Ok(ret)); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_input_stream_read_all_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("InputStream requires GLib >= 2.44");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_input_stream_is_closed(value self)
{
CAMLparam1(self);

gboolean result = g_input_stream_is_closed(GInputStream_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_input_stream_has_pending(value self)
{
CAMLparam1(self);

gboolean result = g_input_stream_has_pending(GInputStream_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_input_stream_close_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_input_stream_close_finish(GInputStream_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_input_stream_close(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_input_stream_close(GInputStream_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_input_stream_clear_pending(value self)
{
CAMLparam1(self);

g_input_stream_clear_pending(GInputStream_val(self));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gio_input_stream_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_input_stream_get_type()));
}
