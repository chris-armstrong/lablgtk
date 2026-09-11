(* GENERATED CODE - DO NOT EDIT *)
(* GestureClick: GestureClick *)

type t =
  [ `gesture_click | `gesture_single | `gesture | `event_controller | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_gesture_click_get_type"

external new_ : unit -> t = "ml_gtk_gesture_click_new"
(** Create a new GestureClick *)

(* Methods *)
val on_pressed :
  ?after:bool ->
  t ->
  callback:(n_press:int -> x:float -> y:float -> unit) ->
  Gobject.Signal.handler_id

val on_released :
  ?after:bool ->
  t ->
  callback:(n_press:int -> x:float -> y:float -> unit) ->
  Gobject.Signal.handler_id

val on_stopped :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
