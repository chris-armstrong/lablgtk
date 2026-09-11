/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PollableOutputStream */

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

#if GLIB_CHECK_VERSION(2,28,0)


#if GLIB_CHECK_VERSION(2,60,0)

CAMLexport CAMLprim value ml_g_pollable_output_stream_writev_nonblocking(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GError *error = NULL;
    int arg1_length = Wosize_val(arg1);
    GOutputVector* c_arg1 = (GOutputVector*)g_malloc(sizeof(GOutputVector) * arg1_length);
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = *GOutputVector_val(Field(arg1, i));
    }
gsize out3;

GPollableReturn result = g_pollable_output_stream_writev_nonblocking(GPollableOutputStream_val(self), c_arg1, Gsize_val(arg2), &out3, Option_val(arg3, GCancellable_val, NULL), &error);
    g_free(c_arg1);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_GioPollableReturn(result));
    Store_field(ret, 1, Val_gsize(out3));
    if (error == NULL) CAMLreturn(Res_Ok(ret)); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_pollable_output_stream_writev_nonblocking(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("PollableOutputStream requires GLib >= 2.60");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_pollable_output_stream_is_writable(value self)
{
CAMLparam1(self);

gboolean result = g_pollable_output_stream_is_writable(GPollableOutputStream_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_pollable_output_stream_can_poll(value self)
{
CAMLparam1(self);

gboolean result = g_pollable_output_stream_can_poll(GPollableOutputStream_val(self));
CAMLreturn(Val_bool(result));
}
CAMLexport CAMLprim value ml_gio_pollable_output_stream_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_POLLABLE_OUTPUT_STREAM)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GPollableOutputStream");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GPollableOutputStream((GPollableOutputStream*)gobj));
}

GType g_pollable_output_stream_get_type (void);


CAMLprim value ml_gio_pollable_output_stream_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_pollable_output_stream_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_pollable_output_stream_can_poll(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PollableOutputStream requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_pollable_output_stream_is_writable(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PollableOutputStream requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_pollable_output_stream_writev_nonblocking(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("PollableOutputStream requires GLib >= 2.28");
return Val_unit;
}

CAMLexport CAMLprim value ml_gio_pollable_output_stream_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("PollableOutputStream requires GTK >= 2.28");
    return Val_unit;
}


#endif
