/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FontFamily */

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


CAMLexport CAMLprim value ml_pango_font_family_list_faces(value self)
{
CAMLparam1(self);
PangoFontFace** out1 = NULL;
int out2;

pango_font_family_list_faces(PangoFontFamily_val(self), &out1, &out2);
    int out1_length = out2;
    CAMLlocal1(ml_out1);
    ml_out1 = caml_alloc(out1_length, 0);
    for (int i = 0; i < out1_length; i++) {
      Store_field(ml_out1, i, Val_PangoFontFace(out1[i]));
    }

    g_free(out1);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_out1);
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

#if PANGO_VERSION_CHECK(1,44,0)

CAMLexport CAMLprim value ml_pango_font_family_is_variable(value self)
{
CAMLparam1(self);

gboolean result = pango_font_family_is_variable(PangoFontFamily_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_pango_font_family_is_variable(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontFamily requires Pango >= 1.44");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,4,0)

CAMLexport CAMLprim value ml_pango_font_family_is_monospace(value self)
{
CAMLparam1(self);

gboolean result = pango_font_family_is_monospace(PangoFontFamily_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_pango_font_family_is_monospace(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontFamily requires Pango >= 1.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_font_family_get_name(value self)
{
CAMLparam1(self);

const char* result = pango_font_family_get_name(PangoFontFamily_val(self));
CAMLreturn(caml_copy_string(result));
}

#if PANGO_VERSION_CHECK(1,46,0)

CAMLexport CAMLprim value ml_pango_font_family_get_face(value self, value arg1)
{
CAMLparam2(self, arg1);

PangoFontFace* result = pango_font_family_get_face(PangoFontFamily_val(self), String_option_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_PangoFontFace));
}

#else

CAMLexport CAMLprim value ml_pango_font_family_get_face(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontFamily requires Pango >= 1.46");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,52,0)

CAMLexport CAMLprim value ml_pango_font_family_get_item_type(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
PangoFontFamily *obj = (PangoFontFamily *)PangoFontFamily_val(self);
    GType *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "item-type");
if (pspec == NULL) caml_failwith("ml_pango_font_family_get_item_type: property 'item-type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "item-type", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_pango_font_family_get_item_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontFamily requires Pango >= 1.52");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,52,0)

CAMLexport CAMLprim value ml_pango_font_family_get_n_items(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
PangoFontFamily *obj = (PangoFontFamily *)PangoFontFamily_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "n-items");
if (pspec == NULL) caml_failwith("ml_pango_font_family_get_n_items: property 'n-items' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "n-items", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_pango_font_family_get_n_items(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontFamily requires Pango >= 1.52");
return Val_unit;
}
#endif

GType pango_font_family_get_type (void);


CAMLprim value ml_pango_font_family_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_font_family_get_type()));
}
