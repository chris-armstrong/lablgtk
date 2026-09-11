/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FileIcon */

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


CAMLexport CAMLprim value ml_g_file_icon_new(value arg1)
{
CAMLparam1(arg1);

GFileIcon *obj = g_file_icon_new(GFile_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GFileIcon(obj));
}
CAMLexport CAMLprim value ml_g_file_icon_get_file(value self)
{
CAMLparam1(self);

GFile* result = g_file_icon_get_file(GFileIcon_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GFile(result));
}


CAMLprim value ml_gio_file_icon_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_file_icon_get_type()));
}
