(* GENERATED CODE - DO NOT EDIT *)
(* TlsClientConnection: TlsClientConnection *)

type t = [ `tls_client_connection ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gio_tls_client_connection_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gio_tls_client_connection_from_gobject"

(* Methods *)

external set_validation_flags : t -> Gio_enums.tlscertificateflags -> unit
  = "ml_g_tls_client_connection_set_validation_flags"
(** Sets @conn's validation flags, to override the default set of
checks performed when validating a server certificate. By default,
%G_TLS_CERTIFICATE_VALIDATE_ALL is used.

This function does not work as originally designed and is impossible
to use correctly. See #GTlsClientConnection:validation-flags for more
information. *)

external set_use_ssl3 : t -> bool -> unit
  = "ml_g_tls_client_connection_set_use_ssl3"
(** Since GLib 2.42.1, SSL 3.0 is no longer supported.

    From GLib 2.42.1 through GLib 2.62, this function could be used to force use
    of TLS 1.0, the lowest-supported TLS protocol version at the time. In the
    past, this was needed to connect to broken TLS servers that exhibited
    protocol version intolerance. Such servers are no longer common, and using
    TLS 1.0 is no longer considered acceptable.

    Since GLib 2.64, this function does nothing. *)

external set_server_identity :
  t ->
  Socket_address_and__socket_address_enumerator_and__socket_connectable
  .Socket_connectable
  .t ->
  unit = "ml_g_tls_client_connection_set_server_identity"
(** Sets @conn's expected server identity, which is used both to tell
servers on virtual hosts which certificate to present, and also
to let @conn know what name to look for in the certificate when
performing %G_TLS_CERTIFICATE_BAD_IDENTITY validation, if enabled. *)

external get_validation_flags : t -> Gio_enums.tlscertificateflags
  = "ml_g_tls_client_connection_get_validation_flags"
(** Gets @conn's validation flags

This function does not work as originally designed and is impossible
to use correctly. See #GTlsClientConnection:validation-flags for more
information. *)

external get_use_ssl3 : t -> bool = "ml_g_tls_client_connection_get_use_ssl3"
(** SSL 3.0 is no longer supported. See g_tls_client_connection_set_use_ssl3()
    for details. *)

external get_server_identity :
  t ->
  Socket_address_and__socket_address_enumerator_and__socket_connectable
  .Socket_connectable
  .t
  option = "ml_g_tls_client_connection_get_server_identity"
(** Gets @conn's expected server identity *)

external copy_session_state : t -> t -> unit
  = "ml_g_tls_client_connection_copy_session_state"
(** Possibly copies session state from one connection to another, for use
in TLS session resumption. This is not normally needed, but may be
used when the same session needs to be used between different
endpoints, as is required by some protocols, such as FTP over TLS.
@source should have already completed a handshake and, since TLS 1.3,
it should have been used to read data at least once. @conn should not
have completed a handshake.

It is not possible to know whether a call to this function will
actually do anything. Because session resumption is normally used
only for performance benefit, the TLS backend might not implement
this function. Even if implemented, it may not actually succeed in
allowing @conn to resume @source's TLS session, because the server
may not have sent a session resumption token to @source, or it may
refuse to accept the token from @conn. There is no way to know
whether a call to this function is actually successful.

Using this function is not required to benefit from session
resumption. If the TLS backend supports session resumption, the
session will be resumed automatically if it is possible to do so
without weakening the privacy guarantees normally provided by TLS,
without need to call this function. For example, with TLS 1.3,
a session ticket will be automatically copied from any
#GTlsClientConnection that has previously received session tickets
from the server, provided a ticket is available that has not
previously been used for session resumption, since session ticket
reuse would be a privacy weakness. Using this function causes the
ticket to be copied without regard for privacy considerations. *)

(* Properties *)
