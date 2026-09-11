/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ContentFormats */

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

/* Conversion functions for GdkContentFormats (opaque record with hidden fields) */
GdkContentFormats *GdkContentFormats_val(value v) {
  return (GdkContentFormats *)ml_gir_record_ptr_val(v, "GdkContentFormats");
}

value Val_GdkContentFormats(const GdkContentFormats *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gdk_content_formats_get_type(), ptr);
}

value Val_GdkContentFormats_option(const GdkContentFormats *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GdkContentFormats(ptr));
}


CAMLexport CAMLprim value ml_gdk_content_formats_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
    int arg1_length = 0;
    const char** c_arg1 = NULL;
    
    if (Is_some(arg1)) {
        value array = Some_val(arg1);
        arg1_length = Wosize_val(array);
        c_arg1 = (const char**)g_malloc(sizeof(const char*) * arg1_length);
        for (int i = 0; i < arg1_length; i++) {
          c_arg1[i] = String_val(Field(array, i));
        }
    }

GdkContentFormats *obj = gdk_content_formats_new(c_arg1, Int_val(arg2));

    if (c_arg1) g_free(c_arg1);
CAMLreturn(Val_GdkContentFormats(obj));
}
CAMLexport CAMLprim value ml_gdk_content_formats_new_for_gtype(value arg1)
{
CAMLparam1(arg1);

GdkContentFormats *obj = gdk_content_formats_new_for_gtype(GType_val(arg1));

CAMLreturn(Val_GdkContentFormats(obj));
}
CAMLexport CAMLprim value ml_gdk_content_formats_union_serialize_mime_types(value self)
{
CAMLparam1(self);

GdkContentFormats* result = gdk_content_formats_union_serialize_mime_types(GdkContentFormats_val(self));
CAMLreturn(Val_GdkContentFormats(result));
}

CAMLexport CAMLprim value ml_gdk_content_formats_union_serialize_gtypes(value self)
{
CAMLparam1(self);

GdkContentFormats* result = gdk_content_formats_union_serialize_gtypes(GdkContentFormats_val(self));
CAMLreturn(Val_GdkContentFormats(result));
}

CAMLexport CAMLprim value ml_gdk_content_formats_union_deserialize_mime_types(value self)
{
CAMLparam1(self);

GdkContentFormats* result = gdk_content_formats_union_deserialize_mime_types(GdkContentFormats_val(self));
CAMLreturn(Val_GdkContentFormats(result));
}

CAMLexport CAMLprim value ml_gdk_content_formats_union_deserialize_gtypes(value self)
{
CAMLparam1(self);

GdkContentFormats* result = gdk_content_formats_union_deserialize_gtypes(GdkContentFormats_val(self));
CAMLreturn(Val_GdkContentFormats(result));
}

CAMLexport CAMLprim value ml_gdk_content_formats_union(value self, value arg1)
{
CAMLparam2(self, arg1);

GdkContentFormats* result = gdk_content_formats_union(GdkContentFormats_val(self), GdkContentFormats_val(arg1));
CAMLreturn(Val_GdkContentFormats(result));
}

CAMLexport CAMLprim value ml_gdk_content_formats_to_string(value self)
{
CAMLparam1(self);

char* result = gdk_content_formats_to_string(GdkContentFormats_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gdk_content_formats_ref(value self)
{
CAMLparam1(self);

GdkContentFormats* result = gdk_content_formats_ref(GdkContentFormats_val(self));
CAMLreturn(Val_GdkContentFormats(result));
}

CAMLexport CAMLprim value ml_gdk_content_formats_match_mime_type(value self, value arg1)
{
CAMLparam2(self, arg1);

const char* result = gdk_content_formats_match_mime_type(GdkContentFormats_val(self), GdkContentFormats_val(arg1));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gdk_content_formats_match_gtype(value self, value arg1)
{
CAMLparam2(self, arg1);

GType result = gdk_content_formats_match_gtype(GdkContentFormats_val(self), GdkContentFormats_val(arg1));
CAMLreturn(Val_GType(result));
}

CAMLexport CAMLprim value ml_gdk_content_formats_match(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gdk_content_formats_match(GdkContentFormats_val(self), GdkContentFormats_val(arg1));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,18,0)

CAMLexport CAMLprim value ml_gdk_content_formats_is_empty(value self)
{
CAMLparam1(self);

gboolean result = gdk_content_formats_is_empty(GdkContentFormats_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gdk_content_formats_is_empty(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ContentFormats requires GTK >= 4.18");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_content_formats_get_mime_types(value self)
{
CAMLparam1(self);
gsize out1;

const char* const* result = gdk_content_formats_get_mime_types(GdkContentFormats_val(self), &out1);
    CAMLlocal2(ml_result, ml_result_opt);
    if (result == NULL) {
      ml_result_opt = Val_none;
    } else {
      int result_length = out1;
      ml_result = caml_alloc(result_length, 0);
      for (int i = 0; i < result_length; i++) {
        Store_field(ml_result, i, caml_copy_string(result[i]));
      }
      ml_result_opt = Val_some(ml_result);
          }
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_result_opt);
    Store_field(ret, 1, Val_gsize(out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gdk_content_formats_get_gtypes(value self)
{
CAMLparam1(self);
gsize out1;

const GType* result = gdk_content_formats_get_gtypes(GdkContentFormats_val(self), &out1);
    CAMLlocal2(ml_result, ml_result_opt);
    if (result == NULL) {
      ml_result_opt = Val_none;
    } else {
      int result_length = out1;
      ml_result = caml_alloc(result_length, 0);
      for (int i = 0; i < result_length; i++) {
        Store_field(ml_result, i, Val_GType(result[i]));
      }
      ml_result_opt = Val_some(ml_result);
          }
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_result_opt);
    Store_field(ret, 1, Val_gsize(out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gdk_content_formats_contain_mime_type(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gdk_content_formats_contain_mime_type(GdkContentFormats_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_content_formats_contain_gtype(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gdk_content_formats_contain_gtype(GdkContentFormats_val(self), GType_val(arg1));
CAMLreturn(Val_bool(result));
}

GType gdk_content_formats_get_type (void);


CAMLprim value ml_gdk_content_formats_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_content_formats_get_type()));
}
