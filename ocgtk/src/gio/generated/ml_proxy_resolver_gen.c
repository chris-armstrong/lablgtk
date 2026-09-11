/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ProxyResolver */

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


CAMLexport CAMLprim value ml_g_proxy_resolver_lookup_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gchar** result = g_proxy_resolver_lookup_finish(GProxyResolver_val(self), GAsyncResult_val(arg1), &error);
    int result_length = 0;
    while (result[result_length] != NULL) result_length++;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, caml_copy_string(result[i]));
    }
    for (int i = 0; i < result_length; i++) {
      g_free((gpointer)result[i]);
    }
    g_free(result);
if (error == NULL) CAMLreturn(Res_Ok(ml_result)); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_proxy_resolver_lookup(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gchar** result = g_proxy_resolver_lookup(GProxyResolver_val(self), String_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
    int result_length = 0;
    while (result[result_length] != NULL) result_length++;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, caml_copy_string(result[i]));
    }
    for (int i = 0; i < result_length; i++) {
      g_free((gpointer)result[i]);
    }
    g_free(result);
if (error == NULL) CAMLreturn(Res_Ok(ml_result)); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_proxy_resolver_is_supported(value self)
{
CAMLparam1(self);

gboolean result = g_proxy_resolver_is_supported(GProxyResolver_val(self));
CAMLreturn(Val_bool(result));
}
CAMLexport CAMLprim value ml_gio_proxy_resolver_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_PROXY_RESOLVER)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GProxyResolver");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GProxyResolver((GProxyResolver*)gobj));
}


CAMLprim value ml_gio_proxy_resolver_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_proxy_resolver_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_proxy_resolver_is_supported(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ProxyResolver requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_proxy_resolver_lookup(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("ProxyResolver requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_proxy_resolver_lookup_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ProxyResolver requires GLib >= 2.26");
return Val_unit;
}

CAMLexport CAMLprim value ml_gio_proxy_resolver_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("ProxyResolver requires GTK >= 2.26");
    return Val_unit;
}


#endif
