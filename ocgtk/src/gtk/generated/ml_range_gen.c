/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Range */

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


CAMLexport CAMLprim value ml_gtk_range_set_value(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_range_set_value(GtkRange_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_range_set_slider_size_fixed(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_range_set_slider_size_fixed(GtkRange_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_range_set_show_fill_level(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_range_set_show_fill_level(GtkRange_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_range_set_round_digits(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_range_set_round_digits(GtkRange_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_range_set_restrict_to_fill_level(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_range_set_restrict_to_fill_level(GtkRange_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_range_set_range(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_range_set_range(GtkRange_val(self), Double_val(arg1), Double_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_range_set_inverted(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_range_set_inverted(GtkRange_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_range_set_increments(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_range_set_increments(GtkRange_val(self), Double_val(arg1), Double_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_range_set_flippable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_range_set_flippable(GtkRange_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_range_set_fill_level(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_range_set_fill_level(GtkRange_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_range_set_adjustment(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_range_set_adjustment(GtkRange_val(self), GtkAdjustment_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_range_get_value(value self)
{
CAMLparam1(self);

double result = gtk_range_get_value(GtkRange_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_range_get_slider_size_fixed(value self)
{
CAMLparam1(self);

gboolean result = gtk_range_get_slider_size_fixed(GtkRange_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_range_get_slider_range(value self)
{
CAMLparam1(self);
int out1;
int out2;

gtk_range_get_slider_range(GtkRange_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_range_get_show_fill_level(value self)
{
CAMLparam1(self);

gboolean result = gtk_range_get_show_fill_level(GtkRange_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_range_get_round_digits(value self)
{
CAMLparam1(self);

int result = gtk_range_get_round_digits(GtkRange_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_range_get_restrict_to_fill_level(value self)
{
CAMLparam1(self);

gboolean result = gtk_range_get_restrict_to_fill_level(GtkRange_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_range_get_range_rect(value self)
{
CAMLparam1(self);
GdkRectangle out1;

gtk_range_get_range_rect(GtkRange_val(self), &out1);
CAMLreturn(Val_GdkRectangle(&out1));
}

CAMLexport CAMLprim value ml_gtk_range_get_inverted(value self)
{
CAMLparam1(self);

gboolean result = gtk_range_get_inverted(GtkRange_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_range_get_flippable(value self)
{
CAMLparam1(self);

gboolean result = gtk_range_get_flippable(GtkRange_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_range_get_fill_level(value self)
{
CAMLparam1(self);

double result = gtk_range_get_fill_level(GtkRange_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_range_get_adjustment(value self)
{
CAMLparam1(self);

GtkAdjustment* result = gtk_range_get_adjustment(GtkRange_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkAdjustment(result));
}

GType gtk_range_get_type (void);


CAMLprim value ml_gtk_range_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_range_get_type()));
}
