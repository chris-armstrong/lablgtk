/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TextNode */

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


CAMLexport CAMLprim value ml_gsk_text_node_new(value arg1, value arg2, value arg3, value arg4)
{
CAMLparam4(arg1, arg2, arg3, arg4);

GskTextNode *obj = gsk_text_node_new(PangoFont_val(arg1), PangoGlyphString_val(arg2), GdkRGBA_val(arg3), graphene_point_t_val(arg4));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GskTextNode(obj));
}
#if GTK_CHECK_VERSION(4,2,0)

CAMLexport CAMLprim value ml_gsk_text_node_has_color_glyphs(value self)
{
CAMLparam1(self);

gboolean result = gsk_text_node_has_color_glyphs(GskTextNode_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gsk_text_node_has_color_glyphs(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TextNode requires GTK >= 4.2");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gsk_text_node_get_offset(value self)
{
CAMLparam1(self);

const graphene_point_t* result = gsk_text_node_get_offset(GskTextNode_val(self));
if (result) result = g_boxed_copy(graphene_point_get_type(), result);
CAMLreturn(Val_graphene_point_t(result));
}

CAMLexport CAMLprim value ml_gsk_text_node_get_num_glyphs(value self)
{
CAMLparam1(self);

guint result = gsk_text_node_get_num_glyphs(GskTextNode_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gsk_text_node_get_glyphs(value self)
{
CAMLparam1(self);
guint out1;

const PangoGlyphInfo* result = gsk_text_node_get_glyphs(GskTextNode_val(self), &out1);
    int result_length = out1;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, Val_PangoGlyphInfo(&result[i]));
    }
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_result);
    Store_field(ret, 1, Val_int(out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gsk_text_node_get_font(value self)
{
CAMLparam1(self);

PangoFont* result = gsk_text_node_get_font(GskTextNode_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_PangoFont(result));
}

CAMLexport CAMLprim value ml_gsk_text_node_get_color(value self)
{
CAMLparam1(self);

const GdkRGBA* result = gsk_text_node_get_color(GskTextNode_val(self));
if (result) result = g_boxed_copy(gdk_rgba_get_type(), result);
CAMLreturn(Val_GdkRGBA(result));
}


CAMLprim value ml_gsk_text_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_text_node_get_type()));
}
