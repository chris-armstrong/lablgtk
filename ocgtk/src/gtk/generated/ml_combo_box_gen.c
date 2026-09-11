/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ComboBox */

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


CAMLexport CAMLprim value ml_gtk_combo_box_new(value unit)
{
CAMLparam1(unit);

GtkComboBox *obj = gtk_combo_box_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkComboBox(obj));
}
CAMLexport CAMLprim value ml_gtk_combo_box_new_with_entry(value unit)
{
CAMLparam1(unit);

GtkComboBox *obj = gtk_combo_box_new_with_entry();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkComboBox(obj));
}
CAMLexport CAMLprim value ml_gtk_combo_box_new_with_model(value arg1)
{
CAMLparam1(arg1);

GtkComboBox *obj = gtk_combo_box_new_with_model(GtkTreeModel_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkComboBox(obj));
}
CAMLexport CAMLprim value ml_gtk_combo_box_new_with_model_and_entry(value arg1)
{
CAMLparam1(arg1);

GtkComboBox *obj = gtk_combo_box_new_with_model_and_entry(GtkTreeModel_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkComboBox(obj));
}
CAMLexport CAMLprim value ml_gtk_combo_box_set_popup_fixed_width(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_combo_box_set_popup_fixed_width(GtkComboBox_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_combo_box_set_model(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_combo_box_set_model(GtkComboBox_val(self), Option_val(arg1, GtkTreeModel_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_combo_box_set_id_column(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_combo_box_set_id_column(GtkComboBox_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_combo_box_set_entry_text_column(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_combo_box_set_entry_text_column(GtkComboBox_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_combo_box_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_combo_box_set_child(GtkComboBox_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_combo_box_set_button_sensitivity(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_combo_box_set_button_sensitivity(GtkComboBox_val(self), GtkSensitivityType_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_combo_box_set_active_iter(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_combo_box_set_active_iter(GtkComboBox_val(self), Option_val(arg1, GtkTreeIter_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_combo_box_set_active_id(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_combo_box_set_active_id(GtkComboBox_val(self), String_option_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_combo_box_set_active(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_combo_box_set_active(GtkComboBox_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_combo_box_popup_for_device(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_combo_box_popup_for_device(GtkComboBox_val(self), GdkDevice_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_combo_box_popup(value self)
{
CAMLparam1(self);

gtk_combo_box_popup(GtkComboBox_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_combo_box_popdown(value self)
{
CAMLparam1(self);

gtk_combo_box_popdown(GtkComboBox_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_combo_box_get_popup_fixed_width(value self)
{
CAMLparam1(self);

gboolean result = gtk_combo_box_get_popup_fixed_width(GtkComboBox_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_combo_box_get_model(value self)
{
CAMLparam1(self);

GtkTreeModel* result = gtk_combo_box_get_model(GtkComboBox_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkTreeModel));
}

CAMLexport CAMLprim value ml_gtk_combo_box_get_id_column(value self)
{
CAMLparam1(self);

int result = gtk_combo_box_get_id_column(GtkComboBox_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_combo_box_get_has_entry(value self)
{
CAMLparam1(self);

gboolean result = gtk_combo_box_get_has_entry(GtkComboBox_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_combo_box_get_entry_text_column(value self)
{
CAMLparam1(self);

int result = gtk_combo_box_get_entry_text_column(GtkComboBox_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_combo_box_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_combo_box_get_child(GtkComboBox_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_combo_box_get_button_sensitivity(value self)
{
CAMLparam1(self);

GtkSensitivityType result = gtk_combo_box_get_button_sensitivity(GtkComboBox_val(self));
CAMLreturn(Val_GtkSensitivityType(result));
}

CAMLexport CAMLprim value ml_gtk_combo_box_get_active_iter(value self)
{
CAMLparam1(self);
GtkTreeIter out1;

gboolean result = gtk_combo_box_get_active_iter(GtkComboBox_val(self), &out1);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_GtkTreeIter(&out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_combo_box_get_active_id(value self)
{
CAMLparam1(self);

const char* result = gtk_combo_box_get_active_id(GtkComboBox_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_combo_box_get_active(value self)
{
CAMLparam1(self);

int result = gtk_combo_box_get_active(GtkComboBox_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_combo_box_get_has_frame(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkComboBox *obj = (GtkComboBox *)GtkComboBox_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "has-frame");
if (pspec == NULL) caml_failwith("ml_gtk_combo_box_get_has_frame: property 'has-frame' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "has-frame", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_combo_box_set_has_frame(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkComboBox *obj = (GtkComboBox *)GtkComboBox_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "has-frame");
if (pspec == NULL) caml_failwith("ml_gtk_combo_box_set_has_frame: property 'has-frame' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "has-frame", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_combo_box_get_popup_shown(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkComboBox *obj = (GtkComboBox *)GtkComboBox_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "popup-shown");
if (pspec == NULL) caml_failwith("ml_gtk_combo_box_get_popup_shown: property 'popup-shown' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "popup-shown", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}


CAMLprim value ml_gtk_combo_box_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_combo_box_get_type()));
}
