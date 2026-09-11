/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DBusNodeInfo */

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
/* Conversion functions for GDBusNodeInfo (opaque record with hidden fields) */
GDBusNodeInfo *GDBusNodeInfo_val(value v) {
  return (GDBusNodeInfo *)ml_gir_record_ptr_val(v, "GDBusNodeInfo");
}

value Val_GDBusNodeInfo(const GDBusNodeInfo *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(g_dbus_node_info_get_type(), ptr);
}

value Val_GDBusNodeInfo_option(const GDBusNodeInfo *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GDBusNodeInfo(ptr));
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)


CAMLexport CAMLprim value ml_g_dbus_node_info_new_for_xml(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GDBusNodeInfo *obj = g_dbus_node_info_new_for_xml(String_val(arg1), &error);

if (error == NULL) CAMLreturn(Res_Ok(Val_GDBusNodeInfo(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_g_dbus_node_info_ref(value self)
{
CAMLparam1(self);

GDBusNodeInfo* result = g_dbus_node_info_ref(GDBusNodeInfo_val(self));
CAMLreturn(Val_GDBusNodeInfo(result));
}

CAMLexport CAMLprim value ml_g_dbus_node_info_lookup_interface(value self, value arg1)
{
CAMLparam2(self, arg1);

GDBusInterfaceInfo* result = g_dbus_node_info_lookup_interface(GDBusNodeInfo_val(self), String_val(arg1));
if (result) result = g_boxed_copy(g_dbus_interface_info_get_type(), result);
CAMLreturn(Val_option(result, Val_GDBusInterfaceInfo));
}

GType g_dbus_node_info_get_type (void);


CAMLprim value ml_gio_d_bus_node_info_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_dbus_node_info_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_dbus_node_info_new_for_xml(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("DBusNodeInfo requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_node_info_lookup_interface(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusNodeInfo requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_node_info_ref(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DBusNodeInfo requires GLib >= 2.26");
return Val_unit;
}


#endif
