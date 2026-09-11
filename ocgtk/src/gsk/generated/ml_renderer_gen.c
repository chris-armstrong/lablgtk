/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Renderer */

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


CAMLexport CAMLprim value ml_gsk_renderer_new_for_surface(value arg1)
{
CAMLparam1(arg1);

GskRenderer *obj = gsk_renderer_new_for_surface(GdkSurface_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GskRenderer(obj));
}
CAMLexport CAMLprim value ml_gsk_renderer_unrealize(value self)
{
CAMLparam1(self);

gsk_renderer_unrealize(GskRenderer_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_renderer_render_texture(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

GdkTexture* result = gsk_renderer_render_texture(GskRenderer_val(self), GskRenderNode_val(arg1), Option_val(arg2, graphene_rect_t_val, NULL));
CAMLreturn(Val_GdkTexture(result));
}

CAMLexport CAMLprim value ml_gsk_renderer_render(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gsk_renderer_render(GskRenderer_val(self), GskRenderNode_val(arg1), Option_val(arg2, cairo_region_t_val, NULL));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gsk_renderer_realize_for_display(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = gsk_renderer_realize_for_display(GskRenderer_val(self), GdkDisplay_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_gsk_renderer_realize_for_display(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Renderer requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gsk_renderer_realize(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = gsk_renderer_realize(GskRenderer_val(self), Option_val(arg1, GdkSurface_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gsk_renderer_is_realized(value self)
{
CAMLparam1(self);

gboolean result = gsk_renderer_is_realized(GskRenderer_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gsk_renderer_get_surface(value self)
{
CAMLparam1(self);

GdkSurface* result = gsk_renderer_get_surface(GskRenderer_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkSurface));
}

GType gsk_renderer_get_type (void);


CAMLprim value ml_gsk_renderer_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_renderer_get_type()));
}
