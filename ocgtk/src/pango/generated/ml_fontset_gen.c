/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Fontset */

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


CAMLexport CAMLprim value ml_pango_fontset_get_metrics(value self)
{
CAMLparam1(self);

PangoFontMetrics* result = pango_fontset_get_metrics(PangoFontset_val(self));
CAMLreturn(Val_PangoFontMetrics(result));
}

CAMLexport CAMLprim value ml_pango_fontset_get_font(value self, value arg1)
{
CAMLparam2(self, arg1);

PangoFont* result = pango_fontset_get_font(PangoFontset_val(self), Int_val(arg1));
CAMLreturn(Val_PangoFont(result));
}

GType pango_fontset_get_type (void);


CAMLprim value ml_pango_fontset_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_fontset_get_type()));
}
