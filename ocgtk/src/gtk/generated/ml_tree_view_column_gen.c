/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TreeViewColumn */

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


CAMLexport CAMLprim value ml_gtk_tree_view_column_new(value unit)
{
CAMLparam1(unit);

GtkTreeViewColumn *obj = gtk_tree_view_column_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkTreeViewColumn(obj));
}
CAMLexport CAMLprim value ml_gtk_tree_view_column_new_with_area(value arg1)
{
CAMLparam1(arg1);

GtkTreeViewColumn *obj = gtk_tree_view_column_new_with_area(GtkCellArea_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkTreeViewColumn(obj));
}
CAMLexport CAMLprim value ml_gtk_tree_view_column_set_widget(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_column_set_widget(GtkTreeViewColumn_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_set_visible(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_column_set_visible(GtkTreeViewColumn_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_set_title(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_column_set_title(GtkTreeViewColumn_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_set_spacing(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_column_set_spacing(GtkTreeViewColumn_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_set_sort_order(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_column_set_sort_order(GtkTreeViewColumn_val(self), GtkSortType_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_set_sort_indicator(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_column_set_sort_indicator(GtkTreeViewColumn_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_set_sort_column_id(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_column_set_sort_column_id(GtkTreeViewColumn_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_set_sizing(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_column_set_sizing(GtkTreeViewColumn_val(self), GtkTreeViewColumnSizing_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_set_resizable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_column_set_resizable(GtkTreeViewColumn_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_set_reorderable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_column_set_reorderable(GtkTreeViewColumn_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_set_min_width(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_column_set_min_width(GtkTreeViewColumn_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_set_max_width(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_column_set_max_width(GtkTreeViewColumn_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_set_fixed_width(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_column_set_fixed_width(GtkTreeViewColumn_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_set_expand(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_column_set_expand(GtkTreeViewColumn_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_set_clickable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_column_set_clickable(GtkTreeViewColumn_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_set_alignment(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_column_set_alignment(GtkTreeViewColumn_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_queue_resize(value self)
{
CAMLparam1(self);

gtk_tree_view_column_queue_resize(GtkTreeViewColumn_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_pack_start(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_tree_view_column_pack_start(GtkTreeViewColumn_val(self), GtkCellRenderer_val(arg1), Bool_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_pack_end(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_tree_view_column_pack_end(GtkTreeViewColumn_val(self), GtkCellRenderer_val(arg1), Bool_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_get_x_offset(value self)
{
CAMLparam1(self);

int result = gtk_tree_view_column_get_x_offset(GtkTreeViewColumn_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_get_width(value self)
{
CAMLparam1(self);

int result = gtk_tree_view_column_get_width(GtkTreeViewColumn_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_get_widget(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_tree_view_column_get_widget(GtkTreeViewColumn_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_get_visible(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_view_column_get_visible(GtkTreeViewColumn_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_get_tree_view(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_tree_view_column_get_tree_view(GtkTreeViewColumn_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_get_title(value self)
{
CAMLparam1(self);

const char* result = gtk_tree_view_column_get_title(GtkTreeViewColumn_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_get_spacing(value self)
{
CAMLparam1(self);

int result = gtk_tree_view_column_get_spacing(GtkTreeViewColumn_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_get_sort_order(value self)
{
CAMLparam1(self);

GtkSortType result = gtk_tree_view_column_get_sort_order(GtkTreeViewColumn_val(self));
CAMLreturn(Val_GtkSortType(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_get_sort_indicator(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_view_column_get_sort_indicator(GtkTreeViewColumn_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_get_sort_column_id(value self)
{
CAMLparam1(self);

int result = gtk_tree_view_column_get_sort_column_id(GtkTreeViewColumn_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_get_sizing(value self)
{
CAMLparam1(self);

GtkTreeViewColumnSizing result = gtk_tree_view_column_get_sizing(GtkTreeViewColumn_val(self));
CAMLreturn(Val_GtkTreeViewColumnSizing(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_get_resizable(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_view_column_get_resizable(GtkTreeViewColumn_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_get_reorderable(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_view_column_get_reorderable(GtkTreeViewColumn_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_get_min_width(value self)
{
CAMLparam1(self);

int result = gtk_tree_view_column_get_min_width(GtkTreeViewColumn_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_get_max_width(value self)
{
CAMLparam1(self);

int result = gtk_tree_view_column_get_max_width(GtkTreeViewColumn_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_get_fixed_width(value self)
{
CAMLparam1(self);

int result = gtk_tree_view_column_get_fixed_width(GtkTreeViewColumn_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_get_expand(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_view_column_get_expand(GtkTreeViewColumn_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_get_clickable(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_view_column_get_clickable(GtkTreeViewColumn_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_get_button(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_tree_view_column_get_button(GtkTreeViewColumn_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkWidget(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_get_alignment(value self)
{
CAMLparam1(self);

float result = gtk_tree_view_column_get_alignment(GtkTreeViewColumn_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_focus_cell(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_column_focus_cell(GtkTreeViewColumn_val(self), GtkCellRenderer_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_clicked(value self)
{
CAMLparam1(self);

gtk_tree_view_column_clicked(GtkTreeViewColumn_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_clear_attributes(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_column_clear_attributes(GtkTreeViewColumn_val(self), GtkCellRenderer_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_clear(value self)
{
CAMLparam1(self);

gtk_tree_view_column_clear(GtkTreeViewColumn_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_cell_set_cell_data(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gtk_tree_view_column_cell_set_cell_data(GtkTreeViewColumn_val(self), GtkTreeModel_val(arg1), GtkTreeIter_val(arg2), Bool_val(arg3), Bool_val(arg4));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_cell_is_visible(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_view_column_cell_is_visible(GtkTreeViewColumn_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_cell_get_size(value self)
{
CAMLparam1(self);
int out1;
int out2;
int out3;
int out4;

gtk_tree_view_column_cell_get_size(GtkTreeViewColumn_val(self), &out1, &out2, &out3, &out4);
CAMLlocal1(ret);
    ret = caml_alloc(4, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    Store_field(ret, 2, Val_int(out3));
    Store_field(ret, 3, Val_int(out4));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_cell_get_position(value self, value arg1)
{
CAMLparam2(self, arg1);
int out2;
int out3;

gboolean result = gtk_tree_view_column_cell_get_position(GtkTreeViewColumn_val(self), GtkCellRenderer_val(arg1), &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_int(out2));
    Store_field(ret, 2, Val_int(out3));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_add_attribute(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_tree_view_column_add_attribute(GtkTreeViewColumn_val(self), GtkCellRenderer_val(arg1), String_val(arg2), Int_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_column_get_cell_area(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTreeViewColumn *obj = (GtkTreeViewColumn *)GtkTreeViewColumn_val(self);
    GtkCellArea *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "cell-area");
if (pspec == NULL) caml_failwith("ml_gtk_tree_view_column_get_cell_area: property 'cell-area' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "cell-area", &prop_gvalue);
          prop_value = (GtkCellArea*)g_value_dup_object(&prop_gvalue);

      result = Val_GtkCellArea(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

GType gtk_tree_view_column_get_type (void);


CAMLprim value ml_gtk_tree_view_column_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_tree_view_column_get_type()));
}
