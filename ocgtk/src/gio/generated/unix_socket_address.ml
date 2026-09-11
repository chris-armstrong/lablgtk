(* GENERATED CODE - DO NOT EDIT *)
(* UnixSocketAddress: UnixSocketAddress *)

type t = [ `unix_socket_address | `socket_address | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_unix_socket_address_get_type"

external new_ : string -> t = "ml_g_unix_socket_address_new"
(** Create a new UnixSocketAddress *)

external new_abstract : int array -> int -> t
  = "ml_g_unix_socket_address_new_abstract"
(** Create a new UnixSocketAddress *)

external new_with_type :
  int array -> int -> Gio_enums.unixsocketaddresstype -> t
  = "ml_g_unix_socket_address_new_with_type"
(** Create a new UnixSocketAddress *)

(* Methods *)

external get_path_len : t -> Gsize.t = "ml_g_unix_socket_address_get_path_len"
(** Gets the length of @address's path.

For details, see g_unix_socket_address_get_path(). *)

external get_path : t -> string = "ml_g_unix_socket_address_get_path"
(** Gets @address's path, or for abstract sockets the "name".

Guaranteed to be zero-terminated, but an abstract socket
may contain embedded zeros, and thus you should use
g_unix_socket_address_get_path_len() to get the true length
of this string. *)

external get_is_abstract : t -> bool
  = "ml_g_unix_socket_address_get_is_abstract"
(** Tests if @address is abstract. *)

external get_address_type : t -> Gio_enums.unixsocketaddresstype
  = "ml_g_unix_socket_address_get_address_type"
(** Gets @address's type. *)

(* Properties *)

external get_abstract : t -> bool = "ml_g_unix_socket_address_get_abstract"
(** Get property: abstract *)
