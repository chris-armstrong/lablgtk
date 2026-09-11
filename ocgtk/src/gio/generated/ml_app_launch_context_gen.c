/* GENERATED CODE - DO NOT EDIT */
/* C bindings for AppLaunchContext */

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


CAMLexport CAMLprim value ml_g_app_launch_context_new(value unit)
{
CAMLparam1(unit);

GAppLaunchContext *obj = g_app_launch_context_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GAppLaunchContext(obj));
}
#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_app_launch_context_unsetenv(value self, value arg1)
{
CAMLparam2(self, arg1);

g_app_launch_context_unsetenv(GAppLaunchContext_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_app_launch_context_unsetenv(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("AppLaunchContext requires GLib >= 2.32");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_app_launch_context_setenv(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_app_launch_context_setenv(GAppLaunchContext_val(self), String_val(arg1), String_val(arg2));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_app_launch_context_setenv(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("AppLaunchContext requires GLib >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_app_launch_context_launch_failed(value self, value arg1)
{
CAMLparam2(self, arg1);

g_app_launch_context_launch_failed(GAppLaunchContext_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_app_launch_context_get_startup_notify_id(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
    GList* arg2_list = NULL;
    GList_val_with(arg2, arg2_list, (gpointer)GFile_val(Field(_iter, 0)));

char* result = g_app_launch_context_get_startup_notify_id(GAppLaunchContext_val(self), Option_val(arg1, GAppInfo_val, NULL), arg2_list);
    g_list_free(arg2_list);
CAMLreturn(Val_option_string(result));
}

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_app_launch_context_get_environment(value self)
{
CAMLparam1(self);

char** result = g_app_launch_context_get_environment(GAppLaunchContext_val(self));
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

#else

CAMLexport CAMLprim value ml_g_app_launch_context_get_environment(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("AppLaunchContext requires GLib >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_app_launch_context_get_display(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
    GList* arg2_list = NULL;
    GList_val_with(arg2, arg2_list, (gpointer)GFile_val(Field(_iter, 0)));

char* result = g_app_launch_context_get_display(GAppLaunchContext_val(self), GAppInfo_val(arg1), arg2_list);
    g_list_free(arg2_list);
CAMLreturn(Val_option_string(result));
}


CAMLprim value ml_gio_app_launch_context_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_app_launch_context_get_type()));
}
