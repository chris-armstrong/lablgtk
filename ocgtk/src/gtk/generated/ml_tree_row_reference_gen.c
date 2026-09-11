/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TreeRowReference */

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

/* Conversion functions for GtkTreeRowReference (opaque record with hidden fields) */
GtkTreeRowReference *GtkTreeRowReference_val(value v) {
  return (GtkTreeRowReference *)ml_gir_record_ptr_val(v, "GtkTreeRowReference");
}

value Val_GtkTreeRowReference(const GtkTreeRowReference *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gtk_tree_row_reference_get_type(), ptr);
}

value Val_GtkTreeRowReference_option(const GtkTreeRowReference *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GtkTreeRowReference(ptr));
}


CAMLexport CAMLprim value ml_gtk_tree_row_reference_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkTreeRowReference *obj = gtk_tree_row_reference_new(GtkTreeModel_val(arg1), GtkTreePath_val(arg2));

CAMLreturn(Val_GtkTreeRowReference(obj));
}
CAMLexport CAMLprim value ml_gtk_tree_row_reference_new_proxy(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GtkTreeRowReference *obj = gtk_tree_row_reference_new_proxy(GObject_ext_of_val(arg1), GtkTreeModel_val(arg2), GtkTreePath_val(arg3));

CAMLreturn(Val_GtkTreeRowReference(obj));
}
CAMLexport CAMLprim value ml_gtk_tree_row_reference_valid(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_row_reference_valid(GtkTreeRowReference_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_row_reference_get_path(value self)
{
CAMLparam1(self);

GtkTreePath* result = gtk_tree_row_reference_get_path(GtkTreeRowReference_val(self));
CAMLreturn(Val_option(result, Val_GtkTreePath));
}

CAMLexport CAMLprim value ml_gtk_tree_row_reference_get_model(value self)
{
CAMLparam1(self);

GtkTreeModel* result = gtk_tree_row_reference_get_model(GtkTreeRowReference_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkTreeModel(result));
}


CAMLprim value ml_gtk_tree_row_reference_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_tree_row_reference_get_type()));
}
