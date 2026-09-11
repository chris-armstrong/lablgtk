/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Separator */

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


CAMLexport CAMLprim value ml_gtk_separator_new(value arg1)
{
CAMLparam1(arg1);

GtkSeparator *obj = gtk_separator_new(GtkOrientation_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkSeparator(obj));
}

CAMLprim value ml_gtk_separator_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_separator_get_type()));
}
