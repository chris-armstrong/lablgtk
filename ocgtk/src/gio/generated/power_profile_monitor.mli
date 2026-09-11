(* GENERATED CODE - DO NOT EDIT *)
(* PowerProfileMonitor: PowerProfileMonitor *)

type t = [ `power_profile_monitor ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gio_power_profile_monitor_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gio_power_profile_monitor_from_gobject"

(* Methods *)

external get_power_saver_enabled : t -> bool
  = "ml_g_power_profile_monitor_get_power_saver_enabled"
(** Gets whether the system is in “Power Saver” mode.

    You are expected to listen to the
    #GPowerProfileMonitor::notify::power-saver-enabled signal to know when the
    profile has changed. *)

(* Properties *)
