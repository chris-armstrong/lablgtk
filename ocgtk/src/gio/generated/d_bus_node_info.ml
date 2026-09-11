(* GENERATED CODE - DO NOT EDIT *)
(* DBusNodeInfo: DBusNodeInfo *)

type t = [ `d_bus_node_info ] Gobject.obj
(** Information about nodes in a remote object hierarchy. *)

external gtype : unit -> Gobject.Type.t = "ml_gio_d_bus_node_info_get_type"

external new_for_xml : string -> (t, GError.t) result
  = "ml_g_dbus_node_info_new_for_xml"
(** Create a new DBusNodeInfo *)

(* Methods *)

external ref : t -> t = "ml_g_dbus_node_info_ref"
(** If @info is statically allocated does nothing. Otherwise increases
the reference count. *)

external lookup_interface : t -> string -> D_bus_interface_info.t option
  = "ml_g_dbus_node_info_lookup_interface"
(** Looks up information about an interface.

    The cost of this function is O(n) in number of interfaces. *)
