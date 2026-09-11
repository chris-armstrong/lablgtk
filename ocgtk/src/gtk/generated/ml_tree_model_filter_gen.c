/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TreeModelFilter */

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


CAMLexport CAMLprim value ml_gtk_tree_model_filter_set_visible_column(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_model_filter_set_visible_column(GtkTreeModelFilter_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_model_filter_refilter(value self)
{
CAMLparam1(self);

gtk_tree_model_filter_refilter(GtkTreeModelFilter_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_model_filter_get_model(value self)
{
CAMLparam1(self);

GtkTreeModel* result = gtk_tree_model_filter_get_model(GtkTreeModelFilter_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkTreeModel(result));
}

CAMLexport CAMLprim value ml_gtk_tree_model_filter_convert_path_to_child_path(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkTreePath* result = gtk_tree_model_filter_convert_path_to_child_path(GtkTreeModelFilter_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_option(result, Val_GtkTreePath));
}

CAMLexport CAMLprim value ml_gtk_tree_model_filter_convert_iter_to_child_iter(value self, value arg1)
{
CAMLparam2(self, arg1);
GtkTreeIter out1;

gtk_tree_model_filter_convert_iter_to_child_iter(GtkTreeModelFilter_val(self), &out1, GtkTreeIter_val(arg1));
CAMLreturn(Val_GtkTreeIter(&out1));
}

CAMLexport CAMLprim value ml_gtk_tree_model_filter_convert_child_path_to_path(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkTreePath* result = gtk_tree_model_filter_convert_child_path_to_path(GtkTreeModelFilter_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_option(result, Val_GtkTreePath));
}

CAMLexport CAMLprim value ml_gtk_tree_model_filter_convert_child_iter_to_iter(value self, value arg1)
{
CAMLparam2(self, arg1);
GtkTreeIter out1;

gboolean result = gtk_tree_model_filter_convert_child_iter_to_iter(GtkTreeModelFilter_val(self), &out1, GtkTreeIter_val(arg1));
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_GtkTreeIter(&out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_tree_model_filter_clear_cache(value self)
{
CAMLparam1(self);

gtk_tree_model_filter_clear_cache(GtkTreeModelFilter_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_model_filter_get_child_model(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTreeModelFilter *obj = (GtkTreeModelFilter *)GtkTreeModelFilter_val(self);
    GtkTreeModel *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "child-model");
if (pspec == NULL) caml_failwith("ml_gtk_tree_model_filter_get_child_model: property 'child-model' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "child-model", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GtkTreeModel(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_tree_model_filter_get_virtual_root(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTreeModelFilter *obj = (GtkTreeModelFilter *)GtkTreeModelFilter_val(self);
    GtkTreePath *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "virtual-root");
if (pspec == NULL) caml_failwith("ml_gtk_tree_model_filter_get_virtual_root: property 'virtual-root' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "virtual-root", &prop_gvalue);
          prop_value = (GtkTreePath*)g_value_get_boxed(&prop_gvalue);

      result = Val_GtkTreePath(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}


CAMLprim value ml_gtk_tree_model_filter_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_tree_model_filter_get_type()));
}
