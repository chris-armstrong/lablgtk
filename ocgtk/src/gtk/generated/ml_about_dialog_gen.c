/* GENERATED CODE - DO NOT EDIT */
/* C bindings for AboutDialog */

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


CAMLexport CAMLprim value ml_gtk_about_dialog_new(value unit)
{
CAMLparam1(unit);

GtkAboutDialog *obj = gtk_about_dialog_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkAboutDialog(obj));
}
CAMLexport CAMLprim value ml_gtk_about_dialog_set_wrap_license(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_about_dialog_set_wrap_license(GtkAboutDialog_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_about_dialog_set_website_label(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_about_dialog_set_website_label(GtkAboutDialog_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_about_dialog_set_website(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_about_dialog_set_website(GtkAboutDialog_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_about_dialog_set_version(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_about_dialog_set_version(GtkAboutDialog_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_about_dialog_set_translator_credits(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_about_dialog_set_translator_credits(GtkAboutDialog_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_about_dialog_set_system_information(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_about_dialog_set_system_information(GtkAboutDialog_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_about_dialog_set_program_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_about_dialog_set_program_name(GtkAboutDialog_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_about_dialog_set_logo_icon_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_about_dialog_set_logo_icon_name(GtkAboutDialog_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_about_dialog_set_logo(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_about_dialog_set_logo(GtkAboutDialog_val(self), Option_val(arg1, GdkPaintable_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_about_dialog_set_license(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_about_dialog_set_license(GtkAboutDialog_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_about_dialog_set_documenters(value self, value arg1)
{
CAMLparam2(self, arg1);
    int arg1_length = Wosize_val(arg1);
    const char** c_arg1 = (const char**)g_malloc(sizeof(const char*) * (arg1_length + 1));
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = String_val(Field(arg1, i));
    }
    c_arg1[arg1_length] = NULL;

gtk_about_dialog_set_documenters(GtkAboutDialog_val(self), c_arg1);
    g_free(c_arg1);
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_about_dialog_set_copyright(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_about_dialog_set_copyright(GtkAboutDialog_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_about_dialog_set_comments(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_about_dialog_set_comments(GtkAboutDialog_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_about_dialog_set_authors(value self, value arg1)
{
CAMLparam2(self, arg1);
    int arg1_length = Wosize_val(arg1);
    const char** c_arg1 = (const char**)g_malloc(sizeof(const char*) * (arg1_length + 1));
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = String_val(Field(arg1, i));
    }
    c_arg1[arg1_length] = NULL;

gtk_about_dialog_set_authors(GtkAboutDialog_val(self), c_arg1);
    g_free(c_arg1);
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_about_dialog_set_artists(value self, value arg1)
{
CAMLparam2(self, arg1);
    int arg1_length = Wosize_val(arg1);
    const char** c_arg1 = (const char**)g_malloc(sizeof(const char*) * (arg1_length + 1));
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = String_val(Field(arg1, i));
    }
    c_arg1[arg1_length] = NULL;

gtk_about_dialog_set_artists(GtkAboutDialog_val(self), c_arg1);
    g_free(c_arg1);
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_about_dialog_get_wrap_license(value self)
{
CAMLparam1(self);

gboolean result = gtk_about_dialog_get_wrap_license(GtkAboutDialog_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_about_dialog_get_website_label(value self)
{
CAMLparam1(self);

const char* result = gtk_about_dialog_get_website_label(GtkAboutDialog_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_about_dialog_get_website(value self)
{
CAMLparam1(self);

const char* result = gtk_about_dialog_get_website(GtkAboutDialog_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_about_dialog_get_version(value self)
{
CAMLparam1(self);

const char* result = gtk_about_dialog_get_version(GtkAboutDialog_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_about_dialog_get_translator_credits(value self)
{
CAMLparam1(self);

const char* result = gtk_about_dialog_get_translator_credits(GtkAboutDialog_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_about_dialog_get_system_information(value self)
{
CAMLparam1(self);

const char* result = gtk_about_dialog_get_system_information(GtkAboutDialog_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_about_dialog_get_program_name(value self)
{
CAMLparam1(self);

const char* result = gtk_about_dialog_get_program_name(GtkAboutDialog_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_about_dialog_get_logo_icon_name(value self)
{
CAMLparam1(self);

const char* result = gtk_about_dialog_get_logo_icon_name(GtkAboutDialog_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_about_dialog_get_logo(value self)
{
CAMLparam1(self);

GdkPaintable* result = gtk_about_dialog_get_logo(GtkAboutDialog_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkPaintable));
}

CAMLexport CAMLprim value ml_gtk_about_dialog_get_license(value self)
{
CAMLparam1(self);

const char* result = gtk_about_dialog_get_license(GtkAboutDialog_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_about_dialog_get_documenters(value self)
{
CAMLparam1(self);

const char* const* result = gtk_about_dialog_get_documenters(GtkAboutDialog_val(self));
    int result_length = 0;
    while (result[result_length] != NULL) result_length++;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, caml_copy_string(result[i]));
    }
CAMLreturn(ml_result);
}

CAMLexport CAMLprim value ml_gtk_about_dialog_get_copyright(value self)
{
CAMLparam1(self);

const char* result = gtk_about_dialog_get_copyright(GtkAboutDialog_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_about_dialog_get_comments(value self)
{
CAMLparam1(self);

const char* result = gtk_about_dialog_get_comments(GtkAboutDialog_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_about_dialog_get_authors(value self)
{
CAMLparam1(self);

const char* const* result = gtk_about_dialog_get_authors(GtkAboutDialog_val(self));
    int result_length = 0;
    while (result[result_length] != NULL) result_length++;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, caml_copy_string(result[i]));
    }
CAMLreturn(ml_result);
}

CAMLexport CAMLprim value ml_gtk_about_dialog_get_artists(value self)
{
CAMLparam1(self);

const char* const* result = gtk_about_dialog_get_artists(GtkAboutDialog_val(self));
    int result_length = 0;
    while (result[result_length] != NULL) result_length++;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, caml_copy_string(result[i]));
    }
CAMLreturn(ml_result);
}

CAMLexport CAMLprim value ml_gtk_about_dialog_add_credit_section(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
    int arg2_length = Wosize_val(arg2);
    const char** c_arg2 = (const char**)g_malloc(sizeof(const char*) * (arg2_length + 1));
    for (int i = 0; i < arg2_length; i++) {
      c_arg2[i] = String_val(Field(arg2, i));
    }
    c_arg2[arg2_length] = NULL;

gtk_about_dialog_add_credit_section(GtkAboutDialog_val(self), String_val(arg1), c_arg2);
    g_free(c_arg2);
CAMLreturn(Val_unit);
}

GType gtk_about_dialog_get_type (void);


CAMLprim value ml_gtk_about_dialog_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_about_dialog_get_type()));
}
