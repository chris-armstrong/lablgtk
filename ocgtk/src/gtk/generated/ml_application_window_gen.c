/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ApplicationWindow */

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


CAMLexport CAMLprim value ml_gtk_application_window_new(value arg1)
{
CAMLparam1(arg1);

GtkApplicationWindow *obj = gtk_application_window_new(GtkApplication_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkApplicationWindow(obj));
}
CAMLexport CAMLprim value ml_gtk_application_window_set_show_menubar(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_application_window_set_show_menubar(GtkApplicationWindow_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_application_window_set_help_overlay(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_application_window_set_help_overlay(GtkApplicationWindow_val(self), Option_val(arg1, GtkShortcutsWindow_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_application_window_get_show_menubar(value self)
{
CAMLparam1(self);

gboolean result = gtk_application_window_get_show_menubar(GtkApplicationWindow_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_application_window_get_id(value self)
{
CAMLparam1(self);

guint result = gtk_application_window_get_id(GtkApplicationWindow_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_application_window_get_help_overlay(value self)
{
CAMLparam1(self);

GtkShortcutsWindow* result = gtk_application_window_get_help_overlay(GtkApplicationWindow_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkShortcutsWindow));
}


CAMLprim value ml_gtk_application_window_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_application_window_get_type()));
}
