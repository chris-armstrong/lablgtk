(* GENERATED CODE - DO NOT EDIT *)
(* NetworkAddress: NetworkAddress *)

type t = [ `network_address | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_network_address_get_type"

external new_ : string -> UInt16.t -> t = "ml_g_network_address_new"
(** Create a new NetworkAddress *)

external new_loopback : UInt16.t -> t = "ml_g_network_address_new_loopback"
(** Create a new NetworkAddress *)

(* Methods *)

external get_scheme : t -> string option = "ml_g_network_address_get_scheme"
(** Gets @addr's scheme *)

external get_port : t -> UInt16.t = "ml_g_network_address_get_port"
(** Gets @addr's port number *)

external get_hostname : t -> string = "ml_g_network_address_get_hostname"
(** Gets @addr's hostname. This might be either UTF-8 or ASCII-encoded,
depending on what @addr was created with. *)

(* Properties *)
