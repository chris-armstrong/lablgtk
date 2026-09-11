(* GENERATED CODE - DO NOT EDIT *)
(* SocketListener: SocketListener *)

type t = [ `socket_listener | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_socket_listener_get_type"

external new_ : unit -> t = "ml_g_socket_listener_new"
(** Create a new SocketListener *)

(* Methods *)

external set_backlog : t -> int -> unit = "ml_g_socket_listener_set_backlog"
(** Sets the listen backlog on the sockets in the listener. This must be called
    before adding any sockets, addresses or ports to the #GSocketListener (for
    example, by calling g_socket_listener_add_inet_port()) to be effective.

    See g_socket_set_listen_backlog() for details *)

external close : t -> unit = "ml_g_socket_listener_close"
(** Closes all the sockets in the listener. *)

external add_socket :
  t ->
  Socket_and__socket_connection.Socket.t ->
  [ `object_ ] Gobject.obj option ->
  (bool, GError.t) result = "ml_g_socket_listener_add_socket"
(** Adds @socket to the set of sockets that we try to accept
new clients from. The socket must be bound to a local
address and listened to.

For parallel calls to [class@Gio.SocketListener] methods to work, the socket
must be in non-blocking mode. (See [property@Gio.Socket:blocking].)

@source_object will be passed out in the various calls
to accept to identify this particular source, which is
useful if you're listening on multiple addresses and do
different things depending on what address is connected to.

The @socket will not be automatically closed when the @listener is finalized
unless the listener held the final reference to the socket. Before GLib 2.42,
the @socket was automatically closed on finalization of the @listener, even
if references to it were held elsewhere. *)

external add_inet_port :
  t -> UInt16.t -> [ `object_ ] Gobject.obj option -> (bool, GError.t) result
  = "ml_g_socket_listener_add_inet_port"
(** Helper function for g_socket_listener_add_address() that
creates a TCP/IP socket listening on IPv4 and IPv6 (if
supported) on the specified port on all interfaces.

If possible, the [class@Gio.SocketListener] will listen on both IPv4 and
IPv6 (listening on the same port on both). If listening on one of the socket
families fails, the [class@Gio.SocketListener] will only listen on the other.
If listening on both fails, an error will be returned.

If you need to distinguish whether listening on IPv4 or IPv6 or both was
successful, connect to [signal@Gio.SocketListener::event].

@source_object will be passed out in the various calls
to accept to identify this particular source, which is
useful if you're listening on multiple addresses and do
different things depending on what address is connected to.

Call g_socket_listener_close() to stop listening on @port; this will not
be done automatically when you drop your final reference to @listener, as
references may be held internally. *)

external add_any_inet_port :
  t -> [ `object_ ] Gobject.obj option -> (UInt16.t, GError.t) result
  = "ml_g_socket_listener_add_any_inet_port"
(** Listens for TCP connections on any available port number for both
IPv6 and IPv4 (if each is available).

This is useful if you need to have a socket for incoming connections
but don't care about the specific port number.

If possible, the [class@Gio.SocketListener] will listen on both IPv4 and
IPv6 (listening on the same port on both). If listening on one of the socket
families fails, the [class@Gio.SocketListener] will only listen on the other.
If listening on both fails, an error will be returned.

If you need to distinguish whether listening on IPv4 or IPv6 or both was
successful, connect to [signal@Gio.SocketListener::event].

@source_object will be passed out in the various calls
to accept to identify this particular source, which is
useful if you're listening on multiple addresses and do
different things depending on what address is connected to. *)

(* Properties *)

external get_listen_backlog : t -> int
  = "ml_g_socket_listener_get_listen_backlog"
(** Get property: listen-backlog *)

external set_listen_backlog : t -> int -> unit
  = "ml_g_socket_listener_set_listen_backlog"
(** Set property: listen-backlog *)

let on_event ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let event =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gio_enums.socketlistenerevent_of_int (Gobject.Value.get_enum_int v)
        in
        let socket =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_object_exn v
            (Socket_and__socket_connection.Socket.gtype ())
        in
        callback ~event ~socket)
  in
  Gobject.Signal.connect obj ~name:"event" ~callback:closure
    ~after:(Option.value after ~default:false)
