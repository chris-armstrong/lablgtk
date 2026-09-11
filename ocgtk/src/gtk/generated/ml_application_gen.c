/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Application */

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


CAMLexport CAMLprim value ml_gtk_application_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkApplication *obj = gtk_application_new(String_option_val(arg1), GioApplicationFlags_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkApplication(obj));
}
CAMLexport CAMLprim value ml_gtk_application_uninhibit(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_application_uninhibit(GtkApplication_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_application_set_menubar(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_application_set_menubar(GtkApplication_val(self), Option_val(arg1, GMenuModel_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_application_set_accels_for_action(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
    int arg2_length = Wosize_val(arg2);
    const char** c_arg2 = (const char**)g_malloc(sizeof(const char*) * (arg2_length + 1));
    for (int i = 0; i < arg2_length; i++) {
      c_arg2[i] = String_val(Field(arg2, i));
    }
    c_arg2[arg2_length] = NULL;

gtk_application_set_accels_for_action(GtkApplication_val(self), String_val(arg1), c_arg2);
    g_free(c_arg2);
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_application_remove_window(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_application_remove_window(GtkApplication_val(self), GtkWindow_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_application_list_action_descriptions(value self)
{
CAMLparam1(self);

char** result = gtk_application_list_action_descriptions(GtkApplication_val(self));
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

CAMLexport CAMLprim value ml_gtk_application_inhibit(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

guint result = gtk_application_inhibit(GtkApplication_val(self), Option_val(arg1, GtkWindow_val, NULL), GtkApplicationInhibitFlags_val(arg2), String_option_val(arg3));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_application_get_windows(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = gtk_application_get_windows(GtkApplication_val(self));
Val_GList_with(c_result, result, item, cell, Val_GtkWindow((gpointer)_tmp->data));
    CAMLreturn(result);
}

CAMLexport CAMLprim value ml_gtk_application_get_window_by_id(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkWindow* result = gtk_application_get_window_by_id(GtkApplication_val(self), Int_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWindow));
}

CAMLexport CAMLprim value ml_gtk_application_get_menubar(value self)
{
CAMLparam1(self);

GMenuModel* result = gtk_application_get_menubar(GtkApplication_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GMenuModel));
}

CAMLexport CAMLprim value ml_gtk_application_get_menu_by_id(value self, value arg1)
{
CAMLparam2(self, arg1);

GMenu* result = gtk_application_get_menu_by_id(GtkApplication_val(self), String_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GMenu));
}

CAMLexport CAMLprim value ml_gtk_application_get_active_window(value self)
{
CAMLparam1(self);

GtkWindow* result = gtk_application_get_active_window(GtkApplication_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWindow));
}

CAMLexport CAMLprim value ml_gtk_application_get_actions_for_accel(value self, value arg1)
{
CAMLparam2(self, arg1);

char** result = gtk_application_get_actions_for_accel(GtkApplication_val(self), String_val(arg1));
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

CAMLexport CAMLprim value ml_gtk_application_get_accels_for_action(value self, value arg1)
{
CAMLparam2(self, arg1);

char** result = gtk_application_get_accels_for_action(GtkApplication_val(self), String_val(arg1));
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

CAMLexport CAMLprim value ml_gtk_application_add_window(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_application_add_window(GtkApplication_val(self), GtkWindow_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_application_get_register_session(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkApplication *obj = (GtkApplication *)GtkApplication_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "register-session");
if (pspec == NULL) caml_failwith("ml_gtk_application_get_register_session: property 'register-session' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "register-session", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_application_set_register_session(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkApplication *obj = (GtkApplication *)GtkApplication_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "register-session");
if (pspec == NULL) caml_failwith("ml_gtk_application_set_register_session: property 'register-session' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "register-session", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_application_get_screensaver_active(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkApplication *obj = (GtkApplication *)GtkApplication_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "screensaver-active");
if (pspec == NULL) caml_failwith("ml_gtk_application_get_screensaver_active: property 'screensaver-active' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "screensaver-active", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}


CAMLprim value ml_gtk_application_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_application_get_type()));
}
