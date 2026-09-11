(* GENERATED CODE - DO NOT EDIT *)
(* TouchEvent: TouchEvent *)

type t = [ `touch_event | `event ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_touch_event_get_type"

(* Methods *)

external get_emulating_pointer : t -> bool
  = "ml_gdk_touch_event_get_emulating_pointer"
(** Extracts whether a touch event is emulating a pointer event. *)
