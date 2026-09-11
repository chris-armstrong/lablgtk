(* GENERATED CODE - DO NOT EDIT *)
(* DBusMethodInvocation: DBusMethodInvocation *)

type t = [ `d_bus_method_invocation | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gio_d_bus_method_invocation_get_type"

(* Methods *)

external return_value_with_unix_fd_list :
  t -> Gvariant.t option -> Unix_fd_list.t option -> unit
  = "ml_g_dbus_method_invocation_return_value_with_unix_fd_list"
(** Like g_dbus_method_invocation_return_value() but also takes a #GUnixFDList.

This method is only available on UNIX.

This method will take ownership of @invocation. See
#GDBusInterfaceVTable for more information about the ownership of
@invocation. *)

external return_value : t -> Gvariant.t option -> unit
  = "ml_g_dbus_method_invocation_return_value"
(** Finishes handling a D-Bus method call by returning @parameters.
If the @parameters GVariant is floating, it is consumed.

It is an error if @parameters is not of the right format: it must be a tuple
containing the out-parameters of the D-Bus method. Even if the method has a
single out-parameter, it must be contained in a tuple. If the method has no
out-parameters, @parameters may be %NULL or an empty tuple.

|[<!-- language="C" -->
GDBusMethodInvocation *invocation = some_invocation;
g_autofree gchar *result_string = NULL;
g_autoptr (GError) error = NULL;

result_string = calculate_result (&error);

if (error != NULL)
  g_dbus_method_invocation_return_gerror (invocation, error);
else
  g_dbus_method_invocation_return_value (invocation,
                                         g_variant_new ("(s)", result_string));

// Do not free @invocation here; returning a value does that
]|

This method will take ownership of @invocation. See
#GDBusInterfaceVTable for more information about the ownership of
@invocation.

Since 2.48, if the method call requested for a reply not to be sent
then this call will sink @parameters and free @invocation, but
otherwise do nothing (as per the recommendations of the D-Bus
specification). *)

external return_gerror : t -> GError.t -> unit
  = "ml_g_dbus_method_invocation_return_gerror"
(** Like g_dbus_method_invocation_return_error() but takes a #GError
instead of the error domain, error code and message.

This method will take ownership of @invocation. See
#GDBusInterfaceVTable for more information about the ownership of
@invocation. *)

external return_dbus_error : t -> string -> string -> unit
  = "ml_g_dbus_method_invocation_return_dbus_error"
(** Finishes handling a D-Bus method call by returning an error.

This method will take ownership of @invocation. See
#GDBusInterfaceVTable for more information about the ownership of
@invocation. *)

external get_sender : t -> string option
  = "ml_g_dbus_method_invocation_get_sender"
(** Gets the bus name that invoked the method.

    This can return %NULL if not specified by the caller, e.g. on peer-to-peer
    connections. *)

external get_property_info : t -> D_bus_property_info.t option
  = "ml_g_dbus_method_invocation_get_property_info"
(** Gets information about the property that this method call is for, if any.

    This will only be set in the case of an invocation in response to a property
    Get or Set call that has been directed to the method call handler for an
    object on account of its property_get() or property_set() vtable pointers
    being unset.

    See #GDBusInterfaceVTable for more information.

    If the call was GetAll, %NULL will be returned. *)

external get_parameters : t -> Gvariant.t
  = "ml_g_dbus_method_invocation_get_parameters"
(** Gets the parameters of the method invocation. If there are no input
    parameters then this will return a GVariant with 0 children rather than
    NULL. *)

external get_object_path : t -> string
  = "ml_g_dbus_method_invocation_get_object_path"
(** Gets the object path the method was invoked on. *)

external get_method_name : t -> string
  = "ml_g_dbus_method_invocation_get_method_name"
(** Gets the name of the method that was invoked. *)

external get_method_info : t -> D_bus_method_info.t option
  = "ml_g_dbus_method_invocation_get_method_info"
(** Gets information about the method call, if any.

    If this method invocation is a property Get, Set or GetAll call that has
    been redirected to the method call handler then %NULL will be returned. See
    g_dbus_method_invocation_get_property_info() and #GDBusInterfaceVTable for
    more information. *)

external get_message : t -> D_bus_message.t
  = "ml_g_dbus_method_invocation_get_message"
(** Gets the #GDBusMessage for the method invocation. This is useful if you need
    to use low-level protocol features, such as UNIX file descriptor passing,
    that cannot be properly expressed in the #GVariant API.

    See this [server][class@Gio.DBusConnection#an-example-d-bus-server] and
    [client][class@Gio.DBusConnection#an-example-for-file-descriptor-passing]
    for an example of how to use this low-level API to send and receive UNIX
    file descriptors. *)

external get_interface_name : t -> string option
  = "ml_g_dbus_method_invocation_get_interface_name"
(** Gets the name of the D-Bus interface the method was invoked on.

    This can be `NULL` if it was not specified by the sender. See
    [callback@Gio.DBusInterfaceMethodCallFunc] or the
    [D-Bus Specification](https://dbus.freedesktop.org/doc/dbus-specification.html#message-protocol-types-method)
    for details on when this can happen and how it should be handled.

    If this method call is a property Get, Set or GetAll call that has been
    redirected to the method call handler then "org.freedesktop.DBus.Properties"
    will be returned. See #GDBusInterfaceVTable for more information. *)

external get_connection : t -> D_bus_connection.t
  = "ml_g_dbus_method_invocation_get_connection"
(** Gets the #GDBusConnection the method was invoked on. *)
