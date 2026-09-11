/* GENERATED CODE - DO NOT EDIT */
/* C bindings for UnixConnection */

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


#if !(defined(_WIN32))
#if GLIB_CHECK_VERSION(2,22,0)


CAMLexport CAMLprim value ml_g_unix_connection_send_fd(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gboolean result = g_unix_connection_send_fd(GUnixConnection_val(self), Int_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_unix_connection_send_credentials_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_unix_connection_send_credentials_finish(GUnixConnection_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_unix_connection_send_credentials_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("UnixConnection requires GLib >= 2.32");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_unix_connection_send_credentials(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_unix_connection_send_credentials(GUnixConnection_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_unix_connection_send_credentials(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("UnixConnection requires GLib >= 2.26");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_unix_connection_receive_fd(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gint result = g_unix_connection_receive_fd(GUnixConnection_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_int(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_unix_connection_receive_credentials_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GCredentials* result = g_unix_connection_receive_credentials_finish(GUnixConnection_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GCredentials(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_unix_connection_receive_credentials_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("UnixConnection requires GLib >= 2.32");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_unix_connection_receive_credentials(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GCredentials* result = g_unix_connection_receive_credentials(GUnixConnection_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GCredentials(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_unix_connection_receive_credentials(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("UnixConnection requires GLib >= 2.26");
return Val_unit;
}
#endif

GType g_unix_connection_get_type (void);


CAMLprim value ml_gio_unix_connection_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_unix_connection_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_unix_connection_receive_credentials(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("UnixConnection requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_unix_connection_receive_credentials_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("UnixConnection requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_unix_connection_receive_fd(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("UnixConnection requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_unix_connection_send_credentials(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("UnixConnection requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_unix_connection_send_credentials_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("UnixConnection requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_unix_connection_send_fd(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("UnixConnection requires GLib >= 2.22");
return Val_unit;
}


#endif

#else


CAMLexport CAMLprim value ml_g_unix_connection_receive_credentials(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("UnixConnection is only available on non-windows");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_unix_connection_receive_credentials_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("UnixConnection is only available on non-windows");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_unix_connection_receive_fd(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("UnixConnection is only available on non-windows");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_unix_connection_send_credentials(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("UnixConnection is only available on non-windows");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_unix_connection_send_credentials_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("UnixConnection is only available on non-windows");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_unix_connection_send_fd(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("UnixConnection is only available on non-windows");
return Val_unit;
}


#endif /* not windows */
