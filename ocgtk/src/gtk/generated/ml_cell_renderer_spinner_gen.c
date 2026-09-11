/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CellRendererSpinner */

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


CAMLexport CAMLprim value ml_gtk_cell_renderer_spinner_new(value unit)
{
CAMLparam1(unit);

GtkCellRendererSpinner *obj = gtk_cell_renderer_spinner_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkCellRendererSpinner(obj));
}
CAMLexport CAMLprim value ml_gtk_cell_renderer_spinner_get_active(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererSpinner *obj = (GtkCellRendererSpinner *)GtkCellRendererSpinner_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "active");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_spinner_get_active: property 'active' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "active", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_spinner_set_active(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererSpinner *obj = (GtkCellRendererSpinner *)GtkCellRendererSpinner_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "active");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_spinner_set_active: property 'active' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "active", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_spinner_get_pulse(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererSpinner *obj = (GtkCellRendererSpinner *)GtkCellRendererSpinner_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pulse");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_spinner_get_pulse: property 'pulse' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "pulse", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_spinner_set_pulse(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererSpinner *obj = (GtkCellRendererSpinner *)GtkCellRendererSpinner_val(self);
    guint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pulse");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_spinner_set_pulse: property 'pulse' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_uint(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "pulse", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_spinner_get_size(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererSpinner *obj = (GtkCellRendererSpinner *)GtkCellRendererSpinner_val(self);
    GtkIconSize prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "size");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_spinner_get_size: property 'size' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "size", &prop_gvalue);
          prop_value = (GtkIconSize)g_value_get_enum(&prop_gvalue);

      result = Val_GtkIconSize(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_spinner_set_size(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererSpinner *obj = (GtkCellRendererSpinner *)GtkCellRendererSpinner_val(self);
    GtkIconSize c_value = GtkIconSize_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "size");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_spinner_set_size: property 'size' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "size", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

GType gtk_cell_renderer_spinner_get_type (void);


CAMLprim value ml_gtk_cell_renderer_spinner_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_cell_renderer_spinner_get_type()));
}
