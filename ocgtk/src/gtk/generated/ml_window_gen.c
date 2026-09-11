/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Window */

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


CAMLexport CAMLprim value ml_gtk_window_new(value unit)
{
CAMLparam1(unit);

GtkWindow *obj = gtk_window_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkWindow(obj));
}
CAMLexport CAMLprim value ml_gtk_window_unminimize(value self)
{
CAMLparam1(self);

gtk_window_unminimize(GtkWindow_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_unmaximize(value self)
{
CAMLparam1(self);

gtk_window_unmaximize(GtkWindow_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_unfullscreen(value self)
{
CAMLparam1(self);

gtk_window_unfullscreen(GtkWindow_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_set_transient_for(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_set_transient_for(GtkWindow_val(self), Option_val(arg1, GtkWindow_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_set_titlebar(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_set_titlebar(GtkWindow_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_set_title(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_set_title(GtkWindow_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_set_startup_id(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_set_startup_id(GtkWindow_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_set_resizable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_set_resizable(GtkWindow_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_set_modal(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_set_modal(GtkWindow_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_set_mnemonics_visible(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_set_mnemonics_visible(GtkWindow_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_set_icon_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_set_icon_name(GtkWindow_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_set_hide_on_close(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_set_hide_on_close(GtkWindow_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,2,0)

CAMLexport CAMLprim value ml_gtk_window_set_handle_menubar_accel(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_set_handle_menubar_accel(GtkWindow_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_window_set_handle_menubar_accel(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Window requires GTK >= 4.2");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gtk_window_set_gravity(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_set_gravity(GtkWindow_val(self), GtkWindowGravity_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_window_set_gravity(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Window requires GTK >= 4.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_window_set_focus_visible(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_set_focus_visible(GtkWindow_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_set_focus(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_set_focus(GtkWindow_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_set_display(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_set_display(GtkWindow_val(self), GdkDisplay_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_set_destroy_with_parent(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_set_destroy_with_parent(GtkWindow_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_set_deletable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_set_deletable(GtkWindow_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_set_default_widget(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_set_default_widget(GtkWindow_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_set_default_size(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_window_set_default_size(GtkWindow_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_set_decorated(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_set_decorated(GtkWindow_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_set_child(GtkWindow_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_set_application(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_set_application(GtkWindow_val(self), Option_val(arg1, GtkApplication_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_present_with_time(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_present_with_time(GtkWindow_val(self), UInt32_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_present(value self)
{
CAMLparam1(self);

gtk_window_present(GtkWindow_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_minimize(value self)
{
CAMLparam1(self);

gtk_window_minimize(GtkWindow_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_maximize(value self)
{
CAMLparam1(self);

gtk_window_maximize(GtkWindow_val(self));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_window_is_suspended(value self)
{
CAMLparam1(self);

gboolean result = gtk_window_is_suspended(GtkWindow_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gtk_window_is_suspended(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Window requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_window_is_maximized(value self)
{
CAMLparam1(self);

gboolean result = gtk_window_is_maximized(GtkWindow_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_window_is_fullscreen(value self)
{
CAMLparam1(self);

gboolean result = gtk_window_is_fullscreen(GtkWindow_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_window_is_active(value self)
{
CAMLparam1(self);

gboolean result = gtk_window_is_active(GtkWindow_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_window_has_group(value self)
{
CAMLparam1(self);

gboolean result = gtk_window_has_group(GtkWindow_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_window_get_transient_for(value self)
{
CAMLparam1(self);

GtkWindow* result = gtk_window_get_transient_for(GtkWindow_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWindow));
}

CAMLexport CAMLprim value ml_gtk_window_get_titlebar(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_window_get_titlebar(GtkWindow_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_window_get_title(value self)
{
CAMLparam1(self);

const char* result = gtk_window_get_title(GtkWindow_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_window_get_resizable(value self)
{
CAMLparam1(self);

gboolean result = gtk_window_get_resizable(GtkWindow_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_window_get_modal(value self)
{
CAMLparam1(self);

gboolean result = gtk_window_get_modal(GtkWindow_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_window_get_mnemonics_visible(value self)
{
CAMLparam1(self);

gboolean result = gtk_window_get_mnemonics_visible(GtkWindow_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_window_get_icon_name(value self)
{
CAMLparam1(self);

const char* result = gtk_window_get_icon_name(GtkWindow_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_window_get_hide_on_close(value self)
{
CAMLparam1(self);

gboolean result = gtk_window_get_hide_on_close(GtkWindow_val(self));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,2,0)

CAMLexport CAMLprim value ml_gtk_window_get_handle_menubar_accel(value self)
{
CAMLparam1(self);

gboolean result = gtk_window_get_handle_menubar_accel(GtkWindow_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gtk_window_get_handle_menubar_accel(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Window requires GTK >= 4.2");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_window_get_group(value self)
{
CAMLparam1(self);

GtkWindowGroup* result = gtk_window_get_group(GtkWindow_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkWindowGroup(result));
}

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gtk_window_get_gravity(value self)
{
CAMLparam1(self);

GtkWindowGravity result = gtk_window_get_gravity(GtkWindow_val(self));
CAMLreturn(Val_GtkWindowGravity(result));
}

#else

CAMLexport CAMLprim value ml_gtk_window_get_gravity(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Window requires GTK >= 4.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_window_get_focus_visible(value self)
{
CAMLparam1(self);

gboolean result = gtk_window_get_focus_visible(GtkWindow_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_window_get_focus(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_window_get_focus(GtkWindow_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_window_get_destroy_with_parent(value self)
{
CAMLparam1(self);

gboolean result = gtk_window_get_destroy_with_parent(GtkWindow_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_window_get_deletable(value self)
{
CAMLparam1(self);

gboolean result = gtk_window_get_deletable(GtkWindow_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_window_get_default_widget(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_window_get_default_widget(GtkWindow_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_window_get_default_size(value self)
{
CAMLparam1(self);
int out1;
int out2;

gtk_window_get_default_size(GtkWindow_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_window_get_decorated(value self)
{
CAMLparam1(self);

gboolean result = gtk_window_get_decorated(GtkWindow_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_window_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_window_get_child(GtkWindow_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_window_get_application(value self)
{
CAMLparam1(self);

GtkApplication* result = gtk_window_get_application(GtkWindow_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkApplication));
}

CAMLexport CAMLprim value ml_gtk_window_fullscreen_on_monitor(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_fullscreen_on_monitor(GtkWindow_val(self), GdkMonitor_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_fullscreen(value self)
{
CAMLparam1(self);

gtk_window_fullscreen(GtkWindow_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_destroy(value self)
{
CAMLparam1(self);

gtk_window_destroy(GtkWindow_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_close(value self)
{
CAMLparam1(self);

gtk_window_close(GtkWindow_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_get_default_height(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkWindow *obj = (GtkWindow *)GtkWindow_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "default-height");
if (pspec == NULL) caml_failwith("ml_gtk_window_get_default_height: property 'default-height' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "default-height", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_window_set_default_height(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkWindow *obj = (GtkWindow *)GtkWindow_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "default-height");
if (pspec == NULL) caml_failwith("ml_gtk_window_set_default_height: property 'default-height' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "default-height", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_get_default_width(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkWindow *obj = (GtkWindow *)GtkWindow_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "default-width");
if (pspec == NULL) caml_failwith("ml_gtk_window_get_default_width: property 'default-width' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "default-width", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_window_set_default_width(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkWindow *obj = (GtkWindow *)GtkWindow_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "default-width");
if (pspec == NULL) caml_failwith("ml_gtk_window_set_default_width: property 'default-width' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "default-width", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_window_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_window_get_type()));
}
