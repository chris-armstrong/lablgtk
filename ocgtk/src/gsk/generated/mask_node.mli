(* GENERATED CODE - DO NOT EDIT *)
(* MaskNode: MaskNode *)

type t = [ `mask_node | `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gsk_mask_node_get_type"

external new_ : Render_node.t -> Render_node.t -> Gsk_enums.maskmode -> t
  = "ml_gsk_mask_node_new"
(** Create a new MaskNode *)

(* Methods *)

external get_source : t -> Render_node.t = "ml_gsk_mask_node_get_source"
(** Retrieves the source `GskRenderNode` child of the @node. *)

external get_mask_mode : t -> Gsk_enums.maskmode
  = "ml_gsk_mask_node_get_mask_mode"
(** Retrieves the mask mode used by @node. *)

external get_mask : t -> Render_node.t = "ml_gsk_mask_node_get_mask"
(** Retrieves the mask `GskRenderNode` child of the @node. *)
