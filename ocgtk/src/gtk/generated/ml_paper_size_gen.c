/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PaperSize */

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

/* Conversion functions for GtkPaperSize (opaque record with hidden fields) */
GtkPaperSize *GtkPaperSize_val(value v) {
  return (GtkPaperSize *)ml_gir_record_ptr_val(v, "GtkPaperSize");
}

value Val_GtkPaperSize(const GtkPaperSize *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gtk_paper_size_get_type(), ptr);
}

value Val_GtkPaperSize_option(const GtkPaperSize *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GtkPaperSize(ptr));
}


CAMLexport CAMLprim value ml_gtk_paper_size_new(value arg1)
{
CAMLparam1(arg1);

GtkPaperSize *obj = gtk_paper_size_new(String_option_val(arg1));

CAMLreturn(Val_GtkPaperSize(obj));
}
CAMLexport CAMLprim value ml_gtk_paper_size_new_custom(value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);

GtkPaperSize *obj = gtk_paper_size_new_custom(String_val(arg1), String_val(arg2), Double_val(arg3), Double_val(arg4), GtkUnit_val(arg5));

CAMLreturn(Val_GtkPaperSize(obj));
}
CAMLexport CAMLprim value ml_gtk_paper_size_new_from_gvariant(value arg1)
{
CAMLparam1(arg1);

GtkPaperSize *obj = gtk_paper_size_new_from_gvariant(GVariant_val(arg1));

CAMLreturn(Val_GtkPaperSize(obj));
}
CAMLexport CAMLprim value ml_gtk_paper_size_new_from_ipp(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GtkPaperSize *obj = gtk_paper_size_new_from_ipp(String_val(arg1), Double_val(arg2), Double_val(arg3));

CAMLreturn(Val_GtkPaperSize(obj));
}
CAMLexport CAMLprim value ml_gtk_paper_size_new_from_ppd(value arg1, value arg2, value arg3, value arg4)
{
CAMLparam4(arg1, arg2, arg3, arg4);

GtkPaperSize *obj = gtk_paper_size_new_from_ppd(String_val(arg1), String_val(arg2), Double_val(arg3), Double_val(arg4));

CAMLreturn(Val_GtkPaperSize(obj));
}
CAMLexport CAMLprim value ml_gtk_paper_size_to_gvariant(value self)
{
CAMLparam1(self);

GVariant* result = gtk_paper_size_to_gvariant(GtkPaperSize_val(self));
if (result) g_variant_ref(result);
CAMLreturn(Val_GVariant(result));
}

CAMLexport CAMLprim value ml_gtk_paper_size_set_size(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_paper_size_set_size(GtkPaperSize_val(self), Double_val(arg1), Double_val(arg2), GtkUnit_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_paper_size_is_ipp(value self)
{
CAMLparam1(self);

gboolean result = gtk_paper_size_is_ipp(GtkPaperSize_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_paper_size_is_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_paper_size_is_equal(GtkPaperSize_val(self), GtkPaperSize_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_paper_size_is_custom(value self)
{
CAMLparam1(self);

gboolean result = gtk_paper_size_is_custom(GtkPaperSize_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_paper_size_get_width(value self, value arg1)
{
CAMLparam2(self, arg1);

double result = gtk_paper_size_get_width(GtkPaperSize_val(self), GtkUnit_val(arg1));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_paper_size_get_ppd_name(value self)
{
CAMLparam1(self);

const char* result = gtk_paper_size_get_ppd_name(GtkPaperSize_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_paper_size_get_name(value self)
{
CAMLparam1(self);

const char* result = gtk_paper_size_get_name(GtkPaperSize_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_paper_size_get_height(value self, value arg1)
{
CAMLparam2(self, arg1);

double result = gtk_paper_size_get_height(GtkPaperSize_val(self), GtkUnit_val(arg1));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_paper_size_get_display_name(value self)
{
CAMLparam1(self);

const char* result = gtk_paper_size_get_display_name(GtkPaperSize_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_paper_size_get_default_top_margin(value self, value arg1)
{
CAMLparam2(self, arg1);

double result = gtk_paper_size_get_default_top_margin(GtkPaperSize_val(self), GtkUnit_val(arg1));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_paper_size_get_default_right_margin(value self, value arg1)
{
CAMLparam2(self, arg1);

double result = gtk_paper_size_get_default_right_margin(GtkPaperSize_val(self), GtkUnit_val(arg1));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_paper_size_get_default_left_margin(value self, value arg1)
{
CAMLparam2(self, arg1);

double result = gtk_paper_size_get_default_left_margin(GtkPaperSize_val(self), GtkUnit_val(arg1));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_paper_size_get_default_bottom_margin(value self, value arg1)
{
CAMLparam2(self, arg1);

double result = gtk_paper_size_get_default_bottom_margin(GtkPaperSize_val(self), GtkUnit_val(arg1));
CAMLreturn(caml_copy_double(result));
}

GType gtk_paper_size_get_type (void);


CAMLprim value ml_gtk_paper_size_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_paper_size_get_type()));
}
