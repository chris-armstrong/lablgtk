/* GENERATED CODE - DO NOT EDIT */
/* C bindings for StringFilter */

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


CAMLexport CAMLprim value ml_gtk_string_filter_new(value arg1)
{
CAMLparam1(arg1);

GtkStringFilter *obj = gtk_string_filter_new(Option_val(arg1, GtkExpression_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkStringFilter(obj));
}
CAMLexport CAMLprim value ml_gtk_string_filter_set_search(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_string_filter_set_search(GtkStringFilter_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_string_filter_set_match_mode(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_string_filter_set_match_mode(GtkStringFilter_val(self), GtkStringFilterMatchMode_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_string_filter_set_ignore_case(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_string_filter_set_ignore_case(GtkStringFilter_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_string_filter_set_expression(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_string_filter_set_expression(GtkStringFilter_val(self), Option_val(arg1, GtkExpression_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_string_filter_get_search(value self)
{
CAMLparam1(self);

const char* result = gtk_string_filter_get_search(GtkStringFilter_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_string_filter_get_match_mode(value self)
{
CAMLparam1(self);

GtkStringFilterMatchMode result = gtk_string_filter_get_match_mode(GtkStringFilter_val(self));
CAMLreturn(Val_GtkStringFilterMatchMode(result));
}

CAMLexport CAMLprim value ml_gtk_string_filter_get_ignore_case(value self)
{
CAMLparam1(self);

gboolean result = gtk_string_filter_get_ignore_case(GtkStringFilter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_string_filter_get_expression(value self)
{
CAMLparam1(self);

GtkExpression* result = gtk_string_filter_get_expression(GtkStringFilter_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkExpression));
}

GType gtk_string_filter_get_type (void);


CAMLprim value ml_gtk_string_filter_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_string_filter_get_type()));
}
