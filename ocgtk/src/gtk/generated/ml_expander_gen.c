/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Expander */

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


CAMLexport CAMLprim value ml_gtk_expander_new(value arg1)
{
CAMLparam1(arg1);

GtkExpander *obj = gtk_expander_new(String_option_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkExpander(obj));
}
CAMLexport CAMLprim value ml_gtk_expander_new_with_mnemonic(value arg1)
{
CAMLparam1(arg1);

GtkExpander *obj = gtk_expander_new_with_mnemonic(String_option_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkExpander(obj));
}
CAMLexport CAMLprim value ml_gtk_expander_set_use_underline(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_expander_set_use_underline(GtkExpander_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_expander_set_use_markup(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_expander_set_use_markup(GtkExpander_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_expander_set_resize_toplevel(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_expander_set_resize_toplevel(GtkExpander_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_expander_set_label_widget(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_expander_set_label_widget(GtkExpander_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_expander_set_label(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_expander_set_label(GtkExpander_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_expander_set_expanded(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_expander_set_expanded(GtkExpander_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_expander_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_expander_set_child(GtkExpander_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_expander_get_use_underline(value self)
{
CAMLparam1(self);

gboolean result = gtk_expander_get_use_underline(GtkExpander_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_expander_get_use_markup(value self)
{
CAMLparam1(self);

gboolean result = gtk_expander_get_use_markup(GtkExpander_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_expander_get_resize_toplevel(value self)
{
CAMLparam1(self);

gboolean result = gtk_expander_get_resize_toplevel(GtkExpander_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_expander_get_label_widget(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_expander_get_label_widget(GtkExpander_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_expander_get_label(value self)
{
CAMLparam1(self);

const char* result = gtk_expander_get_label(GtkExpander_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_expander_get_expanded(value self)
{
CAMLparam1(self);

gboolean result = gtk_expander_get_expanded(GtkExpander_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_expander_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_expander_get_child(GtkExpander_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}


CAMLprim value ml_gtk_expander_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_expander_get_type()));
}
