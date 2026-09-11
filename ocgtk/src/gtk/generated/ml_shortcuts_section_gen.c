/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ShortcutsSection */

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

CAMLexport CAMLprim value ml_gtk_shortcuts_section_add_group(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_shortcuts_section_add_group(GtkShortcutsSection_val(self), GtkShortcutsGroup_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_shortcuts_section_add_group(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ShortcutsSection requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_shortcuts_section_get_max_height(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkShortcutsSection *obj = (GtkShortcutsSection *)GtkShortcutsSection_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "max-height");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_section_get_max_height: property 'max-height' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "max-height", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_shortcuts_section_set_max_height(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkShortcutsSection *obj = (GtkShortcutsSection *)GtkShortcutsSection_val(self);
    guint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "max-height");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_section_set_max_height: property 'max-height' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_uint(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "max-height", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcuts_section_get_section_name(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkShortcutsSection *obj = (GtkShortcutsSection *)GtkShortcutsSection_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "section-name");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_section_get_section_name: property 'section-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "section-name", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_shortcuts_section_set_section_name(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkShortcutsSection *obj = (GtkShortcutsSection *)GtkShortcutsSection_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "section-name");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_section_set_section_name: property 'section-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "section-name", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcuts_section_get_title(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkShortcutsSection *obj = (GtkShortcutsSection *)GtkShortcutsSection_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "title");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_section_get_title: property 'title' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "title", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_shortcuts_section_set_title(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkShortcutsSection *obj = (GtkShortcutsSection *)GtkShortcutsSection_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "title");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_section_set_title: property 'title' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "title", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcuts_section_get_view_name(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkShortcutsSection *obj = (GtkShortcutsSection *)GtkShortcutsSection_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "view-name");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_section_get_view_name: property 'view-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "view-name", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_shortcuts_section_set_view_name(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkShortcutsSection *obj = (GtkShortcutsSection *)GtkShortcutsSection_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "view-name");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_section_set_view_name: property 'view-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "view-name", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_shortcuts_section_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_shortcuts_section_get_type()));
}
