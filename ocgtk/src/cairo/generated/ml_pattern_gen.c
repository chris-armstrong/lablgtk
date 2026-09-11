/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Pattern */

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

/* Conversion functions for cairo_pattern_t (opaque record with hidden fields) */
cairo_pattern_t *cairo_pattern_t_val(value v) {
  return (cairo_pattern_t *)ml_gir_record_ptr_val(v, "cairo_pattern_t");
}

value Val_cairo_pattern_t(const cairo_pattern_t *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(cairo_gobject_pattern_get_type(), ptr);
}

value Val_cairo_pattern_t_option(const cairo_pattern_t *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_cairo_pattern_t(ptr));
}



CAMLprim value ml_cairo_pattern_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(cairo_gobject_pattern_get_type()));
}
