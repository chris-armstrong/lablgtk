/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Vfs */

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


#if GLIB_CHECK_VERSION(2,50,0)

CAMLexport CAMLprim value ml_g_vfs_unregister_uri_scheme(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_vfs_unregister_uri_scheme(GVfs_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_vfs_unregister_uri_scheme(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Vfs requires GLib >= 2.50");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_vfs_parse_name(value self, value arg1)
{
CAMLparam2(self, arg1);

GFile* result = g_vfs_parse_name(GVfs_val(self), String_val(arg1));
CAMLreturn(Val_GFile(result));
}

CAMLexport CAMLprim value ml_g_vfs_is_active(value self)
{
CAMLparam1(self);

gboolean result = g_vfs_is_active(GVfs_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_vfs_get_supported_uri_schemes(value self)
{
CAMLparam1(self);

const gchar* const* result = g_vfs_get_supported_uri_schemes(GVfs_val(self));
    int result_length = 0;
    while (result[result_length] != NULL) result_length++;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, caml_copy_string(result[i]));
    }
CAMLreturn(ml_result);
}

CAMLexport CAMLprim value ml_g_vfs_get_file_for_uri(value self, value arg1)
{
CAMLparam2(self, arg1);

GFile* result = g_vfs_get_file_for_uri(GVfs_val(self), String_val(arg1));
CAMLreturn(Val_GFile(result));
}

CAMLexport CAMLprim value ml_g_vfs_get_file_for_path(value self, value arg1)
{
CAMLparam2(self, arg1);

GFile* result = g_vfs_get_file_for_path(GVfs_val(self), String_val(arg1));
CAMLreturn(Val_GFile(result));
}


CAMLprim value ml_gio_vfs_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_vfs_get_type()));
}
