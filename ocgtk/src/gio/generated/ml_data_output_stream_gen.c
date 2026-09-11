/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DataOutputStream */

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


CAMLexport CAMLprim value ml_g_data_output_stream_new(value arg1)
{
CAMLparam1(arg1);

GDataOutputStream *obj = g_data_output_stream_new(GOutputStream_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GDataOutputStream(obj));
}
CAMLexport CAMLprim value ml_g_data_output_stream_set_byte_order(value self, value arg1)
{
CAMLparam2(self, arg1);

g_data_output_stream_set_byte_order(GDataOutputStream_val(self), GioDataStreamByteOrder_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_data_output_stream_put_uint64(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gboolean result = g_data_output_stream_put_uint64(GDataOutputStream_val(self), Uint64_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_data_output_stream_put_uint32(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gboolean result = g_data_output_stream_put_uint32(GDataOutputStream_val(self), UInt32_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_data_output_stream_put_uint16(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gboolean result = g_data_output_stream_put_uint16(GDataOutputStream_val(self), UInt16_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_data_output_stream_put_string(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gboolean result = g_data_output_stream_put_string(GDataOutputStream_val(self), String_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_data_output_stream_put_int64(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gboolean result = g_data_output_stream_put_int64(GDataOutputStream_val(self), Int64_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_data_output_stream_put_int32(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gboolean result = g_data_output_stream_put_int32(GDataOutputStream_val(self), Int32_val_bounded(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_data_output_stream_put_int16(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gboolean result = g_data_output_stream_put_int16(GDataOutputStream_val(self), Int16_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_data_output_stream_get_byte_order(value self)
{
CAMLparam1(self);

GDataStreamByteOrder result = g_data_output_stream_get_byte_order(GDataOutputStream_val(self));
CAMLreturn(Val_GioDataStreamByteOrder(result));
}

GType g_data_output_stream_get_type (void);


CAMLprim value ml_gio_data_output_stream_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_data_output_stream_get_type()));
}
