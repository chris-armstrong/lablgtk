/* GENERATED CODE - DO NOT EDIT */
/* C bindings for InsetShadowNode */

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


CAMLexport CAMLprim value ml_gsk_inset_shadow_node_new_native(value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);
CAMLxparam1(arg6);

GskInsetShadowNode *obj = gsk_inset_shadow_node_new(GskRoundedRect_val(arg1), GdkRGBA_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5), Double_val(arg6));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GskInsetShadowNode(obj));}

CAMLexport CAMLprim value ml_gsk_inset_shadow_node_new_bytecode(value * argv, int argn)
{
return ml_gsk_inset_shadow_node_new_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gsk_inset_shadow_node_get_spread(value self)
{
CAMLparam1(self);

float result = gsk_inset_shadow_node_get_spread(GskInsetShadowNode_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gsk_inset_shadow_node_get_outline(value self)
{
CAMLparam1(self);

const GskRoundedRect* result = gsk_inset_shadow_node_get_outline(GskInsetShadowNode_val(self));
CAMLreturn(Val_GskRoundedRect(result));
}

CAMLexport CAMLprim value ml_gsk_inset_shadow_node_get_dy(value self)
{
CAMLparam1(self);

float result = gsk_inset_shadow_node_get_dy(GskInsetShadowNode_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gsk_inset_shadow_node_get_dx(value self)
{
CAMLparam1(self);

float result = gsk_inset_shadow_node_get_dx(GskInsetShadowNode_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gsk_inset_shadow_node_get_color(value self)
{
CAMLparam1(self);

const GdkRGBA* result = gsk_inset_shadow_node_get_color(GskInsetShadowNode_val(self));
if (result) result = g_boxed_copy(gdk_rgba_get_type(), result);
CAMLreturn(Val_GdkRGBA(result));
}

CAMLexport CAMLprim value ml_gsk_inset_shadow_node_get_blur_radius(value self)
{
CAMLparam1(self);

float result = gsk_inset_shadow_node_get_blur_radius(GskInsetShadowNode_val(self));
CAMLreturn(caml_copy_double(result));
}


CAMLprim value ml_gsk_inset_shadow_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_inset_shadow_node_get_type()));
}
