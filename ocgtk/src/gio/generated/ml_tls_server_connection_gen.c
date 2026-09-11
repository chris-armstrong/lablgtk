/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TlsServerConnection */

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


CAMLexport CAMLprim value ml_g_tls_server_connection_get_authentication_mode(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GTlsServerConnection *obj = (GTlsServerConnection *)GTlsServerConnection_val(self);
    GTlsAuthenticationMode prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "authentication-mode");
if (pspec == NULL) caml_failwith("ml_g_tls_server_connection_get_authentication_mode: property 'authentication-mode' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "authentication-mode", &prop_gvalue);
          prop_value = (GTlsAuthenticationMode)g_value_get_enum(&prop_gvalue);

      result = Val_GioTlsAuthenticationMode(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_g_tls_server_connection_set_authentication_mode(value self, value new_value)
{
    CAMLparam2(self, new_value);
GTlsServerConnection *obj = (GTlsServerConnection *)GTlsServerConnection_val(self);
    GTlsAuthenticationMode c_value = GioTlsAuthenticationMode_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "authentication-mode");
if (pspec == NULL) caml_failwith("ml_g_tls_server_connection_set_authentication_mode: property 'authentication-mode' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "authentication-mode", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}
CAMLexport CAMLprim value ml_gio_tls_server_connection_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_TLS_SERVER_CONNECTION)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GTlsServerConnection");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GTlsServerConnection((GTlsServerConnection*)gobj));
}

GType g_tls_server_connection_get_type (void);


CAMLprim value ml_gio_tls_server_connection_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_tls_server_connection_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_tls_server_connection_get_authentication_mode(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsServerConnection requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_server_connection_set_authentication_mode(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsServerConnection requires GLib >= 2.28");
return Val_unit;
}

CAMLexport CAMLprim value ml_gio_tls_server_connection_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("TlsServerConnection requires GTK >= 2.28");
    return Val_unit;
}


#endif
