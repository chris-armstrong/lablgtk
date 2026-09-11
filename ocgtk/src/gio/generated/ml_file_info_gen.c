/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FileInfo */

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


CAMLexport CAMLprim value ml_g_file_info_new(value unit)
{
CAMLparam1(unit);

GFileInfo *obj = g_file_info_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GFileInfo(obj));
}
CAMLexport CAMLprim value ml_g_file_info_unset_attribute_mask(value self)
{
CAMLparam1(self);

g_file_info_unset_attribute_mask(GFileInfo_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_info_set_symlink_target(value self, value arg1)
{
CAMLparam2(self, arg1);

g_file_info_set_symlink_target(GFileInfo_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_file_info_set_symbolic_icon(value self, value arg1)
{
CAMLparam2(self, arg1);

g_file_info_set_symbolic_icon(GFileInfo_val(self), GIcon_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_file_info_set_symbolic_icon(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FileInfo requires GLib >= 2.34");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_file_info_set_sort_order(value self, value arg1)
{
CAMLparam2(self, arg1);

g_file_info_set_sort_order(GFileInfo_val(self), Int32_val_bounded(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_info_set_size(value self, value arg1)
{
CAMLparam2(self, arg1);

g_file_info_set_size(GFileInfo_val(self), Int64_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_info_set_name(value self, value arg1)
{
CAMLparam2(self, arg1);

g_file_info_set_name(GFileInfo_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_info_set_is_symlink(value self, value arg1)
{
CAMLparam2(self, arg1);

g_file_info_set_is_symlink(GFileInfo_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_info_set_is_hidden(value self, value arg1)
{
CAMLparam2(self, arg1);

g_file_info_set_is_hidden(GFileInfo_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_info_set_icon(value self, value arg1)
{
CAMLparam2(self, arg1);

g_file_info_set_icon(GFileInfo_val(self), GIcon_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_info_set_file_type(value self, value arg1)
{
CAMLparam2(self, arg1);

g_file_info_set_file_type(GFileInfo_val(self), GioFileType_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_info_set_edit_name(value self, value arg1)
{
CAMLparam2(self, arg1);

g_file_info_set_edit_name(GFileInfo_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_info_set_display_name(value self, value arg1)
{
CAMLparam2(self, arg1);

g_file_info_set_display_name(GFileInfo_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_info_set_content_type(value self, value arg1)
{
CAMLparam2(self, arg1);

g_file_info_set_content_type(GFileInfo_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_info_set_attribute_uint64(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_file_info_set_attribute_uint64(GFileInfo_val(self), String_val(arg1), Uint64_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_info_set_attribute_uint32(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_file_info_set_attribute_uint32(GFileInfo_val(self), String_val(arg1), UInt32_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_info_set_attribute_stringv(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
    int arg2_length = Wosize_val(arg2);
    const char** c_arg2 = (const char**)g_malloc(sizeof(const char*) * (arg2_length + 1));
    for (int i = 0; i < arg2_length; i++) {
      c_arg2[i] = String_val(Field(arg2, i));
    }
    c_arg2[arg2_length] = NULL;

g_file_info_set_attribute_stringv(GFileInfo_val(self), String_val(arg1), c_arg2);
    g_free(c_arg2);
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_info_set_attribute_string(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_file_info_set_attribute_string(GFileInfo_val(self), String_val(arg1), String_val(arg2));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_file_info_set_attribute_status(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = g_file_info_set_attribute_status(GFileInfo_val(self), String_val(arg1), GioFileAttributeStatus_val(arg2));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_file_info_set_attribute_status(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("FileInfo requires GLib >= 2.22");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_file_info_set_attribute_object(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_file_info_set_attribute_object(GFileInfo_val(self), String_val(arg1), GObject_ext_of_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_info_set_attribute_mask(value self, value arg1)
{
CAMLparam2(self, arg1);

g_file_info_set_attribute_mask(GFileInfo_val(self), GFileAttributeMatcher_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_info_set_attribute_int64(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_file_info_set_attribute_int64(GFileInfo_val(self), String_val(arg1), Int64_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_info_set_attribute_int32(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_file_info_set_attribute_int32(GFileInfo_val(self), String_val(arg1), Int32_val_bounded(arg2));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,78,0)

CAMLexport CAMLprim value ml_g_file_info_set_attribute_file_path(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_file_info_set_attribute_file_path(GFileInfo_val(self), String_val(arg1), String_val(arg2));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_file_info_set_attribute_file_path(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("FileInfo requires GLib >= 2.78");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_file_info_set_attribute_byte_string(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_file_info_set_attribute_byte_string(GFileInfo_val(self), String_val(arg1), String_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_info_set_attribute_boolean(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_file_info_set_attribute_boolean(GFileInfo_val(self), String_val(arg1), Bool_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_info_remove_attribute(value self, value arg1)
{
CAMLparam2(self, arg1);

g_file_info_remove_attribute(GFileInfo_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_info_list_attributes(value self, value arg1)
{
CAMLparam2(self, arg1);

char** result = g_file_info_list_attributes(GFileInfo_val(self), String_option_val(arg1));
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

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_file_info_has_namespace(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_file_info_has_namespace(GFileInfo_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_file_info_has_namespace(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FileInfo requires GLib >= 2.22");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_file_info_has_attribute(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_file_info_has_attribute(GFileInfo_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_file_info_get_symlink_target(value self)
{
CAMLparam1(self);

const char* result = g_file_info_get_symlink_target(GFileInfo_val(self));
CAMLreturn(Val_option_string(result));
}

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_file_info_get_symbolic_icon(value self)
{
CAMLparam1(self);

GIcon* result = g_file_info_get_symbolic_icon(GFileInfo_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GIcon));
}

#else

CAMLexport CAMLprim value ml_g_file_info_get_symbolic_icon(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FileInfo requires GLib >= 2.34");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_file_info_get_sort_order(value self)
{
CAMLparam1(self);

gint32 result = g_file_info_get_sort_order(GFileInfo_val(self));
CAMLreturn(Val_int32_bounded(result));
}

CAMLexport CAMLprim value ml_g_file_info_get_size(value self)
{
CAMLparam1(self);

goffset result = g_file_info_get_size(GFileInfo_val(self));
CAMLreturn(caml_copy_int64(result));
}

CAMLexport CAMLprim value ml_g_file_info_get_name(value self)
{
CAMLparam1(self);

const char* result = g_file_info_get_name(GFileInfo_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_g_file_info_get_is_symlink(value self)
{
CAMLparam1(self);

gboolean result = g_file_info_get_is_symlink(GFileInfo_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_file_info_get_is_hidden(value self)
{
CAMLparam1(self);

gboolean result = g_file_info_get_is_hidden(GFileInfo_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_file_info_get_is_backup(value self)
{
CAMLparam1(self);

gboolean result = g_file_info_get_is_backup(GFileInfo_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_file_info_get_icon(value self)
{
CAMLparam1(self);

GIcon* result = g_file_info_get_icon(GFileInfo_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GIcon));
}

CAMLexport CAMLprim value ml_g_file_info_get_file_type(value self)
{
CAMLparam1(self);

GFileType result = g_file_info_get_file_type(GFileInfo_val(self));
CAMLreturn(Val_GioFileType(result));
}

CAMLexport CAMLprim value ml_g_file_info_get_etag(value self)
{
CAMLparam1(self);

const char* result = g_file_info_get_etag(GFileInfo_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_file_info_get_edit_name(value self)
{
CAMLparam1(self);

const char* result = g_file_info_get_edit_name(GFileInfo_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_g_file_info_get_display_name(value self)
{
CAMLparam1(self);

const char* result = g_file_info_get_display_name(GFileInfo_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_g_file_info_get_content_type(value self)
{
CAMLparam1(self);

const char* result = g_file_info_get_content_type(GFileInfo_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_file_info_get_attribute_uint64(value self, value arg1)
{
CAMLparam2(self, arg1);

guint64 result = g_file_info_get_attribute_uint64(GFileInfo_val(self), String_val(arg1));
CAMLreturn(integers_copy_uint64(result));
}

CAMLexport CAMLprim value ml_g_file_info_get_attribute_uint32(value self, value arg1)
{
CAMLparam2(self, arg1);

guint32 result = g_file_info_get_attribute_uint32(GFileInfo_val(self), String_val(arg1));
CAMLreturn(Val_uint32(result));
}

CAMLexport CAMLprim value ml_g_file_info_get_attribute_type(value self, value arg1)
{
CAMLparam2(self, arg1);

GFileAttributeType result = g_file_info_get_attribute_type(GFileInfo_val(self), String_val(arg1));
CAMLreturn(Val_GioFileAttributeType(result));
}

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_file_info_get_attribute_stringv(value self, value arg1)
{
CAMLparam2(self, arg1);

char** result = g_file_info_get_attribute_stringv(GFileInfo_val(self), String_val(arg1));
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
          }
CAMLreturn(ml_result_opt);
}

#else

CAMLexport CAMLprim value ml_g_file_info_get_attribute_stringv(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FileInfo requires GLib >= 2.22");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_file_info_get_attribute_string(value self, value arg1)
{
CAMLparam2(self, arg1);

const char* result = g_file_info_get_attribute_string(GFileInfo_val(self), String_val(arg1));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_file_info_get_attribute_status(value self, value arg1)
{
CAMLparam2(self, arg1);

GFileAttributeStatus result = g_file_info_get_attribute_status(GFileInfo_val(self), String_val(arg1));
CAMLreturn(Val_GioFileAttributeStatus(result));
}

CAMLexport CAMLprim value ml_g_file_info_get_attribute_object(value self, value arg1)
{
CAMLparam2(self, arg1);

GObject* result = g_file_info_get_attribute_object(GFileInfo_val(self), String_val(arg1));
CAMLreturn(Val_option(result, ml_gobject_val_of_ext));
}

CAMLexport CAMLprim value ml_g_file_info_get_attribute_int64(value self, value arg1)
{
CAMLparam2(self, arg1);

gint64 result = g_file_info_get_attribute_int64(GFileInfo_val(self), String_val(arg1));
CAMLreturn(caml_copy_int64(result));
}

CAMLexport CAMLprim value ml_g_file_info_get_attribute_int32(value self, value arg1)
{
CAMLparam2(self, arg1);

gint32 result = g_file_info_get_attribute_int32(GFileInfo_val(self), String_val(arg1));
CAMLreturn(Val_int32_bounded(result));
}

#if GLIB_CHECK_VERSION(2,78,0)

CAMLexport CAMLprim value ml_g_file_info_get_attribute_file_path(value self, value arg1)
{
CAMLparam2(self, arg1);

const char* result = g_file_info_get_attribute_file_path(GFileInfo_val(self), String_val(arg1));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_file_info_get_attribute_file_path(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FileInfo requires GLib >= 2.78");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_file_info_get_attribute_byte_string(value self, value arg1)
{
CAMLparam2(self, arg1);

const char* result = g_file_info_get_attribute_byte_string(GFileInfo_val(self), String_val(arg1));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_file_info_get_attribute_boolean(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_file_info_get_attribute_boolean(GFileInfo_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_file_info_get_attribute_as_string(value self, value arg1)
{
CAMLparam2(self, arg1);

char* result = g_file_info_get_attribute_as_string(GFileInfo_val(self), String_val(arg1));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_file_info_dup(value self)
{
CAMLparam1(self);

GFileInfo* result = g_file_info_dup(GFileInfo_val(self));
CAMLreturn(Val_GFileInfo(result));
}

CAMLexport CAMLprim value ml_g_file_info_copy_into(value self, value arg1)
{
CAMLparam2(self, arg1);

g_file_info_copy_into(GFileInfo_val(self), GFileInfo_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_info_clear_status(value self)
{
CAMLparam1(self);

g_file_info_clear_status(GFileInfo_val(self));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gio_file_info_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_file_info_get_type()));
}
