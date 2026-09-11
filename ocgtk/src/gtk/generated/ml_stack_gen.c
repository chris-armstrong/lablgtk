/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Stack */

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


CAMLexport CAMLprim value ml_gtk_stack_new(value unit)
{
CAMLparam1(unit);

GtkStack *obj = gtk_stack_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkStack(obj));
}
CAMLexport CAMLprim value ml_gtk_stack_set_visible_child_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_stack_set_visible_child_name(GtkStack_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_stack_set_visible_child_full(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_stack_set_visible_child_full(GtkStack_val(self), String_val(arg1), GtkStackTransitionType_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_stack_set_visible_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_stack_set_visible_child(GtkStack_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_stack_set_vhomogeneous(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_stack_set_vhomogeneous(GtkStack_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_stack_set_transition_type(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_stack_set_transition_type(GtkStack_val(self), GtkStackTransitionType_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_stack_set_transition_duration(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_stack_set_transition_duration(GtkStack_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_stack_set_interpolate_size(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_stack_set_interpolate_size(GtkStack_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_stack_set_hhomogeneous(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_stack_set_hhomogeneous(GtkStack_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_stack_remove(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_stack_remove(GtkStack_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_stack_get_visible_child_name(value self)
{
CAMLparam1(self);

const char* result = gtk_stack_get_visible_child_name(GtkStack_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_stack_get_visible_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_stack_get_visible_child(GtkStack_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_stack_get_vhomogeneous(value self)
{
CAMLparam1(self);

gboolean result = gtk_stack_get_vhomogeneous(GtkStack_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_stack_get_transition_type(value self)
{
CAMLparam1(self);

GtkStackTransitionType result = gtk_stack_get_transition_type(GtkStack_val(self));
CAMLreturn(Val_GtkStackTransitionType(result));
}

CAMLexport CAMLprim value ml_gtk_stack_get_transition_running(value self)
{
CAMLparam1(self);

gboolean result = gtk_stack_get_transition_running(GtkStack_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_stack_get_transition_duration(value self)
{
CAMLparam1(self);

guint result = gtk_stack_get_transition_duration(GtkStack_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_stack_get_pages(value self)
{
CAMLparam1(self);

GtkSelectionModel* result = gtk_stack_get_pages(GtkStack_val(self));
CAMLreturn(Val_GtkSelectionModel(result));
}

CAMLexport CAMLprim value ml_gtk_stack_get_page(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkStackPage* result = gtk_stack_get_page(GtkStack_val(self), GtkWidget_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkStackPage(result));
}

CAMLexport CAMLprim value ml_gtk_stack_get_interpolate_size(value self)
{
CAMLparam1(self);

gboolean result = gtk_stack_get_interpolate_size(GtkStack_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_stack_get_hhomogeneous(value self)
{
CAMLparam1(self);

gboolean result = gtk_stack_get_hhomogeneous(GtkStack_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_stack_get_child_by_name(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkWidget* result = gtk_stack_get_child_by_name(GtkStack_val(self), String_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_stack_add_titled(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

GtkStackPage* result = gtk_stack_add_titled(GtkStack_val(self), GtkWidget_val(arg1), String_option_val(arg2), String_val(arg3));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkStackPage(result));
}

CAMLexport CAMLprim value ml_gtk_stack_add_named(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

GtkStackPage* result = gtk_stack_add_named(GtkStack_val(self), GtkWidget_val(arg1), String_option_val(arg2));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkStackPage(result));
}

CAMLexport CAMLprim value ml_gtk_stack_add_child(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkStackPage* result = gtk_stack_add_child(GtkStack_val(self), GtkWidget_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkStackPage(result));
}

GType gtk_stack_get_type (void);


CAMLprim value ml_gtk_stack_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_stack_get_type()));
}
