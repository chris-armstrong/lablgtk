/* GENERATED CODE - DO NOT EDIT */
/* C bindings for BoolFilter */

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


CAMLexport CAMLprim value ml_gtk_bool_filter_new(value arg1)
{
CAMLparam1(arg1);

GtkBoolFilter *obj = gtk_bool_filter_new(Option_val(arg1, GtkExpression_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkBoolFilter(obj));
}
CAMLexport CAMLprim value ml_gtk_bool_filter_set_invert(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_bool_filter_set_invert(GtkBoolFilter_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_bool_filter_set_expression(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_bool_filter_set_expression(GtkBoolFilter_val(self), Option_val(arg1, GtkExpression_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_bool_filter_get_invert(value self)
{
CAMLparam1(self);

gboolean result = gtk_bool_filter_get_invert(GtkBoolFilter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_bool_filter_get_expression(value self)
{
CAMLparam1(self);

GtkExpression* result = gtk_bool_filter_get_expression(GtkBoolFilter_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkExpression));
}


CAMLprim value ml_gtk_bool_filter_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_bool_filter_get_type()));
}
