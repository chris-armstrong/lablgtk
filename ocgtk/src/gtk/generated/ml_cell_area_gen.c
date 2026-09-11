/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CellArea */

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


CAMLexport CAMLprim value ml_gtk_cell_area_stop_editing(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_cell_area_stop_editing(GtkCellArea_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_area_snapshot_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam3(arg5, arg6, arg7);

gtk_cell_area_snapshot(GtkCellArea_val(self), GtkCellAreaContext_val(arg1), GtkWidget_val(arg2), GtkSnapshot_val(arg3), GdkRectangle_val(arg4), GdkRectangle_val(arg5), GtkCellRendererState_val(arg6), Bool_val(arg7));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gtk_cell_area_snapshot_bytecode(value * argv, int argn)
{
return ml_gtk_cell_area_snapshot_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

CAMLexport CAMLprim value ml_gtk_cell_area_set_focus_cell(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_cell_area_set_focus_cell(GtkCellArea_val(self), Option_val(arg1, GtkCellRenderer_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_area_request_renderer(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
int out5;
int out6;

gtk_cell_area_request_renderer(GtkCellArea_val(self), GtkCellRenderer_val(arg1), GtkOrientation_val(arg2), GtkWidget_val(arg3), Int_val(arg4), &out5, &out6);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out5));
    Store_field(ret, 1, Val_int(out6));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_cell_area_remove_focus_sibling(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_cell_area_remove_focus_sibling(GtkCellArea_val(self), GtkCellRenderer_val(arg1), GtkCellRenderer_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_area_remove(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_cell_area_remove(GtkCellArea_val(self), GtkCellRenderer_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_area_is_focus_sibling(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gtk_cell_area_is_focus_sibling(GtkCellArea_val(self), GtkCellRenderer_val(arg1), GtkCellRenderer_val(arg2));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_cell_area_is_activatable(value self)
{
CAMLparam1(self);

gboolean result = gtk_cell_area_is_activatable(GtkCellArea_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_cell_area_inner_cell_area(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GdkRectangle out3;

gtk_cell_area_inner_cell_area(GtkCellArea_val(self), GtkWidget_val(arg1), GdkRectangle_val(arg2), &out3);
CAMLreturn(Val_GdkRectangle(&out3));
}

CAMLexport CAMLprim value ml_gtk_cell_area_has_renderer(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_cell_area_has_renderer(GtkCellArea_val(self), GtkCellRenderer_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_cell_area_get_request_mode(value self)
{
CAMLparam1(self);

GtkSizeRequestMode result = gtk_cell_area_get_request_mode(GtkCellArea_val(self));
CAMLreturn(Val_GtkSizeRequestMode(result));
}

CAMLexport CAMLprim value ml_gtk_cell_area_get_preferred_width_for_height(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
int out4;
int out5;

gtk_cell_area_get_preferred_width_for_height(GtkCellArea_val(self), GtkCellAreaContext_val(arg1), GtkWidget_val(arg2), Int_val(arg3), &out4, &out5);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out4));
    Store_field(ret, 1, Val_int(out5));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_cell_area_get_preferred_width(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
int out3;
int out4;

gtk_cell_area_get_preferred_width(GtkCellArea_val(self), GtkCellAreaContext_val(arg1), GtkWidget_val(arg2), &out3, &out4);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out3));
    Store_field(ret, 1, Val_int(out4));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_cell_area_get_preferred_height_for_width(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
int out4;
int out5;

gtk_cell_area_get_preferred_height_for_width(GtkCellArea_val(self), GtkCellAreaContext_val(arg1), GtkWidget_val(arg2), Int_val(arg3), &out4, &out5);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out4));
    Store_field(ret, 1, Val_int(out5));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_cell_area_get_preferred_height(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
int out3;
int out4;

gtk_cell_area_get_preferred_height(GtkCellArea_val(self), GtkCellAreaContext_val(arg1), GtkWidget_val(arg2), &out3, &out4);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out3));
    Store_field(ret, 1, Val_int(out4));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_cell_area_get_focus_siblings(value self, value arg1)
{
CAMLparam2(self, arg1);

CAMLlocal3(result, item, cell);
    GList* c_result = (GList*)gtk_cell_area_get_focus_siblings(GtkCellArea_val(self), GtkCellRenderer_val(arg1));
Val_GList_with(c_result, result, item, cell, Val_GtkCellRenderer((gpointer)_tmp->data));
    CAMLreturn(result);
}

CAMLexport CAMLprim value ml_gtk_cell_area_get_focus_from_sibling(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkCellRenderer* result = gtk_cell_area_get_focus_from_sibling(GtkCellArea_val(self), GtkCellRenderer_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkCellRenderer));
}

CAMLexport CAMLprim value ml_gtk_cell_area_get_focus_cell(value self)
{
CAMLparam1(self);

GtkCellRenderer* result = gtk_cell_area_get_focus_cell(GtkCellArea_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkCellRenderer));
}

CAMLexport CAMLprim value ml_gtk_cell_area_get_edited_cell(value self)
{
CAMLparam1(self);

GtkCellRenderer* result = gtk_cell_area_get_edited_cell(GtkCellArea_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkCellRenderer));
}

CAMLexport CAMLprim value ml_gtk_cell_area_get_edit_widget(value self)
{
CAMLparam1(self);

GtkCellEditable* result = gtk_cell_area_get_edit_widget(GtkCellArea_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkCellEditable));
}

CAMLexport CAMLprim value ml_gtk_cell_area_get_current_path_string(value self)
{
CAMLparam1(self);

const char* result = gtk_cell_area_get_current_path_string(GtkCellArea_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_cell_area_get_cell_at_position_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);
GdkRectangle out6;

GtkCellRenderer* result = gtk_cell_area_get_cell_at_position(GtkCellArea_val(self), GtkCellAreaContext_val(arg1), GtkWidget_val(arg2), GdkRectangle_val(arg3), Int_val(arg4), Int_val(arg5), &out6);
if (result) g_object_ref_sink(result);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_GtkCellRenderer(result));
    Store_field(ret, 1, Val_GdkRectangle(&out6));
    CAMLreturn(ret);}

CAMLexport CAMLprim value ml_gtk_cell_area_get_cell_at_position_bytecode(value * argv, int argn)
{
return ml_gtk_cell_area_get_cell_at_position_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gtk_cell_area_get_cell_allocation(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
GdkRectangle out5;

gtk_cell_area_get_cell_allocation(GtkCellArea_val(self), GtkCellAreaContext_val(arg1), GtkWidget_val(arg2), GtkCellRenderer_val(arg3), GdkRectangle_val(arg4), &out5);
CAMLreturn(Val_GdkRectangle(&out5));
}

CAMLexport CAMLprim value ml_gtk_cell_area_focus(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_cell_area_focus(GtkCellArea_val(self), GtkDirectionType_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_cell_area_event_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);

int result = gtk_cell_area_event(GtkCellArea_val(self), GtkCellAreaContext_val(arg1), GtkWidget_val(arg2), GdkEvent_val(arg3), GdkRectangle_val(arg4), GtkCellRendererState_val(arg5));
CAMLreturn(Val_int(result));}

CAMLexport CAMLprim value ml_gtk_cell_area_event_bytecode(value * argv, int argn)
{
return ml_gtk_cell_area_event_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gtk_cell_area_create_context(value self)
{
CAMLparam1(self);

GtkCellAreaContext* result = gtk_cell_area_create_context(GtkCellArea_val(self));
CAMLreturn(Val_GtkCellAreaContext(result));
}

CAMLexport CAMLprim value ml_gtk_cell_area_copy_context(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkCellAreaContext* result = gtk_cell_area_copy_context(GtkCellArea_val(self), GtkCellAreaContext_val(arg1));
CAMLreturn(Val_GtkCellAreaContext(result));
}

CAMLexport CAMLprim value ml_gtk_cell_area_cell_set_property(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_cell_area_cell_set_property(GtkCellArea_val(self), GtkCellRenderer_val(arg1), String_val(arg2), GValue_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_area_cell_get_property(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_cell_area_cell_get_property(GtkCellArea_val(self), GtkCellRenderer_val(arg1), String_val(arg2), GValue_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_area_attribute_get_column(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

int result = gtk_cell_area_attribute_get_column(GtkCellArea_val(self), GtkCellRenderer_val(arg1), String_val(arg2));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_cell_area_attribute_disconnect(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_cell_area_attribute_disconnect(GtkCellArea_val(self), GtkCellRenderer_val(arg1), String_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_area_attribute_connect(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_cell_area_attribute_connect(GtkCellArea_val(self), GtkCellRenderer_val(arg1), String_val(arg2), Int_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_area_apply_attributes(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gtk_cell_area_apply_attributes(GtkCellArea_val(self), GtkTreeModel_val(arg1), GtkTreeIter_val(arg2), Bool_val(arg3), Bool_val(arg4));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_area_add_focus_sibling(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_cell_area_add_focus_sibling(GtkCellArea_val(self), GtkCellRenderer_val(arg1), GtkCellRenderer_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_area_add(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_cell_area_add(GtkCellArea_val(self), GtkCellRenderer_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_area_activate_cell_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);

gboolean result = gtk_cell_area_activate_cell(GtkCellArea_val(self), GtkWidget_val(arg1), GtkCellRenderer_val(arg2), GdkEvent_val(arg3), GdkRectangle_val(arg4), GtkCellRendererState_val(arg5));
CAMLreturn(Val_bool(result));}

CAMLexport CAMLprim value ml_gtk_cell_area_activate_cell_bytecode(value * argv, int argn)
{
return ml_gtk_cell_area_activate_cell_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gtk_cell_area_activate_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);

gboolean result = gtk_cell_area_activate(GtkCellArea_val(self), GtkCellAreaContext_val(arg1), GtkWidget_val(arg2), GdkRectangle_val(arg3), GtkCellRendererState_val(arg4), Bool_val(arg5));
CAMLreturn(Val_bool(result));}

CAMLexport CAMLprim value ml_gtk_cell_area_activate_bytecode(value * argv, int argn)
{
return ml_gtk_cell_area_activate_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}


CAMLprim value ml_gtk_cell_area_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_cell_area_get_type()));
}
