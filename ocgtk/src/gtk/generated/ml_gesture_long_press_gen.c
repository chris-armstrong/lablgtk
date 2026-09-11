/* GENERATED CODE - DO NOT EDIT */
/* C bindings for GestureLongPress */

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


CAMLexport CAMLprim value ml_gtk_gesture_long_press_new(value unit)
{
CAMLparam1(unit);

GtkGestureLongPress *obj = gtk_gesture_long_press_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkGestureLongPress(obj));
}
CAMLexport CAMLprim value ml_gtk_gesture_long_press_set_delay_factor(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_gesture_long_press_set_delay_factor(GtkGestureLongPress_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_gesture_long_press_get_delay_factor(value self)
{
CAMLparam1(self);

double result = gtk_gesture_long_press_get_delay_factor(GtkGestureLongPress_val(self));
CAMLreturn(caml_copy_double(result));
}


CAMLprim value ml_gtk_gesture_long_press_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_gesture_long_press_get_type()));
}
