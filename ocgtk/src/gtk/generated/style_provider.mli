(* GENERATED CODE - DO NOT EDIT *)
(* StyleProvider: StyleProvider *)

type t = [ `style_provider ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_style_provider_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gtk_style_provider_from_gobject"

(* Methods *)
val on_gtk_private_changed :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
