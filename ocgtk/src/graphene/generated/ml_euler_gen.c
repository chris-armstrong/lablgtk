/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Euler */

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
/* Conversion functions for graphene_euler_t (opaque record with hidden fields) */
graphene_euler_t *graphene_euler_t_val(value v) {
  return (graphene_euler_t *)ml_gir_record_ptr_val(v, "graphene_euler_t");
}

value Val_graphene_euler_t(const graphene_euler_t *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(graphene_euler_get_type(), ptr);
}

value Val_graphene_euler_t_option(const graphene_euler_t *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_graphene_euler_t(ptr));
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,2,0)


CAMLexport CAMLprim value ml_graphene_euler_alloc(value unit)
{
CAMLparam1(unit);

graphene_euler_t *obj = graphene_euler_alloc();

CAMLreturn(Val_graphene_euler_t(obj));
}
CAMLexport CAMLprim value ml_graphene_euler_to_vec3(value self)
{
CAMLparam1(self);
graphene_vec3_t out1;

graphene_euler_to_vec3(graphene_euler_t_val(self), &out1);
CAMLreturn(Val_graphene_vec3_t(&out1));
}

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_euler_to_quaternion(value self)
{
CAMLparam1(self);
graphene_quaternion_t out1;

graphene_euler_to_quaternion(graphene_euler_t_val(self), &out1);
CAMLreturn(Val_graphene_quaternion_t(&out1));
}

#else

CAMLexport CAMLprim value ml_graphene_euler_to_quaternion(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Euler requires Graphene >= 1.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_graphene_euler_to_matrix(value self)
{
CAMLparam1(self);
graphene_matrix_t out1;

graphene_euler_to_matrix(graphene_euler_t_val(self), &out1);
CAMLreturn(Val_graphene_matrix_t(&out1));
}

CAMLexport CAMLprim value ml_graphene_euler_reorder(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_euler_t out2;

graphene_euler_reorder(graphene_euler_t_val(self), GrapheneEulerOrder_val(arg1), &out2);
CAMLreturn(Val_graphene_euler_t(&out2));
}

CAMLexport CAMLprim value ml_graphene_euler_init_with_order(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

graphene_euler_t* result = graphene_euler_init_with_order(graphene_euler_t_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), GrapheneEulerOrder_val(arg4));
if (result) result = g_boxed_copy(graphene_euler_get_type(), result);
CAMLreturn(Val_graphene_euler_t(result));
}

CAMLexport CAMLprim value ml_graphene_euler_init_from_vec3(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

graphene_euler_t* result = graphene_euler_init_from_vec3(graphene_euler_t_val(self), Option_val(arg1, graphene_vec3_t_val, NULL), GrapheneEulerOrder_val(arg2));
if (result) result = g_boxed_copy(graphene_euler_get_type(), result);
CAMLreturn(Val_graphene_euler_t(result));
}

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_euler_init_from_radians(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

graphene_euler_t* result = graphene_euler_init_from_radians(graphene_euler_t_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), GrapheneEulerOrder_val(arg4));
if (result) result = g_boxed_copy(graphene_euler_get_type(), result);
CAMLreturn(Val_graphene_euler_t(result));
}

#else

CAMLexport CAMLprim value ml_graphene_euler_init_from_radians(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Euler requires Graphene >= 1.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_graphene_euler_init_from_quaternion(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

graphene_euler_t* result = graphene_euler_init_from_quaternion(graphene_euler_t_val(self), Option_val(arg1, graphene_quaternion_t_val, NULL), GrapheneEulerOrder_val(arg2));
if (result) result = g_boxed_copy(graphene_euler_get_type(), result);
CAMLreturn(Val_graphene_euler_t(result));
}

CAMLexport CAMLprim value ml_graphene_euler_init_from_matrix(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

graphene_euler_t* result = graphene_euler_init_from_matrix(graphene_euler_t_val(self), Option_val(arg1, graphene_matrix_t_val, NULL), GrapheneEulerOrder_val(arg2));
if (result) result = g_boxed_copy(graphene_euler_get_type(), result);
CAMLreturn(Val_graphene_euler_t(result));
}

CAMLexport CAMLprim value ml_graphene_euler_init_from_euler(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_euler_t* result = graphene_euler_init_from_euler(graphene_euler_t_val(self), Option_val(arg1, graphene_euler_t_val, NULL));
if (result) result = g_boxed_copy(graphene_euler_get_type(), result);
CAMLreturn(Val_graphene_euler_t(result));
}

CAMLexport CAMLprim value ml_graphene_euler_init(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

graphene_euler_t* result = graphene_euler_init(graphene_euler_t_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3));
if (result) result = g_boxed_copy(graphene_euler_get_type(), result);
CAMLreturn(Val_graphene_euler_t(result));
}

CAMLexport CAMLprim value ml_graphene_euler_get_z(value self)
{
CAMLparam1(self);

float result = graphene_euler_get_z(graphene_euler_t_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_graphene_euler_get_y(value self)
{
CAMLparam1(self);

float result = graphene_euler_get_y(graphene_euler_t_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_graphene_euler_get_x(value self)
{
CAMLparam1(self);

float result = graphene_euler_get_x(graphene_euler_t_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_graphene_euler_get_order(value self)
{
CAMLparam1(self);

graphene_euler_order_t result = graphene_euler_get_order(graphene_euler_t_val(self));
CAMLreturn(Val_GrapheneEulerOrder(result));
}

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_euler_get_gamma(value self)
{
CAMLparam1(self);

float result = graphene_euler_get_gamma(graphene_euler_t_val(self));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_graphene_euler_get_gamma(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Euler requires Graphene >= 1.10");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_euler_get_beta(value self)
{
CAMLparam1(self);

float result = graphene_euler_get_beta(graphene_euler_t_val(self));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_graphene_euler_get_beta(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Euler requires Graphene >= 1.10");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_euler_get_alpha(value self)
{
CAMLparam1(self);

float result = graphene_euler_get_alpha(graphene_euler_t_val(self));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_graphene_euler_get_alpha(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Euler requires Graphene >= 1.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_graphene_euler_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_euler_equal(graphene_euler_t_val(self), graphene_euler_t_val(arg1));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_graphene_euler_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(graphene_euler_get_type()));
}

#else


CAMLexport CAMLprim value ml_graphene_euler_alloc(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("Euler requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_euler_equal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Euler requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_euler_get_alpha(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Euler requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_euler_get_beta(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Euler requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_euler_get_gamma(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Euler requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_euler_get_order(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Euler requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_euler_get_x(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Euler requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_euler_get_y(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Euler requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_euler_get_z(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Euler requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_euler_init(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Euler requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_euler_init_from_euler(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Euler requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_euler_init_from_matrix(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Euler requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_euler_init_from_quaternion(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Euler requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_euler_init_from_radians(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Euler requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_euler_init_from_vec3(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Euler requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_euler_init_with_order(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Euler requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_euler_reorder(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Euler requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_euler_to_matrix(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Euler requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_euler_to_quaternion(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Euler requires Graphene >= 1.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_euler_to_vec3(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Euler requires Graphene >= 1.2");
return Val_unit;
}


#endif
