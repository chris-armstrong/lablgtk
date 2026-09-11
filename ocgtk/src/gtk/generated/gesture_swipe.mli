(* GENERATED CODE - DO NOT EDIT *)
(* GestureSwipe: GestureSwipe *)

type t =
  [ `gesture_swipe | `gesture_single | `gesture | `event_controller | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_gesture_swipe_get_type"

external new_ : unit -> t = "ml_gtk_gesture_swipe_new"
(** Create a new GestureSwipe *)

(* Methods *)

external get_velocity : t -> bool * float * float
  = "ml_gtk_gesture_swipe_get_velocity"
(** Gets the current velocity.

If the gesture is recognized, this function returns %TRUE and fills
in @velocity_x and @velocity_y with the recorded velocity, as per the
last events processed. *)

val on_swipe :
  ?after:bool ->
  t ->
  callback:(velocity_x:float -> velocity_y:float -> unit) ->
  Gobject.Signal.handler_id
