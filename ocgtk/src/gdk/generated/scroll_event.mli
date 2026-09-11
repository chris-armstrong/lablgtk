(* GENERATED CODE - DO NOT EDIT *)
(* ScrollEvent: ScrollEvent *)

type t = [ `scroll_event | `event ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_scroll_event_get_type"

(* Methods *)

external is_stop : t -> bool = "ml_gdk_scroll_event_is_stop"
(** Check whether a scroll event is a stop scroll event.

    Scroll sequences with smooth scroll information may provide a stop scroll
    event once the interaction with the device finishes, e.g. by lifting a
    finger. This stop scroll event is the signal that a widget may trigger
    kinetic scrolling based on the current velocity.

    Stop scroll events always have a delta of 0/0. *)

external get_unit : t -> Gdk_enums.scrollunit = "ml_gdk_scroll_event_get_unit"
(** Extracts the scroll delta unit of a scroll event.

    The unit will always be %GDK_SCROLL_UNIT_WHEEL if the scroll direction is
    not %GDK_SCROLL_SMOOTH. *)

external get_direction : t -> Gdk_enums.scrolldirection
  = "ml_gdk_scroll_event_get_direction"
(** Extracts the direction of a scroll event. *)

external get_deltas : t -> float * float = "ml_gdk_scroll_event_get_deltas"
(** Extracts the scroll deltas of a scroll event.

    The deltas will be zero unless the scroll direction is %GDK_SCROLL_SMOOTH.

    For the representation unit of these deltas, see
    [method@Gdk.ScrollEvent.get_unit]. *)
