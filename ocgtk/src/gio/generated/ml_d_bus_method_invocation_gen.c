/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DBusMethodInvocation */

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


#if !(defined(_WIN32))

#if GLIB_CHECK_VERSION(2,30,0)

CAMLexport CAMLprim value ml_g_dbus_method_invocation_return_value_with_unix_fd_list(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_dbus_method_invocation_return_value_with_unix_fd_list(GDBusMethodInvocation_val(self), Option_val(arg1, GVariant_val, NULL), Option_val(arg2, GUnixFDList_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_dbus_method_invocation_return_value_with_unix_fd_list(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("DBusMethodInvocation requires GLib >= 2.30");
return Val_unit;
}
#endif

#else

CAMLexport CAMLprim value ml_g_dbus_method_invocation_return_value_with_unix_fd_list(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("DBusMethodInvocation is only available on non-windows");
return Val_unit;
}

#endif /* not windows */

CAMLexport CAMLprim value ml_g_dbus_method_invocation_return_value(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_method_invocation_return_value(GDBusMethodInvocation_val(self), Option_val(arg1, GVariant_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_method_invocation_return_gerror(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_method_invocation_return_gerror(GDBusMethodInvocation_val(self), GError_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_method_invocation_return_dbus_error(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_dbus_method_invocation_return_dbus_error(GDBusMethodInvocation_val(self), String_val(arg1), String_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_method_invocation_get_sender(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_method_invocation_get_sender(GDBusMethodInvocation_val(self));
CAMLreturn(Val_option_string(result));
}

#if GLIB_CHECK_VERSION(2,38,0)

CAMLexport CAMLprim value ml_g_dbus_method_invocation_get_property_info(value self)
{
CAMLparam1(self);

const GDBusPropertyInfo* result = g_dbus_method_invocation_get_property_info(GDBusMethodInvocation_val(self));
if (result) result = g_boxed_copy(g_dbus_property_info_get_type(), result);
CAMLreturn(Val_option(result, Val_GDBusPropertyInfo));
}

#else

CAMLexport CAMLprim value ml_g_dbus_method_invocation_get_property_info(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMethodInvocation requires GLib >= 2.38");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_dbus_method_invocation_get_parameters(value self)
{
CAMLparam1(self);

GVariant* result = g_dbus_method_invocation_get_parameters(GDBusMethodInvocation_val(self));
if (result) g_variant_ref(result);
CAMLreturn(Val_GVariant(result));
}

CAMLexport CAMLprim value ml_g_dbus_method_invocation_get_object_path(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_method_invocation_get_object_path(GDBusMethodInvocation_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_g_dbus_method_invocation_get_method_name(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_method_invocation_get_method_name(GDBusMethodInvocation_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_g_dbus_method_invocation_get_method_info(value self)
{
CAMLparam1(self);

const GDBusMethodInfo* result = g_dbus_method_invocation_get_method_info(GDBusMethodInvocation_val(self));
if (result) result = g_boxed_copy(g_dbus_method_info_get_type(), result);
CAMLreturn(Val_option(result, Val_GDBusMethodInfo));
}

CAMLexport CAMLprim value ml_g_dbus_method_invocation_get_message(value self)
{
CAMLparam1(self);

GDBusMessage* result = g_dbus_method_invocation_get_message(GDBusMethodInvocation_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GDBusMessage(result));
}

CAMLexport CAMLprim value ml_g_dbus_method_invocation_get_interface_name(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_method_invocation_get_interface_name(GDBusMethodInvocation_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_dbus_method_invocation_get_connection(value self)
{
CAMLparam1(self);

GDBusConnection* result = g_dbus_method_invocation_get_connection(GDBusMethodInvocation_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GDBusConnection(result));
}


CAMLprim value ml_gio_d_bus_method_invocation_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_dbus_method_invocation_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_dbus_method_invocation_get_connection(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMethodInvocation requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_method_invocation_get_interface_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMethodInvocation requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_method_invocation_get_message(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMethodInvocation requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_method_invocation_get_method_info(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMethodInvocation requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_method_invocation_get_method_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMethodInvocation requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_method_invocation_get_object_path(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMethodInvocation requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_method_invocation_get_parameters(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMethodInvocation requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_method_invocation_get_property_info(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMethodInvocation requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_method_invocation_get_sender(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMethodInvocation requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_method_invocation_return_dbus_error(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("DBusMethodInvocation requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_method_invocation_return_gerror(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusMethodInvocation requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_method_invocation_return_value(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusMethodInvocation requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_method_invocation_return_value_with_unix_fd_list(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("DBusMethodInvocation requires GLib >= 2.26");
return Val_unit;
}


#endif
