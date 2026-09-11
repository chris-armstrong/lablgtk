/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Notebook */

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


CAMLexport CAMLprim value ml_gtk_notebook_new(value unit)
{
CAMLparam1(unit);

GtkNotebook *obj = gtk_notebook_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkNotebook(obj));
}
CAMLexport CAMLprim value ml_gtk_notebook_set_tab_reorderable(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_notebook_set_tab_reorderable(GtkNotebook_val(self), GtkWidget_val(arg1), Bool_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_set_tab_pos(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_notebook_set_tab_pos(GtkNotebook_val(self), GtkPositionType_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_set_tab_label_text(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_notebook_set_tab_label_text(GtkNotebook_val(self), GtkWidget_val(arg1), String_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_set_tab_label(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_notebook_set_tab_label(GtkNotebook_val(self), GtkWidget_val(arg1), Option_val(arg2, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_set_tab_detachable(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_notebook_set_tab_detachable(GtkNotebook_val(self), GtkWidget_val(arg1), Bool_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_set_show_tabs(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_notebook_set_show_tabs(GtkNotebook_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_set_show_border(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_notebook_set_show_border(GtkNotebook_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_set_scrollable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_notebook_set_scrollable(GtkNotebook_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_set_menu_label_text(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_notebook_set_menu_label_text(GtkNotebook_val(self), GtkWidget_val(arg1), String_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_set_menu_label(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_notebook_set_menu_label(GtkNotebook_val(self), GtkWidget_val(arg1), Option_val(arg2, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_set_group_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_notebook_set_group_name(GtkNotebook_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_set_current_page(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_notebook_set_current_page(GtkNotebook_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_set_action_widget(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_notebook_set_action_widget(GtkNotebook_val(self), GtkWidget_val(arg1), GtkPackType_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_reorder_child(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_notebook_reorder_child(GtkNotebook_val(self), GtkWidget_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_remove_page(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_notebook_remove_page(GtkNotebook_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_prev_page(value self)
{
CAMLparam1(self);

gtk_notebook_prev_page(GtkNotebook_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_prepend_page_menu(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

int result = gtk_notebook_prepend_page_menu(GtkNotebook_val(self), GtkWidget_val(arg1), Option_val(arg2, GtkWidget_val, NULL), Option_val(arg3, GtkWidget_val, NULL));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_notebook_prepend_page(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

int result = gtk_notebook_prepend_page(GtkNotebook_val(self), GtkWidget_val(arg1), Option_val(arg2, GtkWidget_val, NULL));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_notebook_popup_enable(value self)
{
CAMLparam1(self);

gtk_notebook_popup_enable(GtkNotebook_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_popup_disable(value self)
{
CAMLparam1(self);

gtk_notebook_popup_disable(GtkNotebook_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_page_num(value self, value arg1)
{
CAMLparam2(self, arg1);

int result = gtk_notebook_page_num(GtkNotebook_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_notebook_next_page(value self)
{
CAMLparam1(self);

gtk_notebook_next_page(GtkNotebook_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_insert_page_menu(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

int result = gtk_notebook_insert_page_menu(GtkNotebook_val(self), GtkWidget_val(arg1), Option_val(arg2, GtkWidget_val, NULL), Option_val(arg3, GtkWidget_val, NULL), Int_val(arg4));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_notebook_insert_page(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

int result = gtk_notebook_insert_page(GtkNotebook_val(self), GtkWidget_val(arg1), Option_val(arg2, GtkWidget_val, NULL), Int_val(arg3));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_notebook_get_tab_reorderable(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_notebook_get_tab_reorderable(GtkNotebook_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_notebook_get_tab_pos(value self)
{
CAMLparam1(self);

GtkPositionType result = gtk_notebook_get_tab_pos(GtkNotebook_val(self));
CAMLreturn(Val_GtkPositionType(result));
}

CAMLexport CAMLprim value ml_gtk_notebook_get_tab_label_text(value self, value arg1)
{
CAMLparam2(self, arg1);

const char* result = gtk_notebook_get_tab_label_text(GtkNotebook_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_notebook_get_tab_label(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkWidget* result = gtk_notebook_get_tab_label(GtkNotebook_val(self), GtkWidget_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_notebook_get_tab_detachable(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_notebook_get_tab_detachable(GtkNotebook_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_notebook_get_show_tabs(value self)
{
CAMLparam1(self);

gboolean result = gtk_notebook_get_show_tabs(GtkNotebook_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_notebook_get_show_border(value self)
{
CAMLparam1(self);

gboolean result = gtk_notebook_get_show_border(GtkNotebook_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_notebook_get_scrollable(value self)
{
CAMLparam1(self);

gboolean result = gtk_notebook_get_scrollable(GtkNotebook_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_notebook_get_pages(value self)
{
CAMLparam1(self);

GListModel* result = gtk_notebook_get_pages(GtkNotebook_val(self));
CAMLreturn(Val_GListModel(result));
}

CAMLexport CAMLprim value ml_gtk_notebook_get_page(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkNotebookPage* result = gtk_notebook_get_page(GtkNotebook_val(self), GtkWidget_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkNotebookPage(result));
}

CAMLexport CAMLprim value ml_gtk_notebook_get_nth_page(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkWidget* result = gtk_notebook_get_nth_page(GtkNotebook_val(self), Int_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_notebook_get_n_pages(value self)
{
CAMLparam1(self);

int result = gtk_notebook_get_n_pages(GtkNotebook_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_notebook_get_menu_label_text(value self, value arg1)
{
CAMLparam2(self, arg1);

const char* result = gtk_notebook_get_menu_label_text(GtkNotebook_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_notebook_get_menu_label(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkWidget* result = gtk_notebook_get_menu_label(GtkNotebook_val(self), GtkWidget_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_notebook_get_group_name(value self)
{
CAMLparam1(self);

const char* result = gtk_notebook_get_group_name(GtkNotebook_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_notebook_get_current_page(value self)
{
CAMLparam1(self);

int result = gtk_notebook_get_current_page(GtkNotebook_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_notebook_get_action_widget(value self, value arg1)
{
CAMLparam2(self, arg1);

GtkWidget* result = gtk_notebook_get_action_widget(GtkNotebook_val(self), GtkPackType_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_notebook_detach_tab(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_notebook_detach_tab(GtkNotebook_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_notebook_append_page_menu(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

int result = gtk_notebook_append_page_menu(GtkNotebook_val(self), GtkWidget_val(arg1), Option_val(arg2, GtkWidget_val, NULL), Option_val(arg3, GtkWidget_val, NULL));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_notebook_append_page(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

int result = gtk_notebook_append_page(GtkNotebook_val(self), GtkWidget_val(arg1), Option_val(arg2, GtkWidget_val, NULL));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_notebook_get_enable_popup(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkNotebook *obj = (GtkNotebook *)GtkNotebook_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "enable-popup");
if (pspec == NULL) caml_failwith("ml_gtk_notebook_get_enable_popup: property 'enable-popup' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "enable-popup", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_notebook_set_enable_popup(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkNotebook *obj = (GtkNotebook *)GtkNotebook_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "enable-popup");
if (pspec == NULL) caml_failwith("ml_gtk_notebook_set_enable_popup: property 'enable-popup' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "enable-popup", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_notebook_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_notebook_get_type()));
}
