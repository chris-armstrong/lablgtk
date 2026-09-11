(* GENERATED CODE - DO NOT EDIT *)
(* DropTargetAsync: DropTargetAsync *)

type t = [ `drop_target_async | `event_controller | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_drop_target_async_get_type"

external new_ :
  Ocgtk_gdk.Gdk.Wrappers.Content_formats.t option ->
  Ocgtk_gdk.Gdk.dragaction ->
  t = "ml_gtk_drop_target_async_new"
(** Create a new DropTargetAsync *)

(* Methods *)

external set_formats :
  t -> Ocgtk_gdk.Gdk.Wrappers.Content_formats.t option -> unit
  = "ml_gtk_drop_target_async_set_formats"
(** Sets the data formats that this drop target will accept. *)

external set_actions : t -> Ocgtk_gdk.Gdk.dragaction -> unit
  = "ml_gtk_drop_target_async_set_actions"
(** Sets the actions that this drop target supports. *)

external reject_drop : t -> Ocgtk_gdk.Gdk.Wrappers.Drop.t -> unit
  = "ml_gtk_drop_target_async_reject_drop"
(** Sets the @drop as not accepted on this drag site.

This function should be used when delaying the decision
on whether to accept a drag or not until after reading
the data. *)

external get_formats : t -> Ocgtk_gdk.Gdk.Wrappers.Content_formats.t option
  = "ml_gtk_drop_target_async_get_formats"
(** Gets the data formats that this drop target accepts.

    If the result is %NULL, all formats are expected to be supported. *)

external get_actions : t -> Ocgtk_gdk.Gdk.dragaction
  = "ml_gtk_drop_target_async_get_actions"
(** Gets the actions that this drop target supports. *)

(* Properties *)

let on_accept ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let drop =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v (Ocgtk_gdk.Gdk.Wrappers.Drop.gtype ())
        in
        let result = callback ~drop in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"accept" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_drag_enter ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let drop =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v (Ocgtk_gdk.Gdk.Wrappers.Drop.gtype ())
        in
        let x =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_double v
        in
        let y =
          let v = Gobject.Closure.nth argv ~pos:3 in
          Gobject.Value.get_double v
        in
        let result = callback ~drop ~x ~y in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_flags_int v (Ocgtk_gdk.Gdk_enums.dragaction_to_int x))
  in
  Gobject.Signal.connect obj ~name:"drag-enter" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_drag_leave ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let drop =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v (Ocgtk_gdk.Gdk.Wrappers.Drop.gtype ())
        in
        callback ~drop)
  in
  Gobject.Signal.connect obj ~name:"drag-leave" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_drag_motion ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let drop =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v (Ocgtk_gdk.Gdk.Wrappers.Drop.gtype ())
        in
        let x =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_double v
        in
        let y =
          let v = Gobject.Closure.nth argv ~pos:3 in
          Gobject.Value.get_double v
        in
        let result = callback ~drop ~x ~y in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_flags_int v (Ocgtk_gdk.Gdk_enums.dragaction_to_int x))
  in
  Gobject.Signal.connect obj ~name:"drag-motion" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_drop ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let drop =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v (Ocgtk_gdk.Gdk.Wrappers.Drop.gtype ())
        in
        let x =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_double v
        in
        let y =
          let v = Gobject.Closure.nth argv ~pos:3 in
          Gobject.Value.get_double v
        in
        let result = callback ~drop ~x ~y in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"drop" ~callback:closure
    ~after:(Option.value after ~default:false)
