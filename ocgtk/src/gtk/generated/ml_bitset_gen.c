/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Bitset */

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

/* Conversion functions for GtkBitset (opaque record with hidden fields) */
GtkBitset *GtkBitset_val(value v) {
  return (GtkBitset *)ml_gir_record_ptr_val(v, "GtkBitset");
}

value Val_GtkBitset(const GtkBitset *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gtk_bitset_get_type(), ptr);
}

value Val_GtkBitset_option(const GtkBitset *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GtkBitset(ptr));
}


CAMLexport CAMLprim value ml_gtk_bitset_new_empty(value unit)
{
CAMLparam1(unit);

GtkBitset *obj = gtk_bitset_new_empty();

CAMLreturn(Val_GtkBitset(obj));
}
CAMLexport CAMLprim value ml_gtk_bitset_new_range(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkBitset *obj = gtk_bitset_new_range(Int_val(arg1), Int_val(arg2));

CAMLreturn(Val_GtkBitset(obj));
}
CAMLexport CAMLprim value ml_gtk_bitset_union(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_bitset_union(GtkBitset_val(self), GtkBitset_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_bitset_subtract(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_bitset_subtract(GtkBitset_val(self), GtkBitset_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_bitset_splice(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_bitset_splice(GtkBitset_val(self), Int_val(arg1), Int_val(arg2), Int_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_bitset_shift_right(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_bitset_shift_right(GtkBitset_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_bitset_shift_left(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_bitset_shift_left(GtkBitset_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_bitset_remove_rectangle(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gtk_bitset_remove_rectangle(GtkBitset_val(self), Int_val(arg1), Int_val(arg2), Int_val(arg3), Int_val(arg4));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_bitset_remove_range_closed(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_bitset_remove_range_closed(GtkBitset_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_bitset_remove_range(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_bitset_remove_range(GtkBitset_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_bitset_remove_all(value self)
{
CAMLparam1(self);

gtk_bitset_remove_all(GtkBitset_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_bitset_remove(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_bitset_remove(GtkBitset_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_bitset_ref(value self)
{
CAMLparam1(self);

GtkBitset* result = gtk_bitset_ref(GtkBitset_val(self));
if (result) result = g_boxed_copy(gtk_bitset_get_type(), result);
CAMLreturn(Val_GtkBitset(result));
}

CAMLexport CAMLprim value ml_gtk_bitset_is_empty(value self)
{
CAMLparam1(self);

gboolean result = gtk_bitset_is_empty(GtkBitset_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_bitset_intersect(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_bitset_intersect(GtkBitset_val(self), GtkBitset_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_bitset_get_size_in_range(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

guint64 result = gtk_bitset_get_size_in_range(GtkBitset_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(integers_copy_uint64(result));
}

CAMLexport CAMLprim value ml_gtk_bitset_get_size(value self)
{
CAMLparam1(self);

guint64 result = gtk_bitset_get_size(GtkBitset_val(self));
CAMLreturn(integers_copy_uint64(result));
}

CAMLexport CAMLprim value ml_gtk_bitset_get_nth(value self, value arg1)
{
CAMLparam2(self, arg1);

guint result = gtk_bitset_get_nth(GtkBitset_val(self), Int_val(arg1));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_bitset_get_minimum(value self)
{
CAMLparam1(self);

guint result = gtk_bitset_get_minimum(GtkBitset_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_bitset_get_maximum(value self)
{
CAMLparam1(self);

guint result = gtk_bitset_get_maximum(GtkBitset_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_bitset_equals(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_bitset_equals(GtkBitset_val(self), GtkBitset_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_bitset_difference(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_bitset_difference(GtkBitset_val(self), GtkBitset_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_bitset_contains(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_bitset_contains(GtkBitset_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_bitset_add_rectangle(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gtk_bitset_add_rectangle(GtkBitset_val(self), Int_val(arg1), Int_val(arg2), Int_val(arg3), Int_val(arg4));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_bitset_add_range_closed(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_bitset_add_range_closed(GtkBitset_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_bitset_add_range(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_bitset_add_range(GtkBitset_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_bitset_add(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_bitset_add(GtkBitset_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_gtk_bitset_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_bitset_get_type()));
}
