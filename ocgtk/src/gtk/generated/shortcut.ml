(* GENERATED CODE - DO NOT EDIT *)
(* Shortcut: Shortcut *)

type t = [ `shortcut | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_shortcut_get_type"

external new_ : Shortcut_trigger.t option -> Shortcut_action.t option -> t
  = "ml_gtk_shortcut_new"
(** Create a new Shortcut *)

(* Methods *)

external set_trigger : t -> Shortcut_trigger.t option -> unit
  = "ml_gtk_shortcut_set_trigger"
(** Sets the new trigger for @self to be @trigger. *)

external set_arguments : t -> Gvariant.t option -> unit
  = "ml_gtk_shortcut_set_arguments"
(** Sets the arguments to pass when activating the shortcut. *)

external set_action : t -> Shortcut_action.t option -> unit
  = "ml_gtk_shortcut_set_action"
(** Sets the new action for @self to be @action. *)

external get_trigger : t -> Shortcut_trigger.t option
  = "ml_gtk_shortcut_get_trigger"
(** Gets the trigger used to trigger @self. *)

external get_arguments : t -> Gvariant.t option
  = "ml_gtk_shortcut_get_arguments"
(** Gets the arguments that are passed when activating the shortcut. *)

external get_action : t -> Shortcut_action.t option
  = "ml_gtk_shortcut_get_action"
(** Gets the action that is activated by this shortcut. *)

(* Properties *)
