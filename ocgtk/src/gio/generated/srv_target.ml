(* GENERATED CODE - DO NOT EDIT *)
(* SrvTarget: SrvTarget *)

type t = [ `srv_target ] Gobject.obj
(** A single target host/port that a network service is running on.

    SRV (service) records are used by some network protocols to provide
    service-specific aliasing and load-balancing. For example, XMPP (Jabber)
    uses SRV records to locate the XMPP server for a domain; rather than
    connecting directly to ‘example.com’ or assuming a specific server hostname
    like ‘xmpp.example.com’, an XMPP client would look up the `xmpp-client` SRV
    record for ‘example.com’, and then connect to whatever host was pointed to
    by that record.

    You can use [method@Gio.Resolver.lookup_service] or
    [method@Gio.Resolver.lookup_service_async] to find the `GSrvTarget`s for a
    given service. However, if you are simply planning to connect to the remote
    service, you can use [class@Gio.NetworkService]’s
    [iface@Gio.SocketConnectable] interface and not need to worry about
    `GSrvTarget` at all. *)

external gtype : unit -> Gobject.Type.t = "ml_gio_srv_target_get_type"

external new_ : string -> UInt16.t -> UInt16.t -> UInt16.t -> t
  = "ml_g_srv_target_new"
(** Create a new SrvTarget *)

(* Methods *)

external get_weight : t -> UInt16.t = "ml_g_srv_target_get_weight"
(** Gets @target's weight. You should not need to look at this;
#GResolver already sorts the targets according to the algorithm in
RFC 2782. *)

external get_priority : t -> UInt16.t = "ml_g_srv_target_get_priority"
(** Gets @target's priority. You should not need to look at this;
#GResolver already sorts the targets according to the algorithm in
RFC 2782. *)

external get_port : t -> UInt16.t = "ml_g_srv_target_get_port"
(** Gets @target's port *)

external get_hostname : t -> string = "ml_g_srv_target_get_hostname"
(** Gets @target's hostname (in ASCII form; if you are going to present
this to the user, you should use g_hostname_is_ascii_encoded() to
check if it contains encoded Unicode segments, and use
g_hostname_to_unicode() to convert it if it does.) *)
