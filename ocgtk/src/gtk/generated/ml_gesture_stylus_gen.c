/* GENERATED CODE - DO NOT EDIT */
/* C bindings for GestureStylus */

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


CAMLexport CAMLprim value ml_gtk_gesture_stylus_new(value unit)
{
CAMLparam1(unit);

GtkGestureStylus *obj = gtk_gesture_stylus_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkGestureStylus(obj));
}
#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_gesture_stylus_set_stylus_only(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_gesture_stylus_set_stylus_only(GtkGestureStylus_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_gesture_stylus_set_stylus_only(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("GestureStylus requires GTK >= 4.10");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_gesture_stylus_get_stylus_only(value self)
{
CAMLparam1(self);

gboolean result = gtk_gesture_stylus_get_stylus_only(GtkGestureStylus_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gtk_gesture_stylus_get_stylus_only(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("GestureStylus requires GTK >= 4.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_gesture_stylus_get_device_tool(value self)
{
CAMLparam1(self);

GdkDeviceTool* result = gtk_gesture_stylus_get_device_tool(GtkGestureStylus_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkDeviceTool));
}

CAMLexport CAMLprim value ml_gtk_gesture_stylus_get_backlog(value self)
{
CAMLparam1(self);
GdkTimeCoord* out1 = NULL;
guint out2;

gboolean result = gtk_gesture_stylus_get_backlog(GtkGestureStylus_val(self), &out1, &out2);
    int out1_length = out2;
    CAMLlocal1(ml_out1);
    ml_out1 = caml_alloc(out1_length, 0);
    for (int i = 0; i < out1_length; i++) {
      Store_field(ml_out1, i, Val_GdkTimeCoord(&out1[i]));
    }

    g_free(out1);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, ml_out1);
    Store_field(ret, 2, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_gesture_stylus_get_axis(value self, value arg1)
{
CAMLparam2(self, arg1);
double out2;

gboolean result = gtk_gesture_stylus_get_axis(GtkGestureStylus_val(self), GdkAxisUse_val(arg1), &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, caml_copy_double(out2));
    CAMLreturn(ret);
}


CAMLprim value ml_gtk_gesture_stylus_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_gesture_stylus_get_type()));
}
