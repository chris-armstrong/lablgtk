/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Box */

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
/* Conversion functions for graphene_box_t (opaque record with hidden fields) */
graphene_box_t *graphene_box_t_val(value v) {
  return (graphene_box_t *)ml_gir_record_ptr_val(v, "graphene_box_t");
}

value Val_graphene_box_t(const graphene_box_t *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(graphene_box_get_type(), ptr);
}

value Val_graphene_box_t_option(const graphene_box_t *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_graphene_box_t(ptr));
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,2,0)


CAMLexport CAMLprim value ml_graphene_box_alloc(value unit)
{
CAMLparam1(unit);

graphene_box_t *obj = graphene_box_alloc();

CAMLreturn(Val_graphene_box_t(obj));
}
CAMLexport CAMLprim value ml_graphene_box_union(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_box_t out2;

graphene_box_union(graphene_box_t_val(self), graphene_box_t_val(arg1), &out2);
CAMLreturn(Val_graphene_box_t(&out2));
}

CAMLexport CAMLprim value ml_graphene_box_intersection(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_box_t out2;

bool result = graphene_box_intersection(graphene_box_t_val(self), graphene_box_t_val(arg1), &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_graphene_box_t(&out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_graphene_box_init_from_vectors(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
    int arg2_length = Wosize_val(arg2);
    graphene_vec3_t* c_arg2 = (graphene_vec3_t*)g_malloc(sizeof(graphene_vec3_t) * arg2_length);
    for (int i = 0; i < arg2_length; i++) {
      c_arg2[i] = *graphene_vec3_t_val(Field(arg2, i));
    }

graphene_box_t* result = graphene_box_init_from_vectors(graphene_box_t_val(self), Int_val(arg1), c_arg2);
if (result) result = g_boxed_copy(graphene_box_get_type(), result);
    g_free(c_arg2);
CAMLreturn(Val_graphene_box_t(result));
}

CAMLexport CAMLprim value ml_graphene_box_init_from_vec3(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

graphene_box_t* result = graphene_box_init_from_vec3(graphene_box_t_val(self), Option_val(arg1, graphene_vec3_t_val, NULL), Option_val(arg2, graphene_vec3_t_val, NULL));
if (result) result = g_boxed_copy(graphene_box_get_type(), result);
CAMLreturn(Val_graphene_box_t(result));
}

CAMLexport CAMLprim value ml_graphene_box_init_from_points(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
    int arg2_length = Wosize_val(arg2);
    graphene_point3d_t* c_arg2 = (graphene_point3d_t*)g_malloc(sizeof(graphene_point3d_t) * arg2_length);
    for (int i = 0; i < arg2_length; i++) {
      c_arg2[i] = *graphene_point3d_t_val(Field(arg2, i));
    }

graphene_box_t* result = graphene_box_init_from_points(graphene_box_t_val(self), Int_val(arg1), c_arg2);
if (result) result = g_boxed_copy(graphene_box_get_type(), result);
    g_free(c_arg2);
CAMLreturn(Val_graphene_box_t(result));
}

CAMLexport CAMLprim value ml_graphene_box_init_from_box(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_box_t* result = graphene_box_init_from_box(graphene_box_t_val(self), graphene_box_t_val(arg1));
if (result) result = g_boxed_copy(graphene_box_get_type(), result);
CAMLreturn(Val_graphene_box_t(result));
}

CAMLexport CAMLprim value ml_graphene_box_init(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

graphene_box_t* result = graphene_box_init(graphene_box_t_val(self), Option_val(arg1, graphene_point3d_t_val, NULL), Option_val(arg2, graphene_point3d_t_val, NULL));
if (result) result = g_boxed_copy(graphene_box_get_type(), result);
CAMLreturn(Val_graphene_box_t(result));
}

CAMLexport CAMLprim value ml_graphene_box_get_width(value self)
{
CAMLparam1(self);

float result = graphene_box_get_width(graphene_box_t_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_graphene_box_get_vertices(value self)
{
CAMLparam1(self);
graphene_vec3_t out1[8];

graphene_box_get_vertices(graphene_box_t_val(self), out1);
    int out1_length = 8;
    CAMLlocal1(ml_out1);
    ml_out1 = caml_alloc(out1_length, 0);
    for (int i = 0; i < out1_length; i++) {
      Store_field(ml_out1, i, Val_graphene_vec3_t(&out1[i]));
    }

CAMLreturn(ml_out1);
}

CAMLexport CAMLprim value ml_graphene_box_get_size(value self)
{
CAMLparam1(self);
graphene_vec3_t out1;

graphene_box_get_size(graphene_box_t_val(self), &out1);
CAMLreturn(Val_graphene_vec3_t(&out1));
}

CAMLexport CAMLprim value ml_graphene_box_get_min(value self)
{
CAMLparam1(self);
graphene_point3d_t out1;

graphene_box_get_min(graphene_box_t_val(self), &out1);
CAMLreturn(Val_graphene_point3d_t(&out1));
}

CAMLexport CAMLprim value ml_graphene_box_get_max(value self)
{
CAMLparam1(self);
graphene_point3d_t out1;

graphene_box_get_max(graphene_box_t_val(self), &out1);
CAMLreturn(Val_graphene_point3d_t(&out1));
}

CAMLexport CAMLprim value ml_graphene_box_get_height(value self)
{
CAMLparam1(self);

float result = graphene_box_get_height(graphene_box_t_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_graphene_box_get_depth(value self)
{
CAMLparam1(self);

float result = graphene_box_get_depth(graphene_box_t_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_graphene_box_get_center(value self)
{
CAMLparam1(self);
graphene_point3d_t out1;

graphene_box_get_center(graphene_box_t_val(self), &out1);
CAMLreturn(Val_graphene_point3d_t(&out1));
}

CAMLexport CAMLprim value ml_graphene_box_get_bounding_sphere(value self)
{
CAMLparam1(self);
graphene_sphere_t out1;

graphene_box_get_bounding_sphere(graphene_box_t_val(self), &out1);
CAMLreturn(Val_graphene_sphere_t(&out1));
}

CAMLexport CAMLprim value ml_graphene_box_expand_vec3(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_box_t out2;

graphene_box_expand_vec3(graphene_box_t_val(self), graphene_vec3_t_val(arg1), &out2);
CAMLreturn(Val_graphene_box_t(&out2));
}

CAMLexport CAMLprim value ml_graphene_box_expand_scalar(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_box_t out2;

graphene_box_expand_scalar(graphene_box_t_val(self), Double_val(arg1), &out2);
CAMLreturn(Val_graphene_box_t(&out2));
}

CAMLexport CAMLprim value ml_graphene_box_expand(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_box_t out2;

graphene_box_expand(graphene_box_t_val(self), graphene_point3d_t_val(arg1), &out2);
CAMLreturn(Val_graphene_box_t(&out2));
}

CAMLexport CAMLprim value ml_graphene_box_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_box_equal(graphene_box_t_val(self), graphene_box_t_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_graphene_box_contains_point(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_box_contains_point(graphene_box_t_val(self), graphene_point3d_t_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_graphene_box_contains_box(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_box_contains_box(graphene_box_t_val(self), graphene_box_t_val(arg1));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_graphene_box_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(graphene_box_get_type()));
}

#else


CAMLexport CAMLprim value ml_graphene_box_alloc(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_contains_box(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_contains_point(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_equal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_expand(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_expand_scalar(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_expand_vec3(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_get_bounding_sphere(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_get_center(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_get_depth(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_get_height(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_get_max(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_get_min(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_get_size(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_get_vertices(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_get_width(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_init(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_init_from_box(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_init_from_points(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_init_from_vec3(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_init_from_vectors(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_intersection(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_box_union(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Box requires Graphene >= 1.2");
return Val_unit;
}


#endif
