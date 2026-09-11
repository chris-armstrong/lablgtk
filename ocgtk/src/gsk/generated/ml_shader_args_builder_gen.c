/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ShaderArgsBuilder */

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

/* Conversion functions for GskShaderArgsBuilder (opaque record with hidden fields) */
GskShaderArgsBuilder *GskShaderArgsBuilder_val(value v) {
  return (GskShaderArgsBuilder *)ml_gir_record_ptr_val(v, "GskShaderArgsBuilder");
}

value Val_GskShaderArgsBuilder(const GskShaderArgsBuilder *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gsk_shader_args_builder_get_type(), ptr);
}

value Val_GskShaderArgsBuilder_option(const GskShaderArgsBuilder *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GskShaderArgsBuilder(ptr));
}


CAMLexport CAMLprim value ml_gsk_shader_args_builder_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GskShaderArgsBuilder *obj = gsk_shader_args_builder_new(GskGLShader_val(arg1), Option_val(arg2, GBytes_val, NULL));

CAMLreturn(Val_GskShaderArgsBuilder(obj));
}
CAMLexport CAMLprim value ml_gsk_shader_args_builder_to_args(value self)
{
CAMLparam1(self);

GBytes* result = gsk_shader_args_builder_to_args(GskShaderArgsBuilder_val(self));
CAMLreturn(Val_GBytes(result));
}

CAMLexport CAMLprim value ml_gsk_shader_args_builder_set_vec4(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gsk_shader_args_builder_set_vec4(GskShaderArgsBuilder_val(self), Int_val(arg1), graphene_vec4_t_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_shader_args_builder_set_vec3(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gsk_shader_args_builder_set_vec3(GskShaderArgsBuilder_val(self), Int_val(arg1), graphene_vec3_t_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_shader_args_builder_set_vec2(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gsk_shader_args_builder_set_vec2(GskShaderArgsBuilder_val(self), Int_val(arg1), graphene_vec2_t_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_shader_args_builder_set_uint(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gsk_shader_args_builder_set_uint(GskShaderArgsBuilder_val(self), Int_val(arg1), UInt32_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_shader_args_builder_set_int(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gsk_shader_args_builder_set_int(GskShaderArgsBuilder_val(self), Int_val(arg1), Int32_val_bounded(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_shader_args_builder_set_float(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gsk_shader_args_builder_set_float(GskShaderArgsBuilder_val(self), Int_val(arg1), Double_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_shader_args_builder_set_bool(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gsk_shader_args_builder_set_bool(GskShaderArgsBuilder_val(self), Int_val(arg1), Bool_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_shader_args_builder_ref(value self)
{
CAMLparam1(self);

GskShaderArgsBuilder* result = gsk_shader_args_builder_ref(GskShaderArgsBuilder_val(self));
CAMLreturn(Val_GskShaderArgsBuilder(result));
}

GType gsk_shader_args_builder_get_type (void);


CAMLprim value ml_gsk_shader_args_builder_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_shader_args_builder_get_type()));
}
