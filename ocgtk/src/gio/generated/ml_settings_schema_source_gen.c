/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SettingsSchemaSource */

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
/* Conversion functions for GSettingsSchemaSource (opaque record with hidden fields) */
GSettingsSchemaSource *GSettingsSchemaSource_val(value v) {
  return (GSettingsSchemaSource *)ml_gir_record_ptr_val(v, "GSettingsSchemaSource");
}

value Val_GSettingsSchemaSource(const GSettingsSchemaSource *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(g_settings_schema_source_get_type(), ptr);
}

value Val_GSettingsSchemaSource_option(const GSettingsSchemaSource *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GSettingsSchemaSource(ptr));
}
#endif

#if GLIB_CHECK_VERSION(2,32,0)


CAMLexport CAMLprim value ml_g_settings_schema_source_new_from_directory(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);
GError *error = NULL;
    
GSettingsSchemaSource *obj = g_settings_schema_source_new_from_directory(String_val(arg1), Option_val(arg2, GSettingsSchemaSource_val, NULL), Bool_val(arg3), &error);

if (error == NULL) CAMLreturn(Res_Ok(Val_GSettingsSchemaSource(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_g_settings_schema_source_ref(value self)
{
CAMLparam1(self);

GSettingsSchemaSource* result = g_settings_schema_source_ref(GSettingsSchemaSource_val(self));
CAMLreturn(Val_GSettingsSchemaSource(result));
}

CAMLexport CAMLprim value ml_g_settings_schema_source_lookup(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

GSettingsSchema* result = g_settings_schema_source_lookup(GSettingsSchemaSource_val(self), String_val(arg1), Bool_val(arg2));
CAMLreturn(Val_option(result, Val_GSettingsSchema));
}

GType g_settings_schema_source_get_type (void);


CAMLprim value ml_gio_settings_schema_source_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_settings_schema_source_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_settings_schema_source_new_from_directory(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("SettingsSchemaSource requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_settings_schema_source_lookup(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("SettingsSchemaSource requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_settings_schema_source_ref(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SettingsSchemaSource requires GLib >= 2.32");
return Val_unit;
}


#endif
