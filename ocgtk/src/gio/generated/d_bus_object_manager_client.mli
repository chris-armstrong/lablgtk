(* GENERATED CODE - DO NOT EDIT *)
(* DBusObjectManagerClient: DBusObjectManagerClient *)

type t = [ `d_bus_object_manager_client | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gio_d_bus_object_manager_client_get_type"

external new_finish : Async_result.t -> (t, GError.t) result
  = "ml_g_dbus_object_manager_client_new_finish"
(** Create a new DBusObjectManagerClient *)

external new_for_bus_finish : Async_result.t -> (t, GError.t) result
  = "ml_g_dbus_object_manager_client_new_for_bus_finish"
(** Create a new DBusObjectManagerClient *)

(* Methods *)

external get_name_owner : t -> string option
  = "ml_g_dbus_object_manager_client_get_name_owner"
(** The unique name that owns the name that @manager is for or %NULL if
no-one currently owns that name. You can connect to the
#GObject::notify signal to track changes to the
#GDBusObjectManagerClient:name-owner property. *)

external get_name : t -> string = "ml_g_dbus_object_manager_client_get_name"
(** Gets the name that @manager is for, or %NULL if not a message bus
connection. *)

external get_flags : t -> Gio_enums.dbusobjectmanagerclientflags
  = "ml_g_dbus_object_manager_client_get_flags"
(** Gets the flags that @manager was constructed with. *)

external get_connection : t -> D_bus_connection.t
  = "ml_g_dbus_object_manager_client_get_connection"
(** Gets the #GDBusConnection used by @manager. *)

(* Properties *)

external get_object_path : t -> string
  = "ml_g_d_bus_object_manager_client_get_object_path"
(** Get property: object-path *)

val on_interface_proxy_signal :
  ?after:bool ->
  t ->
  callback:
    (object_proxy:D_bus_object_proxy.t ->
    interface_proxy:D_bus_proxy.t ->
    sender_name:string ->
    signal_name:string ->
    parameters:Gvariant.t ->
    unit) ->
  Gobject.Signal.handler_id
