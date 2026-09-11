/* GENERATED CODE - DO NOT EDIT */
/* C bindings for NativeDialog */

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


CAMLexport CAMLprim value ml_gtk_native_dialog_show(value self)
{
CAMLparam1(self);

gtk_native_dialog_show(GtkNativeDialog_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_native_dialog_set_transient_for(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_native_dialog_set_transient_for(GtkNativeDialog_val(self), Option_val(arg1, GtkWindow_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_native_dialog_set_title(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_native_dialog_set_title(GtkNativeDialog_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_native_dialog_set_modal(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_native_dialog_set_modal(GtkNativeDialog_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_native_dialog_hide(value self)
{
CAMLparam1(self);

gtk_native_dialog_hide(GtkNativeDialog_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_native_dialog_get_visible(value self)
{
CAMLparam1(self);

gboolean result = gtk_native_dialog_get_visible(GtkNativeDialog_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_native_dialog_get_transient_for(value self)
{
CAMLparam1(self);

GtkWindow* result = gtk_native_dialog_get_transient_for(GtkNativeDialog_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWindow));
}

CAMLexport CAMLprim value ml_gtk_native_dialog_get_title(value self)
{
CAMLparam1(self);

const char* result = gtk_native_dialog_get_title(GtkNativeDialog_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_native_dialog_get_modal(value self)
{
CAMLparam1(self);

gboolean result = gtk_native_dialog_get_modal(GtkNativeDialog_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_native_dialog_destroy(value self)
{
CAMLparam1(self);

gtk_native_dialog_destroy(GtkNativeDialog_val(self));
CAMLreturn(Val_unit);
}

GType gtk_native_dialog_get_type (void);


CAMLprim value ml_gtk_native_dialog_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_native_dialog_get_type()));
}
