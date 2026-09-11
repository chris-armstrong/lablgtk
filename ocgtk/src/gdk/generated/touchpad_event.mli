(* GENERATED CODE - DO NOT EDIT *)
(* TouchpadEvent: TouchpadEvent *)

type t = [ `touchpad_event | `event ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_touchpad_event_get_type"

(* Methods *)

external get_pinch_scale : t -> float = "ml_gdk_touchpad_event_get_pinch_scale"
(** Extracts the scale from a touchpad pinch event. *)

external get_pinch_angle_delta : t -> float
  = "ml_gdk_touchpad_event_get_pinch_angle_delta"
(** Extracts the angle delta from a touchpad pinch event. *)

external get_n_fingers : t -> int = "ml_gdk_touchpad_event_get_n_fingers"
(** Extracts the number of fingers from a touchpad event. *)

external get_gesture_phase : t -> Gdk_enums.touchpadgesturephase
  = "ml_gdk_touchpad_event_get_gesture_phase"
(** Extracts the touchpad gesture phase from a touchpad event. *)

external get_deltas : t -> float * float = "ml_gdk_touchpad_event_get_deltas"
(** Extracts delta information from a touchpad event. *)
