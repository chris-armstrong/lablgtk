/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DBusInterface */

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


CAMLexport CAMLprim value ml_g_dbus_interface_set_object(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_interface_set_object(GDBusInterface_val(self), Option_val(arg1, GDBusObject_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_interface_get_info(value self)
{
CAMLparam1(self);

GDBusInterfaceInfo* result = g_dbus_interface_get_info(GDBusInterface_val(self));
if (result) result = g_boxed_copy(g_dbus_interface_info_get_type(), result);
CAMLreturn(Val_GDBusInterfaceInfo(result));
}

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_dbus_interface_dup_object(value self)
{
CAMLparam1(self);

GDBusObject* result = g_dbus_interface_dup_object(GDBusInterface_val(self));
CAMLreturn(Val_option(result, Val_GDBusObject));
}

#else

CAMLexport CAMLprim value ml_g_dbus_interface_dup_object(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusInterface requires GLib >= 2.32");
return Val_unit;
}
#endif
CAMLexport CAMLprim value ml_gio_d_bus_interface_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_DBUS_INTERFACE)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GDBusInterface");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GDBusInterface((GDBusInterface*)gobj));
}


CAMLprim value ml_gio_d_bus_interface_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_dbus_interface_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_dbus_interface_dup_object(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusInterface requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_interface_get_info(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusInterface requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_interface_set_object(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusInterface requires GLib >= 2.30");
return Val_unit;
}

CAMLexport CAMLprim value ml_gio_d_bus_interface_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("DBusInterface requires GTK >= 2.30");
    return Val_unit;
}


#endif
