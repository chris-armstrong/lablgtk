/* GENERATED CODE - DO NOT EDIT */
/* C bindings for IOModule */

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


CAMLexport CAMLprim value ml_g_io_module_new(value arg1)
{
CAMLparam1(arg1);

GIOModule *obj = g_io_module_new(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GIOModule(obj));
}

CAMLprim value ml_gio_io_module_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_io_module_get_type()));
}
