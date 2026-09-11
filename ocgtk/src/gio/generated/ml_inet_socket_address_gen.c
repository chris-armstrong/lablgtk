/* GENERATED CODE - DO NOT EDIT */
/* C bindings for InetSocketAddress */

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

CAMLexport CAMLprim value ml_g_inet_socket_address_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GInetSocketAddress *obj = g_inet_socket_address_new(GInetAddress_val(arg1), UInt16_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GInetSocketAddress(obj));
}
#else

CAMLexport CAMLprim value ml_g_inet_socket_address_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("InetSocketAddress requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,40,0)

CAMLexport CAMLprim value ml_g_inet_socket_address_new_from_string(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GInetSocketAddress *obj = g_inet_socket_address_new_from_string(String_val(arg1), Int_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GInetSocketAddress(obj));
}
#else

CAMLexport CAMLprim value ml_g_inet_socket_address_new_from_string(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("InetSocketAddress requires GLib >= 2.40");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_inet_socket_address_get_scope_id(value self)
{
CAMLparam1(self);

guint32 result = g_inet_socket_address_get_scope_id(GInetSocketAddress_val(self));
CAMLreturn(Val_uint32(result));
}

#else

CAMLexport CAMLprim value ml_g_inet_socket_address_get_scope_id(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("InetSocketAddress requires GLib >= 2.32");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_inet_socket_address_get_port(value self)
{
CAMLparam1(self);

guint16 result = g_inet_socket_address_get_port(GInetSocketAddress_val(self));
CAMLreturn(Val_uint16(result));
}

#else

CAMLexport CAMLprim value ml_g_inet_socket_address_get_port(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("InetSocketAddress requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_inet_socket_address_get_flowinfo(value self)
{
CAMLparam1(self);

guint32 result = g_inet_socket_address_get_flowinfo(GInetSocketAddress_val(self));
CAMLreturn(Val_uint32(result));
}

#else

CAMLexport CAMLprim value ml_g_inet_socket_address_get_flowinfo(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("InetSocketAddress requires GLib >= 2.32");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_inet_socket_address_get_address(value self)
{
CAMLparam1(self);

GInetAddress* result = g_inet_socket_address_get_address(GInetSocketAddress_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GInetAddress(result));
}

#else

CAMLexport CAMLprim value ml_g_inet_socket_address_get_address(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("InetSocketAddress requires GLib >= 2.22");
return Val_unit;
}
#endif

GType g_inet_socket_address_get_type (void);


CAMLprim value ml_gio_inet_socket_address_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_inet_socket_address_get_type()));
}
