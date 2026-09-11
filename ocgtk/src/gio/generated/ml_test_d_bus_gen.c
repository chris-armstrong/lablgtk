/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TestDBus */

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

#if GLIB_CHECK_VERSION(2,34,0)


CAMLexport CAMLprim value ml_g_test_dbus_new(value arg1)
{
CAMLparam1(arg1);

GTestDBus *obj = g_test_dbus_new(GioTestDBusFlags_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GTestDBus(obj));
}
CAMLexport CAMLprim value ml_g_test_dbus_up(value self)
{
CAMLparam1(self);

g_test_dbus_up(GTestDBus_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_test_dbus_stop(value self)
{
CAMLparam1(self);

g_test_dbus_stop(GTestDBus_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_test_dbus_get_flags(value self)
{
CAMLparam1(self);

GTestDBusFlags result = g_test_dbus_get_flags(GTestDBus_val(self));
CAMLreturn(Val_GioTestDBusFlags(result));
}

CAMLexport CAMLprim value ml_g_test_dbus_get_bus_address(value self)
{
CAMLparam1(self);

const gchar* result = g_test_dbus_get_bus_address(GTestDBus_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_test_dbus_down(value self)
{
CAMLparam1(self);

g_test_dbus_down(GTestDBus_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_test_dbus_add_service_dir(value self, value arg1)
{
CAMLparam2(self, arg1);

g_test_dbus_add_service_dir(GTestDBus_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

GType g_test_dbus_get_type (void);


CAMLprim value ml_gio_test_d_bus_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_test_dbus_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_test_dbus_new(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("TestDBus requires GLib >= 2.34");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_test_dbus_add_service_dir(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TestDBus requires GLib >= 2.34");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_test_dbus_down(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TestDBus requires GLib >= 2.34");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_test_dbus_get_bus_address(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TestDBus requires GLib >= 2.34");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_test_dbus_get_flags(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TestDBus requires GLib >= 2.34");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_test_dbus_stop(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TestDBus requires GLib >= 2.34");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_test_dbus_up(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TestDBus requires GLib >= 2.34");
return Val_unit;
}


#endif
