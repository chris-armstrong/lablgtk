/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ThreadedSocketService */

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


CAMLexport CAMLprim value ml_g_threaded_socket_service_new(value arg1)
{
CAMLparam1(arg1);

GThreadedSocketService *obj = g_threaded_socket_service_new(Int_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GThreadedSocketService(obj));
}
CAMLexport CAMLprim value ml_g_threaded_socket_service_get_max_threads(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GThreadedSocketService *obj = (GThreadedSocketService *)GThreadedSocketService_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "max-threads");
if (pspec == NULL) caml_failwith("ml_g_threaded_socket_service_get_max_threads: property 'max-threads' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "max-threads", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}


CAMLprim value ml_gio_threaded_socket_service_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_threaded_socket_service_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_threaded_socket_service_new(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("ThreadedSocketService requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_threaded_socket_service_get_max_threads(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ThreadedSocketService requires GLib >= 2.22");
return Val_unit;
}


#endif
