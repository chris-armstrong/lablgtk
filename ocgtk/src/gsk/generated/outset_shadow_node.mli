(* GENERATED CODE - DO NOT EDIT *)
(* OutsetShadowNode: OutsetShadowNode *)

type t = [ `outset_shadow_node | `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gsk_outset_shadow_node_get_type"

external new_ :
  Rounded_rect.t ->
  Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t ->
  float ->
  float ->
  float ->
  float ->
  t
  = "ml_gsk_outset_shadow_node_new_bytecode"
    "ml_gsk_outset_shadow_node_new_native"
(** Create a new OutsetShadowNode *)

(* Methods *)

external get_spread : t -> float = "ml_gsk_outset_shadow_node_get_spread"
(** Retrieves how much the shadow spreads outwards. *)

external get_outline : t -> Rounded_rect.t
  = "ml_gsk_outset_shadow_node_get_outline"
(** Retrieves the outline rectangle of the outset shadow. *)

external get_dy : t -> float = "ml_gsk_outset_shadow_node_get_dy"
(** Retrieves the vertical offset of the outset shadow. *)

external get_dx : t -> float = "ml_gsk_outset_shadow_node_get_dx"
(** Retrieves the horizontal offset of the outset shadow. *)

external get_color : t -> Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t
  = "ml_gsk_outset_shadow_node_get_color"
(** Retrieves the color of the outset shadow.

    The value returned by this function will not be correct if the render node
    was created for a non-sRGB color. *)

external get_blur_radius : t -> float
  = "ml_gsk_outset_shadow_node_get_blur_radius"
(** Retrieves the blur radius of the shadow. *)
