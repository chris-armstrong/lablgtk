/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Credentials */

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


CAMLexport CAMLprim value ml_g_credentials_new(value unit)
{
CAMLparam1(unit);

GCredentials *obj = g_credentials_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GCredentials(obj));
}
CAMLexport CAMLprim value ml_g_credentials_to_string(value self)
{
CAMLparam1(self);

gchar* result = g_credentials_to_string(GCredentials_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_g_credentials_is_same_user(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_credentials_is_same_user(GCredentials_val(self), GCredentials_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}


CAMLprim value ml_gio_credentials_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_credentials_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_credentials_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("Credentials requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_credentials_is_same_user(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Credentials requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_credentials_to_string(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Credentials requires GLib >= 2.26");
return Val_unit;
}


#endif
