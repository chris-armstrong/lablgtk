/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CellRendererPixbuf */

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


CAMLexport CAMLprim value ml_gtk_cell_renderer_pixbuf_new(value unit)
{
CAMLparam1(unit);

GtkCellRendererPixbuf *obj = gtk_cell_renderer_pixbuf_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkCellRendererPixbuf(obj));
}
CAMLexport CAMLprim value ml_gtk_cell_renderer_pixbuf_get_gicon(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererPixbuf *obj = (GtkCellRendererPixbuf *)GtkCellRendererPixbuf_val(self);
    GIcon *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gicon");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_pixbuf_get_gicon: property 'gicon' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gicon", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GIcon(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_pixbuf_set_gicon(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererPixbuf *obj = (GtkCellRendererPixbuf *)GtkCellRendererPixbuf_val(self);
    GIcon *c_value = GIcon_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gicon");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_pixbuf_set_gicon: property 'gicon' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          caml_failwith("unsupported property type");
g_object_set_property(G_OBJECT(obj), "gicon", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_pixbuf_get_icon_name(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererPixbuf *obj = (GtkCellRendererPixbuf *)GtkCellRendererPixbuf_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "icon-name");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_pixbuf_get_icon_name: property 'icon-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "icon-name", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_pixbuf_set_icon_name(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererPixbuf *obj = (GtkCellRendererPixbuf *)GtkCellRendererPixbuf_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "icon-name");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_pixbuf_set_icon_name: property 'icon-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "icon-name", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_pixbuf_get_icon_size(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererPixbuf *obj = (GtkCellRendererPixbuf *)GtkCellRendererPixbuf_val(self);
    GtkIconSize prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "icon-size");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_pixbuf_get_icon_size: property 'icon-size' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "icon-size", &prop_gvalue);
          prop_value = (GtkIconSize)g_value_get_enum(&prop_gvalue);

      result = Val_GtkIconSize(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_pixbuf_set_icon_size(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererPixbuf *obj = (GtkCellRendererPixbuf *)GtkCellRendererPixbuf_val(self);
    GtkIconSize c_value = GtkIconSize_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "icon-size");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_pixbuf_set_icon_size: property 'icon-size' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "icon-size", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_pixbuf_set_pixbuf(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererPixbuf *obj = (GtkCellRendererPixbuf *)GtkCellRendererPixbuf_val(self);
    GdkPixbuf *c_value = GdkPixbuf_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pixbuf");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_pixbuf_set_pixbuf: property 'pixbuf' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          caml_failwith("unsupported property type");
g_object_set_property(G_OBJECT(obj), "pixbuf", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_pixbuf_get_pixbuf_expander_closed(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererPixbuf *obj = (GtkCellRendererPixbuf *)GtkCellRendererPixbuf_val(self);
    GdkPixbuf *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pixbuf-expander-closed");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_pixbuf_get_pixbuf_expander_closed: property 'pixbuf-expander-closed' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "pixbuf-expander-closed", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GdkPixbuf(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_pixbuf_set_pixbuf_expander_closed(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererPixbuf *obj = (GtkCellRendererPixbuf *)GtkCellRendererPixbuf_val(self);
    GdkPixbuf *c_value = GdkPixbuf_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pixbuf-expander-closed");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_pixbuf_set_pixbuf_expander_closed: property 'pixbuf-expander-closed' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          caml_failwith("unsupported property type");
g_object_set_property(G_OBJECT(obj), "pixbuf-expander-closed", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_pixbuf_get_pixbuf_expander_open(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererPixbuf *obj = (GtkCellRendererPixbuf *)GtkCellRendererPixbuf_val(self);
    GdkPixbuf *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pixbuf-expander-open");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_pixbuf_get_pixbuf_expander_open: property 'pixbuf-expander-open' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "pixbuf-expander-open", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GdkPixbuf(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_pixbuf_set_pixbuf_expander_open(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererPixbuf *obj = (GtkCellRendererPixbuf *)GtkCellRendererPixbuf_val(self);
    GdkPixbuf *c_value = GdkPixbuf_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pixbuf-expander-open");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_pixbuf_set_pixbuf_expander_open: property 'pixbuf-expander-open' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          caml_failwith("unsupported property type");
g_object_set_property(G_OBJECT(obj), "pixbuf-expander-open", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_pixbuf_get_texture(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererPixbuf *obj = (GtkCellRendererPixbuf *)GtkCellRendererPixbuf_val(self);
    GdkTexture *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "texture");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_pixbuf_get_texture: property 'texture' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "texture", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GdkTexture(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_pixbuf_set_texture(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererPixbuf *obj = (GtkCellRendererPixbuf *)GtkCellRendererPixbuf_val(self);
    GdkTexture *c_value = GdkTexture_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "texture");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_pixbuf_set_texture: property 'texture' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          caml_failwith("unsupported property type");
g_object_set_property(G_OBJECT(obj), "texture", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

GType gtk_cell_renderer_pixbuf_get_type (void);


CAMLprim value ml_gtk_cell_renderer_pixbuf_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_cell_renderer_pixbuf_get_type()));
}
