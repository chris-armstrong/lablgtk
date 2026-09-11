/* GENERATED CODE - DO NOT EDIT */
/* C bindings for BufferedOutputStream */

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


CAMLexport CAMLprim value ml_g_buffered_output_stream_new(value arg1)
{
CAMLparam1(arg1);

GBufferedOutputStream *obj = g_buffered_output_stream_new(GOutputStream_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GBufferedOutputStream(obj));
}
CAMLexport CAMLprim value ml_g_buffered_output_stream_new_sized(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GBufferedOutputStream *obj = g_buffered_output_stream_new_sized(GOutputStream_val(arg1), Gsize_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GBufferedOutputStream(obj));
}
CAMLexport CAMLprim value ml_g_buffered_output_stream_set_buffer_size(value self, value arg1)
{
CAMLparam2(self, arg1);

g_buffered_output_stream_set_buffer_size(GBufferedOutputStream_val(self), Gsize_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_buffered_output_stream_set_auto_grow(value self, value arg1)
{
CAMLparam2(self, arg1);

g_buffered_output_stream_set_auto_grow(GBufferedOutputStream_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_buffered_output_stream_get_buffer_size(value self)
{
CAMLparam1(self);

gsize result = g_buffered_output_stream_get_buffer_size(GBufferedOutputStream_val(self));
CAMLreturn(Val_gsize(result));
}

CAMLexport CAMLprim value ml_g_buffered_output_stream_get_auto_grow(value self)
{
CAMLparam1(self);

gboolean result = g_buffered_output_stream_get_auto_grow(GBufferedOutputStream_val(self));
CAMLreturn(Val_bool(result));
}

GType g_buffered_output_stream_get_type (void);


CAMLprim value ml_gio_buffered_output_stream_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_buffered_output_stream_get_type()));
}
