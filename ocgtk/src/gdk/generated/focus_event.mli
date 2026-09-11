(* GENERATED CODE - DO NOT EDIT *)
(* FocusEvent: FocusEvent *)

type t = [ `focus_event | `event ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_focus_event_get_type"

(* Methods *)

external get_in : t -> bool = "ml_gdk_focus_event_get_in"
(** Extracts whether this event is about focus entering or leaving the surface.
*)
