/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Font */

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


#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_font_serialize(value self)
{
CAMLparam1(self);

GBytes* result = pango_font_serialize(PangoFont_val(self));
CAMLreturn(Val_GBytes(result));
}

#else

CAMLexport CAMLprim value ml_pango_font_serialize(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Font requires Pango >= 1.50");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,44,0)

CAMLexport CAMLprim value ml_pango_font_has_char(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = pango_font_has_char(PangoFont_val(self), Long_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_pango_font_has_char(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Font requires Pango >= 1.44");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_font_get_metrics(value self, value arg1)
{
CAMLparam2(self, arg1);

PangoFontMetrics* result = pango_font_get_metrics(PangoFont_val(self), Option_val(arg1, PangoLanguage_val, NULL));
CAMLreturn(Val_PangoFontMetrics(result));
}

CAMLexport CAMLprim value ml_pango_font_get_glyph_extents(value self, value arg1)
{
CAMLparam2(self, arg1);
PangoRectangle out2;
PangoRectangle out3;

pango_font_get_glyph_extents(PangoFont_val(self), Int_val(arg1), &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_PangoRectangle(&out2));
    Store_field(ret, 1, Val_PangoRectangle(&out3));
    CAMLreturn(ret);
}

#if PANGO_VERSION_CHECK(1,10,0)

CAMLexport CAMLprim value ml_pango_font_get_font_map(value self)
{
CAMLparam1(self);

PangoFontMap* result = pango_font_get_font_map(PangoFont_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_PangoFontMap));
}

#else

CAMLexport CAMLprim value ml_pango_font_get_font_map(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Font requires Pango >= 1.10");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,46,0)

CAMLexport CAMLprim value ml_pango_font_get_face(value self)
{
CAMLparam1(self);

PangoFontFace* result = pango_font_get_face(PangoFont_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_PangoFontFace));
}

#else

CAMLexport CAMLprim value ml_pango_font_get_face(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Font requires Pango >= 1.46");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_font_get_coverage(value self, value arg1)
{
CAMLparam2(self, arg1);

PangoCoverage* result = pango_font_get_coverage(PangoFont_val(self), PangoLanguage_val(arg1));
CAMLreturn(Val_PangoCoverage(result));
}

#if PANGO_VERSION_CHECK(1,14,0)

CAMLexport CAMLprim value ml_pango_font_describe_with_absolute_size(value self)
{
CAMLparam1(self);

PangoFontDescription* result = pango_font_describe_with_absolute_size(PangoFont_val(self));
CAMLreturn(Val_PangoFontDescription(result));
}

#else

CAMLexport CAMLprim value ml_pango_font_describe_with_absolute_size(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Font requires Pango >= 1.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_font_describe(value self)
{
CAMLparam1(self);

PangoFontDescription* result = pango_font_describe(PangoFont_val(self));
CAMLreturn(Val_PangoFontDescription(result));
}


CAMLprim value ml_pango_font_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_font_get_type()));
}
