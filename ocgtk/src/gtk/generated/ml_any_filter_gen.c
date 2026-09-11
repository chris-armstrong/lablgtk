/* GENERATED CODE - DO NOT EDIT */
/* C bindings for AnyFilter */

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


CAMLexport CAMLprim value ml_gtk_any_filter_new(value unit)
{
CAMLparam1(unit);

GtkAnyFilter *obj = gtk_any_filter_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkAnyFilter(obj));
}

CAMLprim value ml_gtk_any_filter_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_any_filter_get_type()));
}
