/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DBusObjectProxy */

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


CAMLexport CAMLprim value ml_g_dbus_object_proxy_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GDBusObjectProxy *obj = g_dbus_object_proxy_new(GDBusConnection_val(arg1), String_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GDBusObjectProxy(obj));
}
CAMLexport CAMLprim value ml_g_dbus_object_proxy_get_connection(value self)
{
CAMLparam1(self);

GDBusConnection* result = g_dbus_object_proxy_get_connection(GDBusObjectProxy_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GDBusConnection(result));
}

CAMLexport CAMLprim value ml_g_d_bus_object_proxy_get_g_connection(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GDBusObjectProxy *obj = (GDBusObjectProxy *)GDBusObjectProxy_val(self);
    GDBusConnection *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "g-connection");
if (pspec == NULL) caml_failwith("ml_g_d_bus_object_proxy_get_g_connection: property 'g-connection' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "g-connection", &prop_gvalue);
          prop_value = (GDBusConnection*)g_value_dup_object(&prop_gvalue);

      result = Val_GDBusConnection(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_g_d_bus_object_proxy_get_g_object_path(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GDBusObjectProxy *obj = (GDBusObjectProxy *)GDBusObjectProxy_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "g-object-path");
if (pspec == NULL) caml_failwith("ml_g_d_bus_object_proxy_get_g_object_path: property 'g-object-path' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "g-object-path", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}


CAMLprim value ml_gio_d_bus_object_proxy_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_dbus_object_proxy_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_dbus_object_proxy_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("DBusObjectProxy requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_object_proxy_get_connection(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusObjectProxy requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_d_bus_object_proxy_get_g_connection(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusObjectProxy requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_d_bus_object_proxy_get_g_object_path(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusObjectProxy requires GLib >= 2.30");
return Val_unit;
}


#endif
