/* GENERATED CODE - DO NOT EDIT */
/* C bindings for VolumeButton */

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


CAMLexport CAMLprim value ml_gtk_volume_button_new(value unit)
{
CAMLparam1(unit);

GtkVolumeButton *obj = gtk_volume_button_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkVolumeButton(obj));
}
CAMLexport CAMLprim value ml_gtk_volume_button_get_use_symbolic(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkVolumeButton *obj = (GtkVolumeButton *)GtkVolumeButton_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "use-symbolic");
if (pspec == NULL) caml_failwith("ml_gtk_volume_button_get_use_symbolic: property 'use-symbolic' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "use-symbolic", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_volume_button_set_use_symbolic(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkVolumeButton *obj = (GtkVolumeButton *)GtkVolumeButton_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "use-symbolic");
if (pspec == NULL) caml_failwith("ml_gtk_volume_button_set_use_symbolic: property 'use-symbolic' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "use-symbolic", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_volume_button_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_volume_button_get_type()));
}
