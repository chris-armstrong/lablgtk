/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Statusbar */

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


CAMLexport CAMLprim value ml_gtk_statusbar_new(value unit)
{
CAMLparam1(unit);

GtkStatusbar *obj = gtk_statusbar_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkStatusbar(obj));
}
CAMLexport CAMLprim value ml_gtk_statusbar_remove_all(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_statusbar_remove_all(GtkStatusbar_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_statusbar_remove(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_statusbar_remove(GtkStatusbar_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_statusbar_push(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

guint result = gtk_statusbar_push(GtkStatusbar_val(self), Int_val(arg1), String_val(arg2));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_statusbar_pop(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_statusbar_pop(GtkStatusbar_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_statusbar_get_context_id(value self, value arg1)
{
CAMLparam2(self, arg1);

guint result = gtk_statusbar_get_context_id(GtkStatusbar_val(self), String_val(arg1));
CAMLreturn(Val_int(result));
}


CAMLprim value ml_gtk_statusbar_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_statusbar_get_type()));
}
