/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Drag */

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


CAMLexport CAMLprim value ml_gdk_drag_set_hotspot(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gdk_drag_set_hotspot(GdkDrag_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_drag_get_surface(value self)
{
CAMLparam1(self);

GdkSurface* result = gdk_drag_get_surface(GdkDrag_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkSurface(result));
}

CAMLexport CAMLprim value ml_gdk_drag_get_selected_action(value self)
{
CAMLparam1(self);

GdkDragAction result = gdk_drag_get_selected_action(GdkDrag_val(self));
CAMLreturn(Val_GdkDragAction(result));
}

CAMLexport CAMLprim value ml_gdk_drag_get_formats(value self)
{
CAMLparam1(self);

GdkContentFormats* result = gdk_drag_get_formats(GdkDrag_val(self));
if (result) result = g_boxed_copy(gdk_content_formats_get_type(), result);
CAMLreturn(Val_GdkContentFormats(result));
}

CAMLexport CAMLprim value ml_gdk_drag_get_drag_surface(value self)
{
CAMLparam1(self);

GdkSurface* result = gdk_drag_get_drag_surface(GdkDrag_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkSurface));
}

CAMLexport CAMLprim value ml_gdk_drag_get_display(value self)
{
CAMLparam1(self);

GdkDisplay* result = gdk_drag_get_display(GdkDrag_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkDisplay(result));
}

CAMLexport CAMLprim value ml_gdk_drag_get_device(value self)
{
CAMLparam1(self);

GdkDevice* result = gdk_drag_get_device(GdkDrag_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkDevice(result));
}

CAMLexport CAMLprim value ml_gdk_drag_get_content(value self)
{
CAMLparam1(self);

GdkContentProvider* result = gdk_drag_get_content(GdkDrag_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkContentProvider(result));
}

CAMLexport CAMLprim value ml_gdk_drag_get_actions(value self)
{
CAMLparam1(self);

GdkDragAction result = gdk_drag_get_actions(GdkDrag_val(self));
CAMLreturn(Val_GdkDragAction(result));
}

CAMLexport CAMLprim value ml_gdk_drag_drop_done(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_drag_drop_done(GdkDrag_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gdk_drag_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_drag_get_type()));
}
