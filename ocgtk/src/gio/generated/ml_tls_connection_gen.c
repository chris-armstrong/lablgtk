/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TlsConnection */

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

#if GLIB_CHECK_VERSION(2,28,0)


CAMLexport CAMLprim value ml_g_tls_connection_set_use_system_certdb(value self, value arg1)
{
CAMLparam2(self, arg1);

g_tls_connection_set_use_system_certdb(GTlsConnection_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_tls_connection_set_require_close_notify(value self, value arg1)
{
CAMLparam2(self, arg1);

g_tls_connection_set_require_close_notify(GTlsConnection_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_tls_connection_set_rehandshake_mode(value self, value arg1)
{
CAMLparam2(self, arg1);

g_tls_connection_set_rehandshake_mode(GTlsConnection_val(self), GioTlsRehandshakeMode_val(arg1));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,30,0)

CAMLexport CAMLprim value ml_g_tls_connection_set_interaction(value self, value arg1)
{
CAMLparam2(self, arg1);

g_tls_connection_set_interaction(GTlsConnection_val(self), Option_val(arg1, GTlsInteraction_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_tls_connection_set_interaction(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsConnection requires GLib >= 2.30");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,30,0)

CAMLexport CAMLprim value ml_g_tls_connection_set_database(value self, value arg1)
{
CAMLparam2(self, arg1);

g_tls_connection_set_database(GTlsConnection_val(self), Option_val(arg1, GTlsDatabase_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_tls_connection_set_database(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsConnection requires GLib >= 2.30");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_tls_connection_set_certificate(value self, value arg1)
{
CAMLparam2(self, arg1);

g_tls_connection_set_certificate(GTlsConnection_val(self), GTlsCertificate_val(arg1));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,60,0)

CAMLexport CAMLprim value ml_g_tls_connection_set_advertised_protocols(value self, value arg1)
{
CAMLparam2(self, arg1);
    int arg1_length = 0;
    const char** c_arg1 = NULL;
    
    if (Is_some(arg1)) {
        value array = Some_val(arg1);
        arg1_length = Wosize_val(array);
        c_arg1 = (const char**)g_malloc(sizeof(const char*) * (arg1_length + 1));
        for (int i = 0; i < arg1_length; i++) {
          c_arg1[i] = String_val(Field(array, i));
        }
        c_arg1[arg1_length] = NULL;
    }

g_tls_connection_set_advertised_protocols(GTlsConnection_val(self), c_arg1);
    if (c_arg1) g_free(c_arg1);
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_tls_connection_set_advertised_protocols(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsConnection requires GLib >= 2.60");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_tls_connection_handshake_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_tls_connection_handshake_finish(GTlsConnection_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_tls_connection_handshake(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_tls_connection_handshake(GTlsConnection_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_tls_connection_get_use_system_certdb(value self)
{
CAMLparam1(self);

gboolean result = g_tls_connection_get_use_system_certdb(GTlsConnection_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_tls_connection_get_require_close_notify(value self)
{
CAMLparam1(self);

gboolean result = g_tls_connection_get_require_close_notify(GTlsConnection_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_tls_connection_get_rehandshake_mode(value self)
{
CAMLparam1(self);

GTlsRehandshakeMode result = g_tls_connection_get_rehandshake_mode(GTlsConnection_val(self));
CAMLreturn(Val_GioTlsRehandshakeMode(result));
}

#if GLIB_CHECK_VERSION(2,70,0)

CAMLexport CAMLprim value ml_g_tls_connection_get_protocol_version(value self)
{
CAMLparam1(self);

GTlsProtocolVersion result = g_tls_connection_get_protocol_version(GTlsConnection_val(self));
CAMLreturn(Val_GioTlsProtocolVersion(result));
}

#else

CAMLexport CAMLprim value ml_g_tls_connection_get_protocol_version(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsConnection requires GLib >= 2.70");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_tls_connection_get_peer_certificate_errors(value self)
{
CAMLparam1(self);

GTlsCertificateFlags result = g_tls_connection_get_peer_certificate_errors(GTlsConnection_val(self));
CAMLreturn(Val_GioTlsCertificateFlags(result));
}

CAMLexport CAMLprim value ml_g_tls_connection_get_peer_certificate(value self)
{
CAMLparam1(self);

GTlsCertificate* result = g_tls_connection_get_peer_certificate(GTlsConnection_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GTlsCertificate));
}

#if GLIB_CHECK_VERSION(2,60,0)

CAMLexport CAMLprim value ml_g_tls_connection_get_negotiated_protocol(value self)
{
CAMLparam1(self);

const gchar* result = g_tls_connection_get_negotiated_protocol(GTlsConnection_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_tls_connection_get_negotiated_protocol(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsConnection requires GLib >= 2.60");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,30,0)

CAMLexport CAMLprim value ml_g_tls_connection_get_interaction(value self)
{
CAMLparam1(self);

GTlsInteraction* result = g_tls_connection_get_interaction(GTlsConnection_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GTlsInteraction));
}

#else

CAMLexport CAMLprim value ml_g_tls_connection_get_interaction(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsConnection requires GLib >= 2.30");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,30,0)

CAMLexport CAMLprim value ml_g_tls_connection_get_database(value self)
{
CAMLparam1(self);

GTlsDatabase* result = g_tls_connection_get_database(GTlsConnection_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GTlsDatabase));
}

#else

CAMLexport CAMLprim value ml_g_tls_connection_get_database(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsConnection requires GLib >= 2.30");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,70,0)

CAMLexport CAMLprim value ml_g_tls_connection_get_ciphersuite_name(value self)
{
CAMLparam1(self);

gchar* result = g_tls_connection_get_ciphersuite_name(GTlsConnection_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_tls_connection_get_ciphersuite_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsConnection requires GLib >= 2.70");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_tls_connection_get_certificate(value self)
{
CAMLparam1(self);

GTlsCertificate* result = g_tls_connection_get_certificate(GTlsConnection_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GTlsCertificate));
}

CAMLexport CAMLprim value ml_g_tls_connection_emit_accept_certificate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = g_tls_connection_emit_accept_certificate(GTlsConnection_val(self), GTlsCertificate_val(arg1), GioTlsCertificateFlags_val(arg2));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_tls_connection_get_base_io_stream(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GTlsConnection *obj = (GTlsConnection *)GTlsConnection_val(self);
    GIOStream *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "base-io-stream");
if (pspec == NULL) caml_failwith("ml_g_tls_connection_get_base_io_stream: property 'base-io-stream' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "base-io-stream", &prop_gvalue);
          prop_value = (GIOStream*)g_value_dup_object(&prop_gvalue);

      result = Val_GIOStream(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else


CAMLexport CAMLprim value ml_g_tls_connection_emit_accept_certificate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_connection_get_certificate(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_connection_get_ciphersuite_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_connection_get_database(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_connection_get_interaction(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_connection_get_negotiated_protocol(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_connection_get_peer_certificate(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_connection_get_peer_certificate_errors(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_connection_get_protocol_version(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_connection_get_rehandshake_mode(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_connection_get_require_close_notify(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_connection_get_use_system_certdb(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_connection_handshake(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_connection_handshake_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_connection_set_advertised_protocols(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_connection_set_certificate(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_connection_set_database(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_connection_set_interaction(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_connection_set_rehandshake_mode(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_connection_set_require_close_notify(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_connection_set_use_system_certdb(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_connection_get_base_io_stream(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsConnection requires GLib >= 2.28");
return Val_unit;
}


#endif
