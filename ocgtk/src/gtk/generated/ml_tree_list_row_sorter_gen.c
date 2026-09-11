/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TreeListRowSorter */

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


CAMLexport CAMLprim value ml_gtk_tree_list_row_sorter_new(value arg1)
{
CAMLparam1(arg1);

GtkTreeListRowSorter *obj = gtk_tree_list_row_sorter_new(Option_val(arg1, GtkSorter_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkTreeListRowSorter(obj));
}
CAMLexport CAMLprim value ml_gtk_tree_list_row_sorter_set_sorter(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_list_row_sorter_set_sorter(GtkTreeListRowSorter_val(self), Option_val(arg1, GtkSorter_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_list_row_sorter_get_sorter(value self)
{
CAMLparam1(self);

GtkSorter* result = gtk_tree_list_row_sorter_get_sorter(GtkTreeListRowSorter_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkSorter));
}


CAMLprim value ml_gtk_tree_list_row_sorter_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_tree_list_row_sorter_get_type()));
}
