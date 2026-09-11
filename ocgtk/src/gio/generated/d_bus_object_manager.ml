(* GENERATED CODE - DO NOT EDIT *)
(* DBusObjectManager: DBusObjectManager *)

type t = [ `d_bus_object_manager ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_d_bus_object_manager_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gio_d_bus_object_manager_from_gobject"

(* Methods *)

external get_objects :
  t -> D_bus_interface_and__d_bus_object.D_bus_object.t list
  = "ml_g_dbus_object_manager_get_objects"
(** Gets all #GDBusObject objects known to @manager. *)

external get_object_path : t -> string
  = "ml_g_dbus_object_manager_get_object_path"
(** Gets the object path that @manager is for. *)

external get_object :
  t -> string -> D_bus_interface_and__d_bus_object.D_bus_object.t option
  = "ml_g_dbus_object_manager_get_object"
(** Gets the #GDBusObject at @object_path, if any. *)

external get_interface :
  t ->
  string ->
  string ->
  D_bus_interface_and__d_bus_object.D_bus_interface.t option
  = "ml_g_dbus_object_manager_get_interface"
(** Gets the interface proxy for @interface_name at @object_path, if
any. *)

let on_interface_added ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let object_ =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (D_bus_interface_and__d_bus_object.D_bus_object.gtype ())
        in
        let interface =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_object_exn v
            (D_bus_interface_and__d_bus_object.D_bus_interface.gtype ())
        in
        callback ~object_ ~interface)
  in
  Gobject.Signal.connect obj ~name:"interface-added" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_interface_removed ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let object_ =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (D_bus_interface_and__d_bus_object.D_bus_object.gtype ())
        in
        let interface =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_object_exn v
            (D_bus_interface_and__d_bus_object.D_bus_interface.gtype ())
        in
        callback ~object_ ~interface)
  in
  Gobject.Signal.connect obj ~name:"interface-removed" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_object_added ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let object_ =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (D_bus_interface_and__d_bus_object.D_bus_object.gtype ())
        in
        callback ~object_)
  in
  Gobject.Signal.connect obj ~name:"object-added" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_object_removed ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let object_ =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (D_bus_interface_and__d_bus_object.D_bus_object.gtype ())
        in
        callback ~object_)
  in
  Gobject.Signal.connect obj ~name:"object-removed" ~callback:closure
    ~after:(Option.value after ~default:false)
