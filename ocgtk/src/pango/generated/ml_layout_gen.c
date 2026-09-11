/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Layout */

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


CAMLexport CAMLprim value ml_pango_layout_new(value arg1)
{
CAMLparam1(arg1);

PangoLayout *obj = pango_layout_new(PangoContext_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_PangoLayout(obj));
}
CAMLexport CAMLprim value ml_pango_layout_xy_to_index(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
int out3;
int out4;

gboolean result = pango_layout_xy_to_index(PangoLayout_val(self), Int_val(arg1), Int_val(arg2), &out3, &out4);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_int(out3));
    Store_field(ret, 2, Val_int(out4));
    CAMLreturn(ret);
}

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_layout_write_to_file(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gboolean result = pango_layout_write_to_file(PangoLayout_val(self), PangoLayoutSerializeFlags_val(arg1), String_val(arg2), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_pango_layout_write_to_file(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Layout requires Pango >= 1.50");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_layout_set_wrap(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_layout_set_wrap(PangoLayout_val(self), PangoWrapMode_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_layout_set_width(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_layout_set_width(PangoLayout_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_layout_set_text(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

pango_layout_set_text(PangoLayout_val(self), String_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_layout_set_tabs(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_layout_set_tabs(PangoLayout_val(self), Option_val(arg1, PangoTabArray_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_layout_set_spacing(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_layout_set_spacing(PangoLayout_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_layout_set_single_paragraph_mode(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_layout_set_single_paragraph_mode(PangoLayout_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_layout_set_markup_with_accel(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
gunichar out4;

pango_layout_set_markup_with_accel(PangoLayout_val(self), String_val(arg1), Int_val(arg2), Long_val(arg3), &out4);
CAMLreturn(Val_long(out4));
}

CAMLexport CAMLprim value ml_pango_layout_set_markup(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

pango_layout_set_markup(PangoLayout_val(self), String_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

#if PANGO_VERSION_CHECK(1,44,0)

CAMLexport CAMLprim value ml_pango_layout_set_line_spacing(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_layout_set_line_spacing(PangoLayout_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_layout_set_line_spacing(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Layout requires Pango >= 1.44");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_layout_set_justify_last_line(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_layout_set_justify_last_line(PangoLayout_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_layout_set_justify_last_line(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Layout requires Pango >= 1.50");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_layout_set_justify(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_layout_set_justify(PangoLayout_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_layout_set_indent(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_layout_set_indent(PangoLayout_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#if PANGO_VERSION_CHECK(1,20,0)

CAMLexport CAMLprim value ml_pango_layout_set_height(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_layout_set_height(PangoLayout_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_layout_set_height(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Layout requires Pango >= 1.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_layout_set_font_description(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_layout_set_font_description(PangoLayout_val(self), Option_val(arg1, PangoFontDescription_val, NULL));
CAMLreturn(Val_unit);
}

#if PANGO_VERSION_CHECK(1,6,0)

CAMLexport CAMLprim value ml_pango_layout_set_ellipsize(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_layout_set_ellipsize(PangoLayout_val(self), PangoEllipsizeMode_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_layout_set_ellipsize(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Layout requires Pango >= 1.6");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,4,0)

CAMLexport CAMLprim value ml_pango_layout_set_auto_dir(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_layout_set_auto_dir(PangoLayout_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_layout_set_auto_dir(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Layout requires Pango >= 1.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_layout_set_attributes(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_layout_set_attributes(PangoLayout_val(self), Option_val(arg1, PangoAttrList_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_layout_set_alignment(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_layout_set_alignment(PangoLayout_val(self), PangoAlignment_val(arg1));
CAMLreturn(Val_unit);
}

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_layout_serialize(value self, value arg1)
{
CAMLparam2(self, arg1);

GBytes* result = pango_layout_serialize(PangoLayout_val(self), PangoLayoutSerializeFlags_val(arg1));
CAMLreturn(Val_GBytes(result));
}

#else

CAMLexport CAMLprim value ml_pango_layout_serialize(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Layout requires Pango >= 1.50");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_layout_move_cursor_visually(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
int out5;
int out6;

pango_layout_move_cursor_visually(PangoLayout_val(self), Bool_val(arg1), Int_val(arg2), Int_val(arg3), Int_val(arg4), &out5, &out6);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out5));
    Store_field(ret, 1, Val_int(out6));
    CAMLreturn(ret);
}

#if PANGO_VERSION_CHECK(1,16,0)

CAMLexport CAMLprim value ml_pango_layout_is_wrapped(value self)
{
CAMLparam1(self);

gboolean result = pango_layout_is_wrapped(PangoLayout_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_pango_layout_is_wrapped(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Layout requires Pango >= 1.16");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,16,0)

CAMLexport CAMLprim value ml_pango_layout_is_ellipsized(value self)
{
CAMLparam1(self);

gboolean result = pango_layout_is_ellipsized(PangoLayout_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_pango_layout_is_ellipsized(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Layout requires Pango >= 1.16");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_layout_index_to_pos(value self, value arg1)
{
CAMLparam2(self, arg1);
PangoRectangle out2;

pango_layout_index_to_pos(PangoLayout_val(self), Int_val(arg1), &out2);
CAMLreturn(Val_PangoRectangle(&out2));
}

CAMLexport CAMLprim value ml_pango_layout_index_to_line_x(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
int out3;
int out4;

pango_layout_index_to_line_x(PangoLayout_val(self), Int_val(arg1), Bool_val(arg2), &out3, &out4);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out3));
    Store_field(ret, 1, Val_int(out4));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_pango_layout_get_wrap(value self)
{
CAMLparam1(self);

PangoWrapMode result = pango_layout_get_wrap(PangoLayout_val(self));
CAMLreturn(Val_PangoWrapMode(result));
}

CAMLexport CAMLprim value ml_pango_layout_get_width(value self)
{
CAMLparam1(self);

int result = pango_layout_get_width(PangoLayout_val(self));
CAMLreturn(Val_int(result));
}

#if PANGO_VERSION_CHECK(1,16,0)

CAMLexport CAMLprim value ml_pango_layout_get_unknown_glyphs_count(value self)
{
CAMLparam1(self);

int result = pango_layout_get_unknown_glyphs_count(PangoLayout_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_pango_layout_get_unknown_glyphs_count(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Layout requires Pango >= 1.16");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_layout_get_text(value self)
{
CAMLparam1(self);

const char* result = pango_layout_get_text(PangoLayout_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_pango_layout_get_tabs(value self)
{
CAMLparam1(self);

PangoTabArray* result = pango_layout_get_tabs(PangoLayout_val(self));
CAMLreturn(Val_option(result, Val_PangoTabArray));
}

CAMLexport CAMLprim value ml_pango_layout_get_spacing(value self)
{
CAMLparam1(self);

int result = pango_layout_get_spacing(PangoLayout_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_pango_layout_get_size(value self)
{
CAMLparam1(self);
int out1;
int out2;

pango_layout_get_size(PangoLayout_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_pango_layout_get_single_paragraph_mode(value self)
{
CAMLparam1(self);

gboolean result = pango_layout_get_single_paragraph_mode(PangoLayout_val(self));
CAMLreturn(Val_bool(result));
}

#if PANGO_VERSION_CHECK(1,32,4)

CAMLexport CAMLprim value ml_pango_layout_get_serial(value self)
{
CAMLparam1(self);

guint result = pango_layout_get_serial(PangoLayout_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_pango_layout_get_serial(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Layout requires Pango >= 1.32.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_layout_get_pixel_size(value self)
{
CAMLparam1(self);
int out1;
int out2;

pango_layout_get_pixel_size(PangoLayout_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_pango_layout_get_pixel_extents(value self)
{
CAMLparam1(self);
PangoRectangle out1;
PangoRectangle out2;

pango_layout_get_pixel_extents(PangoLayout_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_PangoRectangle(&out1));
    Store_field(ret, 1, Val_PangoRectangle(&out2));
    CAMLreturn(ret);
}

#if PANGO_VERSION_CHECK(1,30,0)

CAMLexport CAMLprim value ml_pango_layout_get_log_attrs_readonly(value self)
{
CAMLparam1(self);
gint out1;

const PangoLogAttr* result = pango_layout_get_log_attrs_readonly(PangoLayout_val(self), &out1);
    int result_length = out1;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, Val_PangoLogAttr(&result[i]));
    }
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_result);
    Store_field(ret, 1, Val_int(out1));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_pango_layout_get_log_attrs_readonly(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Layout requires Pango >= 1.30");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_layout_get_log_attrs(value self)
{
CAMLparam1(self);
PangoLogAttr* out1 = NULL;
gint out2;

pango_layout_get_log_attrs(PangoLayout_val(self), &out1, &out2);
    int out1_length = out2;
    CAMLlocal1(ml_out1);
    ml_out1 = caml_alloc(out1_length, 0);
    for (int i = 0; i < out1_length; i++) {
      Store_field(ml_out1, i, Val_PangoLogAttr(&out1[i]));
    }

    g_free(out1);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_out1);
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

#if PANGO_VERSION_CHECK(1,16,0)

CAMLexport CAMLprim value ml_pango_layout_get_lines_readonly(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = pango_layout_get_lines_readonly(PangoLayout_val(self));
Val_GSList_with(c_result, result, item, cell, Val_PangoLayoutLine((gpointer)_tmp->data));
    CAMLreturn(result);
}

#else

CAMLexport CAMLprim value ml_pango_layout_get_lines_readonly(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Layout requires Pango >= 1.16");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_layout_get_lines(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = pango_layout_get_lines(PangoLayout_val(self));
Val_GSList_with(c_result, result, item, cell, Val_PangoLayoutLine((gpointer)_tmp->data));
    CAMLreturn(result);
}

#if PANGO_VERSION_CHECK(1,44,0)

CAMLexport CAMLprim value ml_pango_layout_get_line_spacing(value self)
{
CAMLparam1(self);

float result = pango_layout_get_line_spacing(PangoLayout_val(self));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_pango_layout_get_line_spacing(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Layout requires Pango >= 1.44");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,16,0)

CAMLexport CAMLprim value ml_pango_layout_get_line_readonly(value self, value arg1)
{
CAMLparam2(self, arg1);

PangoLayoutLine* result = pango_layout_get_line_readonly(PangoLayout_val(self), Int_val(arg1));
if (result) result = g_boxed_copy(pango_layout_line_get_type(), result);
CAMLreturn(Val_option(result, Val_PangoLayoutLine));
}

#else

CAMLexport CAMLprim value ml_pango_layout_get_line_readonly(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Layout requires Pango >= 1.16");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_layout_get_line_count(value self)
{
CAMLparam1(self);

int result = pango_layout_get_line_count(PangoLayout_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_pango_layout_get_line(value self, value arg1)
{
CAMLparam2(self, arg1);

PangoLayoutLine* result = pango_layout_get_line(PangoLayout_val(self), Int_val(arg1));
if (result) result = g_boxed_copy(pango_layout_line_get_type(), result);
CAMLreturn(Val_option(result, Val_PangoLayoutLine));
}

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_layout_get_justify_last_line(value self)
{
CAMLparam1(self);

gboolean result = pango_layout_get_justify_last_line(PangoLayout_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_pango_layout_get_justify_last_line(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Layout requires Pango >= 1.50");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_layout_get_justify(value self)
{
CAMLparam1(self);

gboolean result = pango_layout_get_justify(PangoLayout_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_pango_layout_get_iter(value self)
{
CAMLparam1(self);

PangoLayoutIter* result = pango_layout_get_iter(PangoLayout_val(self));
CAMLreturn(Val_PangoLayoutIter(result));
}

CAMLexport CAMLprim value ml_pango_layout_get_indent(value self)
{
CAMLparam1(self);

int result = pango_layout_get_indent(PangoLayout_val(self));
CAMLreturn(Val_int(result));
}

#if PANGO_VERSION_CHECK(1,20,0)

CAMLexport CAMLprim value ml_pango_layout_get_height(value self)
{
CAMLparam1(self);

int result = pango_layout_get_height(PangoLayout_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_pango_layout_get_height(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Layout requires Pango >= 1.20");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,8,0)

CAMLexport CAMLprim value ml_pango_layout_get_font_description(value self)
{
CAMLparam1(self);

const PangoFontDescription* result = pango_layout_get_font_description(PangoLayout_val(self));
if (result) result = g_boxed_copy(pango_font_description_get_type(), result);
CAMLreturn(Val_option(result, Val_PangoFontDescription));
}

#else

CAMLexport CAMLprim value ml_pango_layout_get_font_description(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Layout requires Pango >= 1.8");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_layout_get_extents(value self)
{
CAMLparam1(self);
PangoRectangle out1;
PangoRectangle out2;

pango_layout_get_extents(PangoLayout_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_PangoRectangle(&out1));
    Store_field(ret, 1, Val_PangoRectangle(&out2));
    CAMLreturn(ret);
}

#if PANGO_VERSION_CHECK(1,6,0)

CAMLexport CAMLprim value ml_pango_layout_get_ellipsize(value self)
{
CAMLparam1(self);

PangoEllipsizeMode result = pango_layout_get_ellipsize(PangoLayout_val(self));
CAMLreturn(Val_PangoEllipsizeMode(result));
}

#else

CAMLexport CAMLprim value ml_pango_layout_get_ellipsize(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Layout requires Pango >= 1.6");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,46,0)

CAMLexport CAMLprim value ml_pango_layout_get_direction(value self, value arg1)
{
CAMLparam2(self, arg1);

PangoDirection result = pango_layout_get_direction(PangoLayout_val(self), Int_val(arg1));
CAMLreturn(Val_PangoDirection(result));
}

#else

CAMLexport CAMLprim value ml_pango_layout_get_direction(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Layout requires Pango >= 1.46");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_layout_get_cursor_pos(value self, value arg1)
{
CAMLparam2(self, arg1);
PangoRectangle out2;
PangoRectangle out3;

pango_layout_get_cursor_pos(PangoLayout_val(self), Int_val(arg1), &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_PangoRectangle(&out2));
    Store_field(ret, 1, Val_PangoRectangle(&out3));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_pango_layout_get_context(value self)
{
CAMLparam1(self);

PangoContext* result = pango_layout_get_context(PangoLayout_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_PangoContext(result));
}

#if PANGO_VERSION_CHECK(1,30,0)

CAMLexport CAMLprim value ml_pango_layout_get_character_count(value self)
{
CAMLparam1(self);

gint result = pango_layout_get_character_count(PangoLayout_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_pango_layout_get_character_count(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Layout requires Pango >= 1.30");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_layout_get_caret_pos(value self, value arg1)
{
CAMLparam2(self, arg1);
PangoRectangle out2;
PangoRectangle out3;

pango_layout_get_caret_pos(PangoLayout_val(self), Int_val(arg1), &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_PangoRectangle(&out2));
    Store_field(ret, 1, Val_PangoRectangle(&out3));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_pango_layout_get_caret_pos(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Layout requires Pango >= 1.50");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,22,0)

CAMLexport CAMLprim value ml_pango_layout_get_baseline(value self)
{
CAMLparam1(self);

int result = pango_layout_get_baseline(PangoLayout_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_pango_layout_get_baseline(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Layout requires Pango >= 1.22");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,4,0)

CAMLexport CAMLprim value ml_pango_layout_get_auto_dir(value self)
{
CAMLparam1(self);

gboolean result = pango_layout_get_auto_dir(PangoLayout_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_pango_layout_get_auto_dir(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Layout requires Pango >= 1.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_layout_get_attributes(value self)
{
CAMLparam1(self);

PangoAttrList* result = pango_layout_get_attributes(PangoLayout_val(self));
if (result) result = g_boxed_copy(pango_attr_list_get_type(), result);
CAMLreturn(Val_option(result, Val_PangoAttrList));
}

CAMLexport CAMLprim value ml_pango_layout_get_alignment(value self)
{
CAMLparam1(self);

PangoAlignment result = pango_layout_get_alignment(PangoLayout_val(self));
CAMLreturn(Val_PangoAlignment(result));
}

CAMLexport CAMLprim value ml_pango_layout_copy(value self)
{
CAMLparam1(self);

PangoLayout* result = pango_layout_copy(PangoLayout_val(self));
CAMLreturn(Val_PangoLayout(result));
}

CAMLexport CAMLprim value ml_pango_layout_context_changed(value self)
{
CAMLparam1(self);

pango_layout_context_changed(PangoLayout_val(self));
CAMLreturn(Val_unit);
}


CAMLprim value ml_pango_layout_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_layout_get_type()));
}
