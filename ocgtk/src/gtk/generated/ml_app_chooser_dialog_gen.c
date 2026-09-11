/* GENERATED CODE - DO NOT EDIT */
/* C bindings for AppChooserDialog */

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


CAMLexport CAMLprim value ml_gtk_app_chooser_dialog_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GtkAppChooserDialog *obj = gtk_app_chooser_dialog_new(Option_val(arg1, GtkWindow_val, NULL), GtkDialogFlags_val(arg2), GFile_val(arg3));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkAppChooserDialog(obj));
}
CAMLexport CAMLprim value ml_gtk_app_chooser_dialog_new_for_content_type(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GtkAppChooserDialog *obj = gtk_app_chooser_dialog_new_for_content_type(Option_val(arg1, GtkWindow_val, NULL), GtkDialogFlags_val(arg2), String_val(arg3));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkAppChooserDialog(obj));
}
CAMLexport CAMLprim value ml_gtk_app_chooser_dialog_set_heading(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_app_chooser_dialog_set_heading(GtkAppChooserDialog_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_app_chooser_dialog_get_widget(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_app_chooser_dialog_get_widget(GtkAppChooserDialog_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkWidget(result));
}

CAMLexport CAMLprim value ml_gtk_app_chooser_dialog_get_heading(value self)
{
CAMLparam1(self);

const char* result = gtk_app_chooser_dialog_get_heading(GtkAppChooserDialog_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_app_chooser_dialog_get_gfile(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkAppChooserDialog *obj = (GtkAppChooserDialog *)GtkAppChooserDialog_val(self);
    GFile *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gfile");
if (pspec == NULL) caml_failwith("ml_gtk_app_chooser_dialog_get_gfile: property 'gfile' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gfile", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GFile(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}


CAMLprim value ml_gtk_app_chooser_dialog_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_app_chooser_dialog_get_type()));
}
