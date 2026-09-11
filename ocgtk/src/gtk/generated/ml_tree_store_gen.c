/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TreeStore */

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


CAMLexport CAMLprim value ml_gtk_tree_store_newv(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
    int arg2_length = Wosize_val(arg2);
    GType* c_arg2 = (GType*)g_malloc(sizeof(GType) * arg2_length);
    for (int i = 0; i < arg2_length; i++) {
      c_arg2[i] = GType_val(Field(arg2, i));
    }

GtkTreeStore *obj = gtk_tree_store_newv(Int_val(arg1), c_arg2);
if (obj) g_object_ref_sink(obj);

    g_free(c_arg2);
CAMLreturn(Val_GtkTreeStore(obj));
}
CAMLexport CAMLprim value ml_gtk_tree_store_swap(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_tree_store_swap(GtkTreeStore_val(self), GtkTreeIter_val(arg1), GtkTreeIter_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_store_set_valuesv(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
    int arg2_length = Wosize_val(arg2);
    int* c_arg2 = (int*)g_malloc(sizeof(int) * arg2_length);
    for (int i = 0; i < arg2_length; i++) {
      c_arg2[i] = Int_val(Field(arg2, i));
    }
    int arg3_length = Wosize_val(arg3);
    GValue* c_arg3 = (GValue*)g_malloc(sizeof(GValue) * arg3_length);
    for (int i = 0; i < arg3_length; i++) {
      c_arg3[i] = *GValue_val(Field(arg3, i));
    }

gtk_tree_store_set_valuesv(GtkTreeStore_val(self), GtkTreeIter_val(arg1), c_arg2, c_arg3, Int_val(arg4));
    g_free(c_arg2);
    g_free(c_arg3);
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_store_set_value(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_tree_store_set_value(GtkTreeStore_val(self), GtkTreeIter_val(arg1), Int_val(arg2), GValue_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_store_set_column_types(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
    int arg2_length = Wosize_val(arg2);
    GType* c_arg2 = (GType*)g_malloc(sizeof(GType) * arg2_length);
    for (int i = 0; i < arg2_length; i++) {
      c_arg2[i] = GType_val(Field(arg2, i));
    }

gtk_tree_store_set_column_types(GtkTreeStore_val(self), Int_val(arg1), c_arg2);
    g_free(c_arg2);
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_store_remove(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_tree_store_remove(GtkTreeStore_val(self), GtkTreeIter_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_store_prepend(value self, value arg1)
{
CAMLparam2(self, arg1);
GtkTreeIter out1;

gtk_tree_store_prepend(GtkTreeStore_val(self), &out1, Option_val(arg1, GtkTreeIter_val, NULL));
CAMLreturn(Val_GtkTreeIter(&out1));
}

CAMLexport CAMLprim value ml_gtk_tree_store_move_before(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_tree_store_move_before(GtkTreeStore_val(self), GtkTreeIter_val(arg1), Option_val(arg2, GtkTreeIter_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_store_move_after(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_tree_store_move_after(GtkTreeStore_val(self), GtkTreeIter_val(arg1), Option_val(arg2, GtkTreeIter_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_store_iter_is_valid(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_tree_store_iter_is_valid(GtkTreeStore_val(self), GtkTreeIter_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_store_iter_depth(value self, value arg1)
{
CAMLparam2(self, arg1);

int result = gtk_tree_store_iter_depth(GtkTreeStore_val(self), GtkTreeIter_val(arg1));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_tree_store_is_ancestor(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gtk_tree_store_is_ancestor(GtkTreeStore_val(self), GtkTreeIter_val(arg1), GtkTreeIter_val(arg2));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_store_insert_with_valuesv_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);
GtkTreeIter out1;
    int arg3_length = Wosize_val(arg3);
    int* c_arg3 = (int*)g_malloc(sizeof(int) * arg3_length);
    for (int i = 0; i < arg3_length; i++) {
      c_arg3[i] = Int_val(Field(arg3, i));
    }
    int arg4_length = Wosize_val(arg4);
    GValue* c_arg4 = (GValue*)g_malloc(sizeof(GValue) * arg4_length);
    for (int i = 0; i < arg4_length; i++) {
      c_arg4[i] = *GValue_val(Field(arg4, i));
    }

gtk_tree_store_insert_with_valuesv(GtkTreeStore_val(self), &out1, Option_val(arg1, GtkTreeIter_val, NULL), Int_val(arg2), c_arg3, c_arg4, Int_val(arg5));
    g_free(c_arg3);
    g_free(c_arg4);
CAMLreturn(Val_GtkTreeIter(&out1));}

CAMLexport CAMLprim value ml_gtk_tree_store_insert_with_valuesv_bytecode(value * argv, int argn)
{
return ml_gtk_tree_store_insert_with_valuesv_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gtk_tree_store_insert_before(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GtkTreeIter out1;

gtk_tree_store_insert_before(GtkTreeStore_val(self), &out1, Option_val(arg1, GtkTreeIter_val, NULL), Option_val(arg2, GtkTreeIter_val, NULL));
CAMLreturn(Val_GtkTreeIter(&out1));
}

CAMLexport CAMLprim value ml_gtk_tree_store_insert_after(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GtkTreeIter out1;

gtk_tree_store_insert_after(GtkTreeStore_val(self), &out1, Option_val(arg1, GtkTreeIter_val, NULL), Option_val(arg2, GtkTreeIter_val, NULL));
CAMLreturn(Val_GtkTreeIter(&out1));
}

CAMLexport CAMLprim value ml_gtk_tree_store_insert(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GtkTreeIter out1;

gtk_tree_store_insert(GtkTreeStore_val(self), &out1, Option_val(arg1, GtkTreeIter_val, NULL), Int_val(arg2));
CAMLreturn(Val_GtkTreeIter(&out1));
}

CAMLexport CAMLprim value ml_gtk_tree_store_clear(value self)
{
CAMLparam1(self);

gtk_tree_store_clear(GtkTreeStore_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_store_append(value self, value arg1)
{
CAMLparam2(self, arg1);
GtkTreeIter out1;

gtk_tree_store_append(GtkTreeStore_val(self), &out1, Option_val(arg1, GtkTreeIter_val, NULL));
CAMLreturn(Val_GtkTreeIter(&out1));
}


CAMLprim value ml_gtk_tree_store_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_tree_store_get_type()));
}
