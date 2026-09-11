/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CharsetConverter */

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


#if GLIB_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_g_charset_converter_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
GError *error = NULL;
    
GCharsetConverter *obj = g_charset_converter_new(String_val(arg1), String_val(arg2), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GCharsetConverter(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#else

CAMLexport CAMLprim value ml_g_charset_converter_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("CharsetConverter requires GLib >= 2.24");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_g_charset_converter_set_use_fallback(value self, value arg1)
{
CAMLparam2(self, arg1);

g_charset_converter_set_use_fallback(GCharsetConverter_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_charset_converter_set_use_fallback(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("CharsetConverter requires GLib >= 2.24");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_g_charset_converter_get_use_fallback(value self)
{
CAMLparam1(self);

gboolean result = g_charset_converter_get_use_fallback(GCharsetConverter_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_charset_converter_get_use_fallback(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("CharsetConverter requires GLib >= 2.24");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_g_charset_converter_get_num_fallbacks(value self)
{
CAMLparam1(self);

guint result = g_charset_converter_get_num_fallbacks(GCharsetConverter_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_g_charset_converter_get_num_fallbacks(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("CharsetConverter requires GLib >= 2.24");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_g_charset_converter_get_from_charset(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GCharsetConverter *obj = (GCharsetConverter *)GCharsetConverter_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "from-charset");
if (pspec == NULL) caml_failwith("ml_g_charset_converter_get_from_charset: property 'from-charset' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "from-charset", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_g_charset_converter_get_from_charset(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("CharsetConverter requires GLib >= 2.24");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_g_charset_converter_get_to_charset(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GCharsetConverter *obj = (GCharsetConverter *)GCharsetConverter_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "to-charset");
if (pspec == NULL) caml_failwith("ml_g_charset_converter_get_to_charset: property 'to-charset' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "to-charset", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_g_charset_converter_get_to_charset(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("CharsetConverter requires GLib >= 2.24");
return Val_unit;
}
#endif

GType g_charset_converter_get_type (void);


CAMLprim value ml_gio_charset_converter_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_charset_converter_get_type()));
}
