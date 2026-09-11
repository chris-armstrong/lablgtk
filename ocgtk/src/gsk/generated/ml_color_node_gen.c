/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ColorNode */

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


CAMLexport CAMLprim value ml_gsk_color_node_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GskColorNode *obj = gsk_color_node_new(GdkRGBA_val(arg1), graphene_rect_t_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GskColorNode(obj));
}
CAMLexport CAMLprim value ml_gsk_color_node_get_color(value self)
{
CAMLparam1(self);

const GdkRGBA* result = gsk_color_node_get_color(GskColorNode_val(self));
if (result) result = g_boxed_copy(gdk_rgba_get_type(), result);
CAMLreturn(Val_GdkRGBA(result));
}

GType gsk_color_node_get_type (void);


CAMLprim value ml_gsk_color_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_color_node_get_type()));
}
