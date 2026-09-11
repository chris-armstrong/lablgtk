/* GENERATED CODE - DO NOT EDIT */
/* C bindings for AlternativeTrigger */

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


CAMLexport CAMLprim value ml_gtk_alternative_trigger_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkAlternativeTrigger *obj = gtk_alternative_trigger_new(GtkShortcutTrigger_val(arg1), GtkShortcutTrigger_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkAlternativeTrigger(obj));
}
CAMLexport CAMLprim value ml_gtk_alternative_trigger_get_second(value self)
{
CAMLparam1(self);

GtkShortcutTrigger* result = gtk_alternative_trigger_get_second(GtkAlternativeTrigger_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkShortcutTrigger(result));
}

CAMLexport CAMLprim value ml_gtk_alternative_trigger_get_first(value self)
{
CAMLparam1(self);

GtkShortcutTrigger* result = gtk_alternative_trigger_get_first(GtkAlternativeTrigger_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkShortcutTrigger(result));
}


CAMLprim value ml_gtk_alternative_trigger_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_alternative_trigger_get_type()));
}
