/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PathBuilder */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gsk/gsk.h>
/* Include library-specific type conversions and forward declarations */
#include "gsk_decls.h"

#if GTK_CHECK_VERSION(4,14,0)
/* Conversion functions for GskPathBuilder (opaque record with hidden fields) */
GskPathBuilder *GskPathBuilder_val(value v) {
  return (GskPathBuilder *)ml_gir_record_ptr_val(v, "GskPathBuilder");
}

value Val_GskPathBuilder(const GskPathBuilder *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gsk_path_builder_get_type(), ptr);
}

value Val_GskPathBuilder_option(const GskPathBuilder *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GskPathBuilder(ptr));
}
#endif

#if GTK_CHECK_VERSION(4,14,0)


CAMLexport CAMLprim value ml_gsk_path_builder_new(value unit)
{
CAMLparam1(unit);

GskPathBuilder *obj = gsk_path_builder_new();

CAMLreturn(Val_GskPathBuilder(obj));
}
CAMLexport CAMLprim value ml_gsk_path_builder_to_path(value self)
{
CAMLparam1(self);

GskPath* result = gsk_path_builder_to_path(GskPathBuilder_val(self));
CAMLreturn(Val_GskPath(result));
}

CAMLexport CAMLprim value ml_gsk_path_builder_svg_arc_to_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam3(arg5, arg6, arg7);

