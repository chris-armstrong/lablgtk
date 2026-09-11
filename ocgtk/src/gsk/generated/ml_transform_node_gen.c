/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TransformNode */

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


CAMLexport CAMLprim value ml_gsk_transform_node_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GskTransformNode *obj = gsk_transform_node_new(GskRenderNode_val(arg1), GskTransform_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GskTransformNode(obj));
}
CAMLexport CAMLprim value ml_gsk_transform_node_get_transform(value self)
{
CAMLparam1(self);

GskTransform* result = gsk_transform_node_get_transform(GskTransformNode_val(self));
if (result) result = g_boxed_copy(gsk_transform_get_type(), result);
CAMLreturn(Val_GskTransform(result));
}

CAMLexport CAMLprim value ml_gsk_transform_node_get_child(value self)
{
CAMLparam1(self);

GskRenderNode* result = gsk_transform_node_get_child(GskTransformNode_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GskRenderNode(result));
}


CAMLprim value ml_gsk_transform_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_transform_node_get_type()));
}
