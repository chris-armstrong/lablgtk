/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TreeSelection */

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


CAMLexport CAMLprim value ml_gtk_tree_selection_unselect_range(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_tree_selection_unselect_range(GtkTreeSelection_val(self), GtkTreePath_val(arg1), GtkTreePath_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_selection_unselect_path(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_selection_unselect_path(GtkTreeSelection_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_selection_unselect_iter(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_selection_unselect_iter(GtkTreeSelection_val(self), GtkTreeIter_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_selection_unselect_all(value self)
{
CAMLparam1(self);

gtk_tree_selection_unselect_all(GtkTreeSelection_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_selection_set_mode(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_selection_set_mode(GtkTreeSelection_val(self), GtkSelectionMode_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_selection_select_range(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_tree_selection_select_range(GtkTreeSelection_val(self), GtkTreePath_val(arg1), GtkTreePath_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_selection_select_path(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_selection_select_path(GtkTreeSelection_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_selection_select_iter(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_selection_select_iter(GtkTreeSelection_val(self), GtkTreeIter_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_selection_select_all(value self)
{
CAMLparam1(self);

gtk_tree_selection_select_all(GtkTreeSelection_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_selection_path_is_selected(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_tree_selection_path_is_selected(GtkTreeSelection_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_selection_iter_is_selected(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_tree_selection_iter_is_selected(GtkTreeSelection_val(self), GtkTreeIter_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_selection_get_tree_view(value self)
{
CAMLparam1(self);

GtkTreeView* result = gtk_tree_selection_get_tree_view(GtkTreeSelection_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkTreeView(result));
}

CAMLexport CAMLprim value ml_gtk_tree_selection_get_mode(value self)
{
CAMLparam1(self);

GtkSelectionMode result = gtk_tree_selection_get_mode(GtkTreeSelection_val(self));
CAMLreturn(Val_GtkSelectionMode(result));
}

CAMLexport CAMLprim value ml_gtk_tree_selection_count_selected_rows(value self)
{
CAMLparam1(self);

int result = gtk_tree_selection_count_selected_rows(GtkTreeSelection_val(self));
CAMLreturn(Val_int(result));
}

GType gtk_tree_selection_get_type (void);


CAMLprim value ml_gtk_tree_selection_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_tree_selection_get_type()));
}
