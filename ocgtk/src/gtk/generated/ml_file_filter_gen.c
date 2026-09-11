/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FileFilter */

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


CAMLexport CAMLprim value ml_gtk_file_filter_new(value unit)
{
CAMLparam1(unit);

GtkFileFilter *obj = gtk_file_filter_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkFileFilter(obj));
}
CAMLexport CAMLprim value ml_gtk_file_filter_new_from_gvariant(value arg1)
{
CAMLparam1(arg1);

GtkFileFilter *obj = gtk_file_filter_new_from_gvariant(GVariant_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkFileFilter(obj));
}
CAMLexport CAMLprim value ml_gtk_file_filter_to_gvariant(value self)
{
CAMLparam1(self);

GVariant* result = gtk_file_filter_to_gvariant(GtkFileFilter_val(self));
if (result) g_variant_ref(result);
CAMLreturn(Val_GVariant(result));
}

CAMLexport CAMLprim value ml_gtk_file_filter_set_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_filter_set_name(GtkFileFilter_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_filter_get_name(value self)
{
CAMLparam1(self);

const char* result = gtk_file_filter_get_name(GtkFileFilter_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_file_filter_get_attributes(value self)
{
CAMLparam1(self);

const char** result = gtk_file_filter_get_attributes(GtkFileFilter_val(self));
    int result_length = 0;
    while (result[result_length] != NULL) result_length++;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, caml_copy_string(result[i]));
    }
CAMLreturn(ml_result);
}

#if GTK_CHECK_VERSION(4,4,0)

CAMLexport CAMLprim value ml_gtk_file_filter_add_suffix(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_filter_add_suffix(GtkFileFilter_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_file_filter_add_suffix(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FileFilter requires GTK >= 4.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_file_filter_add_pixbuf_formats(value self)
{
CAMLparam1(self);

gtk_file_filter_add_pixbuf_formats(GtkFileFilter_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_filter_add_pattern(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_filter_add_pattern(GtkFileFilter_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_filter_add_mime_type(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_filter_add_mime_type(GtkFileFilter_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_file_filter_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_file_filter_get_type()));
}
