/* GENERATED CODE - DO NOT EDIT */
/* C bindings for StackPage */

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


CAMLexport CAMLprim value ml_gtk_stack_page_set_visible(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_stack_page_set_visible(GtkStackPage_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_stack_page_set_use_underline(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_stack_page_set_use_underline(GtkStackPage_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_stack_page_set_title(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_stack_page_set_title(GtkStackPage_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_stack_page_set_needs_attention(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_stack_page_set_needs_attention(GtkStackPage_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_stack_page_set_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_stack_page_set_name(GtkStackPage_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_stack_page_set_icon_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_stack_page_set_icon_name(GtkStackPage_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_stack_page_get_visible(value self)
{
CAMLparam1(self);

gboolean result = gtk_stack_page_get_visible(GtkStackPage_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_stack_page_get_use_underline(value self)
{
CAMLparam1(self);

gboolean result = gtk_stack_page_get_use_underline(GtkStackPage_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_stack_page_get_title(value self)
{
CAMLparam1(self);

const char* result = gtk_stack_page_get_title(GtkStackPage_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_stack_page_get_needs_attention(value self)
{
CAMLparam1(self);

gboolean result = gtk_stack_page_get_needs_attention(GtkStackPage_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_stack_page_get_name(value self)
{
CAMLparam1(self);

const char* result = gtk_stack_page_get_name(GtkStackPage_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_stack_page_get_icon_name(value self)
{
CAMLparam1(self);

const char* result = gtk_stack_page_get_icon_name(GtkStackPage_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_stack_page_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_stack_page_get_child(GtkStackPage_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkWidget(result));
}


CAMLprim value ml_gtk_stack_page_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_stack_page_get_type()));
}
