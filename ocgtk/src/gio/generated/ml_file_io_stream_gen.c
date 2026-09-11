/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FileIOStream */

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


CAMLexport CAMLprim value ml_g_file_io_stream_query_info_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GFileInfo* result = g_file_io_stream_query_info_finish(GFileIOStream_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GFileInfo(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_file_io_stream_query_info(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

GFileInfo* result = g_file_io_stream_query_info(GFileIOStream_val(self), String_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GFileInfo(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_file_io_stream_get_etag(value self)
{
CAMLparam1(self);

char* result = g_file_io_stream_get_etag(GFileIOStream_val(self));
CAMLreturn(Val_option_string(result));
}

GType g_file_io_stream_get_type (void);


CAMLprim value ml_gio_file_io_stream_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_file_io_stream_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_file_io_stream_get_etag(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FileIOStream requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_file_io_stream_query_info(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("FileIOStream requires GLib >= 2.22");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_file_io_stream_query_info_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FileIOStream requires GLib >= 2.22");
return Val_unit;
}


#endif
