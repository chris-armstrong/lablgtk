/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FontDescription */

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

/* Conversion functions for PangoFontDescription (opaque record with hidden fields) */
PangoFontDescription *PangoFontDescription_val(value v) {
  return (PangoFontDescription *)ml_gir_record_ptr_val(v, "PangoFontDescription");
}

value Val_PangoFontDescription(const PangoFontDescription *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(pango_font_description_get_type(), ptr);
}

value Val_PangoFontDescription_option(const PangoFontDescription *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_PangoFontDescription(ptr));
}


CAMLexport CAMLprim value ml_pango_font_description_new(value unit)
{
CAMLparam1(unit);

PangoFontDescription *obj = pango_font_description_new();

CAMLreturn(Val_PangoFontDescription(obj));
}
CAMLexport CAMLprim value ml_pango_font_description_unset_fields(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_font_description_unset_fields(PangoFontDescription_val(self), PangoFontMask_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_font_description_to_string(value self)
{
CAMLparam1(self);

char* result = pango_font_description_to_string(PangoFontDescription_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_pango_font_description_to_filename(value self)
{
CAMLparam1(self);

char* result = pango_font_description_to_filename(PangoFontDescription_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_pango_font_description_set_weight(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_font_description_set_weight(PangoFontDescription_val(self), PangoWeight_val(arg1));
CAMLreturn(Val_unit);
}

#if PANGO_VERSION_CHECK(1,42,0)

CAMLexport CAMLprim value ml_pango_font_description_set_variations_static(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_font_description_set_variations_static(PangoFontDescription_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_font_description_set_variations_static(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDescription requires Pango >= 1.42");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,42,0)

CAMLexport CAMLprim value ml_pango_font_description_set_variations(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_font_description_set_variations(PangoFontDescription_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_font_description_set_variations(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDescription requires Pango >= 1.42");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_font_description_set_variant(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_font_description_set_variant(PangoFontDescription_val(self), PangoVariant_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_font_description_set_style(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_font_description_set_style(PangoFontDescription_val(self), PangoStyle_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_font_description_set_stretch(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_font_description_set_stretch(PangoFontDescription_val(self), PangoStretch_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_font_description_set_size(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_font_description_set_size(PangoFontDescription_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#if PANGO_VERSION_CHECK(1,16,0)

CAMLexport CAMLprim value ml_pango_font_description_set_gravity(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_font_description_set_gravity(PangoFontDescription_val(self), PangoGravity_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_font_description_set_gravity(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDescription requires Pango >= 1.16");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,56,0)

CAMLexport CAMLprim value ml_pango_font_description_set_features_static(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_font_description_set_features_static(PangoFontDescription_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_font_description_set_features_static(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDescription requires Pango >= 1.56");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,56,0)

CAMLexport CAMLprim value ml_pango_font_description_set_features(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_font_description_set_features(PangoFontDescription_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_font_description_set_features(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDescription requires Pango >= 1.56");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_font_description_set_family_static(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_font_description_set_family_static(PangoFontDescription_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_font_description_set_family(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_font_description_set_family(PangoFontDescription_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#if PANGO_VERSION_CHECK(1,57,0)

CAMLexport CAMLprim value ml_pango_font_description_set_color(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_font_description_set_color(PangoFontDescription_val(self), PangoFontColor_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_font_description_set_color(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDescription requires Pango >= 1.57");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,8,0)

CAMLexport CAMLprim value ml_pango_font_description_set_absolute_size(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_font_description_set_absolute_size(PangoFontDescription_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_font_description_set_absolute_size(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDescription requires Pango >= 1.8");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_font_description_merge_static(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

pango_font_description_merge_static(PangoFontDescription_val(self), PangoFontDescription_val(arg1), Bool_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_font_description_merge(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

pango_font_description_merge(PangoFontDescription_val(self), Option_val(arg1, PangoFontDescription_val, NULL), Bool_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_font_description_hash(value self)
{
CAMLparam1(self);

guint result = pango_font_description_hash(PangoFontDescription_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_pango_font_description_get_weight(value self)
{
CAMLparam1(self);

PangoWeight result = pango_font_description_get_weight(PangoFontDescription_val(self));
CAMLreturn(Val_PangoWeight(result));
}

#if PANGO_VERSION_CHECK(1,42,0)

CAMLexport CAMLprim value ml_pango_font_description_get_variations(value self)
{
CAMLparam1(self);

const char* result = pango_font_description_get_variations(PangoFontDescription_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_pango_font_description_get_variations(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontDescription requires Pango >= 1.42");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_font_description_get_variant(value self)
{
CAMLparam1(self);

PangoVariant result = pango_font_description_get_variant(PangoFontDescription_val(self));
CAMLreturn(Val_PangoVariant(result));
}

CAMLexport CAMLprim value ml_pango_font_description_get_style(value self)
{
CAMLparam1(self);

PangoStyle result = pango_font_description_get_style(PangoFontDescription_val(self));
CAMLreturn(Val_PangoStyle(result));
}

CAMLexport CAMLprim value ml_pango_font_description_get_stretch(value self)
{
CAMLparam1(self);

PangoStretch result = pango_font_description_get_stretch(PangoFontDescription_val(self));
CAMLreturn(Val_PangoStretch(result));
}

#if PANGO_VERSION_CHECK(1,8,0)

CAMLexport CAMLprim value ml_pango_font_description_get_size_is_absolute(value self)
{
CAMLparam1(self);

gboolean result = pango_font_description_get_size_is_absolute(PangoFontDescription_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_pango_font_description_get_size_is_absolute(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontDescription requires Pango >= 1.8");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_font_description_get_size(value self)
{
CAMLparam1(self);

gint result = pango_font_description_get_size(PangoFontDescription_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_pango_font_description_get_set_fields(value self)
{
CAMLparam1(self);

PangoFontMask result = pango_font_description_get_set_fields(PangoFontDescription_val(self));
CAMLreturn(Val_PangoFontMask(result));
}

#if PANGO_VERSION_CHECK(1,16,0)

CAMLexport CAMLprim value ml_pango_font_description_get_gravity(value self)
{
CAMLparam1(self);

PangoGravity result = pango_font_description_get_gravity(PangoFontDescription_val(self));
CAMLreturn(Val_PangoGravity(result));
}

#else

CAMLexport CAMLprim value ml_pango_font_description_get_gravity(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontDescription requires Pango >= 1.16");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,56,0)

CAMLexport CAMLprim value ml_pango_font_description_get_features(value self)
{
CAMLparam1(self);

const char* result = pango_font_description_get_features(PangoFontDescription_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_pango_font_description_get_features(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontDescription requires Pango >= 1.56");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_font_description_get_family(value self)
{
CAMLparam1(self);

const char* result = pango_font_description_get_family(PangoFontDescription_val(self));
CAMLreturn(Val_option_string(result));
}

#if PANGO_VERSION_CHECK(1,57,0)

CAMLexport CAMLprim value ml_pango_font_description_get_color(value self)
{
CAMLparam1(self);

PangoFontColor result = pango_font_description_get_color(PangoFontDescription_val(self));
CAMLreturn(Val_PangoFontColor(result));
}

#else

CAMLexport CAMLprim value ml_pango_font_description_get_color(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontDescription requires Pango >= 1.57");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_font_description_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = pango_font_description_equal(PangoFontDescription_val(self), PangoFontDescription_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_pango_font_description_copy_static(value self)
{
CAMLparam1(self);

PangoFontDescription* result = pango_font_description_copy_static(PangoFontDescription_val(self));
CAMLreturn(Val_option(result, Val_PangoFontDescription));
}

CAMLexport CAMLprim value ml_pango_font_description_better_match(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = pango_font_description_better_match(PangoFontDescription_val(self), Option_val(arg1, PangoFontDescription_val, NULL), PangoFontDescription_val(arg2));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_pango_font_description_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_font_description_get_type()));
}
