(* GENERATED CODE - DO NOT EDIT *)
(* VolumeMonitor: VolumeMonitor *)

type t = [ `volume_monitor | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_volume_monitor_get_type"

(* Methods *)

external get_volumes : t -> App_info_cycle_64c425a0.Volume.t list
  = "ml_g_volume_monitor_get_volumes"
(** Gets a list of the volumes on the system.

    The returned list should be freed with g_list_free(), after its elements
    have been unreffed with g_object_unref(). *)

external get_volume_for_uuid :
  t -> string -> App_info_cycle_64c425a0.Volume.t option
  = "ml_g_volume_monitor_get_volume_for_uuid"
(** Finds a #GVolume object by its UUID (see g_volume_get_uuid()) *)

external get_mounts : t -> App_info_cycle_64c425a0.Mount.t list
  = "ml_g_volume_monitor_get_mounts"
(** Gets a list of the mounts on the system.

    The returned list should be freed with g_list_free(), after its elements
    have been unreffed with g_object_unref(). *)

external get_mount_for_uuid :
  t -> string -> App_info_cycle_64c425a0.Mount.t option
  = "ml_g_volume_monitor_get_mount_for_uuid"
(** Finds a #GMount object by its UUID (see g_mount_get_uuid()) *)

external get_connected_drives : t -> App_info_cycle_64c425a0.Drive.t list
  = "ml_g_volume_monitor_get_connected_drives"
(** Gets a list of drives connected to the system.

    The returned list should be freed with g_list_free(), after its elements
    have been unreffed with g_object_unref(). *)

val on_drive_changed :
  ?after:bool ->
  t ->
  callback:(drive:App_info_cycle_64c425a0.Drive.t -> unit) ->
  Gobject.Signal.handler_id

val on_drive_connected :
  ?after:bool ->
  t ->
  callback:(drive:App_info_cycle_64c425a0.Drive.t -> unit) ->
  Gobject.Signal.handler_id

val on_drive_disconnected :
  ?after:bool ->
  t ->
  callback:(drive:App_info_cycle_64c425a0.Drive.t -> unit) ->
  Gobject.Signal.handler_id

val on_drive_eject_button :
  ?after:bool ->
  t ->
  callback:(drive:App_info_cycle_64c425a0.Drive.t -> unit) ->
  Gobject.Signal.handler_id

val on_drive_stop_button :
  ?after:bool ->
  t ->
  callback:(drive:App_info_cycle_64c425a0.Drive.t -> unit) ->
  Gobject.Signal.handler_id

val on_mount_added :
  ?after:bool ->
  t ->
  callback:(mount:App_info_cycle_64c425a0.Mount.t -> unit) ->
  Gobject.Signal.handler_id

val on_mount_changed :
  ?after:bool ->
  t ->
  callback:(mount:App_info_cycle_64c425a0.Mount.t -> unit) ->
  Gobject.Signal.handler_id

val on_mount_pre_unmount :
  ?after:bool ->
  t ->
  callback:(mount:App_info_cycle_64c425a0.Mount.t -> unit) ->
  Gobject.Signal.handler_id

val on_mount_removed :
  ?after:bool ->
  t ->
  callback:(mount:App_info_cycle_64c425a0.Mount.t -> unit) ->
  Gobject.Signal.handler_id

val on_volume_added :
  ?after:bool ->
  t ->
  callback:(volume:App_info_cycle_64c425a0.Volume.t -> unit) ->
  Gobject.Signal.handler_id

val on_volume_changed :
  ?after:bool ->
  t ->
  callback:(volume:App_info_cycle_64c425a0.Volume.t -> unit) ->
  Gobject.Signal.handler_id

val on_volume_removed :
  ?after:bool ->
  t ->
  callback:(volume:App_info_cycle_64c425a0.Volume.t -> unit) ->
  Gobject.Signal.handler_id
