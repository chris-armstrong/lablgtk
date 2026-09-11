/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Frame */

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


CAMLexport CAMLprim value ml_gtk_frame_new(value arg1)
{
CAMLparam1(arg1);

GtkFrame *obj = gtk_frame_new(String_option_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkFrame(obj));
}
CAMLexport CAMLprim value ml_gtk_frame_set_label_widget(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_frame_set_label_widget(GtkFrame_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_frame_set_label_align(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_frame_set_label_align(GtkFrame_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_frame_set_label(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_frame_set_label(GtkFrame_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_frame_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_frame_set_child(GtkFrame_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_frame_get_label_widget(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_frame_get_label_widget(GtkFrame_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_frame_get_label_align(value self)
{
CAMLparam1(self);

float result = gtk_frame_get_label_align(GtkFrame_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_frame_get_label(value self)
{
CAMLparam1(self);

const char* result = gtk_frame_get_label(GtkFrame_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_frame_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_frame_get_child(GtkFrame_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}


CAMLprim value ml_gtk_frame_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_frame_get_type()));
}
