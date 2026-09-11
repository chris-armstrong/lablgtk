(* GENERATED CODE - DO NOT EDIT *)
(* GestureDrag: GestureDrag *)

type t =
  [ `gesture_drag | `gesture_single | `gesture | `event_controller | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_gesture_drag_get_type"

external new_ : unit -> t = "ml_gtk_gesture_drag_new"
(** Create a new GestureDrag *)

(* Methods *)

external get_start_point : t -> bool * float * float
  = "ml_gtk_gesture_drag_get_start_point"
(** Gets the point where the drag started.

If the @gesture is active, this function returns %TRUE
and fills in @x and @y with the drag start coordinates,
in widget-relative coordinates. *)

external get_offset : t -> bool * float * float
  = "ml_gtk_gesture_drag_get_offset"
(** Gets the offset from the start point.

If the @gesture is active, this function returns %TRUE and
fills in @x and @y with the coordinates of the current point,
as an offset to the starting drag point. *)

let on_drag_begin ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let start_x =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_double v
        in
        let start_y =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_double v
        in
        callback ~start_x ~start_y)
  in
  Gobject.Signal.connect obj ~name:"drag-begin" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_drag_end ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let offset_x =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_double v
        in
        let offset_y =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_double v
        in
        callback ~offset_x ~offset_y)
  in
  Gobject.Signal.connect obj ~name:"drag-end" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_drag_update ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let offset_x =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_double v
        in
        let offset_y =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_double v
        in
        callback ~offset_x ~offset_y)
  in
  Gobject.Signal.connect obj ~name:"drag-update" ~callback:closure
    ~after:(Option.value after ~default:false)
