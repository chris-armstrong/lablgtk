/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FontOptions */

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

/* Conversion functions for cairo_font_options_t (opaque record with hidden fields) */
cairo_font_options_t *cairo_font_options_t_val(value v) {
  return (cairo_font_options_t *)ml_gir_record_ptr_val(v, "cairo_font_options_t");
}

value Val_cairo_font_options_t(const cairo_font_options_t *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(cairo_gobject_font_options_get_type(), ptr);
}

value Val_cairo_font_options_t_option(const cairo_font_options_t *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_cairo_font_options_t(ptr));
}



CAMLprim value ml_cairo_font_options_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(cairo_gobject_font_options_get_type()));
}
