/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ShortcutsWindow */

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


#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_shortcuts_window_add_section(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_shortcuts_window_add_section(GtkShortcutsWindow_val(self), GtkShortcutsSection_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_shortcuts_window_add_section(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ShortcutsWindow requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_shortcuts_window_get_section_name(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkShortcutsWindow *obj = (GtkShortcutsWindow *)GtkShortcutsWindow_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "section-name");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_window_get_section_name: property 'section-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "section-name", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_shortcuts_window_set_section_name(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkShortcutsWindow *obj = (GtkShortcutsWindow *)GtkShortcutsWindow_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "section-name");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_window_set_section_name: property 'section-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "section-name", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcuts_window_get_view_name(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkShortcutsWindow *obj = (GtkShortcutsWindow *)GtkShortcutsWindow_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "view-name");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_window_get_view_name: property 'view-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "view-name", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_shortcuts_window_set_view_name(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkShortcutsWindow *obj = (GtkShortcutsWindow *)GtkShortcutsWindow_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "view-name");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_window_set_view_name: property 'view-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "view-name", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_shortcuts_window_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_shortcuts_window_get_type()));
}
