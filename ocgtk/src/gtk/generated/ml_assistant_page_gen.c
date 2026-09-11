/* GENERATED CODE - DO NOT EDIT */
/* C bindings for AssistantPage */

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


CAMLexport CAMLprim value ml_gtk_assistant_page_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_assistant_page_get_child(GtkAssistantPage_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkWidget(result));
}

CAMLexport CAMLprim value ml_gtk_assistant_page_get_complete(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkAssistantPage *obj = (GtkAssistantPage *)GtkAssistantPage_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "complete");
if (pspec == NULL) caml_failwith("ml_gtk_assistant_page_get_complete: property 'complete' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "complete", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_assistant_page_set_complete(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkAssistantPage *obj = (GtkAssistantPage *)GtkAssistantPage_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "complete");
if (pspec == NULL) caml_failwith("ml_gtk_assistant_page_set_complete: property 'complete' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "complete", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_assistant_page_get_page_type(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkAssistantPage *obj = (GtkAssistantPage *)GtkAssistantPage_val(self);
    GtkAssistantPageType prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "page-type");
if (pspec == NULL) caml_failwith("ml_gtk_assistant_page_get_page_type: property 'page-type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "page-type", &prop_gvalue);
          prop_value = (GtkAssistantPageType)g_value_get_enum(&prop_gvalue);

      result = Val_GtkAssistantPageType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_assistant_page_set_page_type(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkAssistantPage *obj = (GtkAssistantPage *)GtkAssistantPage_val(self);
    GtkAssistantPageType c_value = GtkAssistantPageType_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "page-type");
if (pspec == NULL) caml_failwith("ml_gtk_assistant_page_set_page_type: property 'page-type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "page-type", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_assistant_page_get_title(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkAssistantPage *obj = (GtkAssistantPage *)GtkAssistantPage_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "title");
if (pspec == NULL) caml_failwith("ml_gtk_assistant_page_get_title: property 'title' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "title", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_assistant_page_set_title(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkAssistantPage *obj = (GtkAssistantPage *)GtkAssistantPage_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "title");
if (pspec == NULL) caml_failwith("ml_gtk_assistant_page_set_title: property 'title' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "title", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

GType gtk_assistant_page_get_type (void);


CAMLprim value ml_gtk_assistant_page_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_assistant_page_get_type()));
}
