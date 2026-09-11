/* GENERATED CODE - DO NOT EDIT */
/* C bindings for IOStream */

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

#if GLIB_CHECK_VERSION(2,22,0)


CAMLexport CAMLprim value ml_g_io_stream_set_pending(value self)
{
CAMLparam1(self);
GError *error = NULL;

gboolean result = g_io_stream_set_pending(GIOStream_val(self), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_io_stream_is_closed(value self)
{
CAMLparam1(self);

gboolean result = g_io_stream_is_closed(GIOStream_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_io_stream_has_pending(value self)
{
CAMLparam1(self);

gboolean result = g_io_stream_has_pending(GIOStream_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_io_stream_get_output_stream(value self)
{
CAMLparam1(self);

GOutputStream* result = g_io_stream_get_output_stream(GIOStream_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GOutputStream(result));
}

CAMLexport CAMLprim value ml_g_io_stream_get_input_stream(value self)
{
CAMLparam1(self);

GInputStream* result = g_io_stream_get_input_stream(GIOStream_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GInputStream(result));
}

CAMLexport CAMLprim value ml_g_io_stream_close_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_io_stream_close_finish(GIOStream_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_io_stream_close(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_io_stream_close(GIOStream_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_io_stream_clear_pending(value self)
{
CAMLparam1(self);

g_io_stream_clear_pending(GIOStream_val(self));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gio_io_stream_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_io_stream_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_io_stream_clear_pending(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("IOStream requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_io_stream_close(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("IOStream requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_io_stream_close_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("IOStream requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_io_stream_get_input_stream(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("IOStream requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_io_stream_get_output_stream(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("IOStream requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_io_stream_has_pending(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("IOStream requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_io_stream_is_closed(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("IOStream requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_io_stream_set_pending(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("IOStream requires GLib >= 2.22");
return Val_unit;
}


#endif
