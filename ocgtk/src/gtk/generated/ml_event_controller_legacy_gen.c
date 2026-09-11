/* GENERATED CODE - DO NOT EDIT */
/* C bindings for EventControllerLegacy */

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


CAMLexport CAMLprim value ml_gtk_event_controller_legacy_new(value unit)
{
CAMLparam1(unit);

GtkEventControllerLegacy *obj = gtk_event_controller_legacy_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkEventControllerLegacy(obj));
}

CAMLprim value ml_gtk_event_controller_legacy_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_event_controller_legacy_get_type()));
}
