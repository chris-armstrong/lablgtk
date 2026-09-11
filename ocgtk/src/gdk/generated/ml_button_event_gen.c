/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ButtonEvent */

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


CAMLexport CAMLprim value ml_gdk_button_event_get_button(value self)
{
CAMLparam1(self);

guint result = gdk_button_event_get_button(GdkButtonEvent_val(self));
CAMLreturn(Val_int(result));
}

GType gdk_button_event_get_type (void);


CAMLprim value ml_gdk_button_event_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_button_event_get_type()));
}
