(* GENERATED CODE - DO NOT EDIT *)
(* Button: Button *)

type t = [ `button | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_button_get_type"

external new_ : unit -> t = "ml_gtk_button_new"
(** Create a new Button *)

external new_from_icon_name : string -> t = "ml_gtk_button_new_from_icon_name"
(** Create a new Button *)

external new_with_label : string -> t = "ml_gtk_button_new_with_label"
(** Create a new Button *)

external new_with_mnemonic : string -> t = "ml_gtk_button_new_with_mnemonic"
(** Create a new Button *)

(* Methods *)

external set_use_underline : t -> bool -> unit
  = "ml_gtk_button_set_use_underline"
(** Sets whether to use underlines as mnemonics.

    If true, an underline in the text of the button label indicates the next
    character should be used for the mnemonic accelerator key. *)

external set_label : t -> string -> unit = "ml_gtk_button_set_label"
(** Sets the text of the label of the button to @label.

This will also clear any previously set labels. *)

external set_icon_name : t -> string -> unit = "ml_gtk_button_set_icon_name"
(** Adds a `GtkImage` with the given icon name as a child.

If @button already contains a child widget, that child widget will
be removed and replaced with the image. *)

external set_has_frame : t -> bool -> unit = "ml_gtk_button_set_has_frame"
(** Sets the style of the button.

    Buttons can have a flat appearance or have a frame drawn around them. *)

external set_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_button_set_child"
(** Sets the child widget of @button.

Note that by using this API, you take full responsibility for setting
up the proper accessibility label and description information for @button.
Most likely, you'll either set the accessibility label or description
for @button explicitly, or you'll set a labelled-by or described-by
relations from @child to @button. *)

external set_can_shrink : t -> bool -> unit = "ml_gtk_button_set_can_shrink"
(** Sets whether the button size can be smaller than the natural size of
its contents.

For text buttons, setting @can_shrink to true will ellipsize the label.

For icons and custom children, this function has no effect. *)

external get_use_underline : t -> bool = "ml_gtk_button_get_use_underline"
(** gets whether underlines are interpreted as mnemonics.

    See [method@Gtk.Button.set_use_underline]. *)

external get_label : t -> string option = "ml_gtk_button_get_label"
(** Fetches the text from the label of the button.

    If the label text has not been set with [method@Gtk.Button.set_label] the
    return value will be %NULL. This will be the case if you create an empty
    button with [ctor@Gtk.Button.new] to use as a container. *)

external get_icon_name : t -> string option = "ml_gtk_button_get_icon_name"
(** Returns the icon name of the button.

    If the icon name has not been set with [method@Gtk.Button.set_icon_name] the
    return value will be %NULL. This will be the case if you create an empty
    button with [ctor@Gtk.Button.new] to use as a container. *)

external get_has_frame : t -> bool = "ml_gtk_button_get_has_frame"
(** Returns whether the button has a frame. *)

external get_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_button_get_child"
(** Gets the child widget of @button. *)

external get_can_shrink : t -> bool = "ml_gtk_button_get_can_shrink"
(** Retrieves whether the button can be smaller than the natural size of its
    contents. *)

(* Properties *)

val on_activate :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_clicked :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
