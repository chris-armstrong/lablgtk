/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FixedLayoutChild */

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


CAMLexport CAMLprim value ml_gtk_fixed_layout_child_set_transform(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_fixed_layout_child_set_transform(GtkFixedLayoutChild_val(self), GskTransform_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_fixed_layout_child_get_transform(value self)
{
CAMLparam1(self);

GskTransform* result = gtk_fixed_layout_child_get_transform(GtkFixedLayoutChild_val(self));
if (result) result = g_boxed_copy(gsk_transform_get_type(), result);
CAMLreturn(Val_option(result, Val_GskTransform));
}

GType gtk_fixed_layout_child_get_type (void);


CAMLprim value ml_gtk_fixed_layout_child_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_fixed_layout_child_get_type()));
}
