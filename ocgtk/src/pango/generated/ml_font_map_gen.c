/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FontMap */

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


#if PANGO_VERSION_CHECK(1,52,0)

CAMLexport CAMLprim value ml_pango_font_map_reload_font(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

PangoFont* result = pango_font_map_reload_font(PangoFontMap_val(self), PangoFont_val(arg1), Double_val(arg2), Option_val(arg3, PangoContext_val, NULL), String_option_val(arg4));
CAMLreturn(Val_PangoFont(result));
}

#else

CAMLexport CAMLprim value ml_pango_font_map_reload_font(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("FontMap requires Pango >= 1.52");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_font_map_load_fontset(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

PangoFontset* result = pango_font_map_load_fontset(PangoFontMap_val(self), PangoContext_val(arg1), PangoFontDescription_val(arg2), PangoLanguage_val(arg3));
CAMLreturn(Val_option(result, Val_PangoFontset));
}

CAMLexport CAMLprim value ml_pango_font_map_load_font(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

PangoFont* result = pango_font_map_load_font(PangoFontMap_val(self), PangoContext_val(arg1), PangoFontDescription_val(arg2));
CAMLreturn(Val_option(result, Val_PangoFont));
}

CAMLexport CAMLprim value ml_pango_font_map_list_families(value self)
{
CAMLparam1(self);
PangoFontFamily** out1 = NULL;
int out2;

pango_font_map_list_families(PangoFontMap_val(self), &out1, &out2);
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

CAMLexport CAMLprim value ml_pango_font_map_get_serial(value self)
{
CAMLparam1(self);

guint result = pango_font_map_get_serial(PangoFontMap_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_pango_font_map_get_serial(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontMap requires Pango >= 1.32.4");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,46,0)

CAMLexport CAMLprim value ml_pango_font_map_get_family(value self, value arg1)
{
CAMLparam2(self, arg1);

PangoFontFamily* result = pango_font_map_get_family(PangoFontMap_val(self), String_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_PangoFontFamily));
}

#else

CAMLexport CAMLprim value ml_pango_font_map_get_family(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontMap requires Pango >= 1.46");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,22,0)

CAMLexport CAMLprim value ml_pango_font_map_create_context(value self)
{
CAMLparam1(self);

PangoContext* result = pango_font_map_create_context(PangoFontMap_val(self));
CAMLreturn(Val_PangoContext(result));
}

#else

CAMLexport CAMLprim value ml_pango_font_map_create_context(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontMap requires Pango >= 1.22");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,34,0)

CAMLexport CAMLprim value ml_pango_font_map_changed(value self)
{
CAMLparam1(self);

pango_font_map_changed(PangoFontMap_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_font_map_changed(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontMap requires Pango >= 1.34");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,56,0)

CAMLexport CAMLprim value ml_pango_font_map_add_font_file(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = pango_font_map_add_font_file(PangoFontMap_val(self), String_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_pango_font_map_add_font_file(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontMap requires Pango >= 1.56");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,52,0)

CAMLexport CAMLprim value ml_pango_font_map_get_item_type(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
PangoFontMap *obj = (PangoFontMap *)PangoFontMap_val(self);
    GType *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "item-type");
if (pspec == NULL) caml_failwith("ml_pango_font_map_get_item_type: property 'item-type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "item-type", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_pango_font_map_get_item_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontMap requires Pango >= 1.52");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,52,0)

CAMLexport CAMLprim value ml_pango_font_map_get_n_items(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
PangoFontMap *obj = (PangoFontMap *)PangoFontMap_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "n-items");
if (pspec == NULL) caml_failwith("ml_pango_font_map_get_n_items: property 'n-items' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "n-items", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_pango_font_map_get_n_items(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontMap requires Pango >= 1.52");
return Val_unit;
}
#endif


CAMLprim value ml_pango_font_map_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_font_map_get_type()));
}
