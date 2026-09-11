/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TextBuffer */

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


CAMLexport CAMLprim value ml_gtk_text_buffer_new(value arg1)
{
CAMLparam1(arg1);

GtkTextBuffer *obj = gtk_text_buffer_new(Option_val(arg1, GtkTextTagTable_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkTextBuffer(obj));
}
CAMLexport CAMLprim value ml_gtk_text_buffer_undo(value self)
{
CAMLparam1(self);

gtk_text_buffer_undo(GtkTextBuffer_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_set_text(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_text_buffer_set_text(GtkTextBuffer_val(self), String_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_set_modified(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_buffer_set_modified(GtkTextBuffer_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_set_max_undo_levels(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_buffer_set_max_undo_levels(GtkTextBuffer_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_set_enable_undo(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_buffer_set_enable_undo(GtkTextBuffer_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_select_range(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_text_buffer_select_range(GtkTextBuffer_val(self), GtkTextIter_val(arg1), GtkTextIter_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_remove_tag_by_name(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_text_buffer_remove_tag_by_name(GtkTextBuffer_val(self), String_val(arg1), GtkTextIter_val(arg2), GtkTextIter_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_remove_tag(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_text_buffer_remove_tag(GtkTextBuffer_val(self), GtkTextTag_val(arg1), GtkTextIter_val(arg2), GtkTextIter_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_remove_selection_clipboard(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_buffer_remove_selection_clipboard(GtkTextBuffer_val(self), GdkClipboard_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,16,0)

CAMLexport CAMLprim value ml_gtk_text_buffer_remove_commit_notify(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_buffer_remove_commit_notify(GtkTextBuffer_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_text_buffer_remove_commit_notify(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TextBuffer requires GTK >= 4.16");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_text_buffer_remove_all_tags(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_text_buffer_remove_all_tags(GtkTextBuffer_val(self), GtkTextIter_val(arg1), GtkTextIter_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_redo(value self)
{
CAMLparam1(self);

gtk_text_buffer_redo(GtkTextBuffer_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_place_cursor(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_buffer_place_cursor(GtkTextBuffer_val(self), GtkTextIter_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_paste_clipboard(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_text_buffer_paste_clipboard(GtkTextBuffer_val(self), GdkClipboard_val(arg1), Option_val(arg2, GtkTextIter_val, NULL), Bool_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_move_mark_by_name(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_text_buffer_move_mark_by_name(GtkTextBuffer_val(self), String_val(arg1), GtkTextIter_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_move_mark(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_text_buffer_move_mark(GtkTextBuffer_val(self), GtkTextMark_val(arg1), GtkTextIter_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_insert_range_interactive(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gboolean result = gtk_text_buffer_insert_range_interactive(GtkTextBuffer_val(self), GtkTextIter_val(arg1), GtkTextIter_val(arg2), GtkTextIter_val(arg3), Bool_val(arg4));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_insert_range(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_text_buffer_insert_range(GtkTextBuffer_val(self), GtkTextIter_val(arg1), GtkTextIter_val(arg2), GtkTextIter_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_insert_paintable(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_text_buffer_insert_paintable(GtkTextBuffer_val(self), GtkTextIter_val(arg1), GdkPaintable_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_insert_markup(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_text_buffer_insert_markup(GtkTextBuffer_val(self), GtkTextIter_val(arg1), String_val(arg2), Int_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_insert_interactive_at_cursor(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gboolean result = gtk_text_buffer_insert_interactive_at_cursor(GtkTextBuffer_val(self), String_val(arg1), Int_val(arg2), Bool_val(arg3));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_insert_interactive(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gboolean result = gtk_text_buffer_insert_interactive(GtkTextBuffer_val(self), GtkTextIter_val(arg1), String_val(arg2), Int_val(arg3), Bool_val(arg4));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_insert_child_anchor(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_text_buffer_insert_child_anchor(GtkTextBuffer_val(self), GtkTextIter_val(arg1), GtkTextChildAnchor_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_insert_at_cursor(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_text_buffer_insert_at_cursor(GtkTextBuffer_val(self), String_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_insert(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_text_buffer_insert(GtkTextBuffer_val(self), GtkTextIter_val(arg1), String_val(arg2), Int_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_text(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

char* result = gtk_text_buffer_get_text(GtkTextBuffer_val(self), GtkTextIter_val(arg1), GtkTextIter_val(arg2), Bool_val(arg3));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_tag_table(value self)
{
CAMLparam1(self);

GtkTextTagTable* result = gtk_text_buffer_get_tag_table(GtkTextBuffer_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkTextTagTable(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_start_iter(value self)
{
CAMLparam1(self);
GtkTextIter out1;

gtk_text_buffer_get_start_iter(GtkTextBuffer_val(self), &out1);
CAMLreturn(Val_GtkTextIter(&out1));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_slice(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

char* result = gtk_text_buffer_get_slice(GtkTextBuffer_val(self), GtkTextIter_val(arg1), GtkTextIter_val(arg2), Bool_val(arg3));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_selection_content(value self)
{
CAMLparam1(self);

GdkContentProvider* result = gtk_text_buffer_get_selection_content(GtkTextBuffer_val(self));
CAMLreturn(Val_GdkContentProvider(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_selection_bounds(value self)
{
CAMLparam1(self);
GtkTextIter out1;
GtkTextIter out2;

gboolean result = gtk_text_buffer_get_selection_bounds(GtkTextBuffer_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_GtkTextIter(&out1));
    Store_field(ret, 2, Val_GtkTextIter(&out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_selection_bound(value self)
{
CAMLparam1(self);

GtkTextMark* result = gtk_text_buffer_get_selection_bound(GtkTextBuffer_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkTextMark(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_modified(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_buffer_get_modified(GtkTextBuffer_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_max_undo_levels(value self)
{
CAMLparam1(self);

guint result = gtk_text_buffer_get_max_undo_levels(GtkTextBuffer_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_mark(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkTextMark* result = gtk_text_buffer_get_mark(GtkTextBuffer_val(self), String_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkTextMark));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_line_count(value self)
{
CAMLparam1(self);

int result = gtk_text_buffer_get_line_count(GtkTextBuffer_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_iter_at_offset(value self, value arg1)
{
CAMLparam2(self, arg1);
GtkTextIter out1;

gtk_text_buffer_get_iter_at_offset(GtkTextBuffer_val(self), &out1, Int_val(arg1));
CAMLreturn(Val_GtkTextIter(&out1));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_iter_at_mark(value self, value arg1)
{
CAMLparam2(self, arg1);
GtkTextIter out1;

gtk_text_buffer_get_iter_at_mark(GtkTextBuffer_val(self), &out1, GtkTextMark_val(arg1));
CAMLreturn(Val_GtkTextIter(&out1));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_iter_at_line_offset(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GtkTextIter out1;

gboolean result = gtk_text_buffer_get_iter_at_line_offset(GtkTextBuffer_val(self), &out1, Int_val(arg1), Int_val(arg2));
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_GtkTextIter(&out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_iter_at_line_index(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GtkTextIter out1;

gboolean result = gtk_text_buffer_get_iter_at_line_index(GtkTextBuffer_val(self), &out1, Int_val(arg1), Int_val(arg2));
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_GtkTextIter(&out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_iter_at_line(value self, value arg1)
{
CAMLparam2(self, arg1);
GtkTextIter out1;

gboolean result = gtk_text_buffer_get_iter_at_line(GtkTextBuffer_val(self), &out1, Int_val(arg1));
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_GtkTextIter(&out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_iter_at_child_anchor(value self, value arg1)
{
CAMLparam2(self, arg1);
GtkTextIter out1;

gtk_text_buffer_get_iter_at_child_anchor(GtkTextBuffer_val(self), &out1, GtkTextChildAnchor_val(arg1));
CAMLreturn(Val_GtkTextIter(&out1));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_insert(value self)
{
CAMLparam1(self);

GtkTextMark* result = gtk_text_buffer_get_insert(GtkTextBuffer_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkTextMark(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_has_selection(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_buffer_get_has_selection(GtkTextBuffer_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_end_iter(value self)
{
CAMLparam1(self);
GtkTextIter out1;

gtk_text_buffer_get_end_iter(GtkTextBuffer_val(self), &out1);
CAMLreturn(Val_GtkTextIter(&out1));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_enable_undo(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_buffer_get_enable_undo(GtkTextBuffer_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_char_count(value self)
{
CAMLparam1(self);

int result = gtk_text_buffer_get_char_count(GtkTextBuffer_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_can_undo(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_buffer_get_can_undo(GtkTextBuffer_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_can_redo(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_buffer_get_can_redo(GtkTextBuffer_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_bounds(value self)
{
CAMLparam1(self);
GtkTextIter out1;
GtkTextIter out2;

gtk_text_buffer_get_bounds(GtkTextBuffer_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_GtkTextIter(&out1));
    Store_field(ret, 1, Val_GtkTextIter(&out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_end_user_action(value self)
{
CAMLparam1(self);

gtk_text_buffer_end_user_action(GtkTextBuffer_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_end_irreversible_action(value self)
{
CAMLparam1(self);

gtk_text_buffer_end_irreversible_action(GtkTextBuffer_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_delete_selection(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gtk_text_buffer_delete_selection(GtkTextBuffer_val(self), Bool_val(arg1), Bool_val(arg2));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_delete_mark_by_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_buffer_delete_mark_by_name(GtkTextBuffer_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_delete_mark(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_buffer_delete_mark(GtkTextBuffer_val(self), GtkTextMark_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_delete_interactive(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gboolean result = gtk_text_buffer_delete_interactive(GtkTextBuffer_val(self), GtkTextIter_val(arg1), GtkTextIter_val(arg2), Bool_val(arg3));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_delete(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_text_buffer_delete(GtkTextBuffer_val(self), GtkTextIter_val(arg1), GtkTextIter_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_cut_clipboard(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_text_buffer_cut_clipboard(GtkTextBuffer_val(self), GdkClipboard_val(arg1), Bool_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_create_mark(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

GtkTextMark* result = gtk_text_buffer_create_mark(GtkTextBuffer_val(self), String_option_val(arg1), GtkTextIter_val(arg2), Bool_val(arg3));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkTextMark(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_create_child_anchor(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkTextChildAnchor* result = gtk_text_buffer_create_child_anchor(GtkTextBuffer_val(self), GtkTextIter_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkTextChildAnchor(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_copy_clipboard(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_buffer_copy_clipboard(GtkTextBuffer_val(self), GdkClipboard_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_begin_user_action(value self)
{
CAMLparam1(self);

gtk_text_buffer_begin_user_action(GtkTextBuffer_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_begin_irreversible_action(value self)
{
CAMLparam1(self);

gtk_text_buffer_begin_irreversible_action(GtkTextBuffer_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_backspace(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gboolean result = gtk_text_buffer_backspace(GtkTextBuffer_val(self), GtkTextIter_val(arg1), Bool_val(arg2), Bool_val(arg3));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_buffer_apply_tag_by_name(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_text_buffer_apply_tag_by_name(GtkTextBuffer_val(self), String_val(arg1), GtkTextIter_val(arg2), GtkTextIter_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_apply_tag(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_text_buffer_apply_tag(GtkTextBuffer_val(self), GtkTextTag_val(arg1), GtkTextIter_val(arg2), GtkTextIter_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_add_selection_clipboard(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_buffer_add_selection_clipboard(GtkTextBuffer_val(self), GdkClipboard_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_add_mark(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_text_buffer_add_mark(GtkTextBuffer_val(self), GtkTextMark_val(arg1), GtkTextIter_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_buffer_get_cursor_position(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextBuffer *obj = (GtkTextBuffer *)GtkTextBuffer_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "cursor-position");
if (pspec == NULL) caml_failwith("ml_gtk_text_buffer_get_cursor_position: property 'cursor-position' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "cursor-position", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}


CAMLprim value ml_gtk_text_buffer_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_text_buffer_get_type()));
}
