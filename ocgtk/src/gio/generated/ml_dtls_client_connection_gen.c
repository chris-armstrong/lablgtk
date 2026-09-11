/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DtlsClientConnection */

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


CAMLexport CAMLprim value ml_g_dtls_client_connection_set_validation_flags(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dtls_client_connection_set_validation_flags(GDtlsClientConnection_val(self), GioTlsCertificateFlags_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dtls_client_connection_set_server_identity(value self, value arg1)
{
CAMLparam2(self, arg1);

g_dtls_client_connection_set_server_identity(GDtlsClientConnection_val(self), GSocketConnectable_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_dtls_client_connection_get_validation_flags(value self)
{
CAMLparam1(self);

GTlsCertificateFlags result = g_dtls_client_connection_get_validation_flags(GDtlsClientConnection_val(self));
CAMLreturn(Val_GioTlsCertificateFlags(result));
}

CAMLexport CAMLprim value ml_g_dtls_client_connection_get_server_identity(value self)
{
CAMLparam1(self);

GSocketConnectable* result = g_dtls_client_connection_get_server_identity(GDtlsClientConnection_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GSocketConnectable(result));
}
CAMLexport CAMLprim value ml_gio_dtls_client_connection_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_DTLS_CLIENT_CONNECTION)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GDtlsClientConnection");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GDtlsClientConnection((GDtlsClientConnection*)gobj));
}

GType g_dtls_client_connection_get_type (void);


CAMLprim value ml_gio_dtls_client_connection_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_dtls_client_connection_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_dtls_client_connection_get_server_identity(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DtlsClientConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_client_connection_get_validation_flags(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DtlsClientConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_client_connection_set_server_identity(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DtlsClientConnection requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dtls_client_connection_set_validation_flags(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DtlsClientConnection requires GLib >= 2.48");
return Val_unit;
}

CAMLexport CAMLprim value ml_gio_dtls_client_connection_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("DtlsClientConnection requires GTK >= 2.48");
    return Val_unit;
}


#endif
