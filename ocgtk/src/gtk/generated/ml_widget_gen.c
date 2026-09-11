/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Widget */

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


CAMLexport CAMLprim value ml_gtk_widget_unset_state_flags(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_unset_state_flags(GtkWidget_val(self), GtkStateFlags_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_unrealize(value self)
{
CAMLparam1(self);

gtk_widget_unrealize(GtkWidget_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_unparent(value self)
{
CAMLparam1(self);

gtk_widget_unparent(GtkWidget_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_unmap(value self)
{
CAMLparam1(self);

gtk_widget_unmap(GtkWidget_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_trigger_tooltip_query(value self)
{
CAMLparam1(self);

gtk_widget_trigger_tooltip_query(GtkWidget_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_translate_coordinates(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
double out4;
double out5;

gboolean result = gtk_widget_translate_coordinates(GtkWidget_val(self), GtkWidget_val(arg1), Double_val(arg2), Double_val(arg3), &out4, &out5);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, caml_copy_double(out4));
    Store_field(ret, 2, caml_copy_double(out5));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_widget_snapshot_child(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_widget_snapshot_child(GtkWidget_val(self), GtkWidget_val(arg1), GtkSnapshot_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_show(value self)
{
CAMLparam1(self);

gtk_widget_show(GtkWidget_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_should_layout(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_should_layout(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_set_visible(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_visible(GtkWidget_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_vexpand_set(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_vexpand_set(GtkWidget_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_vexpand(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_vexpand(GtkWidget_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_valign(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_valign(GtkWidget_val(self), GtkAlign_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_tooltip_text(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_tooltip_text(GtkWidget_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_tooltip_markup(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_tooltip_markup(GtkWidget_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_state_flags(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_widget_set_state_flags(GtkWidget_val(self), GtkStateFlags_val(arg1), Bool_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_size_request(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_widget_set_size_request(GtkWidget_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_sensitive(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_sensitive(GtkWidget_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_receives_default(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_receives_default(GtkWidget_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_parent(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_parent(GtkWidget_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_overflow(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_overflow(GtkWidget_val(self), GtkOverflow_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_opacity(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_opacity(GtkWidget_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_name(GtkWidget_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_margin_top(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_margin_top(GtkWidget_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_margin_start(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_margin_start(GtkWidget_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_margin_end(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_margin_end(GtkWidget_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_margin_bottom(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_margin_bottom(GtkWidget_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,18,0)

CAMLexport CAMLprim value ml_gtk_widget_set_limit_events(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_limit_events(GtkWidget_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_widget_set_limit_events(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Widget requires GTK >= 4.18");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_widget_set_layout_manager(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_layout_manager(GtkWidget_val(self), Option_val(arg1, GtkLayoutManager_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_hexpand_set(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_hexpand_set(GtkWidget_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_hexpand(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_hexpand(GtkWidget_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_has_tooltip(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_has_tooltip(GtkWidget_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_halign(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_halign(GtkWidget_val(self), GtkAlign_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_font_options(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_font_options(GtkWidget_val(self), Option_val(arg1, cairo_font_options_t_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_font_map(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_font_map(GtkWidget_val(self), Option_val(arg1, PangoFontMap_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_focusable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_focusable(GtkWidget_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_focus_on_click(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_focus_on_click(GtkWidget_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_focus_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_focus_child(GtkWidget_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_direction(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_direction(GtkWidget_val(self), GtkTextDirection_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_cursor_from_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_cursor_from_name(GtkWidget_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_cursor(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_cursor(GtkWidget_val(self), Option_val(arg1, GdkCursor_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_css_classes(value self, value arg1)
{
CAMLparam2(self, arg1);
    int arg1_length = Wosize_val(arg1);
    const char** c_arg1 = (const char**)g_malloc(sizeof(const char*) * (arg1_length + 1));
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = String_val(Field(arg1, i));
    }
    c_arg1[arg1_length] = NULL;

gtk_widget_set_css_classes(GtkWidget_val(self), c_arg1);
    g_free(c_arg1);
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_child_visible(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_child_visible(GtkWidget_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_can_target(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_can_target(GtkWidget_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_set_can_focus(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_set_can_focus(GtkWidget_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_remove_tick_callback(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_remove_tick_callback(GtkWidget_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_remove_mnemonic_label(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_remove_mnemonic_label(GtkWidget_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_remove_css_class(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_remove_css_class(GtkWidget_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_remove_controller(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_remove_controller(GtkWidget_val(self), GtkEventController_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_realize(value self)
{
CAMLparam1(self);

gtk_widget_realize(GtkWidget_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_queue_resize(value self)
{
CAMLparam1(self);

gtk_widget_queue_resize(GtkWidget_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_queue_draw(value self)
{
CAMLparam1(self);

gtk_widget_queue_draw(GtkWidget_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_queue_allocate(value self)
{
CAMLparam1(self);

gtk_widget_queue_allocate(GtkWidget_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_pick(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

GtkWidget* result = gtk_widget_pick(GtkWidget_val(self), Double_val(arg1), Double_val(arg2), GtkPickFlags_val(arg3));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_widget_observe_controllers(value self)
{
CAMLparam1(self);

GListModel* result = gtk_widget_observe_controllers(GtkWidget_val(self));
CAMLreturn(Val_GListModel(result));
}

CAMLexport CAMLprim value ml_gtk_widget_observe_children(value self)
{
CAMLparam1(self);

GListModel* result = gtk_widget_observe_children(GtkWidget_val(self));
CAMLreturn(Val_GListModel(result));
}

CAMLexport CAMLprim value ml_gtk_widget_mnemonic_activate(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_widget_mnemonic_activate(GtkWidget_val(self), Bool_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_measure(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
int out3;
int out4;
int out5;
int out6;

gtk_widget_measure(GtkWidget_val(self), GtkOrientation_val(arg1), Int_val(arg2), &out3, &out4, &out5, &out6);
CAMLlocal1(ret);
    ret = caml_alloc(4, 0);
    Store_field(ret, 0, Val_int(out3));
    Store_field(ret, 1, Val_int(out4));
    Store_field(ret, 2, Val_int(out5));
    Store_field(ret, 3, Val_int(out6));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_widget_map(value self)
{
CAMLparam1(self);

gtk_widget_map(GtkWidget_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_list_mnemonic_labels(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = gtk_widget_list_mnemonic_labels(GtkWidget_val(self));
Val_GList_with(c_result, result, item, cell, Val_GtkWidget((gpointer)_tmp->data));
    g_list_free(c_result);
    CAMLreturn(result);
}

CAMLexport CAMLprim value ml_gtk_widget_keynav_failed(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_widget_keynav_failed(GtkWidget_val(self), GtkDirectionType_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_is_visible(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_is_visible(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_is_sensitive(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_is_sensitive(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_is_focus(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_is_focus(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_is_drawable(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_is_drawable(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_is_ancestor(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_widget_is_ancestor(GtkWidget_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_insert_before(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_widget_insert_before(GtkWidget_val(self), GtkWidget_val(arg1), Option_val(arg2, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_insert_after(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_widget_insert_after(GtkWidget_val(self), GtkWidget_val(arg1), Option_val(arg2, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_insert_action_group(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_widget_insert_action_group(GtkWidget_val(self), String_val(arg1), Option_val(arg2, GActionGroup_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_init_template(value self)
{
CAMLparam1(self);

gtk_widget_init_template(GtkWidget_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_in_destruction(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_in_destruction(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_hide(value self)
{
CAMLparam1(self);

gtk_widget_hide(GtkWidget_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_has_visible_focus(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_has_visible_focus(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_has_focus(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_has_focus(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_has_default(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_has_default(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_has_css_class(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_widget_has_css_class(GtkWidget_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_grab_focus(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_grab_focus(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_width(value self)
{
CAMLparam1(self);

int result = gtk_widget_get_width(GtkWidget_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_visible(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_get_visible(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_vexpand_set(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_get_vexpand_set(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_vexpand(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_get_vexpand(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_valign(value self)
{
CAMLparam1(self);

GtkAlign result = gtk_widget_get_valign(GtkWidget_val(self));
CAMLreturn(Val_GtkAlign(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_tooltip_text(value self)
{
CAMLparam1(self);

const char* result = gtk_widget_get_tooltip_text(GtkWidget_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_tooltip_markup(value self)
{
CAMLparam1(self);

const char* result = gtk_widget_get_tooltip_markup(GtkWidget_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_template_child(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

GObject* result = gtk_widget_get_template_child(GtkWidget_val(self), GType_val(arg1), String_val(arg2));
CAMLreturn(ml_gobject_val_of_ext(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_style_context(value self)
{
CAMLparam1(self);

GtkStyleContext* result = gtk_widget_get_style_context(GtkWidget_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkStyleContext(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_state_flags(value self)
{
CAMLparam1(self);

GtkStateFlags result = gtk_widget_get_state_flags(GtkWidget_val(self));
CAMLreturn(Val_GtkStateFlags(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_size_request(value self)
{
CAMLparam1(self);
int out1;
int out2;

gtk_widget_get_size_request(GtkWidget_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_widget_get_size(value self, value arg1)
{
CAMLparam2(self, arg1);

int result = gtk_widget_get_size(GtkWidget_val(self), GtkOrientation_val(arg1));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_settings(value self)
{
CAMLparam1(self);

GtkSettings* result = gtk_widget_get_settings(GtkWidget_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkSettings(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_sensitive(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_get_sensitive(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_scale_factor(value self)
{
CAMLparam1(self);

int result = gtk_widget_get_scale_factor(GtkWidget_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_root(value self)
{
CAMLparam1(self);

GtkRoot* result = gtk_widget_get_root(GtkWidget_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkRoot));
}

CAMLexport CAMLprim value ml_gtk_widget_get_request_mode(value self)
{
CAMLparam1(self);

GtkSizeRequestMode result = gtk_widget_get_request_mode(GtkWidget_val(self));
CAMLreturn(Val_GtkSizeRequestMode(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_receives_default(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_get_receives_default(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_realized(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_get_realized(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_primary_clipboard(value self)
{
CAMLparam1(self);

GdkClipboard* result = gtk_widget_get_primary_clipboard(GtkWidget_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkClipboard(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_prev_sibling(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_widget_get_prev_sibling(GtkWidget_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_widget_get_preferred_size(value self)
{
CAMLparam1(self);
GtkRequisition out1;
GtkRequisition out2;

gtk_widget_get_preferred_size(GtkWidget_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_GtkRequisition(&out1));
    Store_field(ret, 1, Val_GtkRequisition(&out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_widget_get_parent(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_widget_get_parent(GtkWidget_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_widget_get_pango_context(value self)
{
CAMLparam1(self);

PangoContext* result = gtk_widget_get_pango_context(GtkWidget_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_PangoContext(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_overflow(value self)
{
CAMLparam1(self);

GtkOverflow result = gtk_widget_get_overflow(GtkWidget_val(self));
CAMLreturn(Val_GtkOverflow(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_opacity(value self)
{
CAMLparam1(self);

double result = gtk_widget_get_opacity(GtkWidget_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_next_sibling(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_widget_get_next_sibling(GtkWidget_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_widget_get_native(value self)
{
CAMLparam1(self);

GtkNative* result = gtk_widget_get_native(GtkWidget_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkNative));
}

CAMLexport CAMLprim value ml_gtk_widget_get_name(value self)
{
CAMLparam1(self);

const char* result = gtk_widget_get_name(GtkWidget_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_margin_top(value self)
{
CAMLparam1(self);

int result = gtk_widget_get_margin_top(GtkWidget_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_margin_start(value self)
{
CAMLparam1(self);

int result = gtk_widget_get_margin_start(GtkWidget_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_margin_end(value self)
{
CAMLparam1(self);

int result = gtk_widget_get_margin_end(GtkWidget_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_margin_bottom(value self)
{
CAMLparam1(self);

int result = gtk_widget_get_margin_bottom(GtkWidget_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_mapped(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_get_mapped(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,18,0)

CAMLexport CAMLprim value ml_gtk_widget_get_limit_events(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_get_limit_events(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gtk_widget_get_limit_events(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Widget requires GTK >= 4.18");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_widget_get_layout_manager(value self)
{
CAMLparam1(self);

GtkLayoutManager* result = gtk_widget_get_layout_manager(GtkWidget_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkLayoutManager));
}

CAMLexport CAMLprim value ml_gtk_widget_get_last_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_widget_get_last_child(GtkWidget_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_widget_get_hexpand_set(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_get_hexpand_set(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_hexpand(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_get_hexpand(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_height(value self)
{
CAMLparam1(self);

int result = gtk_widget_get_height(GtkWidget_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_has_tooltip(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_get_has_tooltip(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_halign(value self)
{
CAMLparam1(self);

GtkAlign result = gtk_widget_get_halign(GtkWidget_val(self));
CAMLreturn(Val_GtkAlign(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_frame_clock(value self)
{
CAMLparam1(self);

GdkFrameClock* result = gtk_widget_get_frame_clock(GtkWidget_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkFrameClock));
}

CAMLexport CAMLprim value ml_gtk_widget_get_font_options(value self)
{
CAMLparam1(self);

const cairo_font_options_t* result = gtk_widget_get_font_options(GtkWidget_val(self));
if (result) result = g_boxed_copy(cairo_gobject_font_options_get_type(), result);
CAMLreturn(Val_option(result, Val_cairo_font_options_t));
}

CAMLexport CAMLprim value ml_gtk_widget_get_font_map(value self)
{
CAMLparam1(self);

PangoFontMap* result = gtk_widget_get_font_map(GtkWidget_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_PangoFontMap));
}

CAMLexport CAMLprim value ml_gtk_widget_get_focusable(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_get_focusable(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_focus_on_click(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_get_focus_on_click(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_focus_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_widget_get_focus_child(GtkWidget_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_widget_get_first_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_widget_get_first_child(GtkWidget_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_widget_get_display(value self)
{
CAMLparam1(self);

GdkDisplay* result = gtk_widget_get_display(GtkWidget_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkDisplay(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_direction(value self)
{
CAMLparam1(self);

GtkTextDirection result = gtk_widget_get_direction(GtkWidget_val(self));
CAMLreturn(Val_GtkTextDirection(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_cursor(value self)
{
CAMLparam1(self);

GdkCursor* result = gtk_widget_get_cursor(GtkWidget_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkCursor));
}

CAMLexport CAMLprim value ml_gtk_widget_get_css_name(value self)
{
CAMLparam1(self);

const char* result = gtk_widget_get_css_name(GtkWidget_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_css_classes(value self)
{
CAMLparam1(self);

char** result = gtk_widget_get_css_classes(GtkWidget_val(self));
    int result_length = 0;
    while (result[result_length] != NULL) result_length++;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, caml_copy_string(result[i]));
    }
    for (int i = 0; i < result_length; i++) {
      g_free((gpointer)result[i]);
    }
    g_free(result);
CAMLreturn(ml_result);
}

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_widget_get_color(value self)
{
CAMLparam1(self);
GdkRGBA out1;

gtk_widget_get_color(GtkWidget_val(self), &out1);
CAMLreturn(Val_GdkRGBA(&out1));
}

#else

CAMLexport CAMLprim value ml_gtk_widget_get_color(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Widget requires GTK >= 4.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_widget_get_clipboard(value self)
{
CAMLparam1(self);

GdkClipboard* result = gtk_widget_get_clipboard(GtkWidget_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkClipboard(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_child_visible(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_get_child_visible(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_can_target(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_get_can_target(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_can_focus(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_get_can_focus(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_widget_get_baseline(value self)
{
CAMLparam1(self);

int result = gtk_widget_get_baseline(GtkWidget_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_gtk_widget_get_baseline(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Widget requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_widget_get_ancestor(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkWidget* result = gtk_widget_get_ancestor(GtkWidget_val(self), GType_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_widget_get_allocated_width(value self)
{
CAMLparam1(self);

int result = gtk_widget_get_allocated_width(GtkWidget_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_allocated_height(value self)
{
CAMLparam1(self);

int result = gtk_widget_get_allocated_height(GtkWidget_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_widget_get_allocated_baseline(value self)
{
CAMLparam1(self);

int result = gtk_widget_get_allocated_baseline(GtkWidget_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_widget_error_bell(value self)
{
CAMLparam1(self);

gtk_widget_error_bell(GtkWidget_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_drag_check_threshold(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gboolean result = gtk_drag_check_threshold(GtkWidget_val(self), Int_val(arg1), Int_val(arg2), Int_val(arg3), Int_val(arg4));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,8,0)

CAMLexport CAMLprim value ml_gtk_widget_dispose_template(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_dispose_template(GtkWidget_val(self), GType_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_widget_dispose_template(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Widget requires GTK >= 4.8");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_widget_create_pango_layout(value self, value arg1)
{
CAMLparam2(self, arg1);

PangoLayout* result = gtk_widget_create_pango_layout(GtkWidget_val(self), String_option_val(arg1));
CAMLreturn(Val_PangoLayout(result));
}

CAMLexport CAMLprim value ml_gtk_widget_create_pango_context(value self)
{
CAMLparam1(self);

PangoContext* result = gtk_widget_create_pango_context(GtkWidget_val(self));
CAMLreturn(Val_PangoContext(result));
}

CAMLexport CAMLprim value ml_gtk_widget_contains(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gtk_widget_contains(GtkWidget_val(self), Double_val(arg1), Double_val(arg2));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_compute_transform(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_matrix_t out2;

gboolean result = gtk_widget_compute_transform(GtkWidget_val(self), GtkWidget_val(arg1), &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_graphene_matrix_t(&out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_widget_compute_point(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
graphene_point_t out3;

gboolean result = gtk_widget_compute_point(GtkWidget_val(self), GtkWidget_val(arg1), graphene_point_t_val(arg2), &out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_graphene_point_t(&out3));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_widget_compute_expand(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_widget_compute_expand(GtkWidget_val(self), GtkOrientation_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_compute_bounds(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_rect_t out2;

gboolean result = gtk_widget_compute_bounds(GtkWidget_val(self), GtkWidget_val(arg1), &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_graphene_rect_t(&out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_widget_child_focus(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_widget_child_focus(GtkWidget_val(self), GtkDirectionType_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_allocate(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gtk_widget_allocate(GtkWidget_val(self), Int_val(arg1), Int_val(arg2), Int_val(arg3), Option_val(arg4, GskTransform_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_add_mnemonic_label(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_add_mnemonic_label(GtkWidget_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_add_css_class(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_add_css_class(GtkWidget_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_add_controller(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_widget_add_controller(GtkWidget_val(self), GtkEventController_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_activate_default(value self)
{
CAMLparam1(self);

gtk_widget_activate_default(GtkWidget_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_activate_action_variant(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gtk_widget_activate_action_variant(GtkWidget_val(self), String_val(arg1), Option_val(arg2, GVariant_val, NULL));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_activate(value self)
{
CAMLparam1(self);

gboolean result = gtk_widget_activate(GtkWidget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_widget_action_set_enabled(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_widget_action_set_enabled(GtkWidget_val(self), String_val(arg1), Bool_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_get_height_request(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkWidget *obj = (GtkWidget *)GtkWidget_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "height-request");
if (pspec == NULL) caml_failwith("ml_gtk_widget_get_height_request: property 'height-request' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "height-request", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_widget_set_height_request(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkWidget *obj = (GtkWidget *)GtkWidget_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "height-request");
if (pspec == NULL) caml_failwith("ml_gtk_widget_set_height_request: property 'height-request' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "height-request", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_widget_get_width_request(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkWidget *obj = (GtkWidget *)GtkWidget_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "width-request");
if (pspec == NULL) caml_failwith("ml_gtk_widget_get_width_request: property 'width-request' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "width-request", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_widget_set_width_request(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkWidget *obj = (GtkWidget *)GtkWidget_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "width-request");
if (pspec == NULL) caml_failwith("ml_gtk_widget_set_width_request: property 'width-request' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "width-request", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_widget_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_widget_get_type()));
}
