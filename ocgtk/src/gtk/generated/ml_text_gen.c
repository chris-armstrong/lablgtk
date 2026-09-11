/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Text */

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


CAMLexport CAMLprim value ml_gtk_text_new(value unit)
{
CAMLparam1(unit);

GtkText *obj = gtk_text_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkText(obj));
}
CAMLexport CAMLprim value ml_gtk_text_new_with_buffer(value arg1)
{
CAMLparam1(arg1);

GtkText *obj = gtk_text_new_with_buffer(GtkEntryBuffer_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkText(obj));
}
CAMLexport CAMLprim value ml_gtk_text_unset_invisible_char(value self)
{
CAMLparam1(self);

gtk_text_unset_invisible_char(GtkText_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_set_visibility(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_set_visibility(GtkText_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_set_truncate_multiline(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_set_truncate_multiline(GtkText_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_set_tabs(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_set_tabs(GtkText_val(self), Option_val(arg1, PangoTabArray_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_set_propagate_text_width(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_set_propagate_text_width(GtkText_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_set_placeholder_text(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_set_placeholder_text(GtkText_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_set_overwrite_mode(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_set_overwrite_mode(GtkText_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_set_max_length(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_set_max_length(GtkText_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_set_invisible_char(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_set_invisible_char(GtkText_val(self), Long_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_set_input_purpose(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_set_input_purpose(GtkText_val(self), GtkInputPurpose_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_set_input_hints(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_set_input_hints(GtkText_val(self), GtkInputHints_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_set_extra_menu(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_set_extra_menu(GtkText_val(self), Option_val(arg1, GMenuModel_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_set_enable_emoji_completion(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_set_enable_emoji_completion(GtkText_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_set_buffer(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_set_buffer(GtkText_val(self), GtkEntryBuffer_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_set_attributes(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_set_attributes(GtkText_val(self), Option_val(arg1, PangoAttrList_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_set_activates_default(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_set_activates_default(GtkText_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_grab_focus_without_selecting(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_grab_focus_without_selecting(GtkText_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_get_visibility(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_get_visibility(GtkText_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_get_truncate_multiline(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_get_truncate_multiline(GtkText_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_get_text_length(value self)
{
CAMLparam1(self);

guint16 result = gtk_text_get_text_length(GtkText_val(self));
CAMLreturn(Val_uint16(result));
}

CAMLexport CAMLprim value ml_gtk_text_get_tabs(value self)
{
CAMLparam1(self);

PangoTabArray* result = gtk_text_get_tabs(GtkText_val(self));
if (result) result = g_boxed_copy(pango_tab_array_get_type(), result);
CAMLreturn(Val_option(result, Val_PangoTabArray));
}

CAMLexport CAMLprim value ml_gtk_text_get_propagate_text_width(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_get_propagate_text_width(GtkText_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_get_placeholder_text(value self)
{
CAMLparam1(self);

const char* result = gtk_text_get_placeholder_text(GtkText_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_text_get_overwrite_mode(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_get_overwrite_mode(GtkText_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_get_max_length(value self)
{
CAMLparam1(self);

int result = gtk_text_get_max_length(GtkText_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_get_invisible_char(value self)
{
CAMLparam1(self);

gunichar result = gtk_text_get_invisible_char(GtkText_val(self));
CAMLreturn(Val_long(result));
}

CAMLexport CAMLprim value ml_gtk_text_get_input_purpose(value self)
{
CAMLparam1(self);

GtkInputPurpose result = gtk_text_get_input_purpose(GtkText_val(self));
CAMLreturn(Val_GtkInputPurpose(result));
}

CAMLexport CAMLprim value ml_gtk_text_get_input_hints(value self)
{
CAMLparam1(self);

GtkInputHints result = gtk_text_get_input_hints(GtkText_val(self));
CAMLreturn(Val_GtkInputHints(result));
}

CAMLexport CAMLprim value ml_gtk_text_get_extra_menu(value self)
{
CAMLparam1(self);

GMenuModel* result = gtk_text_get_extra_menu(GtkText_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GMenuModel));
}

CAMLexport CAMLprim value ml_gtk_text_get_enable_emoji_completion(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_get_enable_emoji_completion(GtkText_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_get_buffer(value self)
{
CAMLparam1(self);

GtkEntryBuffer* result = gtk_text_get_buffer(GtkText_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkEntryBuffer(result));
}

CAMLexport CAMLprim value ml_gtk_text_get_attributes(value self)
{
CAMLparam1(self);

PangoAttrList* result = gtk_text_get_attributes(GtkText_val(self));
if (result) result = g_boxed_copy(pango_attr_list_get_type(), result);
CAMLreturn(Val_option(result, Val_PangoAttrList));
}

CAMLexport CAMLprim value ml_gtk_text_get_activates_default(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_get_activates_default(GtkText_val(self));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,4,0)

CAMLexport CAMLprim value ml_gtk_text_compute_cursor_extents(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_rect_t out2;
graphene_rect_t out3;

gtk_text_compute_cursor_extents(GtkText_val(self), Gsize_val(arg1), &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_graphene_rect_t(&out2));
    Store_field(ret, 1, Val_graphene_rect_t(&out3));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_gtk_text_compute_cursor_extents(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Text requires GTK >= 4.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_text_get_im_module(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkText *obj = (GtkText *)GtkText_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "im-module");
if (pspec == NULL) caml_failwith("ml_gtk_text_get_im_module: property 'im-module' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "im-module", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_set_im_module(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkText *obj = (GtkText *)GtkText_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "im-module");
if (pspec == NULL) caml_failwith("ml_gtk_text_set_im_module: property 'im-module' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "im-module", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_get_invisible_char_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkText *obj = (GtkText *)GtkText_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "invisible-char-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_get_invisible_char_set: property 'invisible-char-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "invisible-char-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_set_invisible_char_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkText *obj = (GtkText *)GtkText_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "invisible-char-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_set_invisible_char_set: property 'invisible-char-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "invisible-char-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_get_scroll_offset(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkText *obj = (GtkText *)GtkText_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "scroll-offset");
if (pspec == NULL) caml_failwith("ml_gtk_text_get_scroll_offset: property 'scroll-offset' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "scroll-offset", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

GType gtk_text_get_type (void);


CAMLprim value ml_gtk_text_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_text_get_type()));
}
