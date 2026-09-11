/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ObjectExpression */

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


CAMLexport CAMLprim value ml_gtk_object_expression_new(value arg1)
{
CAMLparam1(arg1);

GtkObjectExpression *obj = gtk_object_expression_new(GObject_ext_of_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkObjectExpression(obj));
}
CAMLexport CAMLprim value ml_gtk_object_expression_get_object(value self)
{
CAMLparam1(self);

GObject* result = gtk_object_expression_get_object(GtkObjectExpression_val(self));
CAMLreturn(Val_option(result, ml_gobject_val_of_ext));
}

GType gtk_object_expression_get_type (void);


CAMLprim value ml_gtk_object_expression_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_object_expression_get_type()));
}
