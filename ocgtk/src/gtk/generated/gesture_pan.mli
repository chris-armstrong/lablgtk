(* GENERATED CODE - DO NOT EDIT *)
(* GesturePan: GesturePan *)

type t =
  [ `gesture_pan
  | `gesture_drag
  | `gesture_single
  | `gesture
  | `event_controller
  | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_gesture_pan_get_type"

external new_ : Gtk_enums.orientation -> t = "ml_gtk_gesture_pan_new"
(** Create a new GesturePan *)

(* Methods *)

external set_orientation : t -> Gtk_enums.orientation -> unit
  = "ml_gtk_gesture_pan_set_orientation"
(** Sets the orientation to be expected on pan gestures. *)

external get_orientation : t -> Gtk_enums.orientation
  = "ml_gtk_gesture_pan_get_orientation"
(** Returns the orientation of the pan gestures that this @gesture expects. *)

(* Properties *)

val on_pan :
  ?after:bool ->
  t ->
  callback:(direction:Gtk_enums.pandirection -> offset:float -> unit) ->
  Gobject.Signal.handler_id
