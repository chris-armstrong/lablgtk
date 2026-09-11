(* GENERATED CODE - DO NOT EDIT *)
(* Revealer: Revealer *)

type t = [ `revealer | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_revealer_get_type"

external new_ : unit -> t = "ml_gtk_revealer_new"
(** Create a new Revealer *)

(* Methods *)

external set_transition_type : t -> Gtk_enums.revealertransitiontype -> unit
  = "ml_gtk_revealer_set_transition_type"
(** Sets the type of animation that will be used for
transitions in @revealer.

Available types include various kinds of fades and slides. *)

external set_transition_duration : t -> int -> unit
  = "ml_gtk_revealer_set_transition_duration"
(** Sets the duration that transitions will take. *)

external set_reveal_child : t -> bool -> unit
  = "ml_gtk_revealer_set_reveal_child"
(** Tells the `GtkRevealer` to reveal or conceal its child.

The transition will be animated with the current
transition type of @revealer. *)

external set_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_revealer_set_child"
(** Sets the child widget of @revealer. *)

external get_transition_type : t -> Gtk_enums.revealertransitiontype
  = "ml_gtk_revealer_get_transition_type"
(** Gets the type of animation that will be used
for transitions in @revealer. *)

external get_transition_duration : t -> int
  = "ml_gtk_revealer_get_transition_duration"
(** Returns the amount of time (in milliseconds) that transitions will take. *)

external get_reveal_child : t -> bool = "ml_gtk_revealer_get_reveal_child"
(** Returns whether the child is currently revealed.

    This function returns %TRUE as soon as the transition is to the revealed
    state is started. To learn whether the child is fully revealed (ie the
    transition is completed), use [method@Gtk.Revealer.get_child_revealed]. *)

external get_child_revealed : t -> bool = "ml_gtk_revealer_get_child_revealed"
(** Returns whether the child is fully revealed.

    In other words, this returns whether the transition to the revealed state is
    completed. *)

external get_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_revealer_get_child"
(** Gets the child widget of @revealer. *)

(* Properties *)
