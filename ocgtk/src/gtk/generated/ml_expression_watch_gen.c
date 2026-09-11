/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ExpressionWatch */

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

/* Conversion functions for GtkExpressionWatch (opaque record with hidden fields) */
GtkExpressionWatch *GtkExpressionWatch_val(value v) {
  return (GtkExpressionWatch *)ml_gir_record_ptr_val(v, "GtkExpressionWatch");
}

value Val_GtkExpressionWatch(const GtkExpressionWatch *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gtk_expression_watch_get_type(), ptr);
}

value Val_GtkExpressionWatch_option(const GtkExpressionWatch *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GtkExpressionWatch(ptr));
}


CAMLexport CAMLprim value ml_gtk_expression_watch_unwatch(value self)
{
CAMLparam1(self);

gtk_expression_watch_unwatch(GtkExpressionWatch_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_expression_watch_ref(value self)
{
CAMLparam1(self);

GtkExpressionWatch* result = gtk_expression_watch_ref(GtkExpressionWatch_val(self));
CAMLreturn(Val_GtkExpressionWatch(result));
}

CAMLexport CAMLprim value ml_gtk_expression_watch_evaluate(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_expression_watch_evaluate(GtkExpressionWatch_val(self), GValue_val(arg1));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_gtk_expression_watch_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_expression_watch_get_type()));
}
