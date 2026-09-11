/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DBusInterfaceInfo */

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
/* Conversion functions for GDBusInterfaceInfo (opaque record with hidden fields) */
GDBusInterfaceInfo *GDBusInterfaceInfo_val(value v) {
  return (GDBusInterfaceInfo *)ml_gir_record_ptr_val(v, "GDBusInterfaceInfo");
}

value Val_GDBusInterfaceInfo(const GDBusInterfaceInfo *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(g_dbus_interface_info_get_type(), ptr);
}

value Val_GDBusInterfaceInfo_option(const GDBusInterfaceInfo *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GDBusInterfaceInfo(ptr));
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)


CAMLexport CAMLprim value ml_g_dbus_interface_info_ref(value self)
{
CAMLparam1(self);

GDBusInterfaceInfo* result = g_dbus_interface_info_ref(GDBusInterfaceInfo_val(self));
CAMLreturn(Val_GDBusInterfaceInfo(result));
}

CAMLexport CAMLprim value ml_g_dbus_interface_info_lookup_signal(value self, value arg1)
{
CAMLparam2(self, arg1);

GDBusSignalInfo* result = g_dbus_interface_info_lookup_signal(GDBusInterfaceInfo_val(self), String_val(arg1));
if (result) result = g_boxed_copy(g_dbus_signal_info_get_type(), result);
CAMLreturn(Val_option(result, Val_GDBusSignalInfo));
}

CAMLexport CAMLprim value ml_g_dbus_interface_info_lookup_property(value self, value arg1)
{
CAMLparam2(self, arg1);

GDBusPropertyInfo* result = g_dbus_interface_info_lookup_property(GDBusInterfaceInfo_val(self), String_val(arg1));
if (result) result = g_boxed_copy(g_dbus_property_info_get_type(), result);
CAMLreturn(Val_option(result, Val_GDBusPropertyInfo));
}

CAMLexport CAMLprim value ml_g_dbus_interface_info_lookup_method(value self, value arg1)
{
CAMLparam2(self, arg1);

GDBusMethodInfo* result = g_dbus_interface_info_lookup_method(GDBusInterfaceInfo_val(self), String_val(arg1));
if (result) result = g_boxed_copy(g_dbus_method_info_get_type(), result);
CAMLreturn(Val_option(result, Val_GDBusMethodInfo));
}

#if GLIB_CHECK_VERSION(2,30,0)

CAMLexport CAMLprim value ml_g_dbus_interface_info_cache_release(value self)
{
CAMLparam1(self);

g_dbus_interface_info_cache_release(GDBusInterfaceInfo_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_dbus_interface_info_cache_release(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusInterfaceInfo requires GLib >= 2.30");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,30,0)

CAMLexport CAMLprim value ml_g_dbus_interface_info_cache_build(value self)
{
CAMLparam1(self);

g_dbus_interface_info_cache_build(GDBusInterfaceInfo_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_dbus_interface_info_cache_build(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusInterfaceInfo requires GLib >= 2.30");
return Val_unit;
}
#endif


CAMLprim value ml_gio_d_bus_interface_info_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_dbus_interface_info_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_dbus_interface_info_cache_build(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusInterfaceInfo requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_interface_info_cache_release(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusInterfaceInfo requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_interface_info_lookup_method(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusInterfaceInfo requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_interface_info_lookup_property(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusInterfaceInfo requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_interface_info_lookup_signal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusInterfaceInfo requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_interface_info_ref(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusInterfaceInfo requires GLib >= 2.26");
return Val_unit;
}


#endif
