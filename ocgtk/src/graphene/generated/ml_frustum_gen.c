/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Frustum */

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
/* Conversion functions for graphene_frustum_t (opaque record with hidden fields) */
graphene_frustum_t *graphene_frustum_t_val(value v) {
  return (graphene_frustum_t *)ml_gir_record_ptr_val(v, "graphene_frustum_t");
}

value Val_graphene_frustum_t(const graphene_frustum_t *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(graphene_frustum_get_type(), ptr);
}

value Val_graphene_frustum_t_option(const graphene_frustum_t *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_graphene_frustum_t(ptr));
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,2,0)


CAMLexport CAMLprim value ml_graphene_frustum_alloc(value unit)
{
CAMLparam1(unit);

graphene_frustum_t *obj = graphene_frustum_alloc();

CAMLreturn(Val_graphene_frustum_t(obj));
}
CAMLexport CAMLprim value ml_graphene_frustum_intersects_sphere(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_frustum_intersects_sphere(graphene_frustum_t_val(self), graphene_sphere_t_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_graphene_frustum_intersects_box(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_frustum_intersects_box(graphene_frustum_t_val(self), graphene_box_t_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_graphene_frustum_init_from_matrix(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_frustum_t* result = graphene_frustum_init_from_matrix(graphene_frustum_t_val(self), graphene_matrix_t_val(arg1));
if (result) result = g_boxed_copy(graphene_frustum_get_type(), result);
CAMLreturn(Val_graphene_frustum_t(result));
}

CAMLexport CAMLprim value ml_graphene_frustum_init_from_frustum(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_frustum_t* result = graphene_frustum_init_from_frustum(graphene_frustum_t_val(self), graphene_frustum_t_val(arg1));
if (result) result = g_boxed_copy(graphene_frustum_get_type(), result);
CAMLreturn(Val_graphene_frustum_t(result));
}

CAMLexport CAMLprim value ml_graphene_frustum_init_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam2(arg5, arg6);

graphene_frustum_t* result = graphene_frustum_init(graphene_frustum_t_val(self), graphene_plane_t_val(arg1), graphene_plane_t_val(arg2), graphene_plane_t_val(arg3), graphene_plane_t_val(arg4), graphene_plane_t_val(arg5), graphene_plane_t_val(arg6));
if (result) result = g_boxed_copy(graphene_frustum_get_type(), result);
CAMLreturn(Val_graphene_frustum_t(result));}

CAMLexport CAMLprim value ml_graphene_frustum_init_bytecode(value * argv, int argn)
{
return ml_graphene_frustum_init_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

CAMLexport CAMLprim value ml_graphene_frustum_get_planes(value self)
{
CAMLparam1(self);
graphene_plane_t out1[6];

graphene_frustum_get_planes(graphene_frustum_t_val(self), out1);
    int out1_length = 6;
    CAMLlocal1(ml_out1);
    ml_out1 = caml_alloc(out1_length, 0);
    for (int i = 0; i < out1_length; i++) {
      Store_field(ml_out1, i, Val_graphene_plane_t(&out1[i]));
    }

CAMLreturn(ml_out1);
}

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,6,0)

CAMLexport CAMLprim value ml_graphene_frustum_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_frustum_equal(graphene_frustum_t_val(self), graphene_frustum_t_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_graphene_frustum_equal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Frustum requires Graphene >= 1.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_graphene_frustum_contains_point(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_frustum_contains_point(graphene_frustum_t_val(self), graphene_point3d_t_val(arg1));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_graphene_frustum_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(graphene_frustum_get_type()));
}

#else


CAMLexport CAMLprim value ml_graphene_frustum_alloc(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("Frustum requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_frustum_contains_point(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Frustum requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_frustum_equal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Frustum requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_frustum_get_planes(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Frustum requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_frustum_init(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
(void)arg6;
caml_failwith("Frustum requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_frustum_init_from_frustum(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Frustum requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_frustum_init_from_matrix(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Frustum requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_frustum_intersects_box(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Frustum requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_frustum_intersects_sphere(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Frustum requires Graphene >= 1.2");
return Val_unit;
}


#endif
