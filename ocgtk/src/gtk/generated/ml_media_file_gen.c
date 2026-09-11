/* GENERATED CODE - DO NOT EDIT */
/* C bindings for MediaFile */

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


CAMLexport CAMLprim value ml_gtk_media_file_new(value unit)
{
CAMLparam1(unit);

GtkMediaFile *obj = gtk_media_file_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkMediaFile(obj));
}
CAMLexport CAMLprim value ml_gtk_media_file_new_for_file(value arg1)
{
CAMLparam1(arg1);

GtkMediaFile *obj = gtk_media_file_new_for_file(GFile_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkMediaFile(obj));
}
CAMLexport CAMLprim value ml_gtk_media_file_new_for_filename(value arg1)
{
CAMLparam1(arg1);

GtkMediaFile *obj = gtk_media_file_new_for_filename(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkMediaFile(obj));
}
CAMLexport CAMLprim value ml_gtk_media_file_new_for_input_stream(value arg1)
{
CAMLparam1(arg1);

GtkMediaFile *obj = gtk_media_file_new_for_input_stream(GInputStream_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkMediaFile(obj));
}
CAMLexport CAMLprim value ml_gtk_media_file_new_for_resource(value arg1)
{
CAMLparam1(arg1);

GtkMediaFile *obj = gtk_media_file_new_for_resource(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkMediaFile(obj));
}
CAMLexport CAMLprim value ml_gtk_media_file_set_resource(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_media_file_set_resource(GtkMediaFile_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_media_file_set_input_stream(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_media_file_set_input_stream(GtkMediaFile_val(self), Option_val(arg1, GInputStream_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_media_file_set_filename(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_media_file_set_filename(GtkMediaFile_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_media_file_set_file(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_media_file_set_file(GtkMediaFile_val(self), Option_val(arg1, GFile_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_media_file_get_input_stream(value self)
{
CAMLparam1(self);

GInputStream* result = gtk_media_file_get_input_stream(GtkMediaFile_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GInputStream));
}

CAMLexport CAMLprim value ml_gtk_media_file_get_file(value self)
{
CAMLparam1(self);

GFile* result = gtk_media_file_get_file(GtkMediaFile_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GFile));
}

CAMLexport CAMLprim value ml_gtk_media_file_clear(value self)
{
CAMLparam1(self);

gtk_media_file_clear(GtkMediaFile_val(self));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_media_file_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_media_file_get_type()));
}
