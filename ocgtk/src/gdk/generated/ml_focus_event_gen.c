/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FocusEvent */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gdk/gdk.h>
/* Include library-specific type conversions and forward declarations */
#include "gdk_decls.h"


CAMLexport CAMLprim value ml_gdk_focus_event_get_in(value self)
{
CAMLparam1(self);

gboolean result = gdk_focus_event_get_in(GdkFocusEvent_val(self));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_gdk_focus_event_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_focus_event_get_type()));
}
