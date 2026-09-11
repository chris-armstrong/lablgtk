/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SocketAddress */

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


#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_socket_address_get_native_size(value self)
{
CAMLparam1(self);

gssize result = g_socket_address_get_native_size(GSocketAddress_val(self));
CAMLreturn(Val_long(result));
}

#else

CAMLexport CAMLprim value ml_g_socket_address_get_native_size(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketAddress requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_socket_address_get_family(value self)
{
CAMLparam1(self);

GSocketFamily result = g_socket_address_get_family(GSocketAddress_val(self));
CAMLreturn(Val_GioSocketFamily(result));
}

#else

CAMLexport CAMLprim value ml_g_socket_address_get_family(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketAddress requires GLib >= 2.22");
return Val_unit;
}
#endif


CAMLprim value ml_gio_socket_address_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_socket_address_get_type()));
}
