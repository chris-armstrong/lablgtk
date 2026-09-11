/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Matrix */

#include <graphene.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <graphene-gobject.h>
/* Include library-specific type conversions and forward declarations */
#include "graphene_decls.h"

/* Conversion functions for graphene_matrix_t (opaque record with hidden fields) */
graphene_matrix_t *graphene_matrix_t_val(value v) {
  return (graphene_matrix_t *)ml_gir_record_ptr_val(v, "graphene_matrix_t");
}

value Val_graphene_matrix_t(const graphene_matrix_t *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(graphene_matrix_get_type(), ptr);
}

value Val_graphene_matrix_t_option(const graphene_matrix_t *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_graphene_matrix_t(ptr));
}


#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_alloc(value unit)
{
CAMLparam1(unit);

graphene_matrix_t *obj = graphene_matrix_alloc();

CAMLreturn(Val_graphene_matrix_t(obj));
}
#else

CAMLexport CAMLprim value ml_graphene_matrix_alloc(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_untransform_point(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
graphene_point_t out3;

bool result = graphene_matrix_untransform_point(graphene_matrix_t_val(self), graphene_point_t_val(arg1), graphene_rect_t_val(arg2), &out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_graphene_point_t(&out3));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_untransform_point(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_untransform_bounds(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
graphene_rect_t out3;

graphene_matrix_untransform_bounds(graphene_matrix_t_val(self), graphene_rect_t_val(arg1), graphene_rect_t_val(arg2), &out3);
CAMLreturn(Val_graphene_rect_t(&out3));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_untransform_bounds(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,2,0)

CAMLexport CAMLprim value ml_graphene_matrix_unproject_point3d(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
graphene_point3d_t out3;

graphene_matrix_unproject_point3d(graphene_matrix_t_val(self), graphene_matrix_t_val(arg1), graphene_point3d_t_val(arg2), &out3);
CAMLreturn(Val_graphene_point3d_t(&out3));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_unproject_point3d(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Matrix requires Graphene >= 1.2");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_transpose(value self)
{
CAMLparam1(self);
graphene_matrix_t out1;

graphene_matrix_transpose(graphene_matrix_t_val(self), &out1);
CAMLreturn(Val_graphene_matrix_t(&out1));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_transpose(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_translate(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_matrix_translate(graphene_matrix_t_val(self), graphene_point3d_t_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_translate(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_transform_vec4(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_vec4_t out2;

graphene_matrix_transform_vec4(graphene_matrix_t_val(self), graphene_vec4_t_val(arg1), &out2);
CAMLreturn(Val_graphene_vec4_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_transform_vec4(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_transform_vec3(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_vec3_t out2;

graphene_matrix_transform_vec3(graphene_matrix_t_val(self), graphene_vec3_t_val(arg1), &out2);
CAMLreturn(Val_graphene_vec3_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_transform_vec3(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,2,0)

CAMLexport CAMLprim value ml_graphene_matrix_transform_sphere(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_sphere_t out2;

graphene_matrix_transform_sphere(graphene_matrix_t_val(self), graphene_sphere_t_val(arg1), &out2);
CAMLreturn(Val_graphene_sphere_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_transform_sphere(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.2");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_transform_rect(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_quad_t out2;

graphene_matrix_transform_rect(graphene_matrix_t_val(self), graphene_rect_t_val(arg1), &out2);
CAMLreturn(Val_graphene_quad_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_transform_rect(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,4,0)

CAMLexport CAMLprim value ml_graphene_matrix_transform_ray(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_ray_t out2;

graphene_matrix_transform_ray(graphene_matrix_t_val(self), graphene_ray_t_val(arg1), &out2);
CAMLreturn(Val_graphene_ray_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_transform_ray(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.4");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,2,0)

CAMLexport CAMLprim value ml_graphene_matrix_transform_point3d(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_point3d_t out2;

graphene_matrix_transform_point3d(graphene_matrix_t_val(self), graphene_point3d_t_val(arg1), &out2);
CAMLreturn(Val_graphene_point3d_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_transform_point3d(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.2");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_transform_point(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_point_t out2;

graphene_matrix_transform_point(graphene_matrix_t_val(self), graphene_point_t_val(arg1), &out2);
CAMLreturn(Val_graphene_point_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_transform_point(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,2,0)

CAMLexport CAMLprim value ml_graphene_matrix_transform_box(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_box_t out2;

graphene_matrix_transform_box(graphene_matrix_t_val(self), graphene_box_t_val(arg1), &out2);
CAMLreturn(Val_graphene_box_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_transform_box(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.2");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_transform_bounds(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_rect_t out2;

graphene_matrix_transform_bounds(graphene_matrix_t_val(self), graphene_rect_t_val(arg1), &out2);
CAMLreturn(Val_graphene_rect_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_transform_bounds(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_to_float(value self)
{
CAMLparam1(self);
float out1[16];

graphene_matrix_to_float(graphene_matrix_t_val(self), out1);
    int out1_length = 16;
    CAMLlocal1(ml_out1);
    ml_out1 = caml_alloc(out1_length, 0);
    for (int i = 0; i < out1_length; i++) {
      Store_field(ml_out1, i, caml_copy_double(out1[i]));
    }

CAMLreturn(ml_out1);
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_to_float(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_to_2d(value self)
{
CAMLparam1(self);
double out1;
double out2;
double out3;
double out4;
double out5;
double out6;

bool result = graphene_matrix_to_2d(graphene_matrix_t_val(self), &out1, &out2, &out3, &out4, &out5, &out6);
CAMLlocal1(ret);
    ret = caml_alloc(7, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, caml_copy_double(out1));
    Store_field(ret, 2, caml_copy_double(out2));
    Store_field(ret, 3, caml_copy_double(out3));
    Store_field(ret, 4, caml_copy_double(out4));
    Store_field(ret, 5, caml_copy_double(out5));
    Store_field(ret, 6, caml_copy_double(out6));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_to_2d(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_skew_yz(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_matrix_skew_yz(graphene_matrix_t_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_skew_yz(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_skew_xz(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_matrix_skew_xz(graphene_matrix_t_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_skew_xz(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_skew_xy(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_matrix_skew_xy(graphene_matrix_t_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_skew_xy(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_scale(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

graphene_matrix_scale(graphene_matrix_t_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_scale(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_rotate_z(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_matrix_rotate_z(graphene_matrix_t_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_rotate_z(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_rotate_y(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_matrix_rotate_y(graphene_matrix_t_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_rotate_y(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_rotate_x(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_matrix_rotate_x(graphene_matrix_t_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_rotate_x(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,2,0)

CAMLexport CAMLprim value ml_graphene_matrix_rotate_quaternion(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_matrix_rotate_quaternion(graphene_matrix_t_val(self), graphene_quaternion_t_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_rotate_quaternion(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.2");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,2,0)

CAMLexport CAMLprim value ml_graphene_matrix_rotate_euler(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_matrix_rotate_euler(graphene_matrix_t_val(self), graphene_euler_t_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_rotate_euler(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.2");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_rotate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

graphene_matrix_rotate(graphene_matrix_t_val(self), Double_val(arg1), graphene_vec3_t_val(arg2));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_rotate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_project_rect_bounds(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_rect_t out2;

graphene_matrix_project_rect_bounds(graphene_matrix_t_val(self), graphene_rect_t_val(arg1), &out2);
CAMLreturn(Val_graphene_rect_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_project_rect_bounds(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,2,0)

CAMLexport CAMLprim value ml_graphene_matrix_project_rect(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_quad_t out2;

graphene_matrix_project_rect(graphene_matrix_t_val(self), graphene_rect_t_val(arg1), &out2);
CAMLreturn(Val_graphene_quad_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_project_rect(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.2");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_project_point(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_point_t out2;

graphene_matrix_project_point(graphene_matrix_t_val(self), graphene_point_t_val(arg1), &out2);
CAMLreturn(Val_graphene_point_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_project_point(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_print(value self)
{
CAMLparam1(self);

graphene_matrix_print(graphene_matrix_t_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_print(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_perspective(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_matrix_t out2;

graphene_matrix_perspective(graphene_matrix_t_val(self), Double_val(arg1), &out2);
CAMLreturn(Val_graphene_matrix_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_perspective(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_normalize(value self)
{
CAMLparam1(self);
graphene_matrix_t out1;

graphene_matrix_normalize(graphene_matrix_t_val(self), &out1);
CAMLreturn(Val_graphene_matrix_t(&out1));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_normalize(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_matrix_near(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

bool result = graphene_matrix_near(graphene_matrix_t_val(self), graphene_matrix_t_val(arg1), Double_val(arg2));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_near(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Matrix requires Graphene >= 1.10");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_multiply(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_matrix_t out2;

graphene_matrix_multiply(graphene_matrix_t_val(self), graphene_matrix_t_val(arg1), &out2);
CAMLreturn(Val_graphene_matrix_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_multiply(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_is_singular(value self)
{
CAMLparam1(self);

bool result = graphene_matrix_is_singular(graphene_matrix_t_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_is_singular(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_is_identity(value self)
{
CAMLparam1(self);

bool result = graphene_matrix_is_identity(graphene_matrix_t_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_is_identity(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_is_backface_visible(value self)
{
CAMLparam1(self);

bool result = graphene_matrix_is_backface_visible(graphene_matrix_t_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_is_backface_visible(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_is_2d(value self)
{
CAMLparam1(self);

bool result = graphene_matrix_is_2d(graphene_matrix_t_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_is_2d(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_inverse(value self)
{
CAMLparam1(self);
graphene_matrix_t out1;

bool result = graphene_matrix_inverse(graphene_matrix_t_val(self), &out1);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_graphene_matrix_t(&out1));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_inverse(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_interpolate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
graphene_matrix_t out3;

graphene_matrix_interpolate(graphene_matrix_t_val(self), graphene_matrix_t_val(arg1), Double_val(arg2), &out3);
CAMLreturn(Val_graphene_matrix_t(&out3));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_interpolate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_init_translate(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_matrix_t* result = graphene_matrix_init_translate(graphene_matrix_t_val(self), graphene_point3d_t_val(arg1));
if (result) result = g_boxed_copy(graphene_matrix_get_type(), result);
CAMLreturn(Val_graphene_matrix_t(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_init_translate(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_init_skew(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

graphene_matrix_t* result = graphene_matrix_init_skew(graphene_matrix_t_val(self), Double_val(arg1), Double_val(arg2));
if (result) result = g_boxed_copy(graphene_matrix_get_type(), result);
CAMLreturn(Val_graphene_matrix_t(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_init_skew(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_init_scale(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

graphene_matrix_t* result = graphene_matrix_init_scale(graphene_matrix_t_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3));
if (result) result = g_boxed_copy(graphene_matrix_get_type(), result);
CAMLreturn(Val_graphene_matrix_t(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_init_scale(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_init_rotate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

graphene_matrix_t* result = graphene_matrix_init_rotate(graphene_matrix_t_val(self), Double_val(arg1), graphene_vec3_t_val(arg2));
if (result) result = g_boxed_copy(graphene_matrix_get_type(), result);
CAMLreturn(Val_graphene_matrix_t(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_init_rotate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_init_perspective(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

graphene_matrix_t* result = graphene_matrix_init_perspective(graphene_matrix_t_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4));
if (result) result = g_boxed_copy(graphene_matrix_get_type(), result);
CAMLreturn(Val_graphene_matrix_t(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_init_perspective(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_init_ortho_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam2(arg5, arg6);

graphene_matrix_t* result = graphene_matrix_init_ortho(graphene_matrix_t_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5), Double_val(arg6));
if (result) result = g_boxed_copy(graphene_matrix_get_type(), result);
CAMLreturn(Val_graphene_matrix_t(result));}

CAMLexport CAMLprim value ml_graphene_matrix_init_ortho_bytecode(value * argv, int argn)
{
return ml_graphene_matrix_init_ortho_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_init_ortho(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
(void)arg6;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_init_look_at(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

graphene_matrix_t* result = graphene_matrix_init_look_at(graphene_matrix_t_val(self), graphene_vec3_t_val(arg1), graphene_vec3_t_val(arg2), graphene_vec3_t_val(arg3));
if (result) result = g_boxed_copy(graphene_matrix_get_type(), result);
CAMLreturn(Val_graphene_matrix_t(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_init_look_at(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_init_identity(value self)
{
CAMLparam1(self);

graphene_matrix_t* result = graphene_matrix_init_identity(graphene_matrix_t_val(self));
if (result) result = g_boxed_copy(graphene_matrix_get_type(), result);
CAMLreturn(Val_graphene_matrix_t(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_init_identity(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,2,0)

CAMLexport CAMLprim value ml_graphene_matrix_init_frustum_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam2(arg5, arg6);

graphene_matrix_t* result = graphene_matrix_init_frustum(graphene_matrix_t_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5), Double_val(arg6));
if (result) result = g_boxed_copy(graphene_matrix_get_type(), result);
CAMLreturn(Val_graphene_matrix_t(result));}

CAMLexport CAMLprim value ml_graphene_matrix_init_frustum_bytecode(value * argv, int argn)
{
return ml_graphene_matrix_init_frustum_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_init_frustum(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
(void)arg6;
caml_failwith("Matrix requires Graphene >= 1.2");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_init_from_vec4(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

graphene_matrix_t* result = graphene_matrix_init_from_vec4(graphene_matrix_t_val(self), graphene_vec4_t_val(arg1), graphene_vec4_t_val(arg2), graphene_vec4_t_val(arg3), graphene_vec4_t_val(arg4));
if (result) result = g_boxed_copy(graphene_matrix_get_type(), result);
CAMLreturn(Val_graphene_matrix_t(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_init_from_vec4(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_init_from_matrix(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_matrix_t* result = graphene_matrix_init_from_matrix(graphene_matrix_t_val(self), graphene_matrix_t_val(arg1));
if (result) result = g_boxed_copy(graphene_matrix_get_type(), result);
CAMLreturn(Val_graphene_matrix_t(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_init_from_matrix(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_init_from_float(value self, value arg1)
{
CAMLparam2(self, arg1);
    int arg1_length = Wosize_val(arg1);
    float* c_arg1 = (float*)g_malloc(sizeof(float) * arg1_length);
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = Double_val(Field(arg1, i));
    }

graphene_matrix_t* result = graphene_matrix_init_from_float(graphene_matrix_t_val(self), c_arg1);
if (result) result = g_boxed_copy(graphene_matrix_get_type(), result);
    g_free(c_arg1);
CAMLreturn(Val_graphene_matrix_t(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_init_from_float(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_init_from_2d_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam2(arg5, arg6);

graphene_matrix_t* result = graphene_matrix_init_from_2d(graphene_matrix_t_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5), Double_val(arg6));
if (result) result = g_boxed_copy(graphene_matrix_get_type(), result);
CAMLreturn(Val_graphene_matrix_t(result));}

CAMLexport CAMLprim value ml_graphene_matrix_init_from_2d_bytecode(value * argv, int argn)
{
return ml_graphene_matrix_init_from_2d_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_init_from_2d(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
(void)arg6;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_matrix_get_z_translation(value self)
{
CAMLparam1(self);

float result = graphene_matrix_get_z_translation(graphene_matrix_t_val(self));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_get_z_translation(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Graphene >= 1.10");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_get_z_scale(value self)
{
CAMLparam1(self);

float result = graphene_matrix_get_z_scale(graphene_matrix_t_val(self));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_get_z_scale(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_matrix_get_y_translation(value self)
{
CAMLparam1(self);

float result = graphene_matrix_get_y_translation(graphene_matrix_t_val(self));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_get_y_translation(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Graphene >= 1.10");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_get_y_scale(value self)
{
CAMLparam1(self);

float result = graphene_matrix_get_y_scale(graphene_matrix_t_val(self));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_get_y_scale(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_matrix_get_x_translation(value self)
{
CAMLparam1(self);

float result = graphene_matrix_get_x_translation(graphene_matrix_t_val(self));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_get_x_translation(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Graphene >= 1.10");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_get_x_scale(value self)
{
CAMLparam1(self);

float result = graphene_matrix_get_x_scale(graphene_matrix_t_val(self));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_get_x_scale(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_get_value(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

float result = graphene_matrix_get_value(graphene_matrix_t_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_get_value(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_get_row(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_vec4_t out2;

graphene_matrix_get_row(graphene_matrix_t_val(self), Int_val(arg1), &out2);
CAMLreturn(Val_graphene_vec4_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_get_row(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_matrix_equal_fast(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_matrix_equal_fast(graphene_matrix_t_val(self), graphene_matrix_t_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_equal_fast(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.10");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_matrix_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_matrix_equal(graphene_matrix_t_val(self), graphene_matrix_t_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_equal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Graphene >= 1.10");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_matrix_determinant(value self)
{
CAMLparam1(self);

float result = graphene_matrix_determinant(graphene_matrix_t_val(self));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_graphene_matrix_determinant(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Graphene >= 1.0");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_graphene_matrix_decompose(value self)
{
CAMLparam1(self);
graphene_vec3_t out1;
graphene_vec3_t out2;
graphene_quaternion_t out3;
graphene_vec3_t out4;
graphene_vec4_t out5;

bool result = graphene_matrix_decompose(graphene_matrix_t_val(self), &out1, &out2, &out3, &out4, &out5);
CAMLlocal1(ret);
    ret = caml_alloc(6, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_graphene_vec3_t(&out1));
    Store_field(ret, 2, Val_graphene_vec3_t(&out2));
    Store_field(ret, 3, Val_graphene_quaternion_t(&out3));
    Store_field(ret, 4, Val_graphene_vec3_t(&out4));
    Store_field(ret, 5, Val_graphene_vec4_t(&out5));
    CAMLreturn(ret);
}


CAMLprim value ml_graphene_matrix_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(graphene_matrix_get_type()));
}
