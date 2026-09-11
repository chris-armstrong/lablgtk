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

let on_allow_mechanism ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let mechanism =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_string v
        in
        let result = callback ~mechanism in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"allow-mechanism" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_authorize_authenticated_peer ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let stream =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v (Io_stream.gtype ())
        in
        let credentials =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_object v (Credentials.gtype ())
        in
        let result = callback ~stream ~credentials in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"authorize-authenticated-peer"
    ~callback:closure
    ~after:(Option.value after ~default:false)
