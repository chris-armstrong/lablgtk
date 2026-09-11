(* GENERATED CODE - DO NOT EDIT *)
(* NetworkMonitor: NetworkMonitor *)

type t = [ `network_monitor ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_network_monitor_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gio_network_monitor_from_gobject"

(* Methods *)

external get_network_metered : t -> bool
  = "ml_g_network_monitor_get_network_metered"
(** Checks if the network is metered. See #GNetworkMonitor:network-metered for
    more details. *)

external get_network_available : t -> bool
  = "ml_g_network_monitor_get_network_available"
(** Checks if the network is available. "Available" here means that the system
    has a default route available for at least one of IPv4 or IPv6. It does not
    necessarily imply that the public Internet is reachable. See
    #GNetworkMonitor:network-available for more details. *)

external get_connectivity : t -> Gio_enums.networkconnectivity
  = "ml_g_network_monitor_get_connectivity"
(** Gets a more detailed networking state than
    g_network_monitor_get_network_available().

    If #GNetworkMonitor:network-available is %FALSE, then the connectivity state
    will be %G_NETWORK_CONNECTIVITY_LOCAL.

    If #GNetworkMonitor:network-available is %TRUE, then the connectivity state
    will be %G_NETWORK_CONNECTIVITY_FULL (if there is full Internet
    connectivity), %G_NETWORK_CONNECTIVITY_LIMITED (if the host has a default
    route, but appears to be unable to actually reach the full Internet), or
    %G_NETWORK_CONNECTIVITY_PORTAL (if the host is trapped behind a "captive
    portal" that requires some sort of login or acknowledgement before allowing
    full Internet access).

    Note that in the case of %G_NETWORK_CONNECTIVITY_LIMITED and
    %G_NETWORK_CONNECTIVITY_PORTAL, it is possible that some sites are reachable
    but others are not. In this case, applications can attempt to connect to
    remote servers, but should gracefully fall back to their "offline" behavior
    if the connection attempt fails. *)

external can_reach_finish : t -> Async_result.t -> (bool, GError.t) result
  = "ml_g_network_monitor_can_reach_finish"
(** Finishes an async network connectivity test. See
    g_network_monitor_can_reach_async(). *)

external can_reach :
  t ->
  Socket_address_and__socket_address_enumerator_and__socket_connectable
  .Socket_connectable
  .t ->
  Cancellable.t option ->
  (bool, GError.t) result = "ml_g_network_monitor_can_reach"
(** Attempts to determine whether or not the host pointed to by
@connectable can be reached, without actually trying to connect to
it.

This may return %TRUE even when #GNetworkMonitor:network-available
is %FALSE, if, for example, @monitor can determine that
@connectable refers to a host on a local network.

If @monitor believes that an attempt to connect to @connectable
will succeed, it will return %TRUE. Otherwise, it will return
%FALSE and set @error to an appropriate error (such as
%G_IO_ERROR_HOST_UNREACHABLE).

Note that although this does not attempt to connect to
@connectable, it may still block for a brief period of time (eg,
trying to do multicast DNS on the local network), so if you do not
want to block, you should use g_network_monitor_can_reach_async(). *)

(* Properties *)

val on_network_changed :
  ?after:bool ->
  t ->
  callback:(network_available:bool -> unit) ->
  Gobject.Signal.handler_id
