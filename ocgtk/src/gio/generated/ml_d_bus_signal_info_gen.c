/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DBusSignalInfo */

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
/* Conversion functions for GDBusSignalInfo (opaque record with hidden fields) */
GDBusSignalInfo *GDBusSignalInfo_val(value v) {
  return (GDBusSignalInfo *)ml_gir_record_ptr_val(v, "GDBusSignalInfo");
}

value Val_GDBusSignalInfo(const GDBusSignalInfo *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(g_dbus_signal_info_get_type(), ptr);
}

value Val_GDBusSignalInfo_option(const GDBusSignalInfo *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GDBusSignalInfo(ptr));
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)


CAMLexport CAMLprim value ml_g_dbus_signal_info_ref(value self)
{
CAMLparam1(self);

GDBusSignalInfo* result = g_dbus_signal_info_ref(GDBusSignalInfo_val(self));
CAMLreturn(Val_GDBusSignalInfo(result));
}

GType g_dbus_signal_info_get_type (void);


CAMLprim value ml_gio_d_bus_signal_info_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_dbus_signal_info_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_dbus_signal_info_ref(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusSignalInfo requires GLib >= 2.26");
return Val_unit;
}


#endif
