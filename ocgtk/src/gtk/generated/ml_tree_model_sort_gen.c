/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TreeModelSort */

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


CAMLexport CAMLprim value ml_gtk_tree_model_sort_new_with_model(value arg1)
{
CAMLparam1(arg1);

GtkTreeModelSort *obj = gtk_tree_model_sort_new_with_model(GtkTreeModel_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkTreeModelSort(obj));
}
CAMLexport CAMLprim value ml_gtk_tree_model_sort_reset_default_sort_func(value self)
{
CAMLparam1(self);

gtk_tree_model_sort_reset_default_sort_func(GtkTreeModelSort_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_model_sort_iter_is_valid(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_tree_model_sort_iter_is_valid(GtkTreeModelSort_val(self), GtkTreeIter_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_model_sort_get_model(value self)
{
CAMLparam1(self);

GtkTreeModel* result = gtk_tree_model_sort_get_model(GtkTreeModelSort_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkTreeModel(result));
}

CAMLexport CAMLprim value ml_gtk_tree_model_sort_convert_path_to_child_path(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkTreePath* result = gtk_tree_model_sort_convert_path_to_child_path(GtkTreeModelSort_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_option(result, Val_GtkTreePath));
}

CAMLexport CAMLprim value ml_gtk_tree_model_sort_convert_iter_to_child_iter(value self, value arg1)
{
CAMLparam2(self, arg1);
GtkTreeIter out1;

gtk_tree_model_sort_convert_iter_to_child_iter(GtkTreeModelSort_val(self), &out1, GtkTreeIter_val(arg1));
CAMLreturn(Val_GtkTreeIter(&out1));
}

CAMLexport CAMLprim value ml_gtk_tree_model_sort_convert_child_path_to_path(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkTreePath* result = gtk_tree_model_sort_convert_child_path_to_path(GtkTreeModelSort_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_option(result, Val_GtkTreePath));
}

CAMLexport CAMLprim value ml_gtk_tree_model_sort_convert_child_iter_to_iter(value self, value arg1)
{
CAMLparam2(self, arg1);
GtkTreeIter out1;

gboolean result = gtk_tree_model_sort_convert_child_iter_to_iter(GtkTreeModelSort_val(self), &out1, GtkTreeIter_val(arg1));
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_GtkTreeIter(&out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_tree_model_sort_clear_cache(value self)
{
CAMLparam1(self);

gtk_tree_model_sort_clear_cache(GtkTreeModelSort_val(self));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_tree_model_sort_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_tree_model_sort_get_type()));
}
