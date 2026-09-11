/* GENERATED CODE - DO NOT EDIT */
/* C bindings for GrabBrokenEvent */

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


CAMLexport CAMLprim value ml_gdk_grab_broken_event_get_implicit(value self)
{
CAMLparam1(self);

gboolean result = gdk_grab_broken_event_get_implicit(GdkGrabBrokenEvent_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_grab_broken_event_get_grab_surface(value self)
{
CAMLparam1(self);

GdkSurface* result = gdk_grab_broken_event_get_grab_surface(GdkGrabBrokenEvent_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkSurface(result));
}

GType gdk_grab_broken_event_get_type (void);


CAMLprim value ml_gdk_grab_broken_event_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_grab_broken_event_get_type()));
}
