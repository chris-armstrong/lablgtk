(* GENERATED CODE - DO NOT EDIT *)
(* Proxy: Proxy *)

type t = [ `proxy ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_proxy_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gio_proxy_from_gobject"

(* Methods *)

external supports_hostname : t -> bool = "ml_g_proxy_supports_hostname"
(** Some proxy protocols expect to be passed a hostname, which they
will resolve to an IP address themselves. Others, like SOCKS4, do
not allow this. This function will return %FALSE if @proxy is
implementing such a protocol. When %FALSE is returned, the caller
should resolve the destination hostname first, and then pass a
#GProxyAddress containing the stringified IP address to
g_proxy_connect() or g_proxy_connect_async(). *)

external connect_finish : t -> Async_result.t -> (Io_stream.t, GError.t) result
  = "ml_g_proxy_connect_finish"
(** See g_proxy_connect(). *)

external connect :
  t ->
  Io_stream.t ->
  Proxy_address.t ->
  Cancellable.t option ->
  (Io_stream.t, GError.t) result = "ml_g_proxy_connect"
(** Given @connection to communicate with a proxy (eg, a
#GSocketConnection that is connected to the proxy server), this
does the necessary handshake to connect to @proxy_address, and if
required, wraps the #GIOStream to handle proxy payload. *)
