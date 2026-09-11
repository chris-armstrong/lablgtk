/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CairoNode */

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


CAMLexport CAMLprim value ml_gsk_cairo_node_new(value arg1)
{
CAMLparam1(arg1);

GskCairoNode *obj = gsk_cairo_node_new(graphene_rect_t_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GskCairoNode(obj));
}
CAMLexport CAMLprim value ml_gsk_cairo_node_get_surface(value self)
{
CAMLparam1(self);

cairo_surface_t* result = gsk_cairo_node_get_surface(GskCairoNode_val(self));
if (result) result = g_boxed_copy(cairo_gobject_surface_get_type(), result);
CAMLreturn(Val_cairo_surface_t(result));
}

CAMLexport CAMLprim value ml_gsk_cairo_node_get_draw_context(value self)
{
CAMLparam1(self);

cairo_t* result = gsk_cairo_node_get_draw_context(GskCairoNode_val(self));
CAMLreturn(Val_cairo_t(result));
}


CAMLprim value ml_gsk_cairo_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_cairo_node_get_type()));
}
