/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DataInputStream */

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


CAMLexport CAMLprim value ml_g_data_input_stream_new(value arg1)
{
CAMLparam1(arg1);

GDataInputStream *obj = g_data_input_stream_new(GInputStream_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GDataInputStream(obj));
}
CAMLexport CAMLprim value ml_g_data_input_stream_set_newline_type(value self, value arg1)
{
CAMLparam2(self, arg1);

g_data_input_stream_set_newline_type(GDataInputStream_val(self), GioDataStreamNewlineType_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_data_input_stream_set_byte_order(value self, value arg1)
{
CAMLparam2(self, arg1);

g_data_input_stream_set_byte_order(GDataInputStream_val(self), GioDataStreamByteOrder_val(arg1));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_g_data_input_stream_read_upto_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;
gsize out2;

char* result = g_data_input_stream_read_upto_finish(GDataInputStream_val(self), GAsyncResult_val(arg1), &out2, &error);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, caml_copy_string(result));
    Store_field(ret, 1, Val_gsize(out2));
    if (error == NULL) CAMLreturn(Res_Ok(ret)); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_data_input_stream_read_upto_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DataInputStream requires GLib >= 2.24");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_data_input_stream_read_upto(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GError *error = NULL;
gsize out3;

char* result = g_data_input_stream_read_upto(GDataInputStream_val(self), String_val(arg1), Long_val(arg2), &out3, Option_val(arg3, GCancellable_val, NULL), &error);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, caml_copy_string(result));
    Store_field(ret, 1, Val_gsize(out3));
    if (error == NULL) CAMLreturn(Res_Ok(ret)); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_data_input_stream_read_upto(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("DataInputStream requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,20,0)

CAMLexport CAMLprim value ml_g_data_input_stream_read_until_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;
gsize out2;

char* result = g_data_input_stream_read_until_finish(GDataInputStream_val(self), GAsyncResult_val(arg1), &out2, &error);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, caml_copy_string(result));
    Store_field(ret, 1, Val_gsize(out2));
    if (error == NULL) CAMLreturn(Res_Ok(ret)); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_data_input_stream_read_until_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DataInputStream requires GLib >= 2.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_data_input_stream_read_until(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;
gsize out2;

char* result = g_data_input_stream_read_until(GDataInputStream_val(self), String_val(arg1), &out2, Option_val(arg2, GCancellable_val, NULL), &error);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, caml_copy_string(result));
    Store_field(ret, 1, Val_gsize(out2));
    if (error == NULL) CAMLreturn(Res_Ok(ret)); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_data_input_stream_read_uint64(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

guint64 result = g_data_input_stream_read_uint64(GDataInputStream_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(integers_copy_uint64(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_data_input_stream_read_uint32(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

guint32 result = g_data_input_stream_read_uint32(GDataInputStream_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_uint32(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_data_input_stream_read_uint16(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

guint16 result = g_data_input_stream_read_uint16(GDataInputStream_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_uint16(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if GLIB_CHECK_VERSION(2,30,0)

CAMLexport CAMLprim value ml_g_data_input_stream_read_line_utf8(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;
gsize out1;

char* result = g_data_input_stream_read_line_utf8(GDataInputStream_val(self), &out1, Option_val(arg1, GCancellable_val, NULL), &error);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_option_string(result));
    Store_field(ret, 1, Val_gsize(out1));
    if (error == NULL) CAMLreturn(Res_Ok(ret)); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_data_input_stream_read_line_utf8(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DataInputStream requires GLib >= 2.30");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,30,0)

CAMLexport CAMLprim value ml_g_data_input_stream_read_line_finish_utf8(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;
gsize out2;

char* result = g_data_input_stream_read_line_finish_utf8(GDataInputStream_val(self), GAsyncResult_val(arg1), &out2, &error);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_option_string(result));
    Store_field(ret, 1, Val_gsize(out2));
    if (error == NULL) CAMLreturn(Res_Ok(ret)); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_data_input_stream_read_line_finish_utf8(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DataInputStream requires GLib >= 2.30");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_data_input_stream_read_int64(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gint64 result = g_data_input_stream_read_int64(GDataInputStream_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(caml_copy_int64(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_data_input_stream_read_int32(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gint32 result = g_data_input_stream_read_int32(GDataInputStream_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_int32_bounded(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_data_input_stream_read_int16(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gint16 result = g_data_input_stream_read_int16(GDataInputStream_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_int16(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_data_input_stream_get_newline_type(value self)
{
CAMLparam1(self);

GDataStreamNewlineType result = g_data_input_stream_get_newline_type(GDataInputStream_val(self));
CAMLreturn(Val_GioDataStreamNewlineType(result));
}

CAMLexport CAMLprim value ml_g_data_input_stream_get_byte_order(value self)
{
CAMLparam1(self);

GDataStreamByteOrder result = g_data_input_stream_get_byte_order(GDataInputStream_val(self));
CAMLreturn(Val_GioDataStreamByteOrder(result));
}

GType g_data_input_stream_get_type (void);


CAMLprim value ml_gio_data_input_stream_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_data_input_stream_get_type()));
}
