/* GENERATED CODE - DO NOT EDIT */
/* C bindings for GridLayout */

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


CAMLexport CAMLprim value ml_gtk_grid_layout_new(value unit)
{
CAMLparam1(unit);

GtkGridLayout *obj = gtk_grid_layout_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkGridLayout(obj));
}
CAMLexport CAMLprim value ml_gtk_grid_layout_set_row_spacing(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_layout_set_row_spacing(GtkGridLayout_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_layout_set_row_homogeneous(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_layout_set_row_homogeneous(GtkGridLayout_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_layout_set_row_baseline_position(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_grid_layout_set_row_baseline_position(GtkGridLayout_val(self), Int_val(arg1), GtkBaselinePosition_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_layout_set_column_spacing(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_layout_set_column_spacing(GtkGridLayout_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_layout_set_column_homogeneous(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_layout_set_column_homogeneous(GtkGridLayout_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_layout_set_baseline_row(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_layout_set_baseline_row(GtkGridLayout_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_layout_get_row_spacing(value self)
{
CAMLparam1(self);

guint result = gtk_grid_layout_get_row_spacing(GtkGridLayout_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_grid_layout_get_row_homogeneous(value self)
{
CAMLparam1(self);

gboolean result = gtk_grid_layout_get_row_homogeneous(GtkGridLayout_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_grid_layout_get_row_baseline_position(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkBaselinePosition result = gtk_grid_layout_get_row_baseline_position(GtkGridLayout_val(self), Int_val(arg1));
CAMLreturn(Val_GtkBaselinePosition(result));
}

CAMLexport CAMLprim value ml_gtk_grid_layout_get_column_spacing(value self)
{
CAMLparam1(self);

guint result = gtk_grid_layout_get_column_spacing(GtkGridLayout_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_grid_layout_get_column_homogeneous(value self)
{
CAMLparam1(self);

gboolean result = gtk_grid_layout_get_column_homogeneous(GtkGridLayout_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_grid_layout_get_baseline_row(value self)
{
CAMLparam1(self);

int result = gtk_grid_layout_get_baseline_row(GtkGridLayout_val(self));
CAMLreturn(Val_int(result));
}

GType gtk_grid_layout_get_type (void);


CAMLprim value ml_gtk_grid_layout_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_grid_layout_get_type()));
}
