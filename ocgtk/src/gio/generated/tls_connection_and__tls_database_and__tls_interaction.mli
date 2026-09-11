(* GENERATED CODE - DO NOT EDIT *)
(* Combined modules for cyclic dependencies *)

module rec Tls_connection : sig
  type t = [ `tls_connection | `io_stream | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gio_tls_connection_get_type"

  (* Methods *)

  external set_use_system_certdb : t -> bool -> unit
    = "ml_g_tls_connection_set_use_system_certdb"
  (** Sets whether @conn uses the system certificate database to verify
  peer certificates. This is %TRUE by default. If set to %FALSE, then
  peer certificate validation will always set the
  %G_TLS_CERTIFICATE_UNKNOWN_CA error (meaning
  #GTlsConnection::accept-certificate will always be emitted on
  client-side connections, unless that bit is not set in
  #GTlsClientConnection:validation-flags). *)

  external set_require_close_notify : t -> bool -> unit
    = "ml_g_tls_connection_set_require_close_notify"
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
  redundant and sometimes omitted. (TLS 1.1 explicitly allows this;
  in TLS 1.0 it is technically an error, but often done anyway.) You
  can use g_tls_connection_set_require_close_notify() to tell @conn
  to allow an "unannounced" connection close, in which case the close
  will show up as a 0-length read, as in a non-TLS
  #GSocketConnection, and it is up to the application to check that
  the data has been fully received.

  Note that this only affects the behavior when the peer closes the
  connection; when the application calls g_io_stream_close() itself
  on @conn, this will send a close notification regardless of the
  setting of this property. If you explicitly want to do an unclean
  close, you can close @conn's #GTlsConnection:base-io-stream rather
  than closing @conn itself, but note that this may only be done when no other
  operations are pending on @conn or the base I/O stream. *)

  external set_rehandshake_mode : t -> Gio_enums.tlsrehandshakemode -> unit
    = "ml_g_tls_connection_set_rehandshake_mode"
  (** Since GLib 2.64, changing the rehandshake mode is no longer supported and
      will have no effect. With TLS 1.3, rehandshaking has been removed from the
      TLS protocol, replaced by separate post-handshake authentication and rekey
      operations. *)

  external set_interaction : t -> Tls_interaction.t option -> unit
    = "ml_g_tls_connection_set_interaction"
  (** Set the object that will be used to interact with the user. It will be used
  for things like prompting the user for passwords.

  The @interaction argument will normally be a derived subclass of
  #GTlsInteraction. %NULL can also be provided if no user interaction
  should occur for this connection. *)

  external set_database : t -> Tls_database.t option -> unit
    = "ml_g_tls_connection_set_database"
  (** Sets the certificate database that is used to verify peer certificates.
      This is set to the default database by default. See
      g_tls_backend_get_default_database(). If set to %NULL, then peer
      certificate validation will always set the %G_TLS_CERTIFICATE_UNKNOWN_CA
      error (meaning #GTlsConnection::accept-certificate will always be emitted
      on client-side connections, unless that bit is not set in
      #GTlsClientConnection:validation-flags).

      There are nonintuitive security implications when using a non-default
      database. See #GTlsConnection:database for details. *)

  external set_certificate : t -> Tls_certificate.t -> unit
    = "ml_g_tls_connection_set_certificate"
  (** This sets the certificate that @conn will present to its peer
  during the TLS handshake. For a #GTlsServerConnection, it is
  mandatory to set this, and that will normally be done at construct
  time.

  For a #GTlsClientConnection, this is optional. If a handshake fails
  with %G_TLS_ERROR_CERTIFICATE_REQUIRED, that means that the server
  requires a certificate, and if you try connecting again, you should
  call this method first. You can call
  g_tls_client_connection_get_accepted_cas() on the failed connection
  to get a list of Certificate Authorities that the server will
  accept certificates from.

  (It is also possible that a server will allow the connection with
  or without a certificate; in that case, if you don't provide a
  certificate, you can tell that the server requested one by the fact
  that g_tls_client_connection_get_accepted_cas() will return
  non-%NULL.) *)

  external set_advertised_protocols : t -> string array option -> unit
    = "ml_g_tls_connection_set_advertised_protocols"
  (** Sets the list of application-layer protocols to advertise that the
  caller is willing to speak on this connection. The
  Application-Layer Protocol Negotiation (ALPN) extension will be
  used to negotiate a compatible protocol with the peer; use
  g_tls_connection_get_negotiated_protocol() to find the negotiated
  protocol after the handshake.  Specifying %NULL for the the value
  of @protocols will disable ALPN negotiation.

  See [IANA TLS ALPN Protocol IDs](https://www.iana.org/assignments/tls-extensiontype-values/tls-extensiontype-values.xhtml#alpn-protocol-ids)
  for a list of registered protocol IDs. *)

  external handshake_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_tls_connection_handshake_finish"
  (** Finish an asynchronous TLS handshake operation. See
      g_tls_connection_handshake() for more information. *)

  external handshake : t -> Cancellable.t option -> (bool, GError.t) result
    = "ml_g_tls_connection_handshake"
  (** Attempts a TLS handshake on @conn.

  On the client side, it is never necessary to call this method;
  although the connection needs to perform a handshake after
  connecting (or after sending a "STARTTLS"-type command),
  #GTlsConnection will handle this for you automatically when you try
  to send or receive data on the connection. You can call
  g_tls_connection_handshake() manually if you want to know whether
  the initial handshake succeeded or failed (as opposed to just
  immediately trying to use @conn to read or write, in which case,
  if it fails, it may not be possible to tell if it failed before or
  after completing the handshake), but beware that servers may reject
  client authentication after the handshake has completed, so a
  successful handshake does not indicate the connection will be usable.

  Likewise, on the server side, although a handshake is necessary at
  the beginning of the communication, you do not need to call this
  function explicitly unless you want clearer error reporting.

  Previously, calling g_tls_connection_handshake() after the initial
  handshake would trigger a rehandshake; however, this usage was
  deprecated in GLib 2.60 because rehandshaking was removed from the
  TLS protocol in TLS 1.3. Since GLib 2.64, calling this function after
  the initial handshake will no longer do anything.

  When using a #GTlsConnection created by #GSocketClient, the
  #GSocketClient performs the initial handshake, so calling this
  function manually is not recommended.

  #GTlsConnection::accept_certificate may be emitted during the
  handshake. *)

  external get_use_system_certdb : t -> bool
    = "ml_g_tls_connection_get_use_system_certdb"
  (** Gets whether @conn uses the system certificate database to verify
  peer certificates. See g_tls_connection_set_use_system_certdb(). *)

  external get_require_close_notify : t -> bool
    = "ml_g_tls_connection_get_require_close_notify"
  (** Tests whether or not @conn expects a proper TLS close notification
  when the connection is closed. See
  g_tls_connection_set_require_close_notify() for details. *)

  external get_rehandshake_mode : t -> Gio_enums.tlsrehandshakemode
    = "ml_g_tls_connection_get_rehandshake_mode"
  (** Gets @conn rehandshaking mode. See
  g_tls_connection_set_rehandshake_mode() for details. *)

  external get_protocol_version : t -> Gio_enums.tlsprotocolversion
    = "ml_g_tls_connection_get_protocol_version"
  (** Returns the current TLS protocol version, which may be
      %G_TLS_PROTOCOL_VERSION_UNKNOWN if the connection has not handshaked, or
      has been closed, or if the TLS backend has implemented a protocol version
      that is not a recognized #GTlsProtocolVersion. *)

  external get_peer_certificate_errors : t -> Gio_enums.tlscertificateflags
    = "ml_g_tls_connection_get_peer_certificate_errors"
  (** Gets the errors associated with validating @conn's peer's
  certificate, after the handshake has completed or failed. (It is
  not set during the emission of #GTlsConnection::accept-certificate.)

  See #GTlsConnection:peer-certificate-errors for more information. *)

  external get_peer_certificate : t -> Tls_certificate.t option
    = "ml_g_tls_connection_get_peer_certificate"
  (** Gets @conn's peer's certificate after the handshake has completed
  or failed. (It is not set during the emission of
  #GTlsConnection::accept-certificate.) *)

  external get_negotiated_protocol : t -> string option
    = "ml_g_tls_connection_get_negotiated_protocol"
  (** Gets the name of the application-layer protocol negotiated during
  the handshake.

  If the peer did not use the ALPN extension, or did not advertise a
  protocol that matched one of @conn's protocols, or the TLS backend
  does not support ALPN, then this will be %NULL. See
  g_tls_connection_set_advertised_protocols(). *)

  external get_interaction : t -> Tls_interaction.t option
    = "ml_g_tls_connection_get_interaction"
  (** Get the object that will be used to interact with the user. It will be
      used for things like prompting the user for passwords. If %NULL is
      returned, then no user interaction will occur for this connection. *)

  external get_database : t -> Tls_database.t option
    = "ml_g_tls_connection_get_database"
  (** Gets the certificate database that @conn uses to verify
  peer certificates. See g_tls_connection_set_database(). *)

  external get_ciphersuite_name : t -> string option
    = "ml_g_tls_connection_get_ciphersuite_name"
  (** Returns the name of the current TLS ciphersuite, or %NULL if the
      connection has not handshaked or has been closed. Beware that the TLS
      backend may use any of multiple different naming conventions, because
      OpenSSL and GnuTLS have their own ciphersuite naming conventions that are
      different from each other and different from the standard, IANA-
      registered ciphersuite names. The ciphersuite name is intended to be
      displayed to the user for informative purposes only, and parsing it is not
      recommended. *)

  external get_certificate : t -> Tls_certificate.t option
    = "ml_g_tls_connection_get_certificate"
  (** Gets @conn's certificate, as set by
  g_tls_connection_set_certificate(). *)

  external emit_accept_certificate :
    t -> Tls_certificate.t -> Gio_enums.tlscertificateflags -> bool
    = "ml_g_tls_connection_emit_accept_certificate"
  (** Used by #GTlsConnection implementations to emit the
      #GTlsConnection::accept-certificate signal. *)

  (* Properties *)

  external get_base_io_stream : t -> Io_stream.t
    = "ml_g_tls_connection_get_base_io_stream"
  (** Get property: base-io-stream *)

  val on_accept_certificate :
    ?after:bool ->
    t ->
    callback:
      (peer_cert:Tls_certificate.t ->
      errors:Gio_enums.tlscertificateflags ->
      bool) ->
    Gobject.Signal.handler_id
end

and Tls_database : sig
  type t = [ `tls_database | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gio_tls_database_get_type"

  (* Methods *)

  external verify_chain_finish :
    t -> Async_result.t -> (Gio_enums.tlscertificateflags, GError.t) result
    = "ml_g_tls_database_verify_chain_finish"
  (** Finish an asynchronous verify chain operation. See
  g_tls_database_verify_chain() for more information.

  If @chain is found to be valid, then the return value will be 0. If
  @chain is found to be invalid, then the return value will indicate
  the problems found. If the function is unable to determine whether
  @chain is valid or not (eg, because @cancellable is triggered
  before it completes) then the return value will be
  %G_TLS_CERTIFICATE_GENERIC_ERROR and @error will be set
  accordingly. @error is not set when @chain is successfully analyzed
  but found to be invalid. *)

  external verify_chain :
    t ->
    Tls_certificate.t ->
    string ->
    Socket_address_and__socket_address_enumerator_and__socket_connectable
    .Socket_connectable
    .t
    option ->
    Tls_interaction.t option ->
    Gio_enums.tlsdatabaseverifyflags ->
    Cancellable.t option ->
    (Gio_enums.tlscertificateflags, GError.t) result
    = "ml_g_tls_database_verify_chain_bytecode"
      "ml_g_tls_database_verify_chain_native"
  (** Determines the validity of a certificate chain, outside the context
  of a TLS session.

  @chain is a chain of #GTlsCertificate objects each pointing to the next
  certificate in the chain by its #GTlsCertificate:issuer property.

  @purpose describes the purpose (or usage) for which the certificate
  is being used. Typically @purpose will be set to %G_TLS_DATABASE_PURPOSE_AUTHENTICATE_SERVER
  which means that the certificate is being used to authenticate a server
  (and we are acting as the client).

  The @identity is used to ensure the server certificate is valid for
  the expected peer identity. If the identity does not match the
  certificate, %G_TLS_CERTIFICATE_BAD_IDENTITY will be set in the
  return value. If @identity is %NULL, that bit will never be set in
  the return value. The peer identity may also be used to check for
  pinned certificates (trust exceptions) in the database. These may
  override the normal verification process on a host-by-host basis.

  Currently there are no @flags, and %G_TLS_DATABASE_VERIFY_NONE should be
  used.

  If @chain is found to be valid, then the return value will be 0. If
  @chain is found to be invalid, then the return value will indicate at
  least one problem found. If the function is unable to determine
  whether @chain is valid (for example, because @cancellable is
  triggered before it completes) then the return value will be
  %G_TLS_CERTIFICATE_GENERIC_ERROR and @error will be set accordingly.
  @error is not set when @chain is successfully analyzed but found to
  be invalid.

  GLib guarantees that if certificate verification fails, at least one
  error will be set in the return value, but it does not guarantee
  that all possible errors will be set. Accordingly, you may not safely
  decide to ignore any particular type of error. For example, it would
  be incorrect to mask %G_TLS_CERTIFICATE_EXPIRED if you want to allow
  expired certificates, because this could potentially be the only
  error flag set even if other problems exist with the certificate.

  Prior to GLib 2.48, GLib's default TLS backend modified @chain to
  represent the certification path built by #GTlsDatabase during
  certificate verification by adjusting the #GTlsCertificate:issuer
  property of each certificate in @chain. Since GLib 2.48, this no
  longer occurs, so you cannot rely on #GTlsCertificate:issuer to
  represent the actual certification path used during certificate
  verification.

  Because TLS session context is not used, #GTlsDatabase may not
  perform as many checks on the certificates as #GTlsConnection would.
  For example, certificate constraints may not be honored, and
  revocation checks may not be performed. The best way to verify TLS
  certificates used by a TLS connection is to let #GTlsConnection
  handle the verification.

  The TLS backend may attempt to look up and add missing certificates
  to the chain. This may involve HTTP requests to download missing
  certificates.

  This function can block. Use g_tls_database_verify_chain_async() to
  perform the verification operation asynchronously. *)

  external lookup_certificates_issued_by_finish :
    t -> Async_result.t -> (Tls_certificate.t list, GError.t) result
    = "ml_g_tls_database_lookup_certificates_issued_by_finish"
  (** Finish an asynchronous lookup of certificates. See
      g_tls_database_lookup_certificates_issued_by() for more information. *)

  external lookup_certificate_issuer_finish :
    t -> Async_result.t -> (Tls_certificate.t, GError.t) result
    = "ml_g_tls_database_lookup_certificate_issuer_finish"
  (** Finish an asynchronous lookup issuer operation. See
      g_tls_database_lookup_certificate_issuer() for more information. *)

  external lookup_certificate_issuer :
    t ->
    Tls_certificate.t ->
    Tls_interaction.t option ->
    Gio_enums.tlsdatabaselookupflags ->
    Cancellable.t option ->
    (Tls_certificate.t, GError.t) result
    = "ml_g_tls_database_lookup_certificate_issuer"
  (** Look up the issuer of @certificate in the database. The
  #GTlsCertificate:issuer property of @certificate is not modified, and
  the two certificates are not hooked into a chain.

  This function can block. Use g_tls_database_lookup_certificate_issuer_async()
  to perform the lookup operation asynchronously.

  Beware this function cannot be used to build certification paths. The
  issuer certificate returned by this function may not be the same as
  the certificate that would actually be used to construct a valid
  certification path during certificate verification.
  [RFC 4158](https://datatracker.ietf.org/doc/html/rfc4158) explains
  why an issuer certificate cannot be naively assumed to be part of the
  the certification path (though GLib's TLS backends may not follow the
  path building strategies outlined in this RFC). Due to the complexity
  of certification path building, GLib does not provide any way to know
  which certification path will actually be used when verifying a TLS
  certificate. Accordingly, this function cannot be used to make
  security-related decisions. Only GLib itself should make security
  decisions about TLS certificates. *)

  external lookup_certificate_for_handle_finish :
    t -> Async_result.t -> (Tls_certificate.t, GError.t) result
    = "ml_g_tls_database_lookup_certificate_for_handle_finish"
  (** Finish an asynchronous lookup of a certificate by its handle. See
      g_tls_database_lookup_certificate_for_handle() for more information.

      If the handle is no longer valid, or does not point to a certificate in
      this database, then %NULL will be returned. *)

  external lookup_certificate_for_handle :
    t ->
    string ->
    Tls_interaction.t option ->
    Gio_enums.tlsdatabaselookupflags ->
    Cancellable.t option ->
    (Tls_certificate.t option, GError.t) result
    = "ml_g_tls_database_lookup_certificate_for_handle"
  (** Look up a certificate by its handle.

      The handle should have been created by calling
      g_tls_database_create_certificate_handle() on a #GTlsDatabase object of
      the same TLS backend. The handle is designed to remain valid across
      instantiations of the database.

      If the handle is no longer valid, or does not point to a certificate in
      this database, then %NULL will be returned.

      This function can block, use
      g_tls_database_lookup_certificate_for_handle_async() to perform the lookup
      operation asynchronously. *)

  external create_certificate_handle : t -> Tls_certificate.t -> string option
    = "ml_g_tls_database_create_certificate_handle"
  (** Create a handle string for the certificate. The database will only be able
      to create a handle for certificates that originate from the database. In
      cases where the database cannot create a handle for a certificate, %NULL
      will be returned.

      This handle should be stable across various instances of the application,
      and between applications. If a certificate is modified in the database,
      then it is not guaranteed that this handle will continue to point to it.
  *)
end

and Tls_interaction : sig
  type t = [ `tls_interaction | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gio_tls_interaction_get_type"

  (* Methods *)

  external request_certificate_finish :
    t -> Async_result.t -> (Gio_enums.tlsinteractionresult, GError.t) result
    = "ml_g_tls_interaction_request_certificate_finish"
  (** Complete a request certificate user interaction request. This should be
      once the g_tls_interaction_request_certificate_async() completion callback
      is called.

      If %G_TLS_INTERACTION_HANDLED is returned, then the #GTlsConnection passed
      to g_tls_interaction_request_certificate_async() will have had its
      #GTlsConnection:certificate filled in.

      If the interaction is cancelled by the cancellation object, or by the user
      then %G_TLS_INTERACTION_FAILED will be returned with an error that
      contains a %G_IO_ERROR_CANCELLED error code. *)

  external request_certificate :
    t ->
    Tls_connection.t ->
    Gio_enums.tlscertificaterequestflags ->
    Cancellable.t option ->
    (Gio_enums.tlsinteractionresult, GError.t) result
    = "ml_g_tls_interaction_request_certificate"
  (** Run synchronous interaction to ask the user to choose a certificate to use
      with the connection. In general,
      g_tls_interaction_invoke_request_certificate() should be used instead of
      this function.

      Derived subclasses usually implement a certificate selector, although they
      may also choose to provide a certificate from elsewhere. Alternatively the
      user may abort this certificate request, which will usually abort the TLS
      connection.

      If %G_TLS_INTERACTION_HANDLED is returned, then the #GTlsConnection passed
      to g_tls_interaction_request_certificate() will have had its
      #GTlsConnection:certificate filled in.

      If the interaction is cancelled by the cancellation object, or by the user
      then %G_TLS_INTERACTION_FAILED will be returned with an error that
      contains a %G_IO_ERROR_CANCELLED error code. Certain implementations may
      not support immediate cancellation. *)

  external invoke_request_certificate :
    t ->
    Tls_connection.t ->
    Gio_enums.tlscertificaterequestflags ->
    Cancellable.t option ->
    (Gio_enums.tlsinteractionresult, GError.t) result
    = "ml_g_tls_interaction_invoke_request_certificate"
  (** Invoke the interaction to ask the user to choose a certificate to use with
      the connection. It invokes this interaction in the main loop, specifically
      the #GMainContext returned by g_main_context_get_thread_default() when the
      interaction is created. This is called by called by #GTlsConnection when
      the peer requests a certificate during the handshake.

      Derived subclasses usually implement a certificate selector, although they
      may also choose to provide a certificate from elsewhere. Alternatively the
      user may abort this certificate request, which may or may not abort the
      TLS connection.

      The implementation can either be a synchronous (eg: modal dialog) or an
      asynchronous one (eg: modeless dialog). This function will take care of
      calling which ever one correctly.

      If the interaction is cancelled by the cancellation object, or by the user
      then %G_TLS_INTERACTION_FAILED will be returned with an error that
      contains a %G_IO_ERROR_CANCELLED error code. Certain implementations may
      not support immediate cancellation. *)

  external invoke_ask_password :
    t ->
    Tls_password.t ->
    Cancellable.t option ->
    (Gio_enums.tlsinteractionresult, GError.t) result
    = "ml_g_tls_interaction_invoke_ask_password"
  (** Invoke the interaction to ask the user for a password. It invokes this
  interaction in the main loop, specifically the #GMainContext returned by
  g_main_context_get_thread_default() when the interaction is created. This
  is called by called by #GTlsConnection or #GTlsDatabase to ask the user
  for a password.

  Derived subclasses usually implement a password prompt, although they may
  also choose to provide a password from elsewhere. The @password value will
  be filled in and then @callback will be called. Alternatively the user may
  abort this password request, which will usually abort the TLS connection.

  The implementation can either be a synchronous (eg: modal dialog) or an
  asynchronous one (eg: modeless dialog). This function will take care of
  calling which ever one correctly.

  If the interaction is cancelled by the cancellation object, or by the
  user then %G_TLS_INTERACTION_FAILED will be returned with an error that
  contains a %G_IO_ERROR_CANCELLED error code. Certain implementations may
  not support immediate cancellation. *)

  external ask_password_finish :
    t -> Async_result.t -> (Gio_enums.tlsinteractionresult, GError.t) result
    = "ml_g_tls_interaction_ask_password_finish"
  (** Complete an ask password user interaction request. This should be once the
      g_tls_interaction_ask_password_async() completion callback is called.

      If %G_TLS_INTERACTION_HANDLED is returned, then the #GTlsPassword passed
      to g_tls_interaction_ask_password() will have its password filled in.

      If the interaction is cancelled by the cancellation object, or by the user
      then %G_TLS_INTERACTION_FAILED will be returned with an error that
      contains a %G_IO_ERROR_CANCELLED error code. *)

  external ask_password :
    t ->
    Tls_password.t ->
    Cancellable.t option ->
    (Gio_enums.tlsinteractionresult, GError.t) result
    = "ml_g_tls_interaction_ask_password"
  (** Run synchronous interaction to ask the user for a password. In general,
  g_tls_interaction_invoke_ask_password() should be used instead of this
  function.

  Derived subclasses usually implement a password prompt, although they may
  also choose to provide a password from elsewhere. The @password value will
  be filled in and then @callback will be called. Alternatively the user may
  abort this password request, which will usually abort the TLS connection.

  If the interaction is cancelled by the cancellation object, or by the
  user then %G_TLS_INTERACTION_FAILED will be returned with an error that
  contains a %G_IO_ERROR_CANCELLED error code. Certain implementations may
  not support immediate cancellation. *)
end
