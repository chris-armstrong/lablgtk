/* GENERATED CODE - DO NOT EDIT */
/* C bindings for MountOperation */

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


CAMLexport CAMLprim value ml_g_mount_operation_new(value unit)
{
CAMLparam1(unit);

GMountOperation *obj = g_mount_operation_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GMountOperation(obj));
}
CAMLexport CAMLprim value ml_g_mount_operation_set_username(value self, value arg1)
{
CAMLparam2(self, arg1);

g_mount_operation_set_username(GMountOperation_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,58,0)

CAMLexport CAMLprim value ml_g_mount_operation_set_pim(value self, value arg1)
{
CAMLparam2(self, arg1);

g_mount_operation_set_pim(GMountOperation_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_mount_operation_set_pim(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MountOperation requires GLib >= 2.58");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_mount_operation_set_password_save(value self, value arg1)
{
CAMLparam2(self, arg1);

g_mount_operation_set_password_save(GMountOperation_val(self), GioPasswordSave_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_mount_operation_set_password(value self, value arg1)
{
CAMLparam2(self, arg1);

g_mount_operation_set_password(GMountOperation_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,58,0)

CAMLexport CAMLprim value ml_g_mount_operation_set_is_tcrypt_system_volume(value self, value arg1)
{
CAMLparam2(self, arg1);

g_mount_operation_set_is_tcrypt_system_volume(GMountOperation_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_mount_operation_set_is_tcrypt_system_volume(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MountOperation requires GLib >= 2.58");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,58,0)

CAMLexport CAMLprim value ml_g_mount_operation_set_is_tcrypt_hidden_volume(value self, value arg1)
{
CAMLparam2(self, arg1);

g_mount_operation_set_is_tcrypt_hidden_volume(GMountOperation_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_mount_operation_set_is_tcrypt_hidden_volume(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MountOperation requires GLib >= 2.58");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_mount_operation_set_domain(value self, value arg1)
{
CAMLparam2(self, arg1);

g_mount_operation_set_domain(GMountOperation_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_mount_operation_set_choice(value self, value arg1)
{
CAMLparam2(self, arg1);

g_mount_operation_set_choice(GMountOperation_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_mount_operation_set_anonymous(value self, value arg1)
{
CAMLparam2(self, arg1);

g_mount_operation_set_anonymous(GMountOperation_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_mount_operation_reply(value self, value arg1)
{
CAMLparam2(self, arg1);

g_mount_operation_reply(GMountOperation_val(self), GioMountOperationResult_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_mount_operation_get_username(value self)
{
CAMLparam1(self);

const char* result = g_mount_operation_get_username(GMountOperation_val(self));
CAMLreturn(Val_option_string(result));
}

#if GLIB_CHECK_VERSION(2,58,0)

CAMLexport CAMLprim value ml_g_mount_operation_get_pim(value self)
{
CAMLparam1(self);

guint result = g_mount_operation_get_pim(GMountOperation_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_g_mount_operation_get_pim(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MountOperation requires GLib >= 2.58");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_mount_operation_get_password_save(value self)
{
CAMLparam1(self);

GPasswordSave result = g_mount_operation_get_password_save(GMountOperation_val(self));
CAMLreturn(Val_GioPasswordSave(result));
}

CAMLexport CAMLprim value ml_g_mount_operation_get_password(value self)
{
CAMLparam1(self);

const char* result = g_mount_operation_get_password(GMountOperation_val(self));
CAMLreturn(Val_option_string(result));
}

#if GLIB_CHECK_VERSION(2,58,0)

CAMLexport CAMLprim value ml_g_mount_operation_get_is_tcrypt_system_volume(value self)
{
CAMLparam1(self);

gboolean result = g_mount_operation_get_is_tcrypt_system_volume(GMountOperation_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_mount_operation_get_is_tcrypt_system_volume(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MountOperation requires GLib >= 2.58");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,58,0)

CAMLexport CAMLprim value ml_g_mount_operation_get_is_tcrypt_hidden_volume(value self)
{
CAMLparam1(self);

gboolean result = g_mount_operation_get_is_tcrypt_hidden_volume(GMountOperation_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_mount_operation_get_is_tcrypt_hidden_volume(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MountOperation requires GLib >= 2.58");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_mount_operation_get_domain(value self)
{
CAMLparam1(self);

const char* result = g_mount_operation_get_domain(GMountOperation_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_mount_operation_get_choice(value self)
{
CAMLparam1(self);

int result = g_mount_operation_get_choice(GMountOperation_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_g_mount_operation_get_anonymous(value self)
{
CAMLparam1(self);

gboolean result = g_mount_operation_get_anonymous(GMountOperation_val(self));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_gio_mount_operation_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_mount_operation_get_type()));
}
