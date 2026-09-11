/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DBusArgInfo */

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
/* Conversion functions for GDBusArgInfo (opaque record with hidden fields) */
GDBusArgInfo *GDBusArgInfo_val(value v) {
  return (GDBusArgInfo *)ml_gir_record_ptr_val(v, "GDBusArgInfo");
}

value Val_GDBusArgInfo(const GDBusArgInfo *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(g_dbus_arg_info_get_type(), ptr);
}

value Val_GDBusArgInfo_option(const GDBusArgInfo *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GDBusArgInfo(ptr));
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)


CAMLexport CAMLprim value ml_g_dbus_arg_info_ref(value self)
{
CAMLparam1(self);

GDBusArgInfo* result = g_dbus_arg_info_ref(GDBusArgInfo_val(self));
CAMLreturn(Val_GDBusArgInfo(result));
}

GType g_dbus_arg_info_get_type (void);


CAMLprim value ml_gio_d_bus_arg_info_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_dbus_arg_info_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_dbus_arg_info_ref(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusArgInfo requires GLib >= 2.26");
return Val_unit;
}


#endif
