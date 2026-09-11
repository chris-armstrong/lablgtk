/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Expression */

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


CAMLexport CAMLprim value ml_gtk_expression_unref(value self)
{
CAMLparam1(self);

gtk_expression_unref(GtkExpression_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_expression_ref(value self)
{
CAMLparam1(self);

GtkExpression* result = gtk_expression_ref(GtkExpression_val(self));
CAMLreturn(Val_GtkExpression(result));
}

CAMLexport CAMLprim value ml_gtk_expression_is_static(value self)
{
CAMLparam1(self);

gboolean result = gtk_expression_is_static(GtkExpression_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_expression_get_value_type(value self)
{
CAMLparam1(self);

GType result = gtk_expression_get_value_type(GtkExpression_val(self));
CAMLreturn(Val_GType(result));
}

CAMLexport CAMLprim value ml_gtk_expression_evaluate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gtk_expression_evaluate(GtkExpression_val(self), GObject_ext_of_val(arg1), GValue_val(arg2));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_expression_bind(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

GtkExpressionWatch* result = gtk_expression_bind(GtkExpression_val(self), GObject_ext_of_val(arg1), String_val(arg2), GObject_ext_of_val(arg3));
if (result) result = g_boxed_copy(gtk_expression_watch_get_type(), result);
CAMLreturn(Val_GtkExpressionWatch(result));
}

GType gtk_expression_get_type (void);


CAMLprim value ml_gtk_expression_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_expression_get_type()));
}
