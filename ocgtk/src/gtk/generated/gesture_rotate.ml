(* GENERATED CODE - DO NOT EDIT *)
(* GestureRotate: GestureRotate *)

type t =
  [ `gesture_rotate | `gesture | `event_controller | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_gesture_rotate_get_type"

external new_ : unit -> t = "ml_gtk_gesture_rotate_new"
(** Create a new GestureRotate *)

(* Methods *)

external get_angle_delta : t -> float = "ml_gtk_gesture_rotate_get_angle_delta"
(** Gets the angle delta in radians.

If @gesture is active, this function returns the angle difference
in radians since the gesture was first recognized. If @gesture is
not active, 0 is returned. *)

let on_angle_changed ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let angle =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_double v
        in
        let angle_delta =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_double v
        in
        callback ~angle ~angle_delta)
  in
  Gobject.Signal.connect obj ~name:"angle-changed" ~callback:closure
    ~after:(Option.value after ~default:false)
