/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Application */

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

#if GLIB_CHECK_VERSION(2,28,0)


CAMLexport CAMLprim value ml_g_application_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GApplication *obj = g_application_new(String_option_val(arg1), GioApplicationFlags_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GApplication(obj));
}
#if GLIB_CHECK_VERSION(2,40,0)

CAMLexport CAMLprim value ml_g_application_withdraw_notification(value self, value arg1)
{
CAMLparam2(self, arg1);

g_application_withdraw_notification(GApplication_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_application_withdraw_notification(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Application requires GLib >= 2.40");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,38,0)

CAMLexport CAMLprim value ml_g_application_unmark_busy(value self)
{
CAMLparam1(self);

g_application_unmark_busy(GApplication_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_application_unmark_busy(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.38");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,44,0)

CAMLexport CAMLprim value ml_g_application_unbind_busy_property(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_application_unbind_busy_property(GApplication_val(self), GObject_ext_of_val(arg1), String_val(arg2));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_application_unbind_busy_property(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Application requires GLib >= 2.44");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,80,0)

CAMLexport CAMLprim value ml_g_application_set_version(value self, value arg1)
{
CAMLparam2(self, arg1);

g_application_set_version(GApplication_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_application_set_version(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Application requires GLib >= 2.80");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,42,0)

CAMLexport CAMLprim value ml_g_application_set_resource_base_path(value self, value arg1)
{
CAMLparam2(self, arg1);

g_application_set_resource_base_path(GApplication_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_application_set_resource_base_path(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Application requires GLib >= 2.42");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,56,0)

CAMLexport CAMLprim value ml_g_application_set_option_context_summary(value self, value arg1)
{
CAMLparam2(self, arg1);

g_application_set_option_context_summary(GApplication_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_application_set_option_context_summary(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Application requires GLib >= 2.56");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,56,0)

CAMLexport CAMLprim value ml_g_application_set_option_context_parameter_string(value self, value arg1)
{
CAMLparam2(self, arg1);

g_application_set_option_context_parameter_string(GApplication_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_application_set_option_context_parameter_string(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Application requires GLib >= 2.56");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,56,0)

CAMLexport CAMLprim value ml_g_application_set_option_context_description(value self, value arg1)
{
CAMLparam2(self, arg1);

g_application_set_option_context_description(GApplication_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_application_set_option_context_description(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Application requires GLib >= 2.56");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_application_set_inactivity_timeout(value self, value arg1)
{
CAMLparam2(self, arg1);

g_application_set_inactivity_timeout(GApplication_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_application_set_flags(value self, value arg1)
{
CAMLparam2(self, arg1);

g_application_set_flags(GApplication_val(self), GioApplicationFlags_val(arg1));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_application_set_default(value self)
{
CAMLparam1(self);

g_application_set_default(GApplication_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_application_set_default(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_application_set_application_id(value self, value arg1)
{
CAMLparam2(self, arg1);

g_application_set_application_id(GApplication_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_application_set_action_group(value self, value arg1)
{
CAMLparam2(self, arg1);

g_application_set_action_group(GApplication_val(self), Option_val(arg1, GActionGroup_val, NULL));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,40,0)

CAMLexport CAMLprim value ml_g_application_send_notification(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_application_send_notification(GApplication_val(self), String_option_val(arg1), GNotification_val(arg2));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_application_send_notification(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Application requires GLib >= 2.40");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_application_run(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
    int arg2_length = 0;
    const char** c_arg2 = NULL;
    
    if (Is_some(arg2)) {
        value array = Some_val(arg2);
        arg2_length = Wosize_val(array);
        c_arg2 = (const char**)g_malloc(sizeof(const char*) * arg2_length);
        for (int i = 0; i < arg2_length; i++) {
          c_arg2[i] = String_val(Field(array, i));
        }
    }

int result = g_application_run(GApplication_val(self), Int_val(arg1), c_arg2);
    if (c_arg2) g_free(c_arg2);
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_g_application_release(value self)
{
CAMLparam1(self);

g_application_release(GApplication_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_application_register(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_application_register(GApplication_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_application_quit(value self)
{
CAMLparam1(self);

g_application_quit(GApplication_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_application_quit(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_application_open(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
    int arg1_length = Wosize_val(arg1);
    GFile** c_arg1 = (GFile**)g_malloc(sizeof(GFile*) * arg1_length);
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = GFile_val(Field(arg1, i));
    }

g_application_open(GApplication_val(self), c_arg1, Int_val(arg2), String_val(arg3));
    g_free(c_arg1);
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,38,0)

CAMLexport CAMLprim value ml_g_application_mark_busy(value self)
{
CAMLparam1(self);

g_application_mark_busy(GApplication_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_application_mark_busy(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.38");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_application_hold(value self)
{
CAMLparam1(self);

g_application_hold(GApplication_val(self));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,80,0)

CAMLexport CAMLprim value ml_g_application_get_version(value self)
{
CAMLparam1(self);

const gchar* result = g_application_get_version(GApplication_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_application_get_version(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.80");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,42,0)

CAMLexport CAMLprim value ml_g_application_get_resource_base_path(value self)
{
CAMLparam1(self);

const gchar* result = g_application_get_resource_base_path(GApplication_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_application_get_resource_base_path(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.42");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_application_get_is_remote(value self)
{
CAMLparam1(self);

gboolean result = g_application_get_is_remote(GApplication_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_application_get_is_registered(value self)
{
CAMLparam1(self);

gboolean result = g_application_get_is_registered(GApplication_val(self));
CAMLreturn(Val_bool(result));
}

#if GLIB_CHECK_VERSION(2,44,0)

CAMLexport CAMLprim value ml_g_application_get_is_busy(value self)
{
CAMLparam1(self);

gboolean result = g_application_get_is_busy(GApplication_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_application_get_is_busy(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.44");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_application_get_inactivity_timeout(value self)
{
CAMLparam1(self);

guint result = g_application_get_inactivity_timeout(GApplication_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_g_application_get_flags(value self)
{
CAMLparam1(self);

GApplicationFlags result = g_application_get_flags(GApplication_val(self));
CAMLreturn(Val_GioApplicationFlags(result));
}

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_application_get_dbus_object_path(value self)
{
CAMLparam1(self);

const gchar* result = g_application_get_dbus_object_path(GApplication_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_application_get_dbus_object_path(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.34");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_application_get_dbus_connection(value self)
{
CAMLparam1(self);

GDBusConnection* result = g_application_get_dbus_connection(GApplication_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GDBusConnection));
}

#else

CAMLexport CAMLprim value ml_g_application_get_dbus_connection(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.34");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_application_get_application_id(value self)
{
CAMLparam1(self);

const gchar* result = g_application_get_application_id(GApplication_val(self));
CAMLreturn(Val_option_string(result));
}

#if GLIB_CHECK_VERSION(2,44,0)

CAMLexport CAMLprim value ml_g_application_bind_busy_property(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_application_bind_busy_property(GApplication_val(self), GObject_ext_of_val(arg1), String_val(arg2));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_application_bind_busy_property(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Application requires GLib >= 2.44");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_application_activate(value self)
{
CAMLparam1(self);

g_application_activate(GApplication_val(self));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gio_application_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_application_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_application_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_activate(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_bind_busy_property(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_get_application_id(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_get_dbus_connection(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_get_dbus_object_path(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_get_flags(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_get_inactivity_timeout(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_get_is_busy(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_get_is_registered(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_get_is_remote(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_get_resource_base_path(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_get_version(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_hold(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_mark_busy(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_open(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_quit(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_register(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_release(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_run(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_send_notification(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_set_action_group(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_set_application_id(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_set_default(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_set_flags(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_set_inactivity_timeout(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_set_option_context_description(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_set_option_context_parameter_string(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_set_option_context_summary(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_set_resource_base_path(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_set_version(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_unbind_busy_property(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_unmark_busy(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_application_withdraw_notification(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Application requires GLib >= 2.28");
return Val_unit;
}


#endif
