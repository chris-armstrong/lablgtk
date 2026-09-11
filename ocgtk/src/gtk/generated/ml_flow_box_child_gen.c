/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FlowBoxChild */

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


CAMLexport CAMLprim value ml_gtk_flow_box_child_new(value unit)
{
CAMLparam1(unit);

GtkFlowBoxChild *obj = gtk_flow_box_child_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkFlowBoxChild(obj));
}
CAMLexport CAMLprim value ml_gtk_flow_box_child_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_flow_box_child_set_child(GtkFlowBoxChild_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_flow_box_child_is_selected(value self)
{
CAMLparam1(self);

gboolean result = gtk_flow_box_child_is_selected(GtkFlowBoxChild_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_flow_box_child_get_index(value self)
{
CAMLparam1(self);

int result = gtk_flow_box_child_get_index(GtkFlowBoxChild_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_flow_box_child_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_flow_box_child_get_child(GtkFlowBoxChild_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_flow_box_child_changed(value self)
{
CAMLparam1(self);

gtk_flow_box_child_changed(GtkFlowBoxChild_val(self));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_flow_box_child_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_flow_box_child_get_type()));
}
