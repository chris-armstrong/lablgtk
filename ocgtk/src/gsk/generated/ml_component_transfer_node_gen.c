/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ComponentTransferNode */

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

#if GTK_CHECK_VERSION(4,20,0)


CAMLexport CAMLprim value ml_gsk_component_transfer_node_new(value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);

GskComponentTransferNode *obj = gsk_component_transfer_node_new(GskRenderNode_val(arg1), GskComponentTransfer_val(arg2), GskComponentTransfer_val(arg3), GskComponentTransfer_val(arg4), GskComponentTransfer_val(arg5));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GskComponentTransferNode(obj));
}
CAMLexport CAMLprim value ml_gsk_component_transfer_node_get_transfer(value self, value arg1)
{
CAMLparam2(self, arg1);

const GskComponentTransfer* result = gsk_component_transfer_node_get_transfer(GskComponentTransferNode_val(self), Int_val(arg1));
if (result) result = g_boxed_copy(gsk_component_transfer_get_type(), result);
CAMLreturn(Val_GskComponentTransfer(result));
}

CAMLexport CAMLprim value ml_gsk_component_transfer_node_get_child(value self)
{
CAMLparam1(self);

GskRenderNode* result = gsk_component_transfer_node_get_child(GskComponentTransferNode_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GskRenderNode(result));
}

GType gsk_component_transfer_node_get_type (void);


CAMLprim value ml_gsk_component_transfer_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_component_transfer_node_get_type()));
}

#else


CAMLexport CAMLprim value ml_gsk_component_transfer_node_new(value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
caml_failwith("ComponentTransferNode requires GTK >= 4.20");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_component_transfer_node_get_child(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ComponentTransferNode requires GTK >= 4.20");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_component_transfer_node_get_transfer(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ComponentTransferNode requires GTK >= 4.20");
return Val_unit;
}


#endif
