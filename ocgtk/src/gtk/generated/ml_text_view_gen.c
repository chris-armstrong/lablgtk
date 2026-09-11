/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TextView */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"
#include "converters.h"

#include <gtk/gtk.h>
/* Include library-specific type conversions and forward declarations */
#include "gtk_decls.h"


CAMLexport CAMLprim value ml_gtk_text_view_new(value unit)
{
CAMLparam1(unit);

GtkTextView *obj = gtk_text_view_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkTextView(obj));
}
CAMLexport CAMLprim value ml_gtk_text_view_new_with_buffer(value arg1)
{
CAMLparam1(arg1);

GtkTextView *obj = gtk_text_view_new_with_buffer(GtkTextBuffer_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkTextView(obj));
}
CAMLexport CAMLprim value ml_gtk_text_view_window_to_buffer_coords(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
int out4;
int out5;

gtk_text_view_window_to_buffer_coords(GtkTextView_val(self), GtkTextWindowType_val(arg1), Int_val(arg2), Int_val(arg3), &out4, &out5);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out4));
    Store_field(ret, 1, Val_int(out5));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_text_view_starts_display_line(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_view_starts_display_line(GtkTextView_val(self), GtkTextIter_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_set_wrap_mode(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_set_wrap_mode(GtkTextView_val(self), GtkWrapMode_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_set_top_margin(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_set_top_margin(GtkTextView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_set_tabs(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_set_tabs(GtkTextView_val(self), PangoTabArray_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_set_right_margin(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_set_right_margin(GtkTextView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_set_pixels_inside_wrap(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_set_pixels_inside_wrap(GtkTextView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_set_pixels_below_lines(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_set_pixels_below_lines(GtkTextView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_set_pixels_above_lines(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_set_pixels_above_lines(GtkTextView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_set_overwrite(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_set_overwrite(GtkTextView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_set_monospace(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_set_monospace(GtkTextView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_set_left_margin(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_set_left_margin(GtkTextView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_set_justification(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_set_justification(GtkTextView_val(self), GtkJustification_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_set_input_purpose(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_set_input_purpose(GtkTextView_val(self), GtkInputPurpose_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_set_input_hints(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_set_input_hints(GtkTextView_val(self), GtkInputHints_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_set_indent(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_set_indent(GtkTextView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_set_gutter(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_text_view_set_gutter(GtkTextView_val(self), GtkTextWindowType_val(arg1), Option_val(arg2, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_set_extra_menu(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_set_extra_menu(GtkTextView_val(self), Option_val(arg1, GMenuModel_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_set_editable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_set_editable(GtkTextView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_set_cursor_visible(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_set_cursor_visible(GtkTextView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_set_buffer(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_set_buffer(GtkTextView_val(self), Option_val(arg1, GtkTextBuffer_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_set_bottom_margin(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_set_bottom_margin(GtkTextView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_set_accepts_tab(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_set_accepts_tab(GtkTextView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_scroll_to_mark_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);

gtk_text_view_scroll_to_mark(GtkTextView_val(self), GtkTextMark_val(arg1), Double_val(arg2), Bool_val(arg3), Double_val(arg4), Double_val(arg5));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gtk_text_view_scroll_to_mark_bytecode(value * argv, int argn)
{
return ml_gtk_text_view_scroll_to_mark_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gtk_text_view_scroll_to_iter_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);

gboolean result = gtk_text_view_scroll_to_iter(GtkTextView_val(self), GtkTextIter_val(arg1), Double_val(arg2), Bool_val(arg3), Double_val(arg4), Double_val(arg5));
CAMLreturn(Val_bool(result));}

CAMLexport CAMLprim value ml_gtk_text_view_scroll_to_iter_bytecode(value * argv, int argn)
{
return ml_gtk_text_view_scroll_to_iter_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gtk_text_view_scroll_mark_onscreen(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_scroll_mark_onscreen(GtkTextView_val(self), GtkTextMark_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_reset_im_context(value self)
{
CAMLparam1(self);

gtk_text_view_reset_im_context(GtkTextView_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_reset_cursor_blink(value self)
{
CAMLparam1(self);

gtk_text_view_reset_cursor_blink(GtkTextView_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_remove(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_view_remove(GtkTextView_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_place_cursor_onscreen(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_view_place_cursor_onscreen(GtkTextView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_move_visually(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gtk_text_view_move_visually(GtkTextView_val(self), GtkTextIter_val(arg1), Int_val(arg2));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_move_overlay(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_text_view_move_overlay(GtkTextView_val(self), GtkWidget_val(arg1), Int_val(arg2), Int_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_move_mark_onscreen(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_view_move_mark_onscreen(GtkTextView_val(self), GtkTextMark_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_im_context_filter_keypress(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_view_im_context_filter_keypress(GtkTextView_val(self), GdkEvent_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_get_wrap_mode(value self)
{
CAMLparam1(self);

GtkWrapMode result = gtk_text_view_get_wrap_mode(GtkTextView_val(self));
CAMLreturn(Val_GtkWrapMode(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_get_visible_rect(value self)
{
CAMLparam1(self);
GdkRectangle out1;

gtk_text_view_get_visible_rect(GtkTextView_val(self), &out1);
CAMLreturn(Val_GdkRectangle(&out1));
}

#if GTK_CHECK_VERSION(4,18,0)

CAMLexport CAMLprim value ml_gtk_text_view_get_visible_offset(value self)
{
CAMLparam1(self);
double out1;
double out2;

gtk_text_view_get_visible_offset(GtkTextView_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, caml_copy_double(out1));
    Store_field(ret, 1, caml_copy_double(out2));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_gtk_text_view_get_visible_offset(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TextView requires GTK >= 4.18");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_text_view_get_top_margin(value self)
{
CAMLparam1(self);

int result = gtk_text_view_get_top_margin(GtkTextView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_get_tabs(value self)
{
CAMLparam1(self);

PangoTabArray* result = gtk_text_view_get_tabs(GtkTextView_val(self));
CAMLreturn(Val_option(result, Val_PangoTabArray));
}

#if GTK_CHECK_VERSION(4,4,0)

CAMLexport CAMLprim value ml_gtk_text_view_get_rtl_context(value self)
{
CAMLparam1(self);

PangoContext* result = gtk_text_view_get_rtl_context(GtkTextView_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_PangoContext(result));
}

#else

CAMLexport CAMLprim value ml_gtk_text_view_get_rtl_context(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TextView requires GTK >= 4.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_text_view_get_right_margin(value self)
{
CAMLparam1(self);

int result = gtk_text_view_get_right_margin(GtkTextView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_get_pixels_inside_wrap(value self)
{
CAMLparam1(self);

int result = gtk_text_view_get_pixels_inside_wrap(GtkTextView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_get_pixels_below_lines(value self)
{
CAMLparam1(self);

int result = gtk_text_view_get_pixels_below_lines(GtkTextView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_get_pixels_above_lines(value self)
{
CAMLparam1(self);

int result = gtk_text_view_get_pixels_above_lines(GtkTextView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_get_overwrite(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_view_get_overwrite(GtkTextView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_get_monospace(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_view_get_monospace(GtkTextView_val(self));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,4,0)

CAMLexport CAMLprim value ml_gtk_text_view_get_ltr_context(value self)
{
CAMLparam1(self);

PangoContext* result = gtk_text_view_get_ltr_context(GtkTextView_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_PangoContext(result));
}

#else

CAMLexport CAMLprim value ml_gtk_text_view_get_ltr_context(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TextView requires GTK >= 4.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_text_view_get_line_yrange(value self, value arg1)
{
CAMLparam2(self, arg1);
int out2;
int out3;

gtk_text_view_get_line_yrange(GtkTextView_val(self), GtkTextIter_val(arg1), &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out2));
    Store_field(ret, 1, Val_int(out3));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_text_view_get_line_at_y(value self, value arg1)
{
CAMLparam2(self, arg1);
GtkTextIter out1;
int out3;

gtk_text_view_get_line_at_y(GtkTextView_val(self), &out1, Int_val(arg1), &out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_GtkTextIter(&out1));
    Store_field(ret, 1, Val_int(out3));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_text_view_get_left_margin(value self)
{
CAMLparam1(self);

int result = gtk_text_view_get_left_margin(GtkTextView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_get_justification(value self)
{
CAMLparam1(self);

GtkJustification result = gtk_text_view_get_justification(GtkTextView_val(self));
CAMLreturn(Val_GtkJustification(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_get_iter_location(value self, value arg1)
{
CAMLparam2(self, arg1);
GdkRectangle out2;

gtk_text_view_get_iter_location(GtkTextView_val(self), GtkTextIter_val(arg1), &out2);
CAMLreturn(Val_GdkRectangle(&out2));
}

CAMLexport CAMLprim value ml_gtk_text_view_get_iter_at_position(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GtkTextIter out1;
int out2;

gboolean result = gtk_text_view_get_iter_at_position(GtkTextView_val(self), &out1, &out2, Int_val(arg1), Int_val(arg2));
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_GtkTextIter(&out1));
    Store_field(ret, 2, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_text_view_get_iter_at_location(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GtkTextIter out1;

gboolean result = gtk_text_view_get_iter_at_location(GtkTextView_val(self), &out1, Int_val(arg1), Int_val(arg2));
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_GtkTextIter(&out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_text_view_get_input_purpose(value self)
{
CAMLparam1(self);

GtkInputPurpose result = gtk_text_view_get_input_purpose(GtkTextView_val(self));
CAMLreturn(Val_GtkInputPurpose(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_get_input_hints(value self)
{
CAMLparam1(self);

GtkInputHints result = gtk_text_view_get_input_hints(GtkTextView_val(self));
CAMLreturn(Val_GtkInputHints(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_get_indent(value self)
{
CAMLparam1(self);

int result = gtk_text_view_get_indent(GtkTextView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_get_gutter(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkWidget* result = gtk_text_view_get_gutter(GtkTextView_val(self), GtkTextWindowType_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_text_view_get_extra_menu(value self)
{
CAMLparam1(self);

GMenuModel* result = gtk_text_view_get_extra_menu(GtkTextView_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GMenuModel(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_get_editable(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_view_get_editable(GtkTextView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_get_cursor_visible(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_view_get_cursor_visible(GtkTextView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_get_cursor_locations(value self, value arg1)
{
CAMLparam2(self, arg1);
GdkRectangle out2;
GdkRectangle out3;

gtk_text_view_get_cursor_locations(GtkTextView_val(self), Option_val(arg1, GtkTextIter_val, NULL), &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_GdkRectangle(&out2));
    Store_field(ret, 1, Val_GdkRectangle(&out3));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_text_view_get_buffer(value self)
{
CAMLparam1(self);

GtkTextBuffer* result = gtk_text_view_get_buffer(GtkTextView_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkTextBuffer(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_get_bottom_margin(value self)
{
CAMLparam1(self);

int result = gtk_text_view_get_bottom_margin(GtkTextView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_get_accepts_tab(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_view_get_accepts_tab(GtkTextView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_forward_display_line_end(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_view_forward_display_line_end(GtkTextView_val(self), GtkTextIter_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_forward_display_line(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_view_forward_display_line(GtkTextView_val(self), GtkTextIter_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_buffer_to_window_coords(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
int out4;
int out5;

gtk_text_view_buffer_to_window_coords(GtkTextView_val(self), GtkTextWindowType_val(arg1), Int_val(arg2), Int_val(arg3), &out4, &out5);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out4));
    Store_field(ret, 1, Val_int(out5));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_text_view_backward_display_line_start(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_view_backward_display_line_start(GtkTextView_val(self), GtkTextIter_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_backward_display_line(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_view_backward_display_line(GtkTextView_val(self), GtkTextIter_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_view_add_overlay(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_text_view_add_overlay(GtkTextView_val(self), GtkWidget_val(arg1), Int_val(arg2), Int_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_add_child_at_anchor(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_text_view_add_child_at_anchor(GtkTextView_val(self), GtkWidget_val(arg1), GtkTextChildAnchor_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_view_get_im_module(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextView *obj = (GtkTextView *)GtkTextView_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "im-module");
if (pspec == NULL) caml_failwith("ml_gtk_text_view_get_im_module: property 'im-module' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "im-module", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_view_set_im_module(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextView *obj = (GtkTextView *)GtkTextView_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "im-module");
if (pspec == NULL) caml_failwith("ml_gtk_text_view_set_im_module: property 'im-module' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "im-module", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

GType gtk_text_view_get_type (void);


CAMLprim value ml_gtk_text_view_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_text_view_get_type()));
}
