(* GENERATED CODE - DO NOT EDIT *)
(* ColorMatrixNode: ColorMatrixNode *)

type t = [ `color_matrix_node | `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gsk_color_matrix_node_get_type"

external new_ :
  Render_node.t ->
  Ocgtk_graphene.Graphene.Wrappers.Matrix.t ->
  Ocgtk_graphene.Graphene.Wrappers.Vec4.t ->
  t = "ml_gsk_color_matrix_node_new"
(** Create a new ColorMatrixNode *)

(* Methods *)

external get_color_offset : t -> Ocgtk_graphene.Graphene.Wrappers.Vec4.t
  = "ml_gsk_color_matrix_node_get_color_offset"
(** Retrieves the color offset used by the @node. *)

external get_color_matrix : t -> Ocgtk_graphene.Graphene.Wrappers.Matrix.t
  = "ml_gsk_color_matrix_node_get_color_matrix"
(** Retrieves the color matrix used by the @node. *)

external get_child : t -> Render_node.t = "ml_gsk_color_matrix_node_get_child"
(** Gets the child node that is getting its colors modified by the given @node. *)
