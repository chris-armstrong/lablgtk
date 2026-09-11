/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CellRendererProgress */

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


CAMLexport CAMLprim value ml_gtk_cell_renderer_progress_new(value unit)
{
CAMLparam1(unit);

GtkCellRendererProgress *obj = gtk_cell_renderer_progress_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkCellRendererProgress(obj));
}
CAMLexport CAMLprim value ml_gtk_cell_renderer_progress_get_inverted(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererProgress *obj = (GtkCellRendererProgress *)GtkCellRendererProgress_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "inverted");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_progress_get_inverted: property 'inverted' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "inverted", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_progress_set_inverted(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererProgress *obj = (GtkCellRendererProgress *)GtkCellRendererProgress_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "inverted");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_progress_set_inverted: property 'inverted' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "inverted", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_progress_get_pulse(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererProgress *obj = (GtkCellRendererProgress *)GtkCellRendererProgress_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pulse");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_progress_get_pulse: property 'pulse' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "pulse", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_progress_set_pulse(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererProgress *obj = (GtkCellRendererProgress *)GtkCellRendererProgress_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pulse");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_progress_set_pulse: property 'pulse' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "pulse", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_progress_get_text(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererProgress *obj = (GtkCellRendererProgress *)GtkCellRendererProgress_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "text");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_progress_get_text: property 'text' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "text", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_progress_set_text(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererProgress *obj = (GtkCellRendererProgress *)GtkCellRendererProgress_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "text");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_progress_set_text: property 'text' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "text", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_progress_get_text_xalign(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererProgress *obj = (GtkCellRendererProgress *)GtkCellRendererProgress_val(self);
    gfloat prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "text-xalign");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_progress_get_text_xalign: property 'text-xalign' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "text-xalign", &prop_gvalue);
          prop_value = g_value_get_float(&prop_gvalue);

      result = caml_copy_double(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_progress_set_text_xalign(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererProgress *obj = (GtkCellRendererProgress *)GtkCellRendererProgress_val(self);
    gfloat c_value = Double_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "text-xalign");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_progress_set_text_xalign: property 'text-xalign' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_float(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "text-xalign", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_progress_get_text_yalign(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererProgress *obj = (GtkCellRendererProgress *)GtkCellRendererProgress_val(self);
    gfloat prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "text-yalign");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_progress_get_text_yalign: property 'text-yalign' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "text-yalign", &prop_gvalue);
          prop_value = g_value_get_float(&prop_gvalue);

      result = caml_copy_double(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_progress_set_text_yalign(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererProgress *obj = (GtkCellRendererProgress *)GtkCellRendererProgress_val(self);
    gfloat c_value = Double_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "text-yalign");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_progress_set_text_yalign: property 'text-yalign' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_float(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "text-yalign", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_progress_get_value(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererProgress *obj = (GtkCellRendererProgress *)GtkCellRendererProgress_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "value");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_progress_get_value: property 'value' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "value", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_progress_set_value(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererProgress *obj = (GtkCellRendererProgress *)GtkCellRendererProgress_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "value");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_progress_set_value: property 'value' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "value", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_cell_renderer_progress_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_cell_renderer_progress_get_type()));
}
