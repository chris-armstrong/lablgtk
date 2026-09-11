(* GENERATED CODE - DO NOT EDIT *)
(* ContainerNode: ContainerNode *)

type t = [ `container_node | `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gsk_container_node_get_type"

external new_ : Render_node.t array -> int -> t = "ml_gsk_container_node_new"
(** Create a new ContainerNode *)

(* Methods *)

external get_n_children : t -> int = "ml_gsk_container_node_get_n_children"
(** Retrieves the number of direct children of @node. *)

external get_child : t -> int -> Render_node.t
  = "ml_gsk_container_node_get_child"
(** Gets one of the children of @container. *)
