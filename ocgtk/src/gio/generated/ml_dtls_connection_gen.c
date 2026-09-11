/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DtlsConnection */

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

#if GLIB_CHECK_VERSION(2,48,0)


CAMLexport CAMLprim value ml_g_dtls_connection_shutdown_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_dtls_connection_shutdown_finish(GDtlsConnection_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_dtls_connection_shutdown(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GError *error = NULL;

gboolean result = g_dtls_connection_shutdown(GDtlsConnection_val(self), Bool_val(arg1), Bool_val(arg2), Option_val(arg3, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_dtls_connection_set_require_close_notify(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dtls_connection_set_require_close_notify(GDtlsConnection_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dtls_connection_set_rehandshake_mode(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dtls_connection_set_rehandshake_mode(GDtlsConnection_val(self), GioTlsRehandshakeMode_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dtls_connection_set_interaction(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dtls_connection_set_interaction(GDtlsConnection_val(self), Option_val(arg1, GTlsInteraction_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dtls_connection_set_database(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dtls_connection_set_database(GDtlsConnection_val(self), Option_val(arg1, GTlsDatabase_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dtls_connection_set_certificate(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dtls_connection_set_certificate(GDtlsConnection_val(self), GTlsCertificate_val(arg1));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,60,0)

CAMLexport CAMLprim value ml_g_dtls_connection_set_advertised_protocols(value self, value arg1)
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

g_dtls_connection_set_advertised_protocols(GDtlsConnection_val(self), c_arg1);
    if (c_arg1) g_free(c_arg1);
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_dtls_connection_set_advertised_protocols(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DtlsConnection requires GLib >= 2.60");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_dtls_connection_handshake_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_dtls_connection_handshake_finish(GDtlsConnection_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_dtls_connection_handshake(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_dtls_connection_handshake(GDtlsConnection_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_dtls_connection_get_require_close_notify(value self)
{
CAMLparam1(self);

gboolean result = g_dtls_connection_get_require_close_notify(GDtlsConnection_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_dtls_connection_get_rehandshake_mode(value self)
{
CAMLparam1(self);

GTlsRehandshakeMode result = g_dtls_connection_get_rehandshake_mode(GDtlsConnection_val(self));
CAMLreturn(Val_GioTlsRehandshakeMode(result));
}

#if GLIB_CHECK_VERSION(2,70,0)

CAMLexport CAMLprim value ml_g_dtls_connection_get_protocol_version(value self)
{
CAMLparam1(self);

GTlsProtocolVersion result = g_dtls_connection_get_protocol_version(GDtlsConnection_val(self));
CAMLreturn(Val_GioTlsProtocolVersion(result));
}

#else

CAMLexport CAMLprim value ml_g_dtls_connection_get_protocol_version(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DtlsConnection requires GLib >= 2.70");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_dtls_connection_get_peer_certificate_errors(value self)
{
CAMLparam1(self);

GTlsCertificateFlags result = g_dtls_connection_get_peer_certificate_errors(GDtlsConnection_val(self));
CAMLreturn(Val_GioTlsCertificateFlags(result));
}

CAMLexport CAMLprim value ml_g_dtls_connection_get_peer_certificate(value self)
{
CAMLparam1(self);

GTlsCertificate* result = g_dtls_connection_get_peer_certificate(GDtlsConnection_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GTlsCertificate));
}

#if GLIB_CHECK_VERSION(2,60,0)

CAMLexport CAMLprim value ml_g_dtls_connection_get_negotiated_protocol(value self)
{
CAMLparam1(self);

const gchar* result = g_dtls_connection_get_negotiated_protocol(GDtlsConnection_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_dtls_connection_get_negotiated_protocol(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DtlsConnection requires GLib >= 2.60");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_dtls_connection_get_interaction(value self)
{
CAMLparam1(self);

GTlsInteraction* result = g_dtls_connection_get_interaction(GDtlsConnection_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GTlsInteraction));
}

CAMLexport CAMLprim value ml_g_dtls_connection_get_database(value self)
{
CAMLparam1(self);

GTlsDatabase* result = g_dtls_connection_get_database(GDtlsConnection_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GTlsDatabase));
}

#if GLIB_CHECK_VERSION(2,70,0)

CAMLexport CAMLprim value ml_g_dtls_connection_get_ciphersuite_name(value self)
{
CAMLparam1(self);

gchar* result = g_dtls_connection_get_ciphersuite_name(GDtlsConnection_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_dtls_connection_get_ciphersuite_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DtlsConnection requires GLib >= 2.70");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_dtls_connection_get_certificate(value self)
{
CAMLparam1(self);

GTlsCertificate* result = g_dtls_connection_get_certificate(GDtlsConnection_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GTlsCertificate));
}

CAMLexport CAMLprim value ml_g_dtls_connection_emit_accept_certificate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = g_dtls_connection_emit_accept_certificate(GDtlsConnection_val(self), GTlsCertificate_val(arg1), GioTlsCertificateFlags_val(arg2));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_dtls_connection_close_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_dtls_connection_close_finish(GDtlsConnection_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_dtls_connection_close(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_dtls_connection_close(GDtlsConnection_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_dtls_connection_get_base_socket(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GDtlsConnection *obj = (GDtlsConnection *)GDtlsConnection_val(self);
    GDatagramBased *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "base-socket");
if (pspec == NULL) caml_failwith("ml_g_dtls_connection_get_base_socket: property 'base-socket' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "base-socket", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GDatagramBased(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}
CAMLexport CAMLprim value ml_gio_dtls_connection_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_DTLS_CONNECTION)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GDtlsConnection");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GDtlsConnection((GDtlsConnection*)gobj));
}

GType g_dtls_connection_get_type (void);


CAMLprim value ml_gio_dtls_connection_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_dtls_connection_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_dtls_connection_close(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_close_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_emit_accept_certificate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_get_certificate(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_get_ciphersuite_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_get_database(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_get_interaction(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_get_negotiated_protocol(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_get_peer_certificate(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_get_peer_certificate_errors(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_get_protocol_version(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_get_rehandshake_mode(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_get_require_close_notify(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_handshake(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_handshake_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_set_advertised_protocols(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_set_certificate(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_set_database(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_set_interaction(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_set_rehandshake_mode(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_set_require_close_notify(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_shutdown(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_shutdown_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_connection_get_base_socket(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DtlsConnection requires GLib >= 2.48");
return Val_unit;
}

CAMLexport CAMLprim value ml_gio_dtls_connection_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("DtlsConnection requires GTK >= 2.48");
    return Val_unit;
}


#endif
