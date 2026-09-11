/* GENERATED CODE - DO NOT EDIT */
/* C bindings for GestureRotate */

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


CAMLexport CAMLprim value ml_gtk_gesture_rotate_new(value unit)
{
CAMLparam1(unit);

GtkGestureRotate *obj = gtk_gesture_rotate_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkGestureRotate(obj));
}
CAMLexport CAMLprim value ml_gtk_gesture_rotate_get_angle_delta(value self)
{
CAMLparam1(self);

double result = gtk_gesture_rotate_get_angle_delta(GtkGestureRotate_val(self));
CAMLreturn(caml_copy_double(result));
}

GType gtk_gesture_rotate_get_type (void);


CAMLprim value ml_gtk_gesture_rotate_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_gesture_rotate_get_type()));
}
