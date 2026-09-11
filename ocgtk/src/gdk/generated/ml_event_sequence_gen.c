/* GENERATED CODE - DO NOT EDIT */
/* C bindings for EventSequence */

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

/* Conversion functions for GdkEventSequence (opaque record with hidden fields) */
GdkEventSequence *GdkEventSequence_val(value v) {
  return (GdkEventSequence *)ml_gir_record_ptr_val(v, "GdkEventSequence");
}

value Val_GdkEventSequence(const GdkEventSequence *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gdk_event_sequence_get_type(), ptr);
}

value Val_GdkEventSequence_option(const GdkEventSequence *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GdkEventSequence(ptr));
}


GType gdk_event_sequence_get_type (void);


CAMLprim value ml_gdk_event_sequence_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_event_sequence_get_type()));
}
