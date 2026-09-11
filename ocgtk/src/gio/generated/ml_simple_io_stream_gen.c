/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SimpleIOStream */

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

#if GLIB_CHECK_VERSION(2,44,0)


CAMLexport CAMLprim value ml_g_simple_io_stream_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GSimpleIOStream *obj = g_simple_io_stream_new(GInputStream_val(arg1), GOutputStream_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GSimpleIOStream(obj));
}
CAMLexport CAMLprim value ml_g_simple_io_stream_get_input_stream(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GSimpleIOStream *obj = (GSimpleIOStream *)GSimpleIOStream_val(self);
    GInputStream *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "input-stream");
if (pspec == NULL) caml_failwith("ml_g_simple_io_stream_get_input_stream: property 'input-stream' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "input-stream", &prop_gvalue);
          prop_value = (GInputStream*)g_value_dup_object(&prop_gvalue);

      result = Val_GInputStream(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_g_simple_io_stream_get_output_stream(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GSimpleIOStream *obj = (GSimpleIOStream *)GSimpleIOStream_val(self);
    GOutputStream *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "output-stream");
if (pspec == NULL) caml_failwith("ml_g_simple_io_stream_get_output_stream: property 'output-stream' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "output-stream", &prop_gvalue);
          prop_value = (GOutputStream*)g_value_dup_object(&prop_gvalue);

      result = Val_GOutputStream(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}


CAMLprim value ml_gio_simple_io_stream_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_simple_io_stream_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_simple_io_stream_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("SimpleIOStream requires GLib >= 2.44");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_simple_io_stream_get_input_stream(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SimpleIOStream requires GLib >= 2.44");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_simple_io_stream_get_output_stream(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SimpleIOStream requires GLib >= 2.44");
return Val_unit;
}


#endif
