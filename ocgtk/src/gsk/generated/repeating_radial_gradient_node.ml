(* GENERATED CODE - DO NOT EDIT *)
(* RepeatingRadialGradientNode: RepeatingRadialGradientNode *)

type t = [ `repeating_radial_gradient_node | `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gsk_repeating_radial_gradient_node_get_type"

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
  = "ml_gsk_repeating_radial_gradient_node_new_bytecode"
    "ml_gsk_repeating_radial_gradient_node_new_native"
(** Create a new RepeatingRadialGradientNode *)

(* Methods *)
