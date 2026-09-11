/* GENERATED CODE - DO NOT EDIT */
/* C bindings for AccessibleList */

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

#if GTK_CHECK_VERSION(4,14,0)
/* Conversion functions for GtkAccessibleList (opaque record with hidden fields) */
GtkAccessibleList *GtkAccessibleList_val(value v) {
  return (GtkAccessibleList *)ml_gir_record_ptr_val(v, "GtkAccessibleList");
}

value Val_GtkAccessibleList(const GtkAccessibleList *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gtk_accessible_list_get_type(), ptr);
}

value Val_GtkAccessibleList_option(const GtkAccessibleList *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GtkAccessibleList(ptr));
}
#endif

#if GTK_CHECK_VERSION(4,14,0)


CAMLexport CAMLprim value ml_gtk_accessible_list_new_from_array(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
    int arg1_length = Wosize_val(arg1);
    GtkAccessible** c_arg1 = (GtkAccessible**)g_malloc(sizeof(GtkAccessible*) * arg1_length);
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = GtkAccessible_val(Field(arg1, i));
    }

GtkAccessibleList *obj = gtk_accessible_list_new_from_array(c_arg1, Gsize_val(arg2));

    g_free(c_arg1);
CAMLreturn(Val_GtkAccessibleList(obj));
}
CAMLexport CAMLprim value ml_gtk_accessible_list_new_from_list(value arg1)
{
CAMLparam1(arg1);
    GList* arg1_list = NULL;
    GList_val_with(arg1, arg1_list, (gpointer)GtkAccessible_val(Field(_iter, 0)));

GtkAccessibleList *obj = gtk_accessible_list_new_from_list(arg1_list);

    g_list_free(arg1_list);
CAMLreturn(Val_GtkAccessibleList(obj));
}
CAMLexport CAMLprim value ml_gtk_accessible_list_get_objects(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = gtk_accessible_list_get_objects(GtkAccessibleList_val(self));
Val_GList_with(c_result, result, item, cell, Val_GtkAccessible((gpointer)_tmp->data));
    g_list_free(c_result);
    CAMLreturn(result);
}


CAMLprim value ml_gtk_accessible_list_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_accessible_list_get_type()));
}

#else


CAMLexport CAMLprim value ml_gtk_accessible_list_new_from_array(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("AccessibleList requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_accessible_list_new_from_list(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("AccessibleList requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_accessible_list_get_objects(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("AccessibleList requires GTK >= 4.14");
return Val_unit;
}


#endif
