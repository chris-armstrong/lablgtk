/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CellRendererToggle */

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


CAMLexport CAMLprim value ml_gtk_cell_renderer_toggle_new(value unit)
{
CAMLparam1(unit);

GtkCellRendererToggle *obj = gtk_cell_renderer_toggle_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkCellRendererToggle(obj));
}
CAMLexport CAMLprim value ml_gtk_cell_renderer_toggle_set_radio(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_cell_renderer_toggle_set_radio(GtkCellRendererToggle_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_toggle_set_active(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_cell_renderer_toggle_set_active(GtkCellRendererToggle_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_toggle_set_activatable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_cell_renderer_toggle_set_activatable(GtkCellRendererToggle_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_toggle_get_radio(value self)
{
CAMLparam1(self);

gboolean result = gtk_cell_renderer_toggle_get_radio(GtkCellRendererToggle_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_toggle_get_active(value self)
{
CAMLparam1(self);

gboolean result = gtk_cell_renderer_toggle_get_active(GtkCellRendererToggle_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_toggle_get_activatable(value self)
{
CAMLparam1(self);

gboolean result = gtk_cell_renderer_toggle_get_activatable(GtkCellRendererToggle_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_toggle_get_inconsistent(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererToggle *obj = (GtkCellRendererToggle *)GtkCellRendererToggle_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "inconsistent");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_toggle_get_inconsistent: property 'inconsistent' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "inconsistent", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_toggle_set_inconsistent(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererToggle *obj = (GtkCellRendererToggle *)GtkCellRendererToggle_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "inconsistent");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_toggle_set_inconsistent: property 'inconsistent' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "inconsistent", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_cell_renderer_toggle_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_cell_renderer_toggle_get_type()));
}
