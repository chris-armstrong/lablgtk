/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Snapshot */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"
#include "converters.h"

#include <gtk/gtk.h>
/* Include library-specific type conversions and forward declarations */
#include "gtk_decls.h"


CAMLexport CAMLprim value ml_gtk_snapshot_new(value unit)
{
CAMLparam1(unit);

GtkSnapshot *obj = gtk_snapshot_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkSnapshot(obj));
}
CAMLexport CAMLprim value ml_gtk_snapshot_translate_3d(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_snapshot_translate_3d(GtkSnapshot_val(self), graphene_point3d_t_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_translate(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_snapshot_translate(GtkSnapshot_val(self), graphene_point_t_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_transform_matrix(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_snapshot_transform_matrix(GtkSnapshot_val(self), graphene_matrix_t_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_transform(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_snapshot_transform(GtkSnapshot_val(self), Option_val(arg1, GskTransform_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_to_paintable(value self, value arg1)
{
CAMLparam2(self, arg1);

GdkPaintable* result = gtk_snapshot_to_paintable(GtkSnapshot_val(self), Option_val(arg1, graphene_size_t_val, NULL));
CAMLreturn(Val_option(result, Val_GdkPaintable));
}

CAMLexport CAMLprim value ml_gtk_snapshot_to_node(value self)
{
CAMLparam1(self);

GskRenderNode* result = gtk_snapshot_to_node(GtkSnapshot_val(self));
CAMLreturn(Val_option(result, Val_GskRenderNode));
}

CAMLexport CAMLprim value ml_gtk_snapshot_scale_3d(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_snapshot_scale_3d(GtkSnapshot_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_scale(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_snapshot_scale(GtkSnapshot_val(self), Double_val(arg1), Double_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_save(value self)
{
CAMLparam1(self);

gtk_snapshot_save(GtkSnapshot_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_rotate_3d(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_snapshot_rotate_3d(GtkSnapshot_val(self), Double_val(arg1), graphene_vec3_t_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_rotate(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_snapshot_rotate(GtkSnapshot_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_restore(value self)
{
CAMLparam1(self);

gtk_snapshot_restore(GtkSnapshot_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_render_layout(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gtk_snapshot_render_layout(GtkSnapshot_val(self), GtkStyleContext_val(arg1), Double_val(arg2), Double_val(arg3), PangoLayout_val(arg4));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_render_insertion_cursor_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam2(arg5, arg6);

gtk_snapshot_render_insertion_cursor(GtkSnapshot_val(self), GtkStyleContext_val(arg1), Double_val(arg2), Double_val(arg3), PangoLayout_val(arg4), Int_val(arg5), PangoDirection_val(arg6));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gtk_snapshot_render_insertion_cursor_bytecode(value * argv, int argn)
{
return ml_gtk_snapshot_render_insertion_cursor_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

CAMLexport CAMLprim value ml_gtk_snapshot_render_frame_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);

gtk_snapshot_render_frame(GtkSnapshot_val(self), GtkStyleContext_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gtk_snapshot_render_frame_bytecode(value * argv, int argn)
{
return ml_gtk_snapshot_render_frame_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gtk_snapshot_render_focus_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);

gtk_snapshot_render_focus(GtkSnapshot_val(self), GtkStyleContext_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gtk_snapshot_render_focus_bytecode(value * argv, int argn)
{
return ml_gtk_snapshot_render_focus_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gtk_snapshot_render_background_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);

gtk_snapshot_render_background(GtkSnapshot_val(self), GtkStyleContext_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gtk_snapshot_render_background_bytecode(value * argv, int argn)
{
return ml_gtk_snapshot_render_background_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_snapshot_push_stroke(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_snapshot_push_stroke(GtkSnapshot_val(self), GskPath_val(arg1), GskStroke_val(arg2));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_snapshot_push_stroke(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Snapshot requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_snapshot_push_shadow(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
    int arg1_length = Wosize_val(arg1);
    GskShadow* c_arg1 = (GskShadow*)g_malloc(sizeof(GskShadow) * arg1_length);
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = *GskShadow_val(Field(arg1, i));
    }

gtk_snapshot_push_shadow(GtkSnapshot_val(self), c_arg1, Gsize_val(arg2));
    g_free(c_arg1);
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_push_rounded_clip(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_snapshot_push_rounded_clip(GtkSnapshot_val(self), GskRoundedRect_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_push_repeat(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_snapshot_push_repeat(GtkSnapshot_val(self), graphene_rect_t_val(arg1), Option_val(arg2, graphene_rect_t_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_push_opacity(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_snapshot_push_opacity(GtkSnapshot_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_snapshot_push_mask(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_snapshot_push_mask(GtkSnapshot_val(self), GskMaskMode_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_snapshot_push_mask(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Snapshot requires GTK >= 4.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_snapshot_push_gl_shader(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_snapshot_push_gl_shader(GtkSnapshot_val(self), GskGLShader_val(arg1), graphene_rect_t_val(arg2), GBytes_val(arg3));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_snapshot_push_fill(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_snapshot_push_fill(GtkSnapshot_val(self), GskPath_val(arg1), GskFillRule_val(arg2));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_snapshot_push_fill(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Snapshot requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_snapshot_push_cross_fade(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_snapshot_push_cross_fade(GtkSnapshot_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gtk_snapshot_push_component_transfer(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gtk_snapshot_push_component_transfer(GtkSnapshot_val(self), GskComponentTransfer_val(arg1), GskComponentTransfer_val(arg2), GskComponentTransfer_val(arg3), GskComponentTransfer_val(arg4));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_snapshot_push_component_transfer(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Snapshot requires GTK >= 4.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_snapshot_push_color_matrix(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_snapshot_push_color_matrix(GtkSnapshot_val(self), graphene_matrix_t_val(arg1), graphene_vec4_t_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_push_clip(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_snapshot_push_clip(GtkSnapshot_val(self), graphene_rect_t_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_push_blur(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_snapshot_push_blur(GtkSnapshot_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_push_blend(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_snapshot_push_blend(GtkSnapshot_val(self), GskBlendMode_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_pop(value self)
{
CAMLparam1(self);

gtk_snapshot_pop(GtkSnapshot_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_perspective(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_snapshot_perspective(GtkSnapshot_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_gl_shader_pop_texture(value self)
{
CAMLparam1(self);

gtk_snapshot_gl_shader_pop_texture(GtkSnapshot_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_append_texture(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_snapshot_append_texture(GtkSnapshot_val(self), GdkTexture_val(arg1), graphene_rect_t_val(arg2));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_snapshot_append_stroke(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_snapshot_append_stroke(GtkSnapshot_val(self), GskPath_val(arg1), GskStroke_val(arg2), GdkRGBA_val(arg3));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_snapshot_append_stroke(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Snapshot requires GTK >= 4.14");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_snapshot_append_scaled_texture(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_snapshot_append_scaled_texture(GtkSnapshot_val(self), GdkTexture_val(arg1), GskScalingFilter_val(arg2), graphene_rect_t_val(arg3));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_snapshot_append_scaled_texture(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Snapshot requires GTK >= 4.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_snapshot_append_repeating_radial_gradient_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7, value arg8)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam4(arg5, arg6, arg7, arg8);
    int arg7_length = Wosize_val(arg7);
    GskColorStop* c_arg7 = (GskColorStop*)g_malloc(sizeof(GskColorStop) * arg7_length);
    for (int i = 0; i < arg7_length; i++) {
      c_arg7[i] = *GskColorStop_val(Field(arg7, i));
    }

gtk_snapshot_append_repeating_radial_gradient(GtkSnapshot_val(self), graphene_rect_t_val(arg1), graphene_point_t_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5), Double_val(arg6), c_arg7, Gsize_val(arg8));
    g_free(c_arg7);
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gtk_snapshot_append_repeating_radial_gradient_bytecode(value * argv, int argn)
{
return ml_gtk_snapshot_append_repeating_radial_gradient_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8]);
}

CAMLexport CAMLprim value ml_gtk_snapshot_append_repeating_linear_gradient_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);
    int arg4_length = Wosize_val(arg4);
    GskColorStop* c_arg4 = (GskColorStop*)g_malloc(sizeof(GskColorStop) * arg4_length);
    for (int i = 0; i < arg4_length; i++) {
      c_arg4[i] = *GskColorStop_val(Field(arg4, i));
    }

gtk_snapshot_append_repeating_linear_gradient(GtkSnapshot_val(self), graphene_rect_t_val(arg1), graphene_point_t_val(arg2), graphene_point_t_val(arg3), c_arg4, Gsize_val(arg5));
    g_free(c_arg4);
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gtk_snapshot_append_repeating_linear_gradient_bytecode(value * argv, int argn)
{
return ml_gtk_snapshot_append_repeating_linear_gradient_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gtk_snapshot_append_radial_gradient_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7, value arg8)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam4(arg5, arg6, arg7, arg8);
    int arg7_length = Wosize_val(arg7);
    GskColorStop* c_arg7 = (GskColorStop*)g_malloc(sizeof(GskColorStop) * arg7_length);
    for (int i = 0; i < arg7_length; i++) {
      c_arg7[i] = *GskColorStop_val(Field(arg7, i));
    }

gtk_snapshot_append_radial_gradient(GtkSnapshot_val(self), graphene_rect_t_val(arg1), graphene_point_t_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5), Double_val(arg6), c_arg7, Gsize_val(arg8));
    g_free(c_arg7);
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gtk_snapshot_append_radial_gradient_bytecode(value * argv, int argn)
{
return ml_gtk_snapshot_append_radial_gradient_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8]);
}

CAMLexport CAMLprim value ml_gtk_snapshot_append_outset_shadow_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam2(arg5, arg6);

gtk_snapshot_append_outset_shadow(GtkSnapshot_val(self), GskRoundedRect_val(arg1), GdkRGBA_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5), Double_val(arg6));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gtk_snapshot_append_outset_shadow_bytecode(value * argv, int argn)
{
return ml_gtk_snapshot_append_outset_shadow_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

CAMLexport CAMLprim value ml_gtk_snapshot_append_node(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_snapshot_append_node(GtkSnapshot_val(self), GskRenderNode_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_append_linear_gradient_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);
    int arg4_length = Wosize_val(arg4);
    GskColorStop* c_arg4 = (GskColorStop*)g_malloc(sizeof(GskColorStop) * arg4_length);
    for (int i = 0; i < arg4_length; i++) {
      c_arg4[i] = *GskColorStop_val(Field(arg4, i));
    }

gtk_snapshot_append_linear_gradient(GtkSnapshot_val(self), graphene_rect_t_val(arg1), graphene_point_t_val(arg2), graphene_point_t_val(arg3), c_arg4, Gsize_val(arg5));
    g_free(c_arg4);
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gtk_snapshot_append_linear_gradient_bytecode(value * argv, int argn)
{
return ml_gtk_snapshot_append_linear_gradient_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gtk_snapshot_append_layout(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_snapshot_append_layout(GtkSnapshot_val(self), PangoLayout_val(arg1), GdkRGBA_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_append_inset_shadow_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam2(arg5, arg6);

gtk_snapshot_append_inset_shadow(GtkSnapshot_val(self), GskRoundedRect_val(arg1), GdkRGBA_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5), Double_val(arg6));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gtk_snapshot_append_inset_shadow_bytecode(value * argv, int argn)
{
return ml_gtk_snapshot_append_inset_shadow_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_snapshot_append_fill(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_snapshot_append_fill(GtkSnapshot_val(self), GskPath_val(arg1), GskFillRule_val(arg2), GdkRGBA_val(arg3));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_snapshot_append_fill(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Snapshot requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_snapshot_append_conic_gradient_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);
    int arg4_length = Wosize_val(arg4);
    GskColorStop* c_arg4 = (GskColorStop*)g_malloc(sizeof(GskColorStop) * arg4_length);
    for (int i = 0; i < arg4_length; i++) {
      c_arg4[i] = *GskColorStop_val(Field(arg4, i));
    }

gtk_snapshot_append_conic_gradient(GtkSnapshot_val(self), graphene_rect_t_val(arg1), graphene_point_t_val(arg2), Double_val(arg3), c_arg4, Gsize_val(arg5));
    g_free(c_arg4);
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gtk_snapshot_append_conic_gradient_bytecode(value * argv, int argn)
{
return ml_gtk_snapshot_append_conic_gradient_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gtk_snapshot_append_color(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_snapshot_append_color(GtkSnapshot_val(self), GdkRGBA_val(arg1), graphene_rect_t_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_snapshot_append_cairo(value self, value arg1)
{
CAMLparam2(self, arg1);

cairo_t* result = gtk_snapshot_append_cairo(GtkSnapshot_val(self), graphene_rect_t_val(arg1));
CAMLreturn(Val_cairo_t(result));
}

CAMLexport CAMLprim value ml_gtk_snapshot_append_border(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
    int arg2_length = Wosize_val(arg2);
    float* c_arg2 = (float*)g_malloc(sizeof(float) * arg2_length);
    for (int i = 0; i < arg2_length; i++) {
      c_arg2[i] = Double_val(Field(arg2, i));
    }
    int arg3_length = Wosize_val(arg3);
    GdkRGBA* c_arg3 = (GdkRGBA*)g_malloc(sizeof(GdkRGBA) * arg3_length);
    for (int i = 0; i < arg3_length; i++) {
      c_arg3[i] = *GdkRGBA_val(Field(arg3, i));
    }

gtk_snapshot_append_border(GtkSnapshot_val(self), GskRoundedRect_val(arg1), c_arg2, c_arg3);
    g_free(c_arg2);
    g_free(c_arg3);
CAMLreturn(Val_unit);
}

GType gtk_snapshot_get_type (void);


CAMLprim value ml_gtk_snapshot_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_snapshot_get_type()));
}
