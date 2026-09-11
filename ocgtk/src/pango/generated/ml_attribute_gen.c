/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Attribute */

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

/* Copy function for PangoAttribute (value-like record with copy method) */
value copy_PangoAttribute(const PangoAttribute *ptr)
{
  if (ptr == NULL) return Val_none;
  PangoAttribute *copy = g_boxed_copy(pango_attribute_get_type(), ptr);
  return ml_gir_record_val_ptr_with_type(pango_attribute_get_type(), copy);
}


#if PANGO_VERSION_CHECK(1,20,0)

CAMLexport CAMLprim value ml_pango_attribute_init(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_attribute_init(PangoAttribute_val(self), PangoAttrClass_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_attribute_init(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Attribute requires Pango >= 1.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_attribute_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = pango_attribute_equal(PangoAttribute_val(self), PangoAttribute_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_pango_attribute_destroy(value self)
{
CAMLparam1(self);

pango_attribute_destroy(PangoAttribute_val(self));
CAMLreturn(Val_unit);
}

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_attribute_as_string(value self)
{
CAMLparam1(self);

PangoAttrString* result = pango_attribute_as_string(PangoAttribute_val(self));
CAMLreturn(Val_option(result, Val_PangoAttrString));
}

#else

CAMLexport CAMLprim value ml_pango_attribute_as_string(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Attribute requires Pango >= 1.50");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_attribute_as_size(value self)
{
CAMLparam1(self);

PangoAttrSize* result = pango_attribute_as_size(PangoAttribute_val(self));
CAMLreturn(Val_option(result, Val_PangoAttrSize));
}

#else

CAMLexport CAMLprim value ml_pango_attribute_as_size(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Attribute requires Pango >= 1.50");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_attribute_as_shape(value self)
{
CAMLparam1(self);

PangoAttrShape* result = pango_attribute_as_shape(PangoAttribute_val(self));
CAMLreturn(Val_option(result, Val_PangoAttrShape));
}

#else

CAMLexport CAMLprim value ml_pango_attribute_as_shape(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Attribute requires Pango >= 1.50");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_attribute_as_language(value self)
{
CAMLparam1(self);

PangoAttrLanguage* result = pango_attribute_as_language(PangoAttribute_val(self));
CAMLreturn(Val_option(result, Val_PangoAttrLanguage));
}

#else

CAMLexport CAMLprim value ml_pango_attribute_as_language(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Attribute requires Pango >= 1.50");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_attribute_as_int(value self)
{
CAMLparam1(self);

PangoAttrInt* result = pango_attribute_as_int(PangoAttribute_val(self));
CAMLreturn(Val_option(result, Val_PangoAttrInt));
}

#else

CAMLexport CAMLprim value ml_pango_attribute_as_int(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Attribute requires Pango >= 1.50");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_attribute_as_font_features(value self)
{
CAMLparam1(self);

PangoAttrFontFeatures* result = pango_attribute_as_font_features(PangoAttribute_val(self));
CAMLreturn(Val_option(result, Val_PangoAttrFontFeatures));
}

#else

CAMLexport CAMLprim value ml_pango_attribute_as_font_features(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Attribute requires Pango >= 1.50");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_attribute_as_font_desc(value self)
{
CAMLparam1(self);

PangoAttrFontDesc* result = pango_attribute_as_font_desc(PangoAttribute_val(self));
CAMLreturn(Val_option(result, Val_PangoAttrFontDesc));
}

#else

CAMLexport CAMLprim value ml_pango_attribute_as_font_desc(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Attribute requires Pango >= 1.50");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_attribute_as_float(value self)
{
CAMLparam1(self);

PangoAttrFloat* result = pango_attribute_as_float(PangoAttribute_val(self));
CAMLreturn(Val_option(result, Val_PangoAttrFloat));
}

#else

CAMLexport CAMLprim value ml_pango_attribute_as_float(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Attribute requires Pango >= 1.50");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_attribute_as_color(value self)
{
CAMLparam1(self);

PangoAttrColor* result = pango_attribute_as_color(PangoAttribute_val(self));
CAMLreturn(Val_option(result, Val_PangoAttrColor));
}

#else

CAMLexport CAMLprim value ml_pango_attribute_as_color(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Attribute requires Pango >= 1.50");
return Val_unit;
}
#endif


CAMLprim value ml_pango_attribute_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_attribute_get_type()));
}
