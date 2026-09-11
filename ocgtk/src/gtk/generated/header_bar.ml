(* GENERATED CODE - DO NOT EDIT *)
(* HeaderBar: HeaderBar *)

type t = [ `header_bar | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_header_bar_get_type"

external new_ : unit -> t = "ml_gtk_header_bar_new"
(** Create a new HeaderBar *)

(* Methods *)

external set_use_native_controls : t -> bool -> unit
  = "ml_gtk_header_bar_set_use_native_controls"
(** Sets whether this header bar shows native window controls.

    This option shows the "stoplight" buttons on macOS. For Linux, this option
    has no effect.

    See also [Using GTK on Apple macOS](osx.html?native-window-controls). *)

external set_title_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_header_bar_set_title_widget"
(** Sets the title for the header bar.

    When set to `NULL`, the headerbar will display the title of the window it is
    contained in.

    The title should help a user identify the current view. To achieve the same
    style as the builtin title, use the “title” style class.

    You should set the title widget to `NULL`, for the window title label to be
    visible again. *)

external set_show_title_buttons : t -> bool -> unit
  = "ml_gtk_header_bar_set_show_title_buttons"
(** Sets whether this header bar shows the standard window title buttons. *)

external set_decoration_layout : t -> string option -> unit
  = "ml_gtk_header_bar_set_decoration_layout"
(** Sets the decoration layout for this header bar.

    This property overrides the [property@Gtk.Settings:gtk-decoration-layout]
    setting.

    There can be valid reasons for overriding the setting, such as a header bar
    design that does not allow for buttons to take room on the right, or only
    offers room for a single close button. Split header bars are another example
    for overriding the setting.

    The format of the string is button names, separated by commas. A colon
    separates the buttons that should appear on the left from those on the
    right. Recognized button names are minimize, maximize, close and icon (the
    window icon).

    For example, “icon:minimize,maximize,close” specifies an icon on the left,
    and minimize, maximize and close buttons on the right. *)

external remove :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  unit = "ml_gtk_header_bar_remove"
(** Removes a child from the header bar.

    The child must have been added with [method@Gtk.HeaderBar.pack_start],
    [method@Gtk.HeaderBar.pack_end] or [method@Gtk.HeaderBar.set_title_widget].
*)

external pack_start :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  unit = "ml_gtk_header_bar_pack_start"
(** Adds a child to the header bar, packed with reference to the start. *)

external pack_end :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  unit = "ml_gtk_header_bar_pack_end"
(** Adds a child to the header bar, packed with reference to the end. *)

external get_use_native_controls : t -> bool
  = "ml_gtk_header_bar_get_use_native_controls"
(** Returns whether this header bar shows platform native window controls. *)

external get_title_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_header_bar_get_title_widget"
(** Retrieves the title widget of the header bar.

    See [method@Gtk.HeaderBar.set_title_widget]. *)

external get_show_title_buttons : t -> bool
  = "ml_gtk_header_bar_get_show_title_buttons"
(** Returns whether this header bar shows the standard window title buttons. *)

external get_decoration_layout : t -> string option
  = "ml_gtk_header_bar_get_decoration_layout"
(** Gets the decoration layout of the header bar. *)

(* Properties *)
