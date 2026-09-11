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

let on_swipe ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let velocity_x =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_double v
        in
        let velocity_y =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_double v
        in
        callback ~velocity_x ~velocity_y)
  in
  Gobject.Signal.connect obj ~name:"swipe" ~callback:closure
    ~after:(Option.value after ~default:false)
