/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FontsetSimple */

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


CAMLexport CAMLprim value ml_pango_fontset_simple_new(value arg1)
{
CAMLparam1(arg1);

PangoFontsetSimple *obj = pango_fontset_simple_new(PangoLanguage_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_PangoFontsetSimple(obj));
}
CAMLexport CAMLprim value ml_pango_fontset_simple_size(value self)
{
CAMLparam1(self);

int result = pango_fontset_simple_size(PangoFontsetSimple_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_pango_fontset_simple_append(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_fontset_simple_append(PangoFontsetSimple_val(self), PangoFont_val(arg1));
CAMLreturn(Val_unit);
}


CAMLprim value ml_pango_fontset_simple_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_fontset_simple_get_type()));
}
