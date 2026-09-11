/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Rectangle */

#include <cairo-gobject.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <cairo-gobject.h>
/* Include library-specific type conversions and forward declarations */
#include "cairo_decls.h"

/* Conversion functions for cairo_rectangle_t (opaque record with hidden fields) */
cairo_rectangle_t *cairo_rectangle_t_val(value v) {
  return (cairo_rectangle_t *)ml_gir_record_ptr_val(v, "cairo_rectangle_t");
}

value Val_cairo_rectangle_t(const cairo_rectangle_t *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(cairo_gobject_rectangle_get_type(), ptr);
}

value Val_cairo_rectangle_t_option(const cairo_rectangle_t *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_cairo_rectangle_t(ptr));
}


GType cairo_gobject_rectangle_get_type (void);


CAMLprim value ml_cairo_rectangle_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(cairo_gobject_rectangle_get_type()));
}
