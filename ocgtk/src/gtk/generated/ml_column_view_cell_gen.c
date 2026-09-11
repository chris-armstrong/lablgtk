/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ColumnViewCell */

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

#if GTK_CHECK_VERSION(4,12,0)


CAMLexport CAMLprim value ml_gtk_column_view_cell_set_focusable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_cell_set_focusable(GtkColumnViewCell_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_column_view_cell_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_cell_set_child(GtkColumnViewCell_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_column_view_cell_get_selected(value self)
{
CAMLparam1(self);

gboolean result = gtk_column_view_cell_get_selected(GtkColumnViewCell_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_column_view_cell_get_position(value self)
{
CAMLparam1(self);

guint result = gtk_column_view_cell_get_position(GtkColumnViewCell_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_column_view_cell_get_item(value self)
{
CAMLparam1(self);

gpointer result = gtk_column_view_cell_get_item(GtkColumnViewCell_val(self));
CAMLreturn(ml_gobject_val_of_ext(result));
}

CAMLexport CAMLprim value ml_gtk_column_view_cell_get_focusable(value self)
{
CAMLparam1(self);

gboolean result = gtk_column_view_cell_get_focusable(GtkColumnViewCell_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_column_view_cell_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_column_view_cell_get_child(GtkColumnViewCell_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}


CAMLprim value ml_gtk_column_view_cell_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_column_view_cell_get_type()));
}

#else


CAMLexport CAMLprim value ml_gtk_column_view_cell_get_child(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ColumnViewCell requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_column_view_cell_get_focusable(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ColumnViewCell requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_column_view_cell_get_item(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ColumnViewCell requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_column_view_cell_get_position(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ColumnViewCell requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_column_view_cell_get_selected(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ColumnViewCell requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_column_view_cell_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ColumnViewCell requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_column_view_cell_set_focusable(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ColumnViewCell requires GTK >= 4.12");
return Val_unit;
}


#endif