gsk_path_builder_svg_arc_to(GskPathBuilder_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), Bool_val(arg4), Bool_val(arg5), Double_val(arg6), Double_val(arg7));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gsk_path_builder_svg_arc_to_bytecode(value * argv, int argn)
{
return ml_gsk_path_builder_svg_arc_to_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

CAMLexport CAMLprim value ml_gsk_path_builder_rel_svg_arc_to_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam3(arg5, arg6, arg7);

gsk_path_builder_rel_svg_arc_to(GskPathBuilder_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), Bool_val(arg4), Bool_val(arg5), Double_val(arg6), Double_val(arg7));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gsk_path_builder_rel_svg_arc_to_bytecode(value * argv, int argn)
{
return ml_gsk_path_builder_rel_svg_arc_to_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

CAMLexport CAMLprim value ml_gsk_path_builder_rel_quad_to(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gsk_path_builder_rel_quad_to(GskPathBuilder_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_path_builder_rel_move_to(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gsk_path_builder_rel_move_to(GskPathBuilder_val(self), Double_val(arg1), Double_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_path_builder_rel_line_to(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gsk_path_builder_rel_line_to(GskPathBuilder_val(self), Double_val(arg1), Double_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_path_builder_rel_html_arc_to_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);

gsk_path_builder_rel_html_arc_to(GskPathBuilder_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gsk_path_builder_rel_html_arc_to_bytecode(value * argv, int argn)
{
return ml_gsk_path_builder_rel_html_arc_to_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gsk_path_builder_rel_cubic_to_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam2(arg5, arg6);

gsk_path_builder_rel_cubic_to(GskPathBuilder_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5), Double_val(arg6));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gsk_path_builder_rel_cubic_to_bytecode(value * argv, int argn)
{
return ml_gsk_path_builder_rel_cubic_to_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

CAMLexport CAMLprim value ml_gsk_path_builder_rel_conic_to_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);

gsk_path_builder_rel_conic_to(GskPathBuilder_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gsk_path_builder_rel_conic_to_bytecode(value * argv, int argn)
{
return ml_gsk_path_builder_rel_conic_to_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gsk_path_builder_rel_arc_to(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gsk_path_builder_rel_arc_to(GskPathBuilder_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_path_builder_ref(value self)
{
CAMLparam1(self);

GskPathBuilder* result = gsk_path_builder_ref(GskPathBuilder_val(self));
if (result) result = g_boxed_copy(gsk_path_builder_get_type(), result);
CAMLreturn(Val_GskPathBuilder(result));
}

CAMLexport CAMLprim value ml_gsk_path_builder_quad_to(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gsk_path_builder_quad_to(GskPathBuilder_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_path_builder_move_to(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gsk_path_builder_move_to(GskPathBuilder_val(self), Double_val(arg1), Double_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_path_builder_line_to(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gsk_path_builder_line_to(GskPathBuilder_val(self), Double_val(arg1), Double_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_path_builder_html_arc_to_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);

gsk_path_builder_html_arc_to(GskPathBuilder_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gsk_path_builder_html_arc_to_bytecode(value * argv, int argn)
{
return ml_gsk_path_builder_html_arc_to_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gsk_path_builder_get_current_point(value self)
{
CAMLparam1(self);

const graphene_point_t* result = gsk_path_builder_get_current_point(GskPathBuilder_val(self));
if (result) result = g_boxed_copy(graphene_point_get_type(), result);
CAMLreturn(Val_graphene_point_t(result));
}

CAMLexport CAMLprim value ml_gsk_path_builder_cubic_to_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam2(arg5, arg6);

gsk_path_builder_cubic_to(GskPathBuilder_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5), Double_val(arg6));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gsk_path_builder_cubic_to_bytecode(value * argv, int argn)
{
return ml_gsk_path_builder_cubic_to_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

CAMLexport CAMLprim value ml_gsk_path_builder_conic_to_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);

gsk_path_builder_conic_to(GskPathBuilder_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4), Double_val(arg5));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gsk_path_builder_conic_to_bytecode(value * argv, int argn)
{
return ml_gsk_path_builder_conic_to_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gsk_path_builder_close(value self)
{
CAMLparam1(self);

gsk_path_builder_close(GskPathBuilder_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_path_builder_arc_to(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gsk_path_builder_arc_to(GskPathBuilder_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_path_builder_add_segment(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gsk_path_builder_add_segment(GskPathBuilder_val(self), GskPath_val(arg1), GskPathPoint_val(arg2), GskPathPoint_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_path_builder_add_rounded_rect(value self, value arg1)
{
CAMLparam2(self, arg1);

gsk_path_builder_add_rounded_rect(GskPathBuilder_val(self), GskRoundedRect_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_path_builder_add_reverse_path(value self, value arg1)
{
CAMLparam2(self, arg1);

gsk_path_builder_add_reverse_path(GskPathBuilder_val(self), GskPath_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_path_builder_add_rect(value self, value arg1)
{
CAMLparam2(self, arg1);

gsk_path_builder_add_rect(GskPathBuilder_val(self), graphene_rect_t_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_path_builder_add_path(value self, value arg1)
{
CAMLparam2(self, arg1);

gsk_path_builder_add_path(GskPathBuilder_val(self), GskPath_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_path_builder_add_layout(value self, value arg1)
{
CAMLparam2(self, arg1);

gsk_path_builder_add_layout(GskPathBuilder_val(self), PangoLayout_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_path_builder_add_circle(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gsk_path_builder_add_circle(GskPathBuilder_val(self), graphene_point_t_val(arg1), Double_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_path_builder_add_cairo_path(value self, value arg1)
{
CAMLparam2(self, arg1);

gsk_path_builder_add_cairo_path(GskPathBuilder_val(self), cairo_path_t_val(arg1));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gsk_path_builder_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_path_builder_get_type()));
}

#else


CAMLexport CAMLprim value ml_gsk_path_builder_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_add_cairo_path(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_add_circle(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_add_layout(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_add_path(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_add_rect(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_add_reverse_path(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_add_rounded_rect(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_add_segment(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_arc_to(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_close(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_conic_to(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_cubic_to(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
(void)arg6;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_get_current_point(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_html_arc_to(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_line_to(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_move_to(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_quad_to(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_ref(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_rel_arc_to(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_rel_conic_to(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_rel_cubic_to(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
(void)arg6;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_rel_html_arc_to(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_rel_line_to(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_rel_move_to(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_rel_quad_to(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_rel_svg_arc_to(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7)
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
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_svg_arc_to(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7)
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
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_builder_to_path(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PathBuilder requires GTK >= 4.14");
return Val_unit;
}


#endif
