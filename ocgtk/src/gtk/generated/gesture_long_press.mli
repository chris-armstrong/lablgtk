(* GENERATED CODE - DO NOT EDIT *)
(* GestureLongPress: GestureLongPress *)

type t =
  [ `gesture_long_press
  | `gesture_single
  | `gesture
  | `event_controller
  | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_gesture_long_press_get_type"

external new_ : unit -> t = "ml_gtk_gesture_long_press_new"
(** Create a new GestureLongPress *)

(* Methods *)

external set_delay_factor : t -> float -> unit
  = "ml_gtk_gesture_long_press_set_delay_factor"
(** Applies the given delay factor.

    The default long press time will be multiplied by this value. Valid values
    are in the range [0.5..2.0]. *)

external get_delay_factor : t -> float
  = "ml_gtk_gesture_long_press_get_delay_factor"
(** Returns the delay factor. *)

(* Properties *)

val on_cancelled :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_pressed :
  ?after:bool ->
  t ->
  callback:(x:float -> y:float -> unit) ->
  Gobject.Signal.handler_id
