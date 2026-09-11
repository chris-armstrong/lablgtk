/* GENERATED CODE - DO NOT EDIT */
/* C bindings for RepeatingRadialGradientNode */

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


CAMLexport CAMLprim value ml_gsk_repeating_radial_gradient_node_new_native(value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7, value arg8)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);
CAMLxparam3(arg6, arg7, arg8);
    int arg7_length = Wosize_val(arg7);
    GskColorStop* c_arg7 = (GskColorStop*)g_malloc(sizeof(GskColorStop) * arg7_length);
    for (int i = 0; i < arg7_length; i++) {
      c_arg7[i] = *GskColorStop_val(Field(arg7, i));
    }

GskRepeatingRadialGradientNode *obj = gsk_repeating_radial_gradient_node_new(graphene_rect_t_val(arg1), graphene_point_t_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5), Double_val(arg6), c_arg7, Gsize_val(arg8));
if (obj) g_object_ref_sink(obj);

    g_free(c_arg7);
CAMLreturn(Val_GskRepeatingRadialGradientNode(obj));}

CAMLexport CAMLprim value ml_gsk_repeating_radial_gradient_node_new_bytecode(value * argv, int argn)
{
return ml_gsk_repeating_radial_gradient_node_new_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}


CAMLprim value ml_gsk_repeating_radial_gradient_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_repeating_radial_gradient_node_get_type()));
}
