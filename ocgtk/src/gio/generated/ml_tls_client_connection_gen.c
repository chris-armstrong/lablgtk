/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TlsClientConnection */

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


CAMLexport CAMLprim value ml_g_tls_client_connection_set_validation_flags(value self, value arg1)
{
CAMLparam2(self, arg1);

g_tls_client_connection_set_validation_flags(GTlsClientConnection_val(self), GioTlsCertificateFlags_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_tls_client_connection_set_use_ssl3(value self, value arg1)
{
CAMLparam2(self, arg1);

g_tls_client_connection_set_use_ssl3(GTlsClientConnection_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_tls_client_connection_set_server_identity(value self, value arg1)
{
CAMLparam2(self, arg1);

g_tls_client_connection_set_server_identity(GTlsClientConnection_val(self), GSocketConnectable_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_tls_client_connection_get_validation_flags(value self)
{
CAMLparam1(self);

GTlsCertificateFlags result = g_tls_client_connection_get_validation_flags(GTlsClientConnection_val(self));
CAMLreturn(Val_GioTlsCertificateFlags(result));
}

CAMLexport CAMLprim value ml_g_tls_client_connection_get_use_ssl3(value self)
{
CAMLparam1(self);

gboolean result = g_tls_client_connection_get_use_ssl3(GTlsClientConnection_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_tls_client_connection_get_server_identity(value self)
{
CAMLparam1(self);

GSocketConnectable* result = g_tls_client_connection_get_server_identity(GTlsClientConnection_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GSocketConnectable));
}

#if GLIB_CHECK_VERSION(2,46,0)

CAMLexport CAMLprim value ml_g_tls_client_connection_copy_session_state(value self, value arg1)
{
CAMLparam2(self, arg1);

g_tls_client_connection_copy_session_state(GTlsClientConnection_val(self), GTlsClientConnection_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_tls_client_connection_copy_session_state(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsClientConnection requires GLib >= 2.46");
return Val_unit;
}
#endif
CAMLexport CAMLprim value ml_gio_tls_client_connection_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_TLS_CLIENT_CONNECTION)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GTlsClientConnection");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GTlsClientConnection((GTlsClientConnection*)gobj));
}

GType g_tls_client_connection_get_type (void);


CAMLprim value ml_gio_tls_client_connection_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_tls_client_connection_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_tls_client_connection_copy_session_state(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsClientConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_client_connection_get_server_identity(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsClientConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_client_connection_get_use_ssl3(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsClientConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_client_connection_get_validation_flags(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsClientConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_client_connection_set_server_identity(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsClientConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_client_connection_set_use_ssl3(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsClientConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_client_connection_set_validation_flags(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsClientConnection requires GLib >= 2.28");
return Val_unit;
}

CAMLexport CAMLprim value ml_gio_tls_client_connection_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("TlsClientConnection requires GTK >= 2.28");
    return Val_unit;
}


#endif
