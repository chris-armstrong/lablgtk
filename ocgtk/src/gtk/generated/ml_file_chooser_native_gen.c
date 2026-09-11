/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FileChooserNative */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"
#include "converters.h"

#include <gtk/gtk.h>
/* Include library-specific type conversions and forward declarations */
#include "gtk_decls.h"


CAMLexport CAMLprim value ml_gtk_file_chooser_native_new(value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);

GtkFileChooserNative *obj = gtk_file_chooser_native_new(String_option_val(arg1), Option_val(arg2, GtkWindow_val, NULL), GtkFileChooserAction_val(arg3), String_option_val(arg4), String_option_val(arg5));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkFileChooserNative(obj));
}
CAMLexport CAMLprim value ml_gtk_file_chooser_native_set_cancel_label(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_chooser_native_set_cancel_label(GtkFileChooserNative_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_chooser_native_set_accept_label(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_chooser_native_set_accept_label(GtkFileChooserNative_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_chooser_native_get_cancel_label(value self)
{
CAMLparam1(self);

const char* result = gtk_file_chooser_native_get_cancel_label(GtkFileChooserNative_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_file_chooser_native_get_accept_label(value self)
{
CAMLparam1(self);

const char* result = gtk_file_chooser_native_get_accept_label(GtkFileChooserNative_val(self));
CAMLreturn(Val_option_string(result));
}


CAMLprim value ml_gtk_file_chooser_native_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_file_chooser_native_get_type()));
}
