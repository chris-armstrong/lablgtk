/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DatagramBased */

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

#if GLIB_CHECK_VERSION(2,48,0)


CAMLexport CAMLprim value ml_g_datagram_based_send_messages_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);
GError *error = NULL;
    int arg1_length = Wosize_val(arg1);
    GOutputMessage* c_arg1 = (GOutputMessage*)g_malloc(sizeof(GOutputMessage) * arg1_length);
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = *GOutputMessage_val(Field(arg1, i));
    }

gint result = g_datagram_based_send_messages(GDatagramBased_val(self), c_arg1, Int_val(arg2), Int_val(arg3), Int64_val(arg4), Option_val(arg5, GCancellable_val, NULL), &error);
    g_free(c_arg1);
if (error == NULL) CAMLreturn(Res_Ok(Val_int(result))); else CAMLreturn(Res_Error(Val_GError(error)));}

CAMLexport CAMLprim value ml_g_datagram_based_send_messages_bytecode(value * argv, int argn)
{
return ml_g_datagram_based_send_messages_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_g_datagram_based_receive_messages_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);
GError *error = NULL;
    int arg1_length = Wosize_val(arg1);
    GInputMessage* c_arg1 = (GInputMessage*)g_malloc(sizeof(GInputMessage) * arg1_length);
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = *GInputMessage_val(Field(arg1, i));
    }

gint result = g_datagram_based_receive_messages(GDatagramBased_val(self), c_arg1, Int_val(arg2), Int_val(arg3), Int64_val(arg4), Option_val(arg5, GCancellable_val, NULL), &error);
    g_free(c_arg1);
if (error == NULL) CAMLreturn(Res_Ok(Val_int(result))); else CAMLreturn(Res_Error(Val_GError(error)));}

CAMLexport CAMLprim value ml_g_datagram_based_receive_messages_bytecode(value * argv, int argn)
{
return ml_g_datagram_based_receive_messages_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}
CAMLexport CAMLprim value ml_gio_datagram_based_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_DATAGRAM_BASED)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GDatagramBased");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GDatagramBased((GDatagramBased*)gobj));
}

GType g_datagram_based_get_type (void);


CAMLprim value ml_gio_datagram_based_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_datagram_based_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_datagram_based_receive_messages(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
caml_failwith("DatagramBased requires GLib >= 2.48");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_datagram_based_send_messages(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
caml_failwith("DatagramBased requires GLib >= 2.48");
return Val_unit;
}

CAMLexport CAMLprim value ml_gio_datagram_based_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("DatagramBased requires GTK >= 2.48");
    return Val_unit;
}


#endif
