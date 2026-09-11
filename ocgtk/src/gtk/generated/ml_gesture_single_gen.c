/* GENERATED CODE - DO NOT EDIT */
/* C bindings for GestureSingle */

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


CAMLexport CAMLprim value ml_gtk_gesture_single_set_touch_only(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_gesture_single_set_touch_only(GtkGestureSingle_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_gesture_single_set_exclusive(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_gesture_single_set_exclusive(GtkGestureSingle_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_gesture_single_set_button(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_gesture_single_set_button(GtkGestureSingle_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_gesture_single_get_touch_only(value self)
{
CAMLparam1(self);

gboolean result = gtk_gesture_single_get_touch_only(GtkGestureSingle_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_gesture_single_get_exclusive(value self)
{
CAMLparam1(self);

gboolean result = gtk_gesture_single_get_exclusive(GtkGestureSingle_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_gesture_single_get_current_sequence(value self)
{
CAMLparam1(self);

GdkEventSequence* result = gtk_gesture_single_get_current_sequence(GtkGestureSingle_val(self));
CAMLreturn(Val_option(result, Val_GdkEventSequence));
}

CAMLexport CAMLprim value ml_gtk_gesture_single_get_current_button(value self)
{
CAMLparam1(self);

guint result = gtk_gesture_single_get_current_button(GtkGestureSingle_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_gesture_single_get_button(value self)
{
CAMLparam1(self);

guint result = gtk_gesture_single_get_button(GtkGestureSingle_val(self));
CAMLreturn(Val_int(result));
}


CAMLprim value ml_gtk_gesture_single_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_gesture_single_get_type()));
}
