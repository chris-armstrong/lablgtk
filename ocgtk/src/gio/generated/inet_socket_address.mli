(* GENERATED CODE - DO NOT EDIT *)
(* InetSocketAddress: InetSocketAddress *)

type t = [ `inet_socket_address | `socket_address | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_inet_socket_address_get_type"

external new_ : Inet_address.t -> UInt16.t -> t = "ml_g_inet_socket_address_new"
(** Create a new InetSocketAddress *)

external new_from_string : string -> int -> t
  = "ml_g_inet_socket_address_new_from_string"
(** Create a new InetSocketAddress *)

(* Methods *)

external get_scope_id : t -> UInt32.t = "ml_g_inet_socket_address_get_scope_id"
(** Gets the `sin6_scope_id` field from @address,
which must be an IPv6 address.

If not overridden this value will be inherited from [property@Gio.InetSocketAddress:address]. *)

external get_port : t -> UInt16.t = "ml_g_inet_socket_address_get_port"
(** Gets @address's port. *)

external get_flowinfo : t -> UInt32.t = "ml_g_inet_socket_address_get_flowinfo"
(** Gets the `sin6_flowinfo` field from @address,
which must be an IPv6 address.

If not overridden this value will be inherited from [property@Gio.InetSocketAddress:address]. *)

external get_address : t -> Inet_address.t
  = "ml_g_inet_socket_address_get_address"
(** Gets @address's #GInetAddress. *)

(* Properties *)
