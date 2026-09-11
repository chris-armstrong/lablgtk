/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Viewport */

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


CAMLexport CAMLprim value ml_gtk_viewport_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkViewport *obj = gtk_viewport_new(Option_val(arg1, GtkAdjustment_val, NULL), Option_val(arg2, GtkAdjustment_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkViewport(obj));
}
CAMLexport CAMLprim value ml_gtk_viewport_set_scroll_to_focus(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_viewport_set_scroll_to_focus(GtkViewport_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_viewport_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_viewport_set_child(GtkViewport_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_viewport_scroll_to(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_viewport_scroll_to(GtkViewport_val(self), GtkWidget_val(arg1), Option_val(arg2, GtkScrollInfo_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_viewport_scroll_to(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Viewport requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_viewport_get_scroll_to_focus(value self)
{
CAMLparam1(self);

gboolean result = gtk_viewport_get_scroll_to_focus(GtkViewport_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_viewport_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_viewport_get_child(GtkViewport_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}


CAMLprim value ml_gtk_viewport_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_viewport_get_type()));
}
