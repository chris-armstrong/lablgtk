/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ColumnViewColumn */

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


CAMLexport CAMLprim value ml_gtk_column_view_column_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkColumnViewColumn *obj = gtk_column_view_column_new(String_option_val(arg1), Option_val(arg2, GtkListItemFactory_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkColumnViewColumn(obj));
}
CAMLexport CAMLprim value ml_gtk_column_view_column_set_visible(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_column_set_visible(GtkColumnViewColumn_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_column_view_column_set_title(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_column_set_title(GtkColumnViewColumn_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_column_view_column_set_sorter(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_column_set_sorter(GtkColumnViewColumn_val(self), Option_val(arg1, GtkSorter_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_column_view_column_set_resizable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_column_set_resizable(GtkColumnViewColumn_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_column_view_column_set_id(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_column_set_id(GtkColumnViewColumn_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_column_view_column_set_id(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ColumnViewColumn requires GTK >= 4.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_column_view_column_set_header_menu(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_column_set_header_menu(GtkColumnViewColumn_val(self), Option_val(arg1, GMenuModel_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_column_view_column_set_fixed_width(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_column_set_fixed_width(GtkColumnViewColumn_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_column_view_column_set_factory(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_column_set_factory(GtkColumnViewColumn_val(self), Option_val(arg1, GtkListItemFactory_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_column_view_column_set_expand(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_column_view_column_set_expand(GtkColumnViewColumn_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_column_view_column_get_visible(value self)
{
CAMLparam1(self);

gboolean result = gtk_column_view_column_get_visible(GtkColumnViewColumn_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_column_view_column_get_title(value self)
{
CAMLparam1(self);

const char* result = gtk_column_view_column_get_title(GtkColumnViewColumn_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_column_view_column_get_sorter(value self)
{
CAMLparam1(self);

GtkSorter* result = gtk_column_view_column_get_sorter(GtkColumnViewColumn_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkSorter));
}

CAMLexport CAMLprim value ml_gtk_column_view_column_get_resizable(value self)
{
CAMLparam1(self);

gboolean result = gtk_column_view_column_get_resizable(GtkColumnViewColumn_val(self));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_column_view_column_get_id(value self)
{
CAMLparam1(self);

const char* result = gtk_column_view_column_get_id(GtkColumnViewColumn_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_gtk_column_view_column_get_id(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ColumnViewColumn requires GTK >= 4.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_column_view_column_get_header_menu(value self)
{
CAMLparam1(self);

GMenuModel* result = gtk_column_view_column_get_header_menu(GtkColumnViewColumn_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GMenuModel));
}

CAMLexport CAMLprim value ml_gtk_column_view_column_get_fixed_width(value self)
{
CAMLparam1(self);

int result = gtk_column_view_column_get_fixed_width(GtkColumnViewColumn_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_column_view_column_get_factory(value self)
{
CAMLparam1(self);

GtkListItemFactory* result = gtk_column_view_column_get_factory(GtkColumnViewColumn_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkListItemFactory));
}

CAMLexport CAMLprim value ml_gtk_column_view_column_get_expand(value self)
{
CAMLparam1(self);

gboolean result = gtk_column_view_column_get_expand(GtkColumnViewColumn_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_column_view_column_get_column_view(value self)
{
CAMLparam1(self);

GtkColumnView* result = gtk_column_view_column_get_column_view(GtkColumnViewColumn_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkColumnView));
}


CAMLprim value ml_gtk_column_view_column_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_column_view_column_get_type()));
}
