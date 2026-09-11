/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SocketConnection */

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


#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_socket_connection_is_connected(value self)
{
CAMLparam1(self);

gboolean result = g_socket_connection_is_connected(GSocketConnection_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_socket_connection_is_connected(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketConnection requires GLib >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_socket_connection_get_socket(value self)
{
CAMLparam1(self);

GSocket* result = g_socket_connection_get_socket(GSocketConnection_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GSocket(result));
}

CAMLexport CAMLprim value ml_g_socket_connection_get_remote_address(value self)
{
CAMLparam1(self);
GError *error = NULL;

GSocketAddress* result = g_socket_connection_get_remote_address(GSocketConnection_val(self), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GSocketAddress(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_socket_connection_get_local_address(value self)
{
CAMLparam1(self);
GError *error = NULL;

GSocketAddress* result = g_socket_connection_get_local_address(GSocketConnection_val(self), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GSocketAddress(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_socket_connection_connect_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_socket_connection_connect_finish(GSocketConnection_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_socket_connection_connect_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketConnection requires GLib >= 2.32");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_socket_connection_connect(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gboolean result = g_socket_connection_connect(GSocketConnection_val(self), GSocketAddress_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_socket_connection_connect(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("SocketConnection requires GLib >= 2.32");
return Val_unit;
}
#endif


CAMLprim value ml_gio_socket_connection_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_socket_connection_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_socket_connection_connect(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("SocketConnection requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_connection_connect_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SocketConnection requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_connection_get_local_address(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketConnection requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_connection_get_remote_address(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketConnection requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_connection_get_socket(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketConnection requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_connection_is_connected(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketConnection requires GLib >= 2.22");
return Val_unit;
}


#endif
