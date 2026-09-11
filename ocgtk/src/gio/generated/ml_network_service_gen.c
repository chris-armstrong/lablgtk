/* GENERATED CODE - DO NOT EDIT */
/* C bindings for NetworkService */

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

CAMLexport CAMLprim value ml_g_network_service_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GNetworkService *obj = g_network_service_new(String_val(arg1), String_val(arg2), String_val(arg3));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GNetworkService(obj));
}
#else

CAMLexport CAMLprim value ml_g_network_service_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("NetworkService requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_network_service_set_scheme(value self, value arg1)
{
CAMLparam2(self, arg1);

g_network_service_set_scheme(GNetworkService_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_network_service_set_scheme(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("NetworkService requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_network_service_get_service(value self)
{
CAMLparam1(self);

const gchar* result = g_network_service_get_service(GNetworkService_val(self));
CAMLreturn(caml_copy_string(result));
}

#else

CAMLexport CAMLprim value ml_g_network_service_get_service(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("NetworkService requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_network_service_get_scheme(value self)
{
CAMLparam1(self);

const gchar* result = g_network_service_get_scheme(GNetworkService_val(self));
CAMLreturn(caml_copy_string(result));
}

#else

CAMLexport CAMLprim value ml_g_network_service_get_scheme(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("NetworkService requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_network_service_get_protocol(value self)
{
CAMLparam1(self);

const gchar* result = g_network_service_get_protocol(GNetworkService_val(self));
CAMLreturn(caml_copy_string(result));
}

#else

CAMLexport CAMLprim value ml_g_network_service_get_protocol(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("NetworkService requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_network_service_get_domain(value self)
{
CAMLparam1(self);

const gchar* result = g_network_service_get_domain(GNetworkService_val(self));
CAMLreturn(caml_copy_string(result));
}

#else

CAMLexport CAMLprim value ml_g_network_service_get_domain(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("NetworkService requires GLib >= 2.22");
return Val_unit;
}
#endif

GType g_network_service_get_type (void);


CAMLprim value ml_gio_network_service_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_network_service_get_type()));
}
