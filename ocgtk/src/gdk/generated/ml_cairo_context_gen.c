/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CairoContext */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gdk/gdk.h>
/* Include library-specific type conversions and forward declarations */
#include "gdk_decls.h"


CAMLexport CAMLprim value ml_gdk_cairo_context_cairo_create(value self)
{
CAMLparam1(self);

cairo_t* result = gdk_cairo_context_cairo_create(GdkCairoContext_val(self));
CAMLreturn(Val_option(result, Val_cairo_t));
}

GType gdk_cairo_context_get_type (void);


CAMLprim value ml_gdk_cairo_context_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_cairo_context_get_type()));
}
