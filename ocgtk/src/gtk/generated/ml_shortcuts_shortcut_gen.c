/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ShortcutsShortcut */

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


CAMLexport CAMLprim value ml_gtk_shortcuts_shortcut_set_accel_size_group(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkShortcutsShortcut *obj = (GtkShortcutsShortcut *)GtkShortcutsShortcut_val(self);
    GtkSizeGroup *c_value = GtkSizeGroup_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "accel-size-group");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_shortcut_set_accel_size_group: property 'accel-size-group' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_object(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "accel-size-group", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcuts_shortcut_get_accelerator(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkShortcutsShortcut *obj = (GtkShortcutsShortcut *)GtkShortcutsShortcut_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "accelerator");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_shortcut_get_accelerator: property 'accelerator' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "accelerator", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_shortcuts_shortcut_set_accelerator(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkShortcutsShortcut *obj = (GtkShortcutsShortcut *)GtkShortcutsShortcut_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "accelerator");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_shortcut_set_accelerator: property 'accelerator' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "accelerator", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcuts_shortcut_get_action_name(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkShortcutsShortcut *obj = (GtkShortcutsShortcut *)GtkShortcutsShortcut_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "action-name");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_shortcut_get_action_name: property 'action-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "action-name", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_shortcuts_shortcut_set_action_name(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkShortcutsShortcut *obj = (GtkShortcutsShortcut *)GtkShortcutsShortcut_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "action-name");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_shortcut_set_action_name: property 'action-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "action-name", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcuts_shortcut_get_direction(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkShortcutsShortcut *obj = (GtkShortcutsShortcut *)GtkShortcutsShortcut_val(self);
    GtkTextDirection prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "direction");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_shortcut_get_direction: property 'direction' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "direction", &prop_gvalue);
          prop_value = (GtkTextDirection)g_value_get_enum(&prop_gvalue);

      result = Val_GtkTextDirection(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_shortcuts_shortcut_set_direction(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkShortcutsShortcut *obj = (GtkShortcutsShortcut *)GtkShortcutsShortcut_val(self);
    GtkTextDirection c_value = GtkTextDirection_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "direction");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_shortcut_set_direction: property 'direction' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "direction", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcuts_shortcut_get_icon(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkShortcutsShortcut *obj = (GtkShortcutsShortcut *)GtkShortcutsShortcut_val(self);
    GIcon *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "icon");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_shortcut_get_icon: property 'icon' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "icon", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GIcon(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_shortcuts_shortcut_set_icon(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkShortcutsShortcut *obj = (GtkShortcutsShortcut *)GtkShortcutsShortcut_val(self);
    GIcon *c_value = GIcon_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "icon");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_shortcut_set_icon: property 'icon' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          caml_failwith("unsupported property type");
g_object_set_property(G_OBJECT(obj), "icon", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcuts_shortcut_get_icon_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkShortcutsShortcut *obj = (GtkShortcutsShortcut *)GtkShortcutsShortcut_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "icon-set");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_shortcut_get_icon_set: property 'icon-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "icon-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_shortcuts_shortcut_set_icon_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkShortcutsShortcut *obj = (GtkShortcutsShortcut *)GtkShortcutsShortcut_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "icon-set");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_shortcut_set_icon_set: property 'icon-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "icon-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcuts_shortcut_get_shortcut_type(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkShortcutsShortcut *obj = (GtkShortcutsShortcut *)GtkShortcutsShortcut_val(self);
    GtkShortcutType prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "shortcut-type");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_shortcut_get_shortcut_type: property 'shortcut-type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "shortcut-type", &prop_gvalue);
          prop_value = (GtkShortcutType)g_value_get_enum(&prop_gvalue);

      result = Val_GtkShortcutType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_shortcuts_shortcut_set_shortcut_type(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkShortcutsShortcut *obj = (GtkShortcutsShortcut *)GtkShortcutsShortcut_val(self);
    GtkShortcutType c_value = GtkShortcutType_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "shortcut-type");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_shortcut_set_shortcut_type: property 'shortcut-type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "shortcut-type", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcuts_shortcut_get_subtitle(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkShortcutsShortcut *obj = (GtkShortcutsShortcut *)GtkShortcutsShortcut_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "subtitle");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_shortcut_get_subtitle: property 'subtitle' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "subtitle", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_shortcuts_shortcut_set_subtitle(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkShortcutsShortcut *obj = (GtkShortcutsShortcut *)GtkShortcutsShortcut_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "subtitle");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_shortcut_set_subtitle: property 'subtitle' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "subtitle", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcuts_shortcut_get_subtitle_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkShortcutsShortcut *obj = (GtkShortcutsShortcut *)GtkShortcutsShortcut_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "subtitle-set");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_shortcut_get_subtitle_set: property 'subtitle-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "subtitle-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_shortcuts_shortcut_set_subtitle_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkShortcutsShortcut *obj = (GtkShortcutsShortcut *)GtkShortcutsShortcut_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "subtitle-set");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_shortcut_set_subtitle_set: property 'subtitle-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "subtitle-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcuts_shortcut_get_title(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkShortcutsShortcut *obj = (GtkShortcutsShortcut *)GtkShortcutsShortcut_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "title");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_shortcut_get_title: property 'title' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "title", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_shortcuts_shortcut_set_title(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkShortcutsShortcut *obj = (GtkShortcutsShortcut *)GtkShortcutsShortcut_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "title");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_shortcut_set_title: property 'title' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "title", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcuts_shortcut_set_title_size_group(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkShortcutsShortcut *obj = (GtkShortcutsShortcut *)GtkShortcutsShortcut_val(self);
    GtkSizeGroup *c_value = GtkSizeGroup_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "title-size-group");
if (pspec == NULL) caml_failwith("ml_gtk_shortcuts_shortcut_set_title_size_group: property 'title-size-group' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_object(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "title-size-group", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_shortcuts_shortcut_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_shortcuts_shortcut_get_type()));
}
