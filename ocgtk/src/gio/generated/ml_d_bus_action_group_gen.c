/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DBusActionGroup */

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



CAMLprim value ml_gio_d_bus_action_group_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_dbus_action_group_get_type()));
}
