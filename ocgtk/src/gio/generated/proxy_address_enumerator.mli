(* GENERATED CODE - DO NOT EDIT *)
(* ProxyAddressEnumerator: ProxyAddressEnumerator *)

type t =
  [ `proxy_address_enumerator | `socket_address_enumerator | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gio_proxy_address_enumerator_get_type"

(* Methods *)
(* Properties *)

external get_connectable :
  t ->
  Socket_address_and__socket_address_enumerator_and__socket_connectable
  .Socket_connectable
  .t = "ml_g_proxy_address_enumerator_get_connectable"
(** Get property: connectable *)

external get_default_port : t -> int
  = "ml_g_proxy_address_enumerator_get_default_port"
(** Get property: default-port *)

external get_proxy_resolver : t -> Proxy_resolver.t
  = "ml_g_proxy_address_enumerator_get_proxy_resolver"
(** Get property: proxy-resolver *)

external set_proxy_resolver : t -> Proxy_resolver.t -> unit
  = "ml_g_proxy_address_enumerator_set_proxy_resolver"
(** Set property: proxy-resolver *)

external get_uri : t -> string = "ml_g_proxy_address_enumerator_get_uri"
(** Get property: uri *)
