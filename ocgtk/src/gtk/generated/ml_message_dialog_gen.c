/* GENERATED CODE - DO NOT EDIT */
/* C bindings for MessageDialog */

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


CAMLexport CAMLprim value ml_gtk_message_dialog_set_markup(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_message_dialog_set_markup(GtkMessageDialog_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_message_dialog_get_message_area(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_message_dialog_get_message_area(GtkMessageDialog_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkWidget(result));
}

CAMLexport CAMLprim value ml_gtk_message_dialog_get_message_type(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkMessageDialog *obj = (GtkMessageDialog *)GtkMessageDialog_val(self);
    GtkMessageType prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "message-type");
if (pspec == NULL) caml_failwith("ml_gtk_message_dialog_get_message_type: property 'message-type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "message-type", &prop_gvalue);
          prop_value = (GtkMessageType)g_value_get_enum(&prop_gvalue);

      result = Val_GtkMessageType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_message_dialog_set_message_type(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkMessageDialog *obj = (GtkMessageDialog *)GtkMessageDialog_val(self);
    GtkMessageType c_value = GtkMessageType_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "message-type");
if (pspec == NULL) caml_failwith("ml_gtk_message_dialog_set_message_type: property 'message-type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "message-type", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_message_dialog_get_secondary_text(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkMessageDialog *obj = (GtkMessageDialog *)GtkMessageDialog_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "secondary-text");
if (pspec == NULL) caml_failwith("ml_gtk_message_dialog_get_secondary_text: property 'secondary-text' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "secondary-text", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_message_dialog_set_secondary_text(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkMessageDialog *obj = (GtkMessageDialog *)GtkMessageDialog_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "secondary-text");
if (pspec == NULL) caml_failwith("ml_gtk_message_dialog_set_secondary_text: property 'secondary-text' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "secondary-text", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_message_dialog_get_secondary_use_markup(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkMessageDialog *obj = (GtkMessageDialog *)GtkMessageDialog_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "secondary-use-markup");
if (pspec == NULL) caml_failwith("ml_gtk_message_dialog_get_secondary_use_markup: property 'secondary-use-markup' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "secondary-use-markup", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_message_dialog_set_secondary_use_markup(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkMessageDialog *obj = (GtkMessageDialog *)GtkMessageDialog_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "secondary-use-markup");
if (pspec == NULL) caml_failwith("ml_gtk_message_dialog_set_secondary_use_markup: property 'secondary-use-markup' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "secondary-use-markup", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_message_dialog_get_text(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkMessageDialog *obj = (GtkMessageDialog *)GtkMessageDialog_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "text");
if (pspec == NULL) caml_failwith("ml_gtk_message_dialog_get_text: property 'text' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "text", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_message_dialog_set_text(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkMessageDialog *obj = (GtkMessageDialog *)GtkMessageDialog_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "text");
if (pspec == NULL) caml_failwith("ml_gtk_message_dialog_set_text: property 'text' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "text", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_message_dialog_get_use_markup(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkMessageDialog *obj = (GtkMessageDialog *)GtkMessageDialog_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "use-markup");
if (pspec == NULL) caml_failwith("ml_gtk_message_dialog_get_use_markup: property 'use-markup' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "use-markup", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_message_dialog_set_use_markup(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkMessageDialog *obj = (GtkMessageDialog *)GtkMessageDialog_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "use-markup");
if (pspec == NULL) caml_failwith("ml_gtk_message_dialog_set_use_markup: property 'use-markup' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "use-markup", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

GType gtk_message_dialog_get_type (void);


CAMLprim value ml_gtk_message_dialog_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_message_dialog_get_type()));
}
