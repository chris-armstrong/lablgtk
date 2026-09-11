/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Coverage */

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


CAMLexport CAMLprim value ml_pango_coverage_new(value unit)
{
CAMLparam1(unit);

PangoCoverage *obj = pango_coverage_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_PangoCoverage(obj));
}
CAMLexport CAMLprim value ml_pango_coverage_unref(value self)
{
CAMLparam1(self);

pango_coverage_unref(PangoCoverage_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_coverage_set(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

pango_coverage_set(PangoCoverage_val(self), Int_val(arg1), PangoCoverageLevel_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_coverage_ref(value self)
{
CAMLparam1(self);

PangoCoverage* result = pango_coverage_ref(PangoCoverage_val(self));
CAMLreturn(Val_PangoCoverage(result));
}

CAMLexport CAMLprim value ml_pango_coverage_max(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_coverage_max(PangoCoverage_val(self), PangoCoverage_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_coverage_get(value self, value arg1)
{
CAMLparam2(self, arg1);

PangoCoverageLevel result = pango_coverage_get(PangoCoverage_val(self), Int_val(arg1));
CAMLreturn(Val_PangoCoverageLevel(result));
}

CAMLexport CAMLprim value ml_pango_coverage_copy(value self)
{
CAMLparam1(self);

PangoCoverage* result = pango_coverage_copy(PangoCoverage_val(self));
CAMLreturn(Val_PangoCoverage(result));
}


CAMLprim value ml_pango_coverage_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_coverage_get_type()));
}
