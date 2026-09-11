/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FontMap */

#include <pango/pangocairo.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <pango/pangocairo.h>
/* Include library-specific type conversions and forward declarations */
#include "pangocairo_decls.h"

#if PANGO_VERSION_CHECK(1,10,0)


CAMLexport CAMLprim value ml_pango_cairo_font_map_set_resolution(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_cairo_font_map_set_resolution(PangoCairoFontMap_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

#if PANGO_VERSION_CHECK(1,22,0)

CAMLexport CAMLprim value ml_pango_cairo_font_map_set_default(value self)
{
CAMLparam1(self);

pango_cairo_font_map_set_default(PangoCairoFontMap_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_cairo_font_map_set_default(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontMap requires Pango >= 1.22");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_cairo_font_map_get_resolution(value self)
{
CAMLparam1(self);

double result = pango_cairo_font_map_get_resolution(PangoCairoFontMap_val(self));
CAMLreturn(caml_copy_double(result));
}

#if PANGO_VERSION_CHECK(1,18,0)

CAMLexport CAMLprim value ml_pango_cairo_font_map_get_font_type(value self)
{
CAMLparam1(self);

cairo_font_type_t result = pango_cairo_font_map_get_font_type(PangoCairoFontMap_val(self));
CAMLreturn(Val_cairoFontType(result));
}

#else

CAMLexport CAMLprim value ml_pango_cairo_font_map_get_font_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontMap requires Pango >= 1.18");
return Val_unit;
}
#endif
CAMLexport CAMLprim value ml_pangocairo_font_map_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), PANGO_TYPE_CAIRO_FONT_MAP)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "PangoCairoFontMap");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_PangoCairoFontMap((PangoCairoFontMap*)gobj));
}


CAMLprim value ml_pango_cairo_font_map_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_cairo_font_map_get_type()));
}

#else


CAMLexport CAMLprim value ml_pango_cairo_font_map_get_font_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontMap requires Pango >= 1.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_cairo_font_map_get_resolution(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontMap requires Pango >= 1.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_cairo_font_map_set_default(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontMap requires Pango >= 1.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_cairo_font_map_set_resolution(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontMap requires Pango >= 1.10");
return Val_unit;
}

CAMLexport CAMLprim value ml_pangocairo_font_map_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("FontMap requires GTK >= 1.10");
    return Val_unit;
}


#endif
