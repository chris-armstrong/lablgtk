/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Font */

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

#if PANGO_VERSION_CHECK(1,18,0)


CAMLexport CAMLprim value ml_pango_cairo_font_get_scaled_font(value self)
{
CAMLparam1(self);

cairo_scaled_font_t* result = pango_cairo_font_get_scaled_font(PangoCairoFont_val(self));
if (result) result = g_boxed_copy(cairo_gobject_scaled_font_get_type(), result);
CAMLreturn(Val_option(result, Val_cairo_scaled_font_t));
}
CAMLexport CAMLprim value ml_pangocairo_font_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), PANGO_TYPE_CAIRO_FONT)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "PangoCairoFont");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_PangoCairoFont((PangoCairoFont*)gobj));
}

GType pango_cairo_font_get_type (void);


CAMLprim value ml_pango_cairo_font_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_cairo_font_get_type()));
}

#else


CAMLexport CAMLprim value ml_pango_cairo_font_get_scaled_font(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Font requires Pango >= 1.18");
return Val_unit;
}

CAMLexport CAMLprim value ml_pangocairo_font_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("Font requires GTK >= 1.18");
    return Val_unit;
}


#endif
