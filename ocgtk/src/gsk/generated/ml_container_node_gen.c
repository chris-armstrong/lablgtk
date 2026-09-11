/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ContainerNode */

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


CAMLexport CAMLprim value ml_gsk_container_node_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
    int arg1_length = Wosize_val(arg1);
    GskRenderNode** c_arg1 = (GskRenderNode**)g_malloc(sizeof(GskRenderNode*) * arg1_length);
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = GskRenderNode_val(Field(arg1, i));
    }

GskContainerNode *obj = gsk_container_node_new(c_arg1, Int_val(arg2));
if (obj) g_object_ref_sink(obj);

    g_free(c_arg1);
CAMLreturn(Val_GskContainerNode(obj));
}
CAMLexport CAMLprim value ml_gsk_container_node_get_n_children(value self)
{
CAMLparam1(self);

guint result = gsk_container_node_get_n_children(GskContainerNode_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gsk_container_node_get_child(value self, value arg1)
{
CAMLparam2(self, arg1);

GskRenderNode* result = gsk_container_node_get_child(GskContainerNode_val(self), Int_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GskRenderNode(result));
}


CAMLprim value ml_gsk_container_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_container_node_get_type()));
}
