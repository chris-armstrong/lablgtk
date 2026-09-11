(* GENERATED CODE - DO NOT EDIT *)
(* TcpConnection: TcpConnection *)

type t =
  [ `tcp_connection | `socket_connection | `io_stream | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_tcp_connection_get_type"

(* Methods *)

external set_graceful_disconnect : t -> bool -> unit
  = "ml_g_tcp_connection_set_graceful_disconnect"
(** This enables graceful disconnects on close. A graceful disconnect means that
    we signal the receiving end that the connection is terminated and wait for
    it to close the connection before closing the connection.

    A graceful disconnect means that we can be sure that we successfully sent
    all the outstanding data to the other end, or get an error reported.
    However, it also means we have to wait for all the data to reach the other
    side and for it to acknowledge this by closing the socket, which may take a
    while. For this reason it is disabled by default. *)

external get_graceful_disconnect : t -> bool
  = "ml_g_tcp_connection_get_graceful_disconnect"
(** Checks if graceful disconnects are used. See
    g_tcp_connection_set_graceful_disconnect(). *)

(* Properties *)
