/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PrintSettings */

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


CAMLexport CAMLprim value ml_gtk_print_settings_new(value unit)
{
CAMLparam1(unit);

GtkPrintSettings *obj = gtk_print_settings_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkPrintSettings(obj));
}
CAMLexport CAMLprim value ml_gtk_print_settings_new_from_file(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GtkPrintSettings *obj = gtk_print_settings_new_from_file(String_val(arg1), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GtkPrintSettings(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_gtk_print_settings_new_from_gvariant(value arg1)
{
CAMLparam1(arg1);

GtkPrintSettings *obj = gtk_print_settings_new_from_gvariant(GVariant_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkPrintSettings(obj));
}
CAMLexport CAMLprim value ml_gtk_print_settings_unset(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_unset(GtkPrintSettings_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_to_gvariant(value self)
{
CAMLparam1(self);

GVariant* result = gtk_print_settings_to_gvariant(GtkPrintSettings_val(self));
if (result) g_variant_ref(result);
CAMLreturn(Val_GVariant(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_to_file(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = gtk_print_settings_to_file(GtkPrintSettings_val(self), String_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_use_color(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_set_use_color(GtkPrintSettings_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_scale(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_set_scale(GtkPrintSettings_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_reverse(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_set_reverse(GtkPrintSettings_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_resolution_xy(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_print_settings_set_resolution_xy(GtkPrintSettings_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_resolution(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_set_resolution(GtkPrintSettings_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_quality(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_set_quality(GtkPrintSettings_val(self), GtkPrintQuality_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_printer_lpi(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_set_printer_lpi(GtkPrintSettings_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_printer(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_set_printer(GtkPrintSettings_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_print_pages(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_set_print_pages(GtkPrintSettings_val(self), GtkPrintPages_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_paper_width(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_print_settings_set_paper_width(GtkPrintSettings_val(self), Double_val(arg1), GtkUnit_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_paper_size(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_set_paper_size(GtkPrintSettings_val(self), GtkPaperSize_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_paper_height(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_print_settings_set_paper_height(GtkPrintSettings_val(self), Double_val(arg1), GtkUnit_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_page_set(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_set_page_set(GtkPrintSettings_val(self), GtkPageSet_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_page_ranges(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
    int arg1_length = Wosize_val(arg1);
    GtkPageRange* c_arg1 = (GtkPageRange*)g_malloc(sizeof(GtkPageRange) * arg1_length);
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = *GtkPageRange_val(Field(arg1, i));
    }

gtk_print_settings_set_page_ranges(GtkPrintSettings_val(self), c_arg1, Int_val(arg2));
    g_free(c_arg1);
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_output_bin(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_set_output_bin(GtkPrintSettings_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_orientation(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_set_orientation(GtkPrintSettings_val(self), GtkPageOrientation_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_number_up_layout(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_set_number_up_layout(GtkPrintSettings_val(self), GtkNumberUpLayout_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_number_up(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_set_number_up(GtkPrintSettings_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_n_copies(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_set_n_copies(GtkPrintSettings_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_media_type(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_set_media_type(GtkPrintSettings_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_length(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_print_settings_set_length(GtkPrintSettings_val(self), String_val(arg1), Double_val(arg2), GtkUnit_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_int(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_print_settings_set_int(GtkPrintSettings_val(self), String_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_finishings(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_set_finishings(GtkPrintSettings_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_duplex(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_set_duplex(GtkPrintSettings_val(self), GtkPrintDuplex_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_double(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_print_settings_set_double(GtkPrintSettings_val(self), String_val(arg1), Double_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_dither(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_set_dither(GtkPrintSettings_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_default_source(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_set_default_source(GtkPrintSettings_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_collate(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_settings_set_collate(GtkPrintSettings_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set_bool(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_print_settings_set_bool(GtkPrintSettings_val(self), String_val(arg1), Bool_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_set(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_print_settings_set(GtkPrintSettings_val(self), String_val(arg1), String_option_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_settings_load_file(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = gtk_print_settings_load_file(GtkPrintSettings_val(self), String_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_print_settings_has_key(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_print_settings_has_key(GtkPrintSettings_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_use_color(value self)
{
CAMLparam1(self);

gboolean result = gtk_print_settings_get_use_color(GtkPrintSettings_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_scale(value self)
{
CAMLparam1(self);

double result = gtk_print_settings_get_scale(GtkPrintSettings_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_reverse(value self)
{
CAMLparam1(self);

gboolean result = gtk_print_settings_get_reverse(GtkPrintSettings_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_resolution_y(value self)
{
CAMLparam1(self);

int result = gtk_print_settings_get_resolution_y(GtkPrintSettings_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_resolution_x(value self)
{
CAMLparam1(self);

int result = gtk_print_settings_get_resolution_x(GtkPrintSettings_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_resolution(value self)
{
CAMLparam1(self);

int result = gtk_print_settings_get_resolution(GtkPrintSettings_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_quality(value self)
{
CAMLparam1(self);

GtkPrintQuality result = gtk_print_settings_get_quality(GtkPrintSettings_val(self));
CAMLreturn(Val_GtkPrintQuality(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_printer_lpi(value self)
{
CAMLparam1(self);

double result = gtk_print_settings_get_printer_lpi(GtkPrintSettings_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_printer(value self)
{
CAMLparam1(self);

const char* result = gtk_print_settings_get_printer(GtkPrintSettings_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_print_pages(value self)
{
CAMLparam1(self);

GtkPrintPages result = gtk_print_settings_get_print_pages(GtkPrintSettings_val(self));
CAMLreturn(Val_GtkPrintPages(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_paper_width(value self, value arg1)
{
CAMLparam2(self, arg1);

double result = gtk_print_settings_get_paper_width(GtkPrintSettings_val(self), GtkUnit_val(arg1));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_paper_size(value self)
{
CAMLparam1(self);

GtkPaperSize* result = gtk_print_settings_get_paper_size(GtkPrintSettings_val(self));
CAMLreturn(Val_option(result, Val_GtkPaperSize));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_paper_height(value self, value arg1)
{
CAMLparam2(self, arg1);

double result = gtk_print_settings_get_paper_height(GtkPrintSettings_val(self), GtkUnit_val(arg1));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_page_set(value self)
{
CAMLparam1(self);

GtkPageSet result = gtk_print_settings_get_page_set(GtkPrintSettings_val(self));
CAMLreturn(Val_GtkPageSet(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_page_ranges(value self)
{
CAMLparam1(self);
int out1;

GtkPageRange* result = gtk_print_settings_get_page_ranges(GtkPrintSettings_val(self), &out1);
    int result_length = out1;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, Val_GtkPageRange(&result[i]));
    }
    g_free(result);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_result);
    Store_field(ret, 1, Val_int(out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_output_bin(value self)
{
CAMLparam1(self);

const char* result = gtk_print_settings_get_output_bin(GtkPrintSettings_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_orientation(value self)
{
CAMLparam1(self);

GtkPageOrientation result = gtk_print_settings_get_orientation(GtkPrintSettings_val(self));
CAMLreturn(Val_GtkPageOrientation(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_number_up_layout(value self)
{
CAMLparam1(self);

GtkNumberUpLayout result = gtk_print_settings_get_number_up_layout(GtkPrintSettings_val(self));
CAMLreturn(Val_GtkNumberUpLayout(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_number_up(value self)
{
CAMLparam1(self);

int result = gtk_print_settings_get_number_up(GtkPrintSettings_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_n_copies(value self)
{
CAMLparam1(self);

int result = gtk_print_settings_get_n_copies(GtkPrintSettings_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_media_type(value self)
{
CAMLparam1(self);

const char* result = gtk_print_settings_get_media_type(GtkPrintSettings_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_length(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

double result = gtk_print_settings_get_length(GtkPrintSettings_val(self), String_val(arg1), GtkUnit_val(arg2));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_int_with_default(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

int result = gtk_print_settings_get_int_with_default(GtkPrintSettings_val(self), String_val(arg1), Int_val(arg2));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_int(value self, value arg1)
{
CAMLparam2(self, arg1);

int result = gtk_print_settings_get_int(GtkPrintSettings_val(self), String_val(arg1));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_finishings(value self)
{
CAMLparam1(self);

const char* result = gtk_print_settings_get_finishings(GtkPrintSettings_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_duplex(value self)
{
CAMLparam1(self);

GtkPrintDuplex result = gtk_print_settings_get_duplex(GtkPrintSettings_val(self));
CAMLreturn(Val_GtkPrintDuplex(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_double_with_default(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

double result = gtk_print_settings_get_double_with_default(GtkPrintSettings_val(self), String_val(arg1), Double_val(arg2));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_double(value self, value arg1)
{
CAMLparam2(self, arg1);

double result = gtk_print_settings_get_double(GtkPrintSettings_val(self), String_val(arg1));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_dither(value self)
{
CAMLparam1(self);

const char* result = gtk_print_settings_get_dither(GtkPrintSettings_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_default_source(value self)
{
CAMLparam1(self);

const char* result = gtk_print_settings_get_default_source(GtkPrintSettings_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_collate(value self)
{
CAMLparam1(self);

gboolean result = gtk_print_settings_get_collate(GtkPrintSettings_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get_bool(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_print_settings_get_bool(GtkPrintSettings_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_get(value self, value arg1)
{
CAMLparam2(self, arg1);

const char* result = gtk_print_settings_get(GtkPrintSettings_val(self), String_val(arg1));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_print_settings_copy(value self)
{
CAMLparam1(self);

GtkPrintSettings* result = gtk_print_settings_copy(GtkPrintSettings_val(self));
CAMLreturn(Val_GtkPrintSettings(result));
}

GType gtk_print_settings_get_type (void);


CAMLprim value ml_gtk_print_settings_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_print_settings_get_type()));
}
