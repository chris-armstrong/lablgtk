/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SocketAddressEnumerator */

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


CAMLexport CAMLprim value ml_g_socket_address_enumerator_next_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GSocketAddress* result = g_socket_address_enumerator_next_finish(GSocketAddressEnumerator_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_option(result, Val_GSocketAddress))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_socket_address_enumerator_next(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GSocketAddress* result = g_socket_address_enumerator_next(GSocketAddressEnumerator_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_option(result, Val_GSocketAddress))); else CAMLreturn(Res_Error(Val_GError(error)));
}

GType g_socket_address_enumerator_get_type (void);


CAMLprim value ml_gio_socket_address_enumerator_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_socket_address_enumerator_get_type()));
}
