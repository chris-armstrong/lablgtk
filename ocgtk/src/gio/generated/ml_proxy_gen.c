/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Proxy */

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


CAMLexport CAMLprim value ml_g_proxy_supports_hostname(value self)
{
CAMLparam1(self);

gboolean result = g_proxy_supports_hostname(GProxy_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_proxy_connect_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GIOStream* result = g_proxy_connect_finish(GProxy_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GIOStream(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_proxy_connect(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GError *error = NULL;

GIOStream* result = g_proxy_connect(GProxy_val(self), GIOStream_val(arg1), GProxyAddress_val(arg2), Option_val(arg3, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GIOStream(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_gio_proxy_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_PROXY)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GProxy");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GProxy((GProxy*)gobj));
}

GType g_proxy_get_type (void);


CAMLprim value ml_gio_proxy_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_proxy_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_proxy_connect(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Proxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_proxy_connect_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Proxy requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_proxy_supports_hostname(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Proxy requires GLib >= 2.26");
return Val_unit;
}

CAMLexport CAMLprim value ml_gio_proxy_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("Proxy requires GTK >= 2.26");
    return Val_unit;
}


#endif
