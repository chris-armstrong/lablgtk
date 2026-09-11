/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PrintContext */

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


CAMLexport CAMLprim value ml_gtk_print_context_set_cairo_context(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_print_context_set_cairo_context(GtkPrintContext_val(self), cairo_t_val(arg1), Double_val(arg2), Double_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_print_context_get_width(value self)
{
CAMLparam1(self);

double result = gtk_print_context_get_width(GtkPrintContext_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_print_context_get_pango_fontmap(value self)
{
CAMLparam1(self);

PangoFontMap* result = gtk_print_context_get_pango_fontmap(GtkPrintContext_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_PangoFontMap(result));
}

CAMLexport CAMLprim value ml_gtk_print_context_get_page_setup(value self)
{
CAMLparam1(self);

GtkPageSetup* result = gtk_print_context_get_page_setup(GtkPrintContext_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkPageSetup(result));
}

CAMLexport CAMLprim value ml_gtk_print_context_get_height(value self)
{
CAMLparam1(self);

double result = gtk_print_context_get_height(GtkPrintContext_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_print_context_get_hard_margins(value self)
{
CAMLparam1(self);
double out1;
double out2;
double out3;
double out4;

gboolean result = gtk_print_context_get_hard_margins(GtkPrintContext_val(self), &out1, &out2, &out3, &out4);
CAMLlocal1(ret);
    ret = caml_alloc(5, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, caml_copy_double(out1));
    Store_field(ret, 2, caml_copy_double(out2));
    Store_field(ret, 3, caml_copy_double(out3));
    Store_field(ret, 4, caml_copy_double(out4));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_print_context_get_dpi_y(value self)
{
CAMLparam1(self);

double result = gtk_print_context_get_dpi_y(GtkPrintContext_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_print_context_get_dpi_x(value self)
{
CAMLparam1(self);

double result = gtk_print_context_get_dpi_x(GtkPrintContext_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_print_context_get_cairo_context(value self)
{
CAMLparam1(self);

cairo_t* result = gtk_print_context_get_cairo_context(GtkPrintContext_val(self));
if (result) result = g_boxed_copy(cairo_gobject_context_get_type(), result);
CAMLreturn(Val_cairo_t(result));
}

CAMLexport CAMLprim value ml_gtk_print_context_create_pango_layout(value self)
{
CAMLparam1(self);

PangoLayout* result = gtk_print_context_create_pango_layout(GtkPrintContext_val(self));
CAMLreturn(Val_PangoLayout(result));
}

CAMLexport CAMLprim value ml_gtk_print_context_create_pango_context(value self)
{
CAMLparam1(self);

PangoContext* result = gtk_print_context_create_pango_context(GtkPrintContext_val(self));
CAMLreturn(Val_PangoContext(result));
}


CAMLprim value ml_gtk_print_context_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_print_context_get_type()));
}
