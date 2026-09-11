/* GENERATED CODE - DO NOT EDIT */
/* C bindings for AppChooserButton */

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


CAMLexport CAMLprim value ml_gtk_app_chooser_button_new(value arg1)
{
CAMLparam1(arg1);

GtkAppChooserButton *obj = gtk_app_chooser_button_new(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkAppChooserButton(obj));
}
CAMLexport CAMLprim value ml_gtk_app_chooser_button_set_show_dialog_item(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_app_chooser_button_set_show_dialog_item(GtkAppChooserButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_app_chooser_button_set_show_default_item(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_app_chooser_button_set_show_default_item(GtkAppChooserButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_app_chooser_button_set_modal(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_app_chooser_button_set_modal(GtkAppChooserButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_app_chooser_button_set_heading(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_app_chooser_button_set_heading(GtkAppChooserButton_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_app_chooser_button_set_active_custom_item(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_app_chooser_button_set_active_custom_item(GtkAppChooserButton_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_app_chooser_button_get_show_dialog_item(value self)
{
CAMLparam1(self);

gboolean result = gtk_app_chooser_button_get_show_dialog_item(GtkAppChooserButton_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_app_chooser_button_get_show_default_item(value self)
{
CAMLparam1(self);

gboolean result = gtk_app_chooser_button_get_show_default_item(GtkAppChooserButton_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_app_chooser_button_get_modal(value self)
{
CAMLparam1(self);

gboolean result = gtk_app_chooser_button_get_modal(GtkAppChooserButton_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_app_chooser_button_get_heading(value self)
{
CAMLparam1(self);

const char* result = gtk_app_chooser_button_get_heading(GtkAppChooserButton_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_app_chooser_button_append_separator(value self)
{
CAMLparam1(self);

gtk_app_chooser_button_append_separator(GtkAppChooserButton_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_app_chooser_button_append_custom_item(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_app_chooser_button_append_custom_item(GtkAppChooserButton_val(self), String_val(arg1), String_val(arg2), GIcon_val(arg3));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_app_chooser_button_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_app_chooser_button_get_type()));
}
