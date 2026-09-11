(* GENERATED CODE - DO NOT EDIT *)
(* RadialGradientNode: RadialGradientNode *)

type t = [ `radial_gradient_node | `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gsk_radial_gradient_node_get_type"

external new_ :
  Ocgtk_graphene.Graphene.Wrappers.Rect.t ->
  Ocgtk_graphene.Graphene.Wrappers.Point.t ->
  float ->
  float ->
  float ->
  float ->
  Color_stop.t array ->
  Gsize.t ->
  t
  = "ml_gsk_radial_gradient_node_new_bytecode"
    "ml_gsk_radial_gradient_node_new_native"
(** Create a new RadialGradientNode *)

(* Methods *)

external get_vradius : t -> float = "ml_gsk_radial_gradient_node_get_vradius"
(** Retrieves the vertical radius for the gradient. *)

external get_start : t -> float = "ml_gsk_radial_gradient_node_get_start"
(** Retrieves the start value for the gradient. *)

external get_n_color_stops : t -> Gsize.t
  = "ml_gsk_radial_gradient_node_get_n_color_stops"
(** Retrieves the number of color stops in the gradient. *)

external get_hradius : t -> float = "ml_gsk_radial_gradient_node_get_hradius"
(** Retrieves the horizontal radius for the gradient. *)

external get_end : t -> float = "ml_gsk_radial_gradient_node_get_end"
(** Retrieves the end value for the gradient. *)

external get_color_stops : t -> Color_stop.t array * Gsize.t
  = "ml_gsk_radial_gradient_node_get_color_stops"
(** Retrieves the color stops in the gradient. *)

external get_center : t -> Ocgtk_graphene.Graphene.Wrappers.Point.t
  = "ml_gsk_radial_gradient_node_get_center"
(** Retrieves the center pointer for the gradient. *)
