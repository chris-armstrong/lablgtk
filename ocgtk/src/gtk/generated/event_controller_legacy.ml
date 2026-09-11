(* GENERATED CODE - DO NOT EDIT *)
(* EventControllerLegacy: EventControllerLegacy *)

type t = [ `event_controller_legacy | `event_controller | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gtk_event_controller_legacy_get_type"

external new_ : unit -> t = "ml_gtk_event_controller_legacy_new"
(** Create a new EventControllerLegacy *)

(* Methods *)
let on_event ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let event =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v (Ocgtk_gdk.Gdk.Wrappers.Event.gtype ())
        in
        let result = callback ~event in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"event" ~callback:closure
    ~after:(Option.value after ~default:false)
