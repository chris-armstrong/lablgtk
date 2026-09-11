/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FileChooserWidget */

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


CAMLexport CAMLprim value ml_gtk_file_chooser_widget_new(value arg1)
{
CAMLparam1(arg1);

GtkFileChooserWidget *obj = gtk_file_chooser_widget_new(GtkFileChooserAction_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkFileChooserWidget(obj));
}
CAMLexport CAMLprim value ml_gtk_file_chooser_widget_get_search_mode(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkFileChooserWidget *obj = (GtkFileChooserWidget *)GtkFileChooserWidget_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "search-mode");
if (pspec == NULL) caml_failwith("ml_gtk_file_chooser_widget_get_search_mode: property 'search-mode' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "search-mode", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_file_chooser_widget_set_search_mode(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkFileChooserWidget *obj = (GtkFileChooserWidget *)GtkFileChooserWidget_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "search-mode");
if (pspec == NULL) caml_failwith("ml_gtk_file_chooser_widget_set_search_mode: property 'search-mode' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "search-mode", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_file_chooser_widget_get_show_time(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkFileChooserWidget *obj = (GtkFileChooserWidget *)GtkFileChooserWidget_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "show-time");
if (pspec == NULL) caml_failwith("ml_gtk_file_chooser_widget_get_show_time: property 'show-time' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "show-time", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_file_chooser_widget_get_show_time(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FileChooserWidget requires GTK >= 4.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_file_chooser_widget_get_subtitle(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkFileChooserWidget *obj = (GtkFileChooserWidget *)GtkFileChooserWidget_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "subtitle");
if (pspec == NULL) caml_failwith("ml_gtk_file_chooser_widget_get_subtitle: property 'subtitle' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "subtitle", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

GType gtk_file_chooser_widget_get_type (void);


CAMLprim value ml_gtk_file_chooser_widget_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_file_chooser_widget_get_type()));
}
