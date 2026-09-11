(* GENERATED CODE - DO NOT EDIT *)
(* EventControllerLegacy: EventControllerLegacy *)

type t = [ `event_controller_legacy | `event_controller | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gtk_event_controller_legacy_get_type"

external new_ : unit -> t = "ml_gtk_event_controller_legacy_new"
(** Create a new EventControllerLegacy *)

(* Methods *)
val on_event :
  ?after:bool ->
  t ->
  callback:(event:Ocgtk_gdk.Gdk.Wrappers.Event.t -> bool) ->
  Gobject.Signal.handler_id
