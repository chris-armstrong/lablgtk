/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ProxyAddress */

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


CAMLexport CAMLprim value ml_g_proxy_address_new_native(value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);
CAMLxparam2(arg6, arg7);

GProxyAddress *obj = g_proxy_address_new(GInetAddress_val(arg1), UInt16_val(arg2), String_val(arg3), String_val(arg4), UInt16_val(arg5), String_option_val(arg6), String_option_val(arg7));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GProxyAddress(obj));}

CAMLexport CAMLprim value ml_g_proxy_address_new_bytecode(value * argv, int argn)
{
return ml_g_proxy_address_new_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

CAMLexport CAMLprim value ml_g_proxy_address_get_username(value self)
{
CAMLparam1(self);

const gchar* result = g_proxy_address_get_username(GProxyAddress_val(self));
CAMLreturn(Val_option_string(result));
}

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_proxy_address_get_uri(value self)
{
CAMLparam1(self);

const gchar* result = g_proxy_address_get_uri(GProxyAddress_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_proxy_address_get_uri(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ProxyAddress requires GLib >= 2.34");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_proxy_address_get_protocol(value self)
{
CAMLparam1(self);

const gchar* result = g_proxy_address_get_protocol(GProxyAddress_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_g_proxy_address_get_password(value self)
{
CAMLparam1(self);

const gchar* result = g_proxy_address_get_password(GProxyAddress_val(self));
CAMLreturn(Val_option_string(result));
}

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_proxy_address_get_destination_protocol(value self)
{
CAMLparam1(self);

const gchar* result = g_proxy_address_get_destination_protocol(GProxyAddress_val(self));
CAMLreturn(caml_copy_string(result));
}

#else

CAMLexport CAMLprim value ml_g_proxy_address_get_destination_protocol(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ProxyAddress requires GLib >= 2.34");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_proxy_address_get_destination_port(value self)
{
CAMLparam1(self);

guint16 result = g_proxy_address_get_destination_port(GProxyAddress_val(self));
CAMLreturn(Val_uint16(result));
}

CAMLexport CAMLprim value ml_g_proxy_address_get_destination_hostname(value self)
{
CAMLparam1(self);

const gchar* result = g_proxy_address_get_destination_hostname(GProxyAddress_val(self));
CAMLreturn(caml_copy_string(result));
}

GType g_proxy_address_get_type (void);


CAMLprim value ml_gio_proxy_address_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_proxy_address_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_proxy_address_new(value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7)
{
CAMLparam7(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
(void)arg6;
(void)arg7;
caml_failwith("ProxyAddress requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_proxy_address_get_destination_hostname(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ProxyAddress requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_proxy_address_get_destination_port(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ProxyAddress requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_proxy_address_get_destination_protocol(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ProxyAddress requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_proxy_address_get_password(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ProxyAddress requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_proxy_address_get_protocol(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ProxyAddress requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_proxy_address_get_uri(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ProxyAddress requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_proxy_address_get_username(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ProxyAddress requires GLib >= 2.26");
return Val_unit;
}


#endif
