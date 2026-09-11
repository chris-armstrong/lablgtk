/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Point */

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
/* Conversion functions for graphene_point_t (opaque record with hidden fields) */
graphene_point_t *graphene_point_t_val(value v) {
  return (graphene_point_t *)ml_gir_record_ptr_val(v, "graphene_point_t");
}

value Val_graphene_point_t(const graphene_point_t *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(graphene_point_get_type(), ptr);
}

value Val_graphene_point_t_option(const graphene_point_t *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_graphene_point_t(ptr));
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)


CAMLexport CAMLprim value ml_graphene_point_alloc(value unit)
{
CAMLparam1(unit);

graphene_point_t *obj = graphene_point_alloc();

CAMLreturn(Val_graphene_point_t(obj));
}
#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,4,0)

CAMLexport CAMLprim value ml_graphene_point_to_vec2(value self)
{
CAMLparam1(self);
graphene_vec2_t out1;

graphene_point_to_vec2(graphene_point_t_val(self), &out1);
CAMLreturn(Val_graphene_vec2_t(&out1));
}

#else

CAMLexport CAMLprim value ml_graphene_point_to_vec2(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Point requires Graphene >= 1.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_graphene_point_near(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

bool result = graphene_point_near(graphene_point_t_val(self), graphene_point_t_val(arg1), Double_val(arg2));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_graphene_point_interpolate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
graphene_point_t out3;

graphene_point_interpolate(graphene_point_t_val(self), graphene_point_t_val(arg1), Double_val(arg2), &out3);
CAMLreturn(Val_graphene_point_t(&out3));
}

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,4,0)

CAMLexport CAMLprim value ml_graphene_point_init_from_vec2(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_point_t* result = graphene_point_init_from_vec2(graphene_point_t_val(self), graphene_vec2_t_val(arg1));
if (result) result = g_boxed_copy(graphene_point_get_type(), result);
CAMLreturn(Val_graphene_point_t(result));
}

#else

CAMLexport CAMLprim value ml_graphene_point_init_from_vec2(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Point requires Graphene >= 1.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_graphene_point_init_from_point(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_point_t* result = graphene_point_init_from_point(graphene_point_t_val(self), graphene_point_t_val(arg1));
if (result) result = g_boxed_copy(graphene_point_get_type(), result);
CAMLreturn(Val_graphene_point_t(result));
}

CAMLexport CAMLprim value ml_graphene_point_init(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

graphene_point_t* result = graphene_point_init(graphene_point_t_val(self), Double_val(arg1), Double_val(arg2));
if (result) result = g_boxed_copy(graphene_point_get_type(), result);
CAMLreturn(Val_graphene_point_t(result));
}

CAMLexport CAMLprim value ml_graphene_point_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_point_equal(graphene_point_t_val(self), graphene_point_t_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_graphene_point_distance(value self, value arg1)
{
CAMLparam2(self, arg1);
float out2;
float out3;

float result = graphene_point_distance(graphene_point_t_val(self), graphene_point_t_val(arg1), &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, caml_copy_double(result));
    Store_field(ret, 1, caml_copy_double(out2));
    Store_field(ret, 2, caml_copy_double(out3));
    CAMLreturn(ret);
}

GType graphene_point_get_type (void);


CAMLprim value ml_graphene_point_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(graphene_point_get_type()));
}

#else


CAMLexport CAMLprim value ml_graphene_point_alloc(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("Point requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_point_distance(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Point requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_point_equal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Point requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_point_init(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Point requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_point_init_from_point(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Point requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_point_init_from_vec2(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Point requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_point_interpolate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Point requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_point_near(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Point requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_point_to_vec2(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Point requires Graphene >= 1.0");
return Val_unit;
}


#endif
