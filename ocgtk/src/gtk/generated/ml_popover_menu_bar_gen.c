/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PopoverMenuBar */

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


CAMLexport CAMLprim value ml_gtk_popover_menu_bar_new_from_model(value arg1)
{
CAMLparam1(arg1);

GtkPopoverMenuBar *obj = gtk_popover_menu_bar_new_from_model(Option_val(arg1, GMenuModel_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkPopoverMenuBar(obj));
}
CAMLexport CAMLprim value ml_gtk_popover_menu_bar_set_menu_model(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_popover_menu_bar_set_menu_model(GtkPopoverMenuBar_val(self), Option_val(arg1, GMenuModel_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_popover_menu_bar_remove_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_popover_menu_bar_remove_child(GtkPopoverMenuBar_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_popover_menu_bar_get_menu_model(value self)
{
CAMLparam1(self);

GMenuModel* result = gtk_popover_menu_bar_get_menu_model(GtkPopoverMenuBar_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GMenuModel));
}

CAMLexport CAMLprim value ml_gtk_popover_menu_bar_add_child(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gtk_popover_menu_bar_add_child(GtkPopoverMenuBar_val(self), GtkWidget_val(arg1), String_val(arg2));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_gtk_popover_menu_bar_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_popover_menu_bar_get_type()));
}
