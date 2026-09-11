/* GENERATED CODE - DO NOT EDIT */
/* C bindings for IMContextSimple */

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


CAMLexport CAMLprim value ml_gtk_im_context_simple_new(value unit)
{
CAMLparam1(unit);

GtkIMContextSimple *obj = gtk_im_context_simple_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkIMContextSimple(obj));
}
CAMLexport CAMLprim value ml_gtk_im_context_simple_add_compose_file(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_im_context_simple_add_compose_file(GtkIMContextSimple_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_im_context_simple_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_im_context_simple_get_type()));
}
