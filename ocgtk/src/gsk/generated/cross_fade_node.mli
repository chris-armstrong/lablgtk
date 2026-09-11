(* GENERATED CODE - DO NOT EDIT *)
(* CrossFadeNode: CrossFadeNode *)

type t = [ `cross_fade_node | `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gsk_cross_fade_node_get_type"

external new_ : Render_node.t -> Render_node.t -> float -> t
  = "ml_gsk_cross_fade_node_new"
(** Create a new CrossFadeNode *)

(* Methods *)

external get_start_child : t -> Render_node.t
  = "ml_gsk_cross_fade_node_get_start_child"
(** Retrieves the child `GskRenderNode` at the beginning of the cross-fade. *)

external get_progress : t -> float = "ml_gsk_cross_fade_node_get_progress"
(** Retrieves the progress value of the cross fade. *)

external get_end_child : t -> Render_node.t
  = "ml_gsk_cross_fade_node_get_end_child"
(** Retrieves the child `GskRenderNode` at the end of the cross-fade. *)
