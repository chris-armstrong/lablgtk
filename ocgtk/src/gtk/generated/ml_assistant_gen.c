/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Assistant */

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


CAMLexport CAMLprim value ml_gtk_assistant_new(value unit)
{
CAMLparam1(unit);

GtkAssistant *obj = gtk_assistant_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkAssistant(obj));
}
CAMLexport CAMLprim value ml_gtk_assistant_update_buttons_state(value self)
{
CAMLparam1(self);

gtk_assistant_update_buttons_state(GtkAssistant_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_assistant_set_page_type(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_assistant_set_page_type(GtkAssistant_val(self), GtkWidget_val(arg1), GtkAssistantPageType_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_assistant_set_page_title(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_assistant_set_page_title(GtkAssistant_val(self), GtkWidget_val(arg1), String_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_assistant_set_page_complete(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_assistant_set_page_complete(GtkAssistant_val(self), GtkWidget_val(arg1), Bool_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_assistant_set_current_page(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_assistant_set_current_page(GtkAssistant_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_assistant_remove_page(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_assistant_remove_page(GtkAssistant_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_assistant_remove_action_widget(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_assistant_remove_action_widget(GtkAssistant_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_assistant_previous_page(value self)
{
CAMLparam1(self);

gtk_assistant_previous_page(GtkAssistant_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_assistant_prepend_page(value self, value arg1)
{
CAMLparam2(self, arg1);

int result = gtk_assistant_prepend_page(GtkAssistant_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_assistant_next_page(value self)
{
CAMLparam1(self);

gtk_assistant_next_page(GtkAssistant_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_assistant_insert_page(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

int result = gtk_assistant_insert_page(GtkAssistant_val(self), GtkWidget_val(arg1), Int_val(arg2));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_assistant_get_pages(value self)
{
CAMLparam1(self);

GListModel* result = gtk_assistant_get_pages(GtkAssistant_val(self));
CAMLreturn(Val_GListModel(result));
}

CAMLexport CAMLprim value ml_gtk_assistant_get_page_type(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkAssistantPageType result = gtk_assistant_get_page_type(GtkAssistant_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_GtkAssistantPageType(result));
}

CAMLexport CAMLprim value ml_gtk_assistant_get_page_title(value self, value arg1)
{
CAMLparam2(self, arg1);

const char* result = gtk_assistant_get_page_title(GtkAssistant_val(self), GtkWidget_val(arg1));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_assistant_get_page_complete(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_assistant_get_page_complete(GtkAssistant_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_assistant_get_page(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkAssistantPage* result = gtk_assistant_get_page(GtkAssistant_val(self), GtkWidget_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkAssistantPage(result));
}

CAMLexport CAMLprim value ml_gtk_assistant_get_nth_page(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkWidget* result = gtk_assistant_get_nth_page(GtkAssistant_val(self), Int_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_assistant_get_n_pages(value self)
{
CAMLparam1(self);

int result = gtk_assistant_get_n_pages(GtkAssistant_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_assistant_get_current_page(value self)
{
CAMLparam1(self);

int result = gtk_assistant_get_current_page(GtkAssistant_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_assistant_commit(value self)
{
CAMLparam1(self);

gtk_assistant_commit(GtkAssistant_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_assistant_append_page(value self, value arg1)
{
CAMLparam2(self, arg1);

int result = gtk_assistant_append_page(GtkAssistant_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_assistant_add_action_widget(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_assistant_add_action_widget(GtkAssistant_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_assistant_get_use_header_bar(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkAssistant *obj = (GtkAssistant *)GtkAssistant_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "use-header-bar");
if (pspec == NULL) caml_failwith("ml_gtk_assistant_get_use_header_bar: property 'use-header-bar' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "use-header-bar", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}


CAMLprim value ml_gtk_assistant_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_assistant_get_type()));
}
