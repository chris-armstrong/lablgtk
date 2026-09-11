(* GENERATED CODE - DO NOT EDIT *)
(* ProxyResolver: ProxyResolver *)

type t = [ `proxy_resolver ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_proxy_resolver_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gio_proxy_resolver_from_gobject"

(* Methods *)

external lookup_finish : t -> Async_result.t -> (string array, GError.t) result
  = "ml_g_proxy_resolver_lookup_finish"
(** Call this function to obtain the array of proxy URIs when
    g_proxy_resolver_lookup_async() is complete. See g_proxy_resolver_lookup()
    for more details. *)

external lookup :
  t -> string -> Cancellable.t option -> (string array, GError.t) result
  = "ml_g_proxy_resolver_lookup"
(** Looks into the system proxy configuration to determine what proxy,
if any, to use to connect to @uri. The returned proxy URIs are of
the form `<protocol>://[user[:password]@]host[:port]` or
`direct://`, where `<protocol>` could be http, rtsp, socks
or other proxying protocol.

If you don't know what network protocol is being used on the
socket, you should use `none` as the URI protocol.
In this case, the resolver might still return a generic proxy type
(such as SOCKS), but would not return protocol-specific proxy types
(such as http).

`direct://` is used when no proxy is needed.
Direct connection should not be attempted unless it is part of the
returned array of proxies. *)

external is_supported : t -> bool = "ml_g_proxy_resolver_is_supported"
(** Checks if @resolver can be used on this system. (This is used
internally; g_proxy_resolver_get_default() will only return a proxy
resolver that returns %TRUE for this method.) *)
