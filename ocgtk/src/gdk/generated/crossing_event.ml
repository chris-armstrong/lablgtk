(* GENERATED CODE - DO NOT EDIT *)
(* CrossingEvent: CrossingEvent *)

type t = [ `crossing_event | `event ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_crossing_event_get_type"

(* Methods *)

external get_mode : t -> Gdk_enums.crossingmode
  = "ml_gdk_crossing_event_get_mode"
(** Extracts the crossing mode from a crossing event. *)

external get_focus : t -> bool = "ml_gdk_crossing_event_get_focus"
(** Checks if the @event surface is the focus surface. *)

external get_detail : t -> Gdk_enums.notifytype
  = "ml_gdk_crossing_event_get_detail"
(** Extracts the notify detail from a crossing event. *)
