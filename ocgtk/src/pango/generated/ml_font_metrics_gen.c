/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FontMetrics */

#include <pango/pango.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <pango/pango.h>
/* Include library-specific type conversions and forward declarations */
#include "pango_decls.h"

/* Conversion functions for PangoFontMetrics (opaque record with hidden fields) */
PangoFontMetrics *PangoFontMetrics_val(value v) {
  return (PangoFontMetrics *)ml_gir_record_ptr_val(v, "PangoFontMetrics");
}

value Val_PangoFontMetrics(const PangoFontMetrics *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(pango_font_metrics_get_type(), ptr);
}

value Val_PangoFontMetrics_option(const PangoFontMetrics *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_PangoFontMetrics(ptr));
}


CAMLexport CAMLprim value ml_pango_font_metrics_ref(value self)
{
CAMLparam1(self);

PangoFontMetrics* result = pango_font_metrics_ref(PangoFontMetrics_val(self));
CAMLreturn(Val_option(result, Val_PangoFontMetrics));
}

#if PANGO_VERSION_CHECK(1,6,0)

CAMLexport CAMLprim value ml_pango_font_metrics_get_underline_thickness(value self)
{
CAMLparam1(self);

int result = pango_font_metrics_get_underline_thickness(PangoFontMetrics_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_pango_font_metrics_get_underline_thickness(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontMetrics requires Pango >= 1.6");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,6,0)

CAMLexport CAMLprim value ml_pango_font_metrics_get_underline_position(value self)
{
CAMLparam1(self);

int result = pango_font_metrics_get_underline_position(PangoFontMetrics_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_pango_font_metrics_get_underline_position(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontMetrics requires Pango >= 1.6");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,6,0)

CAMLexport CAMLprim value ml_pango_font_metrics_get_strikethrough_thickness(value self)
{
CAMLparam1(self);

int result = pango_font_metrics_get_strikethrough_thickness(PangoFontMetrics_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_pango_font_metrics_get_strikethrough_thickness(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontMetrics requires Pango >= 1.6");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,6,0)

CAMLexport CAMLprim value ml_pango_font_metrics_get_strikethrough_position(value self)
{
CAMLparam1(self);

int result = pango_font_metrics_get_strikethrough_position(PangoFontMetrics_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_pango_font_metrics_get_strikethrough_position(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontMetrics requires Pango >= 1.6");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,44,0)

CAMLexport CAMLprim value ml_pango_font_metrics_get_height(value self)
{
CAMLparam1(self);

int result = pango_font_metrics_get_height(PangoFontMetrics_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_pango_font_metrics_get_height(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontMetrics requires Pango >= 1.44");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_font_metrics_get_descent(value self)
{
CAMLparam1(self);

int result = pango_font_metrics_get_descent(PangoFontMetrics_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_pango_font_metrics_get_ascent(value self)
{
CAMLparam1(self);

int result = pango_font_metrics_get_ascent(PangoFontMetrics_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_pango_font_metrics_get_approximate_digit_width(value self)
{
CAMLparam1(self);

int result = pango_font_metrics_get_approximate_digit_width(PangoFontMetrics_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_pango_font_metrics_get_approximate_char_width(value self)
{
CAMLparam1(self);

int result = pango_font_metrics_get_approximate_char_width(PangoFontMetrics_val(self));
CAMLreturn(Val_int(result));
}


CAMLprim value ml_pango_font_metrics_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_font_metrics_get_type()));
}
