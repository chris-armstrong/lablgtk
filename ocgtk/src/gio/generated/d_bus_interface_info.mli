(* GENERATED CODE - DO NOT EDIT *)
(* DBusInterfaceInfo: DBusInterfaceInfo *)

type t = [ `d_bus_interface_info ] Gobject.obj
(** Information about a D-Bus interface. *)

external gtype : unit -> Gobject.Type.t = "ml_gio_d_bus_interface_info_get_type"

(* Methods *)

external ref : t -> t = "ml_g_dbus_interface_info_ref"
(** If @info is statically allocated does nothing. Otherwise increases
the reference count. *)

external lookup_signal : t -> string -> D_bus_signal_info.t option
  = "ml_g_dbus_interface_info_lookup_signal"
(** Looks up information about a signal.

The cost of this function is O(n) in number of signals unless
g_dbus_interface_info_cache_build() has been used on @info. *)

external lookup_property : t -> string -> D_bus_property_info.t option
  = "ml_g_dbus_interface_info_lookup_property"
(** Looks up information about a property.

The cost of this function is O(n) in number of properties unless
g_dbus_interface_info_cache_build() has been used on @info. *)

external lookup_method : t -> string -> D_bus_method_info.t option
  = "ml_g_dbus_interface_info_lookup_method"
(** Looks up information about a method.

The cost of this function is O(n) in number of methods unless
g_dbus_interface_info_cache_build() has been used on @info. *)

external cache_release : t -> unit = "ml_g_dbus_interface_info_cache_release"
(** Decrements the usage count for the cache for @info built by
g_dbus_interface_info_cache_build() (if any) and frees the
resources used by the cache if the usage count drops to zero. *)

external cache_build : t -> unit = "ml_g_dbus_interface_info_cache_build"
(** Builds a lookup-cache to speed up
g_dbus_interface_info_lookup_method(),
g_dbus_interface_info_lookup_signal() and
g_dbus_interface_info_lookup_property().

If this has already been called with @info, the existing cache is
used and its use count is increased.

Note that @info cannot be modified until
g_dbus_interface_info_cache_release() is called. *)
