(* GENERATED CODE - DO NOT EDIT *)
(* RoundedClipNode: RoundedClipNode *)

type t = [ `rounded_clip_node | `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gsk_rounded_clip_node_get_type"

external new_ : Render_node.t -> Rounded_rect.t -> t
  = "ml_gsk_rounded_clip_node_new"
(** Create a new RoundedClipNode *)

(* Methods *)

external get_clip : t -> Rounded_rect.t = "ml_gsk_rounded_clip_node_get_clip"
(** Retrieves the rounded rectangle used to clip the contents of the @node. *)

external get_child : t -> Render_node.t = "ml_gsk_rounded_clip_node_get_child"
(** Gets the child node that is getting clipped by the given @node. *)
