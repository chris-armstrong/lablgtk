/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ListBoxRow */

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


CAMLexport CAMLprim value ml_gtk_list_box_row_new(value unit)
{
CAMLparam1(unit);

GtkListBoxRow *obj = gtk_list_box_row_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkListBoxRow(obj));
}
CAMLexport CAMLprim value ml_gtk_list_box_row_set_selectable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_box_row_set_selectable(GtkListBoxRow_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_list_box_row_set_header(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_box_row_set_header(GtkListBoxRow_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_list_box_row_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_box_row_set_child(GtkListBoxRow_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_list_box_row_set_activatable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_box_row_set_activatable(GtkListBoxRow_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_list_box_row_is_selected(value self)
{
CAMLparam1(self);

gboolean result = gtk_list_box_row_is_selected(GtkListBoxRow_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_list_box_row_get_selectable(value self)
{
CAMLparam1(self);

gboolean result = gtk_list_box_row_get_selectable(GtkListBoxRow_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_list_box_row_get_index(value self)
{
CAMLparam1(self);

int result = gtk_list_box_row_get_index(GtkListBoxRow_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_list_box_row_get_header(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_list_box_row_get_header(GtkListBoxRow_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_list_box_row_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_list_box_row_get_child(GtkListBoxRow_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_list_box_row_get_activatable(value self)
{
CAMLparam1(self);

gboolean result = gtk_list_box_row_get_activatable(GtkListBoxRow_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_list_box_row_changed(value self)
{
CAMLparam1(self);

gtk_list_box_row_changed(GtkListBoxRow_val(self));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_list_box_row_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_list_box_row_get_type()));
}
