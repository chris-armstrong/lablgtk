/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CellEditable */

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


CAMLexport CAMLprim value ml_gtk_cell_editable_start_editing(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_cell_editable_start_editing(GtkCellEditable_val(self), Option_val(arg1, GdkEvent_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_editable_remove_widget(value self)
{
CAMLparam1(self);

gtk_cell_editable_remove_widget(GtkCellEditable_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_editable_editing_done(value self)
{
CAMLparam1(self);

gtk_cell_editable_editing_done(GtkCellEditable_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_editable_get_editing_canceled(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellEditable *obj = (GtkCellEditable *)GtkCellEditable_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "editing-canceled");
if (pspec == NULL) caml_failwith("ml_gtk_cell_editable_get_editing_canceled: property 'editing-canceled' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "editing-canceled", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_editable_set_editing_canceled(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellEditable *obj = (GtkCellEditable *)GtkCellEditable_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "editing-canceled");
if (pspec == NULL) caml_failwith("ml_gtk_cell_editable_set_editing_canceled: property 'editing-canceled' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "editing-canceled", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}
CAMLexport CAMLprim value ml_gtk_cell_editable_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GTK_TYPE_CELL_EDITABLE)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GtkCellEditable");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GtkCellEditable((GtkCellEditable*)gobj));
}

GType gtk_cell_editable_get_type (void);


CAMLprim value ml_gtk_cell_editable_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_cell_editable_get_type()));
}
