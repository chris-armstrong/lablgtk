/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CellRendererAccel */

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


CAMLexport CAMLprim value ml_gtk_cell_renderer_accel_new(value unit)
{
CAMLparam1(unit);

GtkCellRendererAccel *obj = gtk_cell_renderer_accel_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkCellRendererAccel(obj));
}
CAMLexport CAMLprim value ml_gtk_cell_renderer_accel_get_accel_key(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererAccel *obj = (GtkCellRendererAccel *)GtkCellRendererAccel_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "accel-key");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_accel_get_accel_key: property 'accel-key' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "accel-key", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_accel_set_accel_key(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererAccel *obj = (GtkCellRendererAccel *)GtkCellRendererAccel_val(self);
    guint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "accel-key");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_accel_set_accel_key: property 'accel-key' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_uint(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "accel-key", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_accel_get_accel_mode(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererAccel *obj = (GtkCellRendererAccel *)GtkCellRendererAccel_val(self);
    GtkCellRendererAccelMode prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "accel-mode");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_accel_get_accel_mode: property 'accel-mode' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "accel-mode", &prop_gvalue);
          prop_value = (GtkCellRendererAccelMode)g_value_get_enum(&prop_gvalue);

      result = Val_GtkCellRendererAccelMode(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_accel_set_accel_mode(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererAccel *obj = (GtkCellRendererAccel *)GtkCellRendererAccel_val(self);
    GtkCellRendererAccelMode c_value = GtkCellRendererAccelMode_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "accel-mode");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_accel_set_accel_mode: property 'accel-mode' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "accel-mode", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_accel_get_accel_mods(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererAccel *obj = (GtkCellRendererAccel *)GtkCellRendererAccel_val(self);
    GdkModifierType prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "accel-mods");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_accel_get_accel_mods: property 'accel-mods' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "accel-mods", &prop_gvalue);
          prop_value = (GdkModifierType)g_value_get_flags(&prop_gvalue);

      result = Val_GdkModifierType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_accel_set_accel_mods(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererAccel *obj = (GtkCellRendererAccel *)GtkCellRendererAccel_val(self);
    GdkModifierType c_value = GdkModifierType_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "accel-mods");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_accel_set_accel_mods: property 'accel-mods' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_flags(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "accel-mods", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_accel_get_keycode(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRendererAccel *obj = (GtkCellRendererAccel *)GtkCellRendererAccel_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "keycode");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_accel_get_keycode: property 'keycode' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "keycode", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_accel_set_keycode(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRendererAccel *obj = (GtkCellRendererAccel *)GtkCellRendererAccel_val(self);
    guint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "keycode");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_accel_set_keycode: property 'keycode' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_uint(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "keycode", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_cell_renderer_accel_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_cell_renderer_accel_get_type()));
}
