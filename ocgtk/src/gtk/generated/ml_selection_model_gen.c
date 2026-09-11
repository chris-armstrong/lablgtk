/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SelectionModel */

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


CAMLexport CAMLprim value ml_gtk_selection_model_unselect_range(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gtk_selection_model_unselect_range(GtkSelectionModel_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_selection_model_unselect_item(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_selection_model_unselect_item(GtkSelectionModel_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_selection_model_unselect_all(value self)
{
CAMLparam1(self);

gboolean result = gtk_selection_model_unselect_all(GtkSelectionModel_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_selection_model_set_selection(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gtk_selection_model_set_selection(GtkSelectionModel_val(self), GtkBitset_val(arg1), GtkBitset_val(arg2));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_selection_model_selection_changed(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_selection_model_selection_changed(GtkSelectionModel_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_selection_model_select_range(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gboolean result = gtk_selection_model_select_range(GtkSelectionModel_val(self), Int_val(arg1), Int_val(arg2), Bool_val(arg3));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_selection_model_select_item(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gtk_selection_model_select_item(GtkSelectionModel_val(self), Int_val(arg1), Bool_val(arg2));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_selection_model_select_all(value self)
{
CAMLparam1(self);

gboolean result = gtk_selection_model_select_all(GtkSelectionModel_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_selection_model_is_selected(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_selection_model_is_selected(GtkSelectionModel_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_selection_model_get_selection_in_range(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

GtkBitset* result = gtk_selection_model_get_selection_in_range(GtkSelectionModel_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_GtkBitset(result));
}

CAMLexport CAMLprim value ml_gtk_selection_model_get_selection(value self)
{
CAMLparam1(self);

GtkBitset* result = gtk_selection_model_get_selection(GtkSelectionModel_val(self));
CAMLreturn(Val_GtkBitset(result));
}
CAMLexport CAMLprim value ml_gtk_selection_model_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GTK_TYPE_SELECTION_MODEL)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GtkSelectionModel");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GtkSelectionModel((GtkSelectionModel*)gobj));
}


CAMLprim value ml_gtk_selection_model_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_selection_model_get_type()));
}
