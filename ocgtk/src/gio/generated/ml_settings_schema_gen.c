/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SettingsSchema */

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
/* Conversion functions for GSettingsSchema (opaque record with hidden fields) */
GSettingsSchema *GSettingsSchema_val(value v) {
  return (GSettingsSchema *)ml_gir_record_ptr_val(v, "GSettingsSchema");
}

value Val_GSettingsSchema(const GSettingsSchema *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(g_settings_schema_get_type(), ptr);
}

value Val_GSettingsSchema_option(const GSettingsSchema *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GSettingsSchema(ptr));
}
#endif

#if GLIB_CHECK_VERSION(2,32,0)


CAMLexport CAMLprim value ml_g_settings_schema_ref(value self)
{
CAMLparam1(self);

GSettingsSchema* result = g_settings_schema_ref(GSettingsSchema_val(self));
CAMLreturn(Val_GSettingsSchema(result));
}

#if GLIB_CHECK_VERSION(2,46,0)

CAMLexport CAMLprim value ml_g_settings_schema_list_keys(value self)
{
CAMLparam1(self);

gchar** result = g_settings_schema_list_keys(GSettingsSchema_val(self));
    int result_length = 0;
    while (result[result_length] != NULL) result_length++;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, caml_copy_string(result[i]));
    }
    for (int i = 0; i < result_length; i++) {
      g_free((gpointer)result[i]);
    }
    g_free(result);
CAMLreturn(ml_result);
}

#else

CAMLexport CAMLprim value ml_g_settings_schema_list_keys(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SettingsSchema requires GLib >= 2.46");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,44,0)

CAMLexport CAMLprim value ml_g_settings_schema_list_children(value self)
{
CAMLparam1(self);

gchar** result = g_settings_schema_list_children(GSettingsSchema_val(self));
    int result_length = 0;
    while (result[result_length] != NULL) result_length++;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, caml_copy_string(result[i]));
    }
    for (int i = 0; i < result_length; i++) {
      g_free((gpointer)result[i]);
    }
    g_free(result);
CAMLreturn(ml_result);
}

#else

CAMLexport CAMLprim value ml_g_settings_schema_list_children(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SettingsSchema requires GLib >= 2.44");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,40,0)

CAMLexport CAMLprim value ml_g_settings_schema_has_key(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_settings_schema_has_key(GSettingsSchema_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_schema_has_key(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SettingsSchema requires GLib >= 2.40");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_settings_schema_get_path(value self)
{
CAMLparam1(self);

const gchar* result = g_settings_schema_get_path(GSettingsSchema_val(self));
CAMLreturn(Val_option_string(result));
}

#if GLIB_CHECK_VERSION(2,40,0)

CAMLexport CAMLprim value ml_g_settings_schema_get_key(value self, value arg1)
{
CAMLparam2(self, arg1);

GSettingsSchemaKey* result = g_settings_schema_get_key(GSettingsSchema_val(self), String_val(arg1));
CAMLreturn(Val_GSettingsSchemaKey(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_schema_get_key(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SettingsSchema requires GLib >= 2.40");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_settings_schema_get_id(value self)
{
CAMLparam1(self);

const gchar* result = g_settings_schema_get_id(GSettingsSchema_val(self));
CAMLreturn(caml_copy_string(result));
}


CAMLprim value ml_gio_settings_schema_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_settings_schema_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_settings_schema_get_id(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SettingsSchema requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_settings_schema_get_key(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SettingsSchema requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_settings_schema_get_path(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SettingsSchema requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_settings_schema_has_key(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SettingsSchema requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_settings_schema_list_children(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SettingsSchema requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_settings_schema_list_keys(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SettingsSchema requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_settings_schema_ref(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SettingsSchema requires GLib >= 2.32");
return Val_unit;
}


#endif
