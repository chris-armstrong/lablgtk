/* GENERATED CODE - DO NOT EDIT */
/* C bindings for MemoryInputStream */

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


CAMLexport CAMLprim value ml_g_memory_input_stream_new(value unit)
{
CAMLparam1(unit);

GMemoryInputStream *obj = g_memory_input_stream_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GMemoryInputStream(obj));
}
#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_memory_input_stream_new_from_bytes(value arg1)
{
CAMLparam1(arg1);

GMemoryInputStream *obj = g_memory_input_stream_new_from_bytes(GBytes_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GMemoryInputStream(obj));
}
#else

CAMLexport CAMLprim value ml_g_memory_input_stream_new_from_bytes(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("MemoryInputStream requires GLib >= 2.34");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_memory_input_stream_add_bytes(value self, value arg1)
{
CAMLparam2(self, arg1);

g_memory_input_stream_add_bytes(GMemoryInputStream_val(self), GBytes_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_memory_input_stream_add_bytes(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MemoryInputStream requires GLib >= 2.34");
return Val_unit;
}
#endif

GType g_memory_input_stream_get_type (void);


CAMLprim value ml_gio_memory_input_stream_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_memory_input_stream_get_type()));
}
