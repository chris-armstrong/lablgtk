/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Entry */

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


CAMLexport CAMLprim value ml_gtk_entry_new(value unit)
{
CAMLparam1(unit);

GtkEntry *obj = gtk_entry_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkEntry(obj));
}
CAMLexport CAMLprim value ml_gtk_entry_new_with_buffer(value arg1)
{
CAMLparam1(arg1);

GtkEntry *obj = gtk_entry_new_with_buffer(GtkEntryBuffer_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkEntry(obj));
}
CAMLexport CAMLprim value ml_gtk_entry_unset_invisible_char(value self)
{
CAMLparam1(self);

gtk_entry_unset_invisible_char(GtkEntry_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_visibility(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_entry_set_visibility(GtkEntry_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_tabs(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_entry_set_tabs(GtkEntry_val(self), Option_val(arg1, PangoTabArray_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_progress_pulse_step(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_entry_set_progress_pulse_step(GtkEntry_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_progress_fraction(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_entry_set_progress_fraction(GtkEntry_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_placeholder_text(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_entry_set_placeholder_text(GtkEntry_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_overwrite_mode(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_entry_set_overwrite_mode(GtkEntry_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gtk_entry_set_menu_entry_icon_text(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_entry_set_menu_entry_icon_text(GtkEntry_val(self), GtkEntryIconPosition_val(arg1), String_val(arg2));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_entry_set_menu_entry_icon_text(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Entry requires GTK >= 4.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_entry_set_max_length(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_entry_set_max_length(GtkEntry_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_invisible_char(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_entry_set_invisible_char(GtkEntry_val(self), Long_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_input_purpose(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_entry_set_input_purpose(GtkEntry_val(self), GtkInputPurpose_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_input_hints(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_entry_set_input_hints(GtkEntry_val(self), GtkInputHints_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_icon_tooltip_text(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_entry_set_icon_tooltip_text(GtkEntry_val(self), GtkEntryIconPosition_val(arg1), String_option_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_icon_tooltip_markup(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_entry_set_icon_tooltip_markup(GtkEntry_val(self), GtkEntryIconPosition_val(arg1), String_option_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_icon_sensitive(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_entry_set_icon_sensitive(GtkEntry_val(self), GtkEntryIconPosition_val(arg1), Bool_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_icon_from_paintable(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_entry_set_icon_from_paintable(GtkEntry_val(self), GtkEntryIconPosition_val(arg1), Option_val(arg2, GdkPaintable_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_icon_from_icon_name(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_entry_set_icon_from_icon_name(GtkEntry_val(self), GtkEntryIconPosition_val(arg1), String_option_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_icon_from_gicon(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_entry_set_icon_from_gicon(GtkEntry_val(self), GtkEntryIconPosition_val(arg1), Option_val(arg2, GIcon_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_icon_drag_source(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_entry_set_icon_drag_source(GtkEntry_val(self), GtkEntryIconPosition_val(arg1), GdkContentProvider_val(arg2), GdkDragAction_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_icon_activatable(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_entry_set_icon_activatable(GtkEntry_val(self), GtkEntryIconPosition_val(arg1), Bool_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_has_frame(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_entry_set_has_frame(GtkEntry_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_extra_menu(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_entry_set_extra_menu(GtkEntry_val(self), Option_val(arg1, GMenuModel_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_completion(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_entry_set_completion(GtkEntry_val(self), Option_val(arg1, GtkEntryCompletion_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_buffer(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_entry_set_buffer(GtkEntry_val(self), GtkEntryBuffer_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_attributes(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_entry_set_attributes(GtkEntry_val(self), PangoAttrList_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_alignment(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_entry_set_alignment(GtkEntry_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_set_activates_default(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_entry_set_activates_default(GtkEntry_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_reset_im_context(value self)
{
CAMLparam1(self);

gtk_entry_reset_im_context(GtkEntry_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_progress_pulse(value self)
{
CAMLparam1(self);

gtk_entry_progress_pulse(GtkEntry_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_grab_focus_without_selecting(value self)
{
CAMLparam1(self);

gboolean result = gtk_entry_grab_focus_without_selecting(GtkEntry_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_visibility(value self)
{
CAMLparam1(self);

gboolean result = gtk_entry_get_visibility(GtkEntry_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_text_length(value self)
{
CAMLparam1(self);

guint16 result = gtk_entry_get_text_length(GtkEntry_val(self));
CAMLreturn(Val_uint16(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_tabs(value self)
{
CAMLparam1(self);

PangoTabArray* result = gtk_entry_get_tabs(GtkEntry_val(self));
if (result) result = g_boxed_copy(pango_tab_array_get_type(), result);
CAMLreturn(Val_option(result, Val_PangoTabArray));
}

CAMLexport CAMLprim value ml_gtk_entry_get_progress_pulse_step(value self)
{
CAMLparam1(self);

double result = gtk_entry_get_progress_pulse_step(GtkEntry_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_progress_fraction(value self)
{
CAMLparam1(self);

double result = gtk_entry_get_progress_fraction(GtkEntry_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_placeholder_text(value self)
{
CAMLparam1(self);

const char* result = gtk_entry_get_placeholder_text(GtkEntry_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_overwrite_mode(value self)
{
CAMLparam1(self);

gboolean result = gtk_entry_get_overwrite_mode(GtkEntry_val(self));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gtk_entry_get_menu_entry_icon_text(value self, value arg1)
{
CAMLparam2(self, arg1);

const gchar* result = gtk_entry_get_menu_entry_icon_text(GtkEntry_val(self), GtkEntryIconPosition_val(arg1));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_gtk_entry_get_menu_entry_icon_text(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Entry requires GTK >= 4.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_entry_get_max_length(value self)
{
CAMLparam1(self);

int result = gtk_entry_get_max_length(GtkEntry_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_invisible_char(value self)
{
CAMLparam1(self);

gunichar result = gtk_entry_get_invisible_char(GtkEntry_val(self));
CAMLreturn(Val_long(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_input_purpose(value self)
{
CAMLparam1(self);

GtkInputPurpose result = gtk_entry_get_input_purpose(GtkEntry_val(self));
CAMLreturn(Val_GtkInputPurpose(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_input_hints(value self)
{
CAMLparam1(self);

GtkInputHints result = gtk_entry_get_input_hints(GtkEntry_val(self));
CAMLreturn(Val_GtkInputHints(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_icon_tooltip_text(value self, value arg1)
{
CAMLparam2(self, arg1);

char* result = gtk_entry_get_icon_tooltip_text(GtkEntry_val(self), GtkEntryIconPosition_val(arg1));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_icon_tooltip_markup(value self, value arg1)
{
CAMLparam2(self, arg1);

char* result = gtk_entry_get_icon_tooltip_markup(GtkEntry_val(self), GtkEntryIconPosition_val(arg1));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_icon_storage_type(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkImageType result = gtk_entry_get_icon_storage_type(GtkEntry_val(self), GtkEntryIconPosition_val(arg1));
CAMLreturn(Val_GtkImageType(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_icon_sensitive(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_entry_get_icon_sensitive(GtkEntry_val(self), GtkEntryIconPosition_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_icon_paintable(value self, value arg1)
{
CAMLparam2(self, arg1);

GdkPaintable* result = gtk_entry_get_icon_paintable(GtkEntry_val(self), GtkEntryIconPosition_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkPaintable));
}

CAMLexport CAMLprim value ml_gtk_entry_get_icon_name(value self, value arg1)
{
CAMLparam2(self, arg1);

const char* result = gtk_entry_get_icon_name(GtkEntry_val(self), GtkEntryIconPosition_val(arg1));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_icon_gicon(value self, value arg1)
{
CAMLparam2(self, arg1);

GIcon* result = gtk_entry_get_icon_gicon(GtkEntry_val(self), GtkEntryIconPosition_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GIcon));
}

CAMLexport CAMLprim value ml_gtk_entry_get_icon_at_pos(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

int result = gtk_entry_get_icon_at_pos(GtkEntry_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_icon_area(value self, value arg1)
{
CAMLparam2(self, arg1);
GdkRectangle out2;

gtk_entry_get_icon_area(GtkEntry_val(self), GtkEntryIconPosition_val(arg1), &out2);
CAMLreturn(Val_GdkRectangle(&out2));
}

CAMLexport CAMLprim value ml_gtk_entry_get_icon_activatable(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_entry_get_icon_activatable(GtkEntry_val(self), GtkEntryIconPosition_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_has_frame(value self)
{
CAMLparam1(self);

gboolean result = gtk_entry_get_has_frame(GtkEntry_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_extra_menu(value self)
{
CAMLparam1(self);

GMenuModel* result = gtk_entry_get_extra_menu(GtkEntry_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GMenuModel));
}

CAMLexport CAMLprim value ml_gtk_entry_get_current_icon_drag_source(value self)
{
CAMLparam1(self);

int result = gtk_entry_get_current_icon_drag_source(GtkEntry_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_completion(value self)
{
CAMLparam1(self);

GtkEntryCompletion* result = gtk_entry_get_completion(GtkEntry_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkEntryCompletion));
}

CAMLexport CAMLprim value ml_gtk_entry_get_buffer(value self)
{
CAMLparam1(self);

GtkEntryBuffer* result = gtk_entry_get_buffer(GtkEntry_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkEntryBuffer(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_attributes(value self)
{
CAMLparam1(self);

PangoAttrList* result = gtk_entry_get_attributes(GtkEntry_val(self));
if (result) result = g_boxed_copy(pango_attr_list_get_type(), result);
CAMLreturn(Val_option(result, Val_PangoAttrList));
}

CAMLexport CAMLprim value ml_gtk_entry_get_alignment(value self)
{
CAMLparam1(self);

float result = gtk_entry_get_alignment(GtkEntry_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_activates_default(value self)
{
CAMLparam1(self);

gboolean result = gtk_entry_get_activates_default(GtkEntry_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_entry_get_enable_emoji_completion(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "enable-emoji-completion");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_enable_emoji_completion: property 'enable-emoji-completion' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "enable-emoji-completion", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_set_enable_emoji_completion(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "enable-emoji-completion");
if (pspec == NULL) caml_failwith("ml_gtk_entry_set_enable_emoji_completion: property 'enable-emoji-completion' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "enable-emoji-completion", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_get_im_module(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "im-module");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_im_module: property 'im-module' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "im-module", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_set_im_module(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "im-module");
if (pspec == NULL) caml_failwith("ml_gtk_entry_set_im_module: property 'im-module' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "im-module", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_get_invisible_char_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "invisible-char-set");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_invisible_char_set: property 'invisible-char-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "invisible-char-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_set_invisible_char_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "invisible-char-set");
if (pspec == NULL) caml_failwith("ml_gtk_entry_set_invisible_char_set: property 'invisible-char-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "invisible-char-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gtk_entry_get_menu_entry_icon_primary_text(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "menu-entry-icon-primary-text");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_menu_entry_icon_primary_text: property 'menu-entry-icon-primary-text' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "menu-entry-icon-primary-text", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_entry_get_menu_entry_icon_primary_text(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Entry requires GTK >= 4.20");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gtk_entry_set_menu_entry_icon_primary_text(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "menu-entry-icon-primary-text");
if (pspec == NULL) caml_failwith("ml_gtk_entry_set_menu_entry_icon_primary_text: property 'menu-entry-icon-primary-text' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "menu-entry-icon-primary-text", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_entry_set_menu_entry_icon_primary_text(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Entry requires GTK >= 4.20");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gtk_entry_get_menu_entry_icon_secondary_text(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "menu-entry-icon-secondary-text");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_menu_entry_icon_secondary_text: property 'menu-entry-icon-secondary-text' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "menu-entry-icon-secondary-text", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_entry_get_menu_entry_icon_secondary_text(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Entry requires GTK >= 4.20");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gtk_entry_set_menu_entry_icon_secondary_text(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "menu-entry-icon-secondary-text");
if (pspec == NULL) caml_failwith("ml_gtk_entry_set_menu_entry_icon_secondary_text: property 'menu-entry-icon-secondary-text' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "menu-entry-icon-secondary-text", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_entry_set_menu_entry_icon_secondary_text(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Entry requires GTK >= 4.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_entry_get_primary_icon_activatable(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "primary-icon-activatable");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_primary_icon_activatable: property 'primary-icon-activatable' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "primary-icon-activatable", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_set_primary_icon_activatable(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "primary-icon-activatable");
if (pspec == NULL) caml_failwith("ml_gtk_entry_set_primary_icon_activatable: property 'primary-icon-activatable' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "primary-icon-activatable", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_get_primary_icon_gicon(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    GIcon *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "primary-icon-gicon");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_primary_icon_gicon: property 'primary-icon-gicon' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "primary-icon-gicon", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GIcon(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_set_primary_icon_gicon(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    GIcon *c_value = GIcon_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "primary-icon-gicon");
if (pspec == NULL) caml_failwith("ml_gtk_entry_set_primary_icon_gicon: property 'primary-icon-gicon' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          caml_failwith("unsupported property type");
g_object_set_property(G_OBJECT(obj), "primary-icon-gicon", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_get_primary_icon_name(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "primary-icon-name");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_primary_icon_name: property 'primary-icon-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "primary-icon-name", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_set_primary_icon_name(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "primary-icon-name");
if (pspec == NULL) caml_failwith("ml_gtk_entry_set_primary_icon_name: property 'primary-icon-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "primary-icon-name", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_get_primary_icon_paintable(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    GdkPaintable *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "primary-icon-paintable");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_primary_icon_paintable: property 'primary-icon-paintable' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "primary-icon-paintable", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GdkPaintable(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_set_primary_icon_paintable(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    GdkPaintable *c_value = GdkPaintable_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "primary-icon-paintable");
if (pspec == NULL) caml_failwith("ml_gtk_entry_set_primary_icon_paintable: property 'primary-icon-paintable' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          caml_failwith("unsupported property type");
g_object_set_property(G_OBJECT(obj), "primary-icon-paintable", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_get_primary_icon_sensitive(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "primary-icon-sensitive");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_primary_icon_sensitive: property 'primary-icon-sensitive' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "primary-icon-sensitive", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_set_primary_icon_sensitive(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "primary-icon-sensitive");
if (pspec == NULL) caml_failwith("ml_gtk_entry_set_primary_icon_sensitive: property 'primary-icon-sensitive' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "primary-icon-sensitive", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_get_primary_icon_storage_type(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    GtkImageType prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "primary-icon-storage-type");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_primary_icon_storage_type: property 'primary-icon-storage-type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "primary-icon-storage-type", &prop_gvalue);
          prop_value = (GtkImageType)g_value_get_enum(&prop_gvalue);

      result = Val_GtkImageType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_get_primary_icon_tooltip_markup(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "primary-icon-tooltip-markup");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_primary_icon_tooltip_markup: property 'primary-icon-tooltip-markup' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "primary-icon-tooltip-markup", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_set_primary_icon_tooltip_markup(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "primary-icon-tooltip-markup");
if (pspec == NULL) caml_failwith("ml_gtk_entry_set_primary_icon_tooltip_markup: property 'primary-icon-tooltip-markup' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "primary-icon-tooltip-markup", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_get_primary_icon_tooltip_text(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "primary-icon-tooltip-text");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_primary_icon_tooltip_text: property 'primary-icon-tooltip-text' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "primary-icon-tooltip-text", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_set_primary_icon_tooltip_text(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "primary-icon-tooltip-text");
if (pspec == NULL) caml_failwith("ml_gtk_entry_set_primary_icon_tooltip_text: property 'primary-icon-tooltip-text' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "primary-icon-tooltip-text", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_get_scroll_offset(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "scroll-offset");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_scroll_offset: property 'scroll-offset' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "scroll-offset", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_get_secondary_icon_activatable(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "secondary-icon-activatable");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_secondary_icon_activatable: property 'secondary-icon-activatable' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "secondary-icon-activatable", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_set_secondary_icon_activatable(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "secondary-icon-activatable");
if (pspec == NULL) caml_failwith("ml_gtk_entry_set_secondary_icon_activatable: property 'secondary-icon-activatable' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "secondary-icon-activatable", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_get_secondary_icon_gicon(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    GIcon *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "secondary-icon-gicon");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_secondary_icon_gicon: property 'secondary-icon-gicon' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "secondary-icon-gicon", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GIcon(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_set_secondary_icon_gicon(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    GIcon *c_value = GIcon_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "secondary-icon-gicon");
if (pspec == NULL) caml_failwith("ml_gtk_entry_set_secondary_icon_gicon: property 'secondary-icon-gicon' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          caml_failwith("unsupported property type");
g_object_set_property(G_OBJECT(obj), "secondary-icon-gicon", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_get_secondary_icon_name(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "secondary-icon-name");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_secondary_icon_name: property 'secondary-icon-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "secondary-icon-name", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_set_secondary_icon_name(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "secondary-icon-name");
if (pspec == NULL) caml_failwith("ml_gtk_entry_set_secondary_icon_name: property 'secondary-icon-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "secondary-icon-name", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_get_secondary_icon_paintable(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    GdkPaintable *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "secondary-icon-paintable");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_secondary_icon_paintable: property 'secondary-icon-paintable' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "secondary-icon-paintable", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GdkPaintable(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_set_secondary_icon_paintable(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    GdkPaintable *c_value = GdkPaintable_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "secondary-icon-paintable");
if (pspec == NULL) caml_failwith("ml_gtk_entry_set_secondary_icon_paintable: property 'secondary-icon-paintable' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          caml_failwith("unsupported property type");
g_object_set_property(G_OBJECT(obj), "secondary-icon-paintable", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_get_secondary_icon_sensitive(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "secondary-icon-sensitive");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_secondary_icon_sensitive: property 'secondary-icon-sensitive' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "secondary-icon-sensitive", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_set_secondary_icon_sensitive(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "secondary-icon-sensitive");
if (pspec == NULL) caml_failwith("ml_gtk_entry_set_secondary_icon_sensitive: property 'secondary-icon-sensitive' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "secondary-icon-sensitive", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_get_secondary_icon_storage_type(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    GtkImageType prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "secondary-icon-storage-type");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_secondary_icon_storage_type: property 'secondary-icon-storage-type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "secondary-icon-storage-type", &prop_gvalue);
          prop_value = (GtkImageType)g_value_get_enum(&prop_gvalue);

      result = Val_GtkImageType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_get_secondary_icon_tooltip_markup(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "secondary-icon-tooltip-markup");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_secondary_icon_tooltip_markup: property 'secondary-icon-tooltip-markup' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "secondary-icon-tooltip-markup", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_set_secondary_icon_tooltip_markup(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "secondary-icon-tooltip-markup");
if (pspec == NULL) caml_failwith("ml_gtk_entry_set_secondary_icon_tooltip_markup: property 'secondary-icon-tooltip-markup' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "secondary-icon-tooltip-markup", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_get_secondary_icon_tooltip_text(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "secondary-icon-tooltip-text");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_secondary_icon_tooltip_text: property 'secondary-icon-tooltip-text' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "secondary-icon-tooltip-text", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_set_secondary_icon_tooltip_text(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "secondary-icon-tooltip-text");
if (pspec == NULL) caml_failwith("ml_gtk_entry_set_secondary_icon_tooltip_text: property 'secondary-icon-tooltip-text' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "secondary-icon-tooltip-text", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_get_show_emoji_icon(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "show-emoji-icon");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_show_emoji_icon: property 'show-emoji-icon' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "show-emoji-icon", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_set_show_emoji_icon(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "show-emoji-icon");
if (pspec == NULL) caml_failwith("ml_gtk_entry_set_show_emoji_icon: property 'show-emoji-icon' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "show-emoji-icon", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_get_truncate_multiline(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "truncate-multiline");
if (pspec == NULL) caml_failwith("ml_gtk_entry_get_truncate_multiline: property 'truncate-multiline' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "truncate-multiline", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_entry_set_truncate_multiline(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkEntry *obj = (GtkEntry *)GtkEntry_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "truncate-multiline");
if (pspec == NULL) caml_failwith("ml_gtk_entry_set_truncate_multiline: property 'truncate-multiline' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "truncate-multiline", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_entry_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_entry_get_type()));
}
