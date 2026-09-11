(* GENERATED CODE - DO NOT EDIT *)
(* BlurNode: BlurNode *)

type t = [ `blur_node | `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gsk_blur_node_get_type"

external new_ : Render_node.t -> float -> t = "ml_gsk_blur_node_new"
(** Create a new BlurNode *)

(* Methods *)

external get_radius : t -> float = "ml_gsk_blur_node_get_radius"
(** Retrieves the blur radius of the @node. *)

external get_child : t -> Render_node.t = "ml_gsk_blur_node_get_child"
(** Retrieves the child `GskRenderNode` of the blur @node. *)
