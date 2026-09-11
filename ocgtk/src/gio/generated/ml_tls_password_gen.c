/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TlsPassword */

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

#if GLIB_CHECK_VERSION(2,30,0)


CAMLexport CAMLprim value ml_g_tls_password_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GTlsPassword *obj = g_tls_password_new(GioTlsPasswordFlags_val(arg1), String_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GTlsPassword(obj));
}
CAMLexport CAMLprim value ml_g_tls_password_set_warning(value self, value arg1)
{
CAMLparam2(self, arg1);

g_tls_password_set_warning(GTlsPassword_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_tls_password_set_flags(value self, value arg1)
{
CAMLparam2(self, arg1);

g_tls_password_set_flags(GTlsPassword_val(self), GioTlsPasswordFlags_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_tls_password_set_description(value self, value arg1)
{
CAMLparam2(self, arg1);

g_tls_password_set_description(GTlsPassword_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_tls_password_get_warning(value self)
{
CAMLparam1(self);

const gchar* result = g_tls_password_get_warning(GTlsPassword_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_g_tls_password_get_flags(value self)
{
CAMLparam1(self);

GTlsPasswordFlags result = g_tls_password_get_flags(GTlsPassword_val(self));
CAMLreturn(Val_GioTlsPasswordFlags(result));
}

CAMLexport CAMLprim value ml_g_tls_password_get_description(value self)
{
CAMLparam1(self);

const gchar* result = g_tls_password_get_description(GTlsPassword_val(self));
CAMLreturn(caml_copy_string(result));
}

GType g_tls_password_get_type (void);


CAMLprim value ml_gio_tls_password_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_tls_password_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_tls_password_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("TlsPassword requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_password_get_description(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsPassword requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_password_get_flags(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsPassword requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_password_get_warning(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TlsPassword requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_password_set_description(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsPassword requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_password_set_flags(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsPassword requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_password_set_warning(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsPassword requires GLib >= 2.30");
return Val_unit;
}


#endif
