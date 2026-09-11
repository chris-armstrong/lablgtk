/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Transform */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gsk/gsk.h>
/* Include library-specific type conversions and forward declarations */
#include "gsk_decls.h"

/* Conversion functions for GskTransform (opaque record with hidden fields) */
GskTransform *GskTransform_val(value v) {
  return (GskTransform *)ml_gir_record_ptr_val(v, "GskTransform");
}

value Val_GskTransform(const GskTransform *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gsk_transform_get_type(), ptr);
}

value Val_GskTransform_option(const GskTransform *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GskTransform(ptr));
}


CAMLexport CAMLprim value ml_gsk_transform_new(value unit)
{
CAMLparam1(unit);

GskTransform *obj = gsk_transform_new();

CAMLreturn(Val_GskTransform(obj));
}
CAMLexport CAMLprim value ml_gsk_transform_translate_3d(value self, value arg1)
{
CAMLparam2(self, arg1);

GskTransform* result = gsk_transform_translate_3d(GskTransform_val(self), graphene_point3d_t_val(arg1));
CAMLreturn(Val_option(result, Val_GskTransform));
}

CAMLexport CAMLprim value ml_gsk_transform_translate(value self, value arg1)
{
CAMLparam2(self, arg1);

GskTransform* result = gsk_transform_translate(GskTransform_val(self), graphene_point_t_val(arg1));
CAMLreturn(Val_option(result, Val_GskTransform));
}

CAMLexport CAMLprim value ml_gsk_transform_transform_point(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_point_t out2;

gsk_transform_transform_point(GskTransform_val(self), graphene_point_t_val(arg1), &out2);
CAMLreturn(Val_graphene_point_t(&out2));
}

CAMLexport CAMLprim value ml_gsk_transform_transform_bounds(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_rect_t out2;

gsk_transform_transform_bounds(GskTransform_val(self), graphene_rect_t_val(arg1), &out2);
CAMLreturn(Val_graphene_rect_t(&out2));
}

CAMLexport CAMLprim value ml_gsk_transform_transform(value self, value arg1)
{
CAMLparam2(self, arg1);

GskTransform* result = gsk_transform_transform(GskTransform_val(self), Option_val(arg1, GskTransform_val, NULL));
CAMLreturn(Val_option(result, Val_GskTransform));
}

