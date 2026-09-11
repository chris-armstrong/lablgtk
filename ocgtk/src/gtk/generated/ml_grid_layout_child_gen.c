/* GENERATED CODE - DO NOT EDIT */
/* C bindings for GridLayoutChild */

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


CAMLexport CAMLprim value ml_gtk_grid_layout_child_set_row_span(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_layout_child_set_row_span(GtkGridLayoutChild_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_layout_child_set_row(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_layout_child_set_row(GtkGridLayoutChild_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_layout_child_set_column_span(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_layout_child_set_column_span(GtkGridLayoutChild_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_layout_child_set_column(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_layout_child_set_column(GtkGridLayoutChild_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_layout_child_get_row_span(value self)
{
CAMLparam1(self);

int result = gtk_grid_layout_child_get_row_span(GtkGridLayoutChild_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_grid_layout_child_get_row(value self)
{
CAMLparam1(self);

int result = gtk_grid_layout_child_get_row(GtkGridLayoutChild_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_grid_layout_child_get_column_span(value self)
{
CAMLparam1(self);

int result = gtk_grid_layout_child_get_column_span(GtkGridLayoutChild_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_grid_layout_child_get_column(value self)
{
CAMLparam1(self);

int result = gtk_grid_layout_child_get_column(GtkGridLayoutChild_val(self));
CAMLreturn(Val_int(result));
}

GType gtk_grid_layout_child_get_type (void);


CAMLprim value ml_gtk_grid_layout_child_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_grid_layout_child_get_type()));
}
