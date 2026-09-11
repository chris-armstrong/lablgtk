/* GENERATED CODE - DO NOT EDIT */
/* C bindings for LayoutLine */

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

/* Conversion functions for PangoLayoutLine (opaque record with hidden fields) */
PangoLayoutLine *PangoLayoutLine_val(value v) {
  return (PangoLayoutLine *)ml_gir_record_ptr_val(v, "PangoLayoutLine");
}

value Val_PangoLayoutLine(const PangoLayoutLine *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(pango_layout_line_get_type(), ptr);
}

value Val_PangoLayoutLine_option(const PangoLayoutLine *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_PangoLayoutLine(ptr));
}


CAMLexport CAMLprim value ml_pango_layout_line_x_to_index(value self, value arg1)
{
CAMLparam2(self, arg1);
int out2;
int out3;

gboolean result = pango_layout_line_x_to_index(PangoLayoutLine_val(self), Int_val(arg1), &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_int(out2));
    Store_field(ret, 2, Val_int(out3));
    CAMLreturn(ret);
}

#if PANGO_VERSION_CHECK(1,10,0)

CAMLexport CAMLprim value ml_pango_layout_line_ref(value self)
{
CAMLparam1(self);

PangoLayoutLine* result = pango_layout_line_ref(PangoLayoutLine_val(self));
CAMLreturn(Val_option(result, Val_PangoLayoutLine));
}

#else

CAMLexport CAMLprim value ml_pango_layout_line_ref(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("LayoutLine requires Pango >= 1.10");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_layout_line_is_paragraph_start(value self)
{
CAMLparam1(self);

gboolean result = pango_layout_line_is_paragraph_start(PangoLayoutLine_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_pango_layout_line_is_paragraph_start(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("LayoutLine requires Pango >= 1.50");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_layout_line_index_to_x(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
int out3;

pango_layout_line_index_to_x(PangoLayoutLine_val(self), Int_val(arg1), Bool_val(arg2), &out3);
CAMLreturn(Val_int(out3));
}

CAMLexport CAMLprim value ml_pango_layout_line_get_x_ranges(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
int* out3 = NULL;
int out4;

pango_layout_line_get_x_ranges(PangoLayoutLine_val(self), Int_val(arg1), Int_val(arg2), &out3, &out4);
    int out3_length = out4;
    CAMLlocal1(ml_out3);
    ml_out3 = caml_alloc(out3_length, 0);
    for (int i = 0; i < out3_length; i++) {
      Store_field(ml_out3, i, Val_int(out3[i]));
    }

    g_free(out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_out3);
    Store_field(ret, 1, Val_int(out4));
    CAMLreturn(ret);
}

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_layout_line_get_start_index(value self)
{
CAMLparam1(self);

int result = pango_layout_line_get_start_index(PangoLayoutLine_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_pango_layout_line_get_start_index(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("LayoutLine requires Pango >= 1.50");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_layout_line_get_resolved_direction(value self)
{
CAMLparam1(self);

PangoDirection result = pango_layout_line_get_resolved_direction(PangoLayoutLine_val(self));
CAMLreturn(Val_PangoDirection(result));
}

#else

CAMLexport CAMLprim value ml_pango_layout_line_get_resolved_direction(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("LayoutLine requires Pango >= 1.50");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_layout_line_get_pixel_extents(value self)
{
CAMLparam1(self);
PangoRectangle out1;
PangoRectangle out2;

pango_layout_line_get_pixel_extents(PangoLayoutLine_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_PangoRectangle(&out1));
    Store_field(ret, 1, Val_PangoRectangle(&out2));
    CAMLreturn(ret);
}

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_layout_line_get_length(value self)
{
CAMLparam1(self);

int result = pango_layout_line_get_length(PangoLayoutLine_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_pango_layout_line_get_length(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("LayoutLine requires Pango >= 1.50");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,44,0)

CAMLexport CAMLprim value ml_pango_layout_line_get_height(value self)
{
CAMLparam1(self);
int out1;

pango_layout_line_get_height(PangoLayoutLine_val(self), &out1);
CAMLreturn(Val_int(out1));
}

#else

CAMLexport CAMLprim value ml_pango_layout_line_get_height(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("LayoutLine requires Pango >= 1.44");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_layout_line_get_extents(value self)
{
CAMLparam1(self);
PangoRectangle out1;
PangoRectangle out2;

pango_layout_line_get_extents(PangoLayoutLine_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_PangoRectangle(&out1));
    Store_field(ret, 1, Val_PangoRectangle(&out2));
    CAMLreturn(ret);
}

GType pango_layout_line_get_type (void);


CAMLprim value ml_pango_layout_line_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_layout_line_get_type()));
}
