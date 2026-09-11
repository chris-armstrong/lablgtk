/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Border */

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

/* Copy function for GtkBorder (value-like record with copy method) */
value copy_GtkBorder(const GtkBorder *ptr)
{
  if (ptr == NULL) return Val_none;
  GtkBorder *copy = g_boxed_copy(gtk_border_get_type(), ptr);
  return ml_gir_record_val_ptr_with_type(gtk_border_get_type(), copy);
}


CAMLexport CAMLprim value ml_gtk_border_new(value unit)
{
CAMLparam1(unit);

GtkBorder *obj = gtk_border_new();

CAMLreturn(Val_GtkBorder(obj));
}
GType gtk_border_get_type (void);


CAMLprim value ml_gtk_border_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_border_get_type()));
}
