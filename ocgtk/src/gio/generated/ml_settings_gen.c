/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Settings */

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

CAMLexport CAMLprim value ml_g_settings_new(value arg1)
{
CAMLparam1(arg1);

GSettings *obj = g_settings_new(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GSettings(obj));
}
#else

CAMLexport CAMLprim value ml_g_settings_new(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_settings_new_with_path(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GSettings *obj = g_settings_new_with_path(String_val(arg1), String_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GSettings(obj));
}
#else

CAMLexport CAMLprim value ml_g_settings_new_with_path(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_settings_set_value(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = g_settings_set_value(GSettings_val(self), String_val(arg1), GVariant_val(arg2));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_set_value(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,50,0)

CAMLexport CAMLprim value ml_g_settings_set_uint64(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = g_settings_set_uint64(GSettings_val(self), String_val(arg1), Uint64_val(arg2));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_set_uint64(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Settings requires GLib >= 2.50");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,30,0)

CAMLexport CAMLprim value ml_g_settings_set_uint(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = g_settings_set_uint(GSettings_val(self), String_val(arg1), Int_val(arg2));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_set_uint(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Settings requires GLib >= 2.30");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_settings_set_strv(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
    int arg2_length = 0;
    const char** c_arg2 = NULL;
    
    if (Is_some(arg2)) {
        value array = Some_val(arg2);
        arg2_length = Wosize_val(array);
        c_arg2 = (const char**)g_malloc(sizeof(const char*) * (arg2_length + 1));
        for (int i = 0; i < arg2_length; i++) {
          c_arg2[i] = String_val(Field(array, i));
        }
        c_arg2[arg2_length] = NULL;
    }

gboolean result = g_settings_set_strv(GSettings_val(self), String_val(arg1), c_arg2);
    if (c_arg2) g_free(c_arg2);
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_set_strv(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_settings_set_string(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = g_settings_set_string(GSettings_val(self), String_val(arg1), String_val(arg2));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_set_string(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,50,0)

CAMLexport CAMLprim value ml_g_settings_set_int64(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = g_settings_set_int64(GSettings_val(self), String_val(arg1), Int64_val(arg2));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_set_int64(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Settings requires GLib >= 2.50");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_settings_set_int(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = g_settings_set_int(GSettings_val(self), String_val(arg1), Int_val(arg2));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_set_int(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_settings_set_flags(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = g_settings_set_flags(GSettings_val(self), String_val(arg1), Int_val(arg2));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_settings_set_enum(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = g_settings_set_enum(GSettings_val(self), String_val(arg1), Int_val(arg2));
CAMLreturn(Val_bool(result));
}

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_settings_set_double(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = g_settings_set_double(GSettings_val(self), String_val(arg1), Double_val(arg2));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_set_double(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_settings_set_boolean(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = g_settings_set_boolean(GSettings_val(self), String_val(arg1), Bool_val(arg2));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_set_boolean(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_settings_revert(value self)
{
CAMLparam1(self);

g_settings_revert(GSettings_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_settings_reset(value self, value arg1)
{
CAMLparam2(self, arg1);

g_settings_reset(GSettings_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_settings_range_check(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = g_settings_range_check(GSettings_val(self), String_val(arg1), GVariant_val(arg2));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_range_check(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Settings requires GLib >= 2.28");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_settings_list_keys(value self)
{
CAMLparam1(self);

gchar** result = g_settings_list_keys(GSettings_val(self));
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

CAMLexport CAMLprim value ml_g_settings_list_children(value self)
{
CAMLparam1(self);

gchar** result = g_settings_list_children(GSettings_val(self));
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

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_settings_is_writable(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_settings_is_writable(GSettings_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_is_writable(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_settings_get_value(value self, value arg1)
{
CAMLparam2(self, arg1);

GVariant* result = g_settings_get_value(GSettings_val(self), String_val(arg1));
CAMLreturn(Val_GVariant(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_get_value(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,40,0)

CAMLexport CAMLprim value ml_g_settings_get_user_value(value self, value arg1)
{
CAMLparam2(self, arg1);

GVariant* result = g_settings_get_user_value(GSettings_val(self), String_val(arg1));
CAMLreturn(Val_option(result, Val_GVariant));
}

#else

CAMLexport CAMLprim value ml_g_settings_get_user_value(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GLib >= 2.40");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,50,0)

CAMLexport CAMLprim value ml_g_settings_get_uint64(value self, value arg1)
{
CAMLparam2(self, arg1);

guint64 result = g_settings_get_uint64(GSettings_val(self), String_val(arg1));
CAMLreturn(integers_copy_uint64(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_get_uint64(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GLib >= 2.50");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,30,0)

CAMLexport CAMLprim value ml_g_settings_get_uint(value self, value arg1)
{
CAMLparam2(self, arg1);

guint result = g_settings_get_uint(GSettings_val(self), String_val(arg1));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_get_uint(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GLib >= 2.30");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_settings_get_strv(value self, value arg1)
{
CAMLparam2(self, arg1);

gchar** result = g_settings_get_strv(GSettings_val(self), String_val(arg1));
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

CAMLexport CAMLprim value ml_g_settings_get_strv(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_settings_get_string(value self, value arg1)
{
CAMLparam2(self, arg1);

gchar* result = g_settings_get_string(GSettings_val(self), String_val(arg1));
CAMLreturn(caml_copy_string(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_get_string(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_settings_get_range(value self, value arg1)
{
CAMLparam2(self, arg1);

GVariant* result = g_settings_get_range(GSettings_val(self), String_val(arg1));
CAMLreturn(Val_GVariant(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_get_range(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,50,0)

CAMLexport CAMLprim value ml_g_settings_get_int64(value self, value arg1)
{
CAMLparam2(self, arg1);

gint64 result = g_settings_get_int64(GSettings_val(self), String_val(arg1));
CAMLreturn(caml_copy_int64(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_get_int64(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GLib >= 2.50");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_settings_get_int(value self, value arg1)
{
CAMLparam2(self, arg1);

gint result = g_settings_get_int(GSettings_val(self), String_val(arg1));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_get_int(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_settings_get_has_unapplied(value self)
{
CAMLparam1(self);

gboolean result = g_settings_get_has_unapplied(GSettings_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_get_has_unapplied(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_settings_get_flags(value self, value arg1)
{
CAMLparam2(self, arg1);

guint result = g_settings_get_flags(GSettings_val(self), String_val(arg1));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_get_flags(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_settings_get_enum(value self, value arg1)
{
CAMLparam2(self, arg1);

gint result = g_settings_get_enum(GSettings_val(self), String_val(arg1));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_get_enum(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_settings_get_double(value self, value arg1)
{
CAMLparam2(self, arg1);

gdouble result = g_settings_get_double(GSettings_val(self), String_val(arg1));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_get_double(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,40,0)

CAMLexport CAMLprim value ml_g_settings_get_default_value(value self, value arg1)
{
CAMLparam2(self, arg1);

GVariant* result = g_settings_get_default_value(GSettings_val(self), String_val(arg1));
CAMLreturn(Val_option(result, Val_GVariant));
}

#else

CAMLexport CAMLprim value ml_g_settings_get_default_value(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GLib >= 2.40");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_settings_get_child(value self, value arg1)
{
CAMLparam2(self, arg1);

GSettings* result = g_settings_get_child(GSettings_val(self), String_val(arg1));
CAMLreturn(Val_GSettings(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_get_child(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_settings_get_boolean(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_settings_get_boolean(GSettings_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_get_boolean(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_settings_delay(value self)
{
CAMLparam1(self);

g_settings_delay(GSettings_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_settings_delay(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_settings_create_action(value self, value arg1)
{
CAMLparam2(self, arg1);

GAction* result = g_settings_create_action(GSettings_val(self), String_val(arg1));
CAMLreturn(Val_GAction(result));
}

#else

CAMLexport CAMLprim value ml_g_settings_create_action(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Settings requires GLib >= 2.32");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_settings_bind_writable(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

g_settings_bind_writable(GSettings_val(self), String_val(arg1), GObject_ext_of_val(arg2), String_val(arg3), Bool_val(arg4));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_settings_bind_writable(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_settings_bind(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

g_settings_bind(GSettings_val(self), String_val(arg1), GObject_ext_of_val(arg2), String_val(arg3), GioSettingsBindFlags_val(arg4));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_settings_bind(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Settings requires GLib >= 2.26");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_settings_apply(value self)
{
CAMLparam1(self);

g_settings_apply(GSettings_val(self));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_settings_get_delay_apply(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GSettings *obj = (GSettings *)GSettings_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "delay-apply");
if (pspec == NULL) caml_failwith("ml_g_settings_get_delay_apply: property 'delay-apply' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "delay-apply", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_g_settings_get_delay_apply(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Settings requires GLib >= 2.28");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_settings_get_path(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GSettings *obj = (GSettings *)GSettings_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "path");
if (pspec == NULL) caml_failwith("ml_g_settings_get_path: property 'path' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "path", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_g_settings_get_schema(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GSettings *obj = (GSettings *)GSettings_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "schema");
if (pspec == NULL) caml_failwith("ml_g_settings_get_schema: property 'schema' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "schema", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_g_settings_get_schema_id(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GSettings *obj = (GSettings *)GSettings_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "schema-id");
if (pspec == NULL) caml_failwith("ml_g_settings_get_schema_id: property 'schema-id' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "schema-id", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_g_settings_get_settings_schema(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GSettings *obj = (GSettings *)GSettings_val(self);
    GSettingsSchema *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "settings-schema");
if (pspec == NULL) caml_failwith("ml_g_settings_get_settings_schema: property 'settings-schema' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "settings-schema", &prop_gvalue);
          prop_value = (GSettingsSchema*)g_value_get_boxed(&prop_gvalue);

      result = Val_GSettingsSchema(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}


CAMLprim value ml_gio_settings_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_settings_get_type()));
}
