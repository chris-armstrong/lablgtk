/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ContentFormatsBuilder */

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

/* Conversion functions for GdkContentFormatsBuilder (opaque record with hidden fields) */
GdkContentFormatsBuilder *GdkContentFormatsBuilder_val(value v) {
  return (GdkContentFormatsBuilder *)ml_gir_record_ptr_val(v, "GdkContentFormatsBuilder");
}

value Val_GdkContentFormatsBuilder(const GdkContentFormatsBuilder *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gdk_content_formats_builder_get_type(), ptr);
}

value Val_GdkContentFormatsBuilder_option(const GdkContentFormatsBuilder *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GdkContentFormatsBuilder(ptr));
}


CAMLexport CAMLprim value ml_gdk_content_formats_builder_new(value unit)
{
CAMLparam1(unit);

GdkContentFormatsBuilder *obj = gdk_content_formats_builder_new();

CAMLreturn(Val_GdkContentFormatsBuilder(obj));
}
CAMLexport CAMLprim value ml_gdk_content_formats_builder_to_formats(value self)
{
CAMLparam1(self);

GdkContentFormats* result = gdk_content_formats_builder_to_formats(GdkContentFormatsBuilder_val(self));
CAMLreturn(Val_GdkContentFormats(result));
}

CAMLexport CAMLprim value ml_gdk_content_formats_builder_ref(value self)
{
CAMLparam1(self);

GdkContentFormatsBuilder* result = gdk_content_formats_builder_ref(GdkContentFormatsBuilder_val(self));
if (result) result = g_boxed_copy(gdk_content_formats_builder_get_type(), result);
CAMLreturn(Val_GdkContentFormatsBuilder(result));
}

CAMLexport CAMLprim value ml_gdk_content_formats_builder_add_mime_type(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_content_formats_builder_add_mime_type(GdkContentFormatsBuilder_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_content_formats_builder_add_gtype(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_content_formats_builder_add_gtype(GdkContentFormatsBuilder_val(self), GType_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_content_formats_builder_add_formats(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_content_formats_builder_add_formats(GdkContentFormatsBuilder_val(self), GdkContentFormats_val(arg1));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gdk_content_formats_builder_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_content_formats_builder_get_type()));
}
