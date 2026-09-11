/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Socket */

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


CAMLexport CAMLprim value ml_g_socket_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);
GError *error = NULL;
    
GSocket *obj = g_socket_new(GioSocketFamily_val(arg1), GioSocketType_val(arg2), GioSocketProtocol_val(arg3), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GSocket(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_g_socket_new_from_fd(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GSocket *obj = g_socket_new_from_fd(Int_val(arg1), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GSocket(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_g_socket_speaks_ipv4(value self)
{
CAMLparam1(self);

gboolean result = g_socket_speaks_ipv4(GSocket_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_socket_shutdown(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gboolean result = g_socket_shutdown(GSocket_val(self), Bool_val(arg1), Bool_val(arg2), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_socket_set_ttl(value self, value arg1)
{
CAMLparam2(self, arg1);

g_socket_set_ttl(GSocket_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_socket_set_ttl(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Socket requires GLib >= 2.32");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_socket_set_timeout(value self, value arg1)
{
CAMLparam2(self, arg1);

g_socket_set_timeout(GSocket_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_socket_set_timeout(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Socket requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,36,0)

CAMLexport CAMLprim value ml_g_socket_set_option(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GError *error = NULL;

gboolean result = g_socket_set_option(GSocket_val(self), Int_val(arg1), Int_val(arg2), Int_val(arg3), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_socket_set_option(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Socket requires GLib >= 2.36");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_socket_set_multicast_ttl(value self, value arg1)
{
CAMLparam2(self, arg1);

g_socket_set_multicast_ttl(GSocket_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_socket_set_multicast_ttl(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Socket requires GLib >= 2.32");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_socket_set_multicast_loopback(value self, value arg1)
{
CAMLparam2(self, arg1);

g_socket_set_multicast_loopback(GSocket_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_socket_set_multicast_loopback(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Socket requires GLib >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_socket_set_listen_backlog(value self, value arg1)
{
CAMLparam2(self, arg1);

g_socket_set_listen_backlog(GSocket_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_socket_set_keepalive(value self, value arg1)
{
CAMLparam2(self, arg1);

g_socket_set_keepalive(GSocket_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_socket_set_broadcast(value self, value arg1)
{
CAMLparam2(self, arg1);

g_socket_set_broadcast(GSocket_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_socket_set_broadcast(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Socket requires GLib >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_socket_set_blocking(value self, value arg1)
{
CAMLparam2(self, arg1);

g_socket_set_blocking(GSocket_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,44,0)

CAMLexport CAMLprim value ml_g_socket_send_messages(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
GError *error = NULL;
    int arg1_length = Wosize_val(arg1);
    GOutputMessage* c_arg1 = (GOutputMessage*)g_malloc(sizeof(GOutputMessage) * arg1_length);
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = *GOutputMessage_val(Field(arg1, i));
    }

gint result = g_socket_send_messages(GSocket_val(self), c_arg1, Int_val(arg2), Int_val(arg3), Option_val(arg4, GCancellable_val, NULL), &error);
    g_free(c_arg1);
if (error == NULL) CAMLreturn(Res_Ok(Val_int(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_socket_send_messages(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Socket requires GLib >= 2.44");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,60,0)

CAMLexport CAMLprim value ml_g_socket_send_message_with_timeout_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7, value arg8)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam4(arg5, arg6, arg7, arg8);
GError *error = NULL;
    int arg2_length = Wosize_val(arg2);
    GOutputVector* c_arg2 = (GOutputVector*)g_malloc(sizeof(GOutputVector) * arg2_length);
    for (int i = 0; i < arg2_length; i++) {
      c_arg2[i] = *GOutputVector_val(Field(arg2, i));
    }
    int arg4_length = 0;
    GSocketControlMessage** c_arg4 = NULL;
    
    if (Is_some(arg4)) {
        value array = Some_val(arg4);
        arg4_length = Wosize_val(array);
        c_arg4 = (GSocketControlMessage**)g_malloc(sizeof(GSocketControlMessage*) * arg4_length);
        for (int i = 0; i < arg4_length; i++) {
          c_arg4[i] = GSocketControlMessage_val(Field(array, i));
        }
    }
gsize out8;

GPollableReturn result = g_socket_send_message_with_timeout(GSocket_val(self), Option_val(arg1, GSocketAddress_val, NULL), c_arg2, Int_val(arg3), c_arg4, Int_val(arg5), Int_val(arg6), Int64_val(arg7), &out8, Option_val(arg8, GCancellable_val, NULL), &error);
    g_free(c_arg2);
    if (c_arg4) g_free(c_arg4);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_GioPollableReturn(result));
    Store_field(ret, 1, Val_gsize(out8));
    if (error == NULL) CAMLreturn(Res_Ok(ret)); else CAMLreturn(Res_Error(Val_GError(error)));}

CAMLexport CAMLprim value ml_g_socket_send_message_with_timeout_bytecode(value * argv, int argn)
{
return ml_g_socket_send_message_with_timeout_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8]);
}

#else

CAMLexport CAMLprim value ml_g_socket_send_message_with_timeout(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7, value arg8)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
(void)arg6;
(void)arg7;
(void)arg8;
caml_failwith("Socket requires GLib >= 2.60");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_socket_send_message_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam3(arg5, arg6, arg7);
GError *error = NULL;
    int arg2_length = Wosize_val(arg2);
    GOutputVector* c_arg2 = (GOutputVector*)g_malloc(sizeof(GOutputVector) * arg2_length);
    for (int i = 0; i < arg2_length; i++) {
      c_arg2[i] = *GOutputVector_val(Field(arg2, i));
    }
    int arg4_length = 0;
    GSocketControlMessage** c_arg4 = NULL;
    
    if (Is_some(arg4)) {
        value array = Some_val(arg4);
        arg4_length = Wosize_val(array);
        c_arg4 = (GSocketControlMessage**)g_malloc(sizeof(GSocketControlMessage*) * arg4_length);
        for (int i = 0; i < arg4_length; i++) {
          c_arg4[i] = GSocketControlMessage_val(Field(array, i));
        }
    }

gssize result = g_socket_send_message(GSocket_val(self), Option_val(arg1, GSocketAddress_val, NULL), c_arg2, Int_val(arg3), c_arg4, Int_val(arg5), Int_val(arg6), Option_val(arg7, GCancellable_val, NULL), &error);
    g_free(c_arg2);
    if (c_arg4) g_free(c_arg4);
if (error == NULL) CAMLreturn(Res_Ok(Val_long(result))); else CAMLreturn(Res_Error(Val_GError(error)));}

CAMLexport CAMLprim value ml_g_socket_send_message_bytecode(value * argv, int argn)
{
return ml_g_socket_send_message_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

#if GLIB_CHECK_VERSION(2,48,0)

CAMLexport CAMLprim value ml_g_socket_receive_messages(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
GError *error = NULL;
    int arg1_length = Wosize_val(arg1);
    GInputMessage* c_arg1 = (GInputMessage*)g_malloc(sizeof(GInputMessage) * arg1_length);
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = *GInputMessage_val(Field(arg1, i));
    }

gint result = g_socket_receive_messages(GSocket_val(self), c_arg1, Int_val(arg2), Int_val(arg3), Option_val(arg4, GCancellable_val, NULL), &error);
    g_free(c_arg1);
if (error == NULL) CAMLreturn(Res_Ok(Val_int(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_socket_receive_messages(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Socket requires GLib >= 2.48");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,80,0)

CAMLexport CAMLprim value ml_g_socket_receive_bytes(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GError *error = NULL;

GBytes* result = g_socket_receive_bytes(GSocket_val(self), Gsize_val(arg1), Int64_val(arg2), Option_val(arg3, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GBytes(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_socket_receive_bytes(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Socket requires GLib >= 2.80");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_socket_listen(value self)
{
CAMLparam1(self);
GError *error = NULL;

gboolean result = g_socket_listen(GSocket_val(self), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if GLIB_CHECK_VERSION(2,56,0)

CAMLexport CAMLprim value ml_g_socket_leave_multicast_group_ssm(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GError *error = NULL;

gboolean result = g_socket_leave_multicast_group_ssm(GSocket_val(self), GInetAddress_val(arg1), Option_val(arg2, GInetAddress_val, NULL), String_option_val(arg3), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_socket_leave_multicast_group_ssm(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Socket requires GLib >= 2.56");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_socket_leave_multicast_group(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GError *error = NULL;

gboolean result = g_socket_leave_multicast_group(GSocket_val(self), GInetAddress_val(arg1), Bool_val(arg2), String_option_val(arg3), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_socket_leave_multicast_group(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Socket requires GLib >= 2.32");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,56,0)

CAMLexport CAMLprim value ml_g_socket_join_multicast_group_ssm(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GError *error = NULL;

gboolean result = g_socket_join_multicast_group_ssm(GSocket_val(self), GInetAddress_val(arg1), Option_val(arg2, GInetAddress_val, NULL), String_option_val(arg3), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_socket_join_multicast_group_ssm(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Socket requires GLib >= 2.56");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_socket_join_multicast_group(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GError *error = NULL;

gboolean result = g_socket_join_multicast_group(GSocket_val(self), GInetAddress_val(arg1), Bool_val(arg2), String_option_val(arg3), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_socket_join_multicast_group(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Socket requires GLib >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_socket_is_connected(value self)
{
CAMLparam1(self);

gboolean result = g_socket_is_connected(GSocket_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_socket_is_closed(value self)
{
CAMLparam1(self);

gboolean result = g_socket_is_closed(GSocket_val(self));
CAMLreturn(Val_bool(result));
}

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_socket_get_ttl(value self)
{
CAMLparam1(self);

guint result = g_socket_get_ttl(GSocket_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_g_socket_get_ttl(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.32");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_socket_get_timeout(value self)
{
CAMLparam1(self);

guint result = g_socket_get_timeout(GSocket_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_g_socket_get_timeout(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.26");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_socket_get_socket_type(value self)
{
CAMLparam1(self);

GSocketType result = g_socket_get_socket_type(GSocket_val(self));
CAMLreturn(Val_GioSocketType(result));
}

CAMLexport CAMLprim value ml_g_socket_get_remote_address(value self)
{
CAMLparam1(self);
GError *error = NULL;

GSocketAddress* result = g_socket_get_remote_address(GSocket_val(self), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GSocketAddress(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_socket_get_protocol(value self)
{
CAMLparam1(self);

GSocketProtocol result = g_socket_get_protocol(GSocket_val(self));
CAMLreturn(Val_GioSocketProtocol(result));
}

#if GLIB_CHECK_VERSION(2,36,0)

CAMLexport CAMLprim value ml_g_socket_get_option(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;
gint out3;

gboolean result = g_socket_get_option(GSocket_val(self), Int_val(arg1), Int_val(arg2), &out3, &error);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_int(out3));
    if (error == NULL) CAMLreturn(Res_Ok(ret)); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_socket_get_option(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Socket requires GLib >= 2.36");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_socket_get_multicast_ttl(value self)
{
CAMLparam1(self);

guint result = g_socket_get_multicast_ttl(GSocket_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_g_socket_get_multicast_ttl(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.32");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_socket_get_multicast_loopback(value self)
{
CAMLparam1(self);

gboolean result = g_socket_get_multicast_loopback(GSocket_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_socket_get_multicast_loopback(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_socket_get_local_address(value self)
{
CAMLparam1(self);
GError *error = NULL;

GSocketAddress* result = g_socket_get_local_address(GSocket_val(self), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GSocketAddress(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_socket_get_listen_backlog(value self)
{
CAMLparam1(self);

gint result = g_socket_get_listen_backlog(GSocket_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_g_socket_get_keepalive(value self)
{
CAMLparam1(self);

gboolean result = g_socket_get_keepalive(GSocket_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_socket_get_fd(value self)
{
CAMLparam1(self);

int result = g_socket_get_fd(GSocket_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_g_socket_get_family(value self)
{
CAMLparam1(self);

GSocketFamily result = g_socket_get_family(GSocket_val(self));
CAMLreturn(Val_GioSocketFamily(result));
}

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_socket_get_credentials(value self)
{
CAMLparam1(self);
GError *error = NULL;

GCredentials* result = g_socket_get_credentials(GSocket_val(self), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GCredentials(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_socket_get_credentials(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_socket_get_broadcast(value self)
{
CAMLparam1(self);

gboolean result = g_socket_get_broadcast(GSocket_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_socket_get_broadcast(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_socket_get_blocking(value self)
{
CAMLparam1(self);

gboolean result = g_socket_get_blocking(GSocket_val(self));
CAMLreturn(Val_bool(result));
}

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_socket_get_available_bytes(value self)
{
CAMLparam1(self);

gssize result = g_socket_get_available_bytes(GSocket_val(self));
CAMLreturn(Val_long(result));
}

#else

CAMLexport CAMLprim value ml_g_socket_get_available_bytes(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_socket_connection_factory_create_connection(value self)
{
CAMLparam1(self);

GSocketConnection* result = g_socket_connection_factory_create_connection(GSocket_val(self));
CAMLreturn(Val_GSocketConnection(result));
}

CAMLexport CAMLprim value ml_g_socket_connect(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gboolean result = g_socket_connect(GSocket_val(self), GSocketAddress_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_socket_close(value self)
{
CAMLparam1(self);
GError *error = NULL;

gboolean result = g_socket_close(GSocket_val(self), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_socket_check_connect_result(value self)
{
CAMLparam1(self);
GError *error = NULL;

gboolean result = g_socket_check_connect_result(GSocket_val(self), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_socket_bind(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gboolean result = g_socket_bind(GSocket_val(self), GSocketAddress_val(arg1), Bool_val(arg2), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_socket_accept(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GSocket* result = g_socket_accept(GSocket_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GSocket(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_socket_get_type(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GSocket *obj = (GSocket *)GSocket_val(self);
    GSocketType prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "type");
if (pspec == NULL) caml_failwith("ml_g_socket_get_type: property 'type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "type", &prop_gvalue);
          prop_value = (GSocketType)g_value_get_enum(&prop_gvalue);

      result = Val_GioSocketType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

GType g_socket_get_type (void);


CAMLprim value ml_gio_socket_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_socket_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_socket_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_new_from_fd(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_accept(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_bind(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_check_connect_result(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_close(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_connect(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_connection_factory_create_connection(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_get_available_bytes(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_get_blocking(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_get_broadcast(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_get_credentials(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_get_family(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_get_fd(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_get_keepalive(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_get_listen_backlog(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_get_local_address(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_get_multicast_loopback(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_get_multicast_ttl(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_get_option(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_get_protocol(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_get_remote_address(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_get_socket_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_get_timeout(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_get_ttl(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_is_closed(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_is_connected(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_join_multicast_group(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_join_multicast_group_ssm(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_leave_multicast_group(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_leave_multicast_group_ssm(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_listen(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_receive_bytes(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_receive_messages(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_send_message(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
(void)arg6;
(void)arg7;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_send_message_with_timeout(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7, value arg8)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
(void)arg6;
(void)arg7;
(void)arg8;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_send_messages(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_set_blocking(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_set_broadcast(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_set_keepalive(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_set_listen_backlog(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_set_multicast_loopback(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_set_multicast_ttl(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_set_option(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_set_timeout(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_set_ttl(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_shutdown(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_speaks_ipv4(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_socket_get_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Socket requires GLib >= 2.22");
return Val_unit;
}


#endif
