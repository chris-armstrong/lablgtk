/* GENERATED CODE - DO NOT EDIT */
/* C bindings for LockButton */

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


CAMLexport CAMLprim value ml_gtk_lock_button_new(value arg1)
{
CAMLparam1(arg1);

GtkLockButton *obj = gtk_lock_button_new(Option_val(arg1, GPermission_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkLockButton(obj));
}
CAMLexport CAMLprim value ml_gtk_lock_button_set_permission(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_lock_button_set_permission(GtkLockButton_val(self), Option_val(arg1, GPermission_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_lock_button_get_permission(value self)
{
CAMLparam1(self);

GPermission* result = gtk_lock_button_get_permission(GtkLockButton_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GPermission));
}

CAMLexport CAMLprim value ml_gtk_lock_button_get_text_lock(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkLockButton *obj = (GtkLockButton *)GtkLockButton_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "text-lock");
if (pspec == NULL) caml_failwith("ml_gtk_lock_button_get_text_lock: property 'text-lock' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "text-lock", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_lock_button_set_text_lock(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkLockButton *obj = (GtkLockButton *)GtkLockButton_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "text-lock");
if (pspec == NULL) caml_failwith("ml_gtk_lock_button_set_text_lock: property 'text-lock' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "text-lock", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_lock_button_get_text_unlock(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkLockButton *obj = (GtkLockButton *)GtkLockButton_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "text-unlock");
if (pspec == NULL) caml_failwith("ml_gtk_lock_button_get_text_unlock: property 'text-unlock' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "text-unlock", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_lock_button_set_text_unlock(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkLockButton *obj = (GtkLockButton *)GtkLockButton_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "text-unlock");
if (pspec == NULL) caml_failwith("ml_gtk_lock_button_set_text_unlock: property 'text-unlock' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "text-unlock", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_lock_button_get_tooltip_lock(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkLockButton *obj = (GtkLockButton *)GtkLockButton_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "tooltip-lock");
if (pspec == NULL) caml_failwith("ml_gtk_lock_button_get_tooltip_lock: property 'tooltip-lock' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "tooltip-lock", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_lock_button_set_tooltip_lock(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkLockButton *obj = (GtkLockButton *)GtkLockButton_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "tooltip-lock");
if (pspec == NULL) caml_failwith("ml_gtk_lock_button_set_tooltip_lock: property 'tooltip-lock' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "tooltip-lock", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_lock_button_get_tooltip_not_authorized(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkLockButton *obj = (GtkLockButton *)GtkLockButton_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "tooltip-not-authorized");
if (pspec == NULL) caml_failwith("ml_gtk_lock_button_get_tooltip_not_authorized: property 'tooltip-not-authorized' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "tooltip-not-authorized", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_lock_button_set_tooltip_not_authorized(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkLockButton *obj = (GtkLockButton *)GtkLockButton_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "tooltip-not-authorized");
if (pspec == NULL) caml_failwith("ml_gtk_lock_button_set_tooltip_not_authorized: property 'tooltip-not-authorized' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "tooltip-not-authorized", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_lock_button_get_tooltip_unlock(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkLockButton *obj = (GtkLockButton *)GtkLockButton_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "tooltip-unlock");
if (pspec == NULL) caml_failwith("ml_gtk_lock_button_get_tooltip_unlock: property 'tooltip-unlock' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "tooltip-unlock", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_lock_button_set_tooltip_unlock(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkLockButton *obj = (GtkLockButton *)GtkLockButton_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "tooltip-unlock");
if (pspec == NULL) caml_failwith("ml_gtk_lock_button_set_tooltip_unlock: property 'tooltip-unlock' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "tooltip-unlock", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_lock_button_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_lock_button_get_type()));
}
