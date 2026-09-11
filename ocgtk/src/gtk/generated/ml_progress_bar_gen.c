/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ProgressBar */

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


CAMLexport CAMLprim value ml_gtk_progress_bar_new(value unit)
{
CAMLparam1(unit);

GtkProgressBar *obj = gtk_progress_bar_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkProgressBar(obj));
}
CAMLexport CAMLprim value ml_gtk_progress_bar_set_text(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_progress_bar_set_text(GtkProgressBar_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_progress_bar_set_show_text(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_progress_bar_set_show_text(GtkProgressBar_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_progress_bar_set_pulse_step(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_progress_bar_set_pulse_step(GtkProgressBar_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_progress_bar_set_inverted(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_progress_bar_set_inverted(GtkProgressBar_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_progress_bar_set_fraction(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_progress_bar_set_fraction(GtkProgressBar_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_progress_bar_set_ellipsize(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_progress_bar_set_ellipsize(GtkProgressBar_val(self), PangoEllipsizeMode_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_progress_bar_pulse(value self)
{
CAMLparam1(self);

gtk_progress_bar_pulse(GtkProgressBar_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_progress_bar_get_text(value self)
{
CAMLparam1(self);

const char* result = gtk_progress_bar_get_text(GtkProgressBar_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_progress_bar_get_show_text(value self)
{
CAMLparam1(self);

gboolean result = gtk_progress_bar_get_show_text(GtkProgressBar_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_progress_bar_get_pulse_step(value self)
{
CAMLparam1(self);

double result = gtk_progress_bar_get_pulse_step(GtkProgressBar_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_progress_bar_get_inverted(value self)
{
CAMLparam1(self);

gboolean result = gtk_progress_bar_get_inverted(GtkProgressBar_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_progress_bar_get_fraction(value self)
{
CAMLparam1(self);

double result = gtk_progress_bar_get_fraction(GtkProgressBar_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_progress_bar_get_ellipsize(value self)
{
CAMLparam1(self);

PangoEllipsizeMode result = gtk_progress_bar_get_ellipsize(GtkProgressBar_val(self));
CAMLreturn(Val_PangoEllipsizeMode(result));
}


CAMLprim value ml_gtk_progress_bar_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_progress_bar_get_type()));
}
