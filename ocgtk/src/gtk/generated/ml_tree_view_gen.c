/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TreeView */

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


CAMLexport CAMLprim value ml_gtk_tree_view_new(value unit)
{
CAMLparam1(unit);

GtkTreeView *obj = gtk_tree_view_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkTreeView(obj));
}
CAMLexport CAMLprim value ml_gtk_tree_view_new_with_model(value arg1)
{
CAMLparam1(arg1);

GtkTreeView *obj = gtk_tree_view_new_with_model(GtkTreeModel_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkTreeView(obj));
}
CAMLexport CAMLprim value ml_gtk_tree_view_unset_rows_drag_source(value self)
{
CAMLparam1(self);

gtk_tree_view_unset_rows_drag_source(GtkTreeView_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_unset_rows_drag_dest(value self)
{
CAMLparam1(self);

gtk_tree_view_unset_rows_drag_dest(GtkTreeView_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_tooltip_row(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_tree_view_set_tooltip_row(GtkTreeView_val(self), GtkTooltip_val(arg1), GtkTreePath_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_tooltip_column(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_set_tooltip_column(GtkTreeView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_tooltip_cell(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gtk_tree_view_set_tooltip_cell(GtkTreeView_val(self), GtkTooltip_val(arg1), Option_val(arg2, GtkTreePath_val, NULL), Option_val(arg3, GtkTreeViewColumn_val, NULL), Option_val(arg4, GtkCellRenderer_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_show_expanders(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_set_show_expanders(GtkTreeView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_search_entry(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_set_search_entry(GtkTreeView_val(self), Option_val(arg1, GtkEditable_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_search_column(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_set_search_column(GtkTreeView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_rubber_banding(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_set_rubber_banding(GtkTreeView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_reorderable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_set_reorderable(GtkTreeView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_model(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_set_model(GtkTreeView_val(self), Option_val(arg1, GtkTreeModel_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_level_indentation(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_set_level_indentation(GtkTreeView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_hover_selection(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_set_hover_selection(GtkTreeView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_hover_expand(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_set_hover_expand(GtkTreeView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_headers_visible(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_set_headers_visible(GtkTreeView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_headers_clickable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_set_headers_clickable(GtkTreeView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_grid_lines(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_set_grid_lines(GtkTreeView_val(self), GtkTreeViewGridLines_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_fixed_height_mode(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_set_fixed_height_mode(GtkTreeView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_expander_column(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_set_expander_column(GtkTreeView_val(self), Option_val(arg1, GtkTreeViewColumn_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_enable_tree_lines(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_set_enable_tree_lines(GtkTreeView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_enable_search(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_set_enable_search(GtkTreeView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_drag_dest_row(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_tree_view_set_drag_dest_row(GtkTreeView_val(self), Option_val(arg1, GtkTreePath_val, NULL), GtkTreeViewDropPosition_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_cursor_on_cell(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gtk_tree_view_set_cursor_on_cell(GtkTreeView_val(self), GtkTreePath_val(arg1), Option_val(arg2, GtkTreeViewColumn_val, NULL), Option_val(arg3, GtkCellRenderer_val, NULL), Bool_val(arg4));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_cursor(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_tree_view_set_cursor(GtkTreeView_val(self), GtkTreePath_val(arg1), Option_val(arg2, GtkTreeViewColumn_val, NULL), Bool_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_set_activate_on_single_click(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_set_activate_on_single_click(GtkTreeView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_scroll_to_point(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_tree_view_scroll_to_point(GtkTreeView_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_scroll_to_cell_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);

gtk_tree_view_scroll_to_cell(GtkTreeView_val(self), Option_val(arg1, GtkTreePath_val, NULL), Option_val(arg2, GtkTreeViewColumn_val, NULL), Bool_val(arg3), Double_val(arg4), Double_val(arg5));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gtk_tree_view_scroll_to_cell_bytecode(value * argv, int argn)
{
return ml_gtk_tree_view_scroll_to_cell_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gtk_tree_view_row_expanded(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_tree_view_row_expanded(GtkTreeView_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_row_activated(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_tree_view_row_activated(GtkTreeView_val(self), GtkTreePath_val(arg1), Option_val(arg2, GtkTreeViewColumn_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_remove_column(value self, value arg1)
{
CAMLparam2(self, arg1);

int result = gtk_tree_view_remove_column(GtkTreeView_val(self), GtkTreeViewColumn_val(arg1));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_move_column_after(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_tree_view_move_column_after(GtkTreeView_val(self), GtkTreeViewColumn_val(arg1), Option_val(arg2, GtkTreeViewColumn_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_is_rubber_banding_active(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_view_is_rubber_banding_active(GtkTreeView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_insert_column(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

int result = gtk_tree_view_insert_column(GtkTreeView_val(self), GtkTreeViewColumn_val(arg1), Int_val(arg2));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_visible_rect(value self)
{
CAMLparam1(self);
GdkRectangle out1;

gtk_tree_view_get_visible_rect(GtkTreeView_val(self), &out1);
CAMLreturn(Val_GdkRectangle(&out1));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_tooltip_column(value self)
{
CAMLparam1(self);

int result = gtk_tree_view_get_tooltip_column(GtkTreeView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_show_expanders(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_view_get_show_expanders(GtkTreeView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_selection(value self)
{
CAMLparam1(self);

GtkTreeSelection* result = gtk_tree_view_get_selection(GtkTreeView_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkTreeSelection(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_search_entry(value self)
{
CAMLparam1(self);

GtkEditable* result = gtk_tree_view_get_search_entry(GtkTreeView_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkEditable));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_search_column(value self)
{
CAMLparam1(self);

int result = gtk_tree_view_get_search_column(GtkTreeView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_rubber_banding(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_view_get_rubber_banding(GtkTreeView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_reorderable(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_view_get_reorderable(GtkTreeView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_n_columns(value self)
{
CAMLparam1(self);

guint result = gtk_tree_view_get_n_columns(GtkTreeView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_model(value self)
{
CAMLparam1(self);

GtkTreeModel* result = gtk_tree_view_get_model(GtkTreeView_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkTreeModel));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_level_indentation(value self)
{
CAMLparam1(self);

int result = gtk_tree_view_get_level_indentation(GtkTreeView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_hover_selection(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_view_get_hover_selection(GtkTreeView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_hover_expand(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_view_get_hover_expand(GtkTreeView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_headers_visible(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_view_get_headers_visible(GtkTreeView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_headers_clickable(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_view_get_headers_clickable(GtkTreeView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_grid_lines(value self)
{
CAMLparam1(self);

GtkTreeViewGridLines result = gtk_tree_view_get_grid_lines(GtkTreeView_val(self));
CAMLreturn(Val_GtkTreeViewGridLines(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_fixed_height_mode(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_view_get_fixed_height_mode(GtkTreeView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_expander_column(value self)
{
CAMLparam1(self);

GtkTreeViewColumn* result = gtk_tree_view_get_expander_column(GtkTreeView_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkTreeViewColumn));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_enable_tree_lines(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_view_get_enable_tree_lines(GtkTreeView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_enable_search(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_view_get_enable_search(GtkTreeView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_columns(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = gtk_tree_view_get_columns(GtkTreeView_val(self));
Val_GList_with(c_result, result, item, cell, Val_GtkTreeViewColumn((gpointer)_tmp->data));
    g_list_free(c_result);
    CAMLreturn(result);
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_column(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkTreeViewColumn* result = gtk_tree_view_get_column(GtkTreeView_val(self), Int_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkTreeViewColumn));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_cell_area(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GdkRectangle out3;

gtk_tree_view_get_cell_area(GtkTreeView_val(self), Option_val(arg1, GtkTreePath_val, NULL), Option_val(arg2, GtkTreeViewColumn_val, NULL), &out3);
CAMLreturn(Val_GdkRectangle(&out3));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_background_area(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GdkRectangle out3;

gtk_tree_view_get_background_area(GtkTreeView_val(self), Option_val(arg1, GtkTreePath_val, NULL), Option_val(arg2, GtkTreeViewColumn_val, NULL), &out3);
CAMLreturn(Val_GdkRectangle(&out3));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_activate_on_single_click(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_view_get_activate_on_single_click(GtkTreeView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_expand_to_path(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_view_expand_to_path(GtkTreeView_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_expand_row(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gtk_tree_view_expand_row(GtkTreeView_val(self), GtkTreePath_val(arg1), Bool_val(arg2));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_expand_all(value self)
{
CAMLparam1(self);

gtk_tree_view_expand_all(GtkTreeView_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_enable_model_drag_source(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_tree_view_enable_model_drag_source(GtkTreeView_val(self), GdkModifierType_val(arg1), GdkContentFormats_val(arg2), GdkDragAction_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_enable_model_drag_dest(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_tree_view_enable_model_drag_dest(GtkTreeView_val(self), GdkContentFormats_val(arg1), GdkDragAction_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_create_row_drag_icon(value self, value arg1)
{
CAMLparam2(self, arg1);

GdkPaintable* result = gtk_tree_view_create_row_drag_icon(GtkTreeView_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_option(result, Val_GdkPaintable));
}

CAMLexport CAMLprim value ml_gtk_tree_view_convert_widget_to_tree_coords(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
int out3;
int out4;

gtk_tree_view_convert_widget_to_tree_coords(GtkTreeView_val(self), Int_val(arg1), Int_val(arg2), &out3, &out4);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out3));
    Store_field(ret, 1, Val_int(out4));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_tree_view_convert_widget_to_bin_window_coords(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
int out3;
int out4;

gtk_tree_view_convert_widget_to_bin_window_coords(GtkTreeView_val(self), Int_val(arg1), Int_val(arg2), &out3, &out4);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out3));
    Store_field(ret, 1, Val_int(out4));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_tree_view_convert_tree_to_widget_coords(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
int out3;
int out4;

gtk_tree_view_convert_tree_to_widget_coords(GtkTreeView_val(self), Int_val(arg1), Int_val(arg2), &out3, &out4);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out3));
    Store_field(ret, 1, Val_int(out4));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_tree_view_convert_tree_to_bin_window_coords(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
int out3;
int out4;

gtk_tree_view_convert_tree_to_bin_window_coords(GtkTreeView_val(self), Int_val(arg1), Int_val(arg2), &out3, &out4);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out3));
    Store_field(ret, 1, Val_int(out4));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_tree_view_convert_bin_window_to_widget_coords(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
int out3;
int out4;

gtk_tree_view_convert_bin_window_to_widget_coords(GtkTreeView_val(self), Int_val(arg1), Int_val(arg2), &out3, &out4);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out3));
    Store_field(ret, 1, Val_int(out4));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_tree_view_convert_bin_window_to_tree_coords(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
int out3;
int out4;

gtk_tree_view_convert_bin_window_to_tree_coords(GtkTreeView_val(self), Int_val(arg1), Int_val(arg2), &out3, &out4);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out3));
    Store_field(ret, 1, Val_int(out4));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_tree_view_columns_autosize(value self)
{
CAMLparam1(self);

gtk_tree_view_columns_autosize(GtkTreeView_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_collapse_row(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_tree_view_collapse_row(GtkTreeView_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_collapse_all(value self)
{
CAMLparam1(self);

gtk_tree_view_collapse_all(GtkTreeView_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_view_append_column(value self, value arg1)
{
CAMLparam2(self, arg1);

int result = gtk_tree_view_append_column(GtkTreeView_val(self), GtkTreeViewColumn_val(arg1));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_tree_view_get_enable_grid_lines(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTreeView *obj = (GtkTreeView *)GtkTreeView_val(self);
    GtkTreeViewGridLines prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "enable-grid-lines");
if (pspec == NULL) caml_failwith("ml_gtk_tree_view_get_enable_grid_lines: property 'enable-grid-lines' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "enable-grid-lines", &prop_gvalue);
          prop_value = (GtkTreeViewGridLines)g_value_get_enum(&prop_gvalue);

      result = Val_GtkTreeViewGridLines(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_tree_view_set_enable_grid_lines(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTreeView *obj = (GtkTreeView *)GtkTreeView_val(self);
    GtkTreeViewGridLines c_value = GtkTreeViewGridLines_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "enable-grid-lines");
if (pspec == NULL) caml_failwith("ml_gtk_tree_view_set_enable_grid_lines: property 'enable-grid-lines' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "enable-grid-lines", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_tree_view_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_tree_view_get_type()));
}
