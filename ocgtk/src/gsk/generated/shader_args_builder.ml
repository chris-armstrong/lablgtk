(* GENERATED CODE - DO NOT EDIT *)
(* ShaderArgsBuilder: ShaderArgsBuilder *)

type t = [ `shader_args_builder ] Gobject.obj
(** Builds the uniforms data for a `GskGLShader`. *)

external gtype : unit -> Gobject.Type.t = "ml_gsk_shader_args_builder_get_type"

external new_ : Gl_shader.t -> Glib_bytes.t option -> t
  = "ml_gsk_shader_args_builder_new"
(** Create a new ShaderArgsBuilder *)

(* Methods *)

external to_args : t -> Glib_bytes.t = "ml_gsk_shader_args_builder_to_args"
(** Creates a new `GBytes` args from the current state of the
given @builder.

Any uniforms of the shader that have not been explicitly set on
the @builder are zero-initialized.

The given `GskShaderArgsBuilder` is reset once this function returns;
you cannot call this function multiple times on the same @builder instance.

This function is intended primarily for bindings. C code should use
[method@Gsk.ShaderArgsBuilder.free_to_args]. *)

external set_vec4 : t -> int -> Ocgtk_graphene.Graphene.Wrappers.Vec4.t -> unit
  = "ml_gsk_shader_args_builder_set_vec4"
(** Sets the value of the uniform @idx.

The uniform must be of vec4 type. *)

external set_vec3 : t -> int -> Ocgtk_graphene.Graphene.Wrappers.Vec3.t -> unit
  = "ml_gsk_shader_args_builder_set_vec3"
(** Sets the value of the uniform @idx.

The uniform must be of vec3 type. *)

external set_vec2 : t -> int -> Ocgtk_graphene.Graphene.Wrappers.Vec2.t -> unit
  = "ml_gsk_shader_args_builder_set_vec2"
(** Sets the value of the uniform @idx.

The uniform must be of vec2 type. *)

external set_uint : t -> int -> UInt32.t -> unit
  = "ml_gsk_shader_args_builder_set_uint"
(** Sets the value of the uniform @idx.

The uniform must be of uint type. *)

external set_int : t -> int -> Int32.t -> unit
  = "ml_gsk_shader_args_builder_set_int"
(** Sets the value of the uniform @idx.

The uniform must be of int type. *)

external set_float : t -> int -> float -> unit
  = "ml_gsk_shader_args_builder_set_float"
(** Sets the value of the uniform @idx.

The uniform must be of float type. *)

external set_bool : t -> int -> bool -> unit
  = "ml_gsk_shader_args_builder_set_bool"
(** Sets the value of the uniform @idx.

The uniform must be of bool type. *)

external ref : t -> t = "ml_gsk_shader_args_builder_ref"
(** Increases the reference count of a `GskShaderArgsBuilder` by one. *)
