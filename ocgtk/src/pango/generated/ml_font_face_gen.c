/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FontFace */

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


#if PANGO_VERSION_CHECK(1,4,0)

CAMLexport CAMLprim value ml_pango_font_face_list_sizes(value self)
{
CAMLparam1(self);
int* out1 = NULL;
int out2;

pango_font_face_list_sizes(PangoFontFace_val(self), &out1, &out2);
    int out1_length = out2;
    CAMLlocal1(ml_out1);
    ml_out1 = caml_alloc(out1_length, 0);
    for (int i = 0; i < out1_length; i++) {
      Store_field(ml_out1, i, Val_int(out1[i]));
    }

    g_free(out1);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_out1);
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_pango_font_face_list_sizes(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontFace requires Pango >= 1.4");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,18,0)

CAMLexport CAMLprim value ml_pango_font_face_is_synthesized(value self)
{
CAMLparam1(self);

gboolean result = pango_font_face_is_synthesized(PangoFontFace_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_pango_font_face_is_synthesized(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontFace requires Pango >= 1.18");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,46,0)

CAMLexport CAMLprim value ml_pango_font_face_get_family(value self)
{
CAMLparam1(self);

PangoFontFamily* result = pango_font_face_get_family(PangoFontFace_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_PangoFontFamily(result));
}

#else

CAMLexport CAMLprim value ml_pango_font_face_get_family(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontFace requires Pango >= 1.46");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_font_face_get_face_name(value self)
{
CAMLparam1(self);

const char* result = pango_font_face_get_face_name(PangoFontFace_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_pango_font_face_describe(value self)
{
CAMLparam1(self);

PangoFontDescription* result = pango_font_face_describe(PangoFontFace_val(self));
CAMLreturn(Val_PangoFontDescription(result));
}


CAMLprim value ml_pango_font_face_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_font_face_get_type()));
}
