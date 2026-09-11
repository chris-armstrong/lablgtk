/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ProxyAddressEnumerator */

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


CAMLexport CAMLprim value ml_g_proxy_address_enumerator_get_connectable(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GProxyAddressEnumerator *obj = (GProxyAddressEnumerator *)GProxyAddressEnumerator_val(self);
    GSocketConnectable *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "connectable");
if (pspec == NULL) caml_failwith("ml_g_proxy_address_enumerator_get_connectable: property 'connectable' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "connectable", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GSocketConnectable(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#if GLIB_CHECK_VERSION(2,38,0)

CAMLexport CAMLprim value ml_g_proxy_address_enumerator_get_default_port(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GProxyAddressEnumerator *obj = (GProxyAddressEnumerator *)GProxyAddressEnumerator_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "default-port");
if (pspec == NULL) caml_failwith("ml_g_proxy_address_enumerator_get_default_port: property 'default-port' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "default-port", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_g_proxy_address_enumerator_get_default_port(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ProxyAddressEnumerator requires GLib >= 2.38");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,36,0)

CAMLexport CAMLprim value ml_g_proxy_address_enumerator_get_proxy_resolver(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GProxyAddressEnumerator *obj = (GProxyAddressEnumerator *)GProxyAddressEnumerator_val(self);
    GProxyResolver *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "proxy-resolver");
if (pspec == NULL) caml_failwith("ml_g_proxy_address_enumerator_get_proxy_resolver: property 'proxy-resolver' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "proxy-resolver", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GProxyResolver(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_g_proxy_address_enumerator_get_proxy_resolver(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ProxyAddressEnumerator requires GLib >= 2.36");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,36,0)

CAMLexport CAMLprim value ml_g_proxy_address_enumerator_set_proxy_resolver(value self, value new_value)
{
    CAMLparam2(self, new_value);
GProxyAddressEnumerator *obj = (GProxyAddressEnumerator *)GProxyAddressEnumerator_val(self);
    GProxyResolver *c_value = GProxyResolver_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "proxy-resolver");
if (pspec == NULL) caml_failwith("ml_g_proxy_address_enumerator_set_proxy_resolver: property 'proxy-resolver' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          caml_failwith("unsupported property type");
g_object_set_property(G_OBJECT(obj), "proxy-resolver", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_proxy_address_enumerator_set_proxy_resolver(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ProxyAddressEnumerator requires GLib >= 2.36");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_proxy_address_enumerator_get_uri(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GProxyAddressEnumerator *obj = (GProxyAddressEnumerator *)GProxyAddressEnumerator_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "uri");
if (pspec == NULL) caml_failwith("ml_g_proxy_address_enumerator_get_uri: property 'uri' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "uri", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

GType g_proxy_address_enumerator_get_type (void);


CAMLprim value ml_gio_proxy_address_enumerator_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_proxy_address_enumerator_get_type()));
}
