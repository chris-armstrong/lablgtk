/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Texture */

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


CAMLexport CAMLprim value ml_gdk_texture_new_for_pixbuf(value arg1)
{
CAMLparam1(arg1);

GdkTexture *obj = gdk_texture_new_for_pixbuf(GdkPixbuf_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GdkTexture(obj));
}
#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gdk_texture_new_from_bytes(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GdkTexture *obj = gdk_texture_new_from_bytes(GBytes_val(arg1), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GdkTexture(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#else

CAMLexport CAMLprim value ml_gdk_texture_new_from_bytes(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("Texture requires GTK >= 4.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_texture_new_from_file(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GdkTexture *obj = gdk_texture_new_from_file(GFile_val(arg1), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GdkTexture(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gdk_texture_new_from_filename(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GdkTexture *obj = gdk_texture_new_from_filename(String_val(arg1), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GdkTexture(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#else

CAMLexport CAMLprim value ml_gdk_texture_new_from_filename(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("Texture requires GTK >= 4.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_texture_new_from_resource(value arg1)
{
CAMLparam1(arg1);

GdkTexture *obj = gdk_texture_new_from_resource(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GdkTexture(obj));
}
#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gdk_texture_save_to_tiff_bytes(value self)
{
CAMLparam1(self);

GBytes* result = gdk_texture_save_to_tiff_bytes(GdkTexture_val(self));
CAMLreturn(Val_GBytes(result));
}

#else

CAMLexport CAMLprim value ml_gdk_texture_save_to_tiff_bytes(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Texture requires GTK >= 4.6");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gdk_texture_save_to_tiff(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gdk_texture_save_to_tiff(GdkTexture_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gdk_texture_save_to_tiff(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Texture requires GTK >= 4.6");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gdk_texture_save_to_png_bytes(value self)
{
CAMLparam1(self);

GBytes* result = gdk_texture_save_to_png_bytes(GdkTexture_val(self));
CAMLreturn(Val_GBytes(result));
}

#else

CAMLexport CAMLprim value ml_gdk_texture_save_to_png_bytes(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Texture requires GTK >= 4.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_texture_save_to_png(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gdk_texture_save_to_png(GdkTexture_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_texture_get_width(value self)
{
CAMLparam1(self);

int result = gdk_texture_get_width(GdkTexture_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_texture_get_height(value self)
{
CAMLparam1(self);

int result = gdk_texture_get_height(GdkTexture_val(self));
CAMLreturn(Val_int(result));
}

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gdk_texture_get_format(value self)
{
CAMLparam1(self);

GdkMemoryFormat result = gdk_texture_get_format(GdkTexture_val(self));
CAMLreturn(Val_GdkMemoryFormat(result));
}

#else

CAMLexport CAMLprim value ml_gdk_texture_get_format(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Texture requires GTK >= 4.10");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,16,0)

CAMLexport CAMLprim value ml_gdk_texture_get_color_state(value self)
{
CAMLparam1(self);

GdkColorState* result = gdk_texture_get_color_state(GdkTexture_val(self));
if (result) result = g_boxed_copy(gdk_color_state_get_type(), result);
CAMLreturn(Val_GdkColorState(result));
}

#else

CAMLexport CAMLprim value ml_gdk_texture_get_color_state(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Texture requires GTK >= 4.16");
return Val_unit;
}
#endif


CAMLprim value ml_gdk_texture_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_texture_get_type()));
}
