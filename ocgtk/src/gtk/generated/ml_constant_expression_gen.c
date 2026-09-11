/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ConstantExpression */

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


CAMLexport CAMLprim value ml_gtk_constant_expression_new_for_value(value arg1)
{
CAMLparam1(arg1);

GtkConstantExpression *obj = gtk_constant_expression_new_for_value(GValue_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkConstantExpression(obj));
}
CAMLexport CAMLprim value ml_gtk_constant_expression_get_value(value self)
{
CAMLparam1(self);

const GValue* result = gtk_constant_expression_get_value(GtkConstantExpression_val(self));
CAMLreturn(Val_GValue_copy(result));
}


CAMLprim value ml_gtk_constant_expression_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_constant_expression_get_type()));
}
