/* GENERATED CODE - DO NOT EDIT */
/* C bindings for UnixCredentialsMessage */

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
#if GLIB_CHECK_VERSION(2,26,0)


CAMLexport CAMLprim value ml_g_unix_credentials_message_new(value unit)
{
CAMLparam1(unit);

GUnixCredentialsMessage *obj = g_unix_credentials_message_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GUnixCredentialsMessage(obj));
}
CAMLexport CAMLprim value ml_g_unix_credentials_message_new_with_credentials(value arg1)
{
CAMLparam1(arg1);

GUnixCredentialsMessage *obj = g_unix_credentials_message_new_with_credentials(GCredentials_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GUnixCredentialsMessage(obj));
}
CAMLexport CAMLprim value ml_g_unix_credentials_message_get_credentials(value self)
{
CAMLparam1(self);

GCredentials* result = g_unix_credentials_message_get_credentials(GUnixCredentialsMessage_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GCredentials(result));
}

GType g_unix_credentials_message_get_type (void);


CAMLprim value ml_gio_unix_credentials_message_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_unix_credentials_message_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_unix_credentials_message_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("UnixCredentialsMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_unix_credentials_message_new_with_credentials(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("UnixCredentialsMessage requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_unix_credentials_message_get_credentials(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("UnixCredentialsMessage requires GLib >= 2.26");
return Val_unit;
}


#endif

#else


CAMLexport CAMLprim value ml_g_unix_credentials_message_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("UnixCredentialsMessage is only available on non-windows");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_unix_credentials_message_new_with_credentials(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("UnixCredentialsMessage is only available on non-windows");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_unix_credentials_message_get_credentials(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("UnixCredentialsMessage is only available on non-windows");
return Val_unit;
}


#endif /* not windows */
