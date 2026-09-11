(* GENERATED CODE - DO NOT EDIT *)
(* DBusObjectManagerServer: DBusObjectManagerServer *)

type t = [ `d_bus_object_manager_server | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gio_d_bus_object_manager_server_get_type"

external new_ : string -> t = "ml_g_dbus_object_manager_server_new"
(** Create a new DBusObjectManagerServer *)

(* Methods *)

external unexport : t -> string -> bool
  = "ml_g_dbus_object_manager_server_unexport"
(** If @manager has an object at @path, removes the object. Otherwise
does nothing.

Note that @object_path must be in the hierarchy rooted by the
object path for @manager. *)

external set_connection : t -> D_bus_connection.t option -> unit
  = "ml_g_dbus_object_manager_server_set_connection"
(** Exports all objects managed by @manager on @connection. If
@connection is %NULL, stops exporting objects. *)

external is_exported : t -> D_bus_object_skeleton.t -> bool
  = "ml_g_dbus_object_manager_server_is_exported"
(** Returns whether @object is currently exported on @manager. *)

external get_connection : t -> D_bus_connection.t option
  = "ml_g_dbus_object_manager_server_get_connection"
(** Gets the #GDBusConnection used by @manager. *)

external export_uniquely : t -> D_bus_object_skeleton.t -> unit
  = "ml_g_dbus_object_manager_server_export_uniquely"
(** Like g_dbus_object_manager_server_export() but appends a string of
the form _N (with N being a natural number) to @object's object path
if an object with the given path already exists. As such, the
#GDBusObjectProxy:g-object-path property of @object may be modified. *)

external export : t -> D_bus_object_skeleton.t -> unit
  = "ml_g_dbus_object_manager_server_export"
(** Exports @object on @manager.

If there is already a #GDBusObject exported at the object path,
then the old object is removed.

The object path for @object must be in the hierarchy rooted by the
object path for @manager.

Note that @manager will take a reference on @object for as long as
it is exported. *)

(* Properties *)

external get_object_path : t -> string
  = "ml_g_d_bus_object_manager_server_get_object_path"
(** Get property: object-path *)
