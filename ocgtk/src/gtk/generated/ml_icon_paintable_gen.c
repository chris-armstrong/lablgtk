/* GENERATED CODE - DO NOT EDIT */
/* C bindings for IconPaintable */

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


CAMLexport CAMLprim value ml_gtk_icon_paintable_new_for_file(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GtkIconPaintable *obj = gtk_icon_paintable_new_for_file(GFile_val(arg1), Int_val(arg2), Int_val(arg3));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkIconPaintable(obj));
}
CAMLexport CAMLprim value ml_gtk_icon_paintable_is_symbolic(value self)
{
CAMLparam1(self);

gboolean result = gtk_icon_paintable_is_symbolic(GtkIconPaintable_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_icon_paintable_get_icon_name(value self)
{
CAMLparam1(self);

const char* result = gtk_icon_paintable_get_icon_name(GtkIconPaintable_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_icon_paintable_get_file(value self)
{
CAMLparam1(self);

GFile* result = gtk_icon_paintable_get_file(GtkIconPaintable_val(self));
CAMLreturn(Val_option(result, Val_GFile));
}

CAMLexport CAMLprim value ml_gtk_icon_paintable_get_scale(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkIconPaintable *obj = (GtkIconPaintable *)GtkIconPaintable_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "scale");
if (pspec == NULL) caml_failwith("ml_gtk_icon_paintable_get_scale: property 'scale' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "scale", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_icon_paintable_set_scale(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkIconPaintable *obj = (GtkIconPaintable *)GtkIconPaintable_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "scale");
if (pspec == NULL) caml_failwith("ml_gtk_icon_paintable_set_scale: property 'scale' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "scale", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_paintable_get_size(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkIconPaintable *obj = (GtkIconPaintable *)GtkIconPaintable_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "size");
if (pspec == NULL) caml_failwith("ml_gtk_icon_paintable_get_size: property 'size' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "size", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_icon_paintable_set_size(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkIconPaintable *obj = (GtkIconPaintable *)GtkIconPaintable_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "size");
if (pspec == NULL) caml_failwith("ml_gtk_icon_paintable_set_size: property 'size' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "size", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_icon_paintable_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_icon_paintable_get_type()));
}
