/* GENERATED CODE - DO NOT EDIT */
/* C bindings for NetworkMonitor */

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

#if GLIB_CHECK_VERSION(2,32,0)


#if GLIB_CHECK_VERSION(2,46,0)

CAMLexport CAMLprim value ml_g_network_monitor_get_network_metered(value self)
{
CAMLparam1(self);

gboolean result = g_network_monitor_get_network_metered(GNetworkMonitor_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_network_monitor_get_network_metered(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("NetworkMonitor requires GLib >= 2.46");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_network_monitor_get_network_available(value self)
{
CAMLparam1(self);

gboolean result = g_network_monitor_get_network_available(GNetworkMonitor_val(self));
CAMLreturn(Val_bool(result));
}

#if GLIB_CHECK_VERSION(2,44,0)

CAMLexport CAMLprim value ml_g_network_monitor_get_connectivity(value self)
{
CAMLparam1(self);

GNetworkConnectivity result = g_network_monitor_get_connectivity(GNetworkMonitor_val(self));
CAMLreturn(Val_GioNetworkConnectivity(result));
}

#else

CAMLexport CAMLprim value ml_g_network_monitor_get_connectivity(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("NetworkMonitor requires GLib >= 2.44");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_network_monitor_can_reach_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_network_monitor_can_reach_finish(GNetworkMonitor_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_network_monitor_can_reach(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gboolean result = g_network_monitor_can_reach(GNetworkMonitor_val(self), GSocketConnectable_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_gio_network_monitor_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_NETWORK_MONITOR)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GNetworkMonitor");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GNetworkMonitor((GNetworkMonitor*)gobj));
}

GType g_network_monitor_get_type (void);


CAMLprim value ml_gio_network_monitor_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_network_monitor_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_network_monitor_can_reach(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("NetworkMonitor requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_network_monitor_can_reach_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("NetworkMonitor requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_network_monitor_get_connectivity(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("NetworkMonitor requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_network_monitor_get_network_available(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("NetworkMonitor requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_network_monitor_get_network_metered(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("NetworkMonitor requires GLib >= 2.32");
return Val_unit;
}

CAMLexport CAMLprim value ml_gio_network_monitor_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("NetworkMonitor requires GTK >= 2.32");
    return Val_unit;
}


#endif
