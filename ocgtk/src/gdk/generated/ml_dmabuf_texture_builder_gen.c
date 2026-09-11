/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DmabufTextureBuilder */

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

#if GTK_CHECK_VERSION(4,14,0)


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_new(value unit)
{
CAMLparam1(unit);

GdkDmabufTextureBuilder *obj = gdk_dmabuf_texture_builder_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GdkDmabufTextureBuilder(obj));
}
CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_width(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_dmabuf_texture_builder_set_width(GdkDmabufTextureBuilder_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_update_texture(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_dmabuf_texture_builder_set_update_texture(GdkDmabufTextureBuilder_val(self), Option_val(arg1, GdkTexture_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_update_region(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_dmabuf_texture_builder_set_update_region(GdkDmabufTextureBuilder_val(self), Option_val(arg1, cairo_region_t_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_stride(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gdk_dmabuf_texture_builder_set_stride(GdkDmabufTextureBuilder_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_premultiplied(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_dmabuf_texture_builder_set_premultiplied(GdkDmabufTextureBuilder_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_offset(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gdk_dmabuf_texture_builder_set_offset(GdkDmabufTextureBuilder_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_n_planes(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_dmabuf_texture_builder_set_n_planes(GdkDmabufTextureBuilder_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_modifier(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_dmabuf_texture_builder_set_modifier(GdkDmabufTextureBuilder_val(self), Uint64_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_height(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_dmabuf_texture_builder_set_height(GdkDmabufTextureBuilder_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_fourcc(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_dmabuf_texture_builder_set_fourcc(GdkDmabufTextureBuilder_val(self), UInt32_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_fd(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gdk_dmabuf_texture_builder_set_fd(GdkDmabufTextureBuilder_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_display(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_dmabuf_texture_builder_set_display(GdkDmabufTextureBuilder_val(self), GdkDisplay_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,16,0)

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_color_state(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_dmabuf_texture_builder_set_color_state(GdkDmabufTextureBuilder_val(self), Option_val(arg1, GdkColorState_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_color_state(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.16");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_width(value self)
{
CAMLparam1(self);

unsigned int result = gdk_dmabuf_texture_builder_get_width(GdkDmabufTextureBuilder_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_update_texture(value self)
{
CAMLparam1(self);

GdkTexture* result = gdk_dmabuf_texture_builder_get_update_texture(GdkDmabufTextureBuilder_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkTexture));
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_update_region(value self)
{
CAMLparam1(self);

cairo_region_t* result = gdk_dmabuf_texture_builder_get_update_region(GdkDmabufTextureBuilder_val(self));
if (result) result = g_boxed_copy(cairo_gobject_region_get_type(), result);
CAMLreturn(Val_option(result, Val_cairo_region_t));
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_stride(value self, value arg1)
{
CAMLparam2(self, arg1);

unsigned int result = gdk_dmabuf_texture_builder_get_stride(GdkDmabufTextureBuilder_val(self), Int_val(arg1));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_premultiplied(value self)
{
CAMLparam1(self);

gboolean result = gdk_dmabuf_texture_builder_get_premultiplied(GdkDmabufTextureBuilder_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_offset(value self, value arg1)
{
CAMLparam2(self, arg1);

unsigned int result = gdk_dmabuf_texture_builder_get_offset(GdkDmabufTextureBuilder_val(self), Int_val(arg1));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_n_planes(value self)
{
CAMLparam1(self);

unsigned int result = gdk_dmabuf_texture_builder_get_n_planes(GdkDmabufTextureBuilder_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_modifier(value self)
{
CAMLparam1(self);

guint64 result = gdk_dmabuf_texture_builder_get_modifier(GdkDmabufTextureBuilder_val(self));
CAMLreturn(integers_copy_uint64(result));
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_height(value self)
{
CAMLparam1(self);

unsigned int result = gdk_dmabuf_texture_builder_get_height(GdkDmabufTextureBuilder_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_fourcc(value self)
{
CAMLparam1(self);

guint32 result = gdk_dmabuf_texture_builder_get_fourcc(GdkDmabufTextureBuilder_val(self));
CAMLreturn(Val_uint32(result));
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_fd(value self, value arg1)
{
CAMLparam2(self, arg1);

int result = gdk_dmabuf_texture_builder_get_fd(GdkDmabufTextureBuilder_val(self), Int_val(arg1));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_display(value self)
{
CAMLparam1(self);

GdkDisplay* result = gdk_dmabuf_texture_builder_get_display(GdkDmabufTextureBuilder_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkDisplay(result));
}

#if GTK_CHECK_VERSION(4,16,0)

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_color_state(value self)
{
CAMLparam1(self);

GdkColorState* result = gdk_dmabuf_texture_builder_get_color_state(GdkDmabufTextureBuilder_val(self));
if (result) result = g_boxed_copy(gdk_color_state_get_type(), result);
CAMLreturn(Val_option(result, Val_GdkColorState));
}

#else

CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_color_state(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.16");
return Val_unit;
}
#endif

GType gdk_dmabuf_texture_builder_get_type (void);


CAMLprim value ml_gdk_dmabuf_texture_builder_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_dmabuf_texture_builder_get_type()));
}

#else


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_color_state(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_display(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_fd(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_fourcc(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_height(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_modifier(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_n_planes(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_offset(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_premultiplied(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_stride(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_update_region(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_update_texture(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_get_width(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_color_state(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_display(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_fd(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_fourcc(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_height(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_modifier(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_n_planes(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_offset(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_premultiplied(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_stride(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_update_region(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_update_texture(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_texture_builder_set_width(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DmabufTextureBuilder requires GTK >= 4.14");
return Val_unit;
}


#endif
