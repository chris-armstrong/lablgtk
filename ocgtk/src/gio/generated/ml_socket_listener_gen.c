/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SocketListener */

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

#if GLIB_CHECK_VERSION(2,22,0)


CAMLexport CAMLprim value ml_g_socket_listener_new(value unit)
{
CAMLparam1(unit);

GSocketListener *obj = g_socket_listener_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GSocketListener(obj));
}
CAMLexport CAMLprim value ml_g_socket_listener_set_backlog(value self, value arg1)
{
CAMLparam2(self, arg1);

g_socket_listener_set_backlog(GSocketListener_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_socket_listener_close(value self)
{
CAMLparam1(self);

g_socket_listener_close(GSocketListener_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_socket_listener_add_socket(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gboolean result = g_socket_listener_add_socket(GSocketListener_val(self), GSocket_val(arg1), Option_val(arg2, GObject_ext_of_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_socket_listener_add_inet_port(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gboolean result = g_socket_listener_add_inet_port(GSocketListener_val(self), UInt16_val(arg1), Option_val(arg2, GObject_ext_of_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if GLIB_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_g_socket_listener_add_any_inet_port(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

guint16 result = g_socket_listener_add_any_inet_port(GSocketListener_val(self), Option_val(arg1, GObject_ext_of_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_uint16(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_socket_listener_add_any_inet_port(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketListener requires GLib >= 2.24");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_socket_listener_get_listen_backlog(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GSocketListener *obj = (GSocketListener *)GSocketListener_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "listen-backlog");
if (pspec == NULL) caml_failwith("ml_g_socket_listener_get_listen_backlog: property 'listen-backlog' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "listen-backlog", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_g_socket_listener_set_listen_backlog(value self, value new_value)
{
    CAMLparam2(self, new_value);
GSocketListener *obj = (GSocketListener *)GSocketListener_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "listen-backlog");
if (pspec == NULL) caml_failwith("ml_g_socket_listener_set_listen_backlog: property 'listen-backlog' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "listen-backlog", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

GType g_socket_listener_get_type (void);


CAMLprim value ml_gio_socket_listener_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_socket_listener_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_socket_listener_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("SocketListener requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_listener_add_any_inet_port(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketListener requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_listener_add_inet_port(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("SocketListener requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_listener_add_socket(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("SocketListener requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_listener_close(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketListener requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_listener_set_backlog(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketListener requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_listener_get_listen_backlog(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketListener requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_listener_set_listen_backlog(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketListener requires GLib >= 2.22");
return Val_unit;
}


#endif
