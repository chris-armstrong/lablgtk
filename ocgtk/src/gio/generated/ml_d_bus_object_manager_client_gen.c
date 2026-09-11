/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DBusObjectManagerClient */

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

#if GLIB_CHECK_VERSION(2,30,0)


CAMLexport CAMLprim value ml_g_dbus_object_manager_client_new_finish(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GDBusObjectManagerClient *obj = g_dbus_object_manager_client_new_finish(GAsyncResult_val(arg1), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GDBusObjectManagerClient(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_g_dbus_object_manager_client_new_for_bus_finish(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GDBusObjectManagerClient *obj = g_dbus_object_manager_client_new_for_bus_finish(GAsyncResult_val(arg1), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GDBusObjectManagerClient(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_g_dbus_object_manager_client_get_name_owner(value self)
{
CAMLparam1(self);

gchar* result = g_dbus_object_manager_client_get_name_owner(GDBusObjectManagerClient_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_dbus_object_manager_client_get_name(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_object_manager_client_get_name(GDBusObjectManagerClient_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_g_dbus_object_manager_client_get_flags(value self)
{
CAMLparam1(self);

GDBusObjectManagerClientFlags result = g_dbus_object_manager_client_get_flags(GDBusObjectManagerClient_val(self));
CAMLreturn(Val_GioDBusObjectManagerClientFlags(result));
}

CAMLexport CAMLprim value ml_g_dbus_object_manager_client_get_connection(value self)
{
CAMLparam1(self);

GDBusConnection* result = g_dbus_object_manager_client_get_connection(GDBusObjectManagerClient_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GDBusConnection(result));
}

CAMLexport CAMLprim value ml_g_d_bus_object_manager_client_get_object_path(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GDBusObjectManagerClient *obj = (GDBusObjectManagerClient *)GDBusObjectManagerClient_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "object-path");
if (pspec == NULL) caml_failwith("ml_g_d_bus_object_manager_client_get_object_path: property 'object-path' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "object-path", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}


CAMLprim value ml_gio_d_bus_object_manager_client_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_dbus_object_manager_client_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_dbus_object_manager_client_new_finish(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("DBusObjectManagerClient requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_object_manager_client_new_for_bus_finish(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("DBusObjectManagerClient requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_object_manager_client_get_connection(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusObjectManagerClient requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_object_manager_client_get_flags(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusObjectManagerClient requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_object_manager_client_get_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusObjectManagerClient requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_object_manager_client_get_name_owner(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusObjectManagerClient requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_d_bus_object_manager_client_get_object_path(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusObjectManagerClient requires GLib >= 2.30");
return Val_unit;
}


#endif
