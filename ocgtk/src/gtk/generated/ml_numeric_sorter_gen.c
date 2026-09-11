/* GENERATED CODE - DO NOT EDIT */
/* C bindings for NumericSorter */

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


CAMLexport CAMLprim value ml_gtk_numeric_sorter_new(value arg1)
{
CAMLparam1(arg1);

GtkNumericSorter *obj = gtk_numeric_sorter_new(Option_val(arg1, GtkExpression_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkNumericSorter(obj));
}
CAMLexport CAMLprim value ml_gtk_numeric_sorter_set_sort_order(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_numeric_sorter_set_sort_order(GtkNumericSorter_val(self), GtkSortType_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_numeric_sorter_set_expression(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_numeric_sorter_set_expression(GtkNumericSorter_val(self), Option_val(arg1, GtkExpression_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_numeric_sorter_get_sort_order(value self)
{
CAMLparam1(self);

GtkSortType result = gtk_numeric_sorter_get_sort_order(GtkNumericSorter_val(self));
CAMLreturn(Val_GtkSortType(result));
}

CAMLexport CAMLprim value ml_gtk_numeric_sorter_get_expression(value self)
{
CAMLparam1(self);

GtkExpression* result = gtk_numeric_sorter_get_expression(GtkNumericSorter_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkExpression));
}

GType gtk_numeric_sorter_get_type (void);


CAMLprim value ml_gtk_numeric_sorter_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_numeric_sorter_get_type()));
}
