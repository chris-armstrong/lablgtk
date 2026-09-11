/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ColorMatrixNode */

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


CAMLexport CAMLprim value ml_gsk_color_matrix_node_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GskColorMatrixNode *obj = gsk_color_matrix_node_new(GskRenderNode_val(arg1), graphene_matrix_t_val(arg2), graphene_vec4_t_val(arg3));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GskColorMatrixNode(obj));
}
CAMLexport CAMLprim value ml_gsk_color_matrix_node_get_color_offset(value self)
{
CAMLparam1(self);

const graphene_vec4_t* result = gsk_color_matrix_node_get_color_offset(GskColorMatrixNode_val(self));
if (result) result = g_boxed_copy(graphene_vec4_get_type(), result);
CAMLreturn(Val_graphene_vec4_t(result));
}

CAMLexport CAMLprim value ml_gsk_color_matrix_node_get_color_matrix(value self)
{
CAMLparam1(self);

const graphene_matrix_t* result = gsk_color_matrix_node_get_color_matrix(GskColorMatrixNode_val(self));
if (result) result = g_boxed_copy(graphene_matrix_get_type(), result);
CAMLreturn(Val_graphene_matrix_t(result));
}

CAMLexport CAMLprim value ml_gsk_color_matrix_node_get_child(value self)
{
CAMLparam1(self);

GskRenderNode* result = gsk_color_matrix_node_get_child(GskColorMatrixNode_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GskRenderNode(result));
}

GType gsk_color_matrix_node_get_type (void);


CAMLprim value ml_gsk_color_matrix_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_color_matrix_node_get_type()));
}
