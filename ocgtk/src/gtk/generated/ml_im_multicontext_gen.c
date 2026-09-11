/* GENERATED CODE - DO NOT EDIT */
/* C bindings for IMMulticontext */

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


CAMLexport CAMLprim value ml_gtk_im_multicontext_new(value unit)
{
CAMLparam1(unit);

GtkIMMulticontext *obj = gtk_im_multicontext_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkIMMulticontext(obj));
}
CAMLexport CAMLprim value ml_gtk_im_multicontext_set_context_id(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_im_multicontext_set_context_id(GtkIMMulticontext_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_im_multicontext_get_context_id(value self)
{
CAMLparam1(self);

const char* result = gtk_im_multicontext_get_context_id(GtkIMMulticontext_val(self));
CAMLreturn(caml_copy_string(result));
}


CAMLprim value ml_gtk_im_multicontext_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_im_multicontext_get_type()));
}
