/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Clipboard */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gdk/gdk.h>
/* Include library-specific type conversions and forward declarations */
#include "gdk_decls.h"


CAMLexport CAMLprim value ml_gdk_clipboard_store_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = gdk_clipboard_store_finish(GdkClipboard_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gdk_clipboard_set_value(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_clipboard_set_value(GdkClipboard_val(self), GValue_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_clipboard_set_content(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gdk_clipboard_set_content(GdkClipboard_val(self), Option_val(arg1, GdkContentProvider_val, NULL));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_clipboard_read_value_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

const GValue* result = gdk_clipboard_read_value_finish(GdkClipboard_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GValue_copy(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gdk_clipboard_read_texture_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GdkTexture* result = gdk_clipboard_read_texture_finish(GdkClipboard_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_option(result, Val_GdkTexture))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gdk_clipboard_read_text_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

char* result = gdk_clipboard_read_text_finish(GdkClipboard_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_option_string(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gdk_clipboard_is_local(value self)
{
CAMLparam1(self);

gboolean result = gdk_clipboard_is_local(GdkClipboard_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_clipboard_get_formats(value self)
{
CAMLparam1(self);

GdkContentFormats* result = gdk_clipboard_get_formats(GdkClipboard_val(self));
if (result) result = g_boxed_copy(gdk_content_formats_get_type(), result);
CAMLreturn(Val_GdkContentFormats(result));
}

CAMLexport CAMLprim value ml_gdk_clipboard_get_display(value self)
{
CAMLparam1(self);

GdkDisplay* result = gdk_clipboard_get_display(GdkClipboard_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkDisplay(result));
}

CAMLexport CAMLprim value ml_gdk_clipboard_get_content(value self)
{
CAMLparam1(self);

GdkContentProvider* result = gdk_clipboard_get_content(GdkClipboard_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkContentProvider));
}

GType gdk_clipboard_get_type (void);


CAMLprim value ml_gdk_clipboard_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_clipboard_get_type()));
}