CAMLexport CAMLprim value ml_gsk_transform_to_translate(value self)
{
CAMLparam1(self);
float out1;
float out2;

gsk_transform_to_translate(GskTransform_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, caml_copy_double(out1));
    Store_field(ret, 1, caml_copy_double(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gsk_transform_to_string(value self)
{
CAMLparam1(self);

char* result = gsk_transform_to_string(GskTransform_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gsk_transform_to_matrix(value self)
{
CAMLparam1(self);
graphene_matrix_t out1;

gsk_transform_to_matrix(GskTransform_val(self), &out1);
CAMLreturn(Val_graphene_matrix_t(&out1));
}

CAMLexport CAMLprim value ml_gsk_transform_to_affine(value self)
{
CAMLparam1(self);
float out1;
float out2;
float out3;
float out4;

gsk_transform_to_affine(GskTransform_val(self), &out1, &out2, &out3, &out4);
CAMLlocal1(ret);
    ret = caml_alloc(4, 0);
    Store_field(ret, 0, caml_copy_double(out1));
    Store_field(ret, 1, caml_copy_double(out2));
    Store_field(ret, 2, caml_copy_double(out3));
    Store_field(ret, 3, caml_copy_double(out4));
    CAMLreturn(ret);
}

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gsk_transform_to_2d_components(value self)
{
CAMLparam1(self);
float out1;
float out2;
float out3;
float out4;
float out5;
float out6;
float out7;

gsk_transform_to_2d_components(GskTransform_val(self), &out1, &out2, &out3, &out4, &out5, &out6, &out7);
CAMLlocal1(ret);
    ret = caml_alloc(7, 0);
    Store_field(ret, 0, caml_copy_double(out1));
    Store_field(ret, 1, caml_copy_double(out2));
    Store_field(ret, 2, caml_copy_double(out3));
    Store_field(ret, 3, caml_copy_double(out4));
    Store_field(ret, 4, caml_copy_double(out5));
    Store_field(ret, 5, caml_copy_double(out6));
    Store_field(ret, 6, caml_copy_double(out7));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_gsk_transform_to_2d_components(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Transform requires GTK >= 4.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gsk_transform_to_2d(value self)
{
CAMLparam1(self);
float out1;
float out2;
float out3;
float out4;
float out5;
float out6;

gsk_transform_to_2d(GskTransform_val(self), &out1, &out2, &out3, &out4, &out5, &out6);
CAMLlocal1(ret);
    ret = caml_alloc(6, 0);
    Store_field(ret, 0, caml_copy_double(out1));
    Store_field(ret, 1, caml_copy_double(out2));
    Store_field(ret, 2, caml_copy_double(out3));
    Store_field(ret, 3, caml_copy_double(out4));
    Store_field(ret, 4, caml_copy_double(out5));
    Store_field(ret, 5, caml_copy_double(out6));
    CAMLreturn(ret);
}

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gsk_transform_skew(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

GskTransform* result = gsk_transform_skew(GskTransform_val(self), Double_val(arg1), Double_val(arg2));
CAMLreturn(Val_option(result, Val_GskTransform));
}

#else

CAMLexport CAMLprim value ml_gsk_transform_skew(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Transform requires GTK >= 4.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gsk_transform_scale_3d(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

GskTransform* result = gsk_transform_scale_3d(GskTransform_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3));
CAMLreturn(Val_option(result, Val_GskTransform));
}

CAMLexport CAMLprim value ml_gsk_transform_scale(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

GskTransform* result = gsk_transform_scale(GskTransform_val(self), Double_val(arg1), Double_val(arg2));
CAMLreturn(Val_option(result, Val_GskTransform));
}

CAMLexport CAMLprim value ml_gsk_transform_rotate_3d(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

GskTransform* result = gsk_transform_rotate_3d(GskTransform_val(self), Double_val(arg1), graphene_vec3_t_val(arg2));
CAMLreturn(Val_option(result, Val_GskTransform));
}

CAMLexport CAMLprim value ml_gsk_transform_rotate(value self, value arg1)
{
CAMLparam2(self, arg1);

GskTransform* result = gsk_transform_rotate(GskTransform_val(self), Double_val(arg1));
CAMLreturn(Val_option(result, Val_GskTransform));
}

CAMLexport CAMLprim value ml_gsk_transform_ref(value self)
{
CAMLparam1(self);

GskTransform* result = gsk_transform_ref(GskTransform_val(self));
if (result) result = g_boxed_copy(gsk_transform_get_type(), result);
CAMLreturn(Val_option(result, Val_GskTransform));
}

CAMLexport CAMLprim value ml_gsk_transform_perspective(value self, value arg1)
{
CAMLparam2(self, arg1);

GskTransform* result = gsk_transform_perspective(GskTransform_val(self), Double_val(arg1));
CAMLreturn(Val_GskTransform(result));
}

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gsk_transform_matrix_2d_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam2(arg5, arg6);

GskTransform* result = gsk_transform_matrix_2d(GskTransform_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5), Double_val(arg6));
CAMLreturn(Val_option(result, Val_GskTransform));}

CAMLexport CAMLprim value ml_gsk_transform_matrix_2d_bytecode(value * argv, int argn)
{
return ml_gsk_transform_matrix_2d_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

#else

CAMLexport CAMLprim value ml_gsk_transform_matrix_2d(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
(void)arg6;
caml_failwith("Transform requires GTK >= 4.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gsk_transform_matrix(value self, value arg1)
{
CAMLparam2(self, arg1);

GskTransform* result = gsk_transform_matrix(GskTransform_val(self), graphene_matrix_t_val(arg1));
CAMLreturn(Val_GskTransform(result));
}

CAMLexport CAMLprim value ml_gsk_transform_invert(value self)
{
CAMLparam1(self);

GskTransform* result = gsk_transform_invert(GskTransform_val(self));
CAMLreturn(Val_option(result, Val_GskTransform));
}

CAMLexport CAMLprim value ml_gsk_transform_get_category(value self)
{
CAMLparam1(self);

GskTransformCategory result = gsk_transform_get_category(GskTransform_val(self));
CAMLreturn(Val_GskTransformCategory(result));
}

CAMLexport CAMLprim value ml_gsk_transform_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gsk_transform_equal(GskTransform_val(self), Option_val(arg1, GskTransform_val, NULL));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_gsk_transform_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_transform_get_type()));
}
