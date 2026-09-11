/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SignalAction */

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


CAMLexport CAMLprim value ml_gtk_signal_action_new(value arg1)
{
CAMLparam1(arg1);

GtkSignalAction *obj = gtk_signal_action_new(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkSignalAction(obj));
}
CAMLexport CAMLprim value ml_gtk_signal_action_get_signal_name(value self)
{
CAMLparam1(self);

const char* result = gtk_signal_action_get_signal_name(GtkSignalAction_val(self));
CAMLreturn(caml_copy_string(result));
}


CAMLprim value ml_gtk_signal_action_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_signal_action_get_type()));
}
