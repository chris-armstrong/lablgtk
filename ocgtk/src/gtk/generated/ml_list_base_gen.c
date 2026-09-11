/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ListBase */

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


CAMLexport CAMLprim value ml_gtk_list_base_get_orientation(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkListBase *obj = (GtkListBase *)GtkListBase_val(self);
    GtkOrientation prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "orientation");
if (pspec == NULL) caml_failwith("ml_gtk_list_base_get_orientation: property 'orientation' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "orientation", &prop_gvalue);
          prop_value = (GtkOrientation)g_value_get_enum(&prop_gvalue);

      result = Val_GtkOrientation(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_list_base_set_orientation(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkListBase *obj = (GtkListBase *)GtkListBase_val(self);
    GtkOrientation c_value = GtkOrientation_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "orientation");
if (pspec == NULL) caml_failwith("ml_gtk_list_base_set_orientation: property 'orientation' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "orientation", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_list_base_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_list_base_get_type()));
}
