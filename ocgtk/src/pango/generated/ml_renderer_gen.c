/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Renderer */

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

#if PANGO_VERSION_CHECK(1,8,0)


CAMLexport CAMLprim value ml_pango_renderer_set_matrix(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_renderer_set_matrix(PangoRenderer_val(self), Option_val(arg1, PangoMatrix_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_renderer_set_color(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

pango_renderer_set_color(PangoRenderer_val(self), PangoRenderPart_val(arg1), Option_val(arg2, PangoColor_val, NULL));
CAMLreturn(Val_unit);
}

#if PANGO_VERSION_CHECK(1,38,0)

CAMLexport CAMLprim value ml_pango_renderer_set_alpha(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

pango_renderer_set_alpha(PangoRenderer_val(self), PangoRenderPart_val(arg1), UInt16_val(arg2));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_renderer_set_alpha(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Renderer requires Pango >= 1.38");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_renderer_part_changed(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_renderer_part_changed(PangoRenderer_val(self), PangoRenderPart_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_renderer_get_matrix(value self)
{
CAMLparam1(self);

const PangoMatrix* result = pango_renderer_get_matrix(PangoRenderer_val(self));
if (result) result = g_boxed_copy(pango_matrix_get_type(), result);
CAMLreturn(Val_option(result, Val_PangoMatrix));
}

#if PANGO_VERSION_CHECK(1,20,0)

CAMLexport CAMLprim value ml_pango_renderer_get_layout_line(value self)
{
CAMLparam1(self);

PangoLayoutLine* result = pango_renderer_get_layout_line(PangoRenderer_val(self));
if (result) result = g_boxed_copy(pango_layout_line_get_type(), result);
CAMLreturn(Val_option(result, Val_PangoLayoutLine));
}

#else

CAMLexport CAMLprim value ml_pango_renderer_get_layout_line(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Renderer requires Pango >= 1.20");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,20,0)

CAMLexport CAMLprim value ml_pango_renderer_get_layout(value self)
{
CAMLparam1(self);

PangoLayout* result = pango_renderer_get_layout(PangoRenderer_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_PangoLayout));
}

#else

CAMLexport CAMLprim value ml_pango_renderer_get_layout(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Renderer requires Pango >= 1.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_renderer_get_color(value self, value arg1)
{
CAMLparam2(self, arg1);

PangoColor* result = pango_renderer_get_color(PangoRenderer_val(self), PangoRenderPart_val(arg1));
if (result) result = g_boxed_copy(pango_color_get_type(), result);
CAMLreturn(Val_option(result, Val_PangoColor));
}

#if PANGO_VERSION_CHECK(1,38,0)

CAMLexport CAMLprim value ml_pango_renderer_get_alpha(value self, value arg1)
{
CAMLparam2(self, arg1);

guint16 result = pango_renderer_get_alpha(PangoRenderer_val(self), PangoRenderPart_val(arg1));
CAMLreturn(Val_uint16(result));
}

#else

CAMLexport CAMLprim value ml_pango_renderer_get_alpha(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Renderer requires Pango >= 1.38");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_renderer_draw_trapezoid_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam3(arg5, arg6, arg7);

pango_renderer_draw_trapezoid(PangoRenderer_val(self), PangoRenderPart_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5), Double_val(arg6), Double_val(arg7));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_pango_renderer_draw_trapezoid_bytecode(value * argv, int argn)
{
return ml_pango_renderer_draw_trapezoid_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

CAMLexport CAMLprim value ml_pango_renderer_draw_rectangle_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);

pango_renderer_draw_rectangle(PangoRenderer_val(self), PangoRenderPart_val(arg1), Int_val(arg2), Int_val(arg3), Int_val(arg4), Int_val(arg5));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_pango_renderer_draw_rectangle_bytecode(value * argv, int argn)
{
return ml_pango_renderer_draw_rectangle_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_pango_renderer_draw_layout_line(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

pango_renderer_draw_layout_line(PangoRenderer_val(self), PangoLayoutLine_val(arg1), Int_val(arg2), Int_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_renderer_draw_layout(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

pango_renderer_draw_layout(PangoRenderer_val(self), PangoLayout_val(arg1), Int_val(arg2), Int_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_renderer_draw_glyphs(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

pango_renderer_draw_glyphs(PangoRenderer_val(self), PangoFont_val(arg1), PangoGlyphString_val(arg2), Int_val(arg3), Int_val(arg4));
CAMLreturn(Val_unit);
}

#if PANGO_VERSION_CHECK(1,22,0)

CAMLexport CAMLprim value ml_pango_renderer_draw_glyph_item(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

pango_renderer_draw_glyph_item(PangoRenderer_val(self), String_option_val(arg1), PangoGlyphItem_val(arg2), Int_val(arg3), Int_val(arg4));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_renderer_draw_glyph_item(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Renderer requires Pango >= 1.22");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_renderer_draw_glyph(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

pango_renderer_draw_glyph(PangoRenderer_val(self), PangoFont_val(arg1), Int_val(arg2), Double_val(arg3), Double_val(arg4));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_renderer_draw_error_underline(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

pango_renderer_draw_error_underline(PangoRenderer_val(self), Int_val(arg1), Int_val(arg2), Int_val(arg3), Int_val(arg4));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_renderer_deactivate(value self)
{
CAMLparam1(self);

pango_renderer_deactivate(PangoRenderer_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_renderer_activate(value self)
{
CAMLparam1(self);

pango_renderer_activate(PangoRenderer_val(self));
CAMLreturn(Val_unit);
}

GType pango_renderer_get_type (void);


CAMLprim value ml_pango_renderer_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_renderer_get_type()));
}

#else


CAMLexport CAMLprim value ml_pango_renderer_activate(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Renderer requires Pango >= 1.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_renderer_deactivate(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Renderer requires Pango >= 1.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_renderer_draw_error_underline(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Renderer requires Pango >= 1.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_renderer_draw_glyph(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Renderer requires Pango >= 1.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_renderer_draw_glyph_item(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Renderer requires Pango >= 1.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_renderer_draw_glyphs(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Renderer requires Pango >= 1.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_renderer_draw_layout(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Renderer requires Pango >= 1.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_renderer_draw_layout_line(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Renderer requires Pango >= 1.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_renderer_draw_rectangle(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
caml_failwith("Renderer requires Pango >= 1.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_renderer_draw_trapezoid(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
(void)arg6;
(void)arg7;
caml_failwith("Renderer requires Pango >= 1.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_renderer_get_alpha(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Renderer requires Pango >= 1.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_renderer_get_color(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Renderer requires Pango >= 1.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_renderer_get_layout(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Renderer requires Pango >= 1.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_renderer_get_layout_line(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Renderer requires Pango >= 1.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_renderer_get_matrix(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Renderer requires Pango >= 1.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_renderer_part_changed(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Renderer requires Pango >= 1.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_renderer_set_alpha(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Renderer requires Pango >= 1.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_renderer_set_color(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Renderer requires Pango >= 1.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_pango_renderer_set_matrix(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Renderer requires Pango >= 1.8");
return Val_unit;
}


#endif
