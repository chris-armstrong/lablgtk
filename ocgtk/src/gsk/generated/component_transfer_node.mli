(* GENERATED CODE - DO NOT EDIT *)
(* ComponentTransferNode: ComponentTransferNode *)

type t = [ `component_transfer_node | `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gsk_component_transfer_node_get_type"

external new_ :
  Render_node.t ->
  Component_transfer.t ->
  Component_transfer.t ->
  Component_transfer.t ->
  Component_transfer.t ->
  t = "ml_gsk_component_transfer_node_new"
(** Create a new ComponentTransferNode *)

(* Methods *)

external get_transfer : t -> int -> Component_transfer.t
  = "ml_gsk_component_transfer_node_get_transfer"
(** Gets the component transfer for one of the components. *)

external get_child : t -> Render_node.t
  = "ml_gsk_component_transfer_node_get_child"
(** Gets the child node that is getting drawn by the given @node. *)
