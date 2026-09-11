/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DNDEvent */

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


CAMLexport CAMLprim value ml_gdk_dnd_event_get_drop(value self)
{
CAMLparam1(self);

GdkDrop* result = gdk_dnd_event_get_drop(GdkDNDEvent_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkDrop));
}

GType gdk_dnd_event_get_type (void);


CAMLprim value ml_gdk_dnd_event_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_dnd_event_get_type()));
}
