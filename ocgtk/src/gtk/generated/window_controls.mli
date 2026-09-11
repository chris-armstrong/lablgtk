(* GENERATED CODE - DO NOT EDIT *)
(* WindowControls: WindowControls *)

type t =
  [ `window_controls | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_window_controls_get_type"

external new_ : Gtk_enums.packtype -> t = "ml_gtk_window_controls_new"
(** Create a new WindowControls *)

(* Methods *)

external set_use_native_controls : t -> bool -> unit
  = "ml_gtk_window_controls_set_use_native_controls"
(** Sets whether platform native window controls are used.

    This option shows the "stoplight" buttons on macOS. For Linux, this option
    has no effect.

    See also [Using GTK on Apple macOS](osx.html?native-window-controls). *)

external set_side : t -> Gtk_enums.packtype -> unit
  = "ml_gtk_window_controls_set_side"
(** Determines which part of decoration layout the window controls widget uses.

    See [property@Gtk.WindowControls:decoration-layout]. *)

external set_decoration_layout : t -> string option -> unit
  = "ml_gtk_window_controls_set_decoration_layout"
(** Sets the decoration layout for the title buttons.

This overrides the [property@Gtk.Settings:gtk-decoration-layout]
setting.

The format of the string is button names, separated by commas.
A colon separates the buttons that should appear on the left
from those on the right. Recognized button names are minimize,
maximize, close and icon (the window icon).

For example, “icon:minimize,maximize,close” specifies a icon
on the left, and minimize, maximize and close buttons on the right.

If [property@Gtk.WindowControls:side] value is [enum@Gtk.PackType.start],
@self will display the part before the colon, otherwise after that. *)

external get_use_native_controls : t -> bool
  = "ml_gtk_window_controls_get_use_native_controls"
(** Returns whether platform native window controls are shown. *)

external get_side : t -> Gtk_enums.packtype = "ml_gtk_window_controls_get_side"
(** Gets the side to which this window controls widget belongs. *)

external get_empty : t -> bool = "ml_gtk_window_controls_get_empty"
(** Gets whether the widget has any window buttons. *)

external get_decoration_layout : t -> string option
  = "ml_gtk_window_controls_get_decoration_layout"
(** Gets the decoration layout of this window controls widget *)

(* Properties *)
