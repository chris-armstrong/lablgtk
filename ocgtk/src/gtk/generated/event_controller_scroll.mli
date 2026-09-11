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

val on_decelerate :
  ?after:bool ->
  t ->
  callback:(vel_x:float -> vel_y:float -> unit) ->
  Gobject.Signal.handler_id

val on_scroll :
  ?after:bool ->
  t ->
  callback:(dx:float -> dy:float -> bool) ->
  Gobject.Signal.handler_id

val on_scroll_begin :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_scroll_end :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
