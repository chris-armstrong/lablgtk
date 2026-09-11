/* GENERATED CODE - DO NOT EDIT */
/* C bindings for GridView */

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


CAMLexport CAMLprim value ml_gtk_grid_view_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkGridView *obj = gtk_grid_view_new(Option_val(arg1, GtkSelectionModel_val, NULL), Option_val(arg2, GtkListItemFactory_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkGridView(obj));
}
#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_grid_view_set_tab_behavior(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_view_set_tab_behavior(GtkGridView_val(self), GtkListTabBehavior_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_grid_view_set_tab_behavior(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("GridView requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_grid_view_set_single_click_activate(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_view_set_single_click_activate(GtkGridView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_view_set_model(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_view_set_model(GtkGridView_val(self), Option_val(arg1, GtkSelectionModel_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_view_set_min_columns(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_view_set_min_columns(GtkGridView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_view_set_max_columns(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_view_set_max_columns(GtkGridView_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_view_set_factory(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_view_set_factory(GtkGridView_val(self), Option_val(arg1, GtkListItemFactory_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_grid_view_set_enable_rubberband(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_grid_view_set_enable_rubberband(GtkGridView_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_grid_view_scroll_to(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_grid_view_scroll_to(GtkGridView_val(self), Int_val(arg1), GtkListScrollFlags_val(arg2), Option_val(arg3, GtkScrollInfo_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_grid_view_scroll_to(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("GridView requires GTK >= 4.12");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_grid_view_get_tab_behavior(value self)
{
CAMLparam1(self);

GtkListTabBehavior result = gtk_grid_view_get_tab_behavior(GtkGridView_val(self));
CAMLreturn(Val_GtkListTabBehavior(result));
}

#else

CAMLexport CAMLprim value ml_gtk_grid_view_get_tab_behavior(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("GridView requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_grid_view_get_single_click_activate(value self)
{
CAMLparam1(self);

gboolean result = gtk_grid_view_get_single_click_activate(GtkGridView_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_grid_view_get_model(value self)
{
CAMLparam1(self);

GtkSelectionModel* result = gtk_grid_view_get_model(GtkGridView_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkSelectionModel));
}

CAMLexport CAMLprim value ml_gtk_grid_view_get_min_columns(value self)
{
CAMLparam1(self);

guint result = gtk_grid_view_get_min_columns(GtkGridView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_grid_view_get_max_columns(value self)
{
CAMLparam1(self);

guint result = gtk_grid_view_get_max_columns(GtkGridView_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_grid_view_get_factory(value self)
{
CAMLparam1(self);

GtkListItemFactory* result = gtk_grid_view_get_factory(GtkGridView_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkListItemFactory));
}

CAMLexport CAMLprim value ml_gtk_grid_view_get_enable_rubberband(value self)
{
CAMLparam1(self);

gboolean result = gtk_grid_view_get_enable_rubberband(GtkGridView_val(self));
CAMLreturn(Val_bool(result));
}

GType gtk_grid_view_get_type (void);


CAMLprim value ml_gtk_grid_view_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_grid_view_get_type()));
}
