/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DBusObjectManager */

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

CAMLexport CAMLprim value ml_g_dbus_object_manager_get_objects(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = g_dbus_object_manager_get_objects(GDBusObjectManager_val(self));
Val_GList_with(c_result, result, item, cell, Val_GDBusObject((gpointer)_tmp->data));
    g_list_free(c_result);
    CAMLreturn(result);
}

#else

CAMLexport CAMLprim value ml_g_dbus_object_manager_get_objects(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusObjectManager requires GLib >= 2.30");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,30,0)

CAMLexport CAMLprim value ml_g_dbus_object_manager_get_object_path(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_object_manager_get_object_path(GDBusObjectManager_val(self));
CAMLreturn(caml_copy_string(result));
}

#else

CAMLexport CAMLprim value ml_g_dbus_object_manager_get_object_path(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusObjectManager requires GLib >= 2.30");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,30,0)

CAMLexport CAMLprim value ml_g_dbus_object_manager_get_object(value self, value arg1)
{
CAMLparam2(self, arg1);

GDBusObject* result = g_dbus_object_manager_get_object(GDBusObjectManager_val(self), String_val(arg1));
CAMLreturn(Val_option(result, Val_GDBusObject));
}

#else

CAMLexport CAMLprim value ml_g_dbus_object_manager_get_object(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusObjectManager requires GLib >= 2.30");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,30,0)

CAMLexport CAMLprim value ml_g_dbus_object_manager_get_interface(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

GDBusInterface* result = g_dbus_object_manager_get_interface(GDBusObjectManager_val(self), String_val(arg1), String_val(arg2));
CAMLreturn(Val_option(result, Val_GDBusInterface));
}

#else

CAMLexport CAMLprim value ml_g_dbus_object_manager_get_interface(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("DBusObjectManager requires GLib >= 2.30");
return Val_unit;
}
#endif
CAMLexport CAMLprim value ml_gio_d_bus_object_manager_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_DBUS_OBJECT_MANAGER)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GDBusObjectManager");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GDBusObjectManager((GDBusObjectManager*)gobj));
}

GType g_dbus_object_manager_get_type (void);


CAMLprim value ml_gio_d_bus_object_manager_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_dbus_object_manager_get_type()));
}
