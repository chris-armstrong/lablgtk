/* GENERATED CODE - DO NOT EDIT */
/* C bindings for RoundedClipNode */

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


CAMLexport CAMLprim value ml_gsk_rounded_clip_node_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GskRoundedClipNode *obj = gsk_rounded_clip_node_new(GskRenderNode_val(arg1), GskRoundedRect_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GskRoundedClipNode(obj));
}
CAMLexport CAMLprim value ml_gsk_rounded_clip_node_get_clip(value self)
{
CAMLparam1(self);

const GskRoundedRect* result = gsk_rounded_clip_node_get_clip(GskRoundedClipNode_val(self));
CAMLreturn(Val_GskRoundedRect(result));
}

CAMLexport CAMLprim value ml_gsk_rounded_clip_node_get_child(value self)
{
CAMLparam1(self);

GskRenderNode* result = gsk_rounded_clip_node_get_child(GskRoundedClipNode_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GskRenderNode(result));
}


CAMLprim value ml_gsk_rounded_clip_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_rounded_clip_node_get_type()));
}
