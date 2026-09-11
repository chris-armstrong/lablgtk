(* GENERATED CODE - DO NOT EDIT *)
(* DBusAuthObserver: DBusAuthObserver *)

type t = [ `d_bus_auth_observer | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_d_bus_auth_observer_get_type"

external new_ : unit -> t = "ml_g_dbus_auth_observer_new"
(** Create a new DBusAuthObserver *)

(* Methods *)

external authorize_authenticated_peer :
  t -> Io_stream.t -> Credentials.t option -> bool
  = "ml_g_dbus_auth_observer_authorize_authenticated_peer"
(** Emits the #GDBusAuthObserver::authorize-authenticated-peer signal on @observer. *)

external allow_mechanism : t -> string -> bool
  = "ml_g_dbus_auth_observer_allow_mechanism"
(** Emits the #GDBusAuthObserver::allow-mechanism signal on @observer. *)

val on_allow_mechanism :
  ?after:bool ->
  t ->
  callback:(mechanism:string -> bool) ->
  Gobject.Signal.handler_id

val on_authorize_authenticated_peer :
  ?after:bool ->
  t ->
  callback:(stream:Io_stream.t -> credentials:Credentials.t option -> bool) ->
  Gobject.Signal.handler_id
