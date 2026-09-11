(* GENERATED CODE - DO NOT EDIT *)
(* SignalAction: SignalAction *)

type t = [ `signal_action | `shortcut_action | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_signal_action_get_type"

external new_ : string -> t = "ml_gtk_signal_action_new"
(** Create a new SignalAction *)

(* Methods *)

external get_signal_name : t -> string = "ml_gtk_signal_action_get_signal_name"
(** Returns the name of the signal that will be emitted. *)

(* Properties *)
