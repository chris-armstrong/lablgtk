/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PrintOperation */

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


CAMLexport CAMLprim value ml_gtk_print_operation_new(value unit)
{
CAMLparam1(unit);

GtkPrintOperation *obj = gtk_print_operation_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkPrintOperation(obj));
}
CAMLexport CAMLprim value ml_gtk_print_operation_set_use_full_page(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_operation_set_use_full_page(GtkPrintOperation_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_operation_set_unit(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_operation_set_unit(GtkPrintOperation_val(self), GtkUnit_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_operation_set_track_print_status(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_operation_set_track_print_status(GtkPrintOperation_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_operation_set_support_selection(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_operation_set_support_selection(GtkPrintOperation_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_operation_set_show_progress(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_operation_set_show_progress(GtkPrintOperation_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_operation_set_print_settings(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_operation_set_print_settings(GtkPrintOperation_val(self), Option_val(arg1, GtkPrintSettings_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_operation_set_n_pages(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_operation_set_n_pages(GtkPrintOperation_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_operation_set_job_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_operation_set_job_name(GtkPrintOperation_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_operation_set_has_selection(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_operation_set_has_selection(GtkPrintOperation_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_operation_set_export_filename(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_operation_set_export_filename(GtkPrintOperation_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_operation_set_embed_page_setup(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_operation_set_embed_page_setup(GtkPrintOperation_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_operation_set_defer_drawing(value self)
{
CAMLparam1(self);

gtk_print_operation_set_defer_drawing(GtkPrintOperation_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_operation_set_default_page_setup(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_operation_set_default_page_setup(GtkPrintOperation_val(self), Option_val(arg1, GtkPageSetup_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_operation_set_custom_tab_label(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_operation_set_custom_tab_label(GtkPrintOperation_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_operation_set_current_page(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_operation_set_current_page(GtkPrintOperation_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_operation_set_allow_async(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_operation_set_allow_async(GtkPrintOperation_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_operation_run(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

GtkPrintOperationResult result = gtk_print_operation_run(GtkPrintOperation_val(self), GtkPrintOperationAction_val(arg1), Option_val(arg2, GtkWindow_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GtkPrintOperationResult(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_print_operation_is_finished(value self)
{
CAMLparam1(self);

gboolean result = gtk_print_operation_is_finished(GtkPrintOperation_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_print_operation_get_support_selection(value self)
{
CAMLparam1(self);

gboolean result = gtk_print_operation_get_support_selection(GtkPrintOperation_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_print_operation_get_status_string(value self)
{
CAMLparam1(self);

const char* result = gtk_print_operation_get_status_string(GtkPrintOperation_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_print_operation_get_status(value self)
{
CAMLparam1(self);

GtkPrintStatus result = gtk_print_operation_get_status(GtkPrintOperation_val(self));
CAMLreturn(Val_GtkPrintStatus(result));
}

CAMLexport CAMLprim value ml_gtk_print_operation_get_print_settings(value self)
{
CAMLparam1(self);

GtkPrintSettings* result = gtk_print_operation_get_print_settings(GtkPrintOperation_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkPrintSettings));
}

CAMLexport CAMLprim value ml_gtk_print_operation_get_n_pages_to_print(value self)
{
CAMLparam1(self);

int result = gtk_print_operation_get_n_pages_to_print(GtkPrintOperation_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_print_operation_get_has_selection(value self)
{
CAMLparam1(self);

gboolean result = gtk_print_operation_get_has_selection(GtkPrintOperation_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_print_operation_get_error(value self)
{
CAMLparam1(self);
GError *error = NULL;

gtk_print_operation_get_error(GtkPrintOperation_val(self), &error);
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_operation_get_embed_page_setup(value self)
{
CAMLparam1(self);

gboolean result = gtk_print_operation_get_embed_page_setup(GtkPrintOperation_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_print_operation_get_default_page_setup(value self)
{
CAMLparam1(self);

GtkPageSetup* result = gtk_print_operation_get_default_page_setup(GtkPrintOperation_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkPageSetup(result));
}

CAMLexport CAMLprim value ml_gtk_print_operation_draw_page_finish(value self)
{
CAMLparam1(self);

gtk_print_operation_draw_page_finish(GtkPrintOperation_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_operation_cancel(value self)
{
CAMLparam1(self);

gtk_print_operation_cancel(GtkPrintOperation_val(self));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_print_operation_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_print_operation_get_type()));
}
