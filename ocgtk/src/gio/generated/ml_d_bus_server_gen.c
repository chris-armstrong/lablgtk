/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DBusServer */

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


CAMLexport CAMLprim value ml_g_dbus_server_new_sync(value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);
GError *error = NULL;
    
GDBusServer *obj = g_dbus_server_new_sync(String_val(arg1), GioDBusServerFlags_val(arg2), String_val(arg3), Option_val(arg4, GDBusAuthObserver_val, NULL), Option_val(arg5, GCancellable_val, NULL), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GDBusServer(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_g_dbus_server_stop(value self)
{
CAMLparam1(self);

g_dbus_server_stop(GDBusServer_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_server_start(value self)
{
CAMLparam1(self);

g_dbus_server_start(GDBusServer_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_server_is_active(value self)
{
CAMLparam1(self);

gboolean result = g_dbus_server_is_active(GDBusServer_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_dbus_server_get_guid(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_server_get_guid(GDBusServer_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_g_dbus_server_get_flags(value self)
{
CAMLparam1(self);

GDBusServerFlags result = g_dbus_server_get_flags(GDBusServer_val(self));
CAMLreturn(Val_GioDBusServerFlags(result));
}

CAMLexport CAMLprim value ml_g_dbus_server_get_client_address(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_server_get_client_address(GDBusServer_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_g_d_bus_server_get_address(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GDBusServer *obj = (GDBusServer *)GDBusServer_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "address");
if (pspec == NULL) caml_failwith("ml_g_d_bus_server_get_address: property 'address' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "address", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_g_d_bus_server_get_authentication_observer(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GDBusServer *obj = (GDBusServer *)GDBusServer_val(self);
    GDBusAuthObserver *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "authentication-observer");
if (pspec == NULL) caml_failwith("ml_g_d_bus_server_get_authentication_observer: property 'authentication-observer' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "authentication-observer", &prop_gvalue);
          prop_value = (GDBusAuthObserver*)g_value_dup_object(&prop_gvalue);

      result = Val_GDBusAuthObserver(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}


CAMLprim value ml_gio_d_bus_server_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_dbus_server_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_dbus_server_new_sync(value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
caml_failwith("DBusServer requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_server_get_client_address(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusServer requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_server_get_flags(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusServer requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_server_get_guid(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusServer requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_server_is_active(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusServer requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_server_start(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusServer requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_server_stop(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusServer requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_d_bus_server_get_address(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusServer requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_d_bus_server_get_authentication_observer(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusServer requires GLib >= 2.26");
return Val_unit;
}


#endif
