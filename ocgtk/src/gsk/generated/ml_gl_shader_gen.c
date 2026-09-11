/* GENERATED CODE - DO NOT EDIT */
/* C bindings for GLShader */

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


CAMLexport CAMLprim value ml_gsk_gl_shader_new_from_bytes(value arg1)
{
CAMLparam1(arg1);

GskGLShader *obj = gsk_gl_shader_new_from_bytes(GBytes_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GskGLShader(obj));
}
CAMLexport CAMLprim value ml_gsk_gl_shader_new_from_resource(value arg1)
{
CAMLparam1(arg1);

GskGLShader *obj = gsk_gl_shader_new_from_resource(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GskGLShader(obj));
}
CAMLexport CAMLprim value ml_gsk_gl_shader_get_uniform_type(value self, value arg1)
{
CAMLparam2(self, arg1);

GskGLUniformType result = gsk_gl_shader_get_uniform_type(GskGLShader_val(self), Int_val(arg1));
CAMLreturn(Val_GskGLUniformType(result));
}

CAMLexport CAMLprim value ml_gsk_gl_shader_get_uniform_offset(value self, value arg1)
{
CAMLparam2(self, arg1);

int result = gsk_gl_shader_get_uniform_offset(GskGLShader_val(self), Int_val(arg1));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gsk_gl_shader_get_uniform_name(value self, value arg1)
{
CAMLparam2(self, arg1);

const char* result = gsk_gl_shader_get_uniform_name(GskGLShader_val(self), Int_val(arg1));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gsk_gl_shader_get_source(value self)
{
CAMLparam1(self);

GBytes* result = gsk_gl_shader_get_source(GskGLShader_val(self));
CAMLreturn(Val_GBytes(result));
}

CAMLexport CAMLprim value ml_gsk_gl_shader_get_resource(value self)
{
CAMLparam1(self);

const char* result = gsk_gl_shader_get_resource(GskGLShader_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gsk_gl_shader_get_n_uniforms(value self)
{
CAMLparam1(self);

int result = gsk_gl_shader_get_n_uniforms(GskGLShader_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gsk_gl_shader_get_n_textures(value self)
{
CAMLparam1(self);

int result = gsk_gl_shader_get_n_textures(GskGLShader_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gsk_gl_shader_get_args_size(value self)
{
CAMLparam1(self);

gsize result = gsk_gl_shader_get_args_size(GskGLShader_val(self));
CAMLreturn(Val_gsize(result));
}

CAMLexport CAMLprim value ml_gsk_gl_shader_get_arg_vec4(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gsk_gl_shader_get_arg_vec4(GskGLShader_val(self), GBytes_val(arg1), Int_val(arg2), graphene_vec4_t_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_gl_shader_get_arg_vec3(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gsk_gl_shader_get_arg_vec3(GskGLShader_val(self), GBytes_val(arg1), Int_val(arg2), graphene_vec3_t_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_gl_shader_get_arg_vec2(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gsk_gl_shader_get_arg_vec2(GskGLShader_val(self), GBytes_val(arg1), Int_val(arg2), graphene_vec2_t_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_gl_shader_get_arg_uint(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

guint32 result = gsk_gl_shader_get_arg_uint(GskGLShader_val(self), GBytes_val(arg1), Int_val(arg2));
CAMLreturn(Val_uint32(result));
}

CAMLexport CAMLprim value ml_gsk_gl_shader_get_arg_int(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gint32 result = gsk_gl_shader_get_arg_int(GskGLShader_val(self), GBytes_val(arg1), Int_val(arg2));
CAMLreturn(Val_int32_bounded(result));
}

CAMLexport CAMLprim value ml_gsk_gl_shader_get_arg_float(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

float result = gsk_gl_shader_get_arg_float(GskGLShader_val(self), GBytes_val(arg1), Int_val(arg2));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gsk_gl_shader_get_arg_bool(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gsk_gl_shader_get_arg_bool(GskGLShader_val(self), GBytes_val(arg1), Int_val(arg2));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gsk_gl_shader_find_uniform_by_name(value self, value arg1)
{
CAMLparam2(self, arg1);

int result = gsk_gl_shader_find_uniform_by_name(GskGLShader_val(self), String_val(arg1));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gsk_gl_shader_compile(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = gsk_gl_shader_compile(GskGLShader_val(self), GskRenderer_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

GType gsk_gl_shader_get_type (void);


CAMLprim value ml_gsk_gl_shader_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_gl_shader_get_type()));
}
