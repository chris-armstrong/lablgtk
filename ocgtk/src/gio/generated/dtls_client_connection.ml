(* GENERATED CODE - DO NOT EDIT *)
(* DtlsClientConnection: DtlsClientConnection *)

type t = [ `dtls_client_connection ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gio_dtls_client_connection_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gio_dtls_client_connection_from_gobject"

(* Methods *)

external set_validation_flags : t -> Gio_enums.tlscertificateflags -> unit
  = "ml_g_dtls_client_connection_set_validation_flags"
(** Sets @conn's validation flags, to override the default set of
checks performed when validating a server certificate. By default,
%G_TLS_CERTIFICATE_VALIDATE_ALL is used.

This function does not work as originally designed and is impossible
to use correctly. See #GDtlsClientConnection:validation-flags for more
information. *)

external set_server_identity :
  t ->
  Socket_address_and__socket_address_enumerator_and__socket_connectable
  .Socket_connectable
  .t ->
  unit = "ml_g_dtls_client_connection_set_server_identity"
(** Sets @conn's expected server identity, which is used both to tell
servers on virtual hosts which certificate to present, and also
to let @conn know what name to look for in the certificate when
performing %G_TLS_CERTIFICATE_BAD_IDENTITY validation, if enabled. *)

external get_validation_flags : t -> Gio_enums.tlscertificateflags
  = "ml_g_dtls_client_connection_get_validation_flags"
(** Gets @conn's validation flags

This function does not work as originally designed and is impossible
to use correctly. See #GDtlsClientConnection:validation-flags for more
information. *)

external get_server_identity :
  t ->
  Socket_address_and__socket_address_enumerator_and__socket_connectable
  .Socket_connectable
  .t = "ml_g_dtls_client_connection_get_server_identity"
(** Gets @conn's expected server identity *)

(* Properties *)
