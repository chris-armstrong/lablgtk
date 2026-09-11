(* GENERATED CODE - DO NOT EDIT *)
(* NamedAction: NamedAction *)

type t = [ `named_action | `shortcut_action | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_named_action_get_type"

external new_ : string -> t = "ml_gtk_named_action_new"
(** Create a new NamedAction *)

(* Methods *)

external get_action_name : t -> string = "ml_gtk_named_action_get_action_name"
(** Returns the name of the action that will be activated. *)

(* Properties *)
