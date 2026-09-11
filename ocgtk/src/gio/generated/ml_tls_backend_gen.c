/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TlsBackend */

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


CAMLexport CAMLprim value ml_g_tls_backend_supports_tls(value self)
{
CAMLparam1(self);

gboolean result = g_tls_backend_supports_tls(GTlsBackend_val(self));
CAMLreturn(Val_bool(result));
}

#if GLIB_CHECK_VERSION(2,48,0)

CAMLexport CAMLprim value ml_g_tls_backend_supports_dtls(value self)
{
CAMLparam1(self);

gboolean result = g_tls_backend_supports_dtls(GTlsBackend_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_tls_backend_supports_dtls(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsBackend requires GLib >= 2.48");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,60,0)

CAMLexport CAMLprim value ml_g_tls_backend_set_default_database(value self, value arg1)
{
CAMLparam2(self, arg1);

g_tls_backend_set_default_database(GTlsBackend_val(self), Option_val(arg1, GTlsDatabase_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_tls_backend_set_default_database(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsBackend requires GLib >= 2.60");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_tls_backend_get_server_connection_type(value self)
{
CAMLparam1(self);

GType result = g_tls_backend_get_server_connection_type(GTlsBackend_val(self));
CAMLreturn(Val_GType(result));
}

#if GLIB_CHECK_VERSION(2,30,0)

CAMLexport CAMLprim value ml_g_tls_backend_get_file_database_type(value self)
{
CAMLparam1(self);

GType result = g_tls_backend_get_file_database_type(GTlsBackend_val(self));
CAMLreturn(Val_GType(result));
}

#else

CAMLexport CAMLprim value ml_g_tls_backend_get_file_database_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsBackend requires GLib >= 2.30");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,48,0)

CAMLexport CAMLprim value ml_g_tls_backend_get_dtls_server_connection_type(value self)
{
CAMLparam1(self);

GType result = g_tls_backend_get_dtls_server_connection_type(GTlsBackend_val(self));
CAMLreturn(Val_GType(result));
}

#else

CAMLexport CAMLprim value ml_g_tls_backend_get_dtls_server_connection_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsBackend requires GLib >= 2.48");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,48,0)

CAMLexport CAMLprim value ml_g_tls_backend_get_dtls_client_connection_type(value self)
{
CAMLparam1(self);

GType result = g_tls_backend_get_dtls_client_connection_type(GTlsBackend_val(self));
CAMLreturn(Val_GType(result));
}

#else

CAMLexport CAMLprim value ml_g_tls_backend_get_dtls_client_connection_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsBackend requires GLib >= 2.48");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,30,0)

CAMLexport CAMLprim value ml_g_tls_backend_get_default_database(value self)
{
CAMLparam1(self);

GTlsDatabase* result = g_tls_backend_get_default_database(GTlsBackend_val(self));
CAMLreturn(Val_GTlsDatabase(result));
}

#else

CAMLexport CAMLprim value ml_g_tls_backend_get_default_database(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsBackend requires GLib >= 2.30");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_tls_backend_get_client_connection_type(value self)
{
CAMLparam1(self);

GType result = g_tls_backend_get_client_connection_type(GTlsBackend_val(self));
CAMLreturn(Val_GType(result));
}

CAMLexport CAMLprim value ml_g_tls_backend_get_certificate_type(value self)
{
CAMLparam1(self);

GType result = g_tls_backend_get_certificate_type(GTlsBackend_val(self));
CAMLreturn(Val_GType(result));
}
CAMLexport CAMLprim value ml_gio_tls_backend_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_TLS_BACKEND)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GTlsBackend");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GTlsBackend((GTlsBackend*)gobj));
}


CAMLprim value ml_gio_tls_backend_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_tls_backend_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_tls_backend_get_certificate_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsBackend requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_backend_get_client_connection_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsBackend requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_backend_get_default_database(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsBackend requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_backend_get_dtls_client_connection_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsBackend requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_backend_get_dtls_server_connection_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsBackend requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_backend_get_file_database_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsBackend requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_backend_get_server_connection_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsBackend requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_backend_set_default_database(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsBackend requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_backend_supports_dtls(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsBackend requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_backend_supports_tls(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsBackend requires GLib >= 2.28");
return Val_unit;
}

CAMLexport CAMLprim value ml_gio_tls_backend_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("TlsBackend requires GTK >= 2.28");
    return Val_unit;
}


#endif
