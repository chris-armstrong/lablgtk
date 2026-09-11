/* GENERATED CODE - DO NOT EDIT */
/* C bindings for LayoutIter */

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

/* Conversion functions for PangoLayoutIter (opaque record with hidden fields) */
PangoLayoutIter *PangoLayoutIter_val(value v) {
  return (PangoLayoutIter *)ml_gir_record_ptr_val(v, "PangoLayoutIter");
}

value Val_PangoLayoutIter(const PangoLayoutIter *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(pango_layout_iter_get_type(), ptr);
}

value Val_PangoLayoutIter_option(const PangoLayoutIter *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_PangoLayoutIter(ptr));
}


CAMLexport CAMLprim value ml_pango_layout_iter_next_run(value self)
{
CAMLparam1(self);

gboolean result = pango_layout_iter_next_run(PangoLayoutIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_pango_layout_iter_next_line(value self)
{
CAMLparam1(self);

gboolean result = pango_layout_iter_next_line(PangoLayoutIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_pango_layout_iter_next_cluster(value self)
{
CAMLparam1(self);

gboolean result = pango_layout_iter_next_cluster(PangoLayoutIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_pango_layout_iter_next_char(value self)
{
CAMLparam1(self);

gboolean result = pango_layout_iter_next_char(PangoLayoutIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_pango_layout_iter_get_run_extents(value self)
{
CAMLparam1(self);
PangoRectangle out1;
PangoRectangle out2;

pango_layout_iter_get_run_extents(PangoLayoutIter_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_PangoRectangle(&out1));
    Store_field(ret, 1, Val_PangoRectangle(&out2));
    CAMLreturn(ret);
}

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_layout_iter_get_run_baseline(value self)
{
CAMLparam1(self);

int result = pango_layout_iter_get_run_baseline(PangoLayoutIter_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_pango_layout_iter_get_run_baseline(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("LayoutIter requires Pango >= 1.50");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_layout_iter_get_line_yrange(value self)
{
CAMLparam1(self);
int out1;
int out2;

pango_layout_iter_get_line_yrange(PangoLayoutIter_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

#if PANGO_VERSION_CHECK(1,16,0)

CAMLexport CAMLprim value ml_pango_layout_iter_get_line_readonly(value self)
{
CAMLparam1(self);

PangoLayoutLine* result = pango_layout_iter_get_line_readonly(PangoLayoutIter_val(self));
if (result) result = g_boxed_copy(pango_layout_line_get_type(), result);
CAMLreturn(Val_option(result, Val_PangoLayoutLine));
}

#else

CAMLexport CAMLprim value ml_pango_layout_iter_get_line_readonly(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("LayoutIter requires Pango >= 1.16");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_layout_iter_get_line_extents(value self)
{
CAMLparam1(self);
PangoRectangle out1;
PangoRectangle out2;

pango_layout_iter_get_line_extents(PangoLayoutIter_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_PangoRectangle(&out1));
    Store_field(ret, 1, Val_PangoRectangle(&out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_pango_layout_iter_get_line(value self)
{
CAMLparam1(self);

PangoLayoutLine* result = pango_layout_iter_get_line(PangoLayoutIter_val(self));
if (result) result = g_boxed_copy(pango_layout_line_get_type(), result);
CAMLreturn(Val_option(result, Val_PangoLayoutLine));
}

CAMLexport CAMLprim value ml_pango_layout_iter_get_layout_extents(value self)
{
CAMLparam1(self);
PangoRectangle out1;
PangoRectangle out2;

pango_layout_iter_get_layout_extents(PangoLayoutIter_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_PangoRectangle(&out1));
    Store_field(ret, 1, Val_PangoRectangle(&out2));
    CAMLreturn(ret);
}

#if PANGO_VERSION_CHECK(1,20,0)

CAMLexport CAMLprim value ml_pango_layout_iter_get_layout(value self)
{
CAMLparam1(self);

PangoLayout* result = pango_layout_iter_get_layout(PangoLayoutIter_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_PangoLayout));
}

#else

CAMLexport CAMLprim value ml_pango_layout_iter_get_layout(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("LayoutIter requires Pango >= 1.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_layout_iter_get_index(value self)
{
CAMLparam1(self);

int result = pango_layout_iter_get_index(PangoLayoutIter_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_pango_layout_iter_get_cluster_extents(value self)
{
CAMLparam1(self);
PangoRectangle out1;
PangoRectangle out2;

pango_layout_iter_get_cluster_extents(PangoLayoutIter_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_PangoRectangle(&out1));
    Store_field(ret, 1, Val_PangoRectangle(&out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_pango_layout_iter_get_char_extents(value self)
{
CAMLparam1(self);
PangoRectangle out1;

pango_layout_iter_get_char_extents(PangoLayoutIter_val(self), &out1);
CAMLreturn(Val_PangoRectangle(&out1));
}

CAMLexport CAMLprim value ml_pango_layout_iter_get_baseline(value self)
{
CAMLparam1(self);

int result = pango_layout_iter_get_baseline(PangoLayoutIter_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_pango_layout_iter_at_last_line(value self)
{
CAMLparam1(self);

gboolean result = pango_layout_iter_at_last_line(PangoLayoutIter_val(self));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_pango_layout_iter_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_layout_iter_get_type()));
}
