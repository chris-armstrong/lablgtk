(* GENERATED CODE - DO NOT EDIT *)
(* EventControllerScroll: EventControllerScroll *)

type t = [ `event_controller_scroll | `event_controller | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gtk_event_controller_scroll_get_type"

external new_ : Gtk_enums.eventcontrollerscrollflags -> t
  = "ml_gtk_event_controller_scroll_new"
(** Create a new EventControllerScroll *)

(* Methods *)

external set_flags : t -> Gtk_enums.eventcontrollerscrollflags -> unit
  = "ml_gtk_event_controller_scroll_set_flags"
(** Sets the flags conditioning scroll controller behavior. *)

external get_unit : t -> Ocgtk_gdk.Gdk.scrollunit
  = "ml_gtk_event_controller_scroll_get_unit"
(** Gets the scroll unit of the last [signal@Gtk.EventControllerScroll::scroll]
    signal received.

    Always returns %GDK_SCROLL_UNIT_WHEEL if the
    %GTK_EVENT_CONTROLLER_SCROLL_DISCRETE flag is set. *)

external get_flags : t -> Gtk_enums.eventcontrollerscrollflags
  = "ml_gtk_event_controller_scroll_get_flags"
(** Gets the flags conditioning the scroll controller behavior. *)

(* Properties *)

let on_decelerate ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let vel_x =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_double v
        in
        let vel_y =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_double v
        in
        callback ~vel_x ~vel_y)
  in
  Gobject.Signal.connect obj ~name:"decelerate" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_scroll ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let dx =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_double v
        in
        let dy =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_double v
        in
        let result = callback ~dx ~dy in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"scroll" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_scroll_begin ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"scroll-begin" ~callback
    ~after:(Option.value after ~default:false)

let on_scroll_end ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"scroll-end" ~callback
    ~after:(Option.value after ~default:false)
