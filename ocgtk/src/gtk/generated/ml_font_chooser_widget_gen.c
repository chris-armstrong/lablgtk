/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FontChooserWidget */

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


CAMLexport CAMLprim value ml_gtk_font_chooser_widget_new(value unit)
{
CAMLparam1(unit);

GtkFontChooserWidget *obj = gtk_font_chooser_widget_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkFontChooserWidget(obj));
}
CAMLexport CAMLprim value ml_gtk_font_chooser_widget_get_tweak_action(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkFontChooserWidget *obj = (GtkFontChooserWidget *)GtkFontChooserWidget_val(self);
    GAction *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "tweak-action");
if (pspec == NULL) caml_failwith("ml_gtk_font_chooser_widget_get_tweak_action: property 'tweak-action' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "tweak-action", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GAction(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}


CAMLprim value ml_gtk_font_chooser_widget_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_font_chooser_widget_get_type()));
}
