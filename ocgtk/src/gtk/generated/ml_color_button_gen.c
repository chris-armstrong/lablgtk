/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ColorButton */

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


CAMLexport CAMLprim value ml_gtk_color_button_new(value unit)
{
CAMLparam1(unit);

GtkColorButton *obj = gtk_color_button_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkColorButton(obj));
}
CAMLexport CAMLprim value ml_gtk_color_button_new_with_rgba(value arg1)
{
CAMLparam1(arg1);

GtkColorButton *obj = gtk_color_button_new_with_rgba(GdkRGBA_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkColorButton(obj));
}
CAMLexport CAMLprim value ml_gtk_color_button_set_title(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_color_button_set_title(GtkColorButton_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_color_button_set_modal(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_color_button_set_modal(GtkColorButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_color_button_get_title(value self)
{
CAMLparam1(self);

const char* result = gtk_color_button_get_title(GtkColorButton_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_color_button_get_modal(value self)
{
CAMLparam1(self);

gboolean result = gtk_color_button_get_modal(GtkColorButton_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_color_button_get_show_editor(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkColorButton *obj = (GtkColorButton *)GtkColorButton_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "show-editor");
if (pspec == NULL) caml_failwith("ml_gtk_color_button_get_show_editor: property 'show-editor' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "show-editor", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_color_button_set_show_editor(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkColorButton *obj = (GtkColorButton *)GtkColorButton_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "show-editor");
if (pspec == NULL) caml_failwith("ml_gtk_color_button_set_show_editor: property 'show-editor' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "show-editor", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

GType gtk_color_button_get_type (void);


CAMLprim value ml_gtk_color_button_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_color_button_get_type()));
}
