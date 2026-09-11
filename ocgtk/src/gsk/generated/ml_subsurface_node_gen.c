/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SubsurfaceNode */

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

#if GTK_CHECK_VERSION(4,14,0)


CAMLexport CAMLprim value ml_gsk_subsurface_node_get_child(value self)
{
CAMLparam1(self);

GskRenderNode* result = gsk_subsurface_node_get_child(GskSubsurfaceNode_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GskRenderNode(result));
}


CAMLprim value ml_gsk_subsurface_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_subsurface_node_get_type()));
}

#else


CAMLexport CAMLprim value ml_gsk_subsurface_node_get_child(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SubsurfaceNode requires GTK >= 4.14");
return Val_unit;
}


#endif
