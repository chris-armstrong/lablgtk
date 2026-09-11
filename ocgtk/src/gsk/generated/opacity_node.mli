(* GENERATED CODE - DO NOT EDIT *)
(* OpacityNode: OpacityNode *)

type t = [ `opacity_node | `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gsk_opacity_node_get_type"

external new_ : Render_node.t -> float -> t = "ml_gsk_opacity_node_new"
(** Create a new OpacityNode *)

(* Methods *)

external get_opacity : t -> float = "ml_gsk_opacity_node_get_opacity"
(** Gets the transparency factor for an opacity node. *)

external get_child : t -> Render_node.t = "ml_gsk_opacity_node_get_child"
(** Gets the child node that is getting opacityed by the given @node. *)
