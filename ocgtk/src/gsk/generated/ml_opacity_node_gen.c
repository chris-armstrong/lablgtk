/* GENERATED CODE - DO NOT EDIT */
/* C bindings for OpacityNode */

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


CAMLexport CAMLprim value ml_gsk_opacity_node_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GskOpacityNode *obj = gsk_opacity_node_new(GskRenderNode_val(arg1), Double_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GskOpacityNode(obj));
}
CAMLexport CAMLprim value ml_gsk_opacity_node_get_opacity(value self)
{
CAMLparam1(self);

float result = gsk_opacity_node_get_opacity(GskOpacityNode_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gsk_opacity_node_get_child(value self)
{
CAMLparam1(self);

GskRenderNode* result = gsk_opacity_node_get_child(GskOpacityNode_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GskRenderNode(result));
}

GType gsk_opacity_node_get_type (void);


CAMLprim value ml_gsk_opacity_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_opacity_node_get_type()));
}
