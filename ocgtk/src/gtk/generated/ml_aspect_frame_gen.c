/* GENERATED CODE - DO NOT EDIT */
/* C bindings for AspectFrame */

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


CAMLexport CAMLprim value ml_gtk_aspect_frame_new(value arg1, value arg2, value arg3, value arg4)
{
CAMLparam4(arg1, arg2, arg3, arg4);

GtkAspectFrame *obj = gtk_aspect_frame_new(Double_val(arg1), Double_val(arg2), Double_val(arg3), Bool_val(arg4));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkAspectFrame(obj));
}
CAMLexport CAMLprim value ml_gtk_aspect_frame_set_yalign(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_aspect_frame_set_yalign(GtkAspectFrame_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_aspect_frame_set_xalign(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_aspect_frame_set_xalign(GtkAspectFrame_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_aspect_frame_set_ratio(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_aspect_frame_set_ratio(GtkAspectFrame_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_aspect_frame_set_obey_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_aspect_frame_set_obey_child(GtkAspectFrame_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_aspect_frame_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_aspect_frame_set_child(GtkAspectFrame_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_aspect_frame_get_yalign(value self)
{
CAMLparam1(self);

float result = gtk_aspect_frame_get_yalign(GtkAspectFrame_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_aspect_frame_get_xalign(value self)
{
CAMLparam1(self);

float result = gtk_aspect_frame_get_xalign(GtkAspectFrame_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_aspect_frame_get_ratio(value self)
{
CAMLparam1(self);

float result = gtk_aspect_frame_get_ratio(GtkAspectFrame_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_aspect_frame_get_obey_child(value self)
{
CAMLparam1(self);

gboolean result = gtk_aspect_frame_get_obey_child(GtkAspectFrame_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_aspect_frame_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_aspect_frame_get_child(GtkAspectFrame_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

GType gtk_aspect_frame_get_type (void);


CAMLprim value ml_gtk_aspect_frame_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_aspect_frame_get_type()));
}
