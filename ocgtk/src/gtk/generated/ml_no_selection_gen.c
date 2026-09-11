/* GENERATED CODE - DO NOT EDIT */
/* C bindings for NoSelection */

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


CAMLexport CAMLprim value ml_gtk_no_selection_new(value arg1)
{
CAMLparam1(arg1);

GtkNoSelection *obj = gtk_no_selection_new(Option_val(arg1, GListModel_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkNoSelection(obj));
}
CAMLexport CAMLprim value ml_gtk_no_selection_set_model(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_no_selection_set_model(GtkNoSelection_val(self), Option_val(arg1, GListModel_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_no_selection_get_model(value self)
{
CAMLparam1(self);

GListModel* result = gtk_no_selection_get_model(GtkNoSelection_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GListModel));
}

#if GTK_CHECK_VERSION(4,8,0)

CAMLexport CAMLprim value ml_gtk_no_selection_get_item_type(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkNoSelection *obj = (GtkNoSelection *)GtkNoSelection_val(self);
    GType *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "item-type");
if (pspec == NULL) caml_failwith("ml_gtk_no_selection_get_item_type: property 'item-type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "item-type", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_no_selection_get_item_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("NoSelection requires GTK >= 4.8");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,8,0)

CAMLexport CAMLprim value ml_gtk_no_selection_get_n_items(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkNoSelection *obj = (GtkNoSelection *)GtkNoSelection_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "n-items");
if (pspec == NULL) caml_failwith("ml_gtk_no_selection_get_n_items: property 'n-items' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "n-items", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_no_selection_get_n_items(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("NoSelection requires GTK >= 4.8");
return Val_unit;
}
#endif

GType gtk_no_selection_get_type (void);


CAMLprim value ml_gtk_no_selection_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_no_selection_get_type()));
}
