/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Paned */

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


CAMLexport CAMLprim value ml_gtk_paned_new(value arg1)
{
CAMLparam1(arg1);

GtkPaned *obj = gtk_paned_new(GtkOrientation_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkPaned(obj));
}
CAMLexport CAMLprim value ml_gtk_paned_set_wide_handle(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_paned_set_wide_handle(GtkPaned_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_paned_set_start_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_paned_set_start_child(GtkPaned_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_paned_set_shrink_start_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_paned_set_shrink_start_child(GtkPaned_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_paned_set_shrink_end_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_paned_set_shrink_end_child(GtkPaned_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_paned_set_resize_start_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_paned_set_resize_start_child(GtkPaned_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_paned_set_resize_end_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_paned_set_resize_end_child(GtkPaned_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_paned_set_position(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_paned_set_position(GtkPaned_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_paned_set_end_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_paned_set_end_child(GtkPaned_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_paned_get_wide_handle(value self)
{
CAMLparam1(self);

gboolean result = gtk_paned_get_wide_handle(GtkPaned_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_paned_get_start_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_paned_get_start_child(GtkPaned_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_paned_get_shrink_start_child(value self)
{
CAMLparam1(self);

gboolean result = gtk_paned_get_shrink_start_child(GtkPaned_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_paned_get_shrink_end_child(value self)
{
CAMLparam1(self);

gboolean result = gtk_paned_get_shrink_end_child(GtkPaned_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_paned_get_resize_start_child(value self)
{
CAMLparam1(self);

gboolean result = gtk_paned_get_resize_start_child(GtkPaned_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_paned_get_resize_end_child(value self)
{
CAMLparam1(self);

gboolean result = gtk_paned_get_resize_end_child(GtkPaned_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_paned_get_position(value self)
{
CAMLparam1(self);

int result = gtk_paned_get_position(GtkPaned_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_paned_get_end_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_paned_get_end_child(GtkPaned_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_paned_get_max_position(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkPaned *obj = (GtkPaned *)GtkPaned_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "max-position");
if (pspec == NULL) caml_failwith("ml_gtk_paned_get_max_position: property 'max-position' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "max-position", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_paned_get_min_position(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkPaned *obj = (GtkPaned *)GtkPaned_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "min-position");
if (pspec == NULL) caml_failwith("ml_gtk_paned_get_min_position: property 'min-position' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "min-position", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_paned_get_position_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkPaned *obj = (GtkPaned *)GtkPaned_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "position-set");
if (pspec == NULL) caml_failwith("ml_gtk_paned_get_position_set: property 'position-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "position-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_paned_set_position_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkPaned *obj = (GtkPaned *)GtkPaned_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "position-set");
if (pspec == NULL) caml_failwith("ml_gtk_paned_set_position_set: property 'position-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "position-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

GType gtk_paned_get_type (void);


CAMLprim value ml_gtk_paned_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_paned_get_type()));
}
