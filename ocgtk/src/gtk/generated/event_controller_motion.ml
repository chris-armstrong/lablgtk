(* GENERATED CODE - DO NOT EDIT *)
(* EventControllerMotion: EventControllerMotion *)

type t = [ `event_controller_motion | `event_controller | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gtk_event_controller_motion_get_type"

external new_ : unit -> t = "ml_gtk_event_controller_motion_new"
(** Create a new EventControllerMotion *)

(* Methods *)

external is_pointer : t -> bool = "ml_gtk_event_controller_motion_is_pointer"
(** Returns if a pointer is within @self, but not one of its children. *)

external contains_pointer : t -> bool
  = "ml_gtk_event_controller_motion_contains_pointer"
(** Returns if a pointer is within @self or one of its children. *)

(* Properties *)

let on_enter ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let x =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_double v
        in
        let y =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_double v
        in
        callback ~x ~y)
  in
  Gobject.Signal.connect obj ~name:"enter" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_leave ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"leave" ~callback
    ~after:(Option.value after ~default:false)

let on_motion ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let x =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_double v
        in
        let y =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_double v
        in
        callback ~x ~y)
  in
  Gobject.Signal.connect obj ~name:"motion" ~callback:closure
    ~after:(Option.value after ~default:false)
