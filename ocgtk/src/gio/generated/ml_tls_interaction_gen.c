/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TlsInteraction */

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


#if GLIB_CHECK_VERSION(2,40,0)

CAMLexport CAMLprim value ml_g_tls_interaction_request_certificate_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GTlsInteractionResult result = g_tls_interaction_request_certificate_finish(GTlsInteraction_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GioTlsInteractionResult(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_tls_interaction_request_certificate_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsInteraction requires GLib >= 2.40");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,40,0)

CAMLexport CAMLprim value ml_g_tls_interaction_request_certificate(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GError *error = NULL;

GTlsInteractionResult result = g_tls_interaction_request_certificate(GTlsInteraction_val(self), GTlsConnection_val(arg1), GioTlsCertificateRequestFlags_val(arg2), Option_val(arg3, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GioTlsInteractionResult(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_tls_interaction_request_certificate(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("TlsInteraction requires GLib >= 2.40");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,40,0)

CAMLexport CAMLprim value ml_g_tls_interaction_invoke_request_certificate(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GError *error = NULL;

GTlsInteractionResult result = g_tls_interaction_invoke_request_certificate(GTlsInteraction_val(self), GTlsConnection_val(arg1), GioTlsCertificateRequestFlags_val(arg2), Option_val(arg3, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GioTlsInteractionResult(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_tls_interaction_invoke_request_certificate(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("TlsInteraction requires GLib >= 2.40");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_tls_interaction_invoke_ask_password(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

GTlsInteractionResult result = g_tls_interaction_invoke_ask_password(GTlsInteraction_val(self), GTlsPassword_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GioTlsInteractionResult(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_tls_interaction_ask_password_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GTlsInteractionResult result = g_tls_interaction_ask_password_finish(GTlsInteraction_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GioTlsInteractionResult(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_tls_interaction_ask_password(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

GTlsInteractionResult result = g_tls_interaction_ask_password(GTlsInteraction_val(self), GTlsPassword_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GioTlsInteractionResult(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

GType g_tls_interaction_get_type (void);


CAMLprim value ml_gio_tls_interaction_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_tls_interaction_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_tls_interaction_ask_password(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("TlsInteraction requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_interaction_ask_password_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsInteraction requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_interaction_invoke_ask_password(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("TlsInteraction requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_interaction_invoke_request_certificate(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("TlsInteraction requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_interaction_request_certificate(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("TlsInteraction requires GLib >= 2.30");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_tls_interaction_request_certificate_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TlsInteraction requires GLib >= 2.30");
return Val_unit;
}


#endif
