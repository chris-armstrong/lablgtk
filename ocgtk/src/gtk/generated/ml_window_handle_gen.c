/* GENERATED CODE - DO NOT EDIT */
/* C bindings for WindowHandle */

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


CAMLexport CAMLprim value ml_gtk_window_handle_new(value unit)
{
CAMLparam1(unit);

GtkWindowHandle *obj = gtk_window_handle_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkWindowHandle(obj));
}
CAMLexport CAMLprim value ml_gtk_window_handle_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_handle_set_child(GtkWindowHandle_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_handle_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_window_handle_get_child(GtkWindowHandle_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

GType gtk_window_handle_get_type (void);


CAMLprim value ml_gtk_window_handle_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_window_handle_get_type()));
}
