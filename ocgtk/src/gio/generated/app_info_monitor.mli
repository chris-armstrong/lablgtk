(* GENERATED CODE - DO NOT EDIT *)
(* AppInfoMonitor: AppInfoMonitor *)

type t = [ `app_info_monitor | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_app_info_monitor_get_type"

(* Methods *)
val on_changed :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
