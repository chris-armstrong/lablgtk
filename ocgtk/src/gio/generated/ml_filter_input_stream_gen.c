/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FilterInputStream */

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


CAMLexport CAMLprim value ml_g_filter_input_stream_set_close_base_stream(value self, value arg1)
{
CAMLparam2(self, arg1);

g_filter_input_stream_set_close_base_stream(GFilterInputStream_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_filter_input_stream_get_close_base_stream(value self)
{
CAMLparam1(self);

gboolean result = g_filter_input_stream_get_close_base_stream(GFilterInputStream_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_filter_input_stream_get_base_stream(value self)
{
CAMLparam1(self);

GInputStream* result = g_filter_input_stream_get_base_stream(GFilterInputStream_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GInputStream(result));
}

GType g_filter_input_stream_get_type (void);


CAMLprim value ml_gio_filter_input_stream_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_filter_input_stream_get_type()));
}
