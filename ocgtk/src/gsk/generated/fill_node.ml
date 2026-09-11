(* GENERATED CODE - DO NOT EDIT *)
(* FillNode: FillNode *)

type t = [ `fill_node | `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gsk_fill_node_get_type"

external new_ :
  Render_node.t ->
  Path_and__path_measure_and__path_point.Path.t ->
  Gsk_enums.fillrule ->
  t = "ml_gsk_fill_node_new"
(** Create a new FillNode *)

(* Methods *)

external get_path : t -> Path_and__path_measure_and__path_point.Path.t
  = "ml_gsk_fill_node_get_path"
(** Retrieves the path used to describe the area filled with the contents of
the @node. *)

external get_fill_rule : t -> Gsk_enums.fillrule
  = "ml_gsk_fill_node_get_fill_rule"
(** Retrieves the fill rule used to determine how the path is filled. *)

external get_child : t -> Render_node.t = "ml_gsk_fill_node_get_child"
(** Gets the child node that is getting drawn by the given @node. *)
