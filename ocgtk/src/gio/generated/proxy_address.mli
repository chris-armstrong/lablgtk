(* GENERATED CODE - DO NOT EDIT *)
(* ProxyAddress: ProxyAddress *)

type t =
  [ `proxy_address | `inet_socket_address | `socket_address | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_proxy_address_get_type"

external new_ :
  Inet_address.t ->
  UInt16.t ->
  string ->
  string ->
  UInt16.t ->
  string option ->
  string option ->
  t = "ml_g_proxy_address_new_bytecode" "ml_g_proxy_address_new_native"
(** Create a new ProxyAddress *)

(* Methods *)

external get_username : t -> string option = "ml_g_proxy_address_get_username"
(** Gets @proxy's username. *)

external get_uri : t -> string option = "ml_g_proxy_address_get_uri"
(** Gets the proxy URI that @proxy was constructed from. *)

external get_protocol : t -> string = "ml_g_proxy_address_get_protocol"
(** Gets @proxy's protocol. eg, "socks" or "http" *)

external get_password : t -> string option = "ml_g_proxy_address_get_password"
(** Gets @proxy's password. *)

external get_destination_protocol : t -> string
  = "ml_g_proxy_address_get_destination_protocol"
(** Gets the protocol that is being spoken to the destination server; eg, "http"
    or "ftp". *)

external get_destination_port : t -> UInt16.t
  = "ml_g_proxy_address_get_destination_port"
(** Gets @proxy's destination port; that is, the port on the
destination host that will be connected to via the proxy, not the
port number of the proxy itself. *)

external get_destination_hostname : t -> string
  = "ml_g_proxy_address_get_destination_hostname"
(** Gets @proxy's destination hostname; that is, the name of the host
that will be connected to via the proxy, not the name of the proxy
itself. *)

(* Properties *)
