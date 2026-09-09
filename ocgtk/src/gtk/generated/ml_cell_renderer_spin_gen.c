/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CellRendererSpin */

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


CAMLexport CAMLprim value ml_gtk_cell_renderer_spin_new(value unit)
{
CAMLparam1(unit);

GtkCellRendererSpin *obj = gtk_cell_renderer_spin_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkCellRendererSpin(obj));
}
CAMLexport CAMLprim value ml_gtk_cell_renderer_spin_get_adjustment(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererSpin *obj = (GtkCellRendererSpin *)GtkCellRendererSpin_val(self);
    GtkAdjustment *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "adjustment");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_spin_get_adjustment: property 'adjustment' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "adjustment", &prop_gvalue);
          prop_value = (GtkAdjustment*)g_value_dup_object(&prop_gvalue);

      result = Val_GtkAdjustment(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_spin_set_adjustment(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererSpin *obj = (GtkCellRendererSpin *)GtkCellRendererSpin_val(self);
    GtkAdjustment *c_value = GtkAdjustment_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "adjustment");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_spin_set_adjustment: property 'adjustment' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_object(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "adjustment", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_spin_get_climb_rate(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererSpin *obj = (GtkCellRendererSpin *)GtkCellRendererSpin_val(self);
    gdouble prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "climb-rate");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_spin_get_climb_rate: property 'climb-rate' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "climb-rate", &prop_gvalue);
          prop_value = g_value_get_double(&prop_gvalue);

      result = caml_copy_double(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_spin_set_climb_rate(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererSpin *obj = (GtkCellRendererSpin *)GtkCellRendererSpin_val(self);
    gdouble c_value = Double_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "climb-rate");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_spin_set_climb_rate: property 'climb-rate' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_double(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "climb-rate", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_spin_get_digits(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererSpin *obj = (GtkCellRendererSpin *)GtkCellRendererSpin_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "digits");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_spin_get_digits: property 'digits' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "digits", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_spin_set_digits(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererSpin *obj = (GtkCellRendererSpin *)GtkCellRendererSpin_val(self);
    guint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "digits");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_spin_set_digits: property 'digits' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_uint(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "digits", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}
