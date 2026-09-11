/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TabArray */

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

/* Conversion functions for PangoTabArray (opaque record with hidden fields) */
PangoTabArray *PangoTabArray_val(value v) {
  return (PangoTabArray *)ml_gir_record_ptr_val(v, "PangoTabArray");
}

value Val_PangoTabArray(const PangoTabArray *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(pango_tab_array_get_type(), ptr);
}

value Val_PangoTabArray_option(const PangoTabArray *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_PangoTabArray(ptr));
}


CAMLexport CAMLprim value ml_pango_tab_array_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

PangoTabArray *obj = pango_tab_array_new(Int_val(arg1), Bool_val(arg2));

CAMLreturn(Val_PangoTabArray(obj));
}
#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_tab_array_to_string(value self)
{
CAMLparam1(self);

char* result = pango_tab_array_to_string(PangoTabArray_val(self));
CAMLreturn(caml_copy_string(result));
}

#else

CAMLexport CAMLprim value ml_pango_tab_array_to_string(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TabArray requires Pango >= 1.50");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_tab_array_sort(value self)
{
CAMLparam1(self);

pango_tab_array_sort(PangoTabArray_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_tab_array_sort(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TabArray requires Pango >= 1.50");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_tab_array_set_tab(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

pango_tab_array_set_tab(PangoTabArray_val(self), Int_val(arg1), PangoTabAlign_val(arg2), Int_val(arg3));
CAMLreturn(Val_unit);
}

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_tab_array_set_positions_in_pixels(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_tab_array_set_positions_in_pixels(PangoTabArray_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_tab_array_set_positions_in_pixels(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TabArray requires Pango >= 1.50");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_tab_array_set_decimal_point(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

pango_tab_array_set_decimal_point(PangoTabArray_val(self), Int_val(arg1), Long_val(arg2));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_tab_array_set_decimal_point(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("TabArray requires Pango >= 1.50");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_tab_array_resize(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_tab_array_resize(PangoTabArray_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_tab_array_get_tab(value self, value arg1)
{
CAMLparam2(self, arg1);
PangoTabAlign out2;
gint out3;

pango_tab_array_get_tab(PangoTabArray_val(self), Int_val(arg1), &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_PangoTabAlign(out2));
    Store_field(ret, 1, Val_int(out3));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_pango_tab_array_get_size(value self)
{
CAMLparam1(self);

gint result = pango_tab_array_get_size(PangoTabArray_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_pango_tab_array_get_positions_in_pixels(value self)
{
CAMLparam1(self);

gboolean result = pango_tab_array_get_positions_in_pixels(PangoTabArray_val(self));
CAMLreturn(Val_bool(result));
}

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_tab_array_get_decimal_point(value self, value arg1)
{
CAMLparam2(self, arg1);

gunichar result = pango_tab_array_get_decimal_point(PangoTabArray_val(self), Int_val(arg1));
CAMLreturn(Val_long(result));
}

#else

CAMLexport CAMLprim value ml_pango_tab_array_get_decimal_point(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TabArray requires Pango >= 1.50");
return Val_unit;
}
#endif


CAMLprim value ml_pango_tab_array_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_tab_array_get_type()));
}
