/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Color */

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

/* Copy function for PangoColor (value-like record with copy method) */
value copy_PangoColor(const PangoColor *ptr)
{
  if (ptr == NULL) return Val_none;
  PangoColor *copy = g_boxed_copy(pango_color_get_type(), ptr);
  return ml_gir_record_val_ptr_with_type(pango_color_get_type(), copy);
}


#if PANGO_VERSION_CHECK(1,16,0)

CAMLexport CAMLprim value ml_pango_color_to_string(value self)
{
CAMLparam1(self);

char* result = pango_color_to_string(PangoColor_val(self));
CAMLreturn(caml_copy_string(result));
}

#else

CAMLexport CAMLprim value ml_pango_color_to_string(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Color requires Pango >= 1.16");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,46,0)

CAMLexport CAMLprim value ml_pango_color_parse_with_alpha(value self, value arg1)
{
CAMLparam2(self, arg1);
guint16 out1;

gboolean result = pango_color_parse_with_alpha(PangoColor_val(self), &out1, String_val(arg1));
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_uint16(out1));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_pango_color_parse_with_alpha(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Color requires Pango >= 1.46");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_color_parse(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = pango_color_parse(PangoColor_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_pango_color_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_color_get_type()));
}
