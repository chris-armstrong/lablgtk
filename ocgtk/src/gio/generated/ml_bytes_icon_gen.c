/* GENERATED CODE - DO NOT EDIT */
/* C bindings for BytesIcon */

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

#if GLIB_CHECK_VERSION(2,38,0)


CAMLexport CAMLprim value ml_g_bytes_icon_new(value arg1)
{
CAMLparam1(arg1);

GBytesIcon *obj = g_bytes_icon_new(GBytes_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GBytesIcon(obj));
}
CAMLexport CAMLprim value ml_g_bytes_icon_get_bytes(value self)
{
CAMLparam1(self);

GBytes* result = g_bytes_icon_get_bytes(GBytesIcon_val(self));
CAMLreturn(Val_GBytes(result));
}


CAMLprim value ml_gio_bytes_icon_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_bytes_icon_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_bytes_icon_new(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("BytesIcon requires GLib >= 2.38");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_bytes_icon_get_bytes(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("BytesIcon requires GLib >= 2.38");
return Val_unit;
}


#endif
