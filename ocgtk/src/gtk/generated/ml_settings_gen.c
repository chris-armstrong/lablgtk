/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Settings */

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


CAMLexport CAMLprim value ml_gtk_settings_reset_property(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_settings_reset_property(GtkSettings_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_alternative_button_order(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-alternative-button-order");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_alternative_button_order: property 'gtk-alternative-button-order' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-alternative-button-order", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_alternative_button_order(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-alternative-button-order");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_alternative_button_order: property 'gtk-alternative-button-order' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-alternative-button-order", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_alternative_sort_arrows(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-alternative-sort-arrows");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_alternative_sort_arrows: property 'gtk-alternative-sort-arrows' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-alternative-sort-arrows", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_alternative_sort_arrows(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-alternative-sort-arrows");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_alternative_sort_arrows: property 'gtk-alternative-sort-arrows' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-alternative-sort-arrows", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_application_prefer_dark_theme(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-application-prefer-dark-theme");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_application_prefer_dark_theme: property 'gtk-application-prefer-dark-theme' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-application-prefer-dark-theme", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_application_prefer_dark_theme(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-application-prefer-dark-theme");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_application_prefer_dark_theme: property 'gtk-application-prefer-dark-theme' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-application-prefer-dark-theme", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_cursor_aspect_ratio(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gdouble prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-cursor-aspect-ratio");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_cursor_aspect_ratio: property 'gtk-cursor-aspect-ratio' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-cursor-aspect-ratio", &prop_gvalue);
          prop_value = g_value_get_double(&prop_gvalue);

      result = caml_copy_double(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_cursor_aspect_ratio(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gdouble c_value = Double_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-cursor-aspect-ratio");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_cursor_aspect_ratio: property 'gtk-cursor-aspect-ratio' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_double(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-cursor-aspect-ratio", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_cursor_blink(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-cursor-blink");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_cursor_blink: property 'gtk-cursor-blink' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-cursor-blink", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_cursor_blink(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-cursor-blink");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_cursor_blink: property 'gtk-cursor-blink' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-cursor-blink", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_cursor_blink_time(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-cursor-blink-time");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_cursor_blink_time: property 'gtk-cursor-blink-time' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-cursor-blink-time", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_cursor_blink_time(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-cursor-blink-time");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_cursor_blink_time: property 'gtk-cursor-blink-time' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-cursor-blink-time", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_cursor_blink_timeout(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-cursor-blink-timeout");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_cursor_blink_timeout: property 'gtk-cursor-blink-timeout' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-cursor-blink-timeout", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_cursor_blink_timeout(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-cursor-blink-timeout");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_cursor_blink_timeout: property 'gtk-cursor-blink-timeout' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-cursor-blink-timeout", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_cursor_theme_name(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-cursor-theme-name");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_cursor_theme_name: property 'gtk-cursor-theme-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-cursor-theme-name", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_cursor_theme_name(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-cursor-theme-name");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_cursor_theme_name: property 'gtk-cursor-theme-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-cursor-theme-name", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_cursor_theme_size(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-cursor-theme-size");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_cursor_theme_size: property 'gtk-cursor-theme-size' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-cursor-theme-size", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_cursor_theme_size(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-cursor-theme-size");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_cursor_theme_size: property 'gtk-cursor-theme-size' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-cursor-theme-size", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_decoration_layout(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-decoration-layout");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_decoration_layout: property 'gtk-decoration-layout' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-decoration-layout", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_decoration_layout(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-decoration-layout");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_decoration_layout: property 'gtk-decoration-layout' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-decoration-layout", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_dialogs_use_header(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-dialogs-use-header");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_dialogs_use_header: property 'gtk-dialogs-use-header' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-dialogs-use-header", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_dialogs_use_header(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-dialogs-use-header");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_dialogs_use_header: property 'gtk-dialogs-use-header' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-dialogs-use-header", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_dnd_drag_threshold(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-dnd-drag-threshold");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_dnd_drag_threshold: property 'gtk-dnd-drag-threshold' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-dnd-drag-threshold", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_dnd_drag_threshold(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-dnd-drag-threshold");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_dnd_drag_threshold: property 'gtk-dnd-drag-threshold' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-dnd-drag-threshold", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_double_click_distance(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-double-click-distance");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_double_click_distance: property 'gtk-double-click-distance' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-double-click-distance", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_double_click_distance(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-double-click-distance");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_double_click_distance: property 'gtk-double-click-distance' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-double-click-distance", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_double_click_time(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-double-click-time");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_double_click_time: property 'gtk-double-click-time' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-double-click-time", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_double_click_time(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-double-click-time");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_double_click_time: property 'gtk-double-click-time' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-double-click-time", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_enable_accels(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-enable-accels");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_enable_accels: property 'gtk-enable-accels' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-enable-accels", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_enable_accels(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-enable-accels");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_enable_accels: property 'gtk-enable-accels' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-enable-accels", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_enable_animations(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-enable-animations");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_enable_animations: property 'gtk-enable-animations' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-enable-animations", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_enable_animations(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-enable-animations");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_enable_animations: property 'gtk-enable-animations' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-enable-animations", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_enable_event_sounds(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-enable-event-sounds");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_enable_event_sounds: property 'gtk-enable-event-sounds' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-enable-event-sounds", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_enable_event_sounds(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-enable-event-sounds");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_enable_event_sounds: property 'gtk-enable-event-sounds' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-enable-event-sounds", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_enable_input_feedback_sounds(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-enable-input-feedback-sounds");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_enable_input_feedback_sounds: property 'gtk-enable-input-feedback-sounds' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-enable-input-feedback-sounds", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_enable_input_feedback_sounds(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-enable-input-feedback-sounds");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_enable_input_feedback_sounds: property 'gtk-enable-input-feedback-sounds' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-enable-input-feedback-sounds", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_enable_primary_paste(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-enable-primary-paste");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_enable_primary_paste: property 'gtk-enable-primary-paste' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-enable-primary-paste", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_enable_primary_paste(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-enable-primary-paste");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_enable_primary_paste: property 'gtk-enable-primary-paste' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-enable-primary-paste", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_entry_password_hint_timeout(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-entry-password-hint-timeout");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_entry_password_hint_timeout: property 'gtk-entry-password-hint-timeout' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-entry-password-hint-timeout", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_entry_password_hint_timeout(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    guint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-entry-password-hint-timeout");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_entry_password_hint_timeout: property 'gtk-entry-password-hint-timeout' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_uint(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-entry-password-hint-timeout", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_entry_select_on_focus(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-entry-select-on-focus");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_entry_select_on_focus: property 'gtk-entry-select-on-focus' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-entry-select-on-focus", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_entry_select_on_focus(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-entry-select-on-focus");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_entry_select_on_focus: property 'gtk-entry-select-on-focus' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-entry-select-on-focus", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_error_bell(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-error-bell");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_error_bell: property 'gtk-error-bell' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-error-bell", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_error_bell(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-error-bell");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_error_bell: property 'gtk-error-bell' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-error-bell", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_font_name(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-font-name");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_font_name: property 'gtk-font-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-font-name", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_font_name(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-font-name");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_font_name: property 'gtk-font-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-font-name", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,16,0)

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_font_rendering(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    GtkFontRendering prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-font-rendering");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_font_rendering: property 'gtk-font-rendering' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-font-rendering", &prop_gvalue);
          prop_value = (GtkFontRendering)g_value_get_enum(&prop_gvalue);

      result = Val_GtkFontRendering(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_font_rendering(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Settings requires GTK >= 4.16");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,16,0)

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_font_rendering(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    GtkFontRendering c_value = GtkFontRendering_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-font-rendering");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_font_rendering: property 'gtk-font-rendering' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-font-rendering", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_font_rendering(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GTK >= 4.16");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_fontconfig_timestamp(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-fontconfig-timestamp");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_fontconfig_timestamp: property 'gtk-fontconfig-timestamp' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-fontconfig-timestamp", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_fontconfig_timestamp(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    guint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-fontconfig-timestamp");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_fontconfig_timestamp: property 'gtk-fontconfig-timestamp' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_uint(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-fontconfig-timestamp", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_hint_font_metrics(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-hint-font-metrics");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_hint_font_metrics: property 'gtk-hint-font-metrics' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-hint-font-metrics", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_hint_font_metrics(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Settings requires GTK >= 4.6");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_hint_font_metrics(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-hint-font-metrics");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_hint_font_metrics: property 'gtk-hint-font-metrics' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-hint-font-metrics", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_hint_font_metrics(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GTK >= 4.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_icon_theme_name(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-icon-theme-name");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_icon_theme_name: property 'gtk-icon-theme-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-icon-theme-name", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_icon_theme_name(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-icon-theme-name");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_icon_theme_name: property 'gtk-icon-theme-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-icon-theme-name", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_im_module(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-im-module");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_im_module: property 'gtk-im-module' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-im-module", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_im_module(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-im-module");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_im_module: property 'gtk-im-module' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-im-module", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_interface_color_scheme(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    GtkInterfaceColorScheme prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-interface-color-scheme");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_interface_color_scheme: property 'gtk-interface-color-scheme' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-interface-color-scheme", &prop_gvalue);
          prop_value = (GtkInterfaceColorScheme)g_value_get_enum(&prop_gvalue);

      result = Val_GtkInterfaceColorScheme(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_interface_color_scheme(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Settings requires GTK >= 4.20");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_interface_color_scheme(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    GtkInterfaceColorScheme c_value = GtkInterfaceColorScheme_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-interface-color-scheme");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_interface_color_scheme: property 'gtk-interface-color-scheme' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-interface-color-scheme", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_interface_color_scheme(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GTK >= 4.20");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_interface_contrast(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    GtkInterfaceContrast prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-interface-contrast");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_interface_contrast: property 'gtk-interface-contrast' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-interface-contrast", &prop_gvalue);
          prop_value = (GtkInterfaceContrast)g_value_get_enum(&prop_gvalue);

      result = Val_GtkInterfaceContrast(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_interface_contrast(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Settings requires GTK >= 4.20");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_interface_contrast(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    GtkInterfaceContrast c_value = GtkInterfaceContrast_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-interface-contrast");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_interface_contrast: property 'gtk-interface-contrast' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-interface-contrast", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_interface_contrast(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GTK >= 4.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_keynav_use_caret(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-keynav-use-caret");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_keynav_use_caret: property 'gtk-keynav-use-caret' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-keynav-use-caret", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_keynav_use_caret(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-keynav-use-caret");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_keynav_use_caret: property 'gtk-keynav-use-caret' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-keynav-use-caret", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_label_select_on_focus(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-label-select-on-focus");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_label_select_on_focus: property 'gtk-label-select-on-focus' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-label-select-on-focus", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_label_select_on_focus(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-label-select-on-focus");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_label_select_on_focus: property 'gtk-label-select-on-focus' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-label-select-on-focus", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_long_press_time(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-long-press-time");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_long_press_time: property 'gtk-long-press-time' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-long-press-time", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_long_press_time(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    guint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-long-press-time");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_long_press_time: property 'gtk-long-press-time' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_uint(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-long-press-time", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_overlay_scrolling(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-overlay-scrolling");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_overlay_scrolling: property 'gtk-overlay-scrolling' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-overlay-scrolling", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_overlay_scrolling(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-overlay-scrolling");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_overlay_scrolling: property 'gtk-overlay-scrolling' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-overlay-scrolling", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_primary_button_warps_slider(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-primary-button-warps-slider");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_primary_button_warps_slider: property 'gtk-primary-button-warps-slider' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-primary-button-warps-slider", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_primary_button_warps_slider(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-primary-button-warps-slider");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_primary_button_warps_slider: property 'gtk-primary-button-warps-slider' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-primary-button-warps-slider", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_print_backends(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-print-backends");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_print_backends: property 'gtk-print-backends' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-print-backends", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_print_backends(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-print-backends");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_print_backends: property 'gtk-print-backends' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-print-backends", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_print_preview_command(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-print-preview-command");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_print_preview_command: property 'gtk-print-preview-command' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-print-preview-command", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_print_preview_command(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-print-preview-command");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_print_preview_command: property 'gtk-print-preview-command' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-print-preview-command", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_recent_files_enabled(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-recent-files-enabled");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_recent_files_enabled: property 'gtk-recent-files-enabled' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-recent-files-enabled", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_recent_files_enabled(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-recent-files-enabled");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_recent_files_enabled: property 'gtk-recent-files-enabled' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-recent-files-enabled", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_recent_files_max_age(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-recent-files-max-age");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_recent_files_max_age: property 'gtk-recent-files-max-age' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-recent-files-max-age", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_recent_files_max_age(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-recent-files-max-age");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_recent_files_max_age: property 'gtk-recent-files-max-age' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-recent-files-max-age", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_shell_shows_app_menu(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-shell-shows-app-menu");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_shell_shows_app_menu: property 'gtk-shell-shows-app-menu' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-shell-shows-app-menu", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_shell_shows_app_menu(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-shell-shows-app-menu");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_shell_shows_app_menu: property 'gtk-shell-shows-app-menu' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-shell-shows-app-menu", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_shell_shows_desktop(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-shell-shows-desktop");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_shell_shows_desktop: property 'gtk-shell-shows-desktop' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-shell-shows-desktop", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_shell_shows_desktop(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-shell-shows-desktop");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_shell_shows_desktop: property 'gtk-shell-shows-desktop' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-shell-shows-desktop", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_shell_shows_menubar(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-shell-shows-menubar");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_shell_shows_menubar: property 'gtk-shell-shows-menubar' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-shell-shows-menubar", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_shell_shows_menubar(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-shell-shows-menubar");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_shell_shows_menubar: property 'gtk-shell-shows-menubar' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-shell-shows-menubar", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_show_status_shapes(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-show-status-shapes");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_show_status_shapes: property 'gtk-show-status-shapes' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-show-status-shapes", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_show_status_shapes(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Settings requires GTK >= 4.14");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_show_status_shapes(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-show-status-shapes");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_show_status_shapes: property 'gtk-show-status-shapes' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-show-status-shapes", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_show_status_shapes(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_sound_theme_name(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-sound-theme-name");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_sound_theme_name: property 'gtk-sound-theme-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-sound-theme-name", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_sound_theme_name(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-sound-theme-name");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_sound_theme_name: property 'gtk-sound-theme-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-sound-theme-name", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_split_cursor(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-split-cursor");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_split_cursor: property 'gtk-split-cursor' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-split-cursor", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_split_cursor(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-split-cursor");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_split_cursor: property 'gtk-split-cursor' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-split-cursor", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_theme_name(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-theme-name");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_theme_name: property 'gtk-theme-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-theme-name", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_theme_name(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-theme-name");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_theme_name: property 'gtk-theme-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-theme-name", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_titlebar_double_click(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-titlebar-double-click");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_titlebar_double_click: property 'gtk-titlebar-double-click' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-titlebar-double-click", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_titlebar_double_click(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-titlebar-double-click");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_titlebar_double_click: property 'gtk-titlebar-double-click' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-titlebar-double-click", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_titlebar_middle_click(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-titlebar-middle-click");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_titlebar_middle_click: property 'gtk-titlebar-middle-click' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-titlebar-middle-click", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_titlebar_middle_click(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-titlebar-middle-click");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_titlebar_middle_click: property 'gtk-titlebar-middle-click' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-titlebar-middle-click", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_titlebar_right_click(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-titlebar-right-click");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_titlebar_right_click: property 'gtk-titlebar-right-click' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-titlebar-right-click", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_titlebar_right_click(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-titlebar-right-click");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_titlebar_right_click: property 'gtk-titlebar-right-click' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-titlebar-right-click", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_xft_antialias(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-xft-antialias");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_xft_antialias: property 'gtk-xft-antialias' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-xft-antialias", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_xft_antialias(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-xft-antialias");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_xft_antialias: property 'gtk-xft-antialias' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-xft-antialias", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_xft_dpi(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-xft-dpi");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_xft_dpi: property 'gtk-xft-dpi' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-xft-dpi", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_xft_dpi(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-xft-dpi");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_xft_dpi: property 'gtk-xft-dpi' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-xft-dpi", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_xft_hinting(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-xft-hinting");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_xft_hinting: property 'gtk-xft-hinting' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-xft-hinting", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_xft_hinting(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-xft-hinting");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_xft_hinting: property 'gtk-xft-hinting' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-xft-hinting", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_xft_hintstyle(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-xft-hintstyle");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_xft_hintstyle: property 'gtk-xft-hintstyle' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-xft-hintstyle", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_xft_hintstyle(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-xft-hintstyle");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_xft_hintstyle: property 'gtk-xft-hintstyle' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-xft-hintstyle", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_settings_get_gtk_xft_rgba(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-xft-rgba");
if (pspec == NULL) caml_failwith("ml_gtk_settings_get_gtk_xft_rgba: property 'gtk-xft-rgba' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gtk-xft-rgba", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_settings_set_gtk_xft_rgba(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSettings *obj = (GtkSettings *)GtkSettings_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gtk-xft-rgba");
if (pspec == NULL) caml_failwith("ml_gtk_settings_set_gtk_xft_rgba: property 'gtk-xft-rgba' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "gtk-xft-rgba", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

GType gtk_settings_get_type (void);


CAMLprim value ml_gtk_settings_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_settings_get_type()));
}
