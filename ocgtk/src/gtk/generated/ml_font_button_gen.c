/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FontButton */

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


CAMLexport CAMLprim value ml_gtk_font_button_new(value unit)
{
CAMLparam1(unit);

GtkFontButton *obj = gtk_font_button_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkFontButton(obj));
}
CAMLexport CAMLprim value ml_gtk_font_button_new_with_font(value arg1)
{
CAMLparam1(arg1);

GtkFontButton *obj = gtk_font_button_new_with_font(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkFontButton(obj));
}
CAMLexport CAMLprim value ml_gtk_font_button_set_use_size(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_button_set_use_size(GtkFontButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_button_set_use_font(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_button_set_use_font(GtkFontButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_button_set_title(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_button_set_title(GtkFontButton_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_button_set_modal(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_button_set_modal(GtkFontButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_button_get_use_size(value self)
{
CAMLparam1(self);

gboolean result = gtk_font_button_get_use_size(GtkFontButton_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_font_button_get_use_font(value self)
{
CAMLparam1(self);

gboolean result = gtk_font_button_get_use_font(GtkFontButton_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_font_button_get_title(value self)
{
CAMLparam1(self);

const char* result = gtk_font_button_get_title(GtkFontButton_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_font_button_get_modal(value self)
{
CAMLparam1(self);

gboolean result = gtk_font_button_get_modal(GtkFontButton_val(self));
CAMLreturn(Val_bool(result));
}

GType gtk_font_button_get_type (void);


CAMLprim value ml_gtk_font_button_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_font_button_get_type()));
}
