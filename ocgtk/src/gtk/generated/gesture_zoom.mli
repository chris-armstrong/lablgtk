(* GENERATED CODE - DO NOT EDIT *)
(* GestureZoom: GestureZoom *)

type t = [ `gesture_zoom | `gesture | `event_controller | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_gesture_zoom_get_type"

external new_ : unit -> t = "ml_gtk_gesture_zoom_new"
(** Create a new GestureZoom *)

(* Methods *)

external get_scale_delta : t -> float = "ml_gtk_gesture_zoom_get_scale_delta"
(** Gets the scale delta.

If @gesture is active, this function returns the zooming
difference since the gesture was recognized (hence the
starting point is considered 1:1). If @gesture is not
active, 1 is returned. *)

val on_scale_changed :
  ?after:bool ->
  t ->
  callback:(scale:float -> unit) ->
  Gobject.Signal.handler_id
