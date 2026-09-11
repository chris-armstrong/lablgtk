/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DBusInterfaceSkeleton */

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


#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_unexport_from_connection(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_interface_skeleton_unexport_from_connection(GDBusInterfaceSkeleton_val(self), GDBusConnection_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_unexport_from_connection(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusInterfaceSkeleton requires GLib >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_unexport(value self)
{
CAMLparam1(self);

g_dbus_interface_skeleton_unexport(GDBusInterfaceSkeleton_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_set_flags(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_interface_skeleton_set_flags(GDBusInterfaceSkeleton_val(self), GioDBusInterfaceSkeletonFlags_val(arg1));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_has_connection(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_dbus_interface_skeleton_has_connection(GDBusInterfaceSkeleton_val(self), GDBusConnection_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_has_connection(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusInterfaceSkeleton requires GLib >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_get_vtable(value self)
{
CAMLparam1(self);

GDBusInterfaceVTable* result = g_dbus_interface_skeleton_get_vtable(GDBusInterfaceSkeleton_val(self));
CAMLreturn(Val_GDBusInterfaceVTable(result));
}

CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_get_properties(value self)
{
CAMLparam1(self);

GVariant* result = g_dbus_interface_skeleton_get_properties(GDBusInterfaceSkeleton_val(self));
CAMLreturn(Val_GVariant(result));
}

CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_get_object_path(value self)
{
CAMLparam1(self);

const gchar* result = g_dbus_interface_skeleton_get_object_path(GDBusInterfaceSkeleton_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_get_info(value self)
{
CAMLparam1(self);

GDBusInterfaceInfo* result = g_dbus_interface_skeleton_get_info(GDBusInterfaceSkeleton_val(self));
if (result) result = g_boxed_copy(g_dbus_interface_info_get_type(), result);
CAMLreturn(Val_GDBusInterfaceInfo(result));
}

CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_get_flags(value self)
{
CAMLparam1(self);

GDBusInterfaceSkeletonFlags result = g_dbus_interface_skeleton_get_flags(GDBusInterfaceSkeleton_val(self));
CAMLreturn(Val_GioDBusInterfaceSkeletonFlags(result));
}

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_get_connections(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = g_dbus_interface_skeleton_get_connections(GDBusInterfaceSkeleton_val(self));
Val_GList_with(c_result, result, item, cell, Val_GDBusConnection((gpointer)_tmp->data));
    g_list_free(c_result);
    CAMLreturn(result);
}

#else

CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_get_connections(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusInterfaceSkeleton requires GLib >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_get_connection(value self)
{
CAMLparam1(self);

GDBusConnection* result = g_dbus_interface_skeleton_get_connection(GDBusInterfaceSkeleton_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GDBusConnection));
}

CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_flush(value self)
{
CAMLparam1(self);

g_dbus_interface_skeleton_flush(GDBusInterfaceSkeleton_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_export(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gboolean result = g_dbus_interface_skeleton_export(GDBusInterfaceSkeleton_val(self), GDBusConnection_val(arg1), String_val(arg2), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_d_bus_interface_skeleton_get_g_flags(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GDBusInterfaceSkeleton *obj = (GDBusInterfaceSkeleton *)GDBusInterfaceSkeleton_val(self);
    GDBusInterfaceSkeletonFlags prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "g-flags");
if (pspec == NULL) caml_failwith("ml_g_d_bus_interface_skeleton_get_g_flags: property 'g-flags' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "g-flags", &prop_gvalue);
          prop_value = (GDBusInterfaceSkeletonFlags)g_value_get_flags(&prop_gvalue);

      result = Val_GioDBusInterfaceSkeletonFlags(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_g_d_bus_interface_skeleton_set_g_flags(value self, value new_value)
{
    CAMLparam2(self, new_value);
GDBusInterfaceSkeleton *obj = (GDBusInterfaceSkeleton *)GDBusInterfaceSkeleton_val(self);
    GDBusInterfaceSkeletonFlags c_value = GioDBusInterfaceSkeletonFlags_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "g-flags");
if (pspec == NULL) caml_failwith("ml_g_d_bus_interface_skeleton_set_g_flags: property 'g-flags' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_flags(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "g-flags", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

GType g_dbus_interface_skeleton_get_type (void);


CAMLprim value ml_gio_d_bus_interface_skeleton_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_dbus_interface_skeleton_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_export(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("DBusInterfaceSkeleton requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_flush(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusInterfaceSkeleton requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_get_connection(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusInterfaceSkeleton requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_get_connections(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusInterfaceSkeleton requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_get_flags(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusInterfaceSkeleton requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_get_info(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusInterfaceSkeleton requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_get_object_path(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusInterfaceSkeleton requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_get_properties(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusInterfaceSkeleton requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_get_vtable(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusInterfaceSkeleton requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_has_connection(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusInterfaceSkeleton requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_set_flags(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusInterfaceSkeleton requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_unexport(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusInterfaceSkeleton requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_interface_skeleton_unexport_from_connection(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusInterfaceSkeleton requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_d_bus_interface_skeleton_get_g_flags(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusInterfaceSkeleton requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_d_bus_interface_skeleton_set_g_flags(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusInterfaceSkeleton requires GLib >= 2.30");
return Val_unit;
}


#endif
