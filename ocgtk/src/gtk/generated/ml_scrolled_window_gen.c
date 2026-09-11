/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ScrolledWindow */

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


CAMLexport CAMLprim value ml_gtk_scrolled_window_new(value unit)
{
CAMLparam1(unit);

GtkScrolledWindow *obj = gtk_scrolled_window_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkScrolledWindow(obj));
}
CAMLexport CAMLprim value ml_gtk_scrolled_window_unset_placement(value self)
{
CAMLparam1(self);

gtk_scrolled_window_unset_placement(GtkScrolledWindow_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_set_vadjustment(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scrolled_window_set_vadjustment(GtkScrolledWindow_val(self), Option_val(arg1, GtkAdjustment_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_set_propagate_natural_width(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scrolled_window_set_propagate_natural_width(GtkScrolledWindow_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_set_propagate_natural_height(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scrolled_window_set_propagate_natural_height(GtkScrolledWindow_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_set_policy(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_scrolled_window_set_policy(GtkScrolledWindow_val(self), GtkPolicyType_val(arg1), GtkPolicyType_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_set_placement(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scrolled_window_set_placement(GtkScrolledWindow_val(self), GtkCornerType_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_set_overlay_scrolling(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scrolled_window_set_overlay_scrolling(GtkScrolledWindow_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_set_min_content_width(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scrolled_window_set_min_content_width(GtkScrolledWindow_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_set_min_content_height(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scrolled_window_set_min_content_height(GtkScrolledWindow_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_set_max_content_width(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scrolled_window_set_max_content_width(GtkScrolledWindow_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_set_max_content_height(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scrolled_window_set_max_content_height(GtkScrolledWindow_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_set_kinetic_scrolling(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scrolled_window_set_kinetic_scrolling(GtkScrolledWindow_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_set_has_frame(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scrolled_window_set_has_frame(GtkScrolledWindow_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_set_hadjustment(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scrolled_window_set_hadjustment(GtkScrolledWindow_val(self), Option_val(arg1, GtkAdjustment_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scrolled_window_set_child(GtkScrolledWindow_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_get_vscrollbar(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_scrolled_window_get_vscrollbar(GtkScrolledWindow_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkWidget(result));
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_get_vadjustment(value self)
{
CAMLparam1(self);

GtkAdjustment* result = gtk_scrolled_window_get_vadjustment(GtkScrolledWindow_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkAdjustment(result));
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_get_propagate_natural_width(value self)
{
CAMLparam1(self);

gboolean result = gtk_scrolled_window_get_propagate_natural_width(GtkScrolledWindow_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_get_propagate_natural_height(value self)
{
CAMLparam1(self);

gboolean result = gtk_scrolled_window_get_propagate_natural_height(GtkScrolledWindow_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_get_policy(value self)
{
CAMLparam1(self);
GtkPolicyType out1;
GtkPolicyType out2;

gtk_scrolled_window_get_policy(GtkScrolledWindow_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_GtkPolicyType(out1));
    Store_field(ret, 1, Val_GtkPolicyType(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_get_placement(value self)
{
CAMLparam1(self);

GtkCornerType result = gtk_scrolled_window_get_placement(GtkScrolledWindow_val(self));
CAMLreturn(Val_GtkCornerType(result));
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_get_overlay_scrolling(value self)
{
CAMLparam1(self);

gboolean result = gtk_scrolled_window_get_overlay_scrolling(GtkScrolledWindow_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_get_min_content_width(value self)
{
CAMLparam1(self);

int result = gtk_scrolled_window_get_min_content_width(GtkScrolledWindow_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_get_min_content_height(value self)
{
CAMLparam1(self);

int result = gtk_scrolled_window_get_min_content_height(GtkScrolledWindow_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_get_max_content_width(value self)
{
CAMLparam1(self);

int result = gtk_scrolled_window_get_max_content_width(GtkScrolledWindow_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_get_max_content_height(value self)
{
CAMLparam1(self);

int result = gtk_scrolled_window_get_max_content_height(GtkScrolledWindow_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_get_kinetic_scrolling(value self)
{
CAMLparam1(self);

gboolean result = gtk_scrolled_window_get_kinetic_scrolling(GtkScrolledWindow_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_get_hscrollbar(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_scrolled_window_get_hscrollbar(GtkScrolledWindow_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkWidget(result));
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_get_has_frame(value self)
{
CAMLparam1(self);

gboolean result = gtk_scrolled_window_get_has_frame(GtkScrolledWindow_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_get_hadjustment(value self)
{
CAMLparam1(self);

GtkAdjustment* result = gtk_scrolled_window_get_hadjustment(GtkScrolledWindow_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkAdjustment(result));
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_scrolled_window_get_child(GtkScrolledWindow_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_get_hscrollbar_policy(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkScrolledWindow *obj = (GtkScrolledWindow *)GtkScrolledWindow_val(self);
    GtkPolicyType prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "hscrollbar-policy");
if (pspec == NULL) caml_failwith("ml_gtk_scrolled_window_get_hscrollbar_policy: property 'hscrollbar-policy' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "hscrollbar-policy", &prop_gvalue);
          prop_value = (GtkPolicyType)g_value_get_enum(&prop_gvalue);

      result = Val_GtkPolicyType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_scrolled_window_set_hscrollbar_policy(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkScrolledWindow *obj = (GtkScrolledWindow *)GtkScrolledWindow_val(self);
    GtkPolicyType c_value = GtkPolicyType_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "hscrollbar-policy");
if (pspec == NULL) caml_failwith("ml_gtk_scrolled_window_set_hscrollbar_policy: property 'hscrollbar-policy' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "hscrollbar-policy", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scrolled_window_get_vscrollbar_policy(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkScrolledWindow *obj = (GtkScrolledWindow *)GtkScrolledWindow_val(self);
    GtkPolicyType prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "vscrollbar-policy");
if (pspec == NULL) caml_failwith("ml_gtk_scrolled_window_get_vscrollbar_policy: property 'vscrollbar-policy' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "vscrollbar-policy", &prop_gvalue);
          prop_value = (GtkPolicyType)g_value_get_enum(&prop_gvalue);

      result = Val_GtkPolicyType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_scrolled_window_set_vscrollbar_policy(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkScrolledWindow *obj = (GtkScrolledWindow *)GtkScrolledWindow_val(self);
    GtkPolicyType c_value = GtkPolicyType_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "vscrollbar-policy");
if (pspec == NULL) caml_failwith("ml_gtk_scrolled_window_set_vscrollbar_policy: property 'vscrollbar-policy' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "vscrollbar-policy", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

GType gtk_scrolled_window_get_type (void);


CAMLprim value ml_gtk_scrolled_window_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_scrolled_window_get_type()));
}
