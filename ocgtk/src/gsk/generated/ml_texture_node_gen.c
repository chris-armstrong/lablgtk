/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TextureNode */

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


CAMLexport CAMLprim value ml_gsk_texture_node_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GskTextureNode *obj = gsk_texture_node_new(GdkTexture_val(arg1), graphene_rect_t_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GskTextureNode(obj));
}
CAMLexport CAMLprim value ml_gsk_texture_node_get_texture(value self)
{
CAMLparam1(self);

GdkTexture* result = gsk_texture_node_get_texture(GskTextureNode_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkTexture(result));
}

GType gsk_texture_node_get_type (void);


CAMLprim value ml_gsk_texture_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_texture_node_get_type()));
}
