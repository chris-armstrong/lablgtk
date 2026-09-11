(* GENERATED CODE - DO NOT EDIT *)
(* PopupLayout: PopupLayout *)

type t = [ `popup_layout ] Gobject.obj
(** Contains information that is necessary position a [iface@Gdk.Popup] relative
    to its parent.

    The positioning requires a negotiation with the windowing system, since it
    depends on external constraints, such as the position of the parent surface,
    and the screen dimensions.

    The basic ingredients are a rectangle on the parent surface, and the anchor
    on both that rectangle and the popup. The anchors specify a side or corner
    to place next to each other.

    ![Popup anchors](popup-anchors.png)

    For cases where placing the anchors next to each other would make the popup
    extend offscreen, the layout includes some hints for how to resolve this
    problem. The hints may suggest to flip the anchor position to the other
    side, or to 'slide' the popup along a side, or to resize it.

    ![Flipping popups](popup-flip.png)

    ![Sliding popups](popup-slide.png)

    These hints may be combined.

    Ultimatively, it is up to the windowing system to determine the position and
    size of the popup. You can learn about the result by calling
    [method@Gdk.Popup.get_position_x], [method@Gdk.Popup.get_position_y],
    [method@Gdk.Popup.get_rect_anchor] and [method@Gdk.Popup.get_surface_anchor]
    after the popup has been presented. This can be used to adjust the
    rendering. For example, [GtkPopover](../gtk4/class.Popover.html) changes its
    arrow position accordingly. But you have to be careful avoid changing the
    size of the popover, or it has to be presented again. *)

external gtype : unit -> Gobject.Type.t = "ml_gdk_popup_layout_get_type"

external new_ : Rectangle.t -> Gdk_enums.gravity -> Gdk_enums.gravity -> t
  = "ml_gdk_popup_layout_new"
(** Create a new PopupLayout *)

(* Methods *)

external set_surface_anchor : t -> Gdk_enums.gravity -> unit
  = "ml_gdk_popup_layout_set_surface_anchor"
(** Set the anchor on the popup surface. *)

external set_shadow_width : t -> int -> int -> int -> int -> unit
  = "ml_gdk_popup_layout_set_shadow_width"
(** Sets the shadow width of the popup.

    The shadow width corresponds to the part of the computed surface size that
    would consist of the shadow margin surrounding the window, would there be
    any. *)

external set_rect_anchor : t -> Gdk_enums.gravity -> unit
  = "ml_gdk_popup_layout_set_rect_anchor"
(** Set the anchor on the anchor rectangle. *)

external set_offset : t -> int -> int -> unit = "ml_gdk_popup_layout_set_offset"
(** Offset the position of the anchor rectangle with the given delta. *)

external set_anchor_rect : t -> Rectangle.t -> unit
  = "ml_gdk_popup_layout_set_anchor_rect"
(** Set the anchor rectangle. *)

external set_anchor_hints : t -> Gdk_enums.anchorhints -> unit
  = "ml_gdk_popup_layout_set_anchor_hints"
(** Set new anchor hints.

The set @anchor_hints determines how @surface will be moved
if the anchor points cause it to move off-screen. For example,
`GDK_ANCHOR_FLIP_X` will replace `GDK_GRAVITY_NORTH_WEST` with
`GDK_GRAVITY_NORTH_EAST` and vice versa if @surface extends
beyond the left or right edges of the monitor. *)

external ref : t -> t = "ml_gdk_popup_layout_ref"
(** Increases the reference count of @value. *)

external get_surface_anchor : t -> Gdk_enums.gravity
  = "ml_gdk_popup_layout_get_surface_anchor"
(** Returns the anchor position on the popup surface. *)

external get_shadow_width : t -> int * int * int * int
  = "ml_gdk_popup_layout_get_shadow_width"
(** Obtains the shadow widths of this layout. *)

external get_rect_anchor : t -> Gdk_enums.gravity
  = "ml_gdk_popup_layout_get_rect_anchor"
(** Returns the anchor position on the anchor rectangle. *)

external get_offset : t -> int * int = "ml_gdk_popup_layout_get_offset"
(** Retrieves the offset for the anchor rectangle. *)

external get_anchor_rect : t -> Rectangle.t
  = "ml_gdk_popup_layout_get_anchor_rect"
(** Get the anchor rectangle. *)

external get_anchor_hints : t -> Gdk_enums.anchorhints
  = "ml_gdk_popup_layout_get_anchor_hints"
(** Get the anchor hints. *)

external equal : t -> t -> bool = "ml_gdk_popup_layout_equal"
(** Check whether @layout and @other has identical layout properties. *)
