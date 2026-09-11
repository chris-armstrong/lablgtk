/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ScrollEvent */

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


CAMLexport CAMLprim value ml_gdk_scroll_event_is_stop(value self)
{
CAMLparam1(self);

gboolean result = gdk_scroll_event_is_stop(GdkScrollEvent_val(self));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,8,0)

CAMLexport CAMLprim value ml_gdk_scroll_event_get_unit(value self)
{
CAMLparam1(self);

GdkScrollUnit result = gdk_scroll_event_get_unit(GdkScrollEvent_val(self));
CAMLreturn(Val_GdkScrollUnit(result));
}

#else

CAMLexport CAMLprim value ml_gdk_scroll_event_get_unit(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ScrollEvent requires GTK >= 4.8");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_scroll_event_get_direction(value self)
{
CAMLparam1(self);

GdkScrollDirection result = gdk_scroll_event_get_direction(GdkScrollEvent_val(self));
CAMLreturn(Val_GdkScrollDirection(result));
}

CAMLexport CAMLprim value ml_gdk_scroll_event_get_deltas(value self)
{
CAMLparam1(self);
double out1;
double out2;

gdk_scroll_event_get_deltas(GdkScrollEvent_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, caml_copy_double(out1));
    Store_field(ret, 1, caml_copy_double(out2));
    CAMLreturn(ret);
}

GType gdk_scroll_event_get_type (void);


CAMLprim value ml_gdk_scroll_event_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_scroll_event_get_type()));
}
