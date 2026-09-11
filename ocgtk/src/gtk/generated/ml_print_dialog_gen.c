/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PrintDialog */

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

#if GTK_CHECK_VERSION(4,14,0)


CAMLexport CAMLprim value ml_gtk_print_dialog_new(value unit)
{
CAMLparam1(unit);

GtkPrintDialog *obj = gtk_print_dialog_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkPrintDialog(obj));
}
CAMLexport CAMLprim value ml_gtk_print_dialog_setup_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GtkPrintSetup* result = gtk_print_dialog_setup_finish(GtkPrintDialog_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GtkPrintSetup(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_print_dialog_set_title(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_dialog_set_title(GtkPrintDialog_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_dialog_set_print_settings(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_dialog_set_print_settings(GtkPrintDialog_val(self), GtkPrintSettings_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_dialog_set_page_setup(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_dialog_set_page_setup(GtkPrintDialog_val(self), GtkPageSetup_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_dialog_set_modal(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_dialog_set_modal(GtkPrintDialog_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_dialog_set_accept_label(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_print_dialog_set_accept_label(GtkPrintDialog_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_dialog_print_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GOutputStream* result = gtk_print_dialog_print_finish(GtkPrintDialog_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GOutputStream(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_print_dialog_print_file_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = gtk_print_dialog_print_file_finish(GtkPrintDialog_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_print_dialog_get_title(value self)
{
CAMLparam1(self);

const char* result = gtk_print_dialog_get_title(GtkPrintDialog_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_print_dialog_get_print_settings(value self)
{
CAMLparam1(self);

GtkPrintSettings* result = gtk_print_dialog_get_print_settings(GtkPrintDialog_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkPrintSettings));
}

CAMLexport CAMLprim value ml_gtk_print_dialog_get_page_setup(value self)
{
CAMLparam1(self);

GtkPageSetup* result = gtk_print_dialog_get_page_setup(GtkPrintDialog_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkPageSetup));
}

CAMLexport CAMLprim value ml_gtk_print_dialog_get_modal(value self)
{
CAMLparam1(self);

gboolean result = gtk_print_dialog_get_modal(GtkPrintDialog_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_print_dialog_get_accept_label(value self)
{
CAMLparam1(self);

const char* result = gtk_print_dialog_get_accept_label(GtkPrintDialog_val(self));
CAMLreturn(caml_copy_string(result));
}

GType gtk_print_dialog_get_type (void);


CAMLprim value ml_gtk_print_dialog_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_print_dialog_get_type()));
}

#else


CAMLexport CAMLprim value ml_gtk_print_dialog_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("PrintDialog requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_print_dialog_get_accept_label(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PrintDialog requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_print_dialog_get_modal(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PrintDialog requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_print_dialog_get_page_setup(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PrintDialog requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_print_dialog_get_print_settings(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PrintDialog requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_print_dialog_get_title(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PrintDialog requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_print_dialog_print_file_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PrintDialog requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_print_dialog_print_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PrintDialog requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_print_dialog_set_accept_label(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PrintDialog requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_print_dialog_set_modal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PrintDialog requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_print_dialog_set_page_setup(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PrintDialog requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_print_dialog_set_print_settings(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PrintDialog requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_print_dialog_set_title(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PrintDialog requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_print_dialog_setup_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PrintDialog requires GTK >= 4.14");
return Val_unit;
}


#endif
