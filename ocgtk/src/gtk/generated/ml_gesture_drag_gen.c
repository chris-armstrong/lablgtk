/* GENERATED CODE - DO NOT EDIT */
/* C bindings for GestureDrag */

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


CAMLexport CAMLprim value ml_gtk_gesture_drag_new(value unit)
{
CAMLparam1(unit);

GtkGestureDrag *obj = gtk_gesture_drag_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkGestureDrag(obj));
}
CAMLexport CAMLprim value ml_gtk_gesture_drag_get_start_point(value self)
{
CAMLparam1(self);
double out1;
double out2;

gboolean result = gtk_gesture_drag_get_start_point(GtkGestureDrag_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, caml_copy_double(out1));
    Store_field(ret, 2, caml_copy_double(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_gesture_drag_get_offset(value self)
{
CAMLparam1(self);
double out1;
double out2;

gboolean result = gtk_gesture_drag_get_offset(GtkGestureDrag_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, caml_copy_double(out1));
    Store_field(ret, 2, caml_copy_double(out2));
    CAMLreturn(ret);
}

GType gtk_gesture_drag_get_type (void);


CAMLprim value ml_gtk_gesture_drag_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_gesture_drag_get_type()));
}
