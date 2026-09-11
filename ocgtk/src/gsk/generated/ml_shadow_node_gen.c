/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ShadowNode */

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


CAMLexport CAMLprim value ml_gsk_shadow_node_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);
    int arg2_length = Wosize_val(arg2);
    GskShadow* c_arg2 = (GskShadow*)g_malloc(sizeof(GskShadow) * arg2_length);
    for (int i = 0; i < arg2_length; i++) {
      c_arg2[i] = *GskShadow_val(Field(arg2, i));
    }

GskShadowNode *obj = gsk_shadow_node_new(GskRenderNode_val(arg1), c_arg2, Gsize_val(arg3));
if (obj) g_object_ref_sink(obj);

    g_free(c_arg2);
CAMLreturn(Val_GskShadowNode(obj));
}
CAMLexport CAMLprim value ml_gsk_shadow_node_get_shadow(value self, value arg1)
{
CAMLparam2(self, arg1);

const GskShadow* result = gsk_shadow_node_get_shadow(GskShadowNode_val(self), Gsize_val(arg1));
CAMLreturn(Val_GskShadow(result));
}

CAMLexport CAMLprim value ml_gsk_shadow_node_get_n_shadows(value self)
{
CAMLparam1(self);

gsize result = gsk_shadow_node_get_n_shadows(GskShadowNode_val(self));
CAMLreturn(Val_gsize(result));
}

CAMLexport CAMLprim value ml_gsk_shadow_node_get_child(value self)
{
CAMLparam1(self);

GskRenderNode* result = gsk_shadow_node_get_child(GskShadowNode_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GskRenderNode(result));
}


CAMLprim value ml_gsk_shadow_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_shadow_node_get_type()));
}
