/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DBusPropertyInfo */

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
/* Conversion functions for GDBusPropertyInfo (opaque record with hidden fields) */
GDBusPropertyInfo *GDBusPropertyInfo_val(value v) {
  return (GDBusPropertyInfo *)ml_gir_record_ptr_val(v, "GDBusPropertyInfo");
}

value Val_GDBusPropertyInfo(const GDBusPropertyInfo *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(g_dbus_property_info_get_type(), ptr);
}

value Val_GDBusPropertyInfo_option(const GDBusPropertyInfo *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GDBusPropertyInfo(ptr));
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)


CAMLexport CAMLprim value ml_g_dbus_property_info_ref(value self)
{
CAMLparam1(self);

GDBusPropertyInfo* result = g_dbus_property_info_ref(GDBusPropertyInfo_val(self));
CAMLreturn(Val_GDBusPropertyInfo(result));
}

GType g_dbus_property_info_get_type (void);


CAMLprim value ml_gio_d_bus_property_info_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_dbus_property_info_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_dbus_property_info_ref(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusPropertyInfo requires GLib >= 2.26");
return Val_unit;
}


#endif
