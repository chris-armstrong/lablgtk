/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Ray */

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

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,4,0)
/* Conversion functions for graphene_ray_t (opaque record with hidden fields) */
graphene_ray_t *graphene_ray_t_val(value v) {
  return (graphene_ray_t *)ml_gir_record_ptr_val(v, "graphene_ray_t");
}

value Val_graphene_ray_t(const graphene_ray_t *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(graphene_ray_get_type(), ptr);
}

value Val_graphene_ray_t_option(const graphene_ray_t *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_graphene_ray_t(ptr));
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,4,0)


CAMLexport CAMLprim value ml_graphene_ray_alloc(value unit)
{
CAMLparam1(unit);

graphene_ray_t *obj = graphene_ray_alloc();

CAMLreturn(Val_graphene_ray_t(obj));
}
#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_ray_intersects_triangle(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_ray_intersects_triangle(graphene_ray_t_val(self), graphene_triangle_t_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_graphene_ray_intersects_triangle(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Ray requires Graphene >= 1.10");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_ray_intersects_sphere(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_ray_intersects_sphere(graphene_ray_t_val(self), graphene_sphere_t_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_graphene_ray_intersects_sphere(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Ray requires Graphene >= 1.10");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_ray_intersects_box(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_ray_intersects_box(graphene_ray_t_val(self), graphene_box_t_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_graphene_ray_intersects_box(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Ray requires Graphene >= 1.10");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_ray_intersect_triangle(value self, value arg1)
{
CAMLparam2(self, arg1);
float out2;

graphene_ray_intersection_kind_t result = graphene_ray_intersect_triangle(graphene_ray_t_val(self), graphene_triangle_t_val(arg1), &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_GrapheneRayIntersectionKind(result));
    Store_field(ret, 1, caml_copy_double(out2));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_graphene_ray_intersect_triangle(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Ray requires Graphene >= 1.10");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_ray_intersect_sphere(value self, value arg1)
{
CAMLparam2(self, arg1);
float out2;

graphene_ray_intersection_kind_t result = graphene_ray_intersect_sphere(graphene_ray_t_val(self), graphene_sphere_t_val(arg1), &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_GrapheneRayIntersectionKind(result));
    Store_field(ret, 1, caml_copy_double(out2));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_graphene_ray_intersect_sphere(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Ray requires Graphene >= 1.10");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_ray_intersect_box(value self, value arg1)
{
CAMLparam2(self, arg1);
float out2;

graphene_ray_intersection_kind_t result = graphene_ray_intersect_box(graphene_ray_t_val(self), graphene_box_t_val(arg1), &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_GrapheneRayIntersectionKind(result));
    Store_field(ret, 1, caml_copy_double(out2));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_graphene_ray_intersect_box(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Ray requires Graphene >= 1.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_graphene_ray_init_from_vec3(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

graphene_ray_t* result = graphene_ray_init_from_vec3(graphene_ray_t_val(self), Option_val(arg1, graphene_vec3_t_val, NULL), Option_val(arg2, graphene_vec3_t_val, NULL));
if (result) result = g_boxed_copy(graphene_ray_get_type(), result);
CAMLreturn(Val_graphene_ray_t(result));
}

CAMLexport CAMLprim value ml_graphene_ray_init_from_ray(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_ray_t* result = graphene_ray_init_from_ray(graphene_ray_t_val(self), graphene_ray_t_val(arg1));
if (result) result = g_boxed_copy(graphene_ray_get_type(), result);
CAMLreturn(Val_graphene_ray_t(result));
}

CAMLexport CAMLprim value ml_graphene_ray_init(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

graphene_ray_t* result = graphene_ray_init(graphene_ray_t_val(self), Option_val(arg1, graphene_point3d_t_val, NULL), Option_val(arg2, graphene_vec3_t_val, NULL));
if (result) result = g_boxed_copy(graphene_ray_get_type(), result);
CAMLreturn(Val_graphene_ray_t(result));
}

CAMLexport CAMLprim value ml_graphene_ray_get_position_at(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_point3d_t out2;

graphene_ray_get_position_at(graphene_ray_t_val(self), Double_val(arg1), &out2);
CAMLreturn(Val_graphene_point3d_t(&out2));
}

CAMLexport CAMLprim value ml_graphene_ray_get_origin(value self)
{
CAMLparam1(self);
graphene_point3d_t out1;

graphene_ray_get_origin(graphene_ray_t_val(self), &out1);
CAMLreturn(Val_graphene_point3d_t(&out1));
}

CAMLexport CAMLprim value ml_graphene_ray_get_distance_to_point(value self, value arg1)
{
CAMLparam2(self, arg1);

float result = graphene_ray_get_distance_to_point(graphene_ray_t_val(self), graphene_point3d_t_val(arg1));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_graphene_ray_get_distance_to_plane(value self, value arg1)
{
CAMLparam2(self, arg1);

float result = graphene_ray_get_distance_to_plane(graphene_ray_t_val(self), graphene_plane_t_val(arg1));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_graphene_ray_get_direction(value self)
{
CAMLparam1(self);
graphene_vec3_t out1;

graphene_ray_get_direction(graphene_ray_t_val(self), &out1);
CAMLreturn(Val_graphene_vec3_t(&out1));
}

CAMLexport CAMLprim value ml_graphene_ray_get_closest_point_to_point(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_point3d_t out2;

graphene_ray_get_closest_point_to_point(graphene_ray_t_val(self), graphene_point3d_t_val(arg1), &out2);
CAMLreturn(Val_graphene_point3d_t(&out2));
}

CAMLexport CAMLprim value ml_graphene_ray_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_ray_equal(graphene_ray_t_val(self), graphene_ray_t_val(arg1));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_graphene_ray_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(graphene_ray_get_type()));
}

#else


CAMLexport CAMLprim value ml_graphene_ray_alloc(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("Ray requires Graphene >= 1.4");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_ray_equal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Ray requires Graphene >= 1.4");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_ray_get_closest_point_to_point(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Ray requires Graphene >= 1.4");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_ray_get_direction(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Ray requires Graphene >= 1.4");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_ray_get_distance_to_plane(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Ray requires Graphene >= 1.4");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_ray_get_distance_to_point(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Ray requires Graphene >= 1.4");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_ray_get_origin(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Ray requires Graphene >= 1.4");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_ray_get_position_at(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Ray requires Graphene >= 1.4");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_ray_init(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Ray requires Graphene >= 1.4");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_ray_init_from_ray(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Ray requires Graphene >= 1.4");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_ray_init_from_vec3(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Ray requires Graphene >= 1.4");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_ray_intersect_box(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Ray requires Graphene >= 1.4");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_ray_intersect_sphere(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Ray requires Graphene >= 1.4");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_ray_intersect_triangle(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Ray requires Graphene >= 1.4");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_ray_intersects_box(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Ray requires Graphene >= 1.4");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_ray_intersects_sphere(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Ray requires Graphene >= 1.4");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_ray_intersects_triangle(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Ray requires Graphene >= 1.4");
return Val_unit;
}


#endif
