/* GENERATED CODE - DO NOT EDIT */
/* C bindings for EveryFilter */

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


CAMLexport CAMLprim value ml_gtk_every_filter_new(value unit)
{
CAMLparam1(unit);

GtkEveryFilter *obj = gtk_every_filter_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkEveryFilter(obj));
}

CAMLprim value ml_gtk_every_filter_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_every_filter_get_type()));
}
