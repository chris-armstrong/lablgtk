/* GENERATED CODE - DO NOT EDIT */
/* C bindings for IconView */

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


CAMLexport CAMLprim value ml_gtk_icon_view_new(value unit)
{
CAMLparam1(unit);

GtkIconView *obj = gtk_icon_view_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkIconView(obj));
}
CAMLexport CAMLprim value ml_gtk_icon_view_new_with_area(value arg1)
{
CAMLparam1(arg1);

GtkIconView *obj = gtk_icon_view_new_with_area(GtkCellArea_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkIconView(obj));
}
CAMLexport CAMLprim value ml_gtk_icon_view_new_with_model(value arg1)
{
CAMLparam1(arg1);

GtkIconView *obj = gtk_icon_view_new_with_model(GtkTreeModel_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkIconView(obj));
}
CAMLexport CAMLprim value ml_gtk_icon_view_unset_model_drag_source(value self)
{
CAMLparam1(self);

gtk_icon_view_unset_model_drag_source(GtkIconView_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_unset_model_drag_dest(value self)
{
CAMLparam1(self);

gtk_icon_view_unset_model_drag_dest(GtkIconView_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_unselect_path(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_view_unselect_path(GtkIconView_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_unselect_all(value self)
{
CAMLparam1(self);

gtk_icon_view_unselect_all(GtkIconView_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_set_tooltip_item(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_icon_view_set_tooltip_item(GtkIconView_val(self), GtkTooltip_val(arg1), GtkTreePath_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_set_tooltip_column(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_view_set_tooltip_column(GtkIconView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_set_tooltip_cell(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_icon_view_set_tooltip_cell(GtkIconView_val(self), GtkTooltip_val(arg1), GtkTreePath_val(arg2), Option_val(arg3, GtkCellRenderer_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_set_text_column(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_view_set_text_column(GtkIconView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_set_spacing(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_view_set_spacing(GtkIconView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_set_selection_mode(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_view_set_selection_mode(GtkIconView_val(self), GtkSelectionMode_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_set_row_spacing(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_view_set_row_spacing(GtkIconView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_set_reorderable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_view_set_reorderable(GtkIconView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_set_pixbuf_column(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_view_set_pixbuf_column(GtkIconView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_set_model(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_view_set_model(GtkIconView_val(self), Option_val(arg1, GtkTreeModel_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_set_markup_column(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_view_set_markup_column(GtkIconView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_set_margin(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_view_set_margin(GtkIconView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_set_item_width(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_view_set_item_width(GtkIconView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_set_item_padding(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_view_set_item_padding(GtkIconView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_set_item_orientation(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_view_set_item_orientation(GtkIconView_val(self), GtkOrientation_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_set_drag_dest_item(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_icon_view_set_drag_dest_item(GtkIconView_val(self), Option_val(arg1, GtkTreePath_val, NULL), GtkIconViewDropPosition_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_set_cursor(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_icon_view_set_cursor(GtkIconView_val(self), GtkTreePath_val(arg1), Option_val(arg2, GtkCellRenderer_val, NULL), Bool_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_set_columns(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_view_set_columns(GtkIconView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_set_column_spacing(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_view_set_column_spacing(GtkIconView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_set_activate_on_single_click(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_view_set_activate_on_single_click(GtkIconView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_select_path(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_view_select_path(GtkIconView_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_select_all(value self)
{
CAMLparam1(self);

gtk_icon_view_select_all(GtkIconView_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_scroll_to_path(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gtk_icon_view_scroll_to_path(GtkIconView_val(self), GtkTreePath_val(arg1), Bool_val(arg2), Double_val(arg3), Double_val(arg4));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_path_is_selected(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_icon_view_path_is_selected(GtkIconView_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_icon_view_item_activated(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_icon_view_item_activated(GtkIconView_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_tooltip_column(value self)
{
CAMLparam1(self);

int result = gtk_icon_view_get_tooltip_column(GtkIconView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_text_column(value self)
{
CAMLparam1(self);

int result = gtk_icon_view_get_text_column(GtkIconView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_spacing(value self)
{
CAMLparam1(self);

int result = gtk_icon_view_get_spacing(GtkIconView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_selection_mode(value self)
{
CAMLparam1(self);

GtkSelectionMode result = gtk_icon_view_get_selection_mode(GtkIconView_val(self));
CAMLreturn(Val_GtkSelectionMode(result));
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_selected_items(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = gtk_icon_view_get_selected_items(GtkIconView_val(self));
Val_GList_with(c_result, result, item, cell, Val_GtkTreePath((gpointer)_tmp->data));
    g_list_free(c_result);
    CAMLreturn(result);
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_row_spacing(value self)
{
CAMLparam1(self);

int result = gtk_icon_view_get_row_spacing(GtkIconView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_reorderable(value self)
{
CAMLparam1(self);

gboolean result = gtk_icon_view_get_reorderable(GtkIconView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_pixbuf_column(value self)
{
CAMLparam1(self);

int result = gtk_icon_view_get_pixbuf_column(GtkIconView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_path_at_pos(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

GtkTreePath* result = gtk_icon_view_get_path_at_pos(GtkIconView_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_option(result, Val_GtkTreePath));
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_model(value self)
{
CAMLparam1(self);

GtkTreeModel* result = gtk_icon_view_get_model(GtkIconView_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkTreeModel));
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_markup_column(value self)
{
CAMLparam1(self);

int result = gtk_icon_view_get_markup_column(GtkIconView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_margin(value self)
{
CAMLparam1(self);

int result = gtk_icon_view_get_margin(GtkIconView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_item_width(value self)
{
CAMLparam1(self);

int result = gtk_icon_view_get_item_width(GtkIconView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_item_row(value self, value arg1)
{
CAMLparam2(self, arg1);

int result = gtk_icon_view_get_item_row(GtkIconView_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_item_padding(value self)
{
CAMLparam1(self);

int result = gtk_icon_view_get_item_padding(GtkIconView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_item_orientation(value self)
{
CAMLparam1(self);

GtkOrientation result = gtk_icon_view_get_item_orientation(GtkIconView_val(self));
CAMLreturn(Val_GtkOrientation(result));
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_item_column(value self, value arg1)
{
CAMLparam2(self, arg1);

int result = gtk_icon_view_get_item_column(GtkIconView_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_columns(value self)
{
CAMLparam1(self);

int result = gtk_icon_view_get_columns(GtkIconView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_column_spacing(value self)
{
CAMLparam1(self);

int result = gtk_icon_view_get_column_spacing(GtkIconView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_cell_rect(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GdkRectangle out3;

gboolean result = gtk_icon_view_get_cell_rect(GtkIconView_val(self), GtkTreePath_val(arg1), Option_val(arg2, GtkCellRenderer_val, NULL), &out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_GdkRectangle(&out3));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_activate_on_single_click(value self)
{
CAMLparam1(self);

gboolean result = gtk_icon_view_get_activate_on_single_click(GtkIconView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_icon_view_enable_model_drag_source(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_icon_view_enable_model_drag_source(GtkIconView_val(self), GdkModifierType_val(arg1), GdkContentFormats_val(arg2), GdkDragAction_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_enable_model_drag_dest(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_icon_view_enable_model_drag_dest(GtkIconView_val(self), GdkContentFormats_val(arg1), GdkDragAction_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_icon_view_create_drag_icon(value self, value arg1)
{
CAMLparam2(self, arg1);

GdkPaintable* result = gtk_icon_view_create_drag_icon(GtkIconView_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_option(result, Val_GdkPaintable));
}

CAMLexport CAMLprim value ml_gtk_icon_view_get_cell_area(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkIconView *obj = (GtkIconView *)GtkIconView_val(self);
    GtkCellArea *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "cell-area");
if (pspec == NULL) caml_failwith("ml_gtk_icon_view_get_cell_area: property 'cell-area' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "cell-area", &prop_gvalue);
          prop_value = (GtkCellArea*)g_value_dup_object(&prop_gvalue);

      result = Val_GtkCellArea(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}
