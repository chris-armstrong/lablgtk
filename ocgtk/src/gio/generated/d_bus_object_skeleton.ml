(* GENERATED CODE - DO NOT EDIT *)
(* DBusObjectSkeleton: DBusObjectSkeleton *)

type t = [ `d_bus_object_skeleton | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gio_d_bus_object_skeleton_get_type"

external new_ : string -> t = "ml_g_dbus_object_skeleton_new"
(** Create a new DBusObjectSkeleton *)

(* Methods *)

external set_object_path : t -> string -> unit
  = "ml_g_dbus_object_skeleton_set_object_path"
(** Sets the object path for @object. *)

external remove_interface_by_name : t -> string -> unit
  = "ml_g_dbus_object_skeleton_remove_interface_by_name"
(** Removes the #GDBusInterface with @interface_name from @object.

If no D-Bus interface of the given interface exists, this function
does nothing. *)

external remove_interface : t -> D_bus_interface_skeleton.t -> unit
  = "ml_g_dbus_object_skeleton_remove_interface"
(** Removes @interface_ from @object. *)

external flush : t -> unit = "ml_g_dbus_object_skeleton_flush"
(** This method simply calls g_dbus_interface_skeleton_flush() on all
interfaces belonging to @object. See that method for when flushing
is useful. *)

external add_interface : t -> D_bus_interface_skeleton.t -> unit
  = "ml_g_dbus_object_skeleton_add_interface"
(** Adds @interface_ to @object.

If @object already contains a #GDBusInterfaceSkeleton with the same
interface name, it is removed before @interface_ is added.

Note that @object takes its own reference on @interface_ and holds
it until removed. *)

(* Properties *)

external get_g_object_path : t -> string
  = "ml_g_d_bus_object_skeleton_get_g_object_path"
(** Get property: g-object-path *)

external set_g_object_path : t -> string -> unit
  = "ml_g_d_bus_object_skeleton_set_g_object_path"
(** Set property: g-object-path *)

let on_authorize_method ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let interface =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v (D_bus_interface_skeleton.gtype ())
        in
        let invocation =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_object_exn v (D_bus_method_invocation.gtype ())
        in
        let result = callback ~interface ~invocation in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"authorize-method" ~callback:closure
    ~after:(Option.value after ~default:false)
