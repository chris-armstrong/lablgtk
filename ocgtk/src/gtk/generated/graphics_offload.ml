(* GENERATED CODE - DO NOT EDIT *)
(* GraphicsOffload: GraphicsOffload *)

type t =
  [ `graphics_offload | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_graphics_offload_get_type"

external new_ :
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  t = "ml_gtk_graphics_offload_new"
(** Create a new GraphicsOffload *)

(* Methods *)

external set_enabled : t -> Gtk_enums.graphicsoffloadenabled -> unit
  = "ml_gtk_graphics_offload_set_enabled"
(** Sets whether this GtkGraphicsOffload widget will attempt to offload the
    content of its child widget. *)

external set_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_graphics_offload_set_child"
(** Sets the child of @self. *)

external set_black_background : t -> bool -> unit
  = "ml_gtk_graphics_offload_set_black_background"
(** Sets whether this GtkGraphicsOffload widget will draw a black background.

    A main use case for this is **_letterboxing_** where black bars are visible
    next to the content if the aspect ratio of the content does not match the
    dimensions of the monitor.

    Using this property for letterboxing instead of CSS allows compositors to
    show content with maximum efficiency, using direct scanout to avoid extra
    copies in the compositor.

    On Wayland, this is implemented using the
    [single-pixel buffer](https://wayland.app/protocols/single-pixel-buffer-v1)
    protocol. *)

external get_enabled : t -> Gtk_enums.graphicsoffloadenabled
  = "ml_gtk_graphics_offload_get_enabled"
(** Returns whether offload is enabled for @self. *)

external get_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_graphics_offload_get_child"
(** Gets the child of @self. *)

external get_black_background : t -> bool
  = "ml_gtk_graphics_offload_get_black_background"
(** Returns whether the widget draws a black background.

    See [method@Gtk.GraphicsOffload.set_black_background]. *)

(* Properties *)
