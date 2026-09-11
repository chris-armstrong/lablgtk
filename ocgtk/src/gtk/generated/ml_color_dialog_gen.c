/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ColorDialog */

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


CAMLexport CAMLprim value ml_gtk_color_dialog_new(value unit)
{
CAMLparam1(unit);

GtkColorDialog *obj = gtk_color_dialog_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkColorDialog(obj));
}
CAMLexport CAMLprim value ml_gtk_color_dialog_set_with_alpha(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_color_dialog_set_with_alpha(GtkColorDialog_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_color_dialog_set_title(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_color_dialog_set_title(GtkColorDialog_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_color_dialog_set_modal(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_color_dialog_set_modal(GtkColorDialog_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_color_dialog_get_with_alpha(value self)
{
CAMLparam1(self);

gboolean result = gtk_color_dialog_get_with_alpha(GtkColorDialog_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_color_dialog_get_title(value self)
{
CAMLparam1(self);

const char* result = gtk_color_dialog_get_title(GtkColorDialog_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_color_dialog_get_modal(value self)
{
CAMLparam1(self);

gboolean result = gtk_color_dialog_get_modal(GtkColorDialog_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_color_dialog_choose_rgba_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GdkRGBA* result = gtk_color_dialog_choose_rgba_finish(GtkColorDialog_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GdkRGBA(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

GType gtk_color_dialog_get_type (void);


CAMLprim value ml_gtk_color_dialog_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_color_dialog_get_type()));
}

#else


CAMLexport CAMLprim value ml_gtk_color_dialog_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("ColorDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_color_dialog_choose_rgba_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ColorDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_color_dialog_get_modal(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ColorDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_color_dialog_get_title(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ColorDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_color_dialog_get_with_alpha(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ColorDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_color_dialog_set_modal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ColorDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_color_dialog_set_title(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ColorDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_color_dialog_set_with_alpha(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ColorDialog requires GTK >= 4.10");
return Val_unit;
}


#endif
