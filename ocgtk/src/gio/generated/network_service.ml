(* GENERATED CODE - DO NOT EDIT *)
(* NetworkService: NetworkService *)

type t = [ `network_service | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_network_service_get_type"

external new_ : string -> string -> string -> t = "ml_g_network_service_new"
(** Create a new NetworkService *)

(* Methods *)

external set_scheme : t -> string -> unit = "ml_g_network_service_set_scheme"
(** Set's the URI scheme used to resolve proxies. By default, the service name
    is used as scheme. *)

external get_service : t -> string = "ml_g_network_service_get_service"
(** Gets @srv's service name (eg, "ldap"). *)

external get_scheme : t -> string = "ml_g_network_service_get_scheme"
(** Gets the URI scheme used to resolve proxies. By default, the service name is
    used as scheme. *)

external get_protocol : t -> string = "ml_g_network_service_get_protocol"
(** Gets @srv's protocol name (eg, "tcp"). *)

external get_domain : t -> string = "ml_g_network_service_get_domain"
(** Gets the domain that @srv serves. This might be either UTF-8 or
ASCII-encoded, depending on what @srv was created with. *)

(* Properties *)
