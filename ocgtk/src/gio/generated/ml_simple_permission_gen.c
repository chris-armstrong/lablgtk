/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SimplePermission */

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


#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_simple_permission_new(value arg1)
{
CAMLparam1(arg1);

GSimplePermission *obj = g_simple_permission_new(Bool_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GSimplePermission(obj));
}
#else

CAMLexport CAMLprim value ml_g_simple_permission_new(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("SimplePermission requires GLib >= 2.26");
return Val_unit;
}
#endif


CAMLprim value ml_gio_simple_permission_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_simple_permission_get_type()));
}
