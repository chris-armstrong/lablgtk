(* GENERATED CODE - DO NOT EDIT *)
(* SocketClient: SocketClient *)

type t = [ `socket_client | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_socket_client_get_type"

external new_ : unit -> t = "ml_g_socket_client_new"
(** Create a new SocketClient *)

(* Methods *)

external set_tls_validation_flags : t -> Gio_enums.tlscertificateflags -> unit
  = "ml_g_socket_client_set_tls_validation_flags"
(** Sets the TLS validation flags used when creating TLS connections
via @client. The default value is %G_TLS_CERTIFICATE_VALIDATE_ALL.

This function does not work as originally designed and is impossible
to use correctly. See #GSocketClient:tls-validation-flags for more
information. *)

external set_tls : t -> bool -> unit = "ml_g_socket_client_set_tls"
(** Sets whether @client creates TLS (aka SSL) connections. If @tls is
%TRUE, @client will wrap its connections in a #GTlsClientConnection
and perform a TLS handshake when connecting.

Note that since #GSocketClient must return a #GSocketConnection,
but #GTlsClientConnection is not a #GSocketConnection, this
actually wraps the resulting #GTlsClientConnection in a
#GTcpWrapperConnection when returning it. You can use
g_tcp_wrapper_connection_get_base_io_stream() on the return value
to extract the #GTlsClientConnection.

If you need to modify the behavior of the TLS handshake (eg, by
setting a client-side certificate to use, or connecting to the
#GTlsConnection::accept-certificate signal), you can connect to
@client's #GSocketClient::event signal and wait for it to be
emitted with %G_SOCKET_CLIENT_TLS_HANDSHAKING, which will give you
a chance to see the #GTlsClientConnection before the handshake
starts. *)

external set_timeout : t -> int -> unit = "ml_g_socket_client_set_timeout"
(** Sets the I/O timeout for sockets created by @client. @timeout is a
time in seconds, or 0 for no timeout (the default).

The timeout value affects the initial connection attempt as well,
so setting this may cause calls to g_socket_client_connect(), etc,
to fail with %G_IO_ERROR_TIMED_OUT. *)

external set_socket_type : t -> Gio_enums.sockettype -> unit
  = "ml_g_socket_client_set_socket_type"
(** Sets the socket type of the socket client. The sockets created by this
    object will be of the specified type.

    It doesn't make sense to specify a type of %G_SOCKET_TYPE_DATAGRAM, as
    GSocketClient is used for connection oriented services. *)

external set_proxy_resolver : t -> Proxy_resolver.t option -> unit
  = "ml_g_socket_client_set_proxy_resolver"
(** Overrides the #GProxyResolver used by @client. You can call this if
you want to use specific proxies, rather than using the system
default proxy settings.

Note that whether or not the proxy resolver is actually used
depends on the setting of #GSocketClient:enable-proxy, which is not
changed by this function (but which is %TRUE by default) *)

external set_protocol : t -> Gio_enums.socketprotocol -> unit
  = "ml_g_socket_client_set_protocol"
(** Sets the protocol of the socket client.
The sockets created by this object will use of the specified
protocol.

If @protocol is %G_SOCKET_PROTOCOL_DEFAULT that means to use the default
protocol for the socket family and type. *)

external set_local_address :
  t ->
  Socket_address_and__socket_address_enumerator_and__socket_connectable
  .Socket_address
  .t
  option ->
  unit = "ml_g_socket_client_set_local_address"
(** Sets the local address of the socket client. The sockets created by this
    object will bound to the specified address (if not %NULL) before connecting.

    This is useful if you want to ensure that the local side of the connection
    is on a specific port, or on a specific interface. *)

external set_family : t -> Gio_enums.socketfamily -> unit
  = "ml_g_socket_client_set_family"
(** Sets the socket family of the socket client. If this is set to something
    other than %G_SOCKET_FAMILY_INVALID then the sockets created by this object
    will be of the specified family.

    This might be useful for instance if you want to force the local connection
    to be an ipv4 socket, even though the address might be an ipv6 mapped to
    ipv4 address. *)

external set_enable_proxy : t -> bool -> unit
  = "ml_g_socket_client_set_enable_proxy"
(** Sets whether or not @client attempts to make connections via a
proxy server. When enabled (the default), #GSocketClient will use a
#GProxyResolver to determine if a proxy protocol such as SOCKS is
needed, and automatically do the necessary proxy negotiation.

See also g_socket_client_set_proxy_resolver(). *)

external get_tls_validation_flags : t -> Gio_enums.tlscertificateflags
  = "ml_g_socket_client_get_tls_validation_flags"
(** Gets the TLS validation flags used creating TLS connections via
@client.

This function does not work as originally designed and is impossible
to use correctly. See #GSocketClient:tls-validation-flags for more
information. *)

external get_tls : t -> bool = "ml_g_socket_client_get_tls"
(** Gets whether @client creates TLS connections. See
g_socket_client_set_tls() for details. *)

external get_timeout : t -> int = "ml_g_socket_client_get_timeout"
(** Gets the I/O timeout time for sockets created by @client.

See g_socket_client_set_timeout() for details. *)

external get_socket_type : t -> Gio_enums.sockettype
  = "ml_g_socket_client_get_socket_type"
(** Gets the socket type of the socket client.

    See g_socket_client_set_socket_type() for details. *)

external get_proxy_resolver : t -> Proxy_resolver.t
  = "ml_g_socket_client_get_proxy_resolver"
(** Gets the #GProxyResolver being used by @client. Normally, this will
be the resolver returned by g_proxy_resolver_get_default(), but you
can override it with g_socket_client_set_proxy_resolver(). *)

external get_protocol : t -> Gio_enums.socketprotocol
  = "ml_g_socket_client_get_protocol"
(** Gets the protocol name type of the socket client.

    See g_socket_client_set_protocol() for details. *)

external get_local_address :
  t ->
  Socket_address_and__socket_address_enumerator_and__socket_connectable
  .Socket_address
  .t
  option = "ml_g_socket_client_get_local_address"
(** Gets the local address of the socket client.

    See g_socket_client_set_local_address() for details. *)

external get_family : t -> Gio_enums.socketfamily
  = "ml_g_socket_client_get_family"
(** Gets the socket family of the socket client.

    See g_socket_client_set_family() for details. *)

external get_enable_proxy : t -> bool = "ml_g_socket_client_get_enable_proxy"
(** Gets the proxy enable state; see g_socket_client_set_enable_proxy() *)

external connect_to_uri_finish :
  t ->
  Async_result.t ->
  (Socket_and__socket_connection.Socket_connection.t, GError.t) result
  = "ml_g_socket_client_connect_to_uri_finish"
(** Finishes an async connect operation. See
    g_socket_client_connect_to_uri_async() *)

external connect_to_uri :
  t ->
  string ->
  UInt16.t ->
  Cancellable.t option ->
  (Socket_and__socket_connection.Socket_connection.t, GError.t) result
  = "ml_g_socket_client_connect_to_uri"
(** This is a helper function for g_socket_client_connect().

Attempts to create a TCP connection with a network URI.

@uri may be any valid URI containing an "authority" (hostname/port)
component. If a port is not specified in the URI, @default_port
will be used. TLS will be negotiated if #GSocketClient:tls is %TRUE.
(#GSocketClient does not know to automatically assume TLS for
certain URI schemes.)

Using this rather than g_socket_client_connect() or
g_socket_client_connect_to_host() allows #GSocketClient to
determine when to use application-specific proxy protocols.

Upon a successful connection, a new #GSocketConnection is constructed
and returned.  The caller owns this new object and must drop their
reference to it when finished with it.

In the event of any failure (DNS error, service not found, no hosts
connectable) %NULL is returned and @error (if non-%NULL) is set
accordingly. *)

external connect_to_service_finish :
  t ->
  Async_result.t ->
  (Socket_and__socket_connection.Socket_connection.t, GError.t) result
  = "ml_g_socket_client_connect_to_service_finish"
(** Finishes an async connect operation. See
    g_socket_client_connect_to_service_async() *)

external connect_to_service :
  t ->
  string ->
  string ->
  Cancellable.t option ->
  (Socket_and__socket_connection.Socket_connection.t, GError.t) result
  = "ml_g_socket_client_connect_to_service"
(** Attempts to create a TCP connection to a service.

This call looks up the SRV record for @service at @domain for the
"tcp" protocol.  It then attempts to connect, in turn, to each of
the hosts providing the service until either a connection succeeds
or there are no hosts remaining.

Upon a successful connection, a new #GSocketConnection is constructed
and returned.  The caller owns this new object and must drop their
reference to it when finished with it.

In the event of any failure (DNS error, service not found, no hosts
connectable) %NULL is returned and @error (if non-%NULL) is set
accordingly. *)

external connect_to_host_finish :
  t ->
  Async_result.t ->
  (Socket_and__socket_connection.Socket_connection.t, GError.t) result
  = "ml_g_socket_client_connect_to_host_finish"
(** Finishes an async connect operation. See
    g_socket_client_connect_to_host_async() *)

external connect_to_host :
  t ->
  string ->
  UInt16.t ->
  Cancellable.t option ->
  (Socket_and__socket_connection.Socket_connection.t, GError.t) result
  = "ml_g_socket_client_connect_to_host"
(** This is a helper function for g_socket_client_connect().

Attempts to create a TCP connection to the named host.

@host_and_port may be in any of a number of recognized formats; an IPv6
address, an IPv4 address, or a domain name (in which case a DNS
lookup is performed).  Quoting with [] is supported for all address
types.  A port override may be specified in the usual way with a
colon.  Ports may be given as decimal numbers or symbolic names (in
which case an /etc/services lookup is performed).

If no port override is given in @host_and_port then @default_port will be
used as the port number to connect to.

In general, @host_and_port is expected to be provided by the user (allowing
them to give the hostname, and a port override if necessary) and
@default_port is expected to be provided by the application.

In the case that an IP address is given, a single connection
attempt is made.  In the case that a name is given, multiple
connection attempts may be made, in turn and according to the
number of address records in DNS, until a connection succeeds.

Upon a successful connection, a new #GSocketConnection is constructed
and returned.  The caller owns this new object and must drop their
reference to it when finished with it.

In the event of any failure (DNS error, service not found, no hosts
connectable) %NULL is returned and @error (if non-%NULL) is set
accordingly. *)

external connect_finish :
  t ->
  Async_result.t ->
  (Socket_and__socket_connection.Socket_connection.t, GError.t) result
  = "ml_g_socket_client_connect_finish"
(** Finishes an async connect operation. See g_socket_client_connect_async() *)

external connect :
  t ->
  Socket_address_and__socket_address_enumerator_and__socket_connectable
  .Socket_connectable
  .t ->
  Cancellable.t option ->
  (Socket_and__socket_connection.Socket_connection.t, GError.t) result
  = "ml_g_socket_client_connect"
(** Tries to resolve the @connectable and make a network connection to it.

Upon a successful connection, a new #GSocketConnection is constructed
and returned.  The caller owns this new object and must drop their
reference to it when finished with it.

The type of the #GSocketConnection object returned depends on the type of
the underlying socket that is used. For instance, for a TCP/IP connection
it will be a #GTcpConnection.

The socket created will be the same family as the address that the
@connectable resolves to, unless family is set with g_socket_client_set_family()
or indirectly via g_socket_client_set_local_address(). The socket type
defaults to %G_SOCKET_TYPE_STREAM but can be set with
g_socket_client_set_socket_type().

If a local address is specified with g_socket_client_set_local_address() the
socket will be bound to this address before connecting. *)

external add_application_proxy : t -> string -> unit
  = "ml_g_socket_client_add_application_proxy"
(** Enable proxy protocols to be handled by the application. When the indicated
    proxy protocol is returned by the #GProxyResolver, #GSocketClient will
    consider this protocol as supported but will not try to find a #GProxy
    instance to handle handshaking. The application must check for this case by
    calling g_socket_connection_get_remote_address() on the returned
    #GSocketConnection, and seeing if it's a #GProxyAddress of the appropriate
    type, to determine whether or not it needs to handle the proxy handshaking
    itself.

    This should be used for proxy protocols that are dialects of another
    protocol such as HTTP proxy. It also allows cohabitation of proxy protocols
    that are reused between protocols. A good example is HTTP. It can be used to
    proxy HTTP, FTP and Gopher and can also be use as generic socket proxy
    through the HTTP CONNECT method.

    When the proxy is detected as being an application proxy, TLS handshake will
    be skipped. This is required to let the application do the proxy specific
    handshake. *)

(* Properties *)

external get_type : t -> Gio_enums.sockettype = "ml_g_socket_client_get_type"
(** Get property: type *)

external set_type : t -> Gio_enums.sockettype -> unit
  = "ml_g_socket_client_set_type"
(** Set property: type *)

val on_event :
  ?after:bool ->
  t ->
  callback:
    (event:Gio_enums.socketclientevent ->
    connectable:
      Socket_address_and__socket_address_enumerator_and__socket_connectable
      .Socket_connectable
      .t ->
    connection:Io_stream.t option ->
    unit) ->
  Gobject.Signal.handler_id
