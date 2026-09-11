/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Rect */

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
/* Conversion functions for graphene_rect_t (opaque record with hidden fields) */
graphene_rect_t *graphene_rect_t_val(value v) {
  return (graphene_rect_t *)ml_gir_record_ptr_val(v, "graphene_rect_t");
}

value Val_graphene_rect_t(const graphene_rect_t *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(graphene_rect_get_type(), ptr);
}

value Val_graphene_rect_t_option(const graphene_rect_t *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_graphene_rect_t(ptr));
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,0,0)


CAMLexport CAMLprim value ml_graphene_rect_union(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_rect_t out2;

graphene_rect_union(graphene_rect_t_val(self), graphene_rect_t_val(arg1), &out2);
CAMLreturn(Val_graphene_rect_t(&out2));
}

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_rect_scale(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
graphene_rect_t out3;

graphene_rect_scale(graphene_rect_t_val(self), Double_val(arg1), Double_val(arg2), &out3);
CAMLreturn(Val_graphene_rect_t(&out3));
}

#else

CAMLexport CAMLprim value ml_graphene_rect_scale(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Rect requires Graphene >= 1.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_graphene_rect_round_to_pixel(value self)
{
CAMLparam1(self);

graphene_rect_t* result = graphene_rect_round_to_pixel(graphene_rect_t_val(self));
if (result) result = g_boxed_copy(graphene_rect_get_type(), result);
CAMLreturn(Val_graphene_rect_t(result));
}

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_rect_round_extents(value self)
{
CAMLparam1(self);
graphene_rect_t out1;

graphene_rect_round_extents(graphene_rect_t_val(self), &out1);
CAMLreturn(Val_graphene_rect_t(&out1));
}

#else

CAMLexport CAMLprim value ml_graphene_rect_round_extents(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Rect requires Graphene >= 1.10");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,4,0)

CAMLexport CAMLprim value ml_graphene_rect_round(value self)
{
CAMLparam1(self);
graphene_rect_t out1;

graphene_rect_round(graphene_rect_t_val(self), &out1);
CAMLreturn(Val_graphene_rect_t(&out1));
}

#else

CAMLexport CAMLprim value ml_graphene_rect_round(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Rect requires Graphene >= 1.4");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,4,0)

CAMLexport CAMLprim value ml_graphene_rect_offset_r(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
graphene_rect_t out3;

graphene_rect_offset_r(graphene_rect_t_val(self), Double_val(arg1), Double_val(arg2), &out3);
CAMLreturn(Val_graphene_rect_t(&out3));
}

#else

CAMLexport CAMLprim value ml_graphene_rect_offset_r(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Rect requires Graphene >= 1.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_graphene_rect_offset(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

graphene_rect_t* result = graphene_rect_offset(graphene_rect_t_val(self), Double_val(arg1), Double_val(arg2));
if (result) result = g_boxed_copy(graphene_rect_get_type(), result);
CAMLreturn(Val_graphene_rect_t(result));
}

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,4,0)

CAMLexport CAMLprim value ml_graphene_rect_normalize_r(value self)
{
CAMLparam1(self);
graphene_rect_t out1;

graphene_rect_normalize_r(graphene_rect_t_val(self), &out1);
CAMLreturn(Val_graphene_rect_t(&out1));
}

#else

CAMLexport CAMLprim value ml_graphene_rect_normalize_r(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Rect requires Graphene >= 1.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_graphene_rect_normalize(value self)
{
CAMLparam1(self);

graphene_rect_t* result = graphene_rect_normalize(graphene_rect_t_val(self));
if (result) result = g_boxed_copy(graphene_rect_get_type(), result);
CAMLreturn(Val_graphene_rect_t(result));
}

CAMLexport CAMLprim value ml_graphene_rect_intersection(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_rect_t out2;

bool result = graphene_rect_intersection(graphene_rect_t_val(self), graphene_rect_t_val(arg1), &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_graphene_rect_t(&out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_graphene_rect_interpolate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
graphene_rect_t out3;

graphene_rect_interpolate(graphene_rect_t_val(self), graphene_rect_t_val(arg1), Double_val(arg2), &out3);
CAMLreturn(Val_graphene_rect_t(&out3));
}

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,4,0)

CAMLexport CAMLprim value ml_graphene_rect_inset_r(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
graphene_rect_t out3;

graphene_rect_inset_r(graphene_rect_t_val(self), Double_val(arg1), Double_val(arg2), &out3);
CAMLreturn(Val_graphene_rect_t(&out3));
}

#else

CAMLexport CAMLprim value ml_graphene_rect_inset_r(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Rect requires Graphene >= 1.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_graphene_rect_inset(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

graphene_rect_t* result = graphene_rect_inset(graphene_rect_t_val(self), Double_val(arg1), Double_val(arg2));
if (result) result = g_boxed_copy(graphene_rect_get_type(), result);
CAMLreturn(Val_graphene_rect_t(result));
}

CAMLexport CAMLprim value ml_graphene_rect_init_from_rect(value self, value arg1)
{
CAMLparam2(self, arg1);

graphene_rect_t* result = graphene_rect_init_from_rect(graphene_rect_t_val(self), graphene_rect_t_val(arg1));
if (result) result = g_boxed_copy(graphene_rect_get_type(), result);
CAMLreturn(Val_graphene_rect_t(result));
}

CAMLexport CAMLprim value ml_graphene_rect_init(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

graphene_rect_t* result = graphene_rect_init(graphene_rect_t_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4));
if (result) result = g_boxed_copy(graphene_rect_get_type(), result);
CAMLreturn(Val_graphene_rect_t(result));
}

CAMLexport CAMLprim value ml_graphene_rect_get_y(value self)
{
CAMLparam1(self);

float result = graphene_rect_get_y(graphene_rect_t_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_graphene_rect_get_x(value self)
{
CAMLparam1(self);

float result = graphene_rect_get_x(graphene_rect_t_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_graphene_rect_get_width(value self)
{
CAMLparam1(self);

float result = graphene_rect_get_width(graphene_rect_t_val(self));
CAMLreturn(caml_copy_double(result));
}

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,4,0)

CAMLexport CAMLprim value ml_graphene_rect_get_vertices(value self)
{
CAMLparam1(self);
graphene_vec2_t out1[4];

graphene_rect_get_vertices(graphene_rect_t_val(self), out1);
    int out1_length = 4;
    CAMLlocal1(ml_out1);
    ml_out1 = caml_alloc(out1_length, 0);
    for (int i = 0; i < out1_length; i++) {
      Store_field(ml_out1, i, Val_graphene_vec2_t(&out1[i]));
    }

CAMLreturn(ml_out1);
}

#else

CAMLexport CAMLprim value ml_graphene_rect_get_vertices(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Rect requires Graphene >= 1.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_graphene_rect_get_top_right(value self)
{
CAMLparam1(self);
graphene_point_t out1;

graphene_rect_get_top_right(graphene_rect_t_val(self), &out1);
CAMLreturn(Val_graphene_point_t(&out1));
}

CAMLexport CAMLprim value ml_graphene_rect_get_top_left(value self)
{
CAMLparam1(self);
graphene_point_t out1;

graphene_rect_get_top_left(graphene_rect_t_val(self), &out1);
CAMLreturn(Val_graphene_point_t(&out1));
}

CAMLexport CAMLprim value ml_graphene_rect_get_height(value self)
{
CAMLparam1(self);

float result = graphene_rect_get_height(graphene_rect_t_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_graphene_rect_get_center(value self)
{
CAMLparam1(self);
graphene_point_t out1;

graphene_rect_get_center(graphene_rect_t_val(self), &out1);
CAMLreturn(Val_graphene_point_t(&out1));
}

CAMLexport CAMLprim value ml_graphene_rect_get_bottom_right(value self)
{
CAMLparam1(self);
graphene_point_t out1;

graphene_rect_get_bottom_right(graphene_rect_t_val(self), &out1);
CAMLreturn(Val_graphene_point_t(&out1));
}

CAMLexport CAMLprim value ml_graphene_rect_get_bottom_left(value self)
{
CAMLparam1(self);
graphene_point_t out1;

graphene_rect_get_bottom_left(graphene_rect_t_val(self), &out1);
CAMLreturn(Val_graphene_point_t(&out1));
}

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,10,0)

CAMLexport CAMLprim value ml_graphene_rect_get_area(value self)
{
CAMLparam1(self);

float result = graphene_rect_get_area(graphene_rect_t_val(self));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_graphene_rect_get_area(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Rect requires Graphene >= 1.10");
return Val_unit;
}
#endif

#if GRAPHENE_VERSION >= GRAPHENE_ENCODE_VERSION(1,4,0)

CAMLexport CAMLprim value ml_graphene_rect_expand(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_rect_t out2;

graphene_rect_expand(graphene_rect_t_val(self), graphene_point_t_val(arg1), &out2);
CAMLreturn(Val_graphene_rect_t(&out2));
}

#else

CAMLexport CAMLprim value ml_graphene_rect_expand(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Rect requires Graphene >= 1.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_graphene_rect_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_rect_equal(graphene_rect_t_val(self), graphene_rect_t_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_graphene_rect_contains_rect(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_rect_contains_rect(graphene_rect_t_val(self), graphene_rect_t_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_graphene_rect_contains_point(value self, value arg1)
{
CAMLparam2(self, arg1);

bool result = graphene_rect_contains_point(graphene_rect_t_val(self), graphene_point_t_val(arg1));
CAMLreturn(Val_bool(result));
}

GType graphene_rect_get_type (void);


CAMLprim value ml_graphene_rect_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(graphene_rect_get_type()));
}

#else


CAMLexport CAMLprim value ml_graphene_rect_contains_point(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_contains_rect(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_equal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_expand(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_get_area(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_get_bottom_left(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_get_bottom_right(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_get_center(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_get_height(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_get_top_left(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_get_top_right(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_get_vertices(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_get_width(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_get_x(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_get_y(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_init(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_init_from_rect(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_inset(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_inset_r(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_interpolate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_intersection(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_normalize(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_normalize_r(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_offset(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_offset_r(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_round(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_round_extents(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_round_to_pixel(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_scale(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


CAMLexport CAMLprim value ml_graphene_rect_union(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Rect requires Graphene >= 1.0");
return Val_unit;
}


#endif
