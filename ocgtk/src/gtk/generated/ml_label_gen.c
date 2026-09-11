/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Label */

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


CAMLexport CAMLprim value ml_gtk_label_new(value arg1)
{
CAMLparam1(arg1);

GtkLabel *obj = gtk_label_new(String_option_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkLabel(obj));
}
CAMLexport CAMLprim value ml_gtk_label_new_with_mnemonic(value arg1)
{
CAMLparam1(arg1);

GtkLabel *obj = gtk_label_new_with_mnemonic(String_option_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkLabel(obj));
}
CAMLexport CAMLprim value ml_gtk_label_set_yalign(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_yalign(GtkLabel_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_label_set_xalign(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_xalign(GtkLabel_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_label_set_wrap_mode(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_wrap_mode(GtkLabel_val(self), PangoWrapMode_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_label_set_wrap(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_wrap(GtkLabel_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_label_set_width_chars(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_width_chars(GtkLabel_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_label_set_use_underline(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_use_underline(GtkLabel_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_label_set_use_markup(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_use_markup(GtkLabel_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_label_set_text_with_mnemonic(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_text_with_mnemonic(GtkLabel_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_label_set_text(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_text(GtkLabel_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,8,0)

CAMLexport CAMLprim value ml_gtk_label_set_tabs(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_tabs(GtkLabel_val(self), Option_val(arg1, PangoTabArray_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_label_set_tabs(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Label requires GTK >= 4.8");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_label_set_single_line_mode(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_single_line_mode(GtkLabel_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_label_set_selectable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_selectable(GtkLabel_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gtk_label_set_natural_wrap_mode(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_natural_wrap_mode(GtkLabel_val(self), GtkNaturalWrapMode_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_label_set_natural_wrap_mode(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Label requires GTK >= 4.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_label_set_mnemonic_widget(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_mnemonic_widget(GtkLabel_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_label_set_max_width_chars(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_max_width_chars(GtkLabel_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_label_set_markup_with_mnemonic(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_markup_with_mnemonic(GtkLabel_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_label_set_markup(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_markup(GtkLabel_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_label_set_lines(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_lines(GtkLabel_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_label_set_label(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_label(GtkLabel_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_label_set_justify(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_justify(GtkLabel_val(self), GtkJustification_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_label_set_extra_menu(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_extra_menu(GtkLabel_val(self), Option_val(arg1, GMenuModel_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_label_set_ellipsize(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_ellipsize(GtkLabel_val(self), PangoEllipsizeMode_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_label_set_attributes(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_label_set_attributes(GtkLabel_val(self), Option_val(arg1, PangoAttrList_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_label_select_region(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_label_select_region(GtkLabel_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_label_get_yalign(value self)
{
CAMLparam1(self);

float result = gtk_label_get_yalign(GtkLabel_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_label_get_xalign(value self)
{
CAMLparam1(self);

float result = gtk_label_get_xalign(GtkLabel_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_label_get_wrap_mode(value self)
{
CAMLparam1(self);

PangoWrapMode result = gtk_label_get_wrap_mode(GtkLabel_val(self));
CAMLreturn(Val_PangoWrapMode(result));
}

CAMLexport CAMLprim value ml_gtk_label_get_wrap(value self)
{
CAMLparam1(self);

gboolean result = gtk_label_get_wrap(GtkLabel_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_label_get_width_chars(value self)
{
CAMLparam1(self);

int result = gtk_label_get_width_chars(GtkLabel_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_label_get_use_underline(value self)
{
CAMLparam1(self);

gboolean result = gtk_label_get_use_underline(GtkLabel_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_label_get_use_markup(value self)
{
CAMLparam1(self);

gboolean result = gtk_label_get_use_markup(GtkLabel_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_label_get_text(value self)
{
CAMLparam1(self);

const char* result = gtk_label_get_text(GtkLabel_val(self));
CAMLreturn(caml_copy_string(result));
}

#if GTK_CHECK_VERSION(4,8,0)

CAMLexport CAMLprim value ml_gtk_label_get_tabs(value self)
{
CAMLparam1(self);

PangoTabArray* result = gtk_label_get_tabs(GtkLabel_val(self));
CAMLreturn(Val_option(result, Val_PangoTabArray));
}

#else

CAMLexport CAMLprim value ml_gtk_label_get_tabs(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Label requires GTK >= 4.8");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_label_get_single_line_mode(value self)
{
CAMLparam1(self);

gboolean result = gtk_label_get_single_line_mode(GtkLabel_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_label_get_selection_bounds(value self)
{
CAMLparam1(self);
int out1;
int out2;

gboolean result = gtk_label_get_selection_bounds(GtkLabel_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_int(out1));
    Store_field(ret, 2, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_label_get_selectable(value self)
{
CAMLparam1(self);

gboolean result = gtk_label_get_selectable(GtkLabel_val(self));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gtk_label_get_natural_wrap_mode(value self)
{
CAMLparam1(self);

GtkNaturalWrapMode result = gtk_label_get_natural_wrap_mode(GtkLabel_val(self));
CAMLreturn(Val_GtkNaturalWrapMode(result));
}

#else

CAMLexport CAMLprim value ml_gtk_label_get_natural_wrap_mode(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Label requires GTK >= 4.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_label_get_mnemonic_widget(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_label_get_mnemonic_widget(GtkLabel_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_label_get_mnemonic_keyval(value self)
{
CAMLparam1(self);

guint result = gtk_label_get_mnemonic_keyval(GtkLabel_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_label_get_max_width_chars(value self)
{
CAMLparam1(self);

int result = gtk_label_get_max_width_chars(GtkLabel_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_label_get_lines(value self)
{
CAMLparam1(self);

int result = gtk_label_get_lines(GtkLabel_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_label_get_layout_offsets(value self)
{
CAMLparam1(self);
int out1;
int out2;

gtk_label_get_layout_offsets(GtkLabel_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_label_get_layout(value self)
{
CAMLparam1(self);

PangoLayout* result = gtk_label_get_layout(GtkLabel_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_PangoLayout(result));
}

CAMLexport CAMLprim value ml_gtk_label_get_label(value self)
{
CAMLparam1(self);

const char* result = gtk_label_get_label(GtkLabel_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_label_get_justify(value self)
{
CAMLparam1(self);

GtkJustification result = gtk_label_get_justify(GtkLabel_val(self));
CAMLreturn(Val_GtkJustification(result));
}

CAMLexport CAMLprim value ml_gtk_label_get_extra_menu(value self)
{
CAMLparam1(self);

GMenuModel* result = gtk_label_get_extra_menu(GtkLabel_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GMenuModel));
}

CAMLexport CAMLprim value ml_gtk_label_get_ellipsize(value self)
{
CAMLparam1(self);

PangoEllipsizeMode result = gtk_label_get_ellipsize(GtkLabel_val(self));
CAMLreturn(Val_PangoEllipsizeMode(result));
}

CAMLexport CAMLprim value ml_gtk_label_get_current_uri(value self)
{
CAMLparam1(self);

const char* result = gtk_label_get_current_uri(GtkLabel_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_label_get_attributes(value self)
{
CAMLparam1(self);

PangoAttrList* result = gtk_label_get_attributes(GtkLabel_val(self));
if (result) result = g_boxed_copy(pango_attr_list_get_type(), result);
CAMLreturn(Val_option(result, Val_PangoAttrList));
}

GType gtk_label_get_type (void);


CAMLprim value ml_gtk_label_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_label_get_type()));
}
