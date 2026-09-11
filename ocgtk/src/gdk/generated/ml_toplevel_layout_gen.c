/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ToplevelLayout */

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

/* Conversion functions for GdkToplevelLayout (opaque record with hidden fields) */
GdkToplevelLayout *GdkToplevelLayout_val(value v) {
  return (GdkToplevelLayout *)ml_gir_record_ptr_val(v, "GdkToplevelLayout");
}

value Val_GdkToplevelLayout(const GdkToplevelLayout *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gdk_toplevel_layout_get_type(), ptr);
}

value Val_GdkToplevelLayout_option(const GdkToplevelLayout *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GdkToplevelLayout(ptr));
}


CAMLexport CAMLprim value ml_gdk_toplevel_layout_new(value unit)
{
CAMLparam1(unit);

GdkToplevelLayout *obj = gdk_toplevel_layout_new();

CAMLreturn(Val_GdkToplevelLayout(obj));
}
CAMLexport CAMLprim value ml_gdk_toplevel_layout_set_resizable(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_toplevel_layout_set_resizable(GdkToplevelLayout_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_toplevel_layout_set_maximized(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_toplevel_layout_set_maximized(GdkToplevelLayout_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_toplevel_layout_set_fullscreen(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gdk_toplevel_layout_set_fullscreen(GdkToplevelLayout_val(self), Bool_val(arg1), Option_val(arg2, GdkMonitor_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_toplevel_layout_ref(value self)
{
CAMLparam1(self);

GdkToplevelLayout* result = gdk_toplevel_layout_ref(GdkToplevelLayout_val(self));
CAMLreturn(Val_GdkToplevelLayout(result));
}

CAMLexport CAMLprim value ml_gdk_toplevel_layout_get_resizable(value self)
{
CAMLparam1(self);

gboolean result = gdk_toplevel_layout_get_resizable(GdkToplevelLayout_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_toplevel_layout_get_maximized(value self)
{
CAMLparam1(self);
gboolean out1;

gboolean result = gdk_toplevel_layout_get_maximized(GdkToplevelLayout_val(self), &out1);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_bool(out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gdk_toplevel_layout_get_fullscreen_monitor(value self)
{
CAMLparam1(self);

GdkMonitor* result = gdk_toplevel_layout_get_fullscreen_monitor(GdkToplevelLayout_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkMonitor));
}

CAMLexport CAMLprim value ml_gdk_toplevel_layout_get_fullscreen(value self)
{
CAMLparam1(self);
gboolean out1;

gboolean result = gdk_toplevel_layout_get_fullscreen(GdkToplevelLayout_val(self), &out1);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_bool(out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gdk_toplevel_layout_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gdk_toplevel_layout_equal(GdkToplevelLayout_val(self), GdkToplevelLayout_val(arg1));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_gdk_toplevel_layout_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_toplevel_layout_get_type()));
}
