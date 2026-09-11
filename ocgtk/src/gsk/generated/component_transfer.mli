(* GENERATED CODE - DO NOT EDIT *)
(* ComponentTransfer: ComponentTransfer *)

type t = [ `component_transfer ] Gobject.obj
(** Specifies a transfer function for a color component to be applied while
    rendering.

    The available functions include linear, piecewise-linear, gamma and step
    functions.

    Note that the transfer function is applied to un-premultiplied values, and
    all results are clamped to the [0, 1] range. *)

external gtype : unit -> Gobject.Type.t = "ml_gsk_component_transfer_get_type"

external new_discrete : int -> float array -> t
  = "ml_gsk_component_transfer_new_discrete"
(** Create a new ComponentTransfer *)

external new_gamma : float -> float -> float -> t
  = "ml_gsk_component_transfer_new_gamma"
(** Create a new ComponentTransfer *)

external new_identity : unit -> t = "ml_gsk_component_transfer_new_identity"
(** Create a new ComponentTransfer *)

external new_levels : float -> t = "ml_gsk_component_transfer_new_levels"
(** Create a new ComponentTransfer *)

external new_linear : float -> float -> t
  = "ml_gsk_component_transfer_new_linear"
(** Create a new ComponentTransfer *)

external new_table : int -> float array -> t
  = "ml_gsk_component_transfer_new_table"
(** Create a new ComponentTransfer *)

(* Methods *)
