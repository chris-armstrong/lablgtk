/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SocketClient */

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


CAMLexport CAMLprim value ml_g_socket_client_new(value unit)
{
CAMLparam1(unit);

GSocketClient *obj = g_socket_client_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GSocketClient(obj));
}
#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_socket_client_set_tls_validation_flags(value self, value arg1)
{
CAMLparam2(self, arg1);

g_socket_client_set_tls_validation_flags(GSocketClient_val(self), GioTlsCertificateFlags_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_socket_client_set_tls_validation_flags(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketClient requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_socket_client_set_tls(value self, value arg1)
{
CAMLparam2(self, arg1);

g_socket_client_set_tls(GSocketClient_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_socket_client_set_tls(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketClient requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_socket_client_set_timeout(value self, value arg1)
{
CAMLparam2(self, arg1);

g_socket_client_set_timeout(GSocketClient_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_socket_client_set_timeout(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketClient requires GLib >= 2.26");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_socket_client_set_socket_type(value self, value arg1)
{
CAMLparam2(self, arg1);

g_socket_client_set_socket_type(GSocketClient_val(self), GioSocketType_val(arg1));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,36,0)

CAMLexport CAMLprim value ml_g_socket_client_set_proxy_resolver(value self, value arg1)
{
CAMLparam2(self, arg1);

g_socket_client_set_proxy_resolver(GSocketClient_val(self), Option_val(arg1, GProxyResolver_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_socket_client_set_proxy_resolver(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketClient requires GLib >= 2.36");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_socket_client_set_protocol(value self, value arg1)
{
CAMLparam2(self, arg1);

g_socket_client_set_protocol(GSocketClient_val(self), GioSocketProtocol_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_socket_client_set_local_address(value self, value arg1)
{
CAMLparam2(self, arg1);

g_socket_client_set_local_address(GSocketClient_val(self), Option_val(arg1, GSocketAddress_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_socket_client_set_family(value self, value arg1)
{
CAMLparam2(self, arg1);

g_socket_client_set_family(GSocketClient_val(self), GioSocketFamily_val(arg1));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_socket_client_set_enable_proxy(value self, value arg1)
{
CAMLparam2(self, arg1);

g_socket_client_set_enable_proxy(GSocketClient_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_socket_client_set_enable_proxy(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketClient requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_socket_client_get_tls_validation_flags(value self)
{
CAMLparam1(self);

GTlsCertificateFlags result = g_socket_client_get_tls_validation_flags(GSocketClient_val(self));
CAMLreturn(Val_GioTlsCertificateFlags(result));
}

#else

CAMLexport CAMLprim value ml_g_socket_client_get_tls_validation_flags(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketClient requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_socket_client_get_tls(value self)
{
CAMLparam1(self);

gboolean result = g_socket_client_get_tls(GSocketClient_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_socket_client_get_tls(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketClient requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_socket_client_get_timeout(value self)
{
CAMLparam1(self);

guint result = g_socket_client_get_timeout(GSocketClient_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_g_socket_client_get_timeout(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketClient requires GLib >= 2.26");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_socket_client_get_socket_type(value self)
{
CAMLparam1(self);

GSocketType result = g_socket_client_get_socket_type(GSocketClient_val(self));
CAMLreturn(Val_GioSocketType(result));
}

#if GLIB_CHECK_VERSION(2,36,0)

CAMLexport CAMLprim value ml_g_socket_client_get_proxy_resolver(value self)
{
CAMLparam1(self);

GProxyResolver* result = g_socket_client_get_proxy_resolver(GSocketClient_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GProxyResolver(result));
}

#else

CAMLexport CAMLprim value ml_g_socket_client_get_proxy_resolver(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketClient requires GLib >= 2.36");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_socket_client_get_protocol(value self)
{
CAMLparam1(self);

GSocketProtocol result = g_socket_client_get_protocol(GSocketClient_val(self));
CAMLreturn(Val_GioSocketProtocol(result));
}

CAMLexport CAMLprim value ml_g_socket_client_get_local_address(value self)
{
CAMLparam1(self);

GSocketAddress* result = g_socket_client_get_local_address(GSocketClient_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GSocketAddress));
}

CAMLexport CAMLprim value ml_g_socket_client_get_family(value self)
{
CAMLparam1(self);

GSocketFamily result = g_socket_client_get_family(GSocketClient_val(self));
CAMLreturn(Val_GioSocketFamily(result));
}

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_socket_client_get_enable_proxy(value self)
{
CAMLparam1(self);

gboolean result = g_socket_client_get_enable_proxy(GSocketClient_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_socket_client_get_enable_proxy(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketClient requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_socket_client_connect_to_uri_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GSocketConnection* result = g_socket_client_connect_to_uri_finish(GSocketClient_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GSocketConnection(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_socket_client_connect_to_uri_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketClient requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_socket_client_connect_to_uri(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GError *error = NULL;

GSocketConnection* result = g_socket_client_connect_to_uri(GSocketClient_val(self), String_val(arg1), UInt16_val(arg2), Option_val(arg3, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GSocketConnection(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_socket_client_connect_to_uri(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("SocketClient requires GLib >= 2.26");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_socket_client_connect_to_service_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GSocketConnection* result = g_socket_client_connect_to_service_finish(GSocketClient_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GSocketConnection(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_socket_client_connect_to_service(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GError *error = NULL;

GSocketConnection* result = g_socket_client_connect_to_service(GSocketClient_val(self), String_val(arg1), String_val(arg2), Option_val(arg3, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GSocketConnection(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_socket_client_connect_to_host_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GSocketConnection* result = g_socket_client_connect_to_host_finish(GSocketClient_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GSocketConnection(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_socket_client_connect_to_host(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GError *error = NULL;

GSocketConnection* result = g_socket_client_connect_to_host(GSocketClient_val(self), String_val(arg1), UInt16_val(arg2), Option_val(arg3, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GSocketConnection(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_socket_client_connect_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GSocketConnection* result = g_socket_client_connect_finish(GSocketClient_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GSocketConnection(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_socket_client_connect(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

GSocketConnection* result = g_socket_client_connect(GSocketClient_val(self), GSocketConnectable_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GSocketConnection(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_socket_client_add_application_proxy(value self, value arg1)
{
CAMLparam2(self, arg1);

g_socket_client_add_application_proxy(GSocketClient_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_socket_client_get_type(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GSocketClient *obj = (GSocketClient *)GSocketClient_val(self);
    GSocketType prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "type");
if (pspec == NULL) caml_failwith("ml_g_socket_client_get_type: property 'type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "type", &prop_gvalue);
          prop_value = (GSocketType)g_value_get_enum(&prop_gvalue);

      result = Val_GioSocketType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_g_socket_client_set_type(value self, value new_value)
{
    CAMLparam2(self, new_value);
GSocketClient *obj = (GSocketClient *)GSocketClient_val(self);
    GSocketType c_value = GioSocketType_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "type");
if (pspec == NULL) caml_failwith("ml_g_socket_client_set_type: property 'type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "type", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gio_socket_client_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_socket_client_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_socket_client_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_add_application_proxy(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_connect(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_connect_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_connect_to_host(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_connect_to_host_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_connect_to_service(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_connect_to_service_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_connect_to_uri(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_connect_to_uri_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_get_enable_proxy(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_get_family(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_get_local_address(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_get_protocol(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_get_proxy_resolver(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_get_socket_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_get_timeout(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_get_tls(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_get_tls_validation_flags(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_set_enable_proxy(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_set_family(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_set_local_address(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_set_protocol(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_set_proxy_resolver(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_set_socket_type(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_set_timeout(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_set_tls(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_set_tls_validation_flags(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_get_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_client_set_type(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketClient requires GLib >= 2.22");
return Val_unit;
}


#endif
