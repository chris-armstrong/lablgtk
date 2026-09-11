/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Vec3 */

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

/* Conversion functions for graphene_vec3_t (opaque record with hidden fields) */
graphene_vec3_t *graphene_vec3_t_val(value v) {
  return (graphene_vec3_t *)ml_gir_record_ptr_val(v, "graphene_vec3_t");
}

value Val_graphene_vec3_t(const graphene_vec3_t *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(graphene_vec3_get_type(), ptr);
}

value Val_graphene_vec3_t_option(const graphene_vec3_t *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_graphene_vec3_t(ptr));
}


#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_alloc(value unit)
{
CAMLparam1(unit);

graphene_vec3_t *obj = graphene_vec3_alloc();

CAMLreturn(Val_graphene_vec3_t(obj));
}
#else

CAMLexport CAMLprim value ml_graphene_vec3_alloc(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_to_float(value self)
{
CAMLparam1(self);
float out1[3];

graphene_vec3_to_float(graphene_vec3_t_val(self), out1);
    int out1_length = 3;
    CAMLlocal1(ml_out1);
    ml_out1 = caml_alloc(out1_length, 0);
    for (int i = 0; i < out1_length; i++) {
      Store_field(ml_out1, i, caml_copy_double(out1[i]));
    }

CAMLreturn(ml_out1);
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_to_float(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_subtract(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_vec3_t out2;

graphene_vec3_subtract(graphene_vec3_t_val(self), graphene_vec3_t_val(arg1), &out2);
CAMLreturn(Val_graphene_vec3_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_subtract(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,2,0)

CAMLexport CAMLprim value ml_graphene_vec3_scale(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_vec3_t out2;

graphene_vec3_scale(graphene_vec3_t_val(self), Double_val(arg1), &out2);
CAMLreturn(Val_graphene_vec3_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_scale(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Vec3 requires Graphene >= 1.2");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_normalize(value self)
{
CAMLparam1(self);
graphene_vec3_t out1;

graphene_vec3_normalize(graphene_vec3_t_val(self), &out1);
CAMLreturn(Val_graphene_vec3_t(&out1));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_normalize(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,2,0)

CAMLexport CAMLprim value ml_graphene_vec3_negate(value self)
{
CAMLparam1(self);
graphene_vec3_t out1;

graphene_vec3_negate(graphene_vec3_t_val(self), &out1);
CAMLreturn(Val_graphene_vec3_t(&out1));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_negate(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Vec3 requires Graphene >= 1.2");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,2,0)

CAMLexport CAMLprim value ml_graphene_vec3_near(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

bool result = graphene_vec3_near(graphene_vec3_t_val(self), graphene_vec3_t_val(arg1), Double_val(arg2));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_near(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Vec3 requires Graphene >= 1.2");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_multiply(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_vec3_t out2;

graphene_vec3_multiply(graphene_vec3_t_val(self), graphene_vec3_t_val(arg1), &out2);
CAMLreturn(Val_graphene_vec3_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_multiply(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_min(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_vec3_t out2;

graphene_vec3_min(graphene_vec3_t_val(self), graphene_vec3_t_val(arg1), &out2);
CAMLreturn(Val_graphene_vec3_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_min(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_max(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_vec3_t out2;

graphene_vec3_max(graphene_vec3_t_val(self), graphene_vec3_t_val(arg1), &out2);
CAMLreturn(Val_graphene_vec3_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_max(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_length(value self)
{
CAMLparam1(self);

float result = graphene_vec3_length(graphene_vec3_t_val(self));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_length(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_vec3_interpolate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
graphene_vec3_t out3;

graphene_vec3_interpolate(graphene_vec3_t_val(self), graphene_vec3_t_val(arg1), Double_val(arg2), &out3);
CAMLreturn(Val_graphene_vec3_t(&out3));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_interpolate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Vec3 requires Graphene >= 1.10");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_init_from_vec3(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_vec3_t* result = graphene_vec3_init_from_vec3(graphene_vec3_t_val(self), graphene_vec3_t_val(arg1));
if (result) result = g_boxed_copy(graphene_vec3_get_type(), result);
CAMLreturn(Val_graphene_vec3_t(result));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_init_from_vec3(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_init_from_float(value self, value arg1)
{
CAMLparam2(self, arg1);
    int arg1_length = Wosize_val(arg1);
    float* c_arg1 = (float*)g_malloc(sizeof(float) * arg1_length);
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = Double_val(Field(arg1, i));
    }

graphene_vec3_t* result = graphene_vec3_init_from_float(graphene_vec3_t_val(self), c_arg1);
if (result) result = g_boxed_copy(graphene_vec3_get_type(), result);
    g_free(c_arg1);
CAMLreturn(Val_graphene_vec3_t(result));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_init_from_float(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_init(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

graphene_vec3_t* result = graphene_vec3_init(graphene_vec3_t_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3));
if (result) result = g_boxed_copy(graphene_vec3_get_type(), result);
CAMLreturn(Val_graphene_vec3_t(result));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_init(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_get_z(value self)
{
CAMLparam1(self);

float result = graphene_vec3_get_z(graphene_vec3_t_val(self));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_get_z(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_get_y(value self)
{
CAMLparam1(self);

float result = graphene_vec3_get_y(graphene_vec3_t_val(self));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_get_y(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_get_xyzw(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_vec4_t out2;

graphene_vec3_get_xyzw(graphene_vec3_t_val(self), Double_val(arg1), &out2);
CAMLreturn(Val_graphene_vec4_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_get_xyzw(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_get_xyz1(value self)
{
CAMLparam1(self);
graphene_vec4_t out1;

graphene_vec3_get_xyz1(graphene_vec3_t_val(self), &out1);
CAMLreturn(Val_graphene_vec4_t(&out1));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_get_xyz1(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_get_xyz0(value self)
{
CAMLparam1(self);
graphene_vec4_t out1;

graphene_vec3_get_xyz0(graphene_vec3_t_val(self), &out1);
CAMLreturn(Val_graphene_vec4_t(&out1));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_get_xyz0(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_get_xy0(value self)
{
CAMLparam1(self);
graphene_vec3_t out1;

graphene_vec3_get_xy0(graphene_vec3_t_val(self), &out1);
CAMLreturn(Val_graphene_vec3_t(&out1));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_get_xy0(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_get_xy(value self)
{
CAMLparam1(self);
graphene_vec2_t out1;

graphene_vec3_get_xy(graphene_vec3_t_val(self), &out1);
CAMLreturn(Val_graphene_vec2_t(&out1));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_get_xy(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_get_x(value self)
{
CAMLparam1(self);

float result = graphene_vec3_get_x(graphene_vec3_t_val(self));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_get_x(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,2,0)

CAMLexport CAMLprim value ml_graphene_vec3_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_vec3_equal(graphene_vec3_t_val(self), graphene_vec3_t_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_equal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Vec3 requires Graphene >= 1.2");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_dot(value self, value arg1)
{
CAMLparam2(self, arg1);

float result = graphene_vec3_dot(graphene_vec3_t_val(self), graphene_vec3_t_val(arg1));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_dot(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_divide(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_vec3_t out2;

graphene_vec3_divide(graphene_vec3_t_val(self), graphene_vec3_t_val(arg1), &out2);
CAMLreturn(Val_graphene_vec3_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_divide(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_cross(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_vec3_t out2;

graphene_vec3_cross(graphene_vec3_t_val(self), graphene_vec3_t_val(arg1), &out2);
CAMLreturn(Val_graphene_vec3_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_cross(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)

CAMLexport CAMLprim value ml_graphene_vec3_add(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_vec3_t out2;

graphene_vec3_add(graphene_vec3_t_val(self), graphene_vec3_t_val(arg1), &out2);
CAMLreturn(Val_graphene_vec3_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_vec3_add(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Vec3 requires Graphene >= 1.0");
return Val_unit;
}
#endif


CAMLprim value ml_graphene_vec3_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(graphene_vec3_get_type()));
}
