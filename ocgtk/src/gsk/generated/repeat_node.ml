(* GENERATED CODE - DO NOT EDIT *)
(* RepeatNode: RepeatNode *)

type t = [ `repeat_node | `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gsk_repeat_node_get_type"

external new_ :
  Ocgtk_graphene.Graphene.Wrappers.Rect.t ->
  Render_node.t ->
  Ocgtk_graphene.Graphene.Wrappers.Rect.t option ->
  t = "ml_gsk_repeat_node_new"
(** Create a new RepeatNode *)

(* Methods *)

external get_child_bounds : t -> Ocgtk_graphene.Graphene.Wrappers.Rect.t
  = "ml_gsk_repeat_node_get_child_bounds"
(** Retrieves the bounding rectangle of the child of @node. *)

external get_child : t -> Render_node.t = "ml_gsk_repeat_node_get_child"
(** Retrieves the child of @node. *)
