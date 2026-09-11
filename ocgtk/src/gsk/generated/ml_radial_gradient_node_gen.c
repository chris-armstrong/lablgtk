/* GENERATED CODE - DO NOT EDIT */
/* C bindings for RadialGradientNode */

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


CAMLexport CAMLprim value ml_gsk_radial_gradient_node_new_native(value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7, value arg8)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);
CAMLxparam3(arg6, arg7, arg8);
    int arg7_length = Wosize_val(arg7);
    GskColorStop* c_arg7 = (GskColorStop*)g_malloc(sizeof(GskColorStop) * arg7_length);
    for (int i = 0; i < arg7_length; i++) {
      c_arg7[i] = *GskColorStop_val(Field(arg7, i));
    }

GskRadialGradientNode *obj = gsk_radial_gradient_node_new(graphene_rect_t_val(arg1), graphene_point_t_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5), Double_val(arg6), c_arg7, Gsize_val(arg8));
if (obj) g_object_ref_sink(obj);

    g_free(c_arg7);
CAMLreturn(Val_GskRadialGradientNode(obj));}

CAMLexport CAMLprim value ml_gsk_radial_gradient_node_new_bytecode(value * argv, int argn)
{
return ml_gsk_radial_gradient_node_new_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

CAMLexport CAMLprim value ml_gsk_radial_gradient_node_get_vradius(value self)
{
CAMLparam1(self);

float result = gsk_radial_gradient_node_get_vradius(GskRadialGradientNode_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gsk_radial_gradient_node_get_start(value self)
{
CAMLparam1(self);

float result = gsk_radial_gradient_node_get_start(GskRadialGradientNode_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gsk_radial_gradient_node_get_n_color_stops(value self)
{
CAMLparam1(self);

gsize result = gsk_radial_gradient_node_get_n_color_stops(GskRadialGradientNode_val(self));
CAMLreturn(Val_gsize(result));
}

CAMLexport CAMLprim value ml_gsk_radial_gradient_node_get_hradius(value self)
{
CAMLparam1(self);

float result = gsk_radial_gradient_node_get_hradius(GskRadialGradientNode_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gsk_radial_gradient_node_get_end(value self)
{
CAMLparam1(self);

float result = gsk_radial_gradient_node_get_end(GskRadialGradientNode_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gsk_radial_gradient_node_get_color_stops(value self)
{
CAMLparam1(self);
gsize out1;

const GskColorStop* result = gsk_radial_gradient_node_get_color_stops(GskRadialGradientNode_val(self), &out1);
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

CAMLexport CAMLprim value ml_gsk_radial_gradient_node_get_center(value self)
{
CAMLparam1(self);

const graphene_point_t* result = gsk_radial_gradient_node_get_center(GskRadialGradientNode_val(self));
if (result) result = g_boxed_copy(graphene_point_get_type(), result);
CAMLreturn(Val_graphene_point_t(result));
}

GType gsk_radial_gradient_node_get_type (void);


CAMLprim value ml_gsk_radial_gradient_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_radial_gradient_node_get_type()));
}
