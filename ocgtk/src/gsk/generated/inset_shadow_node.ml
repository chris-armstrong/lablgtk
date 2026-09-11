(* GENERATED CODE - DO NOT EDIT *)
(* InsetShadowNode: InsetShadowNode *)

type t = [ `inset_shadow_node | `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gsk_inset_shadow_node_get_type"

external new_ :
  Rounded_rect.t ->
  Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t ->
  float ->
  float ->
  float ->
  float ->
  t
  = "ml_gsk_inset_shadow_node_new_bytecode"
    "ml_gsk_inset_shadow_node_new_native"
(** Create a new InsetShadowNode *)

(* Methods *)

external get_spread : t -> float = "ml_gsk_inset_shadow_node_get_spread"
(** Retrieves how much the shadow spreads inwards. *)

external get_outline : t -> Rounded_rect.t
  = "ml_gsk_inset_shadow_node_get_outline"
(** Retrieves the outline rectangle of the inset shadow. *)

external get_dy : t -> float = "ml_gsk_inset_shadow_node_get_dy"
(** Retrieves the vertical offset of the inset shadow. *)

external get_dx : t -> float = "ml_gsk_inset_shadow_node_get_dx"
(** Retrieves the horizontal offset of the inset shadow. *)

external get_color : t -> Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t
  = "ml_gsk_inset_shadow_node_get_color"
(** Retrieves the color of the inset shadow.

    The value returned by this function will not be correct if the render node
    was created for a non-sRGB color. *)

external get_blur_radius : t -> float
  = "ml_gsk_inset_shadow_node_get_blur_radius"
(** Retrieves the blur radius to apply to the shadow. *)
