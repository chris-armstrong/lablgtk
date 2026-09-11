/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DropDown */

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


CAMLexport CAMLprim value ml_gtk_drop_down_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkDropDown *obj = gtk_drop_down_new(Option_val(arg1, GListModel_val, NULL), Option_val(arg2, GtkExpression_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkDropDown(obj));
}
CAMLexport CAMLprim value ml_gtk_drop_down_new_from_strings(value arg1)
{
CAMLparam1(arg1);
    int arg1_length = Wosize_val(arg1);
    const char** c_arg1 = (const char**)g_malloc(sizeof(const char*) * (arg1_length + 1));
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = String_val(Field(arg1, i));
    }
    c_arg1[arg1_length] = NULL;

GtkDropDown *obj = gtk_drop_down_new_from_strings(c_arg1);
if (obj) g_object_ref_sink(obj);

    g_free(c_arg1);
CAMLreturn(Val_GtkDropDown(obj));
}
#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gtk_drop_down_set_show_arrow(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_drop_down_set_show_arrow(GtkDropDown_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_drop_down_set_show_arrow(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DropDown requires GTK >= 4.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_drop_down_set_selected(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_drop_down_set_selected(GtkDropDown_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_drop_down_set_search_match_mode(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_drop_down_set_search_match_mode(GtkDropDown_val(self), GtkStringFilterMatchMode_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_drop_down_set_search_match_mode(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DropDown requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_drop_down_set_model(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_drop_down_set_model(GtkDropDown_val(self), Option_val(arg1, GListModel_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_drop_down_set_list_factory(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_drop_down_set_list_factory(GtkDropDown_val(self), Option_val(arg1, GtkListItemFactory_val, NULL));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_drop_down_set_header_factory(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_drop_down_set_header_factory(GtkDropDown_val(self), Option_val(arg1, GtkListItemFactory_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_drop_down_set_header_factory(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DropDown requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_drop_down_set_factory(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_drop_down_set_factory(GtkDropDown_val(self), Option_val(arg1, GtkListItemFactory_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_drop_down_set_expression(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_drop_down_set_expression(GtkDropDown_val(self), Option_val(arg1, GtkExpression_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_drop_down_set_enable_search(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_drop_down_set_enable_search(GtkDropDown_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gtk_drop_down_get_show_arrow(value self)
{
CAMLparam1(self);

gboolean result = gtk_drop_down_get_show_arrow(GtkDropDown_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gtk_drop_down_get_show_arrow(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DropDown requires GTK >= 4.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_drop_down_get_selected_item(value self)
{
CAMLparam1(self);

gpointer result = gtk_drop_down_get_selected_item(GtkDropDown_val(self));
CAMLreturn(ml_gobject_val_of_ext(result));
}

CAMLexport CAMLprim value ml_gtk_drop_down_get_selected(value self)
{
CAMLparam1(self);

guint result = gtk_drop_down_get_selected(GtkDropDown_val(self));
CAMLreturn(Val_int(result));
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_drop_down_get_search_match_mode(value self)
{
CAMLparam1(self);

GtkStringFilterMatchMode result = gtk_drop_down_get_search_match_mode(GtkDropDown_val(self));
CAMLreturn(Val_GtkStringFilterMatchMode(result));
}

#else

CAMLexport CAMLprim value ml_gtk_drop_down_get_search_match_mode(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DropDown requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_drop_down_get_model(value self)
{
CAMLparam1(self);

GListModel* result = gtk_drop_down_get_model(GtkDropDown_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GListModel));
}

CAMLexport CAMLprim value ml_gtk_drop_down_get_list_factory(value self)
{
CAMLparam1(self);

GtkListItemFactory* result = gtk_drop_down_get_list_factory(GtkDropDown_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkListItemFactory));
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_drop_down_get_header_factory(value self)
{
CAMLparam1(self);

GtkListItemFactory* result = gtk_drop_down_get_header_factory(GtkDropDown_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkListItemFactory));
}

#else

CAMLexport CAMLprim value ml_gtk_drop_down_get_header_factory(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DropDown requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_drop_down_get_factory(value self)
{
CAMLparam1(self);

GtkListItemFactory* result = gtk_drop_down_get_factory(GtkDropDown_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkListItemFactory));
}

CAMLexport CAMLprim value ml_gtk_drop_down_get_expression(value self)
{
CAMLparam1(self);

GtkExpression* result = gtk_drop_down_get_expression(GtkDropDown_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkExpression));
}

CAMLexport CAMLprim value ml_gtk_drop_down_get_enable_search(value self)
{
CAMLparam1(self);

gboolean result = gtk_drop_down_get_enable_search(GtkDropDown_val(self));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_gtk_drop_down_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_drop_down_get_type()));
}
