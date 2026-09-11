/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Scrollbar */

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


CAMLexport CAMLprim value ml_gtk_scrollbar_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkScrollbar *obj = gtk_scrollbar_new(GtkOrientation_val(arg1), Option_val(arg2, GtkAdjustment_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkScrollbar(obj));
}
CAMLexport CAMLprim value ml_gtk_scrollbar_set_adjustment(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scrollbar_set_adjustment(GtkScrollbar_val(self), Option_val(arg1, GtkAdjustment_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scrollbar_get_adjustment(value self)
{
CAMLparam1(self);

GtkAdjustment* result = gtk_scrollbar_get_adjustment(GtkScrollbar_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkAdjustment(result));
}

GType gtk_scrollbar_get_type (void);


CAMLprim value ml_gtk_scrollbar_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_scrollbar_get_type()));
}
