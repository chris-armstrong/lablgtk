/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Language */

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

/* Conversion functions for PangoLanguage (opaque record with hidden fields) */
PangoLanguage *PangoLanguage_val(value v) {
  return (PangoLanguage *)ml_gir_record_ptr_val(v, "PangoLanguage");
}

value Val_PangoLanguage(const PangoLanguage *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(pango_language_get_type(), ptr);
}

value Val_PangoLanguage_option(const PangoLanguage *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_PangoLanguage(ptr));
}


CAMLexport CAMLprim value ml_pango_language_to_string(value self)
{
CAMLparam1(self);

const char* result = pango_language_to_string(PangoLanguage_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_pango_language_matches(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = pango_language_matches(PangoLanguage_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

#if PANGO_VERSION_CHECK(1,4,0)

CAMLexport CAMLprim value ml_pango_language_includes_script(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = pango_language_includes_script(PangoLanguage_val(self), PangoScript_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_pango_language_includes_script(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Language requires Pango >= 1.4");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,22,0)

CAMLexport CAMLprim value ml_pango_language_get_scripts(value self)
{
CAMLparam1(self);
int out1;

const PangoScript* result = pango_language_get_scripts(PangoLanguage_val(self), &out1);
    CAMLlocal2(ml_result, ml_result_opt);
    if (result == NULL) {
      ml_result_opt = Val_none;
    } else {
      int result_length = out1;
      ml_result = caml_alloc(result_length, 0);
      for (int i = 0; i < result_length; i++) {
        Store_field(ml_result, i, Val_PangoScript(result[i]));
      }
      ml_result_opt = Val_some(ml_result);
          }
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_result_opt);
    Store_field(ret, 1, Val_int(out1));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_pango_language_get_scripts(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Language requires Pango >= 1.22");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_language_get_sample_string(value self)
{
CAMLparam1(self);

const char* result = pango_language_get_sample_string(PangoLanguage_val(self));
CAMLreturn(caml_copy_string(result));
}


CAMLprim value ml_pango_language_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_language_get_type()));
}
