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

let on_scale_changed ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let scale =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_double v
        in
        callback ~scale)
  in
  Gobject.Signal.connect obj ~name:"scale-changed" ~callback:closure
    ~after:(Option.value after ~default:false)
