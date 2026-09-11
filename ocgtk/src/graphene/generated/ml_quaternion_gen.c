/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Quaternion */

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

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)
/* Conversion functions for graphene_quaternion_t (opaque record with hidden fields) */
graphene_quaternion_t *graphene_quaternion_t_val(value v) {
  return (graphene_quaternion_t *)ml_gir_record_ptr_val(v, "graphene_quaternion_t");
}

value Val_graphene_quaternion_t(const graphene_quaternion_t *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(graphene_quaternion_get_type(), ptr);
}

value Val_graphene_quaternion_t_option(const graphene_quaternion_t *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_graphene_quaternion_t(ptr));
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)


CAMLexport CAMLprim value ml_graphene_quaternion_alloc(value unit)
{
CAMLparam1(unit);

graphene_quaternion_t *obj = graphene_quaternion_alloc();

CAMLreturn(Val_graphene_quaternion_t(obj));
}
CAMLexport CAMLprim value ml_graphene_quaternion_to_vec4(value self)
{
CAMLparam1(self);
graphene_vec4_t out1;

graphene_quaternion_to_vec4(graphene_quaternion_t_val(self), &out1);
CAMLreturn(Val_graphene_vec4_t(&out1));
}

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,2,0)

CAMLexport CAMLprim value ml_graphene_quaternion_to_radians(value self)
{
CAMLparam1(self);
float out1;
float out2;
float out3;

graphene_quaternion_to_radians(graphene_quaternion_t_val(self), &out1, &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, caml_copy_double(out1));
    Store_field(ret, 1, caml_copy_double(out2));
    Store_field(ret, 2, caml_copy_double(out3));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_graphene_quaternion_to_radians(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Quaternion requires Graphene >= 1.2");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_graphene_quaternion_to_matrix(value self)
{
CAMLparam1(self);
graphene_matrix_t out1;

graphene_quaternion_to_matrix(graphene_quaternion_t_val(self), &out1);
CAMLreturn(Val_graphene_matrix_t(&out1));
}

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,2,0)

CAMLexport CAMLprim value ml_graphene_quaternion_to_angles(value self)
{
CAMLparam1(self);
float out1;
float out2;
float out3;

graphene_quaternion_to_angles(graphene_quaternion_t_val(self), &out1, &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, caml_copy_double(out1));
    Store_field(ret, 1, caml_copy_double(out2));
    Store_field(ret, 2, caml_copy_double(out3));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_graphene_quaternion_to_angles(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Quaternion requires Graphene >= 1.2");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_graphene_quaternion_to_angle_vec3(value self)
{
CAMLparam1(self);
float out1;
graphene_vec3_t out2;

graphene_quaternion_to_angle_vec3(graphene_quaternion_t_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, caml_copy_double(out1));
    Store_field(ret, 1, Val_graphene_vec3_t(&out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_graphene_quaternion_slerp(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
graphene_quaternion_t out3;

graphene_quaternion_slerp(graphene_quaternion_t_val(self), graphene_quaternion_t_val(arg1), Double_val(arg2), &out3);
CAMLreturn(Val_graphene_quaternion_t(&out3));
}

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_quaternion_scale(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_quaternion_t out2;

graphene_quaternion_scale(graphene_quaternion_t_val(self), Double_val(arg1), &out2);
CAMLreturn(Val_graphene_quaternion_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_quaternion_scale(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Quaternion requires Graphene >= 1.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_graphene_quaternion_normalize(value self)
{
CAMLparam1(self);
graphene_quaternion_t out1;

graphene_quaternion_normalize(graphene_quaternion_t_val(self), &out1);
CAMLreturn(Val_graphene_quaternion_t(&out1));
}

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_quaternion_multiply(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_quaternion_t out2;

graphene_quaternion_multiply(graphene_quaternion_t_val(self), graphene_quaternion_t_val(arg1), &out2);
CAMLreturn(Val_graphene_quaternion_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_quaternion_multiply(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Quaternion requires Graphene >= 1.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_graphene_quaternion_invert(value self)
{
CAMLparam1(self);
graphene_quaternion_t out1;

graphene_quaternion_invert(graphene_quaternion_t_val(self), &out1);
CAMLreturn(Val_graphene_quaternion_t(&out1));
}

CAMLexport CAMLprim value ml_graphene_quaternion_init_identity(value self)
{
CAMLparam1(self);

graphene_quaternion_t* result = graphene_quaternion_init_identity(graphene_quaternion_t_val(self));
if (result) result = g_boxed_copy(graphene_quaternion_get_type(), result);
CAMLreturn(Val_graphene_quaternion_t(result));
}

CAMLexport CAMLprim value ml_graphene_quaternion_init_from_vec4(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_quaternion_t* result = graphene_quaternion_init_from_vec4(graphene_quaternion_t_val(self), graphene_vec4_t_val(arg1));
if (result) result = g_boxed_copy(graphene_quaternion_get_type(), result);
CAMLreturn(Val_graphene_quaternion_t(result));
}

CAMLexport CAMLprim value ml_graphene_quaternion_init_from_radians(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

graphene_quaternion_t* result = graphene_quaternion_init_from_radians(graphene_quaternion_t_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3));
if (result) result = g_boxed_copy(graphene_quaternion_get_type(), result);
CAMLreturn(Val_graphene_quaternion_t(result));
}

CAMLexport CAMLprim value ml_graphene_quaternion_init_from_quaternion(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_quaternion_t* result = graphene_quaternion_init_from_quaternion(graphene_quaternion_t_val(self), graphene_quaternion_t_val(arg1));
if (result) result = g_boxed_copy(graphene_quaternion_get_type(), result);
CAMLreturn(Val_graphene_quaternion_t(result));
}

CAMLexport CAMLprim value ml_graphene_quaternion_init_from_matrix(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_quaternion_t* result = graphene_quaternion_init_from_matrix(graphene_quaternion_t_val(self), graphene_matrix_t_val(arg1));
if (result) result = g_boxed_copy(graphene_quaternion_get_type(), result);
CAMLreturn(Val_graphene_quaternion_t(result));
}

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,2,0)

CAMLexport CAMLprim value ml_graphene_quaternion_init_from_euler(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_quaternion_t* result = graphene_quaternion_init_from_euler(graphene_quaternion_t_val(self), graphene_euler_t_val(arg1));
if (result) result = g_boxed_copy(graphene_quaternion_get_type(), result);
CAMLreturn(Val_graphene_quaternion_t(result));
}

#else

CAMLexport CAMLprim value ml_graphene_quaternion_init_from_euler(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Quaternion requires Graphene >= 1.2");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_graphene_quaternion_init_from_angles(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

graphene_quaternion_t* result = graphene_quaternion_init_from_angles(graphene_quaternion_t_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3));
if (result) result = g_boxed_copy(graphene_quaternion_get_type(), result);
CAMLreturn(Val_graphene_quaternion_t(result));
}

CAMLexport CAMLprim value ml_graphene_quaternion_init_from_angle_vec3(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

graphene_quaternion_t* result = graphene_quaternion_init_from_angle_vec3(graphene_quaternion_t_val(self), Double_val(arg1), graphene_vec3_t_val(arg2));
if (result) result = g_boxed_copy(graphene_quaternion_get_type(), result);
CAMLreturn(Val_graphene_quaternion_t(result));
}

CAMLexport CAMLprim value ml_graphene_quaternion_init(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

graphene_quaternion_t* result = graphene_quaternion_init(graphene_quaternion_t_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4));
if (result) result = g_boxed_copy(graphene_quaternion_get_type(), result);
CAMLreturn(Val_graphene_quaternion_t(result));
}

CAMLexport CAMLprim value ml_graphene_quaternion_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_quaternion_equal(graphene_quaternion_t_val(self), graphene_quaternion_t_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_graphene_quaternion_dot(value self, value arg1)
{
CAMLparam2(self, arg1);

float result = graphene_quaternion_dot(graphene_quaternion_t_val(self), graphene_quaternion_t_val(arg1));
CAMLreturn(caml_copy_double(result));
}

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_quaternion_add(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_quaternion_t out2;

graphene_quaternion_add(graphene_quaternion_t_val(self), graphene_quaternion_t_val(arg1), &out2);
CAMLreturn(Val_graphene_quaternion_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_quaternion_add(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Quaternion requires Graphene >= 1.10");
return Val_unit;
}
#endif

GType graphene_quaternion_get_type (void);


CAMLprim value ml_graphene_quaternion_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(graphene_quaternion_get_type()));
}

#else


CAMLexport CAMLprim value ml_graphene_quaternion_alloc(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_add(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_dot(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_equal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_init(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_init_from_angle_vec3(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_init_from_angles(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_init_from_euler(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_init_from_matrix(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_init_from_quaternion(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_init_from_radians(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_init_from_vec4(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_init_identity(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_invert(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_multiply(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_normalize(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_scale(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_slerp(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_to_angle_vec3(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_to_angles(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_to_matrix(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_to_radians(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quaternion_to_vec4(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Quaternion requires Graphene >= 1.0");
return Val_unit;
}


#endif
