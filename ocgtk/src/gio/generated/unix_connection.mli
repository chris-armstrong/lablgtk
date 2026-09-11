(* GENERATED CODE - DO NOT EDIT *)
(* UnixConnection: UnixConnection *)

type t =
  [ `unix_connection | `socket_connection | `io_stream | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_unix_connection_get_type"

(* Methods *)

external send_fd : t -> int -> Cancellable.t option -> (bool, GError.t) result
  = "ml_g_unix_connection_send_fd"
(** Passes a file descriptor to the receiving side of the connection. The
    receiving end has to call g_unix_connection_receive_fd() to accept the file
    descriptor.

    As well as sending the fd this also writes a single byte to the stream, as
    this is required for fd passing to work on some implementations. *)

external send_credentials_finish :
  t -> Async_result.t -> (bool, GError.t) result
  = "ml_g_unix_connection_send_credentials_finish"
(** Finishes an asynchronous send credentials operation started with
    g_unix_connection_send_credentials_async(). *)

external send_credentials : t -> Cancellable.t option -> (bool, GError.t) result
  = "ml_g_unix_connection_send_credentials"
(** Passes the credentials of the current user the receiving side of the
    connection. The receiving end has to call
    g_unix_connection_receive_credentials() (or similar) to accept the
    credentials.

    As well as sending the credentials this also writes a single NUL byte to the
    stream, as this is required for credentials passing to work on some
    implementations.

    This method can be expected to be available on the following platforms:

    - Linux since GLib 2.26
    - FreeBSD since GLib 2.26
    - GNU/kFreeBSD since GLib 2.36
    - Solaris, Illumos and OpenSolaris since GLib 2.40
    - GNU/Hurd since GLib 2.40

    Other ways to exchange credentials with a foreign peer includes the
    #GUnixCredentialsMessage type and g_socket_get_credentials() function. *)

external receive_fd : t -> Cancellable.t option -> (int, GError.t) result
  = "ml_g_unix_connection_receive_fd"
(** Receives a file descriptor from the sending end of the connection. The
    sending end has to call g_unix_connection_send_fd() for this to work.

    As well as reading the fd this also reads a single byte from the stream, as
    this is required for fd passing to work on some implementations. *)

external receive_credentials_finish :
  t -> Async_result.t -> (Credentials.t, GError.t) result
  = "ml_g_unix_connection_receive_credentials_finish"
(** Finishes an asynchronous receive credentials operation started with
    g_unix_connection_receive_credentials_async(). *)

external receive_credentials :
  t -> Cancellable.t option -> (Credentials.t, GError.t) result
  = "ml_g_unix_connection_receive_credentials"
(** Receives credentials from the sending end of the connection. The sending end
    has to call g_unix_connection_send_credentials() (or similar) for this to
    work.

    As well as reading the credentials this also reads (and discards) a single
    byte from the stream, as this is required for credentials passing to work on
    some implementations.

    This method can be expected to be available on the following platforms:

    - Linux since GLib 2.26
    - FreeBSD since GLib 2.26
    - GNU/kFreeBSD since GLib 2.36
    - Solaris, Illumos and OpenSolaris since GLib 2.40
    - GNU/Hurd since GLib 2.40

    Other ways to exchange credentials with a foreign peer includes the
    #GUnixCredentialsMessage type and g_socket_get_credentials() function. *)
