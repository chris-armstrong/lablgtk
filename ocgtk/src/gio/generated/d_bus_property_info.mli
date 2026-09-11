(* GENERATED CODE - DO NOT EDIT *)
(* DBusPropertyInfo: DBusPropertyInfo *)

type t = [ `d_bus_property_info ] Gobject.obj
(** Information about a D-Bus property on a D-Bus interface. *)

external gtype : unit -> Gobject.Type.t = "ml_gio_d_bus_property_info_get_type"

(* Methods *)

external ref : t -> t = "ml_g_dbus_property_info_ref"
(** If @info is statically allocated does nothing. Otherwise increases
the reference count. *)
