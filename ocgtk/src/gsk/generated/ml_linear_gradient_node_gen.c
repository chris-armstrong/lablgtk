/* GENERATED CODE - DO NOT EDIT */
/* C bindings for LinearGradientNode */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gsk/gsk.h>
/* Include library-specific type conversions and forward declarations */
#include "gsk_decls.h"


CAMLexport CAMLprim value ml_gsk_linear_gradient_node_new(value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);
    int arg4_length = Wosize_val(arg4);
    GskColorStop* c_arg4 = (GskColorStop*)g_malloc(sizeof(GskColorStop) * arg4_length);
    for (int i = 0; i < arg4_length; i++) {
      c_arg4[i] = *GskColorStop_val(Field(arg4, i));
    }

GskLinearGradientNode *obj = gsk_linear_gradient_node_new(graphene_rect_t_val(arg1), graphene_point_t_val(arg2), graphene_point_t_val(arg3), c_arg4, Gsize_val(arg5));
if (obj) g_object_ref_sink(obj);

    g_free(c_arg4);
CAMLreturn(Val_GskLinearGradientNode(obj));
}
CAMLexport CAMLprim value ml_gsk_linear_gradient_node_get_start(value self)
{
CAMLparam1(self);

const graphene_point_t* result = gsk_linear_gradient_node_get_start(GskLinearGradientNode_val(self));
if (result) result = g_boxed_copy(graphene_point_get_type(), result);
CAMLreturn(Val_graphene_point_t(result));
}

CAMLexport CAMLprim value ml_gsk_linear_gradient_node_get_n_color_stops(value self)
{
CAMLparam1(self);

gsize result = gsk_linear_gradient_node_get_n_color_stops(GskLinearGradientNode_val(self));
CAMLreturn(Val_gsize(result));
}

CAMLexport CAMLprim value ml_gsk_linear_gradient_node_get_end(value self)
{
CAMLparam1(self);

const graphene_point_t* result = gsk_linear_gradient_node_get_end(GskLinearGradientNode_val(self));
if (result) result = g_boxed_copy(graphene_point_get_type(), result);
CAMLreturn(Val_graphene_point_t(result));
}

CAMLexport CAMLprim value ml_gsk_linear_gradient_node_get_color_stops(value self)
{
CAMLparam1(self);
gsize out1;

const GskColorStop* result = gsk_linear_gradient_node_get_color_stops(GskLinearGradientNode_val(self), &out1);
    int result_length = out1;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, Val_GskColorStop(&result[i]));
    }
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_result);
    Store_field(ret, 1, Val_gsize(out1));
    CAMLreturn(ret);
}


CAMLprim value ml_gsk_linear_gradient_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_linear_gradient_node_get_type()));
}
