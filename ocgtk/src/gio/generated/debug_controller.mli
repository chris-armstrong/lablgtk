(* GENERATED CODE - DO NOT EDIT *)
(* DebugController: DebugController *)

type t = [ `debug_controller ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_debug_controller_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gio_debug_controller_from_gobject"

(* Methods *)

external set_debug_enabled : t -> bool -> unit
  = "ml_g_debug_controller_set_debug_enabled"
(** Set the value of #GDebugController:debug-enabled. *)

external get_debug_enabled : t -> bool
  = "ml_g_debug_controller_get_debug_enabled"
(** Get the value of #GDebugController:debug-enabled. *)

(* Properties *)
