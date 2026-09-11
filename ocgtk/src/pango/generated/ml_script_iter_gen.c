/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ScriptIter */

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

/* Conversion functions for PangoScriptIter (opaque record with hidden fields) */
PangoScriptIter *PangoScriptIter_val(value v) {
  return (PangoScriptIter *)ml_gir_record_ptr_val(v, "PangoScriptIter");
}

value Val_PangoScriptIter(const PangoScriptIter *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(pango_script_iter_get_type(), ptr);
}

value Val_PangoScriptIter_option(const PangoScriptIter *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_PangoScriptIter(ptr));
}


#if PANGO_VERSION_CHECK(1,4,0)

CAMLexport CAMLprim value ml_pango_script_iter_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

PangoScriptIter *obj = pango_script_iter_new(String_val(arg1), Int_val(arg2));

CAMLreturn(Val_PangoScriptIter(obj));
}
#else

CAMLexport CAMLprim value ml_pango_script_iter_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("ScriptIter requires Pango >= 1.4");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,4,0)

CAMLexport CAMLprim value ml_pango_script_iter_next(value self)
{
CAMLparam1(self);

gboolean result = pango_script_iter_next(PangoScriptIter_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_pango_script_iter_next(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ScriptIter requires Pango >= 1.4");
return Val_unit;
}
#endif


CAMLprim value ml_pango_script_iter_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_script_iter_get_type()));
}
