/* GENERATED CODE - DO NOT EDIT */
/* C bindings for BuilderCScope */

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


CAMLexport CAMLprim value ml_gtk_builder_cscope_new(value unit)
{
CAMLparam1(unit);

GtkBuilderCScope *obj = gtk_builder_cscope_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkBuilderCScope(obj));
}
GType gtk_builder_cscope_get_type (void);


CAMLprim value ml_gtk_builder_c_scope_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_builder_cscope_get_type()));
}
