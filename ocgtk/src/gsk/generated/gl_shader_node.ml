(* GENERATED CODE - DO NOT EDIT *)
(* GLShaderNode: GLShaderNode *)

type t = [ `gl_shader_node | `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gsk_gl_shader_node_get_type"

external new_ :
  Gl_shader.t ->
  Ocgtk_graphene.Graphene.Wrappers.Rect.t ->
  Glib_bytes.t ->
  Render_node.t array option ->
  int ->
  t = "ml_gsk_gl_shader_node_new"
(** Create a new GLShaderNode *)

(* Methods *)

external get_shader : t -> Gl_shader.t = "ml_gsk_gl_shader_node_get_shader"
(** Gets shader code for the node. *)

external get_n_children : t -> int = "ml_gsk_gl_shader_node_get_n_children"
(** Returns the number of children *)

external get_child : t -> int -> Render_node.t
  = "ml_gsk_gl_shader_node_get_child"
(** Gets one of the children. *)

external get_args : t -> Glib_bytes.t = "ml_gsk_gl_shader_node_get_args"
(** Gets args for the node. *)
