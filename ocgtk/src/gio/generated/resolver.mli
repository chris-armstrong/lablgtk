(* GENERATED CODE - DO NOT EDIT *)
(* Resolver: Resolver *)

type t = [ `resolver | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_resolver_get_type"

(* Methods *)

external set_timeout : t -> int -> unit = "ml_g_resolver_set_timeout"
(** Set the timeout applied to all resolver lookups. See #GResolver:timeout. *)

external set_default : t -> unit = "ml_g_resolver_set_default"
(** Sets @resolver to be the application's default resolver (reffing
@resolver, and unreffing the previous default resolver, if any).
Future calls to g_resolver_get_default() will return this resolver.

This can be used if an application wants to perform any sort of DNS
caching or "pinning"; it can implement its own #GResolver that
calls the original default resolver for DNS operations, and
implements its own cache policies on top of that, and then set
itself as the default resolver for all later code to use. *)

external lookup_service_finish :
  t -> Async_result.t -> (Srv_target.t list, GError.t) result
  = "ml_g_resolver_lookup_service_finish"
(** Retrieves the result of a previous call to
g_resolver_lookup_service_async().

If the DNS resolution failed, @error (if non-%NULL) will be set to
a value from #GResolverError. If the operation was cancelled,
@error will be set to %G_IO_ERROR_CANCELLED. *)

external lookup_service :
  t ->
  string ->
  string ->
  string ->
  Cancellable.t option ->
  (Srv_target.t list, GError.t) result = "ml_g_resolver_lookup_service"
(** Synchronously performs a DNS SRV lookup for the given @service and
@protocol in the given @domain and returns an array of #GSrvTarget.
@domain may be an ASCII-only or UTF-8 hostname. Note also that the
@service and @protocol arguments do not include the leading underscore
that appears in the actual DNS entry.

On success, g_resolver_lookup_service() will return a non-empty #GList of
#GSrvTarget, sorted in order of preference. (That is, you should
attempt to connect to the first target first, then the second if
the first fails, etc.)

If the DNS resolution fails, @error (if non-%NULL) will be set to
a value from #GResolverError and %NULL will be returned.

If @cancellable is non-%NULL, it can be used to cancel the
operation, in which case @error (if non-%NULL) will be set to
%G_IO_ERROR_CANCELLED.

If you are planning to connect to the service, it is usually easier
to create a #GNetworkService and use its #GSocketConnectable
interface. *)

external lookup_records_finish :
  t -> Async_result.t -> (Gvariant.t list, GError.t) result
  = "ml_g_resolver_lookup_records_finish"
(** Retrieves the result of a previous call to
g_resolver_lookup_records_async(). Returns a non-empty list of records as
#GVariant tuples. See #GResolverRecordType for information on what the
records contain.

If the DNS resolution failed, @error (if non-%NULL) will be set to
a value from #GResolverError. If the operation was cancelled,
@error will be set to %G_IO_ERROR_CANCELLED. *)

external lookup_records :
  t ->
  string ->
  Gio_enums.resolverrecordtype ->
  Cancellable.t option ->
  (Gvariant.t list, GError.t) result = "ml_g_resolver_lookup_records"
(** Synchronously performs a DNS record lookup for the given @rrname and returns
a list of records as #GVariant tuples. See #GResolverRecordType for
information on what the records contain for each @record_type.

If the DNS resolution fails, @error (if non-%NULL) will be set to
a value from #GResolverError and %NULL will be returned.

If @cancellable is non-%NULL, it can be used to cancel the
operation, in which case @error (if non-%NULL) will be set to
%G_IO_ERROR_CANCELLED. *)

external lookup_by_name_with_flags_finish :
  t -> Async_result.t -> (Inet_address.t list, GError.t) result
  = "ml_g_resolver_lookup_by_name_with_flags_finish"
(** Retrieves the result of a call to
g_resolver_lookup_by_name_with_flags_async().

If the DNS resolution failed, @error (if non-%NULL) will be set to
a value from #GResolverError. If the operation was cancelled,
@error will be set to %G_IO_ERROR_CANCELLED. *)

external lookup_by_name_with_flags :
  t ->
  string ->
  Gio_enums.resolvernamelookupflags ->
  Cancellable.t option ->
  (Inet_address.t list, GError.t) result
  = "ml_g_resolver_lookup_by_name_with_flags"
(** This differs from g_resolver_lookup_by_name() in that you can modify
the lookup behavior with @flags. For example this can be used to limit
results with %G_RESOLVER_NAME_LOOKUP_FLAGS_IPV4_ONLY. *)

external lookup_by_name_finish :
  t -> Async_result.t -> (Inet_address.t list, GError.t) result
  = "ml_g_resolver_lookup_by_name_finish"
(** Retrieves the result of a call to
g_resolver_lookup_by_name_async().

If the DNS resolution failed, @error (if non-%NULL) will be set to
a value from #GResolverError. If the operation was cancelled,
@error will be set to %G_IO_ERROR_CANCELLED. *)

external lookup_by_name :
  t -> string -> Cancellable.t option -> (Inet_address.t list, GError.t) result
  = "ml_g_resolver_lookup_by_name"
(** Synchronously resolves @hostname to determine its associated IP
address(es). @hostname may be an ASCII-only or UTF-8 hostname, or
the textual form of an IP address (in which case this just becomes
a wrapper around g_inet_address_new_from_string()).

On success, g_resolver_lookup_by_name() will return a non-empty #GList of
#GInetAddress, sorted in order of preference and guaranteed to not
contain duplicates. That is, if using the result to connect to
@hostname, you should attempt to connect to the first address
first, then the second if the first fails, etc. If you are using
the result to listen on a socket, it is appropriate to add each
result using e.g. g_socket_listener_add_address().

If the DNS resolution fails, @error (if non-%NULL) will be set to a
value from #GResolverError and %NULL will be returned.

If @cancellable is non-%NULL, it can be used to cancel the
operation, in which case @error (if non-%NULL) will be set to
%G_IO_ERROR_CANCELLED.

If you are planning to connect to a socket on the resolved IP
address, it may be easier to create a #GNetworkAddress and use its
#GSocketConnectable interface. *)

external lookup_by_address_finish :
  t -> Async_result.t -> (string, GError.t) result
  = "ml_g_resolver_lookup_by_address_finish"
(** Retrieves the result of a previous call to
g_resolver_lookup_by_address_async().

If the DNS resolution failed, @error (if non-%NULL) will be set to
a value from #GResolverError. If the operation was cancelled,
@error will be set to %G_IO_ERROR_CANCELLED. *)

external lookup_by_address :
  t -> Inet_address.t -> Cancellable.t option -> (string, GError.t) result
  = "ml_g_resolver_lookup_by_address"
(** Synchronously reverse-resolves @address to determine its
associated hostname.

If the DNS resolution fails, @error (if non-%NULL) will be set to
a value from #GResolverError.

If @cancellable is non-%NULL, it can be used to cancel the
operation, in which case @error (if non-%NULL) will be set to
%G_IO_ERROR_CANCELLED. *)

external get_timeout : t -> int = "ml_g_resolver_get_timeout"
(** Get the timeout applied to all resolver lookups. See #GResolver:timeout. *)

(* Properties *)

val on_reload :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
