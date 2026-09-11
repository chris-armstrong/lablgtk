/* GENERATED CODE - DO NOT EDIT */
/* C bindings for StringObject */

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


CAMLexport CAMLprim value ml_gtk_string_object_new(value arg1)
{
CAMLparam1(arg1);

GtkStringObject *obj = gtk_string_object_new(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkStringObject(obj));
}
CAMLexport CAMLprim value ml_gtk_string_object_get_string(value self)
{
CAMLparam1(self);

const char* result = gtk_string_object_get_string(GtkStringObject_val(self));
CAMLreturn(caml_copy_string(result));
}


CAMLprim value ml_gtk_string_object_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_string_object_get_type()));
}
