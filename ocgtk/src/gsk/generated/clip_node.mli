(* GENERATED CODE - DO NOT EDIT *)
(* ClipNode: ClipNode *)

type t = [ `clip_node | `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gsk_clip_node_get_type"

external new_ : Render_node.t -> Ocgtk_graphene.Graphene.Wrappers.Rect.t -> t
  = "ml_gsk_clip_node_new"
(** Create a new ClipNode *)

(* Methods *)

external get_clip : t -> Ocgtk_graphene.Graphene.Wrappers.Rect.t
  = "ml_gsk_clip_node_get_clip"
(** Retrieves the clip rectangle for @node. *)

external get_child : t -> Render_node.t = "ml_gsk_clip_node_get_child"
(** Gets the child node that is getting clipped by the given @node. *)
