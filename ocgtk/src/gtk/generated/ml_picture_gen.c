/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Picture */

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


CAMLexport CAMLprim value ml_gtk_picture_new(value unit)
{
CAMLparam1(unit);

GtkPicture *obj = gtk_picture_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkPicture(obj));
}
CAMLexport CAMLprim value ml_gtk_picture_new_for_file(value arg1)
{
CAMLparam1(arg1);

GtkPicture *obj = gtk_picture_new_for_file(Option_val(arg1, GFile_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkPicture(obj));
}
CAMLexport CAMLprim value ml_gtk_picture_new_for_filename(value arg1)
{
CAMLparam1(arg1);

GtkPicture *obj = gtk_picture_new_for_filename(String_option_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkPicture(obj));
}
CAMLexport CAMLprim value ml_gtk_picture_new_for_paintable(value arg1)
{
CAMLparam1(arg1);

GtkPicture *obj = gtk_picture_new_for_paintable(Option_val(arg1, GdkPaintable_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkPicture(obj));
}
CAMLexport CAMLprim value ml_gtk_picture_new_for_pixbuf(value arg1)
{
CAMLparam1(arg1);

GtkPicture *obj = gtk_picture_new_for_pixbuf(Option_val(arg1, GdkPixbuf_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkPicture(obj));
}
CAMLexport CAMLprim value ml_gtk_picture_new_for_resource(value arg1)
{
CAMLparam1(arg1);

GtkPicture *obj = gtk_picture_new_for_resource(String_option_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkPicture(obj));
}
CAMLexport CAMLprim value ml_gtk_picture_set_resource(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_picture_set_resource(GtkPicture_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_picture_set_pixbuf(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_picture_set_pixbuf(GtkPicture_val(self), Option_val(arg1, GdkPixbuf_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_picture_set_paintable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_picture_set_paintable(GtkPicture_val(self), Option_val(arg1, GdkPaintable_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_picture_set_keep_aspect_ratio(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_picture_set_keep_aspect_ratio(GtkPicture_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_picture_set_filename(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_picture_set_filename(GtkPicture_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_picture_set_file(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_picture_set_file(GtkPicture_val(self), Option_val(arg1, GFile_val, NULL));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,8,0)

CAMLexport CAMLprim value ml_gtk_picture_set_content_fit(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_picture_set_content_fit(GtkPicture_val(self), GtkContentFit_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_picture_set_content_fit(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Picture requires GTK >= 4.8");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_picture_set_can_shrink(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_picture_set_can_shrink(GtkPicture_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_picture_set_alternative_text(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_picture_set_alternative_text(GtkPicture_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_picture_get_paintable(value self)
{
CAMLparam1(self);

GdkPaintable* result = gtk_picture_get_paintable(GtkPicture_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkPaintable));
}

CAMLexport CAMLprim value ml_gtk_picture_get_keep_aspect_ratio(value self)
{
CAMLparam1(self);

gboolean result = gtk_picture_get_keep_aspect_ratio(GtkPicture_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_picture_get_file(value self)
{
CAMLparam1(self);

GFile* result = gtk_picture_get_file(GtkPicture_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GFile));
}

#if GTK_CHECK_VERSION(4,8,0)

CAMLexport CAMLprim value ml_gtk_picture_get_content_fit(value self)
{
CAMLparam1(self);

GtkContentFit result = gtk_picture_get_content_fit(GtkPicture_val(self));
CAMLreturn(Val_GtkContentFit(result));
}

#else

CAMLexport CAMLprim value ml_gtk_picture_get_content_fit(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Picture requires GTK >= 4.8");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_picture_get_can_shrink(value self)
{
CAMLparam1(self);

gboolean result = gtk_picture_get_can_shrink(GtkPicture_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_picture_get_alternative_text(value self)
{
CAMLparam1(self);

const char* result = gtk_picture_get_alternative_text(GtkPicture_val(self));
CAMLreturn(Val_option_string(result));
}


CAMLprim value ml_gtk_picture_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_picture_get_type()));
}
