/* GENERATED CODE - DO NOT EDIT */
/* C bindings for AppInfo */

#include <gio/gio.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gio/gio.h>
/* Include library-specific type conversions and forward declarations */
#include "gio_decls.h"


CAMLexport CAMLprim value ml_g_app_info_supports_uris(value self)
{
CAMLparam1(self);

gboolean result = g_app_info_supports_uris(GAppInfo_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_app_info_supports_files(value self)
{
CAMLparam1(self);

gboolean result = g_app_info_supports_files(GAppInfo_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_app_info_should_show(value self)
{
CAMLparam1(self);

gboolean result = g_app_info_should_show(GAppInfo_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_app_info_set_as_last_used_for_type(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_app_info_set_as_last_used_for_type(GAppInfo_val(self), String_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_app_info_set_as_default_for_type(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_app_info_set_as_default_for_type(GAppInfo_val(self), String_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_app_info_set_as_default_for_extension(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_app_info_set_as_default_for_extension(GAppInfo_val(self), String_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_app_info_remove_supports_type(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_app_info_remove_supports_type(GAppInfo_val(self), String_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if GLIB_CHECK_VERSION(2,60,0)

CAMLexport CAMLprim value ml_g_app_info_launch_uris_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_app_info_launch_uris_finish(GAppInfo_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_app_info_launch_uris_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("AppInfo requires GLib >= 2.60");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_app_info_launch_uris(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;
    GList* arg1_list = NULL;
    GList_val_with(arg1, arg1_list, (gpointer)g_strdup(String_val(Field(_iter, 0))));

gboolean result = g_app_info_launch_uris(GAppInfo_val(self), arg1_list, Option_val(arg2, GAppLaunchContext_val, NULL), &error);
    g_list_free(arg1_list);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_app_info_launch(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;
    GList* arg1_list = NULL;
    GList_val_with(arg1, arg1_list, (gpointer)GFile_val(Field(_iter, 0)));

gboolean result = g_app_info_launch(GAppInfo_val(self), arg1_list, Option_val(arg2, GAppLaunchContext_val, NULL), &error);
    g_list_free(arg1_list);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_app_info_get_supported_types(value self)
{
CAMLparam1(self);

const char** result = g_app_info_get_supported_types(GAppInfo_val(self));
    int result_length = 0;
    while (result[result_length] != NULL) result_length++;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, caml_copy_string(result[i]));
    }
CAMLreturn(ml_result);
}

#else

CAMLexport CAMLprim value ml_g_app_info_get_supported_types(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("AppInfo requires GLib >= 2.34");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_app_info_get_name(value self)
{
CAMLparam1(self);

const char* result = g_app_info_get_name(GAppInfo_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_g_app_info_get_id(value self)
{
CAMLparam1(self);

const char* result = g_app_info_get_id(GAppInfo_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_app_info_get_icon(value self)
{
CAMLparam1(self);

GIcon* result = g_app_info_get_icon(GAppInfo_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GIcon));
}

CAMLexport CAMLprim value ml_g_app_info_get_executable(value self)
{
CAMLparam1(self);

const char* result = g_app_info_get_executable(GAppInfo_val(self));
CAMLreturn(caml_copy_string(result));
}

#if GLIB_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_g_app_info_get_display_name(value self)
{
CAMLparam1(self);

const char* result = g_app_info_get_display_name(GAppInfo_val(self));
CAMLreturn(caml_copy_string(result));
}

#else

CAMLexport CAMLprim value ml_g_app_info_get_display_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("AppInfo requires GLib >= 2.24");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_app_info_get_description(value self)
{
CAMLparam1(self);

const char* result = g_app_info_get_description(GAppInfo_val(self));
CAMLreturn(Val_option_string(result));
}

#if GLIB_CHECK_VERSION(2,20,0)

CAMLexport CAMLprim value ml_g_app_info_get_commandline(value self)
{
CAMLparam1(self);

const char* result = g_app_info_get_commandline(GAppInfo_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_app_info_get_commandline(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("AppInfo requires GLib >= 2.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_app_info_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_app_info_equal(GAppInfo_val(self), GAppInfo_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_app_info_dup(value self)
{
CAMLparam1(self);

GAppInfo* result = g_app_info_dup(GAppInfo_val(self));
CAMLreturn(Val_GAppInfo(result));
}

#if GLIB_CHECK_VERSION(2,20,0)

CAMLexport CAMLprim value ml_g_app_info_delete(value self)
{
CAMLparam1(self);

gboolean result = g_app_info_delete(GAppInfo_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_app_info_delete(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("AppInfo requires GLib >= 2.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_app_info_can_remove_supports_type(value self)
{
CAMLparam1(self);

gboolean result = g_app_info_can_remove_supports_type(GAppInfo_val(self));
CAMLreturn(Val_bool(result));
}

#if GLIB_CHECK_VERSION(2,20,0)

CAMLexport CAMLprim value ml_g_app_info_can_delete(value self)
{
CAMLparam1(self);

gboolean result = g_app_info_can_delete(GAppInfo_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_app_info_can_delete(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("AppInfo requires GLib >= 2.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_app_info_add_supports_type(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_app_info_add_supports_type(GAppInfo_val(self), String_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_gio_app_info_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_APP_INFO)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GAppInfo");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GAppInfo((GAppInfo*)gobj));
}

GType g_app_info_get_type (void);


CAMLprim value ml_gio_app_info_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_app_info_get_type()));
}
