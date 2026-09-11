/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DBusMessage */

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


CAMLexport CAMLprim value ml_g_dbus_message_new(value unit)
{
CAMLparam1(unit);

GDBusMessage *obj = g_dbus_message_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GDBusMessage(obj));
}
CAMLexport CAMLprim value ml_g_dbus_message_new_method_call(value arg1, value arg2, value arg3, value arg4)
{
CAMLparam4(arg1, arg2, arg3, arg4);

GDBusMessage *obj = g_dbus_message_new_method_call(String_option_val(arg1), String_val(arg2), String_option_val(arg3), String_val(arg4));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GDBusMessage(obj));
}
CAMLexport CAMLprim value ml_g_dbus_message_new_signal(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GDBusMessage *obj = g_dbus_message_new_signal(String_val(arg1), String_val(arg2), String_val(arg3));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GDBusMessage(obj));
}
CAMLexport CAMLprim value ml_g_dbus_message_to_gerror(value self)
{
CAMLparam1(self);
GError *error = NULL;

gboolean result = g_dbus_message_to_gerror(GDBusMessage_val(self), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if !(defined(_WIN32))

CAMLexport CAMLprim value ml_g_dbus_message_set_unix_fd_list(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_message_set_unix_fd_list(GDBusMessage_val(self), Option_val(arg1, GUnixFDList_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_dbus_message_set_unix_fd_list(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusMessage is only available on non-windows");
return Val_unit;
}

#endif /* not windows */

CAMLexport CAMLprim value ml_g_dbus_message_set_signature(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_message_set_signature(GDBusMessage_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_message_set_serial(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_message_set_serial(GDBusMessage_val(self), UInt32_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_message_set_sender(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_message_set_sender(GDBusMessage_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_message_set_reply_serial(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_message_set_reply_serial(GDBusMessage_val(self), UInt32_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_message_set_path(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_message_set_path(GDBusMessage_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_message_set_num_unix_fds(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_message_set_num_unix_fds(GDBusMessage_val(self), UInt32_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_message_set_message_type(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_message_set_message_type(GDBusMessage_val(self), GioDBusMessageType_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_message_set_member(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_message_set_member(GDBusMessage_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_message_set_interface(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_message_set_interface(GDBusMessage_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_message_set_header(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_dbus_message_set_header(GDBusMessage_val(self), GioDBusMessageHeaderField_val(arg1), Option_val(arg2, GVariant_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_message_set_flags(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_message_set_flags(GDBusMessage_val(self), GioDBusMessageFlags_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_message_set_error_name(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_message_set_error_name(GDBusMessage_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_message_set_destination(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_message_set_destination(GDBusMessage_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_message_set_byte_order(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_message_set_byte_order(GDBusMessage_val(self), GioDBusMessageByteOrder_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_message_set_body(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_message_set_body(GDBusMessage_val(self), GVariant_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_message_print(value self, value arg1)
{
CAMLparam2(self, arg1);

gchar* result = g_dbus_message_print(GDBusMessage_val(self), Int_val(arg1));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_g_dbus_message_new_method_reply(value self)
{
CAMLparam1(self);

GDBusMessage* result = g_dbus_message_new_method_reply(GDBusMessage_val(self));
CAMLreturn(Val_GDBusMessage(result));
}

CAMLexport CAMLprim value ml_g_dbus_message_new_method_error_literal(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

GDBusMessage* result = g_dbus_message_new_method_error_literal(GDBusMessage_val(self), String_val(arg1), String_val(arg2));
CAMLreturn(Val_GDBusMessage(result));
}

CAMLexport CAMLprim value ml_g_dbus_message_lock(value self)
{
CAMLparam1(self);

g_dbus_message_lock(GDBusMessage_val(self));
CAMLreturn(Val_unit);
}

#if !(defined(_WIN32))

CAMLexport CAMLprim value ml_g_dbus_message_get_unix_fd_list(value self)
{
CAMLparam1(self);

GUnixFDList* result = g_dbus_message_get_unix_fd_list(GDBusMessage_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GUnixFDList));
}

#else

CAMLexport CAMLprim value ml_g_dbus_message_get_unix_fd_list(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage is only available on non-windows");
return Val_unit;
}

#endif /* not windows */

CAMLexport CAMLprim value ml_g_dbus_message_get_signature(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_message_get_signature(GDBusMessage_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_g_dbus_message_get_serial(value self)
{
CAMLparam1(self);

guint32 result = g_dbus_message_get_serial(GDBusMessage_val(self));
CAMLreturn(Val_uint32(result));
}

CAMLexport CAMLprim value ml_g_dbus_message_get_sender(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_message_get_sender(GDBusMessage_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_dbus_message_get_reply_serial(value self)
{
CAMLparam1(self);

guint32 result = g_dbus_message_get_reply_serial(GDBusMessage_val(self));
CAMLreturn(Val_uint32(result));
}

CAMLexport CAMLprim value ml_g_dbus_message_get_path(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_message_get_path(GDBusMessage_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_dbus_message_get_num_unix_fds(value self)
{
CAMLparam1(self);

guint32 result = g_dbus_message_get_num_unix_fds(GDBusMessage_val(self));
CAMLreturn(Val_uint32(result));
}

CAMLexport CAMLprim value ml_g_dbus_message_get_message_type(value self)
{
CAMLparam1(self);

GDBusMessageType result = g_dbus_message_get_message_type(GDBusMessage_val(self));
CAMLreturn(Val_GioDBusMessageType(result));
}

CAMLexport CAMLprim value ml_g_dbus_message_get_member(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_message_get_member(GDBusMessage_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_dbus_message_get_locked(value self)
{
CAMLparam1(self);

gboolean result = g_dbus_message_get_locked(GDBusMessage_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_dbus_message_get_interface(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_message_get_interface(GDBusMessage_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_dbus_message_get_header(value self, value arg1)
{
CAMLparam2(self, arg1);

GVariant* result = g_dbus_message_get_header(GDBusMessage_val(self), GioDBusMessageHeaderField_val(arg1));
if (result) g_variant_ref(result);
CAMLreturn(Val_option(result, Val_GVariant));
}

CAMLexport CAMLprim value ml_g_dbus_message_get_flags(value self)
{
CAMLparam1(self);

GDBusMessageFlags result = g_dbus_message_get_flags(GDBusMessage_val(self));
CAMLreturn(Val_GioDBusMessageFlags(result));
}

CAMLexport CAMLprim value ml_g_dbus_message_get_error_name(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_message_get_error_name(GDBusMessage_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_dbus_message_get_destination(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_message_get_destination(GDBusMessage_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_dbus_message_get_byte_order(value self)
{
CAMLparam1(self);

GDBusMessageByteOrder result = g_dbus_message_get_byte_order(GDBusMessage_val(self));
CAMLreturn(Val_GioDBusMessageByteOrder(result));
}

CAMLexport CAMLprim value ml_g_dbus_message_get_body(value self)
{
CAMLparam1(self);

GVariant* result = g_dbus_message_get_body(GDBusMessage_val(self));
if (result) g_variant_ref(result);
CAMLreturn(Val_option(result, Val_GVariant));
}

#if GLIB_CHECK_VERSION(2,80,0)

CAMLexport CAMLprim value ml_g_dbus_message_get_arg0_path(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_message_get_arg0_path(GDBusMessage_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_dbus_message_get_arg0_path(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.80");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_dbus_message_get_arg0(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_message_get_arg0(GDBusMessage_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_dbus_message_copy(value self)
{
CAMLparam1(self);
GError *error = NULL;

GDBusMessage* result = g_dbus_message_copy(GDBusMessage_val(self), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GDBusMessage(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

GType g_dbus_message_get_type (void);


CAMLprim value ml_gio_d_bus_message_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_dbus_message_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_dbus_message_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_new_method_call(value arg1, value arg2, value arg3, value arg4)
{
CAMLparam4(arg1, arg2, arg3, arg4);
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_new_signal(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_copy(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_get_arg0(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_get_arg0_path(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_get_body(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_get_byte_order(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_get_destination(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_get_error_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_get_flags(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_get_header(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_get_interface(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_get_locked(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_get_member(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_get_message_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_get_num_unix_fds(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_get_path(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_get_reply_serial(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_get_sender(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_get_serial(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_get_signature(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_get_unix_fd_list(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_lock(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_new_method_error_literal(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_new_method_reply(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_print(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_set_body(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_set_byte_order(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_set_destination(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_set_error_name(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_set_flags(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_set_header(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_set_interface(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_set_member(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_set_message_type(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_set_num_unix_fds(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_set_path(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_set_reply_serial(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_set_sender(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_set_serial(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_set_signature(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_set_unix_fd_list(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_message_to_gerror(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMessage requires GLib >= 2.26");
return Val_unit;
}


#endif
