(* GENERATED CODE - DO NOT EDIT *)
(* DtlsConnection: DtlsConnection *)

type t = [ `dtls_connection ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_dtls_connection_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gio_dtls_connection_from_gobject"

(* Methods *)

external shutdown_finish : t -> Async_result.t -> (bool, GError.t) result
  = "ml_g_dtls_connection_shutdown_finish"
(** Finish an asynchronous TLS shutdown operation. See
    g_dtls_connection_shutdown() for more information. *)

external shutdown :
  t -> bool -> bool -> Cancellable.t option -> (bool, GError.t) result
  = "ml_g_dtls_connection_shutdown"
(** Shut down part or all of a DTLS connection.

If @shutdown_read is %TRUE then the receiving side of the connection is shut
down, and further reading is disallowed. Subsequent calls to
g_datagram_based_receive_messages() will return %G_IO_ERROR_CLOSED.

If @shutdown_write is %TRUE then the sending side of the connection is shut
down, and further writing is disallowed. Subsequent calls to
g_datagram_based_send_messages() will return %G_IO_ERROR_CLOSED.

It is allowed for both @shutdown_read and @shutdown_write to be TRUE — this
is equivalent to calling g_dtls_connection_close().

If @cancellable is cancelled, the #GDtlsConnection may be left
partially-closed and any pending untransmitted data may be lost. Call
g_dtls_connection_shutdown() again to complete closing the #GDtlsConnection. *)

external set_require_close_notify : t -> bool -> unit
  = "ml_g_dtls_connection_set_require_close_notify"
(** Sets whether or not @conn expects a proper TLS close notification
before the connection is closed. If this is %TRUE (the default),
then @conn will expect to receive a TLS close notification from its
peer before the connection is closed, and will return a
%G_TLS_ERROR_EOF error if the connection is closed without proper
notification (since this may indicate a network error, or
man-in-the-middle attack).

In some protocols, the application will know whether or not the
connection was closed cleanly based on application-level data
(because the application-level data includes a length field, or is
somehow self-delimiting); in this case, the close notify is
redundant and may be omitted. You
can use g_dtls_connection_set_require_close_notify() to tell @conn
to allow an "unannounced" connection close, in which case the close
will show up as a 0-length read, as in a non-TLS
#GDatagramBased, and it is up to the application to check that
the data has been fully received.

Note that this only affects the behavior when the peer closes the
connection; when the application calls g_dtls_connection_close_async() on
@conn itself, this will send a close notification regardless of the
setting of this property. If you explicitly want to do an unclean
close, you can close @conn's #GDtlsConnection:base-socket rather
than closing @conn itself. *)

external set_rehandshake_mode : t -> Gio_enums.tlsrehandshakemode -> unit
  = "ml_g_dtls_connection_set_rehandshake_mode"
(** Since GLib 2.64, changing the rehandshake mode is no longer supported and
    will have no effect. With TLS 1.3, rehandshaking has been removed from the
    TLS protocol, replaced by separate post-handshake authentication and rekey
    operations. *)

external set_interaction :
  t ->
  Tls_connection_and__tls_database_and__tls_interaction.Tls_interaction.t option ->
  unit = "ml_g_dtls_connection_set_interaction"
(** Set the object that will be used to interact with the user. It will be used
for things like prompting the user for passwords.

The @interaction argument will normally be a derived subclass of
#GTlsInteraction. %NULL can also be provided if no user interaction
should occur for this connection. *)

external set_database :
  t ->
  Tls_connection_and__tls_database_and__tls_interaction.Tls_database.t option ->
  unit = "ml_g_dtls_connection_set_database"
(** Sets the certificate database that is used to verify peer certificates. This
    is set to the default database by default. See
    g_tls_backend_get_default_database(). If set to %NULL, then peer certificate
    validation will always set the %G_TLS_CERTIFICATE_UNKNOWN_CA error (meaning
    #GDtlsConnection::accept-certificate will always be emitted on client-side
    connections, unless that bit is not set in
    #GDtlsClientConnection:validation-flags).

    There are nonintuitive security implications when using a non-default
    database. See #GDtlsConnection:database for details. *)

external set_certificate : t -> Tls_certificate.t -> unit
  = "ml_g_dtls_connection_set_certificate"
(** This sets the certificate that @conn will present to its peer
during the TLS handshake. For a #GDtlsServerConnection, it is
mandatory to set this, and that will normally be done at construct
time.

For a #GDtlsClientConnection, this is optional. If a handshake fails
with %G_TLS_ERROR_CERTIFICATE_REQUIRED, that means that the server
requires a certificate, and if you try connecting again, you should
call this method first. You can call
g_dtls_client_connection_get_accepted_cas() on the failed connection
to get a list of Certificate Authorities that the server will
accept certificates from.

(It is also possible that a server will allow the connection with
or without a certificate; in that case, if you don't provide a
certificate, you can tell that the server requested one by the fact
that g_dtls_client_connection_get_accepted_cas() will return
non-%NULL.) *)

external set_advertised_protocols : t -> string array option -> unit
  = "ml_g_dtls_connection_set_advertised_protocols"
(** Sets the list of application-layer protocols to advertise that the
caller is willing to speak on this connection. The
Application-Layer Protocol Negotiation (ALPN) extension will be
used to negotiate a compatible protocol with the peer; use
g_dtls_connection_get_negotiated_protocol() to find the negotiated
protocol after the handshake.  Specifying %NULL for the the value
of @protocols will disable ALPN negotiation.

See [IANA TLS ALPN Protocol IDs](https://www.iana.org/assignments/tls-extensiontype-values/tls-extensiontype-values.xhtml#alpn-protocol-ids)
for a list of registered protocol IDs. *)

external handshake_finish : t -> Async_result.t -> (bool, GError.t) result
  = "ml_g_dtls_connection_handshake_finish"
(** Finish an asynchronous TLS handshake operation. See
    g_dtls_connection_handshake() for more information. *)

external handshake : t -> Cancellable.t option -> (bool, GError.t) result
  = "ml_g_dtls_connection_handshake"
(** Attempts a TLS handshake on @conn.

On the client side, it is never necessary to call this method;
although the connection needs to perform a handshake after
connecting, #GDtlsConnection will handle this for you automatically
when you try to send or receive data on the connection. You can call
g_dtls_connection_handshake() manually if you want to know whether
the initial handshake succeeded or failed (as opposed to just
immediately trying to use @conn to read or write, in which case,
if it fails, it may not be possible to tell if it failed before
or after completing the handshake), but beware that servers may reject
client authentication after the handshake has completed, so a
successful handshake does not indicate the connection will be usable.

Likewise, on the server side, although a handshake is necessary at
the beginning of the communication, you do not need to call this
function explicitly unless you want clearer error reporting.

Previously, calling g_dtls_connection_handshake() after the initial
handshake would trigger a rehandshake; however, this usage was
deprecated in GLib 2.60 because rehandshaking was removed from the
TLS protocol in TLS 1.3. Since GLib 2.64, calling this function after
the initial handshake will no longer do anything.

#GDtlsConnection::accept_certificate may be emitted during the
handshake. *)

external get_require_close_notify : t -> bool
  = "ml_g_dtls_connection_get_require_close_notify"
(** Tests whether or not @conn expects a proper TLS close notification
when the connection is closed. See
g_dtls_connection_set_require_close_notify() for details. *)

external get_rehandshake_mode : t -> Gio_enums.tlsrehandshakemode
  = "ml_g_dtls_connection_get_rehandshake_mode"
(** Gets @conn rehandshaking mode. See
g_dtls_connection_set_rehandshake_mode() for details. *)

external get_protocol_version : t -> Gio_enums.tlsprotocolversion
  = "ml_g_dtls_connection_get_protocol_version"
(** Returns the current DTLS protocol version, which may be
    %G_TLS_PROTOCOL_VERSION_UNKNOWN if the connection has not handshaked, or has
    been closed, or if the TLS backend has implemented a protocol version that
    is not a recognized #GTlsProtocolVersion. *)

external get_peer_certificate_errors : t -> Gio_enums.tlscertificateflags
  = "ml_g_dtls_connection_get_peer_certificate_errors"
(** Gets the errors associated with validating @conn's peer's
certificate, after the handshake has completed or failed. (It is
not set during the emission of #GDtlsConnection::accept-certificate.) *)

external get_peer_certificate : t -> Tls_certificate.t option
  = "ml_g_dtls_connection_get_peer_certificate"
(** Gets @conn's peer's certificate after the handshake has completed
or failed. (It is not set during the emission of
#GDtlsConnection::accept-certificate.) *)

external get_negotiated_protocol : t -> string option
  = "ml_g_dtls_connection_get_negotiated_protocol"
(** Gets the name of the application-layer protocol negotiated during
the handshake.

If the peer did not use the ALPN extension, or did not advertise a
protocol that matched one of @conn's protocols, or the TLS backend
does not support ALPN, then this will be %NULL. See
g_dtls_connection_set_advertised_protocols(). *)

external get_interaction :
  t ->
  Tls_connection_and__tls_database_and__tls_interaction.Tls_interaction.t option
  = "ml_g_dtls_connection_get_interaction"
(** Get the object that will be used to interact with the user. It will be used
    for things like prompting the user for passwords. If %NULL is returned, then
    no user interaction will occur for this connection. *)

external get_database :
  t ->
  Tls_connection_and__tls_database_and__tls_interaction.Tls_database.t option
  = "ml_g_dtls_connection_get_database"
(** Gets the certificate database that @conn uses to verify
peer certificates. See g_dtls_connection_set_database(). *)

external get_ciphersuite_name : t -> string option
  = "ml_g_dtls_connection_get_ciphersuite_name"
(** Returns the name of the current DTLS ciphersuite, or %NULL if the connection
    has not handshaked or has been closed. Beware that the TLS backend may use
    any of multiple different naming conventions, because OpenSSL and GnuTLS
    have their own ciphersuite naming conventions that are different from each
    other and different from the standard, IANA- registered ciphersuite names.
    The ciphersuite name is intended to be displayed to the user for informative
    purposes only, and parsing it is not recommended. *)

external get_certificate : t -> Tls_certificate.t option
  = "ml_g_dtls_connection_get_certificate"
(** Gets @conn's certificate, as set by
g_dtls_connection_set_certificate(). *)

external emit_accept_certificate :
  t -> Tls_certificate.t -> Gio_enums.tlscertificateflags -> bool
  = "ml_g_dtls_connection_emit_accept_certificate"
(** Used by #GDtlsConnection implementations to emit the
    #GDtlsConnection::accept-certificate signal. *)

external close_finish : t -> Async_result.t -> (bool, GError.t) result
  = "ml_g_dtls_connection_close_finish"
(** Finish an asynchronous TLS close operation. See g_dtls_connection_close()
    for more information. *)

external close : t -> Cancellable.t option -> (bool, GError.t) result
  = "ml_g_dtls_connection_close"
(** Close the DTLS connection. This is equivalent to calling
g_dtls_connection_shutdown() to shut down both sides of the connection.

Closing a #GDtlsConnection waits for all buffered but untransmitted data to
be sent before it completes. It then sends a `close_notify` DTLS alert to the
peer and may wait for a `close_notify` to be received from the peer. It does
not close the underlying #GDtlsConnection:base-socket; that must be closed
separately.

Once @conn is closed, all other operations will return %G_IO_ERROR_CLOSED.
Closing a #GDtlsConnection multiple times will not return an error.

#GDtlsConnections will be automatically closed when the last reference is
dropped, but you might want to call this function to make sure resources are
released as early as possible.

If @cancellable is cancelled, the #GDtlsConnection may be left
partially-closed and any pending untransmitted data may be lost. Call
g_dtls_connection_close() again to complete closing the #GDtlsConnection. *)

(* Properties *)

external get_base_socket : t -> Datagram_based.t
  = "ml_g_dtls_connection_get_base_socket"
(** Get property: base-socket *)

let on_accept_certificate ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let peer_cert =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v (Tls_certificate.gtype ())
        in
        let errors =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gio_enums.tlscertificateflags_of_int (Gobject.Value.get_flags_int v)
        in
        let result = callback ~peer_cert ~errors in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"accept-certificate" ~callback:closure
    ~after:(Option.value after ~default:false)
