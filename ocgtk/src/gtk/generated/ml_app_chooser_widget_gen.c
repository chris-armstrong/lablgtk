/* GENERATED CODE - DO NOT EDIT */
/* C bindings for AppChooserWidget */

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


CAMLexport CAMLprim value ml_gtk_app_chooser_widget_new(value arg1)
{
CAMLparam1(arg1);

GtkAppChooserWidget *obj = gtk_app_chooser_widget_new(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkAppChooserWidget(obj));
}
CAMLexport CAMLprim value ml_gtk_app_chooser_widget_set_show_recommended(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_app_chooser_widget_set_show_recommended(GtkAppChooserWidget_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_app_chooser_widget_set_show_other(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_app_chooser_widget_set_show_other(GtkAppChooserWidget_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_app_chooser_widget_set_show_fallback(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_app_chooser_widget_set_show_fallback(GtkAppChooserWidget_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_app_chooser_widget_set_show_default(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_app_chooser_widget_set_show_default(GtkAppChooserWidget_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_app_chooser_widget_set_show_all(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_app_chooser_widget_set_show_all(GtkAppChooserWidget_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_app_chooser_widget_set_default_text(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_app_chooser_widget_set_default_text(GtkAppChooserWidget_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_app_chooser_widget_get_show_recommended(value self)
{
CAMLparam1(self);

gboolean result = gtk_app_chooser_widget_get_show_recommended(GtkAppChooserWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_app_chooser_widget_get_show_other(value self)
{
CAMLparam1(self);

gboolean result = gtk_app_chooser_widget_get_show_other(GtkAppChooserWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_app_chooser_widget_get_show_fallback(value self)
{
CAMLparam1(self);

gboolean result = gtk_app_chooser_widget_get_show_fallback(GtkAppChooserWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_app_chooser_widget_get_show_default(value self)
{
CAMLparam1(self);

gboolean result = gtk_app_chooser_widget_get_show_default(GtkAppChooserWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_app_chooser_widget_get_show_all(value self)
{
CAMLparam1(self);

gboolean result = gtk_app_chooser_widget_get_show_all(GtkAppChooserWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_app_chooser_widget_get_default_text(value self)
{
CAMLparam1(self);

const char* result = gtk_app_chooser_widget_get_default_text(GtkAppChooserWidget_val(self));
CAMLreturn(Val_option_string(result));
}

GType gtk_app_chooser_widget_get_type (void);


CAMLprim value ml_gtk_app_chooser_widget_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_app_chooser_widget_get_type()));
}
