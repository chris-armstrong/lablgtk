(* GENERATED CODE - DO NOT EDIT *)
(* Orientable: Orientable *)

type t = [ `orientable ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_orientable_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gtk_orientable_from_gobject"

(* Methods *)

external set_orientation : t -> Gtk_enums.orientation -> unit
  = "ml_gtk_orientable_set_orientation"
(** Sets the orientation of the @orientable. *)

external get_orientation : t -> Gtk_enums.orientation
  = "ml_gtk_orientable_get_orientation"
(** Retrieves the orientation of the @orientable. *)

(* Properties *)
