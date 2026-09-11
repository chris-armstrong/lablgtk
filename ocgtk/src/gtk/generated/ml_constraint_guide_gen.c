/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ConstraintGuide */

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


CAMLexport CAMLprim value ml_gtk_constraint_guide_new(value unit)
{
CAMLparam1(unit);

GtkConstraintGuide *obj = gtk_constraint_guide_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkConstraintGuide(obj));
}
CAMLexport CAMLprim value ml_gtk_constraint_guide_set_strength(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_constraint_guide_set_strength(GtkConstraintGuide_val(self), GtkConstraintStrength_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_constraint_guide_set_nat_size(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_constraint_guide_set_nat_size(GtkConstraintGuide_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_constraint_guide_set_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_constraint_guide_set_name(GtkConstraintGuide_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_constraint_guide_set_min_size(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_constraint_guide_set_min_size(GtkConstraintGuide_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_constraint_guide_set_max_size(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_constraint_guide_set_max_size(GtkConstraintGuide_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_constraint_guide_get_strength(value self)
{
CAMLparam1(self);

GtkConstraintStrength result = gtk_constraint_guide_get_strength(GtkConstraintGuide_val(self));
CAMLreturn(Val_GtkConstraintStrength(result));
}

CAMLexport CAMLprim value ml_gtk_constraint_guide_get_nat_size(value self)
{
CAMLparam1(self);
int out1;
int out2;

gtk_constraint_guide_get_nat_size(GtkConstraintGuide_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_constraint_guide_get_name(value self)
{
CAMLparam1(self);

const char* result = gtk_constraint_guide_get_name(GtkConstraintGuide_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_constraint_guide_get_min_size(value self)
{
CAMLparam1(self);
int out1;
int out2;

gtk_constraint_guide_get_min_size(GtkConstraintGuide_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_constraint_guide_get_max_size(value self)
{
CAMLparam1(self);
int out1;
int out2;

gtk_constraint_guide_get_max_size(GtkConstraintGuide_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_constraint_guide_get_max_height(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkConstraintGuide *obj = (GtkConstraintGuide *)GtkConstraintGuide_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "max-height");
if (pspec == NULL) caml_failwith("ml_gtk_constraint_guide_get_max_height: property 'max-height' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "max-height", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_constraint_guide_set_max_height(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkConstraintGuide *obj = (GtkConstraintGuide *)GtkConstraintGuide_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "max-height");
if (pspec == NULL) caml_failwith("ml_gtk_constraint_guide_set_max_height: property 'max-height' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "max-height", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_constraint_guide_get_max_width(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkConstraintGuide *obj = (GtkConstraintGuide *)GtkConstraintGuide_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "max-width");
if (pspec == NULL) caml_failwith("ml_gtk_constraint_guide_get_max_width: property 'max-width' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "max-width", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_constraint_guide_set_max_width(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkConstraintGuide *obj = (GtkConstraintGuide *)GtkConstraintGuide_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "max-width");
if (pspec == NULL) caml_failwith("ml_gtk_constraint_guide_set_max_width: property 'max-width' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "max-width", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_constraint_guide_get_min_height(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkConstraintGuide *obj = (GtkConstraintGuide *)GtkConstraintGuide_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "min-height");
if (pspec == NULL) caml_failwith("ml_gtk_constraint_guide_get_min_height: property 'min-height' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "min-height", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_constraint_guide_set_min_height(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkConstraintGuide *obj = (GtkConstraintGuide *)GtkConstraintGuide_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "min-height");
if (pspec == NULL) caml_failwith("ml_gtk_constraint_guide_set_min_height: property 'min-height' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "min-height", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_constraint_guide_get_min_width(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkConstraintGuide *obj = (GtkConstraintGuide *)GtkConstraintGuide_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "min-width");
if (pspec == NULL) caml_failwith("ml_gtk_constraint_guide_get_min_width: property 'min-width' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "min-width", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_constraint_guide_set_min_width(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkConstraintGuide *obj = (GtkConstraintGuide *)GtkConstraintGuide_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "min-width");
if (pspec == NULL) caml_failwith("ml_gtk_constraint_guide_set_min_width: property 'min-width' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "min-width", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_constraint_guide_get_nat_height(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkConstraintGuide *obj = (GtkConstraintGuide *)GtkConstraintGuide_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "nat-height");
if (pspec == NULL) caml_failwith("ml_gtk_constraint_guide_get_nat_height: property 'nat-height' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "nat-height", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_constraint_guide_set_nat_height(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkConstraintGuide *obj = (GtkConstraintGuide *)GtkConstraintGuide_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "nat-height");
if (pspec == NULL) caml_failwith("ml_gtk_constraint_guide_set_nat_height: property 'nat-height' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "nat-height", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_constraint_guide_get_nat_width(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkConstraintGuide *obj = (GtkConstraintGuide *)GtkConstraintGuide_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "nat-width");
if (pspec == NULL) caml_failwith("ml_gtk_constraint_guide_get_nat_width: property 'nat-width' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "nat-width", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_constraint_guide_set_nat_width(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkConstraintGuide *obj = (GtkConstraintGuide *)GtkConstraintGuide_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "nat-width");
if (pspec == NULL) caml_failwith("ml_gtk_constraint_guide_set_nat_width: property 'nat-width' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "nat-width", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_constraint_guide_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_constraint_guide_get_type()));
}
