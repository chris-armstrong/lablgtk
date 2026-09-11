/* GENERATED CODE - DO NOT EDIT */
/* C bindings for BlurNode */

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


CAMLexport CAMLprim value ml_gsk_blur_node_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GskBlurNode *obj = gsk_blur_node_new(GskRenderNode_val(arg1), Double_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GskBlurNode(obj));
}
CAMLexport CAMLprim value ml_gsk_blur_node_get_radius(value self)
{
CAMLparam1(self);

float result = gsk_blur_node_get_radius(GskBlurNode_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gsk_blur_node_get_child(value self)
{
CAMLparam1(self);

GskRenderNode* result = gsk_blur_node_get_child(GskBlurNode_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GskRenderNode(result));
}


CAMLprim value ml_gsk_blur_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_blur_node_get_type()));
}
