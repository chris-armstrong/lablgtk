/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ColorDialogButton */

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

#if GTK_CHECK_VERSION(4,10,0)


CAMLexport CAMLprim value ml_gtk_color_dialog_button_new(value arg1)
{
CAMLparam1(arg1);

GtkColorDialogButton *obj = gtk_color_dialog_button_new(Option_val(arg1, GtkColorDialog_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkColorDialogButton(obj));
}
CAMLexport CAMLprim value ml_gtk_color_dialog_button_set_rgba(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_color_dialog_button_set_rgba(GtkColorDialogButton_val(self), GdkRGBA_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_color_dialog_button_set_dialog(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_color_dialog_button_set_dialog(GtkColorDialogButton_val(self), GtkColorDialog_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_color_dialog_button_get_rgba(value self)
{
CAMLparam1(self);

const GdkRGBA* result = gtk_color_dialog_button_get_rgba(GtkColorDialogButton_val(self));
if (result) result = g_boxed_copy(gdk_rgba_get_type(), result);
CAMLreturn(Val_GdkRGBA(result));
}

CAMLexport CAMLprim value ml_gtk_color_dialog_button_get_dialog(value self)
{
CAMLparam1(self);

GtkColorDialog* result = gtk_color_dialog_button_get_dialog(GtkColorDialogButton_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkColorDialog));
}


CAMLprim value ml_gtk_color_dialog_button_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_color_dialog_button_get_type()));
}

#else


CAMLexport CAMLprim value ml_gtk_color_dialog_button_new(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("ColorDialogButton requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_color_dialog_button_get_dialog(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ColorDialogButton requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_color_dialog_button_get_rgba(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ColorDialogButton requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_color_dialog_button_set_dialog(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ColorDialogButton requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_color_dialog_button_set_rgba(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ColorDialogButton requires GTK >= 4.10");
return Val_unit;
}


#endif
