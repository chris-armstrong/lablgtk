/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CssProvider */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"
#include "converters.h"

#include <gtk/gtk.h>
/* Include library-specific type conversions and forward declarations */
#include "gtk_decls.h"


CAMLexport CAMLprim value ml_gtk_css_provider_new(value unit)
{
CAMLparam1(unit);

GtkCssProvider *obj = gtk_css_provider_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkCssProvider(obj));
}
CAMLexport CAMLprim value ml_gtk_css_provider_to_string(value self)
{
CAMLparam1(self);

char* result = gtk_css_provider_to_string(GtkCssProvider_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_css_provider_load_named(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_css_provider_load_named(GtkCssProvider_val(self), String_val(arg1), String_option_val(arg2));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_css_provider_load_from_string(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_css_provider_load_from_string(GtkCssProvider_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_css_provider_load_from_string(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("CssProvider requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_css_provider_load_from_resource(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_css_provider_load_from_resource(GtkCssProvider_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_css_provider_load_from_path(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_css_provider_load_from_path(GtkCssProvider_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_css_provider_load_from_file(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_css_provider_load_from_file(GtkCssProvider_val(self), GFile_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_css_provider_load_from_data(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_css_provider_load_from_data(GtkCssProvider_val(self), String_val(arg1), Long_val(arg2));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_css_provider_load_from_bytes(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_css_provider_load_from_bytes(GtkCssProvider_val(self), GBytes_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_css_provider_load_from_bytes(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("CssProvider requires GTK >= 4.12");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gtk_css_provider_get_prefers_color_scheme(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCssProvider *obj = (GtkCssProvider *)GtkCssProvider_val(self);
    GtkInterfaceColorScheme prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "prefers-color-scheme");
if (pspec == NULL) caml_failwith("ml_gtk_css_provider_get_prefers_color_scheme: property 'prefers-color-scheme' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "prefers-color-scheme", &prop_gvalue);
          prop_value = (GtkInterfaceColorScheme)g_value_get_enum(&prop_gvalue);

      result = Val_GtkInterfaceColorScheme(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_css_provider_get_prefers_color_scheme(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("CssProvider requires GTK >= 4.20");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gtk_css_provider_set_prefers_color_scheme(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCssProvider *obj = (GtkCssProvider *)GtkCssProvider_val(self);
    GtkInterfaceColorScheme c_value = GtkInterfaceColorScheme_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "prefers-color-scheme");
if (pspec == NULL) caml_failwith("ml_gtk_css_provider_set_prefers_color_scheme: property 'prefers-color-scheme' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "prefers-color-scheme", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_css_provider_set_prefers_color_scheme(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("CssProvider requires GTK >= 4.20");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gtk_css_provider_get_prefers_contrast(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCssProvider *obj = (GtkCssProvider *)GtkCssProvider_val(self);
    GtkInterfaceContrast prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "prefers-contrast");
if (pspec == NULL) caml_failwith("ml_gtk_css_provider_get_prefers_contrast: property 'prefers-contrast' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "prefers-contrast", &prop_gvalue);
          prop_value = (GtkInterfaceContrast)g_value_get_enum(&prop_gvalue);

      result = Val_GtkInterfaceContrast(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_css_provider_get_prefers_contrast(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("CssProvider requires GTK >= 4.20");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gtk_css_provider_set_prefers_contrast(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCssProvider *obj = (GtkCssProvider *)GtkCssProvider_val(self);
    GtkInterfaceContrast c_value = GtkInterfaceContrast_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "prefers-contrast");
if (pspec == NULL) caml_failwith("ml_gtk_css_provider_set_prefers_contrast: property 'prefers-contrast' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "prefers-contrast", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_css_provider_set_prefers_contrast(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("CssProvider requires GTK >= 4.20");
return Val_unit;
}
#endif

GType gtk_css_provider_get_type (void);


CAMLprim value ml_gtk_css_provider_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_css_provider_get_type()));
}
