/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ColumnViewSorter */

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

#if GTK_CHECK_VERSION(4,10,0)


CAMLexport CAMLprim value ml_gtk_column_view_sorter_get_primary_sort_order(value self)
{
CAMLparam1(self);

GtkSortType result = gtk_column_view_sorter_get_primary_sort_order(GtkColumnViewSorter_val(self));
CAMLreturn(Val_GtkSortType(result));
}

CAMLexport CAMLprim value ml_gtk_column_view_sorter_get_primary_sort_column(value self)
{
CAMLparam1(self);

GtkColumnViewColumn* result = gtk_column_view_sorter_get_primary_sort_column(GtkColumnViewSorter_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkColumnViewColumn));
}

CAMLexport CAMLprim value ml_gtk_column_view_sorter_get_nth_sort_column(value self, value arg1)
{
CAMLparam2(self, arg1);
GtkSortType out2;

GtkColumnViewColumn* result = gtk_column_view_sorter_get_nth_sort_column(GtkColumnViewSorter_val(self), Int_val(arg1), &out2);
if (result) g_object_ref_sink(result);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_option(result, Val_GtkColumnViewColumn));
    Store_field(ret, 1, Val_GtkSortType(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_column_view_sorter_get_n_sort_columns(value self)
{
CAMLparam1(self);

guint result = gtk_column_view_sorter_get_n_sort_columns(GtkColumnViewSorter_val(self));
CAMLreturn(Val_int(result));
}


CAMLprim value ml_gtk_column_view_sorter_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_column_view_sorter_get_type()));
}

#else


CAMLexport CAMLprim value ml_gtk_column_view_sorter_get_n_sort_columns(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ColumnViewSorter requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_column_view_sorter_get_nth_sort_column(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ColumnViewSorter requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_column_view_sorter_get_primary_sort_column(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ColumnViewSorter requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_column_view_sorter_get_primary_sort_order(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ColumnViewSorter requires GTK >= 4.10");
return Val_unit;
}


#endif
