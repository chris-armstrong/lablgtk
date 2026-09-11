/* GENERATED CODE - DO NOT EDIT */
/* C bindings for InetAddressMask */

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

#if GLIB_CHECK_VERSION(2,32,0)


CAMLexport CAMLprim value ml_g_inet_address_mask_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
GError *error = NULL;
    
GInetAddressMask *obj = g_inet_address_mask_new(GInetAddress_val(arg1), Int_val(arg2), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GInetAddressMask(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_g_inet_address_mask_new_from_string(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GInetAddressMask *obj = g_inet_address_mask_new_from_string(String_val(arg1), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GInetAddressMask(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_g_inet_address_mask_to_string(value self)
{
CAMLparam1(self);

gchar* result = g_inet_address_mask_to_string(GInetAddressMask_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_g_inet_address_mask_matches(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_inet_address_mask_matches(GInetAddressMask_val(self), GInetAddress_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_inet_address_mask_get_length(value self)
{
CAMLparam1(self);

guint result = g_inet_address_mask_get_length(GInetAddressMask_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_g_inet_address_mask_get_family(value self)
{
CAMLparam1(self);

GSocketFamily result = g_inet_address_mask_get_family(GInetAddressMask_val(self));
CAMLreturn(Val_GioSocketFamily(result));
}

CAMLexport CAMLprim value ml_g_inet_address_mask_get_address(value self)
{
CAMLparam1(self);

GInetAddress* result = g_inet_address_mask_get_address(GInetAddressMask_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GInetAddress(result));
}

CAMLexport CAMLprim value ml_g_inet_address_mask_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_inet_address_mask_equal(GInetAddressMask_val(self), GInetAddressMask_val(arg1));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_gio_inet_address_mask_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_inet_address_mask_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_inet_address_mask_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("InetAddressMask requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_inet_address_mask_new_from_string(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("InetAddressMask requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_inet_address_mask_equal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("InetAddressMask requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_inet_address_mask_get_address(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("InetAddressMask requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_inet_address_mask_get_family(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("InetAddressMask requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_inet_address_mask_get_length(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("InetAddressMask requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_inet_address_mask_matches(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("InetAddressMask requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_inet_address_mask_to_string(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("InetAddressMask requires GLib >= 2.32");
return Val_unit;
}


#endif
