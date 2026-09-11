/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FontChooser */

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


CAMLexport CAMLprim value ml_gtk_font_chooser_set_show_preview_entry(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_chooser_set_show_preview_entry(GtkFontChooser_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_chooser_set_preview_text(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_chooser_set_preview_text(GtkFontChooser_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_chooser_set_level(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_chooser_set_level(GtkFontChooser_val(self), GtkFontChooserLevel_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_chooser_set_language(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_chooser_set_language(GtkFontChooser_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_chooser_set_font_map(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_chooser_set_font_map(GtkFontChooser_val(self), Option_val(arg1, PangoFontMap_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_chooser_set_font_desc(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_chooser_set_font_desc(GtkFontChooser_val(self), PangoFontDescription_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_chooser_set_font(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_font_chooser_set_font(GtkFontChooser_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_font_chooser_get_show_preview_entry(value self)
{
CAMLparam1(self);

gboolean result = gtk_font_chooser_get_show_preview_entry(GtkFontChooser_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_font_chooser_get_preview_text(value self)
{
CAMLparam1(self);

char* result = gtk_font_chooser_get_preview_text(GtkFontChooser_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_font_chooser_get_level(value self)
{
CAMLparam1(self);

GtkFontChooserLevel result = gtk_font_chooser_get_level(GtkFontChooser_val(self));
CAMLreturn(Val_GtkFontChooserLevel(result));
}

CAMLexport CAMLprim value ml_gtk_font_chooser_get_language(value self)
{
CAMLparam1(self);

char* result = gtk_font_chooser_get_language(GtkFontChooser_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_font_chooser_get_font_size(value self)
{
CAMLparam1(self);

int result = gtk_font_chooser_get_font_size(GtkFontChooser_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_font_chooser_get_font_map(value self)
{
CAMLparam1(self);

PangoFontMap* result = gtk_font_chooser_get_font_map(GtkFontChooser_val(self));
CAMLreturn(Val_option(result, Val_PangoFontMap));
}

CAMLexport CAMLprim value ml_gtk_font_chooser_get_font_features(value self)
{
CAMLparam1(self);

char* result = gtk_font_chooser_get_font_features(GtkFontChooser_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_font_chooser_get_font_family(value self)
{
CAMLparam1(self);

PangoFontFamily* result = gtk_font_chooser_get_font_family(GtkFontChooser_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_PangoFontFamily));
}

CAMLexport CAMLprim value ml_gtk_font_chooser_get_font_face(value self)
{
CAMLparam1(self);

PangoFontFace* result = gtk_font_chooser_get_font_face(GtkFontChooser_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_PangoFontFace));
}

CAMLexport CAMLprim value ml_gtk_font_chooser_get_font_desc(value self)
{
CAMLparam1(self);

PangoFontDescription* result = gtk_font_chooser_get_font_desc(GtkFontChooser_val(self));
CAMLreturn(Val_option(result, Val_PangoFontDescription));
}

CAMLexport CAMLprim value ml_gtk_font_chooser_get_font(value self)
{
CAMLparam1(self);

char* result = gtk_font_chooser_get_font(GtkFontChooser_val(self));
CAMLreturn(Val_option_string(result));
}
CAMLexport CAMLprim value ml_gtk_font_chooser_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GTK_TYPE_FONT_CHOOSER)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GtkFontChooser");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GtkFontChooser((GtkFontChooser*)gobj));
}

GType gtk_font_chooser_get_type (void);


CAMLprim value ml_gtk_font_chooser_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_font_chooser_get_type()));
}
