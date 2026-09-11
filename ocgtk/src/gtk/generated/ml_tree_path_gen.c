/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TreePath */

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

/* Conversion functions for GtkTreePath (opaque record with hidden fields) */
GtkTreePath *GtkTreePath_val(value v) {
  return (GtkTreePath *)ml_gir_record_ptr_val(v, "GtkTreePath");
}

value Val_GtkTreePath(const GtkTreePath *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gtk_tree_path_get_type(), ptr);
}

value Val_GtkTreePath_option(const GtkTreePath *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GtkTreePath(ptr));
}


CAMLexport CAMLprim value ml_gtk_tree_path_new(value unit)
{
CAMLparam1(unit);

GtkTreePath *obj = gtk_tree_path_new();

CAMLreturn(Val_GtkTreePath(obj));
}
CAMLexport CAMLprim value ml_gtk_tree_path_new_first(value unit)
{
CAMLparam1(unit);

GtkTreePath *obj = gtk_tree_path_new_first();

CAMLreturn(Val_GtkTreePath(obj));
}
CAMLexport CAMLprim value ml_gtk_tree_path_new_from_indicesv(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
    int arg1_length = Wosize_val(arg1);
    int* c_arg1 = (int*)g_malloc(sizeof(int) * arg1_length);
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = Int_val(Field(arg1, i));
    }

GtkTreePath *obj = gtk_tree_path_new_from_indicesv(c_arg1, Gsize_val(arg2));

    g_free(c_arg1);
CAMLreturn(Val_GtkTreePath(obj));
}
CAMLexport CAMLprim value ml_gtk_tree_path_new_from_string(value arg1)
{
CAMLparam1(arg1);

GtkTreePath *obj = gtk_tree_path_new_from_string(String_val(arg1));

CAMLreturn(Val_GtkTreePath(obj));
}
CAMLexport CAMLprim value ml_gtk_tree_path_up(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_path_up(GtkTreePath_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_path_to_string(value self)
{
CAMLparam1(self);

char* result = gtk_tree_path_to_string(GtkTreePath_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_tree_path_prev(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_path_prev(GtkTreePath_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_path_prepend_index(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_path_prepend_index(GtkTreePath_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_path_next(value self)
{
CAMLparam1(self);

gtk_tree_path_next(GtkTreePath_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_path_is_descendant(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_tree_path_is_descendant(GtkTreePath_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_path_is_ancestor(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_tree_path_is_ancestor(GtkTreePath_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_path_get_indices_with_depth(value self)
{
CAMLparam1(self);
int out1;

int* result = gtk_tree_path_get_indices_with_depth(GtkTreePath_val(self), &out1);
    CAMLlocal2(ml_result, ml_result_opt);
    if (result == NULL) {
      ml_result_opt = Val_none;
    } else {
      int result_length = out1;
      ml_result = caml_alloc(result_length, 0);
      for (int i = 0; i < result_length; i++) {
        Store_field(ml_result, i, Val_int(result[i]));
      }
      ml_result_opt = Val_some(ml_result);
          }
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_result_opt);
    Store_field(ret, 1, Val_int(out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_tree_path_get_depth(value self)
{
CAMLparam1(self);

int result = gtk_tree_path_get_depth(GtkTreePath_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_tree_path_down(value self)
{
CAMLparam1(self);

gtk_tree_path_down(GtkTreePath_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_path_compare(value self, value arg1)
{
CAMLparam2(self, arg1);

int result = gtk_tree_path_compare(GtkTreePath_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_tree_path_append_index(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_path_append_index(GtkTreePath_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_tree_path_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_tree_path_get_type()));
}
