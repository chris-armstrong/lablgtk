/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Fixed */

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


CAMLexport CAMLprim value ml_gtk_fixed_new(value unit)
{
CAMLparam1(unit);

GtkFixed *obj = gtk_fixed_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkFixed(obj));
}
CAMLexport CAMLprim value ml_gtk_fixed_set_child_transform(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_fixed_set_child_transform(GtkFixed_val(self), GtkWidget_val(arg1), Option_val(arg2, GskTransform_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_fixed_remove(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_fixed_remove(GtkFixed_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_fixed_put(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_fixed_put(GtkFixed_val(self), GtkWidget_val(arg1), Double_val(arg2), Double_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_fixed_move(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_fixed_move(GtkFixed_val(self), GtkWidget_val(arg1), Double_val(arg2), Double_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_fixed_get_child_transform(value self, value arg1)
{
CAMLparam2(self, arg1);

GskTransform* result = gtk_fixed_get_child_transform(GtkFixed_val(self), GtkWidget_val(arg1));
if (result) result = g_boxed_copy(gsk_transform_get_type(), result);
CAMLreturn(Val_option(result, Val_GskTransform));
}

CAMLexport CAMLprim value ml_gtk_fixed_get_child_position(value self, value arg1)
{
CAMLparam2(self, arg1);
double out2;
double out3;

gtk_fixed_get_child_position(GtkFixed_val(self), GtkWidget_val(arg1), &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, caml_copy_double(out2));
    Store_field(ret, 1, caml_copy_double(out3));
    CAMLreturn(ret);
}


CAMLprim value ml_gtk_fixed_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_fixed_get_type()));
}
