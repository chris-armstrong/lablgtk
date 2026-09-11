/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ParamSpecExpression */

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



CAMLprim value ml_gtk_param_spec_expression_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_param_expression_get_type()));
}
