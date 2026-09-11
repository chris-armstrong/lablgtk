/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PasswordEntry */

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


CAMLexport CAMLprim value ml_gtk_password_entry_new(value unit)
{
CAMLparam1(unit);

GtkPasswordEntry *obj = gtk_password_entry_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkPasswordEntry(obj));
}
CAMLexport CAMLprim value ml_gtk_password_entry_set_show_peek_icon(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_password_entry_set_show_peek_icon(GtkPasswordEntry_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_password_entry_set_extra_menu(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_password_entry_set_extra_menu(GtkPasswordEntry_val(self), Option_val(arg1, GMenuModel_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_password_entry_get_show_peek_icon(value self)
{
CAMLparam1(self);

gboolean result = gtk_password_entry_get_show_peek_icon(GtkPasswordEntry_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_password_entry_get_extra_menu(value self)
{
CAMLparam1(self);

GMenuModel* result = gtk_password_entry_get_extra_menu(GtkPasswordEntry_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GMenuModel));
}

CAMLexport CAMLprim value ml_gtk_password_entry_get_activates_default(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkPasswordEntry *obj = (GtkPasswordEntry *)GtkPasswordEntry_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "activates-default");
if (pspec == NULL) caml_failwith("ml_gtk_password_entry_get_activates_default: property 'activates-default' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "activates-default", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_password_entry_set_activates_default(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkPasswordEntry *obj = (GtkPasswordEntry *)GtkPasswordEntry_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "activates-default");
if (pspec == NULL) caml_failwith("ml_gtk_password_entry_set_activates_default: property 'activates-default' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "activates-default", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_password_entry_get_placeholder_text(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkPasswordEntry *obj = (GtkPasswordEntry *)GtkPasswordEntry_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "placeholder-text");
if (pspec == NULL) caml_failwith("ml_gtk_password_entry_get_placeholder_text: property 'placeholder-text' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "placeholder-text", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_password_entry_set_placeholder_text(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkPasswordEntry *obj = (GtkPasswordEntry *)GtkPasswordEntry_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "placeholder-text");
if (pspec == NULL) caml_failwith("ml_gtk_password_entry_set_placeholder_text: property 'placeholder-text' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "placeholder-text", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

GType gtk_password_entry_get_type (void);


CAMLprim value ml_gtk_password_entry_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_password_entry_get_type()));
}
