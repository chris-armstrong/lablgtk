/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TouchpadEvent */

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


CAMLexport CAMLprim value ml_gdk_touchpad_event_get_pinch_scale(value self)
{
CAMLparam1(self);

double result = gdk_touchpad_event_get_pinch_scale(GdkTouchpadEvent_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gdk_touchpad_event_get_pinch_angle_delta(value self)
{
CAMLparam1(self);

double result = gdk_touchpad_event_get_pinch_angle_delta(GdkTouchpadEvent_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gdk_touchpad_event_get_n_fingers(value self)
{
CAMLparam1(self);

guint result = gdk_touchpad_event_get_n_fingers(GdkTouchpadEvent_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_touchpad_event_get_gesture_phase(value self)
{
CAMLparam1(self);

GdkTouchpadGesturePhase result = gdk_touchpad_event_get_gesture_phase(GdkTouchpadEvent_val(self));
CAMLreturn(Val_GdkTouchpadGesturePhase(result));
}

CAMLexport CAMLprim value ml_gdk_touchpad_event_get_deltas(value self)
{
CAMLparam1(self);
double out1;
double out2;

gdk_touchpad_event_get_deltas(GdkTouchpadEvent_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, caml_copy_double(out1));
    Store_field(ret, 1, caml_copy_double(out2));
    CAMLreturn(ret);
}

GType gdk_touchpad_event_get_type (void);


CAMLprim value ml_gdk_touchpad_event_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_touchpad_event_get_type()));
}
