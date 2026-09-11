/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FrameClock */

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


CAMLexport CAMLprim value ml_gdk_frame_clock_request_phase(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_frame_clock_request_phase(GdkFrameClock_val(self), GdkFrameClockPhase_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_frame_clock_get_timings(value self, value arg1)
{
CAMLparam2(self, arg1);

GdkFrameTimings* result = gdk_frame_clock_get_timings(GdkFrameClock_val(self), Int64_val(arg1));
if (result) result = g_boxed_copy(gdk_frame_timings_get_type(), result);
CAMLreturn(Val_option(result, Val_GdkFrameTimings));
}

CAMLexport CAMLprim value ml_gdk_frame_clock_get_refresh_info(value self, value arg1)
{
CAMLparam2(self, arg1);
gint64 out2;
gint64 out3;

gdk_frame_clock_get_refresh_info(GdkFrameClock_val(self), Int64_val(arg1), &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, caml_copy_int64(out2));
    Store_field(ret, 1, caml_copy_int64(out3));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gdk_frame_clock_get_history_start(value self)
{
CAMLparam1(self);

gint64 result = gdk_frame_clock_get_history_start(GdkFrameClock_val(self));
CAMLreturn(caml_copy_int64(result));
}

CAMLexport CAMLprim value ml_gdk_frame_clock_get_frame_time(value self)
{
CAMLparam1(self);

gint64 result = gdk_frame_clock_get_frame_time(GdkFrameClock_val(self));
CAMLreturn(caml_copy_int64(result));
}

CAMLexport CAMLprim value ml_gdk_frame_clock_get_frame_counter(value self)
{
CAMLparam1(self);

gint64 result = gdk_frame_clock_get_frame_counter(GdkFrameClock_val(self));
CAMLreturn(caml_copy_int64(result));
}

CAMLexport CAMLprim value ml_gdk_frame_clock_get_fps(value self)
{
CAMLparam1(self);

double result = gdk_frame_clock_get_fps(GdkFrameClock_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gdk_frame_clock_get_current_timings(value self)
{
CAMLparam1(self);

GdkFrameTimings* result = gdk_frame_clock_get_current_timings(GdkFrameClock_val(self));
if (result) result = g_boxed_copy(gdk_frame_timings_get_type(), result);
CAMLreturn(Val_option(result, Val_GdkFrameTimings));
}

CAMLexport CAMLprim value ml_gdk_frame_clock_end_updating(value self)
{
CAMLparam1(self);

gdk_frame_clock_end_updating(GdkFrameClock_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_frame_clock_begin_updating(value self)
{
CAMLparam1(self);

gdk_frame_clock_begin_updating(GdkFrameClock_val(self));
CAMLreturn(Val_unit);
}

GType gdk_frame_clock_get_type (void);


CAMLprim value ml_gdk_frame_clock_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_frame_clock_get_type()));
}
