(* GENERATED CODE - DO NOT EDIT *)
(* MemoryMonitor: MemoryMonitor *)

type t = [ `memory_monitor ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_memory_monitor_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gio_memory_monitor_from_gobject"

(* Methods *)
val on_low_memory_warning :
  ?after:bool ->
  t ->
  callback:(level:Gio_enums.memorymonitorwarninglevel -> unit) ->
  Gobject.Signal.handler_id
