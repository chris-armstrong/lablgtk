(* GENERATED CODE - DO NOT EDIT *)
(* Buildable: Buildable *)

type t = [ `buildable ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_buildable_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gtk_buildable_from_gobject"

(* Methods *)

external get_buildable_id : t -> string option
  = "ml_gtk_buildable_get_buildable_id"
(** Gets the ID of the @buildable object.

`GtkBuilder` sets the name based on the ID attribute
of the `<object>` tag used to construct the @buildable. *)
