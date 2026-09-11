/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TextIter */

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

/* Copy function for GtkTextIter (value-like record with copy method) */
value copy_GtkTextIter(const GtkTextIter *ptr)
{
  if (ptr == NULL) return Val_none;
  GtkTextIter *copy = g_boxed_copy(gtk_text_iter_get_type(), ptr);
  return ml_gir_record_val_ptr_with_type(gtk_text_iter_get_type(), copy);
}


CAMLexport CAMLprim value ml_gtk_text_iter_toggles_tag(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_toggles_tag(GtkTextIter_val(self), Option_val(arg1, GtkTextTag_val, NULL));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_starts_word(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_starts_word(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_starts_tag(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_starts_tag(GtkTextIter_val(self), Option_val(arg1, GtkTextTag_val, NULL));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_starts_sentence(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_starts_sentence(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_starts_line(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_starts_line(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_set_visible_line_offset(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_iter_set_visible_line_offset(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_iter_set_visible_line_index(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_iter_set_visible_line_index(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_iter_set_offset(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_iter_set_offset(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_iter_set_line_offset(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_iter_set_line_offset(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_iter_set_line_index(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_iter_set_line_index(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_iter_set_line(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_iter_set_line(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_iter_order(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_iter_order(GtkTextIter_val(self), GtkTextIter_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_iter_is_start(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_is_start(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_is_end(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_is_end(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_is_cursor_position(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_is_cursor_position(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_inside_word(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_inside_word(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_inside_sentence(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_inside_sentence(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_in_range(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gtk_text_iter_in_range(GtkTextIter_val(self), GtkTextIter_val(arg1), GtkTextIter_val(arg2));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_has_tag(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_has_tag(GtkTextIter_val(self), GtkTextTag_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_get_visible_text(value self, value arg1)
{
CAMLparam2(self, arg1);

char* result = gtk_text_iter_get_visible_text(GtkTextIter_val(self), GtkTextIter_val(arg1));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_get_visible_slice(value self, value arg1)
{
CAMLparam2(self, arg1);

char* result = gtk_text_iter_get_visible_slice(GtkTextIter_val(self), GtkTextIter_val(arg1));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_get_visible_line_offset(value self)
{
CAMLparam1(self);

int result = gtk_text_iter_get_visible_line_offset(GtkTextIter_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_get_visible_line_index(value self)
{
CAMLparam1(self);

int result = gtk_text_iter_get_visible_line_index(GtkTextIter_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_get_toggled_tags(value self, value arg1)
{
CAMLparam2(self, arg1);

CAMLlocal3(result, item, cell);
    GList* c_result = gtk_text_iter_get_toggled_tags(GtkTextIter_val(self), Bool_val(arg1));
Val_GSList_with(c_result, result, item, cell, Val_GtkTextTag((gpointer)_tmp->data));
    g_slist_free(c_result);
    CAMLreturn(result);
}

CAMLexport CAMLprim value ml_gtk_text_iter_get_text(value self, value arg1)
{
CAMLparam2(self, arg1);

char* result = gtk_text_iter_get_text(GtkTextIter_val(self), GtkTextIter_val(arg1));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_get_tags(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = gtk_text_iter_get_tags(GtkTextIter_val(self));
Val_GSList_with(c_result, result, item, cell, Val_GtkTextTag((gpointer)_tmp->data));
    g_slist_free(c_result);
    CAMLreturn(result);
}

CAMLexport CAMLprim value ml_gtk_text_iter_get_slice(value self, value arg1)
{
CAMLparam2(self, arg1);

char* result = gtk_text_iter_get_slice(GtkTextIter_val(self), GtkTextIter_val(arg1));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_get_paintable(value self)
{
CAMLparam1(self);

GdkPaintable* result = gtk_text_iter_get_paintable(GtkTextIter_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkPaintable));
}

CAMLexport CAMLprim value ml_gtk_text_iter_get_offset(value self)
{
CAMLparam1(self);

int result = gtk_text_iter_get_offset(GtkTextIter_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_get_marks(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = gtk_text_iter_get_marks(GtkTextIter_val(self));
Val_GSList_with(c_result, result, item, cell, Val_GtkTextMark((gpointer)_tmp->data));
    g_slist_free(c_result);
    CAMLreturn(result);
}

CAMLexport CAMLprim value ml_gtk_text_iter_get_line_offset(value self)
{
CAMLparam1(self);

int result = gtk_text_iter_get_line_offset(GtkTextIter_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_get_line_index(value self)
{
CAMLparam1(self);

int result = gtk_text_iter_get_line_index(GtkTextIter_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_get_line(value self)
{
CAMLparam1(self);

int result = gtk_text_iter_get_line(GtkTextIter_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_get_language(value self)
{
CAMLparam1(self);

PangoLanguage* result = gtk_text_iter_get_language(GtkTextIter_val(self));
CAMLreturn(Val_PangoLanguage(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_get_child_anchor(value self)
{
CAMLparam1(self);

GtkTextChildAnchor* result = gtk_text_iter_get_child_anchor(GtkTextIter_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkTextChildAnchor));
}

CAMLexport CAMLprim value ml_gtk_text_iter_get_chars_in_line(value self)
{
CAMLparam1(self);

int result = gtk_text_iter_get_chars_in_line(GtkTextIter_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_get_char(value self)
{
CAMLparam1(self);

gunichar result = gtk_text_iter_get_char(GtkTextIter_val(self));
CAMLreturn(Val_long(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_get_bytes_in_line(value self)
{
CAMLparam1(self);

int result = gtk_text_iter_get_bytes_in_line(GtkTextIter_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_get_buffer(value self)
{
CAMLparam1(self);

GtkTextBuffer* result = gtk_text_iter_get_buffer(GtkTextIter_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkTextBuffer(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_forward_word_ends(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_forward_word_ends(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_forward_word_end(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_forward_word_end(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_forward_visible_word_ends(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_forward_visible_word_ends(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_forward_visible_word_end(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_forward_visible_word_end(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_forward_visible_lines(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_forward_visible_lines(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_forward_visible_line(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_forward_visible_line(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_forward_visible_cursor_positions(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_forward_visible_cursor_positions(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_forward_visible_cursor_position(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_forward_visible_cursor_position(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_forward_to_tag_toggle(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_forward_to_tag_toggle(GtkTextIter_val(self), Option_val(arg1, GtkTextTag_val, NULL));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_forward_to_line_end(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_forward_to_line_end(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_forward_to_end(value self)
{
CAMLparam1(self);

gtk_text_iter_forward_to_end(GtkTextIter_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_iter_forward_sentence_ends(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_forward_sentence_ends(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_forward_sentence_end(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_forward_sentence_end(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_forward_search(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GtkTextIter out3;
GtkTextIter out4;

gboolean result = gtk_text_iter_forward_search(GtkTextIter_val(self), String_val(arg1), GtkTextSearchFlags_val(arg2), &out3, &out4, Option_val(arg3, GtkTextIter_val, NULL));
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_GtkTextIter(&out3));
    Store_field(ret, 2, Val_GtkTextIter(&out4));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_text_iter_forward_lines(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_forward_lines(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_forward_line(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_forward_line(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_forward_cursor_positions(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_forward_cursor_positions(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_forward_cursor_position(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_forward_cursor_position(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_forward_chars(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_forward_chars(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_forward_char(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_forward_char(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_equal(GtkTextIter_val(self), GtkTextIter_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_ends_word(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_ends_word(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_ends_tag(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_ends_tag(GtkTextIter_val(self), Option_val(arg1, GtkTextTag_val, NULL));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_ends_sentence(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_ends_sentence(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_ends_line(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_ends_line(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_editable(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_editable(GtkTextIter_val(self), Bool_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_compare(value self, value arg1)
{
CAMLparam2(self, arg1);

int result = gtk_text_iter_compare(GtkTextIter_val(self), GtkTextIter_val(arg1));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_can_insert(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_can_insert(GtkTextIter_val(self), Bool_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_backward_word_starts(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_backward_word_starts(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_backward_word_start(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_backward_word_start(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_backward_visible_word_starts(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_backward_visible_word_starts(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_backward_visible_word_start(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_backward_visible_word_start(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_backward_visible_lines(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_backward_visible_lines(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_backward_visible_line(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_backward_visible_line(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_backward_visible_cursor_positions(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_backward_visible_cursor_positions(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_backward_visible_cursor_position(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_backward_visible_cursor_position(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_backward_to_tag_toggle(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_backward_to_tag_toggle(GtkTextIter_val(self), Option_val(arg1, GtkTextTag_val, NULL));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_backward_sentence_starts(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_backward_sentence_starts(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_backward_sentence_start(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_backward_sentence_start(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_backward_search(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GtkTextIter out3;
GtkTextIter out4;

gboolean result = gtk_text_iter_backward_search(GtkTextIter_val(self), String_val(arg1), GtkTextSearchFlags_val(arg2), &out3, &out4, Option_val(arg3, GtkTextIter_val, NULL));
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_GtkTextIter(&out3));
    Store_field(ret, 2, Val_GtkTextIter(&out4));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_text_iter_backward_lines(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_backward_lines(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_backward_line(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_backward_line(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_backward_cursor_positions(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_backward_cursor_positions(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_backward_cursor_position(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_backward_cursor_position(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_backward_chars(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_text_iter_backward_chars(GtkTextIter_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_backward_char(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_iter_backward_char(GtkTextIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_iter_assign(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_iter_assign(GtkTextIter_val(self), GtkTextIter_val(arg1));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_text_iter_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_text_iter_get_type()));
}
