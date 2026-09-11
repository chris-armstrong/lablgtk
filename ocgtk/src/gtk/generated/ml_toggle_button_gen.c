/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ToggleButton */

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


CAMLexport CAMLprim value ml_gtk_toggle_button_new(value unit)
{
CAMLparam1(unit);

GtkToggleButton *obj = gtk_toggle_button_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkToggleButton(obj));
}
CAMLexport CAMLprim value ml_gtk_toggle_button_new_with_label(value arg1)
{
CAMLparam1(arg1);

GtkToggleButton *obj = gtk_toggle_button_new_with_label(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkToggleButton(obj));
}
CAMLexport CAMLprim value ml_gtk_toggle_button_new_with_mnemonic(value arg1)
{
CAMLparam1(arg1);

GtkToggleButton *obj = gtk_toggle_button_new_with_mnemonic(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkToggleButton(obj));
}
CAMLexport CAMLprim value ml_gtk_toggle_button_toggled(value self)
{
CAMLparam1(self);

gtk_toggle_button_toggled(GtkToggleButton_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_toggle_button_set_group(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_toggle_button_set_group(GtkToggleButton_val(self), Option_val(arg1, GtkToggleButton_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_toggle_button_set_active(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_toggle_button_set_active(GtkToggleButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_toggle_button_get_active(value self)
{
CAMLparam1(self);

gboolean result = gtk_toggle_button_get_active(GtkToggleButton_val(self));
CAMLreturn(Val_bool(result));
}

GType gtk_toggle_button_get_type (void);


CAMLprim value ml_gtk_toggle_button_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_toggle_button_get_type()));
}
