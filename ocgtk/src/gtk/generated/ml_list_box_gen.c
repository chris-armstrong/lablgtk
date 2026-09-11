/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ListBox */

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


CAMLexport CAMLprim value ml_gtk_list_box_new(value unit)
{
CAMLparam1(unit);

GtkListBox *obj = gtk_list_box_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkListBox(obj));
}
CAMLexport CAMLprim value ml_gtk_list_box_unselect_row(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_box_unselect_row(GtkListBox_val(self), GtkListBoxRow_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_list_box_unselect_all(value self)
{
CAMLparam1(self);

gtk_list_box_unselect_all(GtkListBox_val(self));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,18,0)

CAMLexport CAMLprim value ml_gtk_list_box_set_tab_behavior(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_box_set_tab_behavior(GtkListBox_val(self), GtkListTabBehavior_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_list_box_set_tab_behavior(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ListBox requires GTK >= 4.18");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_list_box_set_show_separators(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_box_set_show_separators(GtkListBox_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_list_box_set_selection_mode(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_box_set_selection_mode(GtkListBox_val(self), GtkSelectionMode_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_list_box_set_placeholder(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_box_set_placeholder(GtkListBox_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_list_box_set_adjustment(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_box_set_adjustment(GtkListBox_val(self), Option_val(arg1, GtkAdjustment_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_list_box_set_activate_on_single_click(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_box_set_activate_on_single_click(GtkListBox_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_list_box_select_row(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_box_select_row(GtkListBox_val(self), Option_val(arg1, GtkListBoxRow_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_list_box_select_all(value self)
{
CAMLparam1(self);

gtk_list_box_select_all(GtkListBox_val(self));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_list_box_remove_all(value self)
{
CAMLparam1(self);

gtk_list_box_remove_all(GtkListBox_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_list_box_remove_all(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ListBox requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_list_box_remove(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_box_remove(GtkListBox_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_list_box_prepend(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_box_prepend(GtkListBox_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_list_box_invalidate_sort(value self)
{
CAMLparam1(self);

gtk_list_box_invalidate_sort(GtkListBox_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_list_box_invalidate_headers(value self)
{
CAMLparam1(self);

gtk_list_box_invalidate_headers(GtkListBox_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_list_box_invalidate_filter(value self)
{
CAMLparam1(self);

gtk_list_box_invalidate_filter(GtkListBox_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_list_box_insert(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_list_box_insert(GtkListBox_val(self), GtkWidget_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,18,0)

CAMLexport CAMLprim value ml_gtk_list_box_get_tab_behavior(value self)
{
CAMLparam1(self);

GtkListTabBehavior result = gtk_list_box_get_tab_behavior(GtkListBox_val(self));
CAMLreturn(Val_GtkListTabBehavior(result));
}

#else

CAMLexport CAMLprim value ml_gtk_list_box_get_tab_behavior(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ListBox requires GTK >= 4.18");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_list_box_get_show_separators(value self)
{
CAMLparam1(self);

gboolean result = gtk_list_box_get_show_separators(GtkListBox_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_list_box_get_selection_mode(value self)
{
CAMLparam1(self);

GtkSelectionMode result = gtk_list_box_get_selection_mode(GtkListBox_val(self));
CAMLreturn(Val_GtkSelectionMode(result));
}

CAMLexport CAMLprim value ml_gtk_list_box_get_selected_rows(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = gtk_list_box_get_selected_rows(GtkListBox_val(self));
Val_GList_with(c_result, result, item, cell, Val_GtkListBoxRow((gpointer)_tmp->data));
    g_list_free(c_result);
    CAMLreturn(result);
}

CAMLexport CAMLprim value ml_gtk_list_box_get_selected_row(value self)
{
CAMLparam1(self);

GtkListBoxRow* result = gtk_list_box_get_selected_row(GtkListBox_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkListBoxRow));
}

CAMLexport CAMLprim value ml_gtk_list_box_get_row_at_y(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkListBoxRow* result = gtk_list_box_get_row_at_y(GtkListBox_val(self), Int_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkListBoxRow));
}

CAMLexport CAMLprim value ml_gtk_list_box_get_row_at_index(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkListBoxRow* result = gtk_list_box_get_row_at_index(GtkListBox_val(self), Int_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkListBoxRow));
}

CAMLexport CAMLprim value ml_gtk_list_box_get_adjustment(value self)
{
CAMLparam1(self);

GtkAdjustment* result = gtk_list_box_get_adjustment(GtkListBox_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkAdjustment));
}

CAMLexport CAMLprim value ml_gtk_list_box_get_activate_on_single_click(value self)
{
CAMLparam1(self);

gboolean result = gtk_list_box_get_activate_on_single_click(GtkListBox_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_list_box_drag_unhighlight_row(value self)
{
CAMLparam1(self);

gtk_list_box_drag_unhighlight_row(GtkListBox_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_list_box_drag_highlight_row(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_box_drag_highlight_row(GtkListBox_val(self), GtkListBoxRow_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_list_box_append(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_box_append(GtkListBox_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_list_box_get_accept_unpaired_release(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkListBox *obj = (GtkListBox *)GtkListBox_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "accept-unpaired-release");
if (pspec == NULL) caml_failwith("ml_gtk_list_box_get_accept_unpaired_release: property 'accept-unpaired-release' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "accept-unpaired-release", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_list_box_set_accept_unpaired_release(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkListBox *obj = (GtkListBox *)GtkListBox_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "accept-unpaired-release");
if (pspec == NULL) caml_failwith("ml_gtk_list_box_set_accept_unpaired_release: property 'accept-unpaired-release' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "accept-unpaired-release", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

GType gtk_list_box_get_type (void);


CAMLprim value ml_gtk_list_box_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_list_box_get_type()));
}
