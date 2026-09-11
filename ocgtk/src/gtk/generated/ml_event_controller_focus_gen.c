/* GENERATED CODE - DO NOT EDIT */
/* C bindings for EventControllerFocus */

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


CAMLexport CAMLprim value ml_gtk_event_controller_focus_new(value unit)
{
CAMLparam1(unit);

GtkEventControllerFocus *obj = gtk_event_controller_focus_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkEventControllerFocus(obj));
}
CAMLexport CAMLprim value ml_gtk_event_controller_focus_is_focus(value self)
{
CAMLparam1(self);

gboolean result = gtk_event_controller_focus_is_focus(GtkEventControllerFocus_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_event_controller_focus_contains_focus(value self)
{
CAMLparam1(self);

gboolean result = gtk_event_controller_focus_contains_focus(GtkEventControllerFocus_val(self));
CAMLreturn(Val_bool(result));
}

GType gtk_event_controller_focus_get_type (void);


CAMLprim value ml_gtk_event_controller_focus_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_event_controller_focus_get_type()));
}
