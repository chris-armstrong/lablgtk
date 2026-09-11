(* GENERATED CODE - DO NOT EDIT *)
(* DBusObjectManager: DBusObjectManager *)

type t = [ `d_bus_object_manager ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_d_bus_object_manager_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gio_d_bus_object_manager_from_gobject"

(* Methods *)

external get_objects :
  t -> D_bus_interface_and__d_bus_object.D_bus_object.t list
  = "ml_g_dbus_object_manager_get_objects"
(** Gets all #GDBusObject objects known to @manager. *)

external get_object_path : t -> string
  = "ml_g_dbus_object_manager_get_object_path"
(** Gets the object path that @manager is for. *)

external get_object :
  t -> string -> D_bus_interface_and__d_bus_object.D_bus_object.t option
  = "ml_g_dbus_object_manager_get_object"
(** Gets the #GDBusObject at @object_path, if any. *)

external get_interface :
  t ->
  string ->
  string ->
  D_bus_interface_and__d_bus_object.D_bus_interface.t option
  = "ml_g_dbus_object_manager_get_interface"
(** Gets the interface proxy for @interface_name at @object_path, if
any. *)

val on_interface_added :
  ?after:bool ->
  t ->
  callback:
    (object_:D_bus_interface_and__d_bus_object.D_bus_object.t ->
    interface:D_bus_interface_and__d_bus_object.D_bus_interface.t ->
    unit) ->
  Gobject.Signal.handler_id

val on_interface_removed :
  ?after:bool ->
  t ->
  callback:
    (object_:D_bus_interface_and__d_bus_object.D_bus_object.t ->
    interface:D_bus_interface_and__d_bus_object.D_bus_interface.t ->
    unit) ->
  Gobject.Signal.handler_id

val on_object_added :
  ?after:bool ->
  t ->
  callback:(object_:D_bus_interface_and__d_bus_object.D_bus_object.t -> unit) ->
  Gobject.Signal.handler_id

val on_object_removed :
  ?after:bool ->
  t ->
  callback:(object_:D_bus_interface_and__d_bus_object.D_bus_object.t -> unit) ->
  Gobject.Signal.handler_id
