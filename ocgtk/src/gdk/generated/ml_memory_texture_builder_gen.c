/* GENERATED CODE - DO NOT EDIT */
/* C bindings for MemoryTextureBuilder */

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

#if GTK_CHECK_VERSION(4,16,0)


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_new(value unit)
{
CAMLparam1(unit);

GdkMemoryTextureBuilder *obj = gdk_memory_texture_builder_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GdkMemoryTextureBuilder(obj));
}
CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_width(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_memory_texture_builder_set_width(GdkMemoryTextureBuilder_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_update_texture(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_memory_texture_builder_set_update_texture(GdkMemoryTextureBuilder_val(self), Option_val(arg1, GdkTexture_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_update_region(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_memory_texture_builder_set_update_region(GdkMemoryTextureBuilder_val(self), Option_val(arg1, cairo_region_t_val, NULL));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_stride_for_plane(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gdk_memory_texture_builder_set_stride_for_plane(GdkMemoryTextureBuilder_val(self), Int_val(arg1), Gsize_val(arg2));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_stride_for_plane(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_stride(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_memory_texture_builder_set_stride(GdkMemoryTextureBuilder_val(self), Gsize_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_offset(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gdk_memory_texture_builder_set_offset(GdkMemoryTextureBuilder_val(self), Int_val(arg1), Gsize_val(arg2));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_offset(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_height(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_memory_texture_builder_set_height(GdkMemoryTextureBuilder_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_format(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_memory_texture_builder_set_format(GdkMemoryTextureBuilder_val(self), GdkMemoryFormat_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_color_state(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_memory_texture_builder_set_color_state(GdkMemoryTextureBuilder_val(self), GdkColorState_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_bytes(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_memory_texture_builder_set_bytes(GdkMemoryTextureBuilder_val(self), Option_val(arg1, GBytes_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_width(value self)
{
CAMLparam1(self);

int result = gdk_memory_texture_builder_get_width(GdkMemoryTextureBuilder_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_update_texture(value self)
{
CAMLparam1(self);

GdkTexture* result = gdk_memory_texture_builder_get_update_texture(GdkMemoryTextureBuilder_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkTexture));
}

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_update_region(value self)
{
CAMLparam1(self);

cairo_region_t* result = gdk_memory_texture_builder_get_update_region(GdkMemoryTextureBuilder_val(self));
if (result) result = g_boxed_copy(cairo_gobject_region_get_type(), result);
CAMLreturn(Val_option(result, Val_cairo_region_t));
}

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_stride_for_plane(value self, value arg1)
{
CAMLparam2(self, arg1);

gsize result = gdk_memory_texture_builder_get_stride_for_plane(GdkMemoryTextureBuilder_val(self), Int_val(arg1));
CAMLreturn(Val_gsize(result));
}

#else

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_stride_for_plane(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_stride(value self)
{
CAMLparam1(self);

gsize result = gdk_memory_texture_builder_get_stride(GdkMemoryTextureBuilder_val(self));
CAMLreturn(Val_gsize(result));
}

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_offset(value self, value arg1)
{
CAMLparam2(self, arg1);

gsize result = gdk_memory_texture_builder_get_offset(GdkMemoryTextureBuilder_val(self), Int_val(arg1));
CAMLreturn(Val_gsize(result));
}

#else

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_offset(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_height(value self)
{
CAMLparam1(self);

int result = gdk_memory_texture_builder_get_height(GdkMemoryTextureBuilder_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_format(value self)
{
CAMLparam1(self);

GdkMemoryFormat result = gdk_memory_texture_builder_get_format(GdkMemoryTextureBuilder_val(self));
CAMLreturn(Val_GdkMemoryFormat(result));
}

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_color_state(value self)
{
CAMLparam1(self);

GdkColorState* result = gdk_memory_texture_builder_get_color_state(GdkMemoryTextureBuilder_val(self));
if (result) result = g_boxed_copy(gdk_color_state_get_type(), result);
CAMLreturn(Val_GdkColorState(result));
}

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_bytes(value self)
{
CAMLparam1(self);

GBytes* result = gdk_memory_texture_builder_get_bytes(GdkMemoryTextureBuilder_val(self));
CAMLreturn(Val_option(result, Val_GBytes));
}

CAMLexport CAMLprim value ml_gdk_memory_texture_builder_build(value self)
{
CAMLparam1(self);

GdkTexture* result = gdk_memory_texture_builder_build(GdkMemoryTextureBuilder_val(self));
CAMLreturn(Val_GdkTexture(result));
}


CAMLprim value ml_gdk_memory_texture_builder_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_memory_texture_builder_get_type()));
}

#else


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_build(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_bytes(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_color_state(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_format(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_height(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_offset(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_stride(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_stride_for_plane(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_update_region(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_update_texture(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_get_width(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_bytes(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_color_state(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_format(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_height(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_offset(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_stride(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_stride_for_plane(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_update_region(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_update_texture(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_memory_texture_builder_set_width(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MemoryTextureBuilder requires GTK >= 4.16");
return Val_unit;
}


#endif
