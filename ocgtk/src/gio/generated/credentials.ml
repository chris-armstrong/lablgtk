(* GENERATED CODE - DO NOT EDIT *)
(* Credentials: Credentials *)

type t = [ `credentials | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_credentials_get_type"

external new_ : unit -> t = "ml_g_credentials_new"
(** Create a new Credentials *)

(* Methods *)

external to_string : t -> string = "ml_g_credentials_to_string"
(** Creates a human-readable textual representation of @credentials
that can be used in logging and debug messages. The format of the
returned string may change in future GLib release. *)

external is_same_user : t -> t -> (bool, GError.t) result
  = "ml_g_credentials_is_same_user"
(** Checks if @credentials and @other_credentials is the same user.

This operation can fail if #GCredentials is not supported on the
the OS. *)
