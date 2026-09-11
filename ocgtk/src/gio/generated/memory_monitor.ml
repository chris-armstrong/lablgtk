(* GENERATED CODE - DO NOT EDIT *)
(* MemoryMonitor: MemoryMonitor *)

type t = [ `memory_monitor ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_memory_monitor_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gio_memory_monitor_from_gobject"

(* Methods *)
let on_low_memory_warning ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let level =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gio_enums.memorymonitorwarninglevel_of_int
            (Gobject.Value.get_enum_int v)
        in
        callback ~level)
  in
  Gobject.Signal.connect obj ~name:"low-memory-warning" ~callback:closure
    ~after:(Option.value after ~default:false)
