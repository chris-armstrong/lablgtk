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

let on_interface_proxy_signal ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let object_proxy =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v (D_bus_object_proxy.gtype ())
        in
        let interface_proxy =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_object_exn v (D_bus_proxy.gtype ())
        in
        let sender_name =
          let v = Gobject.Closure.nth argv ~pos:3 in
          Gobject.Value.get_string v
        in
        let signal_name =
          let v = Gobject.Closure.nth argv ~pos:4 in
          Gobject.Value.get_string v
        in
        let parameters =
          let v = Gobject.Closure.nth argv ~pos:5 in
          Gobject.Value.get_variant v
        in
        callback ~object_proxy ~interface_proxy ~sender_name ~signal_name
          ~parameters)
  in
  Gobject.Signal.connect obj ~name:"interface-proxy-signal" ~callback:closure
    ~after:(Option.value after ~default:false)
