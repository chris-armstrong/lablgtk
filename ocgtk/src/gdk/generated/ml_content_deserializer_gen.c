/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ContentDeserializer */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gdk/gdk.h>
/* Include library-specific type conversions and forward declarations */
#include "gdk_decls.h"


CAMLexport CAMLprim value ml_gdk_content_deserializer_return_success(value self)
{
CAMLparam1(self);

gdk_content_deserializer_return_success(GdkContentDeserializer_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_content_deserializer_return_error(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_content_deserializer_return_error(GdkContentDeserializer_val(self), GError_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_content_deserializer_get_value(value self)
{
CAMLparam1(self);

GValue* result = gdk_content_deserializer_get_value(GdkContentDeserializer_val(self));
CAMLreturn(Val_GValue_copy(result));
}

CAMLexport CAMLprim value ml_gdk_content_deserializer_get_priority(value self)
{
CAMLparam1(self);

int result = gdk_content_deserializer_get_priority(GdkContentDeserializer_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_content_deserializer_get_mime_type(value self)
{
CAMLparam1(self);

const char* result = gdk_content_deserializer_get_mime_type(GdkContentDeserializer_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gdk_content_deserializer_get_input_stream(value self)
{
CAMLparam1(self);

GInputStream* result = gdk_content_deserializer_get_input_stream(GdkContentDeserializer_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GInputStream(result));
}

CAMLexport CAMLprim value ml_gdk_content_deserializer_get_gtype(value self)
{
CAMLparam1(self);

GType result = gdk_content_deserializer_get_gtype(GdkContentDeserializer_val(self));
CAMLreturn(Val_GType(result));
}

CAMLexport CAMLprim value ml_gdk_content_deserializer_get_cancellable(value self)
{
CAMLparam1(self);

GCancellable* result = gdk_content_deserializer_get_cancellable(GdkContentDeserializer_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GCancellable));
}


CAMLprim value ml_gdk_content_deserializer_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_content_deserializer_get_type()));
}
