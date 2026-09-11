/* GENERATED CODE - DO NOT EDIT */
/* C bindings for OverlayLayoutChild */

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


CAMLexport CAMLprim value ml_gtk_overlay_layout_child_set_measure(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_overlay_layout_child_set_measure(GtkOverlayLayoutChild_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_overlay_layout_child_set_clip_overlay(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_overlay_layout_child_set_clip_overlay(GtkOverlayLayoutChild_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_overlay_layout_child_get_measure(value self)
{
CAMLparam1(self);

gboolean result = gtk_overlay_layout_child_get_measure(GtkOverlayLayoutChild_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_overlay_layout_child_get_clip_overlay(value self)
{
CAMLparam1(self);

gboolean result = gtk_overlay_layout_child_get_clip_overlay(GtkOverlayLayoutChild_val(self));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_gtk_overlay_layout_child_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_overlay_layout_child_get_type()));
}
