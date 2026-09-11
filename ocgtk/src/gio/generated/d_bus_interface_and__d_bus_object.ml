(* GENERATED CODE - DO NOT EDIT *)
(* Combined modules for cyclic dependencies *)

module rec D_bus_interface : sig
  type t = [ `d_bus_interface ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gio_d_bus_interface_get_type"

  external from_gobject : 'a Gobject.obj -> t
    = "ml_gio_d_bus_interface_from_gobject"

  (* Methods *)

  external set_object : t -> D_bus_object.t option -> unit
    = "ml_g_dbus_interface_set_object"
  (** Sets the #GDBusObject for @interface_ to @object.

  Note that @interface_ will hold a weak reference to @object. *)

  external get_info : t -> D_bus_interface_info.t
    = "ml_g_dbus_interface_get_info"
  (** Gets D-Bus introspection information for the D-Bus interface
  implemented by @interface_. *)

  external dup_object : t -> D_bus_object.t option
    = "ml_g_dbus_interface_dup_object"
  (** Gets the #GDBusObject that @interface_ belongs to, if any. *)
end = struct
  type t = [ `d_bus_interface ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gio_d_bus_interface_get_type"

  external from_gobject : 'a Gobject.obj -> t
    = "ml_gio_d_bus_interface_from_gobject"

  (* Methods *)

  external set_object : t -> D_bus_object.t option -> unit
    = "ml_g_dbus_interface_set_object"
  (** Sets the #GDBusObject for @interface_ to @object.

  Note that @interface_ will hold a weak reference to @object. *)

  external get_info : t -> D_bus_interface_info.t
    = "ml_g_dbus_interface_get_info"
  (** Gets D-Bus introspection information for the D-Bus interface
  implemented by @interface_. *)

  external dup_object : t -> D_bus_object.t option
    = "ml_g_dbus_interface_dup_object"
  (** Gets the #GDBusObject that @interface_ belongs to, if any. *)
end

and D_bus_object : sig
  type t = [ `d_bus_object ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gio_d_bus_object_get_type"

  external from_gobject : 'a Gobject.obj -> t
    = "ml_gio_d_bus_object_from_gobject"

  (* Methods *)

  external get_object_path : t -> string = "ml_g_dbus_object_get_object_path"
  (** Gets the object path for @object. *)

  external get_interfaces : t -> D_bus_interface.t list
    = "ml_g_dbus_object_get_interfaces"
  (** Gets the D-Bus interfaces associated with @object. *)

  external get_interface : t -> string -> D_bus_interface.t option
    = "ml_g_dbus_object_get_interface"
  (** Gets the D-Bus interface with name @interface_name associated with
  @object, if any. *)

  val on_interface_added :
    ?after:bool ->
    t ->
    callback:(interface:D_bus_interface.t -> unit) ->
    Gobject.Signal.handler_id

  val on_interface_removed :
    ?after:bool ->
    t ->
    callback:(interface:D_bus_interface.t -> unit) ->
    Gobject.Signal.handler_id
end = struct
  type t = [ `d_bus_object ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gio_d_bus_object_get_type"

  external from_gobject : 'a Gobject.obj -> t
    = "ml_gio_d_bus_object_from_gobject"

  (* Methods *)

  external get_object_path : t -> string = "ml_g_dbus_object_get_object_path"
  (** Gets the object path for @object. *)

  external get_interfaces : t -> D_bus_interface.t list
    = "ml_g_dbus_object_get_interfaces"
  (** Gets the D-Bus interfaces associated with @object. *)

  external get_interface : t -> string -> D_bus_interface.t option
    = "ml_g_dbus_object_get_interface"
  (** Gets the D-Bus interface with name @interface_name associated with
  @object, if any. *)

  let on_interface_added ?after obj ~callback =
    let closure =
      Gobject.Closure.create (fun argv ->
          let interface =
            let v = Gobject.Closure.nth argv ~pos:1 in
            Gobject.Value.get_object_exn v (D_bus_interface.gtype ())
          in
          callback ~interface)
    in
    Gobject.Signal.connect obj ~name:"interface-added" ~callback:closure
      ~after:(Option.value after ~default:false)

  let on_interface_removed ?after obj ~callback =
    let closure =
      Gobject.Closure.create (fun argv ->
          let interface =
            let v = Gobject.Closure.nth argv ~pos:1 in
            Gobject.Value.get_object_exn v (D_bus_interface.gtype ())
          in
          callback ~interface)
    in
    Gobject.Signal.connect obj ~name:"interface-removed" ~callback:closure
      ~after:(Option.value after ~default:false)
end
