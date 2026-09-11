/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Gesture */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"
#include "converters.h"

#include <gtk/gtk.h>
/* Include library-specific type conversions and forward declarations */
#include "gtk_decls.h"


CAMLexport CAMLprim value ml_gtk_gesture_ungroup(value self)
{
CAMLparam1(self);

gtk_gesture_ungroup(GtkGesture_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_gesture_set_state(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_gesture_set_state(GtkGesture_val(self), GtkEventSequenceState_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_gesture_set_sequence_state(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gtk_gesture_set_sequence_state(GtkGesture_val(self), GdkEventSequence_val(arg1), GtkEventSequenceState_val(arg2));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_gesture_is_recognized(value self)
{
CAMLparam1(self);

gboolean result = gtk_gesture_is_recognized(GtkGesture_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_gesture_is_grouped_with(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_gesture_is_grouped_with(GtkGesture_val(self), GtkGesture_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_gesture_is_active(value self)
{
CAMLparam1(self);

gboolean result = gtk_gesture_is_active(GtkGesture_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_gesture_handles_sequence(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_gesture_handles_sequence(GtkGesture_val(self), Option_val(arg1, GdkEventSequence_val, NULL));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_gesture_group(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_gesture_group(GtkGesture_val(self), GtkGesture_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_gesture_get_sequences(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = gtk_gesture_get_sequences(GtkGesture_val(self));
Val_GList_with(c_result, result, item, cell, Val_GdkEventSequence((gpointer)_tmp->data));
    g_list_free(c_result);
    CAMLreturn(result);
}

CAMLexport CAMLprim value ml_gtk_gesture_get_sequence_state(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkEventSequenceState result = gtk_gesture_get_sequence_state(GtkGesture_val(self), GdkEventSequence_val(arg1));
CAMLreturn(Val_GtkEventSequenceState(result));
}

CAMLexport CAMLprim value ml_gtk_gesture_get_point(value self, value arg1)
{
CAMLparam2(self, arg1);
double out2;
double out3;

gboolean result = gtk_gesture_get_point(GtkGesture_val(self), Option_val(arg1, GdkEventSequence_val, NULL), &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, caml_copy_double(out2));
    Store_field(ret, 2, caml_copy_double(out3));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_gesture_get_last_updated_sequence(value self)
{
CAMLparam1(self);

GdkEventSequence* result = gtk_gesture_get_last_updated_sequence(GtkGesture_val(self));
if (result) result = g_boxed_copy(gdk_event_sequence_get_type(), result);
CAMLreturn(Val_option(result, Val_GdkEventSequence));
}

CAMLexport CAMLprim value ml_gtk_gesture_get_last_event(value self, value arg1)
{
CAMLparam2(self, arg1);

GdkEvent* result = gtk_gesture_get_last_event(GtkGesture_val(self), Option_val(arg1, GdkEventSequence_val, NULL));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkEvent));
}

CAMLexport CAMLprim value ml_gtk_gesture_get_group(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = gtk_gesture_get_group(GtkGesture_val(self));
Val_GList_with(c_result, result, item, cell, Val_GtkGesture((gpointer)_tmp->data));
    g_list_free(c_result);
    CAMLreturn(result);
}

CAMLexport CAMLprim value ml_gtk_gesture_get_device(value self)
{
CAMLparam1(self);

GdkDevice* result = gtk_gesture_get_device(GtkGesture_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkDevice));
}

CAMLexport CAMLprim value ml_gtk_gesture_get_bounding_box_center(value self)
{
CAMLparam1(self);
double out1;
double out2;

gboolean result = gtk_gesture_get_bounding_box_center(GtkGesture_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, caml_copy_double(out1));
    Store_field(ret, 2, caml_copy_double(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_gesture_get_bounding_box(value self)
{
CAMLparam1(self);
GdkRectangle out1;

gboolean result = gtk_gesture_get_bounding_box(GtkGesture_val(self), &out1);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_GdkRectangle(&out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_gesture_get_n_points(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkGesture *obj = (GtkGesture *)GtkGesture_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "n-points");
if (pspec == NULL) caml_failwith("ml_gtk_gesture_get_n_points: property 'n-points' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "n-points", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}


CAMLprim value ml_gtk_gesture_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_gesture_get_type()));
}
