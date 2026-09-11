/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FontDialogButton */

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


CAMLexport CAMLprim value ml_gtk_font_dialog_button_new(value arg1)
{
CAMLparam1(arg1);

GtkFontDialogButton *obj = gtk_font_dialog_button_new(Option_val(arg1, GtkFontDialog_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkFontDialogButton(obj));
}
CAMLexport CAMLprim value ml_gtk_font_dialog_button_set_use_size(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_dialog_button_set_use_size(GtkFontDialogButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_dialog_button_set_use_font(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_dialog_button_set_use_font(GtkFontDialogButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_dialog_button_set_level(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_dialog_button_set_level(GtkFontDialogButton_val(self), GtkFontLevel_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_dialog_button_set_language(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_dialog_button_set_language(GtkFontDialogButton_val(self), Option_val(arg1, PangoLanguage_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_dialog_button_set_font_features(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_dialog_button_set_font_features(GtkFontDialogButton_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_dialog_button_set_font_desc(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_dialog_button_set_font_desc(GtkFontDialogButton_val(self), PangoFontDescription_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_dialog_button_set_dialog(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_dialog_button_set_dialog(GtkFontDialogButton_val(self), GtkFontDialog_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_dialog_button_get_use_size(value self)
{
CAMLparam1(self);

gboolean result = gtk_font_dialog_button_get_use_size(GtkFontDialogButton_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_font_dialog_button_get_use_font(value self)
{
CAMLparam1(self);

gboolean result = gtk_font_dialog_button_get_use_font(GtkFontDialogButton_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_font_dialog_button_get_level(value self)
{
CAMLparam1(self);

GtkFontLevel result = gtk_font_dialog_button_get_level(GtkFontDialogButton_val(self));
CAMLreturn(Val_GtkFontLevel(result));
}

CAMLexport CAMLprim value ml_gtk_font_dialog_button_get_language(value self)
{
CAMLparam1(self);

PangoLanguage* result = gtk_font_dialog_button_get_language(GtkFontDialogButton_val(self));
CAMLreturn(Val_option(result, Val_PangoLanguage));
}

CAMLexport CAMLprim value ml_gtk_font_dialog_button_get_font_features(value self)
{
CAMLparam1(self);

const char* result = gtk_font_dialog_button_get_font_features(GtkFontDialogButton_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_font_dialog_button_get_font_desc(value self)
{
CAMLparam1(self);

PangoFontDescription* result = gtk_font_dialog_button_get_font_desc(GtkFontDialogButton_val(self));
if (result) result = g_boxed_copy(pango_font_description_get_type(), result);
CAMLreturn(Val_option(result, Val_PangoFontDescription));
}

CAMLexport CAMLprim value ml_gtk_font_dialog_button_get_dialog(value self)
{
CAMLparam1(self);

GtkFontDialog* result = gtk_font_dialog_button_get_dialog(GtkFontDialogButton_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkFontDialog));
}


CAMLprim value ml_gtk_font_dialog_button_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_font_dialog_button_get_type()));
}

#else


CAMLexport CAMLprim value ml_gtk_font_dialog_button_new(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("FontDialogButton requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_button_get_dialog(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontDialogButton requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_button_get_font_desc(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontDialogButton requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_button_get_font_features(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontDialogButton requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_button_get_language(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontDialogButton requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_button_get_level(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontDialogButton requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_button_get_use_font(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontDialogButton requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_button_get_use_size(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontDialogButton requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_button_set_dialog(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDialogButton requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_button_set_font_desc(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDialogButton requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_button_set_font_features(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDialogButton requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_button_set_language(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDialogButton requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_button_set_level(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDialogButton requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_button_set_use_font(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDialogButton requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_button_set_use_size(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDialogButton requires GTK >= 4.10");
return Val_unit;
}


#endif
