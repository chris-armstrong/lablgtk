/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CellView */

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


CAMLexport CAMLprim value ml_gtk_cell_view_new(value unit)
{
CAMLparam1(unit);

GtkCellView *obj = gtk_cell_view_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkCellView(obj));
}
CAMLexport CAMLprim value ml_gtk_cell_view_new_with_context(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkCellView *obj = gtk_cell_view_new_with_context(GtkCellArea_val(arg1), GtkCellAreaContext_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkCellView(obj));
}
CAMLexport CAMLprim value ml_gtk_cell_view_new_with_markup(value arg1)
{
CAMLparam1(arg1);

GtkCellView *obj = gtk_cell_view_new_with_markup(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkCellView(obj));
}
CAMLexport CAMLprim value ml_gtk_cell_view_new_with_text(value arg1)
{
CAMLparam1(arg1);

GtkCellView *obj = gtk_cell_view_new_with_text(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkCellView(obj));
}
CAMLexport CAMLprim value ml_gtk_cell_view_new_with_texture(value arg1)
{
CAMLparam1(arg1);

GtkCellView *obj = gtk_cell_view_new_with_texture(GdkTexture_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkCellView(obj));
}
CAMLexport CAMLprim value ml_gtk_cell_view_set_model(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_cell_view_set_model(GtkCellView_val(self), Option_val(arg1, GtkTreeModel_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_view_set_fit_model(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_cell_view_set_fit_model(GtkCellView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_view_set_draw_sensitive(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_cell_view_set_draw_sensitive(GtkCellView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_view_set_displayed_row(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_cell_view_set_displayed_row(GtkCellView_val(self), Option_val(arg1, GtkTreePath_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_view_get_model(value self)
{
CAMLparam1(self);

GtkTreeModel* result = gtk_cell_view_get_model(GtkCellView_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkTreeModel));
}

CAMLexport CAMLprim value ml_gtk_cell_view_get_fit_model(value self)
{
CAMLparam1(self);

gboolean result = gtk_cell_view_get_fit_model(GtkCellView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_cell_view_get_draw_sensitive(value self)
{
CAMLparam1(self);

gboolean result = gtk_cell_view_get_draw_sensitive(GtkCellView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_cell_view_get_displayed_row(value self)
{
CAMLparam1(self);

GtkTreePath* result = gtk_cell_view_get_displayed_row(GtkCellView_val(self));
CAMLreturn(Val_option(result, Val_GtkTreePath));
}

CAMLexport CAMLprim value ml_gtk_cell_view_get_cell_area(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellView *obj = (GtkCellView *)GtkCellView_val(self);
    GtkCellArea *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "cell-area");
if (pspec == NULL) caml_failwith("ml_gtk_cell_view_get_cell_area: property 'cell-area' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "cell-area", &prop_gvalue);
          prop_value = (GtkCellArea*)g_value_dup_object(&prop_gvalue);

      result = Val_GtkCellArea(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_view_get_cell_area_context(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellView *obj = (GtkCellView *)GtkCellView_val(self);
    GtkCellAreaContext *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "cell-area-context");
if (pspec == NULL) caml_failwith("ml_gtk_cell_view_get_cell_area_context: property 'cell-area-context' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "cell-area-context", &prop_gvalue);
          prop_value = (GtkCellAreaContext*)g_value_dup_object(&prop_gvalue);

      result = Val_GtkCellAreaContext(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}


CAMLprim value ml_gtk_cell_view_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_cell_view_get_type()));
}
