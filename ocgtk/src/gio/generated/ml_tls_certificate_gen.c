/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TlsCertificate */

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


CAMLexport CAMLprim value ml_g_tls_certificate_new_from_file(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GTlsCertificate *obj = g_tls_certificate_new_from_file(String_val(arg1), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GTlsCertificate(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#if GLIB_CHECK_VERSION(2,72,0)

CAMLexport CAMLprim value ml_g_tls_certificate_new_from_file_with_password(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
GError *error = NULL;
    
GTlsCertificate *obj = g_tls_certificate_new_from_file_with_password(String_val(arg1), String_val(arg2), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GTlsCertificate(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#else

CAMLexport CAMLprim value ml_g_tls_certificate_new_from_file_with_password(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("TlsCertificate requires GLib >= 2.72");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_tls_certificate_new_from_files(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
GError *error = NULL;
    
GTlsCertificate *obj = g_tls_certificate_new_from_files(String_val(arg1), String_val(arg2), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GTlsCertificate(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_g_tls_certificate_new_from_pem(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
GError *error = NULL;
    
GTlsCertificate *obj = g_tls_certificate_new_from_pem(String_val(arg1), Long_val(arg2), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GTlsCertificate(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#if GLIB_CHECK_VERSION(2,68,0)

CAMLexport CAMLprim value ml_g_tls_certificate_new_from_pkcs11_uris(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
GError *error = NULL;
    
GTlsCertificate *obj = g_tls_certificate_new_from_pkcs11_uris(String_val(arg1), String_option_val(arg2), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GTlsCertificate(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#else

CAMLexport CAMLprim value ml_g_tls_certificate_new_from_pkcs11_uris(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("TlsCertificate requires GLib >= 2.68");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_tls_certificate_verify(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

GTlsCertificateFlags result = g_tls_certificate_verify(GTlsCertificate_val(self), Option_val(arg1, GSocketConnectable_val, NULL), Option_val(arg2, GTlsCertificate_val, NULL));
CAMLreturn(Val_GioTlsCertificateFlags(result));
}

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_tls_certificate_is_same(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_tls_certificate_is_same(GTlsCertificate_val(self), GTlsCertificate_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_tls_certificate_is_same(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsCertificate requires GLib >= 2.34");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,70,0)

CAMLexport CAMLprim value ml_g_tls_certificate_get_subject_name(value self)
{
CAMLparam1(self);

gchar* result = g_tls_certificate_get_subject_name(GTlsCertificate_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_tls_certificate_get_subject_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsCertificate requires GLib >= 2.70");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,70,0)

CAMLexport CAMLprim value ml_g_tls_certificate_get_issuer_name(value self)
{
CAMLparam1(self);

gchar* result = g_tls_certificate_get_issuer_name(GTlsCertificate_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_tls_certificate_get_issuer_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsCertificate requires GLib >= 2.70");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_tls_certificate_get_issuer(value self)
{
CAMLparam1(self);

GTlsCertificate* result = g_tls_certificate_get_issuer(GTlsCertificate_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GTlsCertificate));
}

CAMLexport CAMLprim value ml_g_tls_certificate_get_certificate_pem(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GTlsCertificate *obj = (GTlsCertificate *)GTlsCertificate_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "certificate-pem");
if (pspec == NULL) caml_failwith("ml_g_tls_certificate_get_certificate_pem: property 'certificate-pem' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "certificate-pem", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#if GLIB_CHECK_VERSION(2,68,0)

CAMLexport CAMLprim value ml_g_tls_certificate_get_pkcs11_uri(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GTlsCertificate *obj = (GTlsCertificate *)GTlsCertificate_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pkcs11-uri");
if (pspec == NULL) caml_failwith("ml_g_tls_certificate_get_pkcs11_uri: property 'pkcs11-uri' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "pkcs11-uri", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_g_tls_certificate_get_pkcs11_uri(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsCertificate requires GLib >= 2.68");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_tls_certificate_get_private_key_pem(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GTlsCertificate *obj = (GTlsCertificate *)GTlsCertificate_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "private-key-pem");
if (pspec == NULL) caml_failwith("ml_g_tls_certificate_get_private_key_pem: property 'private-key-pem' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "private-key-pem", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#if GLIB_CHECK_VERSION(2,68,0)

CAMLexport CAMLprim value ml_g_tls_certificate_get_private_key_pkcs11_uri(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GTlsCertificate *obj = (GTlsCertificate *)GTlsCertificate_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "private-key-pkcs11-uri");
if (pspec == NULL) caml_failwith("ml_g_tls_certificate_get_private_key_pkcs11_uri: property 'private-key-pkcs11-uri' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "private-key-pkcs11-uri", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_g_tls_certificate_get_private_key_pkcs11_uri(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsCertificate requires GLib >= 2.68");
return Val_unit;
}
#endif


CAMLprim value ml_gio_tls_certificate_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_tls_certificate_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_tls_certificate_new_from_file(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("TlsCertificate requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_certificate_new_from_file_with_password(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("TlsCertificate requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_certificate_new_from_files(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("TlsCertificate requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_certificate_new_from_pem(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("TlsCertificate requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_certificate_new_from_pkcs11_uris(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("TlsCertificate requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_certificate_get_issuer(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsCertificate requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_certificate_get_issuer_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsCertificate requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_certificate_get_subject_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsCertificate requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_certificate_is_same(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsCertificate requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_certificate_verify(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("TlsCertificate requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_certificate_get_certificate_pem(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsCertificate requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_certificate_get_pkcs11_uri(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsCertificate requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_certificate_get_private_key_pem(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsCertificate requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_certificate_get_private_key_pkcs11_uri(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsCertificate requires GLib >= 2.28");
return Val_unit;
}


#endif
