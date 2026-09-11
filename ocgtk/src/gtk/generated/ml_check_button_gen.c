/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CheckButton */

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


CAMLexport CAMLprim value ml_gtk_check_button_new(value unit)
{
CAMLparam1(unit);

GtkCheckButton *obj = gtk_check_button_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkCheckButton(obj));
}
CAMLexport CAMLprim value ml_gtk_check_button_new_with_label(value arg1)
{
CAMLparam1(arg1);

GtkCheckButton *obj = gtk_check_button_new_with_label(String_option_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkCheckButton(obj));
}
CAMLexport CAMLprim value ml_gtk_check_button_new_with_mnemonic(value arg1)
{
CAMLparam1(arg1);

GtkCheckButton *obj = gtk_check_button_new_with_mnemonic(String_option_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkCheckButton(obj));
}
CAMLexport CAMLprim value ml_gtk_check_button_set_use_underline(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_check_button_set_use_underline(GtkCheckButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_check_button_set_label(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_check_button_set_label(GtkCheckButton_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_check_button_set_inconsistent(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_check_button_set_inconsistent(GtkCheckButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_check_button_set_group(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_check_button_set_group(GtkCheckButton_val(self), Option_val(arg1, GtkCheckButton_val, NULL));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,8,0)

CAMLexport CAMLprim value ml_gtk_check_button_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_check_button_set_child(GtkCheckButton_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_check_button_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("CheckButton requires GTK >= 4.8");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_check_button_set_active(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_check_button_set_active(GtkCheckButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_check_button_get_use_underline(value self)
{
CAMLparam1(self);

gboolean result = gtk_check_button_get_use_underline(GtkCheckButton_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_check_button_get_label(value self)
{
CAMLparam1(self);

const char* result = gtk_check_button_get_label(GtkCheckButton_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_check_button_get_inconsistent(value self)
{
CAMLparam1(self);

gboolean result = gtk_check_button_get_inconsistent(GtkCheckButton_val(self));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,8,0)

CAMLexport CAMLprim value ml_gtk_check_button_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_check_button_get_child(GtkCheckButton_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

#else

CAMLexport CAMLprim value ml_gtk_check_button_get_child(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("CheckButton requires GTK >= 4.8");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_check_button_get_active(value self)
{
CAMLparam1(self);

gboolean result = gtk_check_button_get_active(GtkCheckButton_val(self));
CAMLreturn(Val_bool(result));
}

GType gtk_check_button_get_type (void);


CAMLprim value ml_gtk_check_button_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_check_button_get_type()));
}
