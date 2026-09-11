(* GENERATED CODE - DO NOT EDIT *)
(* DebugNode: DebugNode *)

type t = [ `debug_node | `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gsk_debug_node_get_type"

external new_ : Render_node.t -> string -> t = "ml_gsk_debug_node_new"
(** Create a new DebugNode *)

(* Methods *)

external get_message : t -> string = "ml_gsk_debug_node_get_message"
(** Gets the debug message that was set on this node *)

external get_child : t -> Render_node.t = "ml_gsk_debug_node_get_child"
(** Gets the child node that is getting drawn by the given @node. *)
