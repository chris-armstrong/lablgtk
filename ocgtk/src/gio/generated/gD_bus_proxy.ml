class type d_bus_proxy_t = object
  inherit GAsync_initable.async_initable_t
  inherit GD_bus_interface_and__d_bus_object.d_bus_interface_t
  inherit GInitable.initable_t

  method on_g_signal :
    ?after:bool ->
    callback:
      (sender_name:string option ->
      signal_name:string ->
      parameters:Gvariant.t ->
      unit) ->
    unit ->
    Gobject.Signal.handler_id

  method call_finish :
    GAsync_result.async_result_t -> (Gvariant.t, GError.t) result

  method call_sync :
    string ->
    Gvariant.t option ->
    Gio_enums.dbuscallflags ->
    int ->
    GCancellable.cancellable_t option ->
    (Gvariant.t, GError.t) result

  method get_cached_property : string -> Gvariant.t option
  method get_cached_property_names : unit -> string array option
  method get_connection : unit -> GD_bus_connection.d_bus_connection_t
  method get_default_timeout : unit -> int
  method get_flags : unit -> Gio_enums.dbusproxyflags
  method get_interface_info : unit -> D_bus_interface_info.t option
  method get_interface_name : unit -> string
  method get_name : unit -> string option
  method get_name_owner : unit -> string option
  method get_object_path : unit -> string
  method set_cached_property : string -> Gvariant.t option -> unit
  method set_default_timeout : int -> unit
  method set_interface_info : D_bus_interface_info.t option -> unit
  method g_connection : GD_bus_connection.d_bus_connection_t
  method g_default_timeout : int
  method set_g_default_timeout : int -> unit
  method g_flags : Gio_enums.dbusproxyflags
  method g_interface_info : D_bus_interface_info.t
  method set_g_interface_info : D_bus_interface_info.t -> unit
  method g_interface_name : string
  method g_name : string
  method g_name_owner : string
  method g_object_path : string
  method as_d_bus_proxy : D_bus_proxy.t
end

(* High-level class for DBusProxy *)
class d_bus_proxy (obj : D_bus_proxy.t) : d_bus_proxy_t =
  object (self)
    inherit GAsync_initable.async_initable (Async_initable.from_gobject obj)

    inherit
      GD_bus_interface_and__d_bus_object.d_bus_interface
        (D_bus_interface_and__d_bus_object.D_bus_interface.from_gobject obj)

    inherit GInitable.initable (Initable.from_gobject obj)

    method on_g_signal ?(after = false) ~callback () =
      D_bus_proxy.on_g_signal ~after self#as_d_bus_proxy ~callback

    method call_finish :
        GAsync_result.async_result_t -> (Gvariant.t, GError.t) result =
      fun res ->
        let res = res#as_async_result in
        D_bus_proxy.call_finish obj res

    method call_sync :
        string ->
        Gvariant.t option ->
        Gio_enums.dbuscallflags ->
        int ->
        GCancellable.cancellable_t option ->
        (Gvariant.t, GError.t) result =
      fun method_name parameters flags timeout_msec cancellable ->
        let cancellable = Option.map (fun c -> c#as_cancellable) cancellable in
        D_bus_proxy.call_sync obj method_name parameters flags timeout_msec
          cancellable

    method get_cached_property : string -> Gvariant.t option =
      fun property_name -> D_bus_proxy.get_cached_property obj property_name

    method get_cached_property_names : unit -> string array option =
      fun () -> D_bus_proxy.get_cached_property_names obj

    method get_connection : unit -> GD_bus_connection.d_bus_connection_t =
      fun () ->
        new GD_bus_connection.d_bus_connection (D_bus_proxy.get_connection obj)

    method get_default_timeout : unit -> int =
      fun () -> D_bus_proxy.get_default_timeout obj

    method get_flags : unit -> Gio_enums.dbusproxyflags =
      fun () -> D_bus_proxy.get_flags obj

    method get_interface_info : unit -> D_bus_interface_info.t option =
      fun () -> D_bus_proxy.get_interface_info obj

    method get_interface_name : unit -> string =
      fun () -> D_bus_proxy.get_interface_name obj

    method get_name : unit -> string option = fun () -> D_bus_proxy.get_name obj

    method get_name_owner : unit -> string option =
      fun () -> D_bus_proxy.get_name_owner obj

    method get_object_path : unit -> string =
      fun () -> D_bus_proxy.get_object_path obj

    method set_cached_property : string -> Gvariant.t option -> unit =
      fun property_name value ->
        D_bus_proxy.set_cached_property obj property_name value

    method set_default_timeout : int -> unit =
      fun timeout_msec -> D_bus_proxy.set_default_timeout obj timeout_msec

    method set_interface_info : D_bus_interface_info.t option -> unit =
      fun info -> D_bus_proxy.set_interface_info obj info

    method g_connection =
      new GD_bus_connection.d_bus_connection (D_bus_proxy.get_g_connection obj)

    method g_default_timeout = D_bus_proxy.get_g_default_timeout obj
    method set_g_default_timeout v = D_bus_proxy.set_g_default_timeout obj v
    method g_flags = D_bus_proxy.get_g_flags obj
    method g_interface_info = D_bus_proxy.get_g_interface_info obj
    method set_g_interface_info v = D_bus_proxy.set_g_interface_info obj v
    method g_interface_name = D_bus_proxy.get_g_interface_name obj
    method g_name = D_bus_proxy.get_g_name obj
    method g_name_owner = D_bus_proxy.get_g_name_owner obj
    method g_object_path = D_bus_proxy.get_g_object_path obj
    method as_d_bus_proxy = obj
  end

let new_finish (res : GAsync_result.async_result_t) :
    (d_bus_proxy_t, GError.t) result =
  let res = res#as_async_result in
  let obj_ = D_bus_proxy.new_finish res in
  Result.map (fun obj_ -> new d_bus_proxy obj_) obj_

let new_for_bus_finish (res : GAsync_result.async_result_t) :
    (d_bus_proxy_t, GError.t) result =
  let res = res#as_async_result in
  let obj_ = D_bus_proxy.new_for_bus_finish res in
  Result.map (fun obj_ -> new d_bus_proxy obj_) obj_

let new_for_bus_sync (bus_type : Gio_enums.bustype)
    (flags : Gio_enums.dbusproxyflags) (info : D_bus_interface_info.t option)
    (name : string) (object_path : string) (interface_name : string)
    (cancellable : GCancellable.cancellable_t option) :
    (d_bus_proxy_t, GError.t) result =
  let cancellable = Option.map (fun c -> c#as_cancellable) cancellable in
  let obj_ =
    D_bus_proxy.new_for_bus_sync bus_type flags info name object_path
      interface_name cancellable
  in
  Result.map (fun obj_ -> new d_bus_proxy obj_) obj_

let new_sync (connection : GD_bus_connection.d_bus_connection_t)
    (flags : Gio_enums.dbusproxyflags) (info : D_bus_interface_info.t option)
    (name : string option) (object_path : string) (interface_name : string)
    (cancellable : GCancellable.cancellable_t option) :
    (d_bus_proxy_t, GError.t) result =
  let connection = connection#as_d_bus_connection in
  let cancellable = Option.map (fun c -> c#as_cancellable) cancellable in
  let obj_ =
    D_bus_proxy.new_sync connection flags info name object_path interface_name
      cancellable
  in
  Result.map (fun obj_ -> new d_bus_proxy obj_) obj_
