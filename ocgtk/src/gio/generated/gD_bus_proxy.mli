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

class d_bus_proxy : D_bus_proxy.t -> d_bus_proxy_t

val new_finish :
  GAsync_result.async_result_t -> (d_bus_proxy_t, GError.t) result

val new_for_bus_finish :
  GAsync_result.async_result_t -> (d_bus_proxy_t, GError.t) result

val new_for_bus_sync :
  Gio_enums.bustype ->
  Gio_enums.dbusproxyflags ->
  D_bus_interface_info.t option ->
  string ->
  string ->
  string ->
  GCancellable.cancellable_t option ->
  (d_bus_proxy_t, GError.t) result

val new_sync :
  GD_bus_connection.d_bus_connection_t ->
  Gio_enums.dbusproxyflags ->
  D_bus_interface_info.t option ->
  string option ->
  string ->
  string ->
  GCancellable.cancellable_t option ->
  (d_bus_proxy_t, GError.t) result
