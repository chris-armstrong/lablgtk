(* GENERATED CODE - DO NOT EDIT *)
(* TlsBackend: TlsBackend *)

type t = [ `tls_backend ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_tls_backend_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gio_tls_backend_from_gobject"

(* Methods *)

external supports_tls : t -> bool = "ml_g_tls_backend_supports_tls"
(** Checks if TLS is supported; if this returns %FALSE for the default
    #GTlsBackend, it means no "real" TLS backend is available. *)

external supports_dtls : t -> bool = "ml_g_tls_backend_supports_dtls"
(** Checks if DTLS is supported. DTLS support may not be available even if TLS
    support is available, and vice-versa. *)

external set_default_database :
  t ->
  Tls_connection_and__tls_database_and__tls_interaction.Tls_database.t option ->
  unit = "ml_g_tls_backend_set_default_database"
(** Set the default #GTlsDatabase used to verify TLS connections

    Any subsequent call to g_tls_backend_get_default_database() will return the
    database set in this call. Existing databases and connections are not
    modified.

    Setting a %NULL default database will reset to using the system default
    database as if g_tls_backend_set_default_database() had never been called.
*)

external get_server_connection_type : t -> Gobject.Type.t
  = "ml_g_tls_backend_get_server_connection_type"
(** Gets the #GType of @backend's #GTlsServerConnection implementation. *)

external get_file_database_type : t -> Gobject.Type.t
  = "ml_g_tls_backend_get_file_database_type"
(** Gets the #GType of @backend's #GTlsFileDatabase implementation. *)

external get_dtls_server_connection_type : t -> Gobject.Type.t
  = "ml_g_tls_backend_get_dtls_server_connection_type"
(** Gets the #GType of @backend’s #GDtlsServerConnection implementation. *)

external get_dtls_client_connection_type : t -> Gobject.Type.t
  = "ml_g_tls_backend_get_dtls_client_connection_type"
(** Gets the #GType of @backend’s #GDtlsClientConnection implementation. *)

external get_default_database :
  t -> Tls_connection_and__tls_database_and__tls_interaction.Tls_database.t
  = "ml_g_tls_backend_get_default_database"
(** Gets the default #GTlsDatabase used to verify TLS connections. *)

external get_client_connection_type : t -> Gobject.Type.t
  = "ml_g_tls_backend_get_client_connection_type"
(** Gets the #GType of @backend's #GTlsClientConnection implementation. *)

external get_certificate_type : t -> Gobject.Type.t
  = "ml_g_tls_backend_get_certificate_type"
(** Gets the #GType of @backend's #GTlsCertificate implementation. *)
