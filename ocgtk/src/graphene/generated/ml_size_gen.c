/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Size */

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
/* Conversion functions for graphene_size_t (opaque record with hidden fields) */
graphene_size_t *graphene_size_t_val(value v) {
  return (graphene_size_t *)ml_gir_record_ptr_val(v, "graphene_size_t");
}

value Val_graphene_size_t(const graphene_size_t *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(graphene_size_get_type(), ptr);
}

value Val_graphene_size_t_option(const graphene_size_t *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_graphene_size_t(ptr));
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)


CAMLexport CAMLprim value ml_graphene_size_alloc(value unit)
{
CAMLparam1(unit);

graphene_size_t *obj = graphene_size_alloc();

CAMLreturn(Val_graphene_size_t(obj));
}
CAMLexport CAMLprim value ml_graphene_size_scale(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_size_t out2;

graphene_size_scale(graphene_size_t_val(self), Double_val(arg1), &out2);
CAMLreturn(Val_graphene_size_t(&out2));
}

CAMLexport CAMLprim value ml_graphene_size_interpolate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
graphene_size_t out3;

graphene_size_interpolate(graphene_size_t_val(self), graphene_size_t_val(arg1), Double_val(arg2), &out3);
CAMLreturn(Val_graphene_size_t(&out3));
}

CAMLexport CAMLprim value ml_graphene_size_init_from_size(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_size_t* result = graphene_size_init_from_size(graphene_size_t_val(self), graphene_size_t_val(arg1));
if (result) result = g_boxed_copy(graphene_size_get_type(), result);
CAMLreturn(Val_graphene_size_t(result));
}

CAMLexport CAMLprim value ml_graphene_size_init(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

graphene_size_t* result = graphene_size_init(graphene_size_t_val(self), Double_val(arg1), Double_val(arg2));
if (result) result = g_boxed_copy(graphene_size_get_type(), result);
CAMLreturn(Val_graphene_size_t(result));
}

CAMLexport CAMLprim value ml_graphene_size_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_size_equal(graphene_size_t_val(self), graphene_size_t_val(arg1));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_graphene_size_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(graphene_size_get_type()));
}

#else


CAMLexport CAMLprim value ml_graphene_size_alloc(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("Size requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_size_equal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Size requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_size_init(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Size requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_size_init_from_size(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Size requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_size_interpolate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Size requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_size_scale(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Size requires Graphene >= 1.0");
return Val_unit;
}


#endif
