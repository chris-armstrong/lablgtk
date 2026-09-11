(* GENERATED CODE - DO NOT EDIT *)
(* DBusArgInfo: DBusArgInfo *)

type t = [ `d_bus_arg_info ] Gobject.obj
(** Information about an argument for a method or a signal. *)

external gtype : unit -> Gobject.Type.t = "ml_gio_d_bus_arg_info_get_type"

(* Methods *)

external ref : t -> t = "ml_g_dbus_arg_info_ref"
(** If @info is statically allocated does nothing. Otherwise increases
the reference count. *)
