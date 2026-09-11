/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FontDialog */

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


CAMLexport CAMLprim value ml_gtk_font_dialog_new(value unit)
{
CAMLparam1(unit);

GtkFontDialog *obj = gtk_font_dialog_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkFontDialog(obj));
}
CAMLexport CAMLprim value ml_gtk_font_dialog_set_title(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_dialog_set_title(GtkFontDialog_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_dialog_set_modal(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_dialog_set_modal(GtkFontDialog_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_dialog_set_language(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_dialog_set_language(GtkFontDialog_val(self), PangoLanguage_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_dialog_set_font_map(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_dialog_set_font_map(GtkFontDialog_val(self), Option_val(arg1, PangoFontMap_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_dialog_set_filter(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_dialog_set_filter(GtkFontDialog_val(self), Option_val(arg1, GtkFilter_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_dialog_get_title(value self)
{
CAMLparam1(self);

const char* result = gtk_font_dialog_get_title(GtkFontDialog_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_font_dialog_get_modal(value self)
{
CAMLparam1(self);

gboolean result = gtk_font_dialog_get_modal(GtkFontDialog_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_font_dialog_get_language(value self)
{
CAMLparam1(self);

PangoLanguage* result = gtk_font_dialog_get_language(GtkFontDialog_val(self));
CAMLreturn(Val_option(result, Val_PangoLanguage));
}

CAMLexport CAMLprim value ml_gtk_font_dialog_get_font_map(value self)
{
CAMLparam1(self);

PangoFontMap* result = gtk_font_dialog_get_font_map(GtkFontDialog_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_PangoFontMap));
}

CAMLexport CAMLprim value ml_gtk_font_dialog_get_filter(value self)
{
CAMLparam1(self);

GtkFilter* result = gtk_font_dialog_get_filter(GtkFontDialog_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkFilter));
}

CAMLexport CAMLprim value ml_gtk_font_dialog_choose_font_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

PangoFontDescription* result = gtk_font_dialog_choose_font_finish(GtkFontDialog_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_PangoFontDescription(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_font_dialog_choose_family_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

PangoFontFamily* result = gtk_font_dialog_choose_family_finish(GtkFontDialog_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_PangoFontFamily(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_font_dialog_choose_face_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

PangoFontFace* result = gtk_font_dialog_choose_face_finish(GtkFontDialog_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_PangoFontFace(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}


CAMLprim value ml_gtk_font_dialog_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_font_dialog_get_type()));
}

#else


CAMLexport CAMLprim value ml_gtk_font_dialog_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("FontDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_choose_face_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_choose_family_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_choose_font_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_get_filter(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_get_font_map(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_get_language(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_get_modal(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_get_title(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FontDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_set_filter(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_set_font_map(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_set_language(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_set_modal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_font_dialog_set_title(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FontDialog requires GTK >= 4.10");
return Val_unit;
}


#endif
