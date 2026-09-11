/* GENERATED CODE - DO NOT EDIT */
/* C bindings for GLShaderNode */

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


CAMLexport CAMLprim value ml_gsk_gl_shader_node_new(value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);
    int arg4_length = 0;
    GskRenderNode** c_arg4 = NULL;
    
    if (Is_some(arg4)) {
        value array = Some_val(arg4);
        arg4_length = Wosize_val(array);
        c_arg4 = (GskRenderNode**)g_malloc(sizeof(GskRenderNode*) * arg4_length);
        for (int i = 0; i < arg4_length; i++) {
          c_arg4[i] = GskRenderNode_val(Field(array, i));
        }
    }

GskGLShaderNode *obj = gsk_gl_shader_node_new(GskGLShader_val(arg1), graphene_rect_t_val(arg2), GBytes_val(arg3), c_arg4, Int_val(arg5));
if (obj) g_object_ref_sink(obj);

    if (c_arg4) g_free(c_arg4);
CAMLreturn(Val_GskGLShaderNode(obj));
}
CAMLexport CAMLprim value ml_gsk_gl_shader_node_get_shader(value self)
{
CAMLparam1(self);

GskGLShader* result = gsk_gl_shader_node_get_shader(GskGLShaderNode_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GskGLShader(result));
}

CAMLexport CAMLprim value ml_gsk_gl_shader_node_get_n_children(value self)
{
CAMLparam1(self);

guint result = gsk_gl_shader_node_get_n_children(GskGLShaderNode_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gsk_gl_shader_node_get_child(value self, value arg1)
{
CAMLparam2(self, arg1);

GskRenderNode* result = gsk_gl_shader_node_get_child(GskGLShaderNode_val(self), Int_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GskRenderNode(result));
}

CAMLexport CAMLprim value ml_gsk_gl_shader_node_get_args(value self)
{
CAMLparam1(self);

GBytes* result = gsk_gl_shader_node_get_args(GskGLShaderNode_val(self));
CAMLreturn(Val_GBytes(result));
}

GType gsk_gl_shader_node_get_type (void);


CAMLprim value ml_gsk_gl_shader_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_gl_shader_node_get_type()));
}
