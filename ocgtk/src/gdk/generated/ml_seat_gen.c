/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Seat */

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


CAMLexport CAMLprim value ml_gdk_seat_get_tools(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = gdk_seat_get_tools(GdkSeat_val(self));
Val_GList_with(c_result, result, item, cell, Val_GdkDeviceTool((gpointer)_tmp->data));
    g_list_free(c_result);
    CAMLreturn(result);
}

CAMLexport CAMLprim value ml_gdk_seat_get_pointer(value self)
{
CAMLparam1(self);

GdkDevice* result = gdk_seat_get_pointer(GdkSeat_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkDevice));
}

CAMLexport CAMLprim value ml_gdk_seat_get_keyboard(value self)
{
CAMLparam1(self);

GdkDevice* result = gdk_seat_get_keyboard(GdkSeat_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkDevice));
}

CAMLexport CAMLprim value ml_gdk_seat_get_display(value self)
{
CAMLparam1(self);

GdkDisplay* result = gdk_seat_get_display(GdkSeat_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkDisplay(result));
}

CAMLexport CAMLprim value ml_gdk_seat_get_devices(value self, value arg1)
{
CAMLparam2(self, arg1);

CAMLlocal3(result, item, cell);
    GList* c_result = gdk_seat_get_devices(GdkSeat_val(self), GdkSeatCapabilities_val(arg1));
Val_GList_with(c_result, result, item, cell, Val_GdkDevice((gpointer)_tmp->data));
    g_list_free(c_result);
    CAMLreturn(result);
}

CAMLexport CAMLprim value ml_gdk_seat_get_capabilities(value self)
{
CAMLparam1(self);

GdkSeatCapabilities result = gdk_seat_get_capabilities(GdkSeat_val(self));
CAMLreturn(Val_GdkSeatCapabilities(result));
}


CAMLprim value ml_gdk_seat_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_seat_get_type()));
}
