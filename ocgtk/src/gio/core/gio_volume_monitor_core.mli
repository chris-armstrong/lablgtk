(** Hand-written binding for the GVolumeMonitor singleton getter.

    [g_volume_monitor_get()] is a free function (not a GIR class constructor),
    so the generator does not produce it. This module provides the C FFI stub so
    that L1/L2 code can obtain the singleton [Volume_monitor] instance. *)

external volume_monitor_get : unit -> Volume_monitor.t
  = "ml_g_volume_monitor_get"
(** [volume_monitor_get ()] returns the global singleton [Volume_monitor.t]
    instance. Raises if GTK/GIO has not been initialised. *)
