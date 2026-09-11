/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Image */

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


CAMLexport CAMLprim value ml_gtk_image_new(value unit)
{
CAMLparam1(unit);

GtkImage *obj = gtk_image_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkImage(obj));
}
CAMLexport CAMLprim value ml_gtk_image_new_from_file(value arg1)
{
CAMLparam1(arg1);

GtkImage *obj = gtk_image_new_from_file(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkImage(obj));
}
CAMLexport CAMLprim value ml_gtk_image_new_from_gicon(value arg1)
{
CAMLparam1(arg1);

GtkImage *obj = gtk_image_new_from_gicon(GIcon_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkImage(obj));
}
CAMLexport CAMLprim value ml_gtk_image_new_from_icon_name(value arg1)
{
CAMLparam1(arg1);

GtkImage *obj = gtk_image_new_from_icon_name(String_option_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkImage(obj));
}
CAMLexport CAMLprim value ml_gtk_image_new_from_paintable(value arg1)
{
CAMLparam1(arg1);

GtkImage *obj = gtk_image_new_from_paintable(Option_val(arg1, GdkPaintable_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkImage(obj));
}
CAMLexport CAMLprim value ml_gtk_image_new_from_pixbuf(value arg1)
{
CAMLparam1(arg1);

GtkImage *obj = gtk_image_new_from_pixbuf(Option_val(arg1, GdkPixbuf_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkImage(obj));
}
CAMLexport CAMLprim value ml_gtk_image_new_from_resource(value arg1)
{
CAMLparam1(arg1);

GtkImage *obj = gtk_image_new_from_resource(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkImage(obj));
}
CAMLexport CAMLprim value ml_gtk_image_set_pixel_size(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_image_set_pixel_size(GtkImage_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_image_set_icon_size(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_image_set_icon_size(GtkImage_val(self), GtkIconSize_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_image_set_from_resource(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_image_set_from_resource(GtkImage_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_image_set_from_pixbuf(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_image_set_from_pixbuf(GtkImage_val(self), Option_val(arg1, GdkPixbuf_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_image_set_from_paintable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_image_set_from_paintable(GtkImage_val(self), Option_val(arg1, GdkPaintable_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_image_set_from_icon_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_image_set_from_icon_name(GtkImage_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_image_set_from_gicon(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_image_set_from_gicon(GtkImage_val(self), GIcon_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_image_set_from_file(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_image_set_from_file(GtkImage_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_image_get_storage_type(value self)
{
CAMLparam1(self);

GtkImageType result = gtk_image_get_storage_type(GtkImage_val(self));
CAMLreturn(Val_GtkImageType(result));
}

CAMLexport CAMLprim value ml_gtk_image_get_pixel_size(value self)
{
CAMLparam1(self);

int result = gtk_image_get_pixel_size(GtkImage_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_image_get_paintable(value self)
{
CAMLparam1(self);

GdkPaintable* result = gtk_image_get_paintable(GtkImage_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkPaintable));
}

CAMLexport CAMLprim value ml_gtk_image_get_icon_size(value self)
{
CAMLparam1(self);

GtkIconSize result = gtk_image_get_icon_size(GtkImage_val(self));
CAMLreturn(Val_GtkIconSize(result));
}

CAMLexport CAMLprim value ml_gtk_image_get_icon_name(value self)
{
CAMLparam1(self);

const char* result = gtk_image_get_icon_name(GtkImage_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_image_get_gicon(value self)
{
CAMLparam1(self);

GIcon* result = gtk_image_get_gicon(GtkImage_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GIcon));
}

CAMLexport CAMLprim value ml_gtk_image_clear(value self)
{
CAMLparam1(self);

gtk_image_clear(GtkImage_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_image_get_use_fallback(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkImage *obj = (GtkImage *)GtkImage_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "use-fallback");
if (pspec == NULL) caml_failwith("ml_gtk_image_get_use_fallback: property 'use-fallback' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "use-fallback", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_image_set_use_fallback(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkImage *obj = (GtkImage *)GtkImage_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "use-fallback");
if (pspec == NULL) caml_failwith("ml_gtk_image_set_use_fallback: property 'use-fallback' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "use-fallback", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_image_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_image_get_type()));
}
