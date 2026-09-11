/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TextMark */

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


CAMLexport CAMLprim value ml_gtk_text_mark_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkTextMark *obj = gtk_text_mark_new(String_option_val(arg1), Bool_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkTextMark(obj));
}
CAMLexport CAMLprim value ml_gtk_text_mark_set_visible(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_mark_set_visible(GtkTextMark_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_mark_get_visible(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_mark_get_visible(GtkTextMark_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_mark_get_name(value self)
{
CAMLparam1(self);

const char* result = gtk_text_mark_get_name(GtkTextMark_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_text_mark_get_left_gravity(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_mark_get_left_gravity(GtkTextMark_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_mark_get_deleted(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_mark_get_deleted(GtkTextMark_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_text_mark_get_buffer(value self)
{
CAMLparam1(self);

GtkTextBuffer* result = gtk_text_mark_get_buffer(GtkTextMark_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkTextBuffer));
}

GType gtk_text_mark_get_type (void);


CAMLprim value ml_gtk_text_mark_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_text_mark_get_type()));
}
