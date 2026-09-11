/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DBusObjectSkeleton */

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


CAMLexport CAMLprim value ml_g_dbus_object_skeleton_new(value arg1)
{
CAMLparam1(arg1);

GDBusObjectSkeleton *obj = g_dbus_object_skeleton_new(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GDBusObjectSkeleton(obj));
}
CAMLexport CAMLprim value ml_g_dbus_object_skeleton_set_object_path(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_object_skeleton_set_object_path(GDBusObjectSkeleton_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_object_skeleton_remove_interface_by_name(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_object_skeleton_remove_interface_by_name(GDBusObjectSkeleton_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_object_skeleton_remove_interface(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_object_skeleton_remove_interface(GDBusObjectSkeleton_val(self), GDBusInterfaceSkeleton_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_object_skeleton_flush(value self)
{
CAMLparam1(self);

g_dbus_object_skeleton_flush(GDBusObjectSkeleton_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dbus_object_skeleton_add_interface(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dbus_object_skeleton_add_interface(GDBusObjectSkeleton_val(self), GDBusInterfaceSkeleton_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_d_bus_object_skeleton_get_g_object_path(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GDBusObjectSkeleton *obj = (GDBusObjectSkeleton *)GDBusObjectSkeleton_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "g-object-path");
if (pspec == NULL) caml_failwith("ml_g_d_bus_object_skeleton_get_g_object_path: property 'g-object-path' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "g-object-path", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_g_d_bus_object_skeleton_set_g_object_path(value self, value new_value)
{
    CAMLparam2(self, new_value);
GDBusObjectSkeleton *obj = (GDBusObjectSkeleton *)GDBusObjectSkeleton_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "g-object-path");
if (pspec == NULL) caml_failwith("ml_g_d_bus_object_skeleton_set_g_object_path: property 'g-object-path' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "g-object-path", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gio_d_bus_object_skeleton_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_dbus_object_skeleton_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_dbus_object_skeleton_new(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("DBusObjectSkeleton requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_object_skeleton_add_interface(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusObjectSkeleton requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_object_skeleton_flush(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusObjectSkeleton requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_object_skeleton_remove_interface(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusObjectSkeleton requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_object_skeleton_remove_interface_by_name(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusObjectSkeleton requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_object_skeleton_set_object_path(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusObjectSkeleton requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_d_bus_object_skeleton_get_g_object_path(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusObjectSkeleton requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_d_bus_object_skeleton_set_g_object_path(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusObjectSkeleton requires GLib >= 2.30");
return Val_unit;
}


#endif
