/* GENERATED CODE - DO NOT EDIT */
/* C bindings for MemoryOutputStream */

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


#if GLIB_CHECK_VERSION(2,36,0)

CAMLexport CAMLprim value ml_g_memory_output_stream_new_resizable(value unit)
{
CAMLparam1(unit);

GMemoryOutputStream *obj = g_memory_output_stream_new_resizable();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GMemoryOutputStream(obj));
}
#else

CAMLexport CAMLprim value ml_g_memory_output_stream_new_resizable(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("MemoryOutputStream requires GLib >= 2.36");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_memory_output_stream_steal_as_bytes(value self)
{
CAMLparam1(self);

GBytes* result = g_memory_output_stream_steal_as_bytes(GMemoryOutputStream_val(self));
CAMLreturn(Val_GBytes(result));
}

#else

CAMLexport CAMLprim value ml_g_memory_output_stream_steal_as_bytes(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MemoryOutputStream requires GLib >= 2.34");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_memory_output_stream_get_size(value self)
{
CAMLparam1(self);

gsize result = g_memory_output_stream_get_size(GMemoryOutputStream_val(self));
CAMLreturn(Val_gsize(result));
}

#if GLIB_CHECK_VERSION(2,18,0)

CAMLexport CAMLprim value ml_g_memory_output_stream_get_data_size(value self)
{
CAMLparam1(self);

gsize result = g_memory_output_stream_get_data_size(GMemoryOutputStream_val(self));
CAMLreturn(Val_gsize(result));
}

#else

CAMLexport CAMLprim value ml_g_memory_output_stream_get_data_size(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MemoryOutputStream requires GLib >= 2.18");
return Val_unit;
}
#endif


CAMLprim value ml_gio_memory_output_stream_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_memory_output_stream_get_type()));
}
