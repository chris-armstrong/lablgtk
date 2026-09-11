/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SocketService */

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


CAMLexport CAMLprim value ml_g_socket_service_new(value unit)
{
CAMLparam1(unit);

GSocketService *obj = g_socket_service_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GSocketService(obj));
}
CAMLexport CAMLprim value ml_g_socket_service_stop(value self)
{
CAMLparam1(self);

g_socket_service_stop(GSocketService_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_socket_service_start(value self)
{
CAMLparam1(self);

g_socket_service_start(GSocketService_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_socket_service_is_active(value self)
{
CAMLparam1(self);

gboolean result = g_socket_service_is_active(GSocketService_val(self));
CAMLreturn(Val_bool(result));
}

GType g_socket_service_get_type (void);


CAMLprim value ml_gio_socket_service_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_socket_service_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_socket_service_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("SocketService requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_service_is_active(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketService requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_service_start(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketService requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_service_stop(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketService requires GLib >= 2.22");
return Val_unit;
}


#endif
