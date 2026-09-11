/* GENERATED CODE - DO NOT EDIT */
/* C bindings for LayoutChild */

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


CAMLexport CAMLprim value ml_gtk_layout_child_get_layout_manager(value self)
{
CAMLparam1(self);

GtkLayoutManager* result = gtk_layout_child_get_layout_manager(GtkLayoutChild_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkLayoutManager(result));
}

CAMLexport CAMLprim value ml_gtk_layout_child_get_child_widget(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_layout_child_get_child_widget(GtkLayoutChild_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkWidget(result));
}


CAMLprim value ml_gtk_layout_child_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_layout_child_get_type()));
}
