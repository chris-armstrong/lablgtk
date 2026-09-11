/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Quad */

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
/* Conversion functions for graphene_quad_t (opaque record with hidden fields) */
graphene_quad_t *graphene_quad_t_val(value v) {
  return (graphene_quad_t *)ml_gir_record_ptr_val(v, "graphene_quad_t");
}

value Val_graphene_quad_t(const graphene_quad_t *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(graphene_quad_get_type(), ptr);
}

value Val_graphene_quad_t_option(const graphene_quad_t *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_graphene_quad_t(ptr));
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)


CAMLexport CAMLprim value ml_graphene_quad_alloc(value unit)
{
CAMLparam1(unit);

graphene_quad_t *obj = graphene_quad_alloc();

CAMLreturn(Val_graphene_quad_t(obj));
}
CAMLexport CAMLprim value ml_graphene_quad_init_from_rect(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_quad_t* result = graphene_quad_init_from_rect(graphene_quad_t_val(self), graphene_rect_t_val(arg1));
if (result) result = g_boxed_copy(graphene_quad_get_type(), result);
CAMLreturn(Val_graphene_quad_t(result));
}

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,2,0)

CAMLexport CAMLprim value ml_graphene_quad_init_from_points(value self, value arg1)
{
CAMLparam2(self, arg1);
    int arg1_length = Wosize_val(arg1);
    graphene_point_t* c_arg1 = (graphene_point_t*)g_malloc(sizeof(graphene_point_t) * arg1_length);
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = *graphene_point_t_val(Field(arg1, i));
    }

graphene_quad_t* result = graphene_quad_init_from_points(graphene_quad_t_val(self), c_arg1);
if (result) result = g_boxed_copy(graphene_quad_get_type(), result);
    g_free(c_arg1);
CAMLreturn(Val_graphene_quad_t(result));
}

#else

CAMLexport CAMLprim value ml_graphene_quad_init_from_points(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Quad requires Graphene >= 1.2");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_graphene_quad_init(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

graphene_quad_t* result = graphene_quad_init(graphene_quad_t_val(self), graphene_point_t_val(arg1), graphene_point_t_val(arg2), graphene_point_t_val(arg3), graphene_point_t_val(arg4));
if (result) result = g_boxed_copy(graphene_quad_get_type(), result);
CAMLreturn(Val_graphene_quad_t(result));
}

CAMLexport CAMLprim value ml_graphene_quad_get_point(value self, value arg1)
{
CAMLparam2(self, arg1);

const graphene_point_t* result = graphene_quad_get_point(graphene_quad_t_val(self), Int_val(arg1));
if (result) result = g_boxed_copy(graphene_point_get_type(), result);
CAMLreturn(Val_graphene_point_t(result));
}

CAMLexport CAMLprim value ml_graphene_quad_contains(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_quad_contains(graphene_quad_t_val(self), graphene_point_t_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_graphene_quad_bounds(value self)
{
CAMLparam1(self);
graphene_rect_t out1;

graphene_quad_bounds(graphene_quad_t_val(self), &out1);
CAMLreturn(Val_graphene_rect_t(&out1));
}

GType graphene_quad_get_type (void);


CAMLprim value ml_graphene_quad_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(graphene_quad_get_type()));
}

#else


CAMLexport CAMLprim value ml_graphene_quad_alloc(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("Quad requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quad_bounds(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Quad requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quad_contains(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Quad requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quad_get_point(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Quad requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quad_init(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Quad requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quad_init_from_points(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Quad requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_quad_init_from_rect(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Quad requires Graphene >= 1.0");
return Val_unit;
}


#endif
