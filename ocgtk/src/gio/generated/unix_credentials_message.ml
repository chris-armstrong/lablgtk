(* GENERATED CODE - DO NOT EDIT *)
(* UnixCredentialsMessage: UnixCredentialsMessage *)

type t =
  [ `unix_credentials_message | `socket_control_message | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gio_unix_credentials_message_get_type"

external new_ : unit -> t = "ml_g_unix_credentials_message_new"
(** Create a new UnixCredentialsMessage *)

external new_with_credentials : Credentials.t -> t
  = "ml_g_unix_credentials_message_new_with_credentials"
(** Create a new UnixCredentialsMessage *)

(* Methods *)

external get_credentials : t -> Credentials.t
  = "ml_g_unix_credentials_message_get_credentials"
(** Gets the credentials stored in @message. *)

(* Properties *)
