/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DBusAuthObserver */

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


CAMLexport CAMLprim value ml_g_dbus_auth_observer_new(value unit)
{
CAMLparam1(unit);

GDBusAuthObserver *obj = g_dbus_auth_observer_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GDBusAuthObserver(obj));
}
CAMLexport CAMLprim value ml_g_dbus_auth_observer_authorize_authenticated_peer(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = g_dbus_auth_observer_authorize_authenticated_peer(GDBusAuthObserver_val(self), GIOStream_val(arg1), Option_val(arg2, GCredentials_val, NULL));
CAMLreturn(Val_bool(result));
}

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_dbus_auth_observer_allow_mechanism(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_dbus_auth_observer_allow_mechanism(GDBusAuthObserver_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_dbus_auth_observer_allow_mechanism(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusAuthObserver requires GLib >= 2.34");
return Val_unit;
}
#endif


CAMLprim value ml_gio_d_bus_auth_observer_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_dbus_auth_observer_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_dbus_auth_observer_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("DBusAuthObserver requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_auth_observer_allow_mechanism(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DBusAuthObserver requires GLib >= 2.26");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_dbus_auth_observer_authorize_authenticated_peer(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("DBusAuthObserver requires GLib >= 2.26");
return Val_unit;
}


#endif
