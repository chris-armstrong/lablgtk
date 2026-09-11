(* GENERATED CODE - DO NOT EDIT *)
(* GrabBrokenEvent: GrabBrokenEvent *)

type t = [ `grab_broken_event | `event ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_grab_broken_event_get_type"

(* Methods *)

external get_implicit : t -> bool = "ml_gdk_grab_broken_event_get_implicit"
(** Checks whether the grab broken event is for an implicit grab. *)

external get_grab_surface : t -> App_launch_context_cycle_de440b34.Surface.t
  = "ml_gdk_grab_broken_event_get_grab_surface"
(** Extracts the grab surface from a grab broken event. *)
