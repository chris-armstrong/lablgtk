/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DBusProxy */

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


CAMLexport CAMLprim value ml_g_dbus_proxy_new_finish(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GDBusProxy *obj = g_dbus_proxy_new_finish(GAsyncResult_val(arg1), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GDBusProxy(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_g_dbus_proxy_new_for_bus_finish(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GDBusProxy *obj = g_dbus_proxy_new_for_bus_finish(GAsyncResult_val(arg1), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GDBusProxy(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_g_dbus_proxy_new_for_bus_sync_native(value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);
CAMLxparam2(arg6, arg7);
GError *error = NULL;
    
GDBusProxy *obj = g_dbus_proxy_new_for_bus_sync(GioBusType_val(arg1), GioDBusProxyFlags_val(arg2), Option_val(arg3, GDBusInterfaceInfo_val, NULL), String_val(arg4), String_val(arg5), String_val(arg6), Option_val(arg7, GCancellable_val, NULL), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GDBusProxy(obj))); else CAMLreturn(Res_Error(Val_GError(error)));}

CAMLexport CAMLprim value ml_g_dbus_proxy_new_for_bus_sync_bytecode(value * argv, int argn)
{
return ml_g_dbus_proxy_new_for_bus_sync_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

CAMLexport CAMLprim value ml_g_dbus_proxy_new_sync_native(value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);
CAMLxparam2(arg6, arg7);
GError *error = NULL;
    
GDBusProxy *obj = g_dbus_proxy_new_sync(GDBusConnection_val(arg1), GioDBusProxyFlags_val(arg2), Option_val(arg3, GDBusInterfaceInfo_val, NULL), String_option_val(arg4), String_val(arg5), String_val(arg6), Option_val(arg7, GCancellable_val, NULL), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GDBusProxy(obj))); else CAMLreturn(Res_Error(Val_GError(error)));}

CAMLexport CAMLprim value ml_g_dbus_proxy_new_sync_bytecode(value * argv, int argn)
{
return ml_g_dbus_proxy_new_sync_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

CAMLexport CAMLprim value ml_g_dbus_proxy_set_interface_info(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_proxy_set_interface_info(GDBusProxy_val(self), Option_val(arg1, GDBusInterfaceInfo_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_proxy_set_default_timeout(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_proxy_set_default_timeout(GDBusProxy_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_proxy_set_cached_property(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_dbus_proxy_set_cached_property(GDBusProxy_val(self), String_val(arg1), Option_val(arg2, GVariant_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_proxy_get_object_path(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_proxy_get_object_path(GDBusProxy_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_g_dbus_proxy_get_name_owner(value self)
{
CAMLparam1(self);

gchar* result = g_dbus_proxy_get_name_owner(GDBusProxy_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_dbus_proxy_get_name(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_proxy_get_name(GDBusProxy_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_dbus_proxy_get_interface_name(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_proxy_get_interface_name(GDBusProxy_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_g_dbus_proxy_get_interface_info(value self)
{
CAMLparam1(self);

GDBusInterfaceInfo* result = g_dbus_proxy_get_interface_info(GDBusProxy_val(self));
if (result) result = g_boxed_copy(g_dbus_interface_info_get_type(), result);
CAMLreturn(Val_option(result, Val_GDBusInterfaceInfo));
}

CAMLexport CAMLprim value ml_g_dbus_proxy_get_flags(value self)
{
CAMLparam1(self);

GDBusProxyFlags result = g_dbus_proxy_get_flags(GDBusProxy_val(self));
CAMLreturn(Val_GioDBusProxyFlags(result));
}

CAMLexport CAMLprim value ml_g_dbus_proxy_get_default_timeout(value self)
{
CAMLparam1(self);

gint result = g_dbus_proxy_get_default_timeout(GDBusProxy_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_g_dbus_proxy_get_connection(value self)
{
CAMLparam1(self);

GDBusConnection* result = g_dbus_proxy_get_connection(GDBusProxy_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GDBusConnection(result));
}

CAMLexport CAMLprim value ml_g_dbus_proxy_get_cached_property_names(value self)
{
CAMLparam1(self);

gchar** result = g_dbus_proxy_get_cached_property_names(GDBusProxy_val(self));
    CAMLlocal2(ml_result, ml_result_opt);
    if (result == NULL) {
      ml_result_opt = Val_none;
    } else {
      int result_length = 0;
    while (result[result_length] != NULL) result_length++;
      ml_result = caml_alloc(result_length, 0);
      for (int i = 0; i < result_length; i++) {
        Store_field(ml_result, i, caml_copy_string(result[i]));
      }
      ml_result_opt = Val_some(ml_result);
            for (int i = 0; i < result_length; i++) {
      g_free((gpointer)result[i]);
    }
    g_free(result);
    }
CAMLreturn(ml_result_opt);
}

CAMLexport CAMLprim value ml_g_dbus_proxy_get_cached_property(value self, value arg1)
{
CAMLparam2(self, arg1);

GVariant* result = g_dbus_proxy_get_cached_property(GDBusProxy_val(self), String_val(arg1));
CAMLreturn(Val_option(result, Val_GVariant));
}

CAMLexport CAMLprim value ml_g_dbus_proxy_call_sync_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);
GError *error = NULL;

GVariant* result = g_dbus_proxy_call_sync(GDBusProxy_val(self), String_val(arg1), Option_val(arg2, GVariant_val, NULL), GioDBusCallFlags_val(arg3), Int_val(arg4), Option_val(arg5, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GVariant(result))); else CAMLreturn(Res_Error(Val_GError(error)));}

CAMLexport CAMLprim value ml_g_dbus_proxy_call_sync_bytecode(value * argv, int argn)
{
return ml_g_dbus_proxy_call_sync_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_g_dbus_proxy_call_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GVariant* result = g_dbus_proxy_call_finish(GDBusProxy_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GVariant(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_d_bus_proxy_get_g_connection(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GDBusProxy *obj = (GDBusProxy *)GDBusProxy_val(self);
    GDBusConnection *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "g-connection");
if (pspec == NULL) caml_failwith("ml_g_d_bus_proxy_get_g_connection: property 'g-connection' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "g-connection", &prop_gvalue);
          prop_value = (GDBusConnection*)g_value_dup_object(&prop_gvalue);

      result = Val_GDBusConnection(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_g_d_bus_proxy_get_g_default_timeout(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GDBusProxy *obj = (GDBusProxy *)GDBusProxy_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "g-default-timeout");
if (pspec == NULL) caml_failwith("ml_g_d_bus_proxy_get_g_default_timeout: property 'g-default-timeout' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "g-default-timeout", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_g_d_bus_proxy_set_g_default_timeout(value self, value new_value)
{
    CAMLparam2(self, new_value);
GDBusProxy *obj = (GDBusProxy *)GDBusProxy_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "g-default-timeout");
if (pspec == NULL) caml_failwith("ml_g_d_bus_proxy_set_g_default_timeout: property 'g-default-timeout' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "g-default-timeout", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_d_bus_proxy_get_g_flags(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GDBusProxy *obj = (GDBusProxy *)GDBusProxy_val(self);
    GDBusProxyFlags prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "g-flags");
if (pspec == NULL) caml_failwith("ml_g_d_bus_proxy_get_g_flags: property 'g-flags' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "g-flags", &prop_gvalue);
          prop_value = (GDBusProxyFlags)g_value_get_flags(&prop_gvalue);

      result = Val_GioDBusProxyFlags(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_g_d_bus_proxy_get_g_interface_info(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GDBusProxy *obj = (GDBusProxy *)GDBusProxy_val(self);
    GDBusInterfaceInfo *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "g-interface-info");
if (pspec == NULL) caml_failwith("ml_g_d_bus_proxy_get_g_interface_info: property 'g-interface-info' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "g-interface-info", &prop_gvalue);
          prop_value = (GDBusInterfaceInfo*)g_value_get_boxed(&prop_gvalue);

      result = Val_GDBusInterfaceInfo(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_g_d_bus_proxy_set_g_interface_info(value self, value new_value)
{
    CAMLparam2(self, new_value);
GDBusProxy *obj = (GDBusProxy *)GDBusProxy_val(self);
    GDBusInterfaceInfo *c_value = GDBusInterfaceInfo_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "g-interface-info");
if (pspec == NULL) caml_failwith("ml_g_d_bus_proxy_set_g_interface_info: property 'g-interface-info' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boxed(&prop_gvalue, &c_value);
g_object_set_property(G_OBJECT(obj), "g-interface-info", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_d_bus_proxy_get_g_interface_name(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GDBusProxy *obj = (GDBusProxy *)GDBusProxy_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "g-interface-name");
if (pspec == NULL) caml_failwith("ml_g_d_bus_proxy_get_g_interface_name: property 'g-interface-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "g-interface-name", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_g_d_bus_proxy_get_g_name(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GDBusProxy *obj = (GDBusProxy *)GDBusProxy_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "g-name");
if (pspec == NULL) caml_failwith("ml_g_d_bus_proxy_get_g_name: property 'g-name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "g-name", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_g_d_bus_proxy_get_g_name_owner(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GDBusProxy *obj = (GDBusProxy *)GDBusProxy_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "g-name-owner");
if (pspec == NULL) caml_failwith("ml_g_d_bus_proxy_get_g_name_owner: property 'g-name-owner' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "g-name-owner", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_g_d_bus_proxy_get_g_object_path(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GDBusProxy *obj = (GDBusProxy *)GDBusProxy_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "g-object-path");
if (pspec == NULL) caml_failwith("ml_g_d_bus_proxy_get_g_object_path: property 'g-object-path' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "g-object-path", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else


CAMLexport CAMLprim value ml_g_dbus_proxy_new_finish(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_proxy_new_for_bus_finish(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_proxy_new_for_bus_sync(value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7)
{
CAMLparam7(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
(void)arg6;
(void)arg7;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_proxy_new_sync(value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7)
{
CAMLparam7(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
(void)arg6;
(void)arg7;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_proxy_call_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_proxy_call_sync(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_proxy_get_cached_property(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_proxy_get_cached_property_names(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_proxy_get_connection(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_proxy_get_default_timeout(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_proxy_get_flags(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_proxy_get_interface_info(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_proxy_get_interface_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_proxy_get_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_proxy_get_name_owner(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_proxy_get_object_path(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_proxy_set_cached_property(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_proxy_set_default_timeout(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_proxy_set_interface_info(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_d_bus_proxy_get_g_connection(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_d_bus_proxy_get_g_default_timeout(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_d_bus_proxy_set_g_default_timeout(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_d_bus_proxy_get_g_flags(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_d_bus_proxy_get_g_interface_info(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_d_bus_proxy_set_g_interface_info(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_d_bus_proxy_get_g_interface_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_d_bus_proxy_get_g_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_d_bus_proxy_get_g_name_owner(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_d_bus_proxy_get_g_object_path(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusProxy requires GLib >= 2.26");
return Val_unit;
}


#endif
