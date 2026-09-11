(* GENERATED CODE - DO NOT EDIT *)
(* CheckButton: CheckButton *)

type t = [ `check_button | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_check_button_get_type"

external new_ : unit -> t = "ml_gtk_check_button_new"
(** Create a new CheckButton *)

external new_with_label : string option -> t
  = "ml_gtk_check_button_new_with_label"
(** Create a new CheckButton *)

external new_with_mnemonic : string option -> t
  = "ml_gtk_check_button_new_with_mnemonic"
(** Create a new CheckButton *)

(* Methods *)

external set_use_underline : t -> bool -> unit
  = "ml_gtk_check_button_set_use_underline"
(** Sets whether underlines in the label indicate mnemonics.

If @setting is %TRUE, an underscore character in @self's label
indicates a mnemonic accelerator key. This behavior is similar
to [property@Gtk.Label:use-underline]. *)

external set_label : t -> string option -> unit
  = "ml_gtk_check_button_set_label"
(** Sets the text of @self.

If [property@Gtk.CheckButton:use-underline] is %TRUE, an underscore
in @label is interpreted as mnemonic indicator, see
[method@Gtk.CheckButton.set_use_underline] for details on this behavior. *)

external set_inconsistent : t -> bool -> unit
  = "ml_gtk_check_button_set_inconsistent"
(** Sets the `GtkCheckButton` to inconsistent state.

    You should turn off the inconsistent state again if the user checks the
    check button. This has to be done manually. *)

external set_group : t -> t option -> unit = "ml_gtk_check_button_set_group"
(** Adds @self to the group of @group.

In a group of multiple check buttons, only one button can be active
at a time. The behavior of a checkbutton in a group is also commonly
known as a *radio button*.

Setting the group of a check button also changes the css name of the
indicator widget's CSS node to 'radio'.

Setting up groups in a cycle leads to undefined behavior.

Note that the same effect can be achieved via the [iface@Gtk.Actionable]
API, by using the same action with parameter type and state type 's'
for all buttons in the group, and giving each button its own target
value. *)

external set_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_check_button_set_child"
(** Sets the child widget of @button.

Note that by using this API, you take full responsibility for setting
up the proper accessibility label and description information for @button.
Most likely, you'll either set the accessibility label or description
for @button explicitly, or you'll set a labelled-by or described-by
relations from @child to @button. *)

external set_active : t -> bool -> unit = "ml_gtk_check_button_set_active"
(** Changes the check buttons active state. *)

external get_use_underline : t -> bool = "ml_gtk_check_button_get_use_underline"
(** Returns whether underlines in the label indicate mnemonics. *)

external get_label : t -> string option = "ml_gtk_check_button_get_label"
(** Returns the label of the check button or `NULL` if
    [property@CheckButton:child] is set. *)

external get_inconsistent : t -> bool = "ml_gtk_check_button_get_inconsistent"
(** Returns whether the check button is in an inconsistent state. *)

external get_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_check_button_get_child"
(** Gets the child widget of @button or `NULL` if [property@CheckButton:label] is set. *)

external get_active : t -> bool = "ml_gtk_check_button_get_active"
(** Returns whether the check button is active. *)

(* Properties *)

let on_activate ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"activate" ~callback
    ~after:(Option.value after ~default:false)

let on_toggled ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"toggled" ~callback
    ~after:(Option.value after ~default:false)
