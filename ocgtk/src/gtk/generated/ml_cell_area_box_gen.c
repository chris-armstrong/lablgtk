/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CellAreaBox */

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


CAMLexport CAMLprim value ml_gtk_cell_area_box_new(value unit)
{
CAMLparam1(unit);

GtkCellAreaBox *obj = gtk_cell_area_box_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkCellAreaBox(obj));
}
CAMLexport CAMLprim value ml_gtk_cell_area_box_set_spacing(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_cell_area_box_set_spacing(GtkCellAreaBox_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_area_box_pack_start(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gtk_cell_area_box_pack_start(GtkCellAreaBox_val(self), GtkCellRenderer_val(arg1), Bool_val(arg2), Bool_val(arg3), Bool_val(arg4));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_area_box_pack_end(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gtk_cell_area_box_pack_end(GtkCellAreaBox_val(self), GtkCellRenderer_val(arg1), Bool_val(arg2), Bool_val(arg3), Bool_val(arg4));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_area_box_get_spacing(value self)
{
CAMLparam1(self);

int result = gtk_cell_area_box_get_spacing(GtkCellAreaBox_val(self));
CAMLreturn(Val_int(result));
}


CAMLprim value ml_gtk_cell_area_box_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_cell_area_box_get_type()));
}
