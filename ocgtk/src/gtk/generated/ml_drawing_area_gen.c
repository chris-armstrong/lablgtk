/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DrawingArea */

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


CAMLexport CAMLprim value ml_gtk_drawing_area_new(value unit)
{
CAMLparam1(unit);

GtkDrawingArea *obj = gtk_drawing_area_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkDrawingArea(obj));
}
CAMLexport CAMLprim value ml_gtk_drawing_area_set_content_width(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_drawing_area_set_content_width(GtkDrawingArea_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_drawing_area_set_content_height(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_drawing_area_set_content_height(GtkDrawingArea_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_drawing_area_get_content_width(value self)
{
CAMLparam1(self);

int result = gtk_drawing_area_get_content_width(GtkDrawingArea_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_drawing_area_get_content_height(value self)
{
CAMLparam1(self);

int result = gtk_drawing_area_get_content_height(GtkDrawingArea_val(self));
CAMLreturn(Val_int(result));
}

GType gtk_drawing_area_get_type (void);


CAMLprim value ml_gtk_drawing_area_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_drawing_area_get_type()));
}
