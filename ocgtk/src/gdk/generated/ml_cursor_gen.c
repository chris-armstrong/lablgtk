/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Cursor */

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


CAMLexport CAMLprim value ml_gdk_cursor_new_from_name(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GdkCursor *obj = gdk_cursor_new_from_name(String_val(arg1), Option_val(arg2, GdkCursor_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GdkCursor(obj));
}
CAMLexport CAMLprim value ml_gdk_cursor_new_from_texture(value arg1, value arg2, value arg3, value arg4)
{
CAMLparam4(arg1, arg2, arg3, arg4);

GdkCursor *obj = gdk_cursor_new_from_texture(GdkTexture_val(arg1), Int_val(arg2), Int_val(arg3), Option_val(arg4, GdkCursor_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GdkCursor(obj));
}
CAMLexport CAMLprim value ml_gdk_cursor_get_texture(value self)
{
CAMLparam1(self);

GdkTexture* result = gdk_cursor_get_texture(GdkCursor_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkTexture));
}

CAMLexport CAMLprim value ml_gdk_cursor_get_name(value self)
{
CAMLparam1(self);

const char* result = gdk_cursor_get_name(GdkCursor_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gdk_cursor_get_hotspot_y(value self)
{
CAMLparam1(self);

int result = gdk_cursor_get_hotspot_y(GdkCursor_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_cursor_get_hotspot_x(value self)
{
CAMLparam1(self);

int result = gdk_cursor_get_hotspot_x(GdkCursor_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_cursor_get_fallback(value self)
{
CAMLparam1(self);

GdkCursor* result = gdk_cursor_get_fallback(GdkCursor_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkCursor));
}


CAMLprim value ml_gdk_cursor_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_cursor_get_type()));
}
