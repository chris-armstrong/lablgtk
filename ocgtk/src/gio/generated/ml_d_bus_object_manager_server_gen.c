/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DBusObjectManagerServer */

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


CAMLexport CAMLprim value ml_g_dbus_object_manager_server_new(value arg1)
{
CAMLparam1(arg1);

GDBusObjectManagerServer *obj = g_dbus_object_manager_server_new(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GDBusObjectManagerServer(obj));
}
CAMLexport CAMLprim value ml_g_dbus_object_manager_server_unexport(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_dbus_object_manager_server_unexport(GDBusObjectManagerServer_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_dbus_object_manager_server_set_connection(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_object_manager_server_set_connection(GDBusObjectManagerServer_val(self), Option_val(arg1, GDBusConnection_val, NULL));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_dbus_object_manager_server_is_exported(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_dbus_object_manager_server_is_exported(GDBusObjectManagerServer_val(self), GDBusObjectSkeleton_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_dbus_object_manager_server_is_exported(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusObjectManagerServer requires GLib >= 2.34");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_dbus_object_manager_server_get_connection(value self)
{
CAMLparam1(self);

GDBusConnection* result = g_dbus_object_manager_server_get_connection(GDBusObjectManagerServer_val(self));
CAMLreturn(Val_option(result, Val_GDBusConnection));
}

CAMLexport CAMLprim value ml_g_dbus_object_manager_server_export_uniquely(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_object_manager_server_export_uniquely(GDBusObjectManagerServer_val(self), GDBusObjectSkeleton_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_object_manager_server_export(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_object_manager_server_export(GDBusObjectManagerServer_val(self), GDBusObjectSkeleton_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_d_bus_object_manager_server_get_object_path(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GDBusObjectManagerServer *obj = (GDBusObjectManagerServer *)GDBusObjectManagerServer_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "object-path");
if (pspec == NULL) caml_failwith("ml_g_d_bus_object_manager_server_get_object_path: property 'object-path' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "object-path", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}


CAMLprim value ml_gio_d_bus_object_manager_server_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_dbus_object_manager_server_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_dbus_object_manager_server_new(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("DBusObjectManagerServer requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_object_manager_server_export(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusObjectManagerServer requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_object_manager_server_export_uniquely(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusObjectManagerServer requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_object_manager_server_get_connection(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusObjectManagerServer requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_object_manager_server_is_exported(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusObjectManagerServer requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_object_manager_server_set_connection(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusObjectManagerServer requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_object_manager_server_unexport(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusObjectManagerServer requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_d_bus_object_manager_server_get_object_path(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusObjectManagerServer requires GLib >= 2.30");
return Val_unit;
}


#endif
