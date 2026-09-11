/* GENERATED CODE - DO NOT EDIT */
/* C bindings for RecentInfo */

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

/* Conversion functions for GtkRecentInfo (opaque record with hidden fields) */
GtkRecentInfo *GtkRecentInfo_val(value v) {
  return (GtkRecentInfo *)ml_gir_record_ptr_val(v, "GtkRecentInfo");
}

value Val_GtkRecentInfo(const GtkRecentInfo *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gtk_recent_info_get_type(), ptr);
}

value Val_GtkRecentInfo_option(const GtkRecentInfo *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GtkRecentInfo(ptr));
}


CAMLexport CAMLprim value ml_gtk_recent_info_ref(value self)
{
CAMLparam1(self);

GtkRecentInfo* result = gtk_recent_info_ref(GtkRecentInfo_val(self));
CAMLreturn(Val_GtkRecentInfo(result));
}

CAMLexport CAMLprim value ml_gtk_recent_info_match(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_recent_info_match(GtkRecentInfo_val(self), GtkRecentInfo_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_recent_info_last_application(value self)
{
CAMLparam1(self);

char* result = gtk_recent_info_last_application(GtkRecentInfo_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_recent_info_is_local(value self)
{
CAMLparam1(self);

gboolean result = gtk_recent_info_is_local(GtkRecentInfo_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_recent_info_has_group(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_recent_info_has_group(GtkRecentInfo_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_recent_info_has_application(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_recent_info_has_application(GtkRecentInfo_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_recent_info_get_uri_display(value self)
{
CAMLparam1(self);

char* result = gtk_recent_info_get_uri_display(GtkRecentInfo_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_recent_info_get_uri(value self)
{
CAMLparam1(self);

const char* result = gtk_recent_info_get_uri(GtkRecentInfo_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_recent_info_get_short_name(value self)
{
CAMLparam1(self);

char* result = gtk_recent_info_get_short_name(GtkRecentInfo_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_recent_info_get_private_hint(value self)
{
CAMLparam1(self);

gboolean result = gtk_recent_info_get_private_hint(GtkRecentInfo_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_recent_info_get_mime_type(value self)
{
CAMLparam1(self);

const char* result = gtk_recent_info_get_mime_type(GtkRecentInfo_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_recent_info_get_groups(value self)
{
CAMLparam1(self);
gsize out1;

char** result = gtk_recent_info_get_groups(GtkRecentInfo_val(self), &out1);
    int result_length = out1;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, caml_copy_string(result[i]));
    }
    for (int i = 0; i < result_length; i++) {
      g_free((gpointer)result[i]);
    }
    g_free(result);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_result);
    Store_field(ret, 1, Val_gsize(out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_recent_info_get_gicon(value self)
{
CAMLparam1(self);

GIcon* result = gtk_recent_info_get_gicon(GtkRecentInfo_val(self));
CAMLreturn(Val_option(result, Val_GIcon));
}

CAMLexport CAMLprim value ml_gtk_recent_info_get_display_name(value self)
{
CAMLparam1(self);

const char* result = gtk_recent_info_get_display_name(GtkRecentInfo_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_recent_info_get_description(value self)
{
CAMLparam1(self);

const char* result = gtk_recent_info_get_description(GtkRecentInfo_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_recent_info_get_applications(value self)
{
CAMLparam1(self);
gsize out1;

char** result = gtk_recent_info_get_applications(GtkRecentInfo_val(self), &out1);
    int result_length = out1;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, caml_copy_string(result[i]));
    }
    for (int i = 0; i < result_length; i++) {
      g_free((gpointer)result[i]);
    }
    g_free(result);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_result);
    Store_field(ret, 1, Val_gsize(out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_recent_info_get_age(value self)
{
CAMLparam1(self);

int result = gtk_recent_info_get_age(GtkRecentInfo_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_recent_info_exists(value self)
{
CAMLparam1(self);

gboolean result = gtk_recent_info_exists(GtkRecentInfo_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_recent_info_create_app_info(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GAppInfo* result = gtk_recent_info_create_app_info(GtkRecentInfo_val(self), String_option_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_option(result, Val_GAppInfo))); else CAMLreturn(Res_Error(Val_GError(error)));
}

GType gtk_recent_info_get_type (void);


CAMLprim value ml_gtk_recent_info_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_recent_info_get_type()));
}
