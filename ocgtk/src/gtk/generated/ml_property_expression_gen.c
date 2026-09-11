/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PropertyExpression */

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


CAMLexport CAMLprim value ml_gtk_property_expression_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GtkPropertyExpression *obj = gtk_property_expression_new(GType_val(arg1), Option_val(arg2, GtkExpression_val, NULL), String_val(arg3));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkPropertyExpression(obj));
}
CAMLexport CAMLprim value ml_gtk_property_expression_get_expression(value self)
{
CAMLparam1(self);

GtkExpression* result = gtk_property_expression_get_expression(GtkPropertyExpression_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkExpression));
}

GType gtk_property_expression_get_type (void);


CAMLprim value ml_gtk_property_expression_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_property_expression_get_type()));
}
