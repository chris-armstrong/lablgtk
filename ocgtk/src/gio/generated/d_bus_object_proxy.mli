(* GENERATED CODE - DO NOT EDIT *)
(* DBusObjectProxy: DBusObjectProxy *)

type t = [ `d_bus_object_proxy | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_d_bus_object_proxy_get_type"

external new_ : D_bus_connection.t -> string -> t = "ml_g_dbus_object_proxy_new"
(** Create a new DBusObjectProxy *)

(* Methods *)

external get_connection : t -> D_bus_connection.t
  = "ml_g_dbus_object_proxy_get_connection"
(** Gets the connection that @proxy is for. *)

(* Properties *)

external get_g_connection : t -> D_bus_connection.t
  = "ml_g_d_bus_object_proxy_get_g_connection"
(** Get property: g-connection *)

external get_g_object_path : t -> string
  = "ml_g_d_bus_object_proxy_get_g_object_path"
(** Get property: g-object-path *)
