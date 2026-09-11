/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DrawContext */

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


CAMLexport CAMLprim value ml_gdk_draw_context_is_in_frame(value self)
{
CAMLparam1(self);

gboolean result = gdk_draw_context_is_in_frame(GdkDrawContext_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_draw_context_get_surface(value self)
{
CAMLparam1(self);

GdkSurface* result = gdk_draw_context_get_surface(GdkDrawContext_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkSurface));
}

CAMLexport CAMLprim value ml_gdk_draw_context_get_frame_region(value self)
{
CAMLparam1(self);

const cairo_region_t* result = gdk_draw_context_get_frame_region(GdkDrawContext_val(self));
if (result) result = g_boxed_copy(cairo_gobject_region_get_type(), result);
CAMLreturn(Val_option(result, Val_cairo_region_t));
}

CAMLexport CAMLprim value ml_gdk_draw_context_get_display(value self)
{
CAMLparam1(self);

GdkDisplay* result = gdk_draw_context_get_display(GdkDrawContext_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkDisplay));
}

CAMLexport CAMLprim value ml_gdk_draw_context_end_frame(value self)
{
CAMLparam1(self);

gdk_draw_context_end_frame(GdkDrawContext_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_draw_context_begin_frame(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_draw_context_begin_frame(GdkDrawContext_val(self), cairo_region_t_val(arg1));
CAMLreturn(Val_unit);
}

GType gdk_draw_context_get_type (void);


CAMLprim value ml_gdk_draw_context_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_draw_context_get_type()));
}
