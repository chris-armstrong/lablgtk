/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DBusConnection */

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

#if GLIB_CHECK_VERSION(2,26,0)


CAMLexport CAMLprim value ml_g_dbus_connection_new_finish(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GDBusConnection *obj = g_dbus_connection_new_finish(GAsyncResult_val(arg1), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GDBusConnection(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_g_dbus_connection_new_for_address_finish(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GDBusConnection *obj = g_dbus_connection_new_for_address_finish(GAsyncResult_val(arg1), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GDBusConnection(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_g_dbus_connection_new_for_address_sync(value arg1, value arg2, value arg3, value arg4)
{
CAMLparam4(arg1, arg2, arg3, arg4);
GError *error = NULL;
    
GDBusConnection *obj = g_dbus_connection_new_for_address_sync(String_val(arg1), GioDBusConnectionFlags_val(arg2), Option_val(arg3, GDBusAuthObserver_val, NULL), Option_val(arg4, GCancellable_val, NULL), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GDBusConnection(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_g_dbus_connection_new_sync(value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);
GError *error = NULL;
    
GDBusConnection *obj = g_dbus_connection_new_sync(GIOStream_val(arg1), String_option_val(arg2), GioDBusConnectionFlags_val(arg3), Option_val(arg4, GDBusAuthObserver_val, NULL), Option_val(arg5, GCancellable_val, NULL), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GDBusConnection(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_g_dbus_connection_unregister_subtree(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_dbus_connection_unregister_subtree(GDBusConnection_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_dbus_connection_unregister_object(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_dbus_connection_unregister_object(GDBusConnection_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_dbus_connection_unexport_menu_model(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_connection_unexport_menu_model(GDBusConnection_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_dbus_connection_unexport_menu_model(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusConnection requires GLib >= 2.32");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_dbus_connection_unexport_action_group(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_connection_unexport_action_group(GDBusConnection_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_dbus_connection_unexport_action_group(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusConnection requires GLib >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_dbus_connection_start_message_processing(value self)
{
CAMLparam1(self);

g_dbus_connection_start_message_processing(GDBusConnection_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_connection_signal_unsubscribe(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_connection_signal_unsubscribe(GDBusConnection_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_connection_set_exit_on_close(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_connection_set_exit_on_close(GDBusConnection_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_connection_send_message_with_reply_sync(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
GError *error = NULL;
volatile guint32 out4;

GDBusMessage* result = g_dbus_connection_send_message_with_reply_sync(GDBusConnection_val(self), GDBusMessage_val(arg1), GioDBusSendMessageFlags_val(arg2), Int_val(arg3), &out4, Option_val(arg4, GCancellable_val, NULL), &error);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_GDBusMessage(result));
    Store_field(ret, 1, Val_uint32(out4));
    if (error == NULL) CAMLreturn(Res_Ok(ret)); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_dbus_connection_send_message_with_reply_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GDBusMessage* result = g_dbus_connection_send_message_with_reply_finish(GDBusConnection_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GDBusMessage(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_dbus_connection_send_message(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;
volatile guint32 out3;

gboolean result = g_dbus_connection_send_message(GDBusConnection_val(self), GDBusMessage_val(arg1), GioDBusSendMessageFlags_val(arg2), &out3, &error);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_uint32(out3));
    if (error == NULL) CAMLreturn(Res_Ok(ret)); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_dbus_connection_remove_filter(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_connection_remove_filter(GDBusConnection_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_connection_is_closed(value self)
{
CAMLparam1(self);

gboolean result = g_dbus_connection_is_closed(GDBusConnection_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_dbus_connection_get_unique_name(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_connection_get_unique_name(GDBusConnection_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_dbus_connection_get_stream(value self)
{
CAMLparam1(self);

GIOStream* result = g_dbus_connection_get_stream(GDBusConnection_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GIOStream(result));
}

CAMLexport CAMLprim value ml_g_dbus_connection_get_peer_credentials(value self)
{
CAMLparam1(self);

GCredentials* result = g_dbus_connection_get_peer_credentials(GDBusConnection_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GCredentials));
}

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_dbus_connection_get_last_serial(value self)
{
CAMLparam1(self);

guint32 result = g_dbus_connection_get_last_serial(GDBusConnection_val(self));
CAMLreturn(Val_uint32(result));
}

#else

CAMLexport CAMLprim value ml_g_dbus_connection_get_last_serial(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusConnection requires GLib >= 2.34");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_dbus_connection_get_guid(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_connection_get_guid(GDBusConnection_val(self));
CAMLreturn(caml_copy_string(result));
}

#if GLIB_CHECK_VERSION(2,60,0)

CAMLexport CAMLprim value ml_g_dbus_connection_get_flags(value self)
{
CAMLparam1(self);

GDBusConnectionFlags result = g_dbus_connection_get_flags(GDBusConnection_val(self));
CAMLreturn(Val_GioDBusConnectionFlags(result));
}

#else

CAMLexport CAMLprim value ml_g_dbus_connection_get_flags(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusConnection requires GLib >= 2.60");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_dbus_connection_get_exit_on_close(value self)
{
CAMLparam1(self);

gboolean result = g_dbus_connection_get_exit_on_close(GDBusConnection_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_dbus_connection_get_capabilities(value self)
{
CAMLparam1(self);

GDBusCapabilityFlags result = g_dbus_connection_get_capabilities(GDBusConnection_val(self));
CAMLreturn(Val_GioDBusCapabilityFlags(result));
}

CAMLexport CAMLprim value ml_g_dbus_connection_flush_sync(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_dbus_connection_flush_sync(GDBusConnection_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_dbus_connection_flush_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_dbus_connection_flush_finish(GDBusConnection_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_dbus_connection_export_menu_model(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

guint result = g_dbus_connection_export_menu_model(GDBusConnection_val(self), String_val(arg1), GMenuModel_val(arg2), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_int(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_dbus_connection_export_menu_model(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("DBusConnection requires GLib >= 2.32");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_dbus_connection_export_action_group(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

guint result = g_dbus_connection_export_action_group(GDBusConnection_val(self), String_val(arg1), GActionGroup_val(arg2), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_int(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_dbus_connection_export_action_group(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("DBusConnection requires GLib >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_dbus_connection_emit_signal_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);
GError *error = NULL;

gboolean result = g_dbus_connection_emit_signal(GDBusConnection_val(self), String_option_val(arg1), String_val(arg2), String_val(arg3), String_val(arg4), Option_val(arg5, GVariant_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));}

CAMLexport CAMLprim value ml_g_dbus_connection_emit_signal_bytecode(value * argv, int argn)
{
return ml_g_dbus_connection_emit_signal_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_g_dbus_connection_close_sync(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_dbus_connection_close_sync(GDBusConnection_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_dbus_connection_close_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_dbus_connection_close_finish(GDBusConnection_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_dbus_connection_call_sync_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7, value arg8, value arg9)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam5(arg5, arg6, arg7, arg8, arg9);
GError *error = NULL;

GVariant* result = g_dbus_connection_call_sync(GDBusConnection_val(self), String_option_val(arg1), String_val(arg2), String_val(arg3), String_val(arg4), Option_val(arg5, GVariant_val, NULL), Option_val(arg6, GVariantType_val, NULL), GioDBusCallFlags_val(arg7), Int_val(arg8), Option_val(arg9, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GVariant(result))); else CAMLreturn(Res_Error(Val_GError(error)));}

CAMLexport CAMLprim value ml_g_dbus_connection_call_sync_bytecode(value * argv, int argn)
{
return ml_g_dbus_connection_call_sync_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9]);
}

CAMLexport CAMLprim value ml_g_dbus_connection_call_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GVariant* result = g_dbus_connection_call_finish(GDBusConnection_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GVariant(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

GType g_dbus_connection_get_type (void);


CAMLprim value ml_gio_d_bus_connection_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_dbus_connection_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_dbus_connection_new_finish(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_new_for_address_finish(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_new_for_address_sync(value arg1, value arg2, value arg3, value arg4)
{
CAMLparam4(arg1, arg2, arg3, arg4);
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_new_sync(value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_call_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_call_sync(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7, value arg8, value arg9)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
(void)arg6;
(void)arg7;
(void)arg8;
(void)arg9;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_close_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_close_sync(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_emit_signal(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_export_action_group(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_export_menu_model(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_flush_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_flush_sync(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_get_capabilities(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_get_exit_on_close(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_get_flags(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_get_guid(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_get_last_serial(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_get_peer_credentials(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_get_stream(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_get_unique_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_is_closed(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_remove_filter(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_send_message(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_send_message_with_reply_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_send_message_with_reply_sync(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_set_exit_on_close(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_signal_unsubscribe(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_start_message_processing(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_unexport_action_group(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_unexport_menu_model(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_unregister_object(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_connection_unregister_subtree(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusConnection requires GLib >= 2.26");
return Val_unit;
}


#endif
