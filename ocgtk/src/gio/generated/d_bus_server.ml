(* GENERATED CODE - DO NOT EDIT *)
(* DBusServer: DBusServer *)

type t = [ `d_bus_server | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_d_bus_server_get_type"

external new_sync :
  string ->
  Gio_enums.dbusserverflags ->
  string ->
  D_bus_auth_observer.t option ->
  Cancellable.t option ->
  (t, GError.t) result = "ml_g_dbus_server_new_sync"
(** Create a new DBusServer *)

(* Methods *)

external stop : t -> unit = "ml_g_dbus_server_stop"
(** Stops @server. *)

external start : t -> unit = "ml_g_dbus_server_start"
(** Starts @server. *)

external is_active : t -> bool = "ml_g_dbus_server_is_active"
(** Gets whether @server is active. *)

external get_guid : t -> string = "ml_g_dbus_server_get_guid"
(** Gets the GUID for @server, as provided to g_dbus_server_new_sync(). *)

external get_flags : t -> Gio_enums.dbusserverflags
  = "ml_g_dbus_server_get_flags"
(** Gets the flags for @server. *)

external get_client_address : t -> string
  = "ml_g_dbus_server_get_client_address"
(** Gets a
[D-Bus address](https://dbus.freedesktop.org/doc/dbus-specification.html#addresses)
string that can be used by clients to connect to @server.

This is valid and non-empty if initializing the #GDBusServer succeeded. *)

(* Properties *)

external get_address : t -> string = "ml_g_d_bus_server_get_address"
(** Get property: address *)

external get_authentication_observer : t -> D_bus_auth_observer.t
  = "ml_g_d_bus_server_get_authentication_observer"
(** Get property: authentication-observer *)

let on_new_connection ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let connection =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v (D_bus_connection.gtype ())
        in
        let result = callback ~connection in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"new-connection" ~callback:closure
    ~after:(Option.value after ~default:false)
