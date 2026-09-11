/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ColumnView */

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


CAMLexport CAMLprim value ml_gtk_column_view_new(value arg1)
{
CAMLparam1(arg1);

GtkColumnView *obj = gtk_column_view_new(Option_val(arg1, GtkSelectionModel_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkColumnView(obj));
}
CAMLexport CAMLprim value ml_gtk_column_view_sort_by_column(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_column_view_sort_by_column(GtkColumnView_val(self), Option_val(arg1, GtkColumnViewColumn_val, NULL), GtkSortType_val(arg2));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_column_view_set_tab_behavior(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_set_tab_behavior(GtkColumnView_val(self), GtkListTabBehavior_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_column_view_set_tab_behavior(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ColumnView requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_column_view_set_single_click_activate(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_set_single_click_activate(GtkColumnView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_column_view_set_show_row_separators(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_set_show_row_separators(GtkColumnView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_column_view_set_show_column_separators(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_set_show_column_separators(GtkColumnView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_column_view_set_row_factory(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_set_row_factory(GtkColumnView_val(self), Option_val(arg1, GtkListItemFactory_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_column_view_set_row_factory(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ColumnView requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_column_view_set_reorderable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_set_reorderable(GtkColumnView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_column_view_set_model(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_set_model(GtkColumnView_val(self), Option_val(arg1, GtkSelectionModel_val, NULL));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_column_view_set_header_factory(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_set_header_factory(GtkColumnView_val(self), Option_val(arg1, GtkListItemFactory_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_column_view_set_header_factory(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ColumnView requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_column_view_set_enable_rubberband(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_set_enable_rubberband(GtkColumnView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_column_view_scroll_to(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gtk_column_view_scroll_to(GtkColumnView_val(self), Int_val(arg1), Option_val(arg2, GtkColumnViewColumn_val, NULL), GtkListScrollFlags_val(arg3), Option_val(arg4, GtkScrollInfo_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_column_view_scroll_to(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("ColumnView requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_column_view_remove_column(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_remove_column(GtkColumnView_val(self), GtkColumnViewColumn_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_column_view_insert_column(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_column_view_insert_column(GtkColumnView_val(self), Int_val(arg1), GtkColumnViewColumn_val(arg2));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_column_view_get_tab_behavior(value self)
{
CAMLparam1(self);

GtkListTabBehavior result = gtk_column_view_get_tab_behavior(GtkColumnView_val(self));
CAMLreturn(Val_GtkListTabBehavior(result));
}

#else

CAMLexport CAMLprim value ml_gtk_column_view_get_tab_behavior(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ColumnView requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_column_view_get_sorter(value self)
{
CAMLparam1(self);

GtkSorter* result = gtk_column_view_get_sorter(GtkColumnView_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkSorter));
}

CAMLexport CAMLprim value ml_gtk_column_view_get_single_click_activate(value self)
{
CAMLparam1(self);

gboolean result = gtk_column_view_get_single_click_activate(GtkColumnView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_column_view_get_show_row_separators(value self)
{
CAMLparam1(self);

gboolean result = gtk_column_view_get_show_row_separators(GtkColumnView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_column_view_get_show_column_separators(value self)
{
CAMLparam1(self);

gboolean result = gtk_column_view_get_show_column_separators(GtkColumnView_val(self));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_column_view_get_row_factory(value self)
{
CAMLparam1(self);

GtkListItemFactory* result = gtk_column_view_get_row_factory(GtkColumnView_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkListItemFactory));
}

#else

CAMLexport CAMLprim value ml_gtk_column_view_get_row_factory(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ColumnView requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_column_view_get_reorderable(value self)
{
CAMLparam1(self);

gboolean result = gtk_column_view_get_reorderable(GtkColumnView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_column_view_get_model(value self)
{
CAMLparam1(self);

GtkSelectionModel* result = gtk_column_view_get_model(GtkColumnView_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkSelectionModel));
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_column_view_get_header_factory(value self)
{
CAMLparam1(self);

GtkListItemFactory* result = gtk_column_view_get_header_factory(GtkColumnView_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkListItemFactory));
}

#else

CAMLexport CAMLprim value ml_gtk_column_view_get_header_factory(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ColumnView requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_column_view_get_enable_rubberband(value self)
{
CAMLparam1(self);

gboolean result = gtk_column_view_get_enable_rubberband(GtkColumnView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_column_view_get_columns(value self)
{
CAMLparam1(self);

GListModel* result = gtk_column_view_get_columns(GtkColumnView_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GListModel(result));
}

CAMLexport CAMLprim value ml_gtk_column_view_append_column(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_append_column(GtkColumnView_val(self), GtkColumnViewColumn_val(arg1));
CAMLreturn(Val_unit);
}

GType gtk_column_view_get_type (void);


CAMLprim value ml_gtk_column_view_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_column_view_get_type()));
}
