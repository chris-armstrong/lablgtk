/* GENERATED CODE - DO NOT EDIT */
/* C bindings for RepeatingLinearGradientNode */

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


CAMLexport CAMLprim value ml_gsk_repeating_linear_gradient_node_new(value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);
    int arg4_length = Wosize_val(arg4);
    GskColorStop* c_arg4 = (GskColorStop*)g_malloc(sizeof(GskColorStop) * arg4_length);
    for (int i = 0; i < arg4_length; i++) {
      c_arg4[i] = *GskColorStop_val(Field(arg4, i));
    }

GskRepeatingLinearGradientNode *obj = gsk_repeating_linear_gradient_node_new(graphene_rect_t_val(arg1), graphene_point_t_val(arg2), graphene_point_t_val(arg3), c_arg4, Gsize_val(arg5));
if (obj) g_object_ref_sink(obj);

    g_free(c_arg4);
CAMLreturn(Val_GskRepeatingLinearGradientNode(obj));
}
GType gsk_repeating_linear_gradient_node_get_type (void);


CAMLprim value ml_gsk_repeating_linear_gradient_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_repeating_linear_gradient_node_get_type()));
}
