/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Button */

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


CAMLexport CAMLprim value ml_gtk_button_new(value unit)
{
CAMLparam1(unit);

GtkButton *obj = gtk_button_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkButton(obj));
}
CAMLexport CAMLprim value ml_gtk_button_new_from_icon_name(value arg1)
{
CAMLparam1(arg1);

GtkButton *obj = gtk_button_new_from_icon_name(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkButton(obj));
}
CAMLexport CAMLprim value ml_gtk_button_new_with_label(value arg1)
{
CAMLparam1(arg1);

GtkButton *obj = gtk_button_new_with_label(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkButton(obj));
}
CAMLexport CAMLprim value ml_gtk_button_new_with_mnemonic(value arg1)
{
CAMLparam1(arg1);

GtkButton *obj = gtk_button_new_with_mnemonic(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkButton(obj));
}
CAMLexport CAMLprim value ml_gtk_button_set_use_underline(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_button_set_use_underline(GtkButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_button_set_label(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_button_set_label(GtkButton_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_button_set_icon_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_button_set_icon_name(GtkButton_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_button_set_has_frame(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_button_set_has_frame(GtkButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_button_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_button_set_child(GtkButton_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_button_set_can_shrink(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_button_set_can_shrink(GtkButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_button_set_can_shrink(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Button requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_button_get_use_underline(value self)
{
CAMLparam1(self);

gboolean result = gtk_button_get_use_underline(GtkButton_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_button_get_label(value self)
{
CAMLparam1(self);

const char* result = gtk_button_get_label(GtkButton_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_button_get_icon_name(value self)
{
CAMLparam1(self);

const char* result = gtk_button_get_icon_name(GtkButton_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_button_get_has_frame(value self)
{
CAMLparam1(self);

gboolean result = gtk_button_get_has_frame(GtkButton_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_button_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_button_get_child(GtkButton_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_button_get_can_shrink(value self)
{
CAMLparam1(self);

gboolean result = gtk_button_get_can_shrink(GtkButton_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gtk_button_get_can_shrink(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Button requires GTK >= 4.12");
return Val_unit;
}
#endif


CAMLprim value ml_gtk_button_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_button_get_type()));
}
