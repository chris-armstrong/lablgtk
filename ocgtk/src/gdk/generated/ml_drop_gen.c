/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Drop */

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


CAMLexport CAMLprim value ml_gdk_drop_status(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gdk_drop_status(GdkDrop_val(self), GdkDragAction_val(arg1), GdkDragAction_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_drop_read_value_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

const GValue* result = gdk_drop_read_value_finish(GdkDrop_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GValue_copy(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gdk_drop_get_surface(value self)
{
CAMLparam1(self);

GdkSurface* result = gdk_drop_get_surface(GdkDrop_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkSurface(result));
}

CAMLexport CAMLprim value ml_gdk_drop_get_formats(value self)
{
CAMLparam1(self);

GdkContentFormats* result = gdk_drop_get_formats(GdkDrop_val(self));
if (result) result = g_boxed_copy(gdk_content_formats_get_type(), result);
CAMLreturn(Val_GdkContentFormats(result));
}

CAMLexport CAMLprim value ml_gdk_drop_get_drag(value self)
{
CAMLparam1(self);

GdkDrag* result = gdk_drop_get_drag(GdkDrop_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkDrag));
}

CAMLexport CAMLprim value ml_gdk_drop_get_display(value self)
{
CAMLparam1(self);

GdkDisplay* result = gdk_drop_get_display(GdkDrop_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkDisplay(result));
}

CAMLexport CAMLprim value ml_gdk_drop_get_device(value self)
{
CAMLparam1(self);

GdkDevice* result = gdk_drop_get_device(GdkDrop_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkDevice(result));
}

CAMLexport CAMLprim value ml_gdk_drop_get_actions(value self)
{
CAMLparam1(self);

GdkDragAction result = gdk_drop_get_actions(GdkDrop_val(self));
CAMLreturn(Val_GdkDragAction(result));
}

CAMLexport CAMLprim value ml_gdk_drop_finish(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_drop_finish(GdkDrop_val(self), GdkDragAction_val(arg1));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gdk_drop_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_drop_get_type()));
}
