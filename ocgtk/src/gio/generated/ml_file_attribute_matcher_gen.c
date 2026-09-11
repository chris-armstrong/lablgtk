/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FileAttributeMatcher */

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

/* Conversion functions for GFileAttributeMatcher (opaque record with hidden fields) */
GFileAttributeMatcher *GFileAttributeMatcher_val(value v) {
  return (GFileAttributeMatcher *)ml_gir_record_ptr_val(v, "GFileAttributeMatcher");
}

value Val_GFileAttributeMatcher(const GFileAttributeMatcher *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(g_file_attribute_matcher_get_type(), ptr);
}

value Val_GFileAttributeMatcher_option(const GFileAttributeMatcher *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GFileAttributeMatcher(ptr));
}


CAMLexport CAMLprim value ml_g_file_attribute_matcher_new(value arg1)
{
CAMLparam1(arg1);

GFileAttributeMatcher *obj = g_file_attribute_matcher_new(String_val(arg1));

CAMLreturn(Val_GFileAttributeMatcher(obj));
}
#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_file_attribute_matcher_to_string(value self)
{
CAMLparam1(self);

char* result = g_file_attribute_matcher_to_string(GFileAttributeMatcher_val(self));
CAMLreturn(caml_copy_string(result));
}

#else

CAMLexport CAMLprim value ml_g_file_attribute_matcher_to_string(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FileAttributeMatcher requires GLib >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_file_attribute_matcher_subtract(value self, value arg1)
{
CAMLparam2(self, arg1);

GFileAttributeMatcher* result = g_file_attribute_matcher_subtract(GFileAttributeMatcher_val(self), Option_val(arg1, GFileAttributeMatcher_val, NULL));
CAMLreturn(Val_option(result, Val_GFileAttributeMatcher));
}

CAMLexport CAMLprim value ml_g_file_attribute_matcher_ref(value self)
{
CAMLparam1(self);

GFileAttributeMatcher* result = g_file_attribute_matcher_ref(GFileAttributeMatcher_val(self));
CAMLreturn(Val_GFileAttributeMatcher(result));
}

CAMLexport CAMLprim value ml_g_file_attribute_matcher_matches_only(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_file_attribute_matcher_matches_only(GFileAttributeMatcher_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_file_attribute_matcher_matches(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_file_attribute_matcher_matches(GFileAttributeMatcher_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_file_attribute_matcher_enumerate_next(value self)
{
CAMLparam1(self);

const char* result = g_file_attribute_matcher_enumerate_next(GFileAttributeMatcher_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_file_attribute_matcher_enumerate_namespace(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_file_attribute_matcher_enumerate_namespace(GFileAttributeMatcher_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

GType g_file_attribute_matcher_get_type (void);


CAMLprim value ml_gio_file_attribute_matcher_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_file_attribute_matcher_get_type()));
}
