/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SocketControlMessage */

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


CAMLexport CAMLprim value ml_g_socket_control_message_get_size(value self)
{
CAMLparam1(self);

gsize result = g_socket_control_message_get_size(GSocketControlMessage_val(self));
CAMLreturn(Val_gsize(result));
}

CAMLexport CAMLprim value ml_g_socket_control_message_get_msg_type(value self)
{
CAMLparam1(self);

int result = g_socket_control_message_get_msg_type(GSocketControlMessage_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_g_socket_control_message_get_level(value self)
{
CAMLparam1(self);

int result = g_socket_control_message_get_level(GSocketControlMessage_val(self));
CAMLreturn(Val_int(result));
}

GType g_socket_control_message_get_type (void);


CAMLprim value ml_gio_socket_control_message_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_socket_control_message_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_socket_control_message_get_level(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketControlMessage requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_control_message_get_msg_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketControlMessage requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_control_message_get_size(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SocketControlMessage requires GLib >= 2.22");
return Val_unit;
}


#endif
