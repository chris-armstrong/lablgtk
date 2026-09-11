/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FrameTimings */

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

/* Conversion functions for GdkFrameTimings (opaque record with hidden fields) */
GdkFrameTimings *GdkFrameTimings_val(value v) {
  return (GdkFrameTimings *)ml_gir_record_ptr_val(v, "GdkFrameTimings");
}

value Val_GdkFrameTimings(const GdkFrameTimings *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gdk_frame_timings_get_type(), ptr);
}

value Val_GdkFrameTimings_option(const GdkFrameTimings *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GdkFrameTimings(ptr));
}


CAMLexport CAMLprim value ml_gdk_frame_timings_ref(value self)
{
CAMLparam1(self);

GdkFrameTimings* result = gdk_frame_timings_ref(GdkFrameTimings_val(self));
CAMLreturn(Val_GdkFrameTimings(result));
}

CAMLexport CAMLprim value ml_gdk_frame_timings_get_refresh_interval(value self)
{
CAMLparam1(self);

gint64 result = gdk_frame_timings_get_refresh_interval(GdkFrameTimings_val(self));
CAMLreturn(caml_copy_int64(result));
}

CAMLexport CAMLprim value ml_gdk_frame_timings_get_presentation_time(value self)
{
CAMLparam1(self);

gint64 result = gdk_frame_timings_get_presentation_time(GdkFrameTimings_val(self));
CAMLreturn(caml_copy_int64(result));
}

CAMLexport CAMLprim value ml_gdk_frame_timings_get_predicted_presentation_time(value self)
{
CAMLparam1(self);

gint64 result = gdk_frame_timings_get_predicted_presentation_time(GdkFrameTimings_val(self));
CAMLreturn(caml_copy_int64(result));
}

CAMLexport CAMLprim value ml_gdk_frame_timings_get_frame_time(value self)
{
CAMLparam1(self);

gint64 result = gdk_frame_timings_get_frame_time(GdkFrameTimings_val(self));
CAMLreturn(caml_copy_int64(result));
}

CAMLexport CAMLprim value ml_gdk_frame_timings_get_frame_counter(value self)
{
CAMLparam1(self);

gint64 result = gdk_frame_timings_get_frame_counter(GdkFrameTimings_val(self));
CAMLreturn(caml_copy_int64(result));
}

CAMLexport CAMLprim value ml_gdk_frame_timings_get_complete(value self)
{
CAMLparam1(self);

gboolean result = gdk_frame_timings_get_complete(GdkFrameTimings_val(self));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_gdk_frame_timings_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_frame_timings_get_type()));
}
