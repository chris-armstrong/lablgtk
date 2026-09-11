/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FillNode */

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


CAMLexport CAMLprim value ml_gsk_fill_node_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GskFillNode *obj = gsk_fill_node_new(GskRenderNode_val(arg1), GskPath_val(arg2), GskFillRule_val(arg3));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GskFillNode(obj));
}
CAMLexport CAMLprim value ml_gsk_fill_node_get_path(value self)
{
CAMLparam1(self);

GskPath* result = gsk_fill_node_get_path(GskFillNode_val(self));
if (result) result = g_boxed_copy(gsk_path_get_type(), result);
CAMLreturn(Val_GskPath(result));
}

CAMLexport CAMLprim value ml_gsk_fill_node_get_fill_rule(value self)
{
CAMLparam1(self);

GskFillRule result = gsk_fill_node_get_fill_rule(GskFillNode_val(self));
CAMLreturn(Val_GskFillRule(result));
}

CAMLexport CAMLprim value ml_gsk_fill_node_get_child(value self)
{
CAMLparam1(self);

GskRenderNode* result = gsk_fill_node_get_child(GskFillNode_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GskRenderNode(result));
}

GType gsk_fill_node_get_type (void);


CAMLprim value ml_gsk_fill_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_fill_node_get_type()));
}

#else


CAMLexport CAMLprim value ml_gsk_fill_node_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("FillNode requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_fill_node_get_child(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FillNode requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_fill_node_get_fill_rule(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FillNode requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_fill_node_get_path(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FillNode requires GTK >= 4.14");
return Val_unit;
}


#endif
