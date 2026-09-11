/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Sphere */

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

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,2,0)
/* Conversion functions for graphene_sphere_t (opaque record with hidden fields) */
graphene_sphere_t *graphene_sphere_t_val(value v) {
  return (graphene_sphere_t *)ml_gir_record_ptr_val(v, "graphene_sphere_t");
}

value Val_graphene_sphere_t(const graphene_sphere_t *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(graphene_sphere_get_type(), ptr);
}

value Val_graphene_sphere_t_option(const graphene_sphere_t *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_graphene_sphere_t(ptr));
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,2,0)


CAMLexport CAMLprim value ml_graphene_sphere_alloc(value unit)
{
CAMLparam1(unit);

graphene_sphere_t *obj = graphene_sphere_alloc();

CAMLreturn(Val_graphene_sphere_t(obj));
}
CAMLexport CAMLprim value ml_graphene_sphere_translate(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_sphere_t out2;

graphene_sphere_translate(graphene_sphere_t_val(self), graphene_point3d_t_val(arg1), &out2);
CAMLreturn(Val_graphene_sphere_t(&out2));
}

CAMLexport CAMLprim value ml_graphene_sphere_is_empty(value self)
{
CAMLparam1(self);

bool result = graphene_sphere_is_empty(graphene_sphere_t_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_graphene_sphere_init_from_vectors(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
    int arg2_length = Wosize_val(arg2);
    graphene_vec3_t* c_arg2 = (graphene_vec3_t*)g_malloc(sizeof(graphene_vec3_t) * arg2_length);
    for (int i = 0; i < arg2_length; i++) {
      c_arg2[i] = *graphene_vec3_t_val(Field(arg2, i));
    }

graphene_sphere_t* result = graphene_sphere_init_from_vectors(graphene_sphere_t_val(self), Int_val(arg1), c_arg2, Option_val(arg3, graphene_point3d_t_val, NULL));
if (result) result = g_boxed_copy(graphene_sphere_get_type(), result);
    g_free(c_arg2);
CAMLreturn(Val_graphene_sphere_t(result));
}

CAMLexport CAMLprim value ml_graphene_sphere_init_from_points(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
    int arg2_length = Wosize_val(arg2);
    graphene_point3d_t* c_arg2 = (graphene_point3d_t*)g_malloc(sizeof(graphene_point3d_t) * arg2_length);
    for (int i = 0; i < arg2_length; i++) {
      c_arg2[i] = *graphene_point3d_t_val(Field(arg2, i));
    }

graphene_sphere_t* result = graphene_sphere_init_from_points(graphene_sphere_t_val(self), Int_val(arg1), c_arg2, Option_val(arg3, graphene_point3d_t_val, NULL));
if (result) result = g_boxed_copy(graphene_sphere_get_type(), result);
    g_free(c_arg2);
CAMLreturn(Val_graphene_sphere_t(result));
}

CAMLexport CAMLprim value ml_graphene_sphere_init(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

graphene_sphere_t* result = graphene_sphere_init(graphene_sphere_t_val(self), Option_val(arg1, graphene_point3d_t_val, NULL), Double_val(arg2));
if (result) result = g_boxed_copy(graphene_sphere_get_type(), result);
CAMLreturn(Val_graphene_sphere_t(result));
}

CAMLexport CAMLprim value ml_graphene_sphere_get_radius(value self)
{
CAMLparam1(self);

float result = graphene_sphere_get_radius(graphene_sphere_t_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_graphene_sphere_get_center(value self)
{
CAMLparam1(self);
graphene_point3d_t out1;

graphene_sphere_get_center(graphene_sphere_t_val(self), &out1);
CAMLreturn(Val_graphene_point3d_t(&out1));
}

CAMLexport CAMLprim value ml_graphene_sphere_get_bounding_box(value self)
{
CAMLparam1(self);
graphene_box_t out1;

graphene_sphere_get_bounding_box(graphene_sphere_t_val(self), &out1);
CAMLreturn(Val_graphene_box_t(&out1));
}

CAMLexport CAMLprim value ml_graphene_sphere_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_sphere_equal(graphene_sphere_t_val(self), graphene_sphere_t_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_graphene_sphere_distance(value self, value arg1)
{
CAMLparam2(self, arg1);

float result = graphene_sphere_distance(graphene_sphere_t_val(self), graphene_point3d_t_val(arg1));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_graphene_sphere_contains_point(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_sphere_contains_point(graphene_sphere_t_val(self), graphene_point3d_t_val(arg1));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_graphene_sphere_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(graphene_sphere_get_type()));
}

#else


CAMLexport CAMLprim value ml_graphene_sphere_alloc(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("Sphere requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_sphere_contains_point(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Sphere requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_sphere_distance(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Sphere requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_sphere_equal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Sphere requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_sphere_get_bounding_box(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Sphere requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_sphere_get_center(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Sphere requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_sphere_get_radius(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Sphere requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_sphere_init(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Sphere requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_sphere_init_from_points(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Sphere requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_sphere_init_from_vectors(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Sphere requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_sphere_is_empty(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Sphere requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_sphere_translate(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Sphere requires Graphene >= 1.2");
return Val_unit;
}


#endif
