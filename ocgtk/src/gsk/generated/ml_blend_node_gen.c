/* GENERATED CODE - DO NOT EDIT */
/* C bindings for BlendNode */

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


CAMLexport CAMLprim value ml_gsk_blend_node_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GskBlendNode *obj = gsk_blend_node_new(GskRenderNode_val(arg1), GskRenderNode_val(arg2), GskBlendMode_val(arg3));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GskBlendNode(obj));
}
CAMLexport CAMLprim value ml_gsk_blend_node_get_top_child(value self)
{
CAMLparam1(self);

GskRenderNode* result = gsk_blend_node_get_top_child(GskBlendNode_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GskRenderNode(result));
}

CAMLexport CAMLprim value ml_gsk_blend_node_get_bottom_child(value self)
{
CAMLparam1(self);

GskRenderNode* result = gsk_blend_node_get_bottom_child(GskBlendNode_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GskRenderNode(result));
}

CAMLexport CAMLprim value ml_gsk_blend_node_get_blend_mode(value self)
{
CAMLparam1(self);

GskBlendMode result = gsk_blend_node_get_blend_mode(GskBlendNode_val(self));
CAMLreturn(Val_GskBlendMode(result));
}


CAMLprim value ml_gsk_blend_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_blend_node_get_type()));
}
