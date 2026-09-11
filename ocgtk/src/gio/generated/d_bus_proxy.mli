(* GENERATED CODE - DO NOT EDIT *)
(* DBusProxy: DBusProxy *)

type t = [ `d_bus_proxy | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_d_bus_proxy_get_type"

external new_finish : Async_result.t -> (t, GError.t) result
  = "ml_g_dbus_proxy_new_finish"
(** Create a new DBusProxy *)

external new_for_bus_finish : Async_result.t -> (t, GError.t) result
  = "ml_g_dbus_proxy_new_for_bus_finish"
(** Create a new DBusProxy *)

external new_for_bus_sync :
  Gio_enums.bustype ->
  Gio_enums.dbusproxyflags ->
  D_bus_interface_info.t option ->
  string ->
  string ->
  string ->
  Cancellable.t option ->
  (t, GError.t) result
  = "ml_g_dbus_proxy_new_for_bus_sync_bytecode"
    "ml_g_dbus_proxy_new_for_bus_sync_native"
(** Create a new DBusProxy *)

external new_sync :
  D_bus_connection.t ->
  Gio_enums.dbusproxyflags ->
  D_bus_interface_info.t option ->
  string option ->
  string ->
  string ->
  Cancellable.t option ->
  (t, GError.t) result
  = "ml_g_dbus_proxy_new_sync_bytecode" "ml_g_dbus_proxy_new_sync_native"
(** Create a new DBusProxy *)

(* Methods *)

external set_interface_info : t -> D_bus_interface_info.t option -> unit
  = "ml_g_dbus_proxy_set_interface_info"
(** Ensure that interactions with @proxy conform to the given
interface. See the #GDBusProxy:g-interface-info property for more
details. *)

external set_default_timeout : t -> int -> unit
  = "ml_g_dbus_proxy_set_default_timeout"
(** Sets the timeout to use if -1 (specifying default timeout) is
passed as @timeout_msec in the g_dbus_proxy_call() and
g_dbus_proxy_call_sync() functions.

See the #GDBusProxy:g-default-timeout property for more details. *)

external set_cached_property : t -> string -> Gvariant.t option -> unit
  = "ml_g_dbus_proxy_set_cached_property"
(** If @value is not %NULL, sets the cached value for the property with
name @property_name to the value in @value.

If @value is %NULL, then the cached value is removed from the
property cache.

If @proxy has an expected interface (see
#GDBusProxy:g-interface-info) and @property_name is referenced by
it, then @value is checked against the type of the property.

If the @value #GVariant is floating, it is consumed. This allows
convenient 'inline' use of g_variant_new(), e.g.
|[<!-- language="C" -->
 g_dbus_proxy_set_cached_property (proxy,
                                   "SomeProperty",
                                   g_variant_new ("(si)",
                                                 "A String",
                                                 42));
]|

Normally you will not need to use this method since @proxy
is tracking changes using the
`org.freedesktop.DBus.Properties.PropertiesChanged`
D-Bus signal. However, for performance reasons an object may
decide to not use this signal for some properties and instead
use a proprietary out-of-band mechanism to transmit changes.

As a concrete example, consider an object with a property
`ChatroomParticipants` which is an array of strings. Instead of
transmitting the same (long) array every time the property changes,
it is more efficient to only transmit the delta using e.g. signals
`ChatroomParticipantJoined(String name)` and
`ChatroomParticipantParted(String name)`. *)

external get_object_path : t -> string = "ml_g_dbus_proxy_get_object_path"
(** Gets the object path @proxy is for. *)

external get_name_owner : t -> string option = "ml_g_dbus_proxy_get_name_owner"
(** The unique name that owns the name that @proxy is for or %NULL if
no-one currently owns that name. You may connect to the
#GObject::notify signal to track changes to the
#GDBusProxy:g-name-owner property. *)

external get_name : t -> string option = "ml_g_dbus_proxy_get_name"
(** Gets the name that @proxy was constructed for.

When connected to a message bus, this will usually be non-%NULL.
However, it may be %NULL for a proxy that communicates using a peer-to-peer
pattern. *)

external get_interface_name : t -> string = "ml_g_dbus_proxy_get_interface_name"
(** Gets the D-Bus interface name @proxy is for. *)

external get_interface_info : t -> D_bus_interface_info.t option
  = "ml_g_dbus_proxy_get_interface_info"
(** Returns the #GDBusInterfaceInfo, if any, specifying the interface
that @proxy conforms to. See the #GDBusProxy:g-interface-info
property for more details. *)

external get_flags : t -> Gio_enums.dbusproxyflags = "ml_g_dbus_proxy_get_flags"
(** Gets the flags that @proxy was constructed with. *)

external get_default_timeout : t -> int = "ml_g_dbus_proxy_get_default_timeout"
(** Gets the timeout to use if -1 (specifying default timeout) is
passed as @timeout_msec in the g_dbus_proxy_call() and
g_dbus_proxy_call_sync() functions.

See the #GDBusProxy:g-default-timeout property for more details. *)

external get_connection : t -> D_bus_connection.t
  = "ml_g_dbus_proxy_get_connection"
(** Gets the connection @proxy is for. *)

external get_cached_property_names : t -> string array option
  = "ml_g_dbus_proxy_get_cached_property_names"
(** Gets the names of all cached properties on @proxy. *)

external get_cached_property : t -> string -> Gvariant.t option
  = "ml_g_dbus_proxy_get_cached_property"
(** Looks up the value for a property from the cache. This call does no
blocking IO.

If @proxy has an expected interface (see
#GDBusProxy:g-interface-info) and @property_name is referenced by
it, then @value is checked against the type of the property. *)

external call_sync :
  t ->
  string ->
  Gvariant.t option ->
  Gio_enums.dbuscallflags ->
  int ->
  Cancellable.t option ->
  (Gvariant.t, GError.t) result
  = "ml_g_dbus_proxy_call_sync_bytecode" "ml_g_dbus_proxy_call_sync_native"
(** Synchronously invokes the @method_name method on @proxy.

If @method_name contains any dots, then @name is split into interface and
method name parts. This allows using @proxy for invoking methods on
other interfaces.

If the #GDBusConnection associated with @proxy is disconnected then
the operation will fail with %G_IO_ERROR_CLOSED. If
@cancellable is canceled, the operation will fail with
%G_IO_ERROR_CANCELLED. If @parameters contains a value not
compatible with the D-Bus protocol, the operation fails with
%G_IO_ERROR_INVALID_ARGUMENT.

If the @parameters #GVariant is floating, it is consumed. This allows
convenient 'inline' use of g_variant_new(), e.g.:
|[<!-- language="C" -->
 g_dbus_proxy_call_sync (proxy,
                         "TwoStrings",
                         g_variant_new ("(ss)",
                                        "Thing One",
                                        "Thing Two"),
                         G_DBUS_CALL_FLAGS_NONE,
                         -1,
                         NULL,
                         &error);
]|

The calling thread is blocked until a reply is received. See
g_dbus_proxy_call() for the asynchronous version of this
method.

If @proxy has an expected interface (see
#GDBusProxy:g-interface-info) and @method_name is referenced by it,
then the return value is checked against the return type. *)

external call_finish : t -> Async_result.t -> (Gvariant.t, GError.t) result
  = "ml_g_dbus_proxy_call_finish"
(** Finishes an operation started with g_dbus_proxy_call(). *)

(* Properties *)

external get_g_connection : t -> D_bus_connection.t
  = "ml_g_d_bus_proxy_get_g_connection"
(** Get property: g-connection *)

external get_g_default_timeout : t -> int
  = "ml_g_d_bus_proxy_get_g_default_timeout"
(** Get property: g-default-timeout *)

external set_g_default_timeout : t -> int -> unit
  = "ml_g_d_bus_proxy_set_g_default_timeout"
(** Set property: g-default-timeout *)

external get_g_flags : t -> Gio_enums.dbusproxyflags
  = "ml_g_d_bus_proxy_get_g_flags"
(** Get property: g-flags *)

external get_g_interface_info : t -> D_bus_interface_info.t
  = "ml_g_d_bus_proxy_get_g_interface_info"
(** Get property: g-interface-info *)

external set_g_interface_info : t -> D_bus_interface_info.t -> unit
  = "ml_g_d_bus_proxy_set_g_interface_info"
(** Set property: g-interface-info *)

external get_g_interface_name : t -> string
  = "ml_g_d_bus_proxy_get_g_interface_name"
(** Get property: g-interface-name *)

external get_g_name : t -> string = "ml_g_d_bus_proxy_get_g_name"
(** Get property: g-name *)

external get_g_name_owner : t -> string = "ml_g_d_bus_proxy_get_g_name_owner"
(** Get property: g-name-owner *)

external get_g_object_path : t -> string = "ml_g_d_bus_proxy_get_g_object_path"
(** Get property: g-object-path *)

val on_g_signal :
  ?after:bool ->
  t ->
  callback:
    (sender_name:string -> signal_name:string -> parameters:Gvariant.t -> unit) ->
  Gobject.Signal.handler_id
