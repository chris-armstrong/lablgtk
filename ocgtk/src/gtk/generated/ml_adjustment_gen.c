/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Adjustment */

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


CAMLexport CAMLprim value ml_gtk_adjustment_new_native(value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);
CAMLxparam1(arg6);

GtkAdjustment *obj = gtk_adjustment_new(Double_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5), Double_val(arg6));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkAdjustment(obj));}

CAMLexport CAMLprim value ml_gtk_adjustment_new_bytecode(value * argv, int argn)
{
return ml_gtk_adjustment_new_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gtk_adjustment_set_value(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_adjustment_set_value(GtkAdjustment_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_adjustment_set_upper(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_adjustment_set_upper(GtkAdjustment_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_adjustment_set_step_increment(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_adjustment_set_step_increment(GtkAdjustment_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_adjustment_set_page_size(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_adjustment_set_page_size(GtkAdjustment_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_adjustment_set_page_increment(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_adjustment_set_page_increment(GtkAdjustment_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_adjustment_set_lower(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_adjustment_set_lower(GtkAdjustment_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_adjustment_get_value(value self)
{
CAMLparam1(self);

double result = gtk_adjustment_get_value(GtkAdjustment_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_adjustment_get_upper(value self)
{
CAMLparam1(self);

double result = gtk_adjustment_get_upper(GtkAdjustment_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_adjustment_get_step_increment(value self)
{
CAMLparam1(self);

double result = gtk_adjustment_get_step_increment(GtkAdjustment_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_adjustment_get_page_size(value self)
{
CAMLparam1(self);

double result = gtk_adjustment_get_page_size(GtkAdjustment_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_adjustment_get_page_increment(value self)
{
CAMLparam1(self);

double result = gtk_adjustment_get_page_increment(GtkAdjustment_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_adjustment_get_minimum_increment(value self)
{
CAMLparam1(self);

double result = gtk_adjustment_get_minimum_increment(GtkAdjustment_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_adjustment_get_lower(value self)
{
CAMLparam1(self);

double result = gtk_adjustment_get_lower(GtkAdjustment_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_adjustment_configure_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam2(arg5, arg6);

gtk_adjustment_configure(GtkAdjustment_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5), Double_val(arg6));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gtk_adjustment_configure_bytecode(value * argv, int argn)
{
return ml_gtk_adjustment_configure_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

CAMLexport CAMLprim value ml_gtk_adjustment_clamp_page(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_adjustment_clamp_page(GtkAdjustment_val(self), Double_val(arg1), Double_val(arg2));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_adjustment_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_adjustment_get_type()));
}
