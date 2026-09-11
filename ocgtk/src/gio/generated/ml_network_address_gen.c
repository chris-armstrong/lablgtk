/* GENERATED CODE - DO NOT EDIT */
/* C bindings for NetworkAddress */

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

CAMLexport CAMLprim value ml_g_network_address_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GNetworkAddress *obj = g_network_address_new(String_val(arg1), UInt16_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GNetworkAddress(obj));
}
#else

CAMLexport CAMLprim value ml_g_network_address_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("NetworkAddress requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,44,0)

CAMLexport CAMLprim value ml_g_network_address_new_loopback(value arg1)
{
CAMLparam1(arg1);

GNetworkAddress *obj = g_network_address_new_loopback(UInt16_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GNetworkAddress(obj));
}
#else

CAMLexport CAMLprim value ml_g_network_address_new_loopback(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("NetworkAddress requires GLib >= 2.44");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_network_address_get_scheme(value self)
{
CAMLparam1(self);

const gchar* result = g_network_address_get_scheme(GNetworkAddress_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_network_address_get_scheme(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("NetworkAddress requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_network_address_get_port(value self)
{
CAMLparam1(self);

guint16 result = g_network_address_get_port(GNetworkAddress_val(self));
CAMLreturn(Val_uint16(result));
}

#else

CAMLexport CAMLprim value ml_g_network_address_get_port(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("NetworkAddress requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_network_address_get_hostname(value self)
{
CAMLparam1(self);

const gchar* result = g_network_address_get_hostname(GNetworkAddress_val(self));
CAMLreturn(caml_copy_string(result));
}

#else

CAMLexport CAMLprim value ml_g_network_address_get_hostname(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("NetworkAddress requires GLib >= 2.22");
return Val_unit;
}
#endif


CAMLprim value ml_gio_network_address_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_network_address_get_type()));
}
