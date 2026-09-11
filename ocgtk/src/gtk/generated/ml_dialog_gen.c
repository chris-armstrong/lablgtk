/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Dialog */

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


CAMLexport CAMLprim value ml_gtk_dialog_new(value unit)
{
CAMLparam1(unit);

GtkDialog *obj = gtk_dialog_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkDialog(obj));
}
CAMLexport CAMLprim value ml_gtk_dialog_set_response_sensitive(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_dialog_set_response_sensitive(GtkDialog_val(self), Int_val(arg1), Bool_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_dialog_set_default_response(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_dialog_set_default_response(GtkDialog_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_dialog_response(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_dialog_response(GtkDialog_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_dialog_get_widget_for_response(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkWidget* result = gtk_dialog_get_widget_for_response(GtkDialog_val(self), Int_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_dialog_get_response_for_widget(value self, value arg1)
{
CAMLparam2(self, arg1);

int result = gtk_dialog_get_response_for_widget(GtkDialog_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_dialog_get_header_bar(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_dialog_get_header_bar(GtkDialog_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkHeaderBar(result));
}

CAMLexport CAMLprim value ml_gtk_dialog_get_content_area(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_dialog_get_content_area(GtkDialog_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkBox(result));
}

CAMLexport CAMLprim value ml_gtk_dialog_add_button(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

GtkWidget* result = gtk_dialog_add_button(GtkDialog_val(self), String_val(arg1), Int_val(arg2));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkWidget(result));
}

CAMLexport CAMLprim value ml_gtk_dialog_add_action_widget(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_dialog_add_action_widget(GtkDialog_val(self), GtkWidget_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_dialog_get_use_header_bar(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkDialog *obj = (GtkDialog *)GtkDialog_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "use-header-bar");
if (pspec == NULL) caml_failwith("ml_gtk_dialog_get_use_header_bar: property 'use-header-bar' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "use-header-bar", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}


CAMLprim value ml_gtk_dialog_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_dialog_get_type()));
}
