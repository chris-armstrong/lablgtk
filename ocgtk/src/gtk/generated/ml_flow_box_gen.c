/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FlowBox */

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


CAMLexport CAMLprim value ml_gtk_flow_box_new(value unit)
{
CAMLparam1(unit);

GtkFlowBox *obj = gtk_flow_box_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkFlowBox(obj));
}
CAMLexport CAMLprim value ml_gtk_flow_box_unselect_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_flow_box_unselect_child(GtkFlowBox_val(self), GtkFlowBoxChild_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_flow_box_unselect_all(value self)
{
CAMLparam1(self);

gtk_flow_box_unselect_all(GtkFlowBox_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_flow_box_set_vadjustment(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_flow_box_set_vadjustment(GtkFlowBox_val(self), GtkAdjustment_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_flow_box_set_selection_mode(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_flow_box_set_selection_mode(GtkFlowBox_val(self), GtkSelectionMode_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_flow_box_set_row_spacing(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_flow_box_set_row_spacing(GtkFlowBox_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_flow_box_set_min_children_per_line(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_flow_box_set_min_children_per_line(GtkFlowBox_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_flow_box_set_max_children_per_line(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_flow_box_set_max_children_per_line(GtkFlowBox_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_flow_box_set_homogeneous(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_flow_box_set_homogeneous(GtkFlowBox_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_flow_box_set_hadjustment(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_flow_box_set_hadjustment(GtkFlowBox_val(self), GtkAdjustment_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_flow_box_set_column_spacing(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_flow_box_set_column_spacing(GtkFlowBox_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_flow_box_set_activate_on_single_click(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_flow_box_set_activate_on_single_click(GtkFlowBox_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_flow_box_select_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_flow_box_select_child(GtkFlowBox_val(self), GtkFlowBoxChild_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_flow_box_select_all(value self)
{
CAMLparam1(self);

gtk_flow_box_select_all(GtkFlowBox_val(self));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_flow_box_remove_all(value self)
{
CAMLparam1(self);

gtk_flow_box_remove_all(GtkFlowBox_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_flow_box_remove_all(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FlowBox requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_flow_box_remove(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_flow_box_remove(GtkFlowBox_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gtk_flow_box_prepend(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_flow_box_prepend(GtkFlowBox_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_flow_box_prepend(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FlowBox requires GTK >= 4.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_flow_box_invalidate_sort(value self)
{
CAMLparam1(self);

gtk_flow_box_invalidate_sort(GtkFlowBox_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_flow_box_invalidate_filter(value self)
{
CAMLparam1(self);

gtk_flow_box_invalidate_filter(GtkFlowBox_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_flow_box_insert(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_flow_box_insert(GtkFlowBox_val(self), GtkWidget_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_flow_box_get_selection_mode(value self)
{
CAMLparam1(self);

GtkSelectionMode result = gtk_flow_box_get_selection_mode(GtkFlowBox_val(self));
CAMLreturn(Val_GtkSelectionMode(result));
}

CAMLexport CAMLprim value ml_gtk_flow_box_get_selected_children(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = gtk_flow_box_get_selected_children(GtkFlowBox_val(self));
    /* gtk_flow_box_get_selected_children is transfer-container: the GList
       itself is ours to free (g_list_free below) but each GtkFlowBoxChild*
       element is borrowed (transfer none), same as get_child_at_index /
       get_child_at_pos elsewhere in this file -- and like those, it must be
       g_object_ref_sink()'d before Val_GtkFlowBoxChild wraps it in an
       owning custom block (wrappers.h's ml_gobject_val_of_ext contract).
       This one differed from its siblings and was missing the sink,
       so every OCaml FlowBoxChild wrapper produced here carried an
       unbalanced g_object_unref on GC -- confirmed contributing to the
       double-click-to-activate GtkFlowBoxChild dispose-while-parented
       CRITICAL. */
Val_GList_with(c_result, result, item, cell, Val_GtkFlowBoxChild(g_object_ref_sink((gpointer)_tmp->data)));
    g_list_free(c_result);
    CAMLreturn(result);
}

CAMLexport CAMLprim value ml_gtk_flow_box_get_row_spacing(value self)
{
CAMLparam1(self);

guint result = gtk_flow_box_get_row_spacing(GtkFlowBox_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_flow_box_get_min_children_per_line(value self)
{
CAMLparam1(self);

guint result = gtk_flow_box_get_min_children_per_line(GtkFlowBox_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_flow_box_get_max_children_per_line(value self)
{
CAMLparam1(self);

guint result = gtk_flow_box_get_max_children_per_line(GtkFlowBox_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_flow_box_get_homogeneous(value self)
{
CAMLparam1(self);

gboolean result = gtk_flow_box_get_homogeneous(GtkFlowBox_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_flow_box_get_column_spacing(value self)
{
CAMLparam1(self);

guint result = gtk_flow_box_get_column_spacing(GtkFlowBox_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_flow_box_get_child_at_pos(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

GtkFlowBoxChild* result = gtk_flow_box_get_child_at_pos(GtkFlowBox_val(self), Int_val(arg1), Int_val(arg2));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkFlowBoxChild));
}

CAMLexport CAMLprim value ml_gtk_flow_box_get_child_at_index(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkFlowBoxChild* result = gtk_flow_box_get_child_at_index(GtkFlowBox_val(self), Int_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkFlowBoxChild));
}

CAMLexport CAMLprim value ml_gtk_flow_box_get_activate_on_single_click(value self)
{
CAMLparam1(self);

gboolean result = gtk_flow_box_get_activate_on_single_click(GtkFlowBox_val(self));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gtk_flow_box_append(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_flow_box_append(GtkFlowBox_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_flow_box_append(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FlowBox requires GTK >= 4.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_flow_box_get_accept_unpaired_release(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkFlowBox *obj = (GtkFlowBox *)GtkFlowBox_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "accept-unpaired-release");
if (pspec == NULL) caml_failwith("ml_gtk_flow_box_get_accept_unpaired_release: property 'accept-unpaired-release' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "accept-unpaired-release", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_flow_box_set_accept_unpaired_release(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkFlowBox *obj = (GtkFlowBox *)GtkFlowBox_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "accept-unpaired-release");
if (pspec == NULL) caml_failwith("ml_gtk_flow_box_set_accept_unpaired_release: property 'accept-unpaired-release' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "accept-unpaired-release", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}
