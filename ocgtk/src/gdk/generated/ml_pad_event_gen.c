/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PadEvent */

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


CAMLexport CAMLprim value ml_gdk_pad_event_get_group_mode(value self)
{
CAMLparam1(self);
guint out1;
guint out2;

gdk_pad_event_get_group_mode(GdkPadEvent_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gdk_pad_event_get_button(value self)
{
CAMLparam1(self);

guint result = gdk_pad_event_get_button(GdkPadEvent_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_pad_event_get_axis_value(value self)
{
CAMLparam1(self);
guint out1;
double out2;

gdk_pad_event_get_axis_value(GdkPadEvent_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, caml_copy_double(out2));
    CAMLreturn(ret);
}

GType gdk_pad_event_get_type (void);


CAMLprim value ml_gdk_pad_event_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_pad_event_get_type()));
}
