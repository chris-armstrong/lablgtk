/* GENERATED CODE - DO NOT EDIT */
/* C bindings for IconTheme */

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


CAMLexport CAMLprim value ml_gtk_icon_theme_new(value unit)
{
CAMLparam1(unit);

GtkIconTheme *obj = gtk_icon_theme_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkIconTheme(obj));
}
CAMLexport CAMLprim value ml_gtk_icon_theme_set_theme_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_theme_set_theme_name(GtkIconTheme_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_theme_set_search_path(value self, value arg1)
{
CAMLparam2(self, arg1);
    int arg1_length = 0;
    const char** c_arg1 = NULL;
    
    if (Is_some(arg1)) {
        value array = Some_val(arg1);
        arg1_length = Wosize_val(array);
        c_arg1 = (const char**)g_malloc(sizeof(const char*) * (arg1_length + 1));
        for (int i = 0; i < arg1_length; i++) {
          c_arg1[i] = String_val(Field(array, i));
        }
        c_arg1[arg1_length] = NULL;
    }

gtk_icon_theme_set_search_path(GtkIconTheme_val(self), c_arg1);
    if (c_arg1) g_free(c_arg1);
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_theme_set_resource_path(value self, value arg1)
{
CAMLparam2(self, arg1);
    int arg1_length = 0;
    const char** c_arg1 = NULL;
    
    if (Is_some(arg1)) {
        value array = Some_val(arg1);
        arg1_length = Wosize_val(array);
        c_arg1 = (const char**)g_malloc(sizeof(const char*) * (arg1_length + 1));
        for (int i = 0; i < arg1_length; i++) {
          c_arg1[i] = String_val(Field(array, i));
        }
        c_arg1[arg1_length] = NULL;
    }

gtk_icon_theme_set_resource_path(GtkIconTheme_val(self), c_arg1);
    if (c_arg1) g_free(c_arg1);
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_theme_lookup_icon_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam2(arg5, arg6);
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

GtkIconPaintable* result = gtk_icon_theme_lookup_icon(GtkIconTheme_val(self), String_val(arg1), c_arg2, Int_val(arg3), Int_val(arg4), GtkTextDirection_val(arg5), GtkIconLookupFlags_val(arg6));
    if (c_arg2) g_free(c_arg2);
CAMLreturn(Val_GtkIconPaintable(result));}

CAMLexport CAMLprim value ml_gtk_icon_theme_lookup_icon_bytecode(value * argv, int argn)
{
return ml_gtk_icon_theme_lookup_icon_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

CAMLexport CAMLprim value ml_gtk_icon_theme_lookup_by_gicon_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);

GtkIconPaintable* result = gtk_icon_theme_lookup_by_gicon(GtkIconTheme_val(self), GIcon_val(arg1), Int_val(arg2), Int_val(arg3), GtkTextDirection_val(arg4), GtkIconLookupFlags_val(arg5));
CAMLreturn(Val_GtkIconPaintable(result));}

CAMLexport CAMLprim value ml_gtk_icon_theme_lookup_by_gicon_bytecode(value * argv, int argn)
{
return ml_gtk_icon_theme_lookup_by_gicon_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gtk_icon_theme_has_icon(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_icon_theme_has_icon(GtkIconTheme_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,2,0)

CAMLexport CAMLprim value ml_gtk_icon_theme_has_gicon(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_icon_theme_has_gicon(GtkIconTheme_val(self), GIcon_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gtk_icon_theme_has_gicon(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("IconTheme requires GTK >= 4.2");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_icon_theme_get_theme_name(value self)
{
CAMLparam1(self);

char* result = gtk_icon_theme_get_theme_name(GtkIconTheme_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_icon_theme_get_search_path(value self)
{
CAMLparam1(self);

char** result = gtk_icon_theme_get_search_path(GtkIconTheme_val(self));
    CAMLlocal2(ml_result, ml_result_opt);
    if (result == NULL) {
      ml_result_opt = Val_none;
    } else {
      int result_length = 0;
    while (result[result_length] != NULL) result_length++;
      ml_result = caml_alloc(result_length, 0);
      for (int i = 0; i < result_length; i++) {
        Store_field(ml_result, i, caml_copy_string(result[i]));
      }
      ml_result_opt = Val_some(ml_result);
            for (int i = 0; i < result_length; i++) {
      g_free((gpointer)result[i]);
    }
    g_free(result);
    }
CAMLreturn(ml_result_opt);
}

CAMLexport CAMLprim value ml_gtk_icon_theme_get_resource_path(value self)
{
CAMLparam1(self);

char** result = gtk_icon_theme_get_resource_path(GtkIconTheme_val(self));
    CAMLlocal2(ml_result, ml_result_opt);
    if (result == NULL) {
      ml_result_opt = Val_none;
    } else {
      int result_length = 0;
    while (result[result_length] != NULL) result_length++;
      ml_result = caml_alloc(result_length, 0);
      for (int i = 0; i < result_length; i++) {
        Store_field(ml_result, i, caml_copy_string(result[i]));
      }
      ml_result_opt = Val_some(ml_result);
            for (int i = 0; i < result_length; i++) {
      g_free((gpointer)result[i]);
    }
    g_free(result);
    }
CAMLreturn(ml_result_opt);
}

CAMLexport CAMLprim value ml_gtk_icon_theme_get_icon_names(value self)
{
CAMLparam1(self);

char** result = gtk_icon_theme_get_icon_names(GtkIconTheme_val(self));
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

CAMLexport CAMLprim value ml_gtk_icon_theme_get_display(value self)
{
CAMLparam1(self);

GdkDisplay* result = gtk_icon_theme_get_display(GtkIconTheme_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkDisplay));
}

CAMLexport CAMLprim value ml_gtk_icon_theme_add_search_path(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_theme_add_search_path(GtkIconTheme_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_theme_add_resource_path(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_theme_add_resource_path(GtkIconTheme_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

GType gtk_icon_theme_get_type (void);


CAMLprim value ml_gtk_icon_theme_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_icon_theme_get_type()));
}
