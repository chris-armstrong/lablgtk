/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SettingsSchemaKey */

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

/* Conversion functions for GSettingsSchemaKey (opaque record with hidden fields) */
GSettingsSchemaKey *GSettingsSchemaKey_val(value v) {
  return (GSettingsSchemaKey *)ml_gir_record_ptr_val(v, "GSettingsSchemaKey");
}

value Val_GSettingsSchemaKey(const GSettingsSchemaKey *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(g_settings_schema_key_get_type(), ptr);
}

value Val_GSettingsSchemaKey_option(const GSettingsSchemaKey *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GSettingsSchemaKey(ptr));
}


#if GLIB_CHECK_VERSION(2,40,0)

CAMLexport CAMLprim value ml_g_settings_schema_key_ref(value self)
{
CAMLparam1(self);

GSettingsSchemaKey* result = g_settings_schema_key_ref(GSettingsSchemaKey_val(self));
CAMLreturn(Val_GSettingsSchemaKey(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_schema_key_ref(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SettingsSchemaKey requires GLib >= 2.40");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,40,0)

CAMLexport CAMLprim value ml_g_settings_schema_key_range_check(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_settings_schema_key_range_check(GSettingsSchemaKey_val(self), GVariant_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_schema_key_range_check(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SettingsSchemaKey requires GLib >= 2.40");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,40,0)

CAMLexport CAMLprim value ml_g_settings_schema_key_get_value_type(value self)
{
CAMLparam1(self);

const GVariantType* result = g_settings_schema_key_get_value_type(GSettingsSchemaKey_val(self));
CAMLreturn(Val_GVariantType(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_schema_key_get_value_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SettingsSchemaKey requires GLib >= 2.40");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_settings_schema_key_get_summary(value self)
{
CAMLparam1(self);

const gchar* result = g_settings_schema_key_get_summary(GSettingsSchemaKey_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_schema_key_get_summary(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SettingsSchemaKey requires GLib >= 2.34");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,40,0)

CAMLexport CAMLprim value ml_g_settings_schema_key_get_range(value self)
{
CAMLparam1(self);

GVariant* result = g_settings_schema_key_get_range(GSettingsSchemaKey_val(self));
CAMLreturn(Val_GVariant(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_schema_key_get_range(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SettingsSchemaKey requires GLib >= 2.40");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,44,0)

CAMLexport CAMLprim value ml_g_settings_schema_key_get_name(value self)
{
CAMLparam1(self);

const gchar* result = g_settings_schema_key_get_name(GSettingsSchemaKey_val(self));
CAMLreturn(caml_copy_string(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_schema_key_get_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SettingsSchemaKey requires GLib >= 2.44");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_settings_schema_key_get_description(value self)
{
CAMLparam1(self);

const gchar* result = g_settings_schema_key_get_description(GSettingsSchemaKey_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_schema_key_get_description(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SettingsSchemaKey requires GLib >= 2.34");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,40,0)

CAMLexport CAMLprim value ml_g_settings_schema_key_get_default_value(value self)
{
CAMLparam1(self);

GVariant* result = g_settings_schema_key_get_default_value(GSettingsSchemaKey_val(self));
CAMLreturn(Val_GVariant(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_schema_key_get_default_value(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SettingsSchemaKey requires GLib >= 2.40");
return Val_unit;
}
#endif


CAMLprim value ml_gio_settings_schema_key_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_settings_schema_key_get_type()));
}
