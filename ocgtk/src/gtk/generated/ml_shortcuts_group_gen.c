/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ShortcutsGroup */

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

CAMLexport CAMLprim value ml_gtk_shortcuts_group_add_shortcut(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_shortcuts_group_add_shortcut(GtkShortcutsGroup_val(self), GtkShortcutsShortcut_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_shortcuts_group_add_shortcut(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ShortcutsGroup requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_shortcuts_group_set_accel_size_group(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkShortcutsGroup *obj = (GtkShortcutsGroup *)GtkShortcutsGroup_val(self);
    GtkSizeGroup *c_value = GtkSizeGroup_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "accel-size-group");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_group_set_accel_size_group: property 'accel-size-group' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_object(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "accel-size-group", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcuts_group_get_height(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkShortcutsGroup *obj = (GtkShortcutsGroup *)GtkShortcutsGroup_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "height");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_group_get_height: property 'height' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "height", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_shortcuts_group_get_title(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkShortcutsGroup *obj = (GtkShortcutsGroup *)GtkShortcutsGroup_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "title");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_group_get_title: property 'title' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "title", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_shortcuts_group_set_title(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkShortcutsGroup *obj = (GtkShortcutsGroup *)GtkShortcutsGroup_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "title");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_group_set_title: property 'title' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "title", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcuts_group_set_title_size_group(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkShortcutsGroup *obj = (GtkShortcutsGroup *)GtkShortcutsGroup_val(self);
    GtkSizeGroup *c_value = GtkSizeGroup_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "title-size-group");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_group_set_title_size_group: property 'title-size-group' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_object(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "title-size-group", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcuts_group_get_view(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkShortcutsGroup *obj = (GtkShortcutsGroup *)GtkShortcutsGroup_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "view");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_group_get_view: property 'view' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "view", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_shortcuts_group_set_view(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkShortcutsGroup *obj = (GtkShortcutsGroup *)GtkShortcutsGroup_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "view");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_group_set_view: property 'view' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "view", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_shortcuts_group_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_shortcuts_group_get_type()));
}
