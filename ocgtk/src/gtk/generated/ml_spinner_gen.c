/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Spinner */

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


CAMLexport CAMLprim value ml_gtk_spinner_new(value unit)
{
CAMLparam1(unit);

GtkSpinner *obj = gtk_spinner_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkSpinner(obj));
}
CAMLexport CAMLprim value ml_gtk_spinner_stop(value self)
{
CAMLparam1(self);

gtk_spinner_stop(GtkSpinner_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_spinner_start(value self)
{
CAMLparam1(self);

gtk_spinner_start(GtkSpinner_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_spinner_set_spinning(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_spinner_set_spinning(GtkSpinner_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_spinner_get_spinning(value self)
{
CAMLparam1(self);

gboolean result = gtk_spinner_get_spinning(GtkSpinner_val(self));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_gtk_spinner_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_spinner_get_type()));
}
