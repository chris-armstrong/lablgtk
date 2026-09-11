/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SizeGroup */

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


CAMLexport CAMLprim value ml_gtk_size_group_new(value arg1)
{
CAMLparam1(arg1);

GtkSizeGroup *obj = gtk_size_group_new(GtkSizeGroupMode_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkSizeGroup(obj));
}
CAMLexport CAMLprim value ml_gtk_size_group_set_mode(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_size_group_set_mode(GtkSizeGroup_val(self), GtkSizeGroupMode_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_size_group_remove_widget(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_size_group_remove_widget(GtkSizeGroup_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_size_group_get_widgets(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = gtk_size_group_get_widgets(GtkSizeGroup_val(self));
Val_GSList_with(c_result, result, item, cell, Val_GtkWidget((gpointer)_tmp->data));
    CAMLreturn(result);
}

CAMLexport CAMLprim value ml_gtk_size_group_get_mode(value self)
{
CAMLparam1(self);

GtkSizeGroupMode result = gtk_size_group_get_mode(GtkSizeGroup_val(self));
CAMLreturn(Val_GtkSizeGroupMode(result));
}

CAMLexport CAMLprim value ml_gtk_size_group_add_widget(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_size_group_add_widget(GtkSizeGroup_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_size_group_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_size_group_get_type()));
}
