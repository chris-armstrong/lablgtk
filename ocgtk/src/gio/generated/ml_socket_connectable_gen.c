/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SocketConnectable */

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

CAMLexport CAMLprim value ml_g_socket_connectable_to_string(value self)
{
CAMLparam1(self);

gchar* result = g_socket_connectable_to_string(GSocketConnectable_val(self));
CAMLreturn(caml_copy_string(result));
}

#else

CAMLexport CAMLprim value ml_g_socket_connectable_to_string(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketConnectable requires GLib >= 2.48");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_socket_connectable_proxy_enumerate(value self)
{
CAMLparam1(self);

GSocketAddressEnumerator* result = g_socket_connectable_proxy_enumerate(GSocketConnectable_val(self));
CAMLreturn(Val_GSocketAddressEnumerator(result));
}

#else

CAMLexport CAMLprim value ml_g_socket_connectable_proxy_enumerate(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketConnectable requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_socket_connectable_enumerate(value self)
{
CAMLparam1(self);

GSocketAddressEnumerator* result = g_socket_connectable_enumerate(GSocketConnectable_val(self));
CAMLreturn(Val_GSocketAddressEnumerator(result));
}

#else

CAMLexport CAMLprim value ml_g_socket_connectable_enumerate(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketConnectable requires GLib >= 2.22");
return Val_unit;
}
#endif
CAMLexport CAMLprim value ml_gio_socket_connectable_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_SOCKET_CONNECTABLE)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GSocketConnectable");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GSocketConnectable((GSocketConnectable*)gobj));
}


CAMLprim value ml_gio_socket_connectable_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_socket_connectable_get_type()));
}
