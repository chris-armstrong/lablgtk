(* GENERATED CODE - DO NOT EDIT *)
(* DBusInterfaceSkeleton: DBusInterfaceSkeleton *)

type t = [ `d_bus_interface_skeleton | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gio_d_bus_interface_skeleton_get_type"

(* Methods *)

external unexport_from_connection : t -> D_bus_connection.t -> unit
  = "ml_g_dbus_interface_skeleton_unexport_from_connection"
(** Stops exporting @interface_ on @connection.

To stop exporting on all connections the interface is exported on,
use g_dbus_interface_skeleton_unexport(). *)

external unexport : t -> unit = "ml_g_dbus_interface_skeleton_unexport"
(** Stops exporting @interface_ on all connections it is exported on.

To unexport @interface_ from only a single connection, use
g_dbus_interface_skeleton_unexport_from_connection() *)

external set_flags : t -> Gio_enums.dbusinterfaceskeletonflags -> unit
  = "ml_g_dbus_interface_skeleton_set_flags"
(** Sets flags describing what the behavior of @skeleton should be. *)

external has_connection : t -> D_bus_connection.t -> bool
  = "ml_g_dbus_interface_skeleton_has_connection"
(** Checks if @interface_ is exported on @connection. *)

external get_vtable : t -> D_bus_interface_v_table.t
  = "ml_g_dbus_interface_skeleton_get_vtable"
(** Gets the interface vtable for the D-Bus interface implemented by
@interface_. The returned function pointers should expect @interface_
itself to be passed as @user_data. *)

external get_properties : t -> Gvariant.t
  = "ml_g_dbus_interface_skeleton_get_properties"
(** Gets all D-Bus properties for @interface_. *)

external get_object_path : t -> string option
  = "ml_g_dbus_interface_skeleton_get_object_path"
(** Gets the object path that @interface_ is exported on, if any. *)

external get_info : t -> D_bus_interface_info.t
  = "ml_g_dbus_interface_skeleton_get_info"
(** Gets D-Bus introspection information for the D-Bus interface
implemented by @interface_. *)

external get_flags : t -> Gio_enums.dbusinterfaceskeletonflags
  = "ml_g_dbus_interface_skeleton_get_flags"
(** Gets the #GDBusInterfaceSkeletonFlags that describes what the behavior
of @interface_ *)

external get_connections : t -> D_bus_connection.t list
  = "ml_g_dbus_interface_skeleton_get_connections"
(** Gets a list of the connections that @interface_ is exported on. *)

external get_connection : t -> D_bus_connection.t option
  = "ml_g_dbus_interface_skeleton_get_connection"
(** Gets the first connection that @interface_ is exported on, if any. *)

external flush : t -> unit = "ml_g_dbus_interface_skeleton_flush"
(** If @interface_ has outstanding changes, request for these changes to be
emitted immediately.

For example, an exported D-Bus interface may queue up property
changes and emit the
`org.freedesktop.DBus.Properties.PropertiesChanged`
signal later (e.g. in an idle handler). This technique is useful
for collapsing multiple property changes into one. *)

external export : t -> D_bus_connection.t -> string -> (bool, GError.t) result
  = "ml_g_dbus_interface_skeleton_export"
(** Exports @interface_ at @object_path on @connection.

This can be called multiple times to export the same @interface_
onto multiple connections however the @object_path provided must be
the same for all connections.

Use g_dbus_interface_skeleton_unexport() to unexport the object. *)

(* Properties *)

external get_g_flags : t -> Gio_enums.dbusinterfaceskeletonflags
  = "ml_g_d_bus_interface_skeleton_get_g_flags"
(** Get property: g-flags *)

external set_g_flags : t -> Gio_enums.dbusinterfaceskeletonflags -> unit
  = "ml_g_d_bus_interface_skeleton_set_g_flags"
(** Set property: g-flags *)

val on_g_authorize_method :
  ?after:bool ->
  t ->
  callback:(invocation:D_bus_method_invocation.t -> bool) ->
  Gobject.Signal.handler_id
