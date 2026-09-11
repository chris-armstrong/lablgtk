/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DBusMethodInfo */

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
/* Conversion functions for GDBusMethodInfo (opaque record with hidden fields) */
GDBusMethodInfo *GDBusMethodInfo_val(value v) {
  return (GDBusMethodInfo *)ml_gir_record_ptr_val(v, "GDBusMethodInfo");
}

value Val_GDBusMethodInfo(const GDBusMethodInfo *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(g_dbus_method_info_get_type(), ptr);
}

value Val_GDBusMethodInfo_option(const GDBusMethodInfo *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GDBusMethodInfo(ptr));
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)


CAMLexport CAMLprim value ml_g_dbus_method_info_ref(value self)
{
CAMLparam1(self);

GDBusMethodInfo* result = g_dbus_method_info_ref(GDBusMethodInfo_val(self));
CAMLreturn(Val_GDBusMethodInfo(result));
}

GType g_dbus_method_info_get_type (void);


CAMLprim value ml_gio_d_bus_method_info_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_dbus_method_info_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_dbus_method_info_ref(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusMethodInfo requires GLib >= 2.26");
return Val_unit;
}


#endif
