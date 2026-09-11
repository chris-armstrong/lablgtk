/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ToplevelSize */

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

/* Conversion functions for GdkToplevelSize (opaque record with hidden fields) */
GdkToplevelSize *GdkToplevelSize_val(value v) {
  return (GdkToplevelSize *)ml_gir_record_ptr_val(v, "GdkToplevelSize");
}

value Val_GdkToplevelSize(const GdkToplevelSize *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr(ptr);
}

value Val_GdkToplevelSize_option(const GdkToplevelSize *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GdkToplevelSize(ptr));
}


CAMLexport CAMLprim value ml_gdk_toplevel_size_set_size(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gdk_toplevel_size_set_size(GdkToplevelSize_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_toplevel_size_set_shadow_width(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gdk_toplevel_size_set_shadow_width(GdkToplevelSize_val(self), Int_val(arg1), Int_val(arg2), Int_val(arg3), Int_val(arg4));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_toplevel_size_set_min_size(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gdk_toplevel_size_set_min_size(GdkToplevelSize_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_toplevel_size_get_bounds(value self)
{
CAMLparam1(self);
int out1;
int out2;

gdk_toplevel_size_get_bounds(GdkToplevelSize_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}


CAMLprim value ml_gdk_toplevel_size_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_toplevel_size_get_type()));
}
