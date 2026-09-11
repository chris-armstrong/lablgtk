/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Display */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gdk/gdk.h>
/* Include library-specific type conversions and forward declarations */
#include "gdk_decls.h"


CAMLexport CAMLprim value ml_gdk_display_translate_key(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
guint out4;
int out5;
int out6;
GdkModifierType out7;

gboolean result = gdk_display_translate_key(GdkDisplay_val(self), Int_val(arg1), GdkModifierType_val(arg2), Int_val(arg3), &out4, &out5, &out6, &out7);
CAMLlocal1(ret);
    ret = caml_alloc(5, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_int(out4));
    Store_field(ret, 2, Val_int(out5));
    Store_field(ret, 3, Val_int(out6));
    Store_field(ret, 4, Val_GdkModifierType(out7));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gdk_display_sync(value self)
{
CAMLparam1(self);

gdk_display_sync(GdkDisplay_val(self));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gdk_display_supports_shadow_width(value self)
{
CAMLparam1(self);

gboolean result = gdk_display_supports_shadow_width(GdkDisplay_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gdk_display_supports_shadow_width(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Display requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_display_supports_input_shapes(value self)
{
CAMLparam1(self);

gboolean result = gdk_display_supports_input_shapes(GdkDisplay_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_display_put_event(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_display_put_event(GdkDisplay_val(self), GdkEvent_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,4,0)

CAMLexport CAMLprim value ml_gdk_display_prepare_gl(value self)
{
CAMLparam1(self);
GError *error = NULL;

gboolean result = gdk_display_prepare_gl(GdkDisplay_val(self), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_gdk_display_prepare_gl(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Display requires GTK >= 4.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_display_notify_startup_complete(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_display_notify_startup_complete(GdkDisplay_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_display_map_keyval(value self, value arg1)
{
CAMLparam2(self, arg1);
GdkKeymapKey* out2 = NULL;
int out3;

gboolean result = gdk_display_map_keyval(GdkDisplay_val(self), Int_val(arg1), &out2, &out3);
    int out2_length = out3;
    CAMLlocal1(ml_out2);
    ml_out2 = caml_alloc(out2_length, 0);
    for (int i = 0; i < out2_length; i++) {
      Store_field(ml_out2, i, Val_GdkKeymapKey(&out2[i]));
    }

    g_free(out2);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, ml_out2);
    Store_field(ret, 2, Val_int(out3));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gdk_display_map_keycode(value self, value arg1)
{
CAMLparam2(self, arg1);
GdkKeymapKey* out2 = NULL;
guint* out3 = NULL;
int out4;

gboolean result = gdk_display_map_keycode(GdkDisplay_val(self), Int_val(arg1), &out2, &out3, &out4);
    int out2_length = out4;
    CAMLlocal1(ml_out2);
    ml_out2 = caml_alloc(out2_length, 0);
    for (int i = 0; i < out2_length; i++) {
      Store_field(ml_out2, i, Val_GdkKeymapKey(&out2[i]));
    }
    int out3_length = out4;
    CAMLlocal1(ml_out3);
    ml_out3 = caml_alloc(out3_length, 0);
    for (int i = 0; i < out3_length; i++) {
      Store_field(ml_out3, i, Val_int(out3[i]));
    }

    g_free(out2);
    g_free(out3);
CAMLlocal1(ret);
    ret = caml_alloc(4, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, ml_out2);
    Store_field(ret, 2, ml_out3);
    Store_field(ret, 3, Val_int(out4));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gdk_display_list_seats(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = gdk_display_list_seats(GdkDisplay_val(self));
Val_GList_with(c_result, result, item, cell, Val_GdkSeat((gpointer)_tmp->data));
    g_list_free(c_result);
    CAMLreturn(result);
}

CAMLexport CAMLprim value ml_gdk_display_is_rgba(value self)
{
CAMLparam1(self);

gboolean result = gdk_display_is_rgba(GdkDisplay_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_display_is_composited(value self)
{
CAMLparam1(self);

gboolean result = gdk_display_is_composited(GdkDisplay_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_display_is_closed(value self)
{
CAMLparam1(self);

gboolean result = gdk_display_is_closed(GdkDisplay_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_display_get_startup_notification_id(value self)
{
CAMLparam1(self);

const char* result = gdk_display_get_startup_notification_id(GdkDisplay_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gdk_display_get_setting(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gdk_display_get_setting(GdkDisplay_val(self), String_val(arg1), GValue_val(arg2));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_display_get_primary_clipboard(value self)
{
CAMLparam1(self);

GdkClipboard* result = gdk_display_get_primary_clipboard(GdkDisplay_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkClipboard(result));
}

CAMLexport CAMLprim value ml_gdk_display_get_name(value self)
{
CAMLparam1(self);

const char* result = gdk_display_get_name(GdkDisplay_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gdk_display_get_monitors(value self)
{
CAMLparam1(self);

GListModel* result = gdk_display_get_monitors(GdkDisplay_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GListModel(result));
}

CAMLexport CAMLprim value ml_gdk_display_get_monitor_at_surface(value self, value arg1)
{
CAMLparam2(self, arg1);

GdkMonitor* result = gdk_display_get_monitor_at_surface(GdkDisplay_val(self), GdkSurface_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkMonitor));
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gdk_display_get_dmabuf_formats(value self)
{
CAMLparam1(self);

GdkDmabufFormats* result = gdk_display_get_dmabuf_formats(GdkDisplay_val(self));
if (result) result = g_boxed_copy(gdk_dmabuf_formats_get_type(), result);
CAMLreturn(Val_GdkDmabufFormats(result));
}

#else

CAMLexport CAMLprim value ml_gdk_display_get_dmabuf_formats(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Display requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_display_get_default_seat(value self)
{
CAMLparam1(self);

GdkSeat* result = gdk_display_get_default_seat(GdkDisplay_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkSeat));
}

CAMLexport CAMLprim value ml_gdk_display_get_clipboard(value self)
{
CAMLparam1(self);

GdkClipboard* result = gdk_display_get_clipboard(GdkDisplay_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkClipboard(result));
}

CAMLexport CAMLprim value ml_gdk_display_get_app_launch_context(value self)
{
CAMLparam1(self);

GdkAppLaunchContext* result = gdk_display_get_app_launch_context(GdkDisplay_val(self));
CAMLreturn(Val_GdkAppLaunchContext(result));
}

CAMLexport CAMLprim value ml_gdk_display_flush(value self)
{
CAMLparam1(self);

gdk_display_flush(GdkDisplay_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_display_device_is_grabbed(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gdk_display_device_is_grabbed(GdkDisplay_val(self), GdkDevice_val(arg1));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gdk_display_create_gl_context(value self)
{
CAMLparam1(self);
GError *error = NULL;

GdkGLContext* result = gdk_display_create_gl_context(GdkDisplay_val(self), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GdkGLContext(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_gdk_display_create_gl_context(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Display requires GTK >= 4.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_display_close(value self)
{
CAMLparam1(self);

gdk_display_close(GdkDisplay_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_display_beep(value self)
{
CAMLparam1(self);

gdk_display_beep(GdkDisplay_val(self));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gdk_display_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_display_get_type()));
}
