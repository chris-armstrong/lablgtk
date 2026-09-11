/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Matrix */

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

#if PANGO_VERSION_CHECK(1,6,0)
/* Copy function for PangoMatrix (value-like record with copy method) */
value copy_PangoMatrix(const PangoMatrix *ptr)
{
  if (ptr == NULL) return Val_none;
  PangoMatrix *copy = g_boxed_copy(pango_matrix_get_type(), ptr);
  return ml_gir_record_val_ptr_with_type(pango_matrix_get_type(), copy);
}
#endif

#if PANGO_VERSION_CHECK(1,6,0)


CAMLexport CAMLprim value ml_pango_matrix_translate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

pango_matrix_translate(PangoMatrix_val(self), Double_val(arg1), Double_val(arg2));
CAMLreturn(Val_unit);
}

#if PANGO_VERSION_CHECK(1,16,0)

CAMLexport CAMLprim value ml_pango_matrix_transform_rectangle(value self, value arg1)
{
CAMLparam2(self, arg1);
PangoRectangle inout1_val = *PangoRectangle_val(arg1);
PangoRectangle *inout1 = &inout1_val;

pango_matrix_transform_rectangle(PangoMatrix_val(self), inout1);
CAMLreturn(Val_PangoRectangle(&inout1));
}

#else

CAMLexport CAMLprim value ml_pango_matrix_transform_rectangle(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Pango >= 1.16");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,16,0)

CAMLexport CAMLprim value ml_pango_matrix_transform_point(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
double inout1 = Double_val(arg1);
double inout2 = Double_val(arg2);

pango_matrix_transform_point(PangoMatrix_val(self), &inout1, &inout2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, caml_copy_double(inout1));
    Store_field(ret, 1, caml_copy_double(inout2));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_pango_matrix_transform_point(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Matrix requires Pango >= 1.16");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,16,0)

CAMLexport CAMLprim value ml_pango_matrix_transform_pixel_rectangle(value self, value arg1)
{
CAMLparam2(self, arg1);
PangoRectangle inout1_val = *PangoRectangle_val(arg1);
PangoRectangle *inout1 = &inout1_val;

pango_matrix_transform_pixel_rectangle(PangoMatrix_val(self), inout1);
CAMLreturn(Val_PangoRectangle(&inout1));
}

#else

CAMLexport CAMLprim value ml_pango_matrix_transform_pixel_rectangle(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Pango >= 1.16");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,16,0)

CAMLexport CAMLprim value ml_pango_matrix_transform_distance(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
double inout1 = Double_val(arg1);
double inout2 = Double_val(arg2);

pango_matrix_transform_distance(PangoMatrix_val(self), &inout1, &inout2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, caml_copy_double(inout1));
    Store_field(ret, 1, caml_copy_double(inout2));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_pango_matrix_transform_distance(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Matrix requires Pango >= 1.16");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_matrix_scale(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

pango_matrix_scale(PangoMatrix_val(self), Double_val(arg1), Double_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_matrix_rotate(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_matrix_rotate(PangoMatrix_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_matrix_get_slant_ratio(value self)
{
CAMLparam1(self);

double result = pango_matrix_get_slant_ratio(PangoMatrix_val(self));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_pango_matrix_get_slant_ratio(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Pango >= 1.50");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,38,0)

CAMLexport CAMLprim value ml_pango_matrix_get_font_scale_factors(value self)
{
CAMLparam1(self);
double out1;
double out2;

pango_matrix_get_font_scale_factors(PangoMatrix_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, caml_copy_double(out1));
    Store_field(ret, 1, caml_copy_double(out2));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_pango_matrix_get_font_scale_factors(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Pango >= 1.38");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,12,0)

CAMLexport CAMLprim value ml_pango_matrix_get_font_scale_factor(value self)
{
CAMLparam1(self);

double result = pango_matrix_get_font_scale_factor(PangoMatrix_val(self));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_pango_matrix_get_font_scale_factor(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Pango >= 1.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_matrix_concat(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_matrix_concat(PangoMatrix_val(self), PangoMatrix_val(arg1));
CAMLreturn(Val_unit);
}


CAMLprim value ml_pango_matrix_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_matrix_get_type()));
}

#else


CAMLexport CAMLprim value ml_pango_matrix_concat(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Pango >= 1.6");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_matrix_get_font_scale_factor(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Pango >= 1.6");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_matrix_get_font_scale_factors(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Pango >= 1.6");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_matrix_get_slant_ratio(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Matrix requires Pango >= 1.6");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_matrix_rotate(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Pango >= 1.6");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_matrix_scale(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Matrix requires Pango >= 1.6");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_matrix_transform_distance(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Matrix requires Pango >= 1.6");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_matrix_transform_pixel_rectangle(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Pango >= 1.6");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_matrix_transform_point(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Matrix requires Pango >= 1.6");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_matrix_transform_rectangle(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Matrix requires Pango >= 1.6");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_matrix_translate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Matrix requires Pango >= 1.6");
return Val_unit;
}


#endif
