/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Context */

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


CAMLexport CAMLprim value ml_pango_context_new(value unit)
{
CAMLparam1(unit);

PangoContext *obj = pango_context_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_PangoContext(obj));
}
#if PANGO_VERSION_CHECK(1,44,0)

CAMLexport CAMLprim value ml_pango_context_set_round_glyph_positions(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_context_set_round_glyph_positions(PangoContext_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_context_set_round_glyph_positions(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Context requires Pango >= 1.44");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,6,0)

CAMLexport CAMLprim value ml_pango_context_set_matrix(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_context_set_matrix(PangoContext_val(self), Option_val(arg1, PangoMatrix_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_context_set_matrix(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Context requires Pango >= 1.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_context_set_language(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_context_set_language(PangoContext_val(self), Option_val(arg1, PangoLanguage_val, NULL));
CAMLreturn(Val_unit);
}

#if PANGO_VERSION_CHECK(1,16,0)

CAMLexport CAMLprim value ml_pango_context_set_gravity_hint(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_context_set_gravity_hint(PangoContext_val(self), PangoGravityHint_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_context_set_gravity_hint(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Context requires Pango >= 1.16");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_context_set_font_map(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_context_set_font_map(PangoContext_val(self), Option_val(arg1, PangoFontMap_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_context_set_font_description(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_context_set_font_description(PangoContext_val(self), PangoFontDescription_val(arg1));
CAMLreturn(Val_unit);
}

#if PANGO_VERSION_CHECK(1,16,0)

CAMLexport CAMLprim value ml_pango_context_set_base_gravity(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_context_set_base_gravity(PangoContext_val(self), PangoGravity_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_context_set_base_gravity(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Context requires Pango >= 1.16");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_context_set_base_dir(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_context_set_base_dir(PangoContext_val(self), PangoDirection_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_context_load_fontset(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

PangoFontset* result = pango_context_load_fontset(PangoContext_val(self), PangoFontDescription_val(arg1), PangoLanguage_val(arg2));
CAMLreturn(Val_option(result, Val_PangoFontset));
}

CAMLexport CAMLprim value ml_pango_context_load_font(value self, value arg1)
{
CAMLparam2(self, arg1);

PangoFont* result = pango_context_load_font(PangoContext_val(self), PangoFontDescription_val(arg1));
CAMLreturn(Val_option(result, Val_PangoFont));
}

CAMLexport CAMLprim value ml_pango_context_list_families(value self)
{
CAMLparam1(self);
PangoFontFamily** out1 = NULL;
int out2;

pango_context_list_families(PangoContext_val(self), &out1, &out2);
    int out1_length = out2;
    CAMLlocal1(ml_out1);
    ml_out1 = caml_alloc(out1_length, 0);
    for (int i = 0; i < out1_length; i++) {
      Store_field(ml_out1, i, Val_PangoFontFamily(out1[i]));
    }

    g_free(out1);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_out1);
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

#if PANGO_VERSION_CHECK(1,32,4)

CAMLexport CAMLprim value ml_pango_context_get_serial(value self)
{
CAMLparam1(self);

guint result = pango_context_get_serial(PangoContext_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_pango_context_get_serial(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Context requires Pango >= 1.32.4");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,44,0)

CAMLexport CAMLprim value ml_pango_context_get_round_glyph_positions(value self)
{
CAMLparam1(self);

gboolean result = pango_context_get_round_glyph_positions(PangoContext_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_pango_context_get_round_glyph_positions(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Context requires Pango >= 1.44");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_context_get_metrics(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

PangoFontMetrics* result = pango_context_get_metrics(PangoContext_val(self), Option_val(arg1, PangoFontDescription_val, NULL), Option_val(arg2, PangoLanguage_val, NULL));
CAMLreturn(Val_PangoFontMetrics(result));
}

#if PANGO_VERSION_CHECK(1,6,0)

CAMLexport CAMLprim value ml_pango_context_get_matrix(value self)
{
CAMLparam1(self);

const PangoMatrix* result = pango_context_get_matrix(PangoContext_val(self));
if (result) result = g_boxed_copy(pango_matrix_get_type(), result);
CAMLreturn(Val_option(result, Val_PangoMatrix));
}

#else

CAMLexport CAMLprim value ml_pango_context_get_matrix(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Context requires Pango >= 1.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_context_get_language(value self)
{
CAMLparam1(self);

PangoLanguage* result = pango_context_get_language(PangoContext_val(self));
if (result) result = g_boxed_copy(pango_language_get_type(), result);
CAMLreturn(Val_PangoLanguage(result));
}

#if PANGO_VERSION_CHECK(1,16,0)

CAMLexport CAMLprim value ml_pango_context_get_gravity_hint(value self)
{
CAMLparam1(self);

PangoGravityHint result = pango_context_get_gravity_hint(PangoContext_val(self));
CAMLreturn(Val_PangoGravityHint(result));
}

#else

CAMLexport CAMLprim value ml_pango_context_get_gravity_hint(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Context requires Pango >= 1.16");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,16,0)

CAMLexport CAMLprim value ml_pango_context_get_gravity(value self)
{
CAMLparam1(self);

PangoGravity result = pango_context_get_gravity(PangoContext_val(self));
CAMLreturn(Val_PangoGravity(result));
}

#else

CAMLexport CAMLprim value ml_pango_context_get_gravity(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Context requires Pango >= 1.16");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,6,0)

CAMLexport CAMLprim value ml_pango_context_get_font_map(value self)
{
CAMLparam1(self);

PangoFontMap* result = pango_context_get_font_map(PangoContext_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_PangoFontMap));
}

#else

CAMLexport CAMLprim value ml_pango_context_get_font_map(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Context requires Pango >= 1.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_context_get_font_description(value self)
{
CAMLparam1(self);

PangoFontDescription* result = pango_context_get_font_description(PangoContext_val(self));
if (result) result = g_boxed_copy(pango_font_description_get_type(), result);
CAMLreturn(Val_option(result, Val_PangoFontDescription));
}

#if PANGO_VERSION_CHECK(1,16,0)

CAMLexport CAMLprim value ml_pango_context_get_base_gravity(value self)
{
CAMLparam1(self);

PangoGravity result = pango_context_get_base_gravity(PangoContext_val(self));
CAMLreturn(Val_PangoGravity(result));
}

#else

CAMLexport CAMLprim value ml_pango_context_get_base_gravity(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Context requires Pango >= 1.16");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_context_get_base_dir(value self)
{
CAMLparam1(self);

PangoDirection result = pango_context_get_base_dir(PangoContext_val(self));
CAMLreturn(Val_PangoDirection(result));
}

#if PANGO_VERSION_CHECK(1,32,4)

CAMLexport CAMLprim value ml_pango_context_changed(value self)
{
CAMLparam1(self);

pango_context_changed(PangoContext_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_context_changed(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Context requires Pango >= 1.32.4");
return Val_unit;
}
#endif

GType pango_context_get_type (void);


CAMLprim value ml_pango_context_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_context_get_type()));
}
