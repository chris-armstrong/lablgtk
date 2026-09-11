(* GENERATED CODE - DO NOT EDIT *)
(* ScrolledWindow: ScrolledWindow *)

type t =
  [ `scrolled_window | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_scrolled_window_get_type"

external new_ : unit -> t = "ml_gtk_scrolled_window_new"
(** Create a new ScrolledWindow *)

(* Methods *)

external unset_placement : t -> unit = "ml_gtk_scrolled_window_unset_placement"
(** Unsets the placement of the contents with respect to the scrollbars.

    If no window placement is set for a scrolled window, it defaults to
    %GTK_CORNER_TOP_LEFT. *)

external set_vadjustment : t -> Adjustment.t option -> unit
  = "ml_gtk_scrolled_window_set_vadjustment"
(** Sets the `GtkAdjustment` for the vertical scrollbar. *)

external set_propagate_natural_width : t -> bool -> unit
  = "ml_gtk_scrolled_window_set_propagate_natural_width"
(** Sets whether the natural width of the child should be calculated and
    propagated through the scrolled window’s requested natural width. *)

external set_propagate_natural_height : t -> bool -> unit
  = "ml_gtk_scrolled_window_set_propagate_natural_height"
(** Sets whether the natural height of the child should be calculated and
    propagated through the scrolled window’s requested natural height. *)

external set_policy : t -> Gtk_enums.policytype -> Gtk_enums.policytype -> unit
  = "ml_gtk_scrolled_window_set_policy"
(** Sets the scrollbar policy for the horizontal and vertical scrollbars.

    The policy determines when the scrollbar should appear; it is a value from
    the [enum@Gtk.PolicyType] enumeration. If %GTK_POLICY_ALWAYS, the scrollbar
    is always present; if %GTK_POLICY_NEVER, the scrollbar is never present; if
    %GTK_POLICY_AUTOMATIC, the scrollbar is present only if needed (that is, if
    the slider part of the bar would be smaller than the trough — the display is
    larger than the page size). *)

external set_placement : t -> Gtk_enums.cornertype -> unit
  = "ml_gtk_scrolled_window_set_placement"
(** Sets the placement of the contents with respect to the scrollbars for the
    scrolled window.

    The default is %GTK_CORNER_TOP_LEFT, meaning the child is in the top left,
    with the scrollbars underneath and to the right. Other values in
    [enum@Gtk.CornerType] are %GTK_CORNER_TOP_RIGHT, %GTK_CORNER_BOTTOM_LEFT,
    and %GTK_CORNER_BOTTOM_RIGHT.

    See also [method@Gtk.ScrolledWindow.get_placement] and
    [method@Gtk.ScrolledWindow.unset_placement]. *)

external set_overlay_scrolling : t -> bool -> unit
  = "ml_gtk_scrolled_window_set_overlay_scrolling"
(** Enables or disables overlay scrolling for this scrolled window. *)

external set_min_content_width : t -> int -> unit
  = "ml_gtk_scrolled_window_set_min_content_width"
(** Sets the minimum width that @scrolled_window should keep visible.

Note that this can and (usually will) be smaller than the minimum
size of the content.

It is a programming error to set the minimum content width to a
value greater than [property@Gtk.ScrolledWindow:max-content-width]. *)

external set_min_content_height : t -> int -> unit
  = "ml_gtk_scrolled_window_set_min_content_height"
(** Sets the minimum height that @scrolled_window should keep visible.

Note that this can and (usually will) be smaller than the minimum
size of the content.

It is a programming error to set the minimum content height to a
value greater than [property@Gtk.ScrolledWindow:max-content-height]. *)

external set_max_content_width : t -> int -> unit
  = "ml_gtk_scrolled_window_set_max_content_width"
(** Sets the maximum width that @scrolled_window should keep visible.

The @scrolled_window will grow up to this width before it starts
scrolling the content.

It is a programming error to set the maximum content width to a
value smaller than [property@Gtk.ScrolledWindow:min-content-width]. *)

external set_max_content_height : t -> int -> unit
  = "ml_gtk_scrolled_window_set_max_content_height"
(** Sets the maximum height that @scrolled_window should keep visible.

The @scrolled_window will grow up to this height before it starts
scrolling the content.

It is a programming error to set the maximum content height to a value
smaller than [property@Gtk.ScrolledWindow:min-content-height]. *)

external set_kinetic_scrolling : t -> bool -> unit
  = "ml_gtk_scrolled_window_set_kinetic_scrolling"
(** Turns kinetic scrolling on or off.

    Kinetic scrolling only applies to devices with source
    %GDK_SOURCE_TOUCHSCREEN. *)

external set_has_frame : t -> bool -> unit
  = "ml_gtk_scrolled_window_set_has_frame"
(** Changes the frame drawn around the contents of @scrolled_window. *)

external set_hadjustment : t -> Adjustment.t option -> unit
  = "ml_gtk_scrolled_window_set_hadjustment"
(** Sets the `GtkAdjustment` for the horizontal scrollbar. *)

external set_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_scrolled_window_set_child"
(** Sets the child widget of @scrolled_window.

If @child does not implement the [iface@Gtk.Scrollable] interface,
the scrolled window will add @child to a [class@Gtk.Viewport] instance
and then add the viewport as its child widget. *)

external get_vscrollbar :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t = "ml_gtk_scrolled_window_get_vscrollbar"
(** Returns the vertical scrollbar of @scrolled_window. *)

external get_vadjustment : t -> Adjustment.t
  = "ml_gtk_scrolled_window_get_vadjustment"
(** Returns the vertical scrollbar’s adjustment.

    This is the adjustment used to connect the vertical scrollbar to the child
    widget’s vertical scroll functionality. *)

external get_propagate_natural_width : t -> bool
  = "ml_gtk_scrolled_window_get_propagate_natural_width"
(** Reports whether the natural width of the child will be calculated and
    propagated through the scrolled window’s requested natural width. *)

external get_propagate_natural_height : t -> bool
  = "ml_gtk_scrolled_window_get_propagate_natural_height"
(** Reports whether the natural height of the child will be calculated and
    propagated through the scrolled window’s requested natural height. *)

external get_policy : t -> Gtk_enums.policytype * Gtk_enums.policytype
  = "ml_gtk_scrolled_window_get_policy"
(** Retrieves the current policy values for the horizontal and vertical
    scrollbars.

    See [method@Gtk.ScrolledWindow.set_policy]. *)

external get_placement : t -> Gtk_enums.cornertype
  = "ml_gtk_scrolled_window_get_placement"
(** Gets the placement of the contents with respect to the scrollbars. *)

external get_overlay_scrolling : t -> bool
  = "ml_gtk_scrolled_window_get_overlay_scrolling"
(** Returns whether overlay scrolling is enabled for this scrolled window. *)

external get_min_content_width : t -> int
  = "ml_gtk_scrolled_window_get_min_content_width"
(** Gets the minimum content width of @scrolled_window. *)

external get_min_content_height : t -> int
  = "ml_gtk_scrolled_window_get_min_content_height"
(** Gets the minimal content height of @scrolled_window. *)

external get_max_content_width : t -> int
  = "ml_gtk_scrolled_window_get_max_content_width"
(** Returns the maximum content width set. *)

external get_max_content_height : t -> int
  = "ml_gtk_scrolled_window_get_max_content_height"
(** Returns the maximum content height set. *)

external get_kinetic_scrolling : t -> bool
  = "ml_gtk_scrolled_window_get_kinetic_scrolling"
(** Returns the specified kinetic scrolling behavior. *)

external get_hscrollbar :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t = "ml_gtk_scrolled_window_get_hscrollbar"
(** Returns the horizontal scrollbar of @scrolled_window. *)

external get_has_frame : t -> bool = "ml_gtk_scrolled_window_get_has_frame"
(** Gets whether the scrolled window draws a frame. *)

external get_hadjustment : t -> Adjustment.t
  = "ml_gtk_scrolled_window_get_hadjustment"
(** Returns the horizontal scrollbar’s adjustment.

    This is the adjustment used to connect the horizontal scrollbar to the child
    widget’s horizontal scroll functionality. *)

external get_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_scrolled_window_get_child"
(** Gets the child widget of @scrolled_window.

If the scrolled window automatically added a [class@Gtk.Viewport], this
function will return the viewport widget, and you can retrieve its child
using [method@Gtk.Viewport.get_child]. *)

(* Properties *)

external get_hscrollbar_policy : t -> Gtk_enums.policytype
  = "ml_gtk_scrolled_window_get_hscrollbar_policy"
(** Get property: hscrollbar-policy *)

external set_hscrollbar_policy : t -> Gtk_enums.policytype -> unit
  = "ml_gtk_scrolled_window_set_hscrollbar_policy"
(** Set property: hscrollbar-policy *)

external get_vscrollbar_policy : t -> Gtk_enums.policytype
  = "ml_gtk_scrolled_window_get_vscrollbar_policy"
(** Get property: vscrollbar-policy *)

external set_vscrollbar_policy : t -> Gtk_enums.policytype -> unit
  = "ml_gtk_scrolled_window_set_vscrollbar_policy"
(** Set property: vscrollbar-policy *)

val on_edge_overshot :
  ?after:bool ->
  t ->
  callback:(pos:Gtk_enums.positiontype -> unit) ->
  Gobject.Signal.handler_id

val on_edge_reached :
  ?after:bool ->
  t ->
  callback:(pos:Gtk_enums.positiontype -> unit) ->
  Gobject.Signal.handler_id

val on_move_focus_out :
  ?after:bool ->
  t ->
  callback:(direction_type:Gtk_enums.directiontype -> unit) ->
  Gobject.Signal.handler_id

val on_scroll_child :
  ?after:bool ->
  t ->
  callback:(scroll:Gtk_enums.scrolltype -> horizontal:bool -> bool) ->
  Gobject.Signal.handler_id
