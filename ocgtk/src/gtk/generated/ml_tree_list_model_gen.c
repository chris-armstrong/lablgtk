/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TreeListModel */

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


CAMLexport CAMLprim value ml_gtk_tree_list_model_set_autoexpand(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tree_list_model_set_autoexpand(GtkTreeListModel_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tree_list_model_get_row(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkTreeListRow* result = gtk_tree_list_model_get_row(GtkTreeListModel_val(self), Int_val(arg1));
CAMLreturn(Val_option(result, Val_GtkTreeListRow));
}

CAMLexport CAMLprim value ml_gtk_tree_list_model_get_passthrough(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_list_model_get_passthrough(GtkTreeListModel_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_list_model_get_model(value self)
{
CAMLparam1(self);

GListModel* result = gtk_tree_list_model_get_model(GtkTreeListModel_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GListModel(result));
}

CAMLexport CAMLprim value ml_gtk_tree_list_model_get_child_row(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkTreeListRow* result = gtk_tree_list_model_get_child_row(GtkTreeListModel_val(self), Int_val(arg1));
CAMLreturn(Val_option(result, Val_GtkTreeListRow));
}

CAMLexport CAMLprim value ml_gtk_tree_list_model_get_autoexpand(value self)
{
CAMLparam1(self);

gboolean result = gtk_tree_list_model_get_autoexpand(GtkTreeListModel_val(self));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,8,0)

CAMLexport CAMLprim value ml_gtk_tree_list_model_get_item_type(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTreeListModel *obj = (GtkTreeListModel *)GtkTreeListModel_val(self);
    GType *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "item-type");
if (pspec == NULL) caml_failwith("ml_gtk_tree_list_model_get_item_type: property 'item-type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "item-type", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_tree_list_model_get_item_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TreeListModel requires GTK >= 4.8");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,8,0)

CAMLexport CAMLprim value ml_gtk_tree_list_model_get_n_items(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTreeListModel *obj = (GtkTreeListModel *)GtkTreeListModel_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "n-items");
if (pspec == NULL) caml_failwith("ml_gtk_tree_list_model_get_n_items: property 'n-items' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "n-items", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_tree_list_model_get_n_items(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TreeListModel requires GTK >= 4.8");
return Val_unit;
}
#endif


CAMLprim value ml_gtk_tree_list_model_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_tree_list_model_get_type()));
}
