/* GENERATED CODE - DO NOT EDIT */
/* C bindings for NamedAction */

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


CAMLexport CAMLprim value ml_gtk_named_action_new(value arg1)
{
CAMLparam1(arg1);

GtkNamedAction *obj = gtk_named_action_new(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkNamedAction(obj));
}
CAMLexport CAMLprim value ml_gtk_named_action_get_action_name(value self)
{
CAMLparam1(self);

const char* result = gtk_named_action_get_action_name(GtkNamedAction_val(self));
CAMLreturn(caml_copy_string(result));
}


CAMLprim value ml_gtk_named_action_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_named_action_get_type()));
}
