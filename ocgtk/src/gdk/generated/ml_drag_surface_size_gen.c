/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DragSurfaceSize */

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

#if GTK_CHECK_VERSION(4,12,0)
/* Conversion functions for GdkDragSurfaceSize (opaque record with hidden fields) */
GdkDragSurfaceSize *GdkDragSurfaceSize_val(value v) {
  return (GdkDragSurfaceSize *)ml_gir_record_ptr_val(v, "GdkDragSurfaceSize");
}

value Val_GdkDragSurfaceSize(const GdkDragSurfaceSize *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr(ptr);
}

value Val_GdkDragSurfaceSize_option(const GdkDragSurfaceSize *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GdkDragSurfaceSize(ptr));
}
#endif

#if GTK_CHECK_VERSION(4,12,0)


CAMLexport CAMLprim value ml_gdk_drag_surface_size_set_size(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gdk_drag_surface_size_set_size(GdkDragSurfaceSize_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

GType gdk_drag_surface_size_get_type (void);


CAMLprim value ml_gdk_drag_surface_size_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_drag_surface_size_get_type()));
}

#else


CAMLexport CAMLprim value ml_gdk_drag_surface_size_set_size(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("DragSurfaceSize requires GTK >= 4.12");
return Val_unit;
}


#endif
