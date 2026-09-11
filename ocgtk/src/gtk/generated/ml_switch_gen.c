/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Switch */

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


CAMLexport CAMLprim value ml_gtk_switch_new(value unit)
{
CAMLparam1(unit);

GtkSwitch *obj = gtk_switch_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkSwitch(obj));
}
CAMLexport CAMLprim value ml_gtk_switch_set_state(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_switch_set_state(GtkSwitch_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_switch_set_active(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_switch_set_active(GtkSwitch_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_switch_get_state(value self)
{
CAMLparam1(self);

gboolean result = gtk_switch_get_state(GtkSwitch_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_switch_get_active(value self)
{
CAMLparam1(self);

gboolean result = gtk_switch_get_active(GtkSwitch_val(self));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_gtk_switch_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_switch_get_type()));
}
