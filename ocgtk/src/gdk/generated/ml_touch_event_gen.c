/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TouchEvent */

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


CAMLexport CAMLprim value ml_gdk_touch_event_get_emulating_pointer(value self)
{
CAMLparam1(self);

gboolean result = gdk_touch_event_get_emulating_pointer(GdkTouchEvent_val(self));
CAMLreturn(Val_bool(result));
}

GType gdk_touch_event_get_type (void);


CAMLprim value ml_gdk_touch_event_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_touch_event_get_type()));
}
