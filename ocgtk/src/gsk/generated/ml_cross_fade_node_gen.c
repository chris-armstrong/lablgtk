/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CrossFadeNode */

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


CAMLexport CAMLprim value ml_gsk_cross_fade_node_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GskCrossFadeNode *obj = gsk_cross_fade_node_new(GskRenderNode_val(arg1), GskRenderNode_val(arg2), Double_val(arg3));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GskCrossFadeNode(obj));
}
CAMLexport CAMLprim value ml_gsk_cross_fade_node_get_start_child(value self)
{
CAMLparam1(self);

GskRenderNode* result = gsk_cross_fade_node_get_start_child(GskCrossFadeNode_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GskRenderNode(result));
}

CAMLexport CAMLprim value ml_gsk_cross_fade_node_get_progress(value self)
{
CAMLparam1(self);

float result = gsk_cross_fade_node_get_progress(GskCrossFadeNode_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gsk_cross_fade_node_get_end_child(value self)
{
CAMLparam1(self);

GskRenderNode* result = gsk_cross_fade_node_get_end_child(GskCrossFadeNode_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GskRenderNode(result));
}


CAMLprim value ml_gsk_cross_fade_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_cross_fade_node_get_type()));
}
