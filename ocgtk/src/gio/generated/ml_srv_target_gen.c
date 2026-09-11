/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SrvTarget */

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

/* Conversion functions for GSrvTarget (opaque record with hidden fields) */
GSrvTarget *GSrvTarget_val(value v) {
  return (GSrvTarget *)ml_gir_record_ptr_val(v, "GSrvTarget");
}

value Val_GSrvTarget(const GSrvTarget *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(g_srv_target_get_type(), ptr);
}

value Val_GSrvTarget_option(const GSrvTarget *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GSrvTarget(ptr));
}


#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_srv_target_new(value arg1, value arg2, value arg3, value arg4)
{
CAMLparam4(arg1, arg2, arg3, arg4);

GSrvTarget *obj = g_srv_target_new(String_val(arg1), UInt16_val(arg2), UInt16_val(arg3), UInt16_val(arg4));

CAMLreturn(Val_GSrvTarget(obj));
}
#else

CAMLexport CAMLprim value ml_g_srv_target_new(value arg1, value arg2, value arg3, value arg4)
{
CAMLparam4(arg1, arg2, arg3, arg4);
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("SrvTarget requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_srv_target_get_weight(value self)
{
CAMLparam1(self);

guint16 result = g_srv_target_get_weight(GSrvTarget_val(self));
CAMLreturn(Val_uint16(result));
}

#else

CAMLexport CAMLprim value ml_g_srv_target_get_weight(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SrvTarget requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_srv_target_get_priority(value self)
{
CAMLparam1(self);

guint16 result = g_srv_target_get_priority(GSrvTarget_val(self));
CAMLreturn(Val_uint16(result));
}

#else

CAMLexport CAMLprim value ml_g_srv_target_get_priority(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SrvTarget requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_srv_target_get_port(value self)
{
CAMLparam1(self);

guint16 result = g_srv_target_get_port(GSrvTarget_val(self));
CAMLreturn(Val_uint16(result));
}

#else

CAMLexport CAMLprim value ml_g_srv_target_get_port(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SrvTarget requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_srv_target_get_hostname(value self)
{
CAMLparam1(self);

const gchar* result = g_srv_target_get_hostname(GSrvTarget_val(self));
CAMLreturn(caml_copy_string(result));
}

#else

CAMLexport CAMLprim value ml_g_srv_target_get_hostname(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SrvTarget requires GLib >= 2.22");
return Val_unit;
}
#endif

GType g_srv_target_get_type (void);


CAMLprim value ml_gio_srv_target_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_srv_target_get_type()));
}
