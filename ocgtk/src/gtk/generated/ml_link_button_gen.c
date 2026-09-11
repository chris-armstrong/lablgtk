/* GENERATED CODE - DO NOT EDIT */
/* C bindings for LinkButton */

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


CAMLexport CAMLprim value ml_gtk_link_button_new(value arg1)
{
CAMLparam1(arg1);

GtkLinkButton *obj = gtk_link_button_new(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkLinkButton(obj));
}
CAMLexport CAMLprim value ml_gtk_link_button_new_with_label(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkLinkButton *obj = gtk_link_button_new_with_label(String_val(arg1), String_option_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkLinkButton(obj));
}
CAMLexport CAMLprim value ml_gtk_link_button_set_visited(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_link_button_set_visited(GtkLinkButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_link_button_set_uri(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_link_button_set_uri(GtkLinkButton_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_link_button_get_visited(value self)
{
CAMLparam1(self);

gboolean result = gtk_link_button_get_visited(GtkLinkButton_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_link_button_get_uri(value self)
{
CAMLparam1(self);

const char* result = gtk_link_button_get_uri(GtkLinkButton_val(self));
CAMLreturn(caml_copy_string(result));
}

GType gtk_link_button_get_type (void);


CAMLprim value ml_gtk_link_button_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_link_button_get_type()));
}
