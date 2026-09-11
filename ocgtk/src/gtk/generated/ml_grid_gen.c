/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Grid */

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


CAMLexport CAMLprim value ml_gtk_grid_new(value unit)
{
CAMLparam1(unit);

GtkGrid *obj = gtk_grid_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkGrid(obj));
}
CAMLexport CAMLprim value ml_gtk_grid_set_row_spacing(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_set_row_spacing(GtkGrid_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_set_row_homogeneous(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_set_row_homogeneous(GtkGrid_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_set_row_baseline_position(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_grid_set_row_baseline_position(GtkGrid_val(self), Int_val(arg1), GtkBaselinePosition_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_set_column_spacing(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_set_column_spacing(GtkGrid_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_set_column_homogeneous(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_set_column_homogeneous(GtkGrid_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_set_baseline_row(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_set_baseline_row(GtkGrid_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_remove_row(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_remove_row(GtkGrid_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_remove_column(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_remove_column(GtkGrid_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_remove(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_remove(GtkGrid_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_query_child(value self, value arg1)
{
CAMLparam2(self, arg1);
int out2;
int out3;
int out4;
int out5;

gtk_grid_query_child(GtkGrid_val(self), GtkWidget_val(arg1), &out2, &out3, &out4, &out5);
CAMLlocal1(ret);
    ret = caml_alloc(4, 0);
    Store_field(ret, 0, Val_int(out2));
    Store_field(ret, 1, Val_int(out3));
    Store_field(ret, 2, Val_int(out4));
    Store_field(ret, 3, Val_int(out5));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_grid_insert_row(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_insert_row(GtkGrid_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_insert_next_to(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_grid_insert_next_to(GtkGrid_val(self), GtkWidget_val(arg1), GtkPositionType_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_insert_column(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_insert_column(GtkGrid_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_get_row_spacing(value self)
{
CAMLparam1(self);

guint result = gtk_grid_get_row_spacing(GtkGrid_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_grid_get_row_homogeneous(value self)
{
CAMLparam1(self);

gboolean result = gtk_grid_get_row_homogeneous(GtkGrid_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_grid_get_row_baseline_position(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkBaselinePosition result = gtk_grid_get_row_baseline_position(GtkGrid_val(self), Int_val(arg1));
CAMLreturn(Val_GtkBaselinePosition(result));
}

CAMLexport CAMLprim value ml_gtk_grid_get_column_spacing(value self)
{
CAMLparam1(self);

guint result = gtk_grid_get_column_spacing(GtkGrid_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_grid_get_column_homogeneous(value self)
{
CAMLparam1(self);

gboolean result = gtk_grid_get_column_homogeneous(GtkGrid_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_grid_get_child_at(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

GtkWidget* result = gtk_grid_get_child_at(GtkGrid_val(self), Int_val(arg1), Int_val(arg2));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_grid_get_baseline_row(value self)
{
CAMLparam1(self);

int result = gtk_grid_get_baseline_row(GtkGrid_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_grid_attach_next_to_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);

gtk_grid_attach_next_to(GtkGrid_val(self), GtkWidget_val(arg1), Option_val(arg2, GtkWidget_val, NULL), GtkPositionType_val(arg3), Int_val(arg4), Int_val(arg5));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gtk_grid_attach_next_to_bytecode(value * argv, int argn)
{
return ml_gtk_grid_attach_next_to_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gtk_grid_attach_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);

gtk_grid_attach(GtkGrid_val(self), GtkWidget_val(arg1), Int_val(arg2), Int_val(arg3), Int_val(arg4), Int_val(arg5));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gtk_grid_attach_bytecode(value * argv, int argn)
{
return ml_gtk_grid_attach_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

GType gtk_grid_get_type (void);


CAMLprim value ml_gtk_grid_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_grid_get_type()));
}
