/* GENERATED CODE - DO NOT EDIT */
/* C bindings for LayoutManager */

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


CAMLexport CAMLprim value ml_gtk_layout_manager_measure(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
int out4;
int out5;
int out6;
int out7;

gtk_layout_manager_measure(GtkLayoutManager_val(self), GtkWidget_val(arg1), GtkOrientation_val(arg2), Int_val(arg3), &out4, &out5, &out6, &out7);
CAMLlocal1(ret);
    ret = caml_alloc(4, 0);
    Store_field(ret, 0, Val_int(out4));
    Store_field(ret, 1, Val_int(out5));
    Store_field(ret, 2, Val_int(out6));
    Store_field(ret, 3, Val_int(out7));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_layout_manager_layout_changed(value self)
{
CAMLparam1(self);

gtk_layout_manager_layout_changed(GtkLayoutManager_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_layout_manager_get_widget(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_layout_manager_get_widget(GtkLayoutManager_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_layout_manager_get_request_mode(value self)
{
CAMLparam1(self);

GtkSizeRequestMode result = gtk_layout_manager_get_request_mode(GtkLayoutManager_val(self));
CAMLreturn(Val_GtkSizeRequestMode(result));
}

CAMLexport CAMLprim value ml_gtk_layout_manager_get_layout_child(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkLayoutChild* result = gtk_layout_manager_get_layout_child(GtkLayoutManager_val(self), GtkWidget_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkLayoutChild(result));
}

CAMLexport CAMLprim value ml_gtk_layout_manager_allocate(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gtk_layout_manager_allocate(GtkLayoutManager_val(self), GtkWidget_val(arg1), Int_val(arg2), Int_val(arg3), Int_val(arg4));
CAMLreturn(Val_unit);
}

GType gtk_layout_manager_get_type (void);


CAMLprim value ml_gtk_layout_manager_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_layout_manager_get_type()));
}
