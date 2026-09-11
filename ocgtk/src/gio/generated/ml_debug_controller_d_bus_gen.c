/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DebugControllerDBus */

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

#if GLIB_CHECK_VERSION(2,72,0)


CAMLexport CAMLprim value ml_g_debug_controller_dbus_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
GError *error = NULL;
    
GDebugControllerDBus *obj = g_debug_controller_dbus_new(GDBusConnection_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GDebugControllerDBus(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_g_debug_controller_dbus_stop(value self)
{
CAMLparam1(self);

g_debug_controller_dbus_stop(GDebugControllerDBus_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_debug_controller_d_bus_get_connection(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GDebugControllerDBus *obj = (GDebugControllerDBus *)GDebugControllerDBus_val(self);
    GDBusConnection *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "connection");
if (pspec == NULL) caml_failwith("ml_g_debug_controller_d_bus_get_connection: property 'connection' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "connection", &prop_gvalue);
          prop_value = (GDBusConnection*)g_value_dup_object(&prop_gvalue);

      result = Val_GDBusConnection(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

GType g_debug_controller_dbus_get_type (void);


CAMLprim value ml_gio_debug_controller_d_bus_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_debug_controller_dbus_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_debug_controller_dbus_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("DebugControllerDBus requires GLib >= 2.72");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_debug_controller_dbus_stop(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DebugControllerDBus requires GLib >= 2.72");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_debug_controller_d_bus_get_connection(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DebugControllerDBus requires GLib >= 2.72");
return Val_unit;
}


#endif
