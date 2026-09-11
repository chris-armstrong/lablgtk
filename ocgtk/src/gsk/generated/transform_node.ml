(* GENERATED CODE - DO NOT EDIT *)
(* TransformNode: TransformNode *)

type t = [ `transform_node | `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gsk_transform_node_get_type"

external new_ : Render_node.t -> Transform.t -> t = "ml_gsk_transform_node_new"
(** Create a new TransformNode *)

(* Methods *)

external get_transform : t -> Transform.t
  = "ml_gsk_transform_node_get_transform"
(** Retrieves the `GskTransform` used by the @node. *)

external get_child : t -> Render_node.t = "ml_gsk_transform_node_get_child"
(** Gets the child node that is getting transformed by the given @node. *)
