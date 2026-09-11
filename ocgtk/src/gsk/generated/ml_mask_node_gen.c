/* GENERATED CODE - DO NOT EDIT */
/* C bindings for MaskNode */

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

#if GTK_CHECK_VERSION(4,10,0)


CAMLexport CAMLprim value ml_gsk_mask_node_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GskMaskNode *obj = gsk_mask_node_new(GskRenderNode_val(arg1), GskRenderNode_val(arg2), GskMaskMode_val(arg3));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GskMaskNode(obj));
}
CAMLexport CAMLprim value ml_gsk_mask_node_get_source(value self)
{
CAMLparam1(self);

GskRenderNode* result = gsk_mask_node_get_source(GskMaskNode_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GskRenderNode(result));
}

CAMLexport CAMLprim value ml_gsk_mask_node_get_mask_mode(value self)
{
CAMLparam1(self);

GskMaskMode result = gsk_mask_node_get_mask_mode(GskMaskNode_val(self));
CAMLreturn(Val_GskMaskMode(result));
}

CAMLexport CAMLprim value ml_gsk_mask_node_get_mask(value self)
{
CAMLparam1(self);

GskRenderNode* result = gsk_mask_node_get_mask(GskMaskNode_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GskRenderNode(result));
}

GType gsk_mask_node_get_type (void);


CAMLprim value ml_gsk_mask_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_mask_node_get_type()));
}

#else


CAMLexport CAMLprim value ml_gsk_mask_node_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("MaskNode requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_mask_node_get_mask(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MaskNode requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_mask_node_get_mask_mode(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MaskNode requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_mask_node_get_source(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MaskNode requires GTK >= 4.10");
return Val_unit;
}


#endif
