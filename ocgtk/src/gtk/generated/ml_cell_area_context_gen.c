/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CellAreaContext */

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


CAMLexport CAMLprim value ml_gtk_cell_area_context_reset(value self)
{
CAMLparam1(self);

gtk_cell_area_context_reset(GtkCellAreaContext_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_area_context_push_preferred_width(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_cell_area_context_push_preferred_width(GtkCellAreaContext_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_area_context_push_preferred_height(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_cell_area_context_push_preferred_height(GtkCellAreaContext_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_area_context_get_preferred_width_for_height(value self, value arg1)
{
CAMLparam2(self, arg1);
int out2;
int out3;

gtk_cell_area_context_get_preferred_width_for_height(GtkCellAreaContext_val(self), Int_val(arg1), &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out2));
    Store_field(ret, 1, Val_int(out3));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_cell_area_context_get_preferred_width(value self)
{
CAMLparam1(self);
int out1;
int out2;

gtk_cell_area_context_get_preferred_width(GtkCellAreaContext_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_cell_area_context_get_preferred_height_for_width(value self, value arg1)
{
CAMLparam2(self, arg1);
int out2;
int out3;

gtk_cell_area_context_get_preferred_height_for_width(GtkCellAreaContext_val(self), Int_val(arg1), &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out2));
    Store_field(ret, 1, Val_int(out3));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_cell_area_context_get_preferred_height(value self)
{
CAMLparam1(self);
int out1;
int out2;

gtk_cell_area_context_get_preferred_height(GtkCellAreaContext_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_cell_area_context_get_area(value self)
{
CAMLparam1(self);

GtkCellArea* result = gtk_cell_area_context_get_area(GtkCellAreaContext_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkCellArea(result));
}

CAMLexport CAMLprim value ml_gtk_cell_area_context_get_allocation(value self)
{
CAMLparam1(self);
int out1;
int out2;

gtk_cell_area_context_get_allocation(GtkCellAreaContext_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_cell_area_context_allocate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_cell_area_context_allocate(GtkCellAreaContext_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_area_context_get_minimum_height(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellAreaContext *obj = (GtkCellAreaContext *)GtkCellAreaContext_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "minimum-height");
if (pspec == NULL) caml_failwith("ml_gtk_cell_area_context_get_minimum_height: property 'minimum-height' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "minimum-height", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_area_context_get_minimum_width(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellAreaContext *obj = (GtkCellAreaContext *)GtkCellAreaContext_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "minimum-width");
if (pspec == NULL) caml_failwith("ml_gtk_cell_area_context_get_minimum_width: property 'minimum-width' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "minimum-width", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_area_context_get_natural_height(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellAreaContext *obj = (GtkCellAreaContext *)GtkCellAreaContext_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "natural-height");
if (pspec == NULL) caml_failwith("ml_gtk_cell_area_context_get_natural_height: property 'natural-height' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "natural-height", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_area_context_get_natural_width(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellAreaContext *obj = (GtkCellAreaContext *)GtkCellAreaContext_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "natural-width");
if (pspec == NULL) caml_failwith("ml_gtk_cell_area_context_get_natural_width: property 'natural-width' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "natural-width", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}


CAMLprim value ml_gtk_cell_area_context_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_cell_area_context_get_type()));
}
