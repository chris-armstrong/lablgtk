/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Event */

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


CAMLexport CAMLprim value ml_gdk_event_unref(value self)
{
CAMLparam1(self);

gdk_event_unref(GdkEvent_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_event_triggers_context_menu(value self)
{
CAMLparam1(self);

gboolean result = gdk_event_triggers_context_menu(GdkEvent_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_event_ref(value self)
{
CAMLparam1(self);

GdkEvent* result = gdk_event_ref(GdkEvent_val(self));
CAMLreturn(Val_GdkEvent(result));
}

CAMLexport CAMLprim value ml_gdk_event_get_time(value self)
{
CAMLparam1(self);

guint32 result = gdk_event_get_time(GdkEvent_val(self));
CAMLreturn(Val_uint32(result));
}

CAMLexport CAMLprim value ml_gdk_event_get_surface(value self)
{
CAMLparam1(self);

GdkSurface* result = gdk_event_get_surface(GdkEvent_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkSurface));
}

CAMLexport CAMLprim value ml_gdk_event_get_seat(value self)
{
CAMLparam1(self);

GdkSeat* result = gdk_event_get_seat(GdkEvent_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkSeat));
}

CAMLexport CAMLprim value ml_gdk_event_get_position(value self)
{
CAMLparam1(self);
double out1;
double out2;

gboolean result = gdk_event_get_position(GdkEvent_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, caml_copy_double(out1));
    Store_field(ret, 2, caml_copy_double(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gdk_event_get_pointer_emulated(value self)
{
CAMLparam1(self);

gboolean result = gdk_event_get_pointer_emulated(GdkEvent_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_event_get_modifier_state(value self)
{
CAMLparam1(self);

GdkModifierType result = gdk_event_get_modifier_state(GdkEvent_val(self));
CAMLreturn(Val_GdkModifierType(result));
}

CAMLexport CAMLprim value ml_gdk_event_get_history(value self)
{
CAMLparam1(self);
guint out1;

GdkTimeCoord* result = gdk_event_get_history(GdkEvent_val(self), &out1);
    CAMLlocal2(ml_result, ml_result_opt);
    if (result == NULL) {
      ml_result_opt = Val_none;
    } else {
      int result_length = out1;
      ml_result = caml_alloc(result_length, 0);
      for (int i = 0; i < result_length; i++) {
        Store_field(ml_result, i, Val_GdkTimeCoord(&result[i]));
      }
      ml_result_opt = Val_some(ml_result);
            g_free(result);
    }
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_result_opt);
    Store_field(ret, 1, Val_int(out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gdk_event_get_event_type(value self)
{
CAMLparam1(self);

GdkEventType result = gdk_event_get_event_type(GdkEvent_val(self));
CAMLreturn(Val_GdkEventType(result));
}

CAMLexport CAMLprim value ml_gdk_event_get_event_sequence(value self)
{
CAMLparam1(self);

GdkEventSequence* result = gdk_event_get_event_sequence(GdkEvent_val(self));
if (result) result = g_boxed_copy(gdk_event_sequence_get_type(), result);
CAMLreturn(Val_GdkEventSequence(result));
}

CAMLexport CAMLprim value ml_gdk_event_get_display(value self)
{
CAMLparam1(self);

GdkDisplay* result = gdk_event_get_display(GdkEvent_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkDisplay));
}

CAMLexport CAMLprim value ml_gdk_event_get_device_tool(value self)
{
CAMLparam1(self);

GdkDeviceTool* result = gdk_event_get_device_tool(GdkEvent_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkDeviceTool));
}

CAMLexport CAMLprim value ml_gdk_event_get_device(value self)
{
CAMLparam1(self);

GdkDevice* result = gdk_event_get_device(GdkEvent_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkDevice));
}

CAMLexport CAMLprim value ml_gdk_event_get_axis(value self, value arg1)
{
CAMLparam2(self, arg1);
double out2;

gboolean result = gdk_event_get_axis(GdkEvent_val(self), GdkAxisUse_val(arg1), &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, caml_copy_double(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gdk_event_get_axes(value self)
{
CAMLparam1(self);
double* out1 = NULL;
guint out2;

gboolean result = gdk_event_get_axes(GdkEvent_val(self), &out1, &out2);
    int out1_length = out2;
    CAMLlocal1(ml_out1);
    ml_out1 = caml_alloc(out1_length, 0);
    for (int i = 0; i < out1_length; i++) {
      Store_field(ml_out1, i, caml_copy_double(out1[i]));
    }

CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, ml_out1);
    Store_field(ret, 2, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gdk_events_get_distance(value self, value arg1)
{
CAMLparam2(self, arg1);
double out2;

gboolean result = gdk_events_get_distance(GdkEvent_val(self), GdkEvent_val(arg1), &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, caml_copy_double(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gdk_events_get_center(value self, value arg1)
{
CAMLparam2(self, arg1);
double out2;
double out3;

gboolean result = gdk_events_get_center(GdkEvent_val(self), GdkEvent_val(arg1), &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, caml_copy_double(out2));
    Store_field(ret, 2, caml_copy_double(out3));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gdk_events_get_angle(value self, value arg1)
{
CAMLparam2(self, arg1);
double out2;

gboolean result = gdk_events_get_angle(GdkEvent_val(self), GdkEvent_val(arg1), &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, caml_copy_double(out2));
    CAMLreturn(ret);
}

GType gdk_event_get_type (void);


CAMLprim value ml_gdk_event_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_event_get_type()));
}
