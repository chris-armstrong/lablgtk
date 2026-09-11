/* GENERATED CODE - DO NOT EDIT */
/* C bindings for NotebookPage */

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


CAMLexport CAMLprim value ml_gtk_notebook_page_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_notebook_page_get_child(GtkNotebookPage_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkWidget(result));
}

CAMLexport CAMLprim value ml_gtk_notebook_page_get_detachable(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkNotebookPage *obj = (GtkNotebookPage *)GtkNotebookPage_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "detachable");
if (pspec == NULL) caml_failwith("ml_gtk_notebook_page_get_detachable: property 'detachable' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "detachable", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_notebook_page_set_detachable(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkNotebookPage *obj = (GtkNotebookPage *)GtkNotebookPage_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "detachable");
if (pspec == NULL) caml_failwith("ml_gtk_notebook_page_set_detachable: property 'detachable' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "detachable", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_page_get_menu(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkNotebookPage *obj = (GtkNotebookPage *)GtkNotebookPage_val(self);
    GtkWidget *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "menu");
if (pspec == NULL) caml_failwith("ml_gtk_notebook_page_get_menu: property 'menu' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "menu", &prop_gvalue);
          prop_value = (GtkWidget*)g_value_dup_object(&prop_gvalue);

      result = Val_GtkWidget(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_notebook_page_get_menu_label(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkNotebookPage *obj = (GtkNotebookPage *)GtkNotebookPage_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "menu-label");
if (pspec == NULL) caml_failwith("ml_gtk_notebook_page_get_menu_label: property 'menu-label' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "menu-label", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_notebook_page_set_menu_label(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkNotebookPage *obj = (GtkNotebookPage *)GtkNotebookPage_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "menu-label");
if (pspec == NULL) caml_failwith("ml_gtk_notebook_page_set_menu_label: property 'menu-label' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "menu-label", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_page_get_position(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkNotebookPage *obj = (GtkNotebookPage *)GtkNotebookPage_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "position");
if (pspec == NULL) caml_failwith("ml_gtk_notebook_page_get_position: property 'position' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "position", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_notebook_page_set_position(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkNotebookPage *obj = (GtkNotebookPage *)GtkNotebookPage_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "position");
if (pspec == NULL) caml_failwith("ml_gtk_notebook_page_set_position: property 'position' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "position", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_page_get_reorderable(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkNotebookPage *obj = (GtkNotebookPage *)GtkNotebookPage_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "reorderable");
if (pspec == NULL) caml_failwith("ml_gtk_notebook_page_get_reorderable: property 'reorderable' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "reorderable", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_notebook_page_set_reorderable(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkNotebookPage *obj = (GtkNotebookPage *)GtkNotebookPage_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "reorderable");
if (pspec == NULL) caml_failwith("ml_gtk_notebook_page_set_reorderable: property 'reorderable' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "reorderable", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_page_get_tab(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkNotebookPage *obj = (GtkNotebookPage *)GtkNotebookPage_val(self);
    GtkWidget *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "tab");
if (pspec == NULL) caml_failwith("ml_gtk_notebook_page_get_tab: property 'tab' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "tab", &prop_gvalue);
          prop_value = (GtkWidget*)g_value_dup_object(&prop_gvalue);

      result = Val_GtkWidget(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_notebook_page_get_tab_expand(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkNotebookPage *obj = (GtkNotebookPage *)GtkNotebookPage_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "tab-expand");
if (pspec == NULL) caml_failwith("ml_gtk_notebook_page_get_tab_expand: property 'tab-expand' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "tab-expand", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_notebook_page_set_tab_expand(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkNotebookPage *obj = (GtkNotebookPage *)GtkNotebookPage_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "tab-expand");
if (pspec == NULL) caml_failwith("ml_gtk_notebook_page_set_tab_expand: property 'tab-expand' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "tab-expand", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_page_get_tab_fill(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkNotebookPage *obj = (GtkNotebookPage *)GtkNotebookPage_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "tab-fill");
if (pspec == NULL) caml_failwith("ml_gtk_notebook_page_get_tab_fill: property 'tab-fill' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "tab-fill", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_notebook_page_set_tab_fill(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkNotebookPage *obj = (GtkNotebookPage *)GtkNotebookPage_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "tab-fill");
if (pspec == NULL) caml_failwith("ml_gtk_notebook_page_set_tab_fill: property 'tab-fill' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "tab-fill", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_page_get_tab_label(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkNotebookPage *obj = (GtkNotebookPage *)GtkNotebookPage_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "tab-label");
if (pspec == NULL) caml_failwith("ml_gtk_notebook_page_get_tab_label: property 'tab-label' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "tab-label", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_notebook_page_set_tab_label(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkNotebookPage *obj = (GtkNotebookPage *)GtkNotebookPage_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "tab-label");
if (pspec == NULL) caml_failwith("ml_gtk_notebook_page_set_tab_label: property 'tab-label' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "tab-label", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_notebook_page_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_notebook_page_get_type()));
}
