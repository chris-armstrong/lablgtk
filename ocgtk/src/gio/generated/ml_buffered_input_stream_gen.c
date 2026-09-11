/* GENERATED CODE - DO NOT EDIT */
/* C bindings for BufferedInputStream */

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


CAMLexport CAMLprim value ml_g_buffered_input_stream_new(value arg1)
{
CAMLparam1(arg1);

GBufferedInputStream *obj = g_buffered_input_stream_new(GInputStream_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GBufferedInputStream(obj));
}
CAMLexport CAMLprim value ml_g_buffered_input_stream_new_sized(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GBufferedInputStream *obj = g_buffered_input_stream_new_sized(GInputStream_val(arg1), Gsize_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GBufferedInputStream(obj));
}
CAMLexport CAMLprim value ml_g_buffered_input_stream_set_buffer_size(value self, value arg1)
{
CAMLparam2(self, arg1);

g_buffered_input_stream_set_buffer_size(GBufferedInputStream_val(self), Gsize_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_buffered_input_stream_read_byte(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

int result = g_buffered_input_stream_read_byte(GBufferedInputStream_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_int(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_buffered_input_stream_get_buffer_size(value self)
{
CAMLparam1(self);

gsize result = g_buffered_input_stream_get_buffer_size(GBufferedInputStream_val(self));
CAMLreturn(Val_gsize(result));
}

CAMLexport CAMLprim value ml_g_buffered_input_stream_get_available(value self)
{
CAMLparam1(self);

gsize result = g_buffered_input_stream_get_available(GBufferedInputStream_val(self));
CAMLreturn(Val_gsize(result));
}

CAMLexport CAMLprim value ml_g_buffered_input_stream_fill_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gssize result = g_buffered_input_stream_fill_finish(GBufferedInputStream_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_long(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_buffered_input_stream_fill(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gssize result = g_buffered_input_stream_fill(GBufferedInputStream_val(self), Long_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_long(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}


CAMLprim value ml_gio_buffered_input_stream_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_buffered_input_stream_get_type()));
}
