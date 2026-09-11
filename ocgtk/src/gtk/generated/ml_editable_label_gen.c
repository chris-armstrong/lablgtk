/* GENERATED CODE - DO NOT EDIT */
/* C bindings for EditableLabel */

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


CAMLexport CAMLprim value ml_gtk_editable_label_new(value arg1)
{
CAMLparam1(arg1);

GtkEditableLabel *obj = gtk_editable_label_new(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkEditableLabel(obj));
}
CAMLexport CAMLprim value ml_gtk_editable_label_stop_editing(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_editable_label_stop_editing(GtkEditableLabel_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_editable_label_start_editing(value self)
{
CAMLparam1(self);

gtk_editable_label_start_editing(GtkEditableLabel_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_editable_label_get_editing(value self)
{
CAMLparam1(self);

gboolean result = gtk_editable_label_get_editing(GtkEditableLabel_val(self));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_gtk_editable_label_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_editable_label_get_type()));
}
