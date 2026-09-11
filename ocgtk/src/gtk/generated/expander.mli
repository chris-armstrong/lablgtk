(* GENERATED CODE - DO NOT EDIT *)
(* Expander: Expander *)

type t = [ `expander | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_expander_get_type"

external new_ : string option -> t = "ml_gtk_expander_new"
(** Create a new Expander *)

external new_with_mnemonic : string option -> t
  = "ml_gtk_expander_new_with_mnemonic"
(** Create a new Expander *)

(* Methods *)

external set_use_underline : t -> bool -> unit
  = "ml_gtk_expander_set_use_underline"
(** If true, an underline in the text indicates a mnemonic. *)

external set_use_markup : t -> bool -> unit = "ml_gtk_expander_set_use_markup"
(** Sets whether the text of the label contains Pango markup. *)

external set_resize_toplevel : t -> bool -> unit
  = "ml_gtk_expander_set_resize_toplevel"
(** Sets whether the expander will resize the toplevel widget containing the
    expander upon resizing and collapsing. *)

external set_label_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_expander_set_label_widget"
(** Set the label widget for the expander.

    This is the widget that will appear embedded alongside the expander arrow.
*)

external set_label : t -> string option -> unit = "ml_gtk_expander_set_label"
(** Sets the text of the label of the expander to @label.

This will also clear any previously set labels. *)

external set_expanded : t -> bool -> unit = "ml_gtk_expander_set_expanded"
(** Sets the state of the expander.

    Set to %TRUE, if you want the child widget to be revealed, and %FALSE if you
    want the child widget to be hidden. *)

external set_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_expander_set_child"
(** Sets the child widget of @expander. *)

external get_use_underline : t -> bool = "ml_gtk_expander_get_use_underline"
(** Returns whether an underline in the text indicates a mnemonic. *)

external get_use_markup : t -> bool = "ml_gtk_expander_get_use_markup"
(** Returns whether the label’s text is interpreted as Pango markup. *)

external get_resize_toplevel : t -> bool = "ml_gtk_expander_get_resize_toplevel"
(** Returns whether the expander will resize the toplevel widget containing the
    expander upon resizing and collapsing. *)

external get_label_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_expander_get_label_widget"
(** Retrieves the label widget for the frame. *)

external get_label : t -> string option = "ml_gtk_expander_get_label"
(** Fetches the text from a label widget.

    This is including any embedded underlines indicating mnemonics and Pango
    markup, as set by [method@Gtk.Expander.set_label]. If the label text has not
    been set the return value will be %NULL. This will be the case if you create
    an empty button with gtk_button_new() to use as a container. *)

external get_expanded : t -> bool = "ml_gtk_expander_get_expanded"
(** Queries a `GtkExpander` and returns its current state.

    Returns %TRUE if the child widget is revealed. *)

external get_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_expander_get_child"
(** Gets the child widget of @expander. *)

(* Properties *)

val on_activate :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
