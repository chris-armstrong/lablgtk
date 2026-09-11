/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CellLayout */

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


CAMLexport CAMLprim value ml_gtk_cell_layout_reorder(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_cell_layout_reorder(GtkCellLayout_val(self), GtkCellRenderer_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_layout_pack_start(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_cell_layout_pack_start(GtkCellLayout_val(self), GtkCellRenderer_val(arg1), Bool_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_layout_pack_end(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_cell_layout_pack_end(GtkCellLayout_val(self), GtkCellRenderer_val(arg1), Bool_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_layout_get_cells(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = gtk_cell_layout_get_cells(GtkCellLayout_val(self));
Val_GList_with(c_result, result, item, cell, Val_GtkCellRenderer((gpointer)_tmp->data));
    g_list_free(c_result);
    CAMLreturn(result);
}

CAMLexport CAMLprim value ml_gtk_cell_layout_get_area(value self)
{
CAMLparam1(self);

GtkCellArea* result = gtk_cell_layout_get_area(GtkCellLayout_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkCellArea));
}

CAMLexport CAMLprim value ml_gtk_cell_layout_clear_attributes(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_cell_layout_clear_attributes(GtkCellLayout_val(self), GtkCellRenderer_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_layout_clear(value self)
{
CAMLparam1(self);

gtk_cell_layout_clear(GtkCellLayout_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_layout_add_attribute(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_cell_layout_add_attribute(GtkCellLayout_val(self), GtkCellRenderer_val(arg1), String_val(arg2), Int_val(arg3));
CAMLreturn(Val_unit);
}
CAMLexport CAMLprim value ml_gtk_cell_layout_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GTK_TYPE_CELL_LAYOUT)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GtkCellLayout");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GtkCellLayout((GtkCellLayout*)gobj));
}

GType gtk_cell_layout_get_type (void);


CAMLprim value ml_gtk_cell_layout_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_cell_layout_get_type()));
}
