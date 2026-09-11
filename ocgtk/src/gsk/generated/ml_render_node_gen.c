/* GENERATED CODE - DO NOT EDIT */
/* C bindings for RenderNode */

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


CAMLexport CAMLprim value ml_gsk_render_node_write_to_file(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = gsk_render_node_write_to_file(GskRenderNode_val(self), String_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gsk_render_node_unref(value self)
{
CAMLparam1(self);

gsk_render_node_unref(GskRenderNode_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_render_node_serialize(value self)
{
CAMLparam1(self);

GBytes* result = gsk_render_node_serialize(GskRenderNode_val(self));
CAMLreturn(Val_GBytes(result));
}

CAMLexport CAMLprim value ml_gsk_render_node_ref(value self)
{
CAMLparam1(self);

GskRenderNode* result = gsk_render_node_ref(GskRenderNode_val(self));
CAMLreturn(Val_GskRenderNode(result));
}

#if GTK_CHECK_VERSION(4,16,0)

CAMLexport CAMLprim value ml_gsk_render_node_get_opaque_rect(value self)
{
CAMLparam1(self);
graphene_rect_t out1;

gboolean result = gsk_render_node_get_opaque_rect(GskRenderNode_val(self), &out1);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_graphene_rect_t(&out1));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_gsk_render_node_get_opaque_rect(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("RenderNode requires GTK >= 4.16");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gsk_render_node_get_node_type(value self)
{
CAMLparam1(self);

GskRenderNodeType result = gsk_render_node_get_node_type(GskRenderNode_val(self));
CAMLreturn(Val_GskRenderNodeType(result));
}

CAMLexport CAMLprim value ml_gsk_render_node_get_bounds(value self)
{
CAMLparam1(self);
graphene_rect_t out1;

gsk_render_node_get_bounds(GskRenderNode_val(self), &out1);
CAMLreturn(Val_graphene_rect_t(&out1));
}

CAMLexport CAMLprim value ml_gsk_render_node_draw(value self, value arg1)
{
CAMLparam2(self, arg1);

gsk_render_node_draw(GskRenderNode_val(self), cairo_t_val(arg1));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gsk_render_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_render_node_get_type()));
}
