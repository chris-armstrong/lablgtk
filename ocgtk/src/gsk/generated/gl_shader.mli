(* GENERATED CODE - DO NOT EDIT *)
(* GLShader: GLShader *)

type t = [ `gl_shader | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gsk_gl_shader_get_type"

external new_from_bytes : Glib_bytes.t -> t = "ml_gsk_gl_shader_new_from_bytes"
(** Create a new GLShader *)

external new_from_resource : string -> t = "ml_gsk_gl_shader_new_from_resource"
(** Create a new GLShader *)

(* Methods *)

external get_uniform_type : t -> int -> Gsk_enums.gluniformtype
  = "ml_gsk_gl_shader_get_uniform_type"
(** Get the type of the declared uniform for this shader at index @idx. *)

external get_uniform_offset : t -> int -> int
  = "ml_gsk_gl_shader_get_uniform_offset"
(** Get the offset into the data block where data for this uniforms is stored.
*)

external get_uniform_name : t -> int -> string
  = "ml_gsk_gl_shader_get_uniform_name"
(** Get the name of the declared uniform for this shader at index @idx. *)

external get_source : t -> Glib_bytes.t = "ml_gsk_gl_shader_get_source"
(** Gets the GLSL sourcecode being used to render this shader. *)

external get_resource : t -> string option = "ml_gsk_gl_shader_get_resource"
(** Gets the resource path for the GLSL sourcecode being used to render this
    shader. *)

external get_n_uniforms : t -> int = "ml_gsk_gl_shader_get_n_uniforms"
(** Get the number of declared uniforms for this shader. *)

external get_n_textures : t -> int = "ml_gsk_gl_shader_get_n_textures"
(** Returns the number of textures that the shader requires.

    This can be used to check that the a passed shader works in your usecase. It
    is determined by looking at the highest u_textureN value that the shader
    defines. *)

external get_args_size : t -> Gsize.t = "ml_gsk_gl_shader_get_args_size"
(** Get the size of the data block used to specify arguments for this shader. *)

external get_arg_vec4 :
  t -> Glib_bytes.t -> int -> Ocgtk_graphene.Graphene.Wrappers.Vec4.t -> unit
  = "ml_gsk_gl_shader_get_arg_vec4"
(** Gets the value of the uniform @idx in the @args block.

The uniform must be of vec4 type. *)

external get_arg_vec3 :
  t -> Glib_bytes.t -> int -> Ocgtk_graphene.Graphene.Wrappers.Vec3.t -> unit
  = "ml_gsk_gl_shader_get_arg_vec3"
(** Gets the value of the uniform @idx in the @args block.

The uniform must be of vec3 type. *)

external get_arg_vec2 :
  t -> Glib_bytes.t -> int -> Ocgtk_graphene.Graphene.Wrappers.Vec2.t -> unit
  = "ml_gsk_gl_shader_get_arg_vec2"
(** Gets the value of the uniform @idx in the @args block.

The uniform must be of vec2 type. *)

external get_arg_uint : t -> Glib_bytes.t -> int -> UInt32.t
  = "ml_gsk_gl_shader_get_arg_uint"
(** Gets the value of the uniform @idx in the @args block.

The uniform must be of uint type. *)

external get_arg_int : t -> Glib_bytes.t -> int -> Int32.t
  = "ml_gsk_gl_shader_get_arg_int"
(** Gets the value of the uniform @idx in the @args block.

The uniform must be of int type. *)

external get_arg_float : t -> Glib_bytes.t -> int -> float
  = "ml_gsk_gl_shader_get_arg_float"
(** Gets the value of the uniform @idx in the @args block.

The uniform must be of float type. *)

external get_arg_bool : t -> Glib_bytes.t -> int -> bool
  = "ml_gsk_gl_shader_get_arg_bool"
(** Gets the value of the uniform @idx in the @args block.

The uniform must be of bool type. *)

external find_uniform_by_name : t -> string -> int
  = "ml_gsk_gl_shader_find_uniform_by_name"
(** Looks for a uniform by the name @name, and returns the index
of the uniform, or -1 if it was not found. *)

external compile : t -> Renderer.t -> (bool, GError.t) result
  = "ml_gsk_gl_shader_compile"
(** Tries to compile the @shader for the given @renderer.

If there is a problem, this function returns %FALSE and reports
an error. You should use this function before relying on the shader
for rendering and use a fallback with a simpler shader or without
shaders if it fails.

Note that this will modify the rendering state (for example
change the current GL context) and requires the renderer to be
set up. This means that the widget has to be realized. Commonly you
want to call this from the realize signal of a widget, or during
widget snapshot. *)

(* Properties *)
