(* GENERATED CODE - DO NOT EDIT *)
(* ToggleButton: ToggleButton *)

type t =
  [ `toggle_button | `button | `widget | `initially_unowned | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_toggle_button_get_type"

external new_ : unit -> t = "ml_gtk_toggle_button_new"
(** Create a new ToggleButton *)

external new_with_label : string -> t = "ml_gtk_toggle_button_new_with_label"
(** Create a new ToggleButton *)

external new_with_mnemonic : string -> t
  = "ml_gtk_toggle_button_new_with_mnemonic"
(** Create a new ToggleButton *)

(* Methods *)

external toggled : t -> unit = "ml_gtk_toggle_button_toggled"
(** Emits the ::toggled signal on the `GtkToggleButton`. *)

external set_group : t -> t option -> unit = "ml_gtk_toggle_button_set_group"
(** Adds @self to the group of @group.

In a group of multiple toggle buttons, only one button can be active
at a time.

Setting up groups in a cycle leads to undefined behavior.

Note that the same effect can be achieved via the [iface@Gtk.Actionable]
API, by using the same action with parameter type and state type 's'
for all buttons in the group, and giving each button its own target
value. *)

external set_active : t -> bool -> unit = "ml_gtk_toggle_button_set_active"
(** Sets the status of the toggle button.

    Set to %TRUE if you want the `GtkToggleButton` to be “pressed in”, and
    %FALSE to raise it.

    If the status of the button changes, this action causes the
    [signal@Gtk.ToggleButton::toggled] signal to be emitted. *)

external get_active : t -> bool = "ml_gtk_toggle_button_get_active"
(** Queries a `GtkToggleButton` and returns its current state.

    Returns %TRUE if the toggle button is pressed in and %FALSE if it is raised.
*)

(* Properties *)

val on_toggled :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
