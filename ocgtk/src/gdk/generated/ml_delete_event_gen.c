/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DeleteEvent */

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



CAMLprim value ml_gdk_delete_event_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_delete_event_get_type()));
}
