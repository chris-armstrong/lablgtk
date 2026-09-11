/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CairoRenderer */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gsk/gsk.h>
/* Include library-specific type conversions and forward declarations */
#include "gsk_decls.h"


CAMLexport CAMLprim value ml_gsk_cairo_renderer_new(value unit)
{
CAMLparam1(unit);

GskCairoRenderer *obj = gsk_cairo_renderer_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GskCairoRenderer(obj));
}

CAMLprim value ml_gsk_cairo_renderer_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_cairo_renderer_get_type()));
}
