/* GENERATED CODE - DO NOT EDIT */
/* C bindings for RepeatNode */

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


CAMLexport CAMLprim value ml_gsk_repeat_node_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GskRepeatNode *obj = gsk_repeat_node_new(graphene_rect_t_val(arg1), GskRenderNode_val(arg2), Option_val(arg3, graphene_rect_t_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GskRepeatNode(obj));
}
CAMLexport CAMLprim value ml_gsk_repeat_node_get_child_bounds(value self)
{
CAMLparam1(self);

const graphene_rect_t* result = gsk_repeat_node_get_child_bounds(GskRepeatNode_val(self));
if (result) result = g_boxed_copy(graphene_rect_get_type(), result);
CAMLreturn(Val_graphene_rect_t(result));
}

CAMLexport CAMLprim value ml_gsk_repeat_node_get_child(value self)
{
CAMLparam1(self);

GskRenderNode* result = gsk_repeat_node_get_child(GskRepeatNode_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GskRenderNode(result));
}

GType gsk_repeat_node_get_type (void);


CAMLprim value ml_gsk_repeat_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_repeat_node_get_type()));
}
