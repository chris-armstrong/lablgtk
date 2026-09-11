/* GENERATED CODE - DO NOT EDIT */
/* C bindings for GLTextureBuilder */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gdk/gdk.h>
/* Include library-specific type conversions and forward declarations */
#include "gdk_decls.h"

#if GTK_CHECK_VERSION(4,12,0)


CAMLexport CAMLprim value ml_gdk_gl_texture_builder_new(value unit)
{
CAMLparam1(unit);

GdkGLTextureBuilder *obj = gdk_gl_texture_builder_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GdkGLTextureBuilder(obj));
}
CAMLexport CAMLprim value ml_gdk_gl_texture_builder_set_width(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_gl_texture_builder_set_width(GdkGLTextureBuilder_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_gl_texture_builder_set_update_texture(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_gl_texture_builder_set_update_texture(GdkGLTextureBuilder_val(self), Option_val(arg1, GdkTexture_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_gl_texture_builder_set_update_region(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_gl_texture_builder_set_update_region(GdkGLTextureBuilder_val(self), Option_val(arg1, cairo_region_t_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_gl_texture_builder_set_id(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_gl_texture_builder_set_id(GdkGLTextureBuilder_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_gl_texture_builder_set_height(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_gl_texture_builder_set_height(GdkGLTextureBuilder_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_gl_texture_builder_set_has_mipmap(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_gl_texture_builder_set_has_mipmap(GdkGLTextureBuilder_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_gl_texture_builder_set_format(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_gl_texture_builder_set_format(GdkGLTextureBuilder_val(self), GdkMemoryFormat_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_gl_texture_builder_set_context(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_gl_texture_builder_set_context(GdkGLTextureBuilder_val(self), Option_val(arg1, GdkGLContext_val, NULL));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,16,0)

CAMLexport CAMLprim value ml_gdk_gl_texture_builder_set_color_state(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_gl_texture_builder_set_color_state(GdkGLTextureBuilder_val(self), GdkColorState_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gdk_gl_texture_builder_set_color_state(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("GLTextureBuilder requires GTK >= 4.16");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_gl_texture_builder_get_width(value self)
{
CAMLparam1(self);

int result = gdk_gl_texture_builder_get_width(GdkGLTextureBuilder_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_gl_texture_builder_get_update_texture(value self)
{
CAMLparam1(self);

GdkTexture* result = gdk_gl_texture_builder_get_update_texture(GdkGLTextureBuilder_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkTexture));
}

CAMLexport CAMLprim value ml_gdk_gl_texture_builder_get_update_region(value self)
{
CAMLparam1(self);

cairo_region_t* result = gdk_gl_texture_builder_get_update_region(GdkGLTextureBuilder_val(self));
if (result) result = g_boxed_copy(cairo_gobject_region_get_type(), result);
CAMLreturn(Val_option(result, Val_cairo_region_t));
}

CAMLexport CAMLprim value ml_gdk_gl_texture_builder_get_id(value self)
{
CAMLparam1(self);

guint result = gdk_gl_texture_builder_get_id(GdkGLTextureBuilder_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_gl_texture_builder_get_height(value self)
{
CAMLparam1(self);

int result = gdk_gl_texture_builder_get_height(GdkGLTextureBuilder_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_gl_texture_builder_get_has_mipmap(value self)
{
CAMLparam1(self);

gboolean result = gdk_gl_texture_builder_get_has_mipmap(GdkGLTextureBuilder_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_gl_texture_builder_get_format(value self)
{
CAMLparam1(self);

GdkMemoryFormat result = gdk_gl_texture_builder_get_format(GdkGLTextureBuilder_val(self));
CAMLreturn(Val_GdkMemoryFormat(result));
}

CAMLexport CAMLprim value ml_gdk_gl_texture_builder_get_context(value self)
{
CAMLparam1(self);

GdkGLContext* result = gdk_gl_texture_builder_get_context(GdkGLTextureBuilder_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkGLContext));
}

#if GTK_CHECK_VERSION(4,16,0)

CAMLexport CAMLprim value ml_gdk_gl_texture_builder_get_color_state(value self)
{
CAMLparam1(self);

GdkColorState* result = gdk_gl_texture_builder_get_color_state(GdkGLTextureBuilder_val(self));
if (result) result = g_boxed_copy(gdk_color_state_get_type(), result);
CAMLreturn(Val_GdkColorState(result));
}

#else

CAMLexport CAMLprim value ml_gdk_gl_texture_builder_get_color_state(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("GLTextureBuilder requires GTK >= 4.16");
return Val_unit;
}
#endif


CAMLprim value ml_gdk_gl_texture_builder_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_gl_texture_builder_get_type()));
}

#else


CAMLexport CAMLprim value ml_gdk_gl_texture_builder_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("GLTextureBuilder requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_gl_texture_builder_get_color_state(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("GLTextureBuilder requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_gl_texture_builder_get_context(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("GLTextureBuilder requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_gl_texture_builder_get_format(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("GLTextureBuilder requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_gl_texture_builder_get_has_mipmap(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("GLTextureBuilder requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_gl_texture_builder_get_height(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("GLTextureBuilder requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_gl_texture_builder_get_id(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("GLTextureBuilder requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_gl_texture_builder_get_update_region(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("GLTextureBuilder requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_gl_texture_builder_get_update_texture(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("GLTextureBuilder requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_gl_texture_builder_get_width(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("GLTextureBuilder requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_gl_texture_builder_set_color_state(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("GLTextureBuilder requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_gl_texture_builder_set_context(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("GLTextureBuilder requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_gl_texture_builder_set_format(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("GLTextureBuilder requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_gl_texture_builder_set_has_mipmap(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("GLTextureBuilder requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_gl_texture_builder_set_height(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("GLTextureBuilder requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_gl_texture_builder_set_id(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("GLTextureBuilder requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_gl_texture_builder_set_update_region(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("GLTextureBuilder requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_gl_texture_builder_set_update_texture(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("GLTextureBuilder requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_gl_texture_builder_set_width(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("GLTextureBuilder requires GTK >= 4.12");
return Val_unit;
}


#endif
