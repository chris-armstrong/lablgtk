/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ATContext */

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


CAMLexport CAMLprim value ml_gtk_at_context_create(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GtkATContext *obj = gtk_at_context_create(GtkAccessibleRole_val(arg1), GtkAccessible_val(arg2), GdkDisplay_val(arg3));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkATContext(obj));
}
CAMLexport CAMLprim value ml_gtk_at_context_get_accessible_role(value self)
{
CAMLparam1(self);

GtkAccessibleRole result = gtk_at_context_get_accessible_role(GtkATContext_val(self));
CAMLreturn(Val_GtkAccessibleRole(result));
}

CAMLexport CAMLprim value ml_gtk_at_context_get_accessible(value self)
{
CAMLparam1(self);

GtkAccessible* result = gtk_at_context_get_accessible(GtkATContext_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkAccessible(result));
}

CAMLexport CAMLprim value ml_gtk_at_context_get_display(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkATContext *obj = (GtkATContext *)GtkATContext_val(self);
    GdkDisplay *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "display");
if (pspec == NULL) caml_failwith("ml_gtk_at_context_get_display: property 'display' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "display", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GdkDisplay(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_at_context_set_display(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkATContext *obj = (GtkATContext *)GtkATContext_val(self);
    GdkDisplay *c_value = GdkDisplay_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "display");
if (pspec == NULL) caml_failwith("ml_gtk_at_context_set_display: property 'display' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          caml_failwith("unsupported property type");
g_object_set_property(G_OBJECT(obj), "display", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_at_context_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_at_context_get_type()));
}
