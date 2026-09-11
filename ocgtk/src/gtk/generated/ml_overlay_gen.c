/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Overlay */

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


CAMLexport CAMLprim value ml_gtk_overlay_new(value unit)
{
CAMLparam1(unit);

GtkOverlay *obj = gtk_overlay_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkOverlay(obj));
}
CAMLexport CAMLprim value ml_gtk_overlay_set_measure_overlay(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_overlay_set_measure_overlay(GtkOverlay_val(self), GtkWidget_val(arg1), Bool_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_overlay_set_clip_overlay(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_overlay_set_clip_overlay(GtkOverlay_val(self), GtkWidget_val(arg1), Bool_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_overlay_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_overlay_set_child(GtkOverlay_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_overlay_remove_overlay(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_overlay_remove_overlay(GtkOverlay_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_overlay_get_measure_overlay(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_overlay_get_measure_overlay(GtkOverlay_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_overlay_get_clip_overlay(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_overlay_get_clip_overlay(GtkOverlay_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_overlay_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_overlay_get_child(GtkOverlay_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_overlay_add_overlay(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_overlay_add_overlay(GtkOverlay_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_overlay_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_overlay_get_type()));
}
