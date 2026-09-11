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

let on_drive_changed ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let drive =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (App_info_cycle_64c425a0.Drive.gtype ())
        in
        callback ~drive)
  in
  Gobject.Signal.connect obj ~name:"drive-changed" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_drive_connected ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let drive =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (App_info_cycle_64c425a0.Drive.gtype ())
        in
        callback ~drive)
  in
  Gobject.Signal.connect obj ~name:"drive-connected" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_drive_disconnected ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let drive =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (App_info_cycle_64c425a0.Drive.gtype ())
        in
        callback ~drive)
  in
  Gobject.Signal.connect obj ~name:"drive-disconnected" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_drive_eject_button ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let drive =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (App_info_cycle_64c425a0.Drive.gtype ())
        in
        callback ~drive)
  in
  Gobject.Signal.connect obj ~name:"drive-eject-button" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_drive_stop_button ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let drive =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (App_info_cycle_64c425a0.Drive.gtype ())
        in
        callback ~drive)
  in
  Gobject.Signal.connect obj ~name:"drive-stop-button" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_mount_added ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let mount =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (App_info_cycle_64c425a0.Mount.gtype ())
        in
        callback ~mount)
  in
  Gobject.Signal.connect obj ~name:"mount-added" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_mount_changed ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let mount =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (App_info_cycle_64c425a0.Mount.gtype ())
        in
        callback ~mount)
  in
  Gobject.Signal.connect obj ~name:"mount-changed" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_mount_pre_unmount ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let mount =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (App_info_cycle_64c425a0.Mount.gtype ())
        in
        callback ~mount)
  in
  Gobject.Signal.connect obj ~name:"mount-pre-unmount" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_mount_removed ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let mount =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (App_info_cycle_64c425a0.Mount.gtype ())
        in
        callback ~mount)
  in
  Gobject.Signal.connect obj ~name:"mount-removed" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_volume_added ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let volume =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (App_info_cycle_64c425a0.Volume.gtype ())
        in
        callback ~volume)
  in
  Gobject.Signal.connect obj ~name:"volume-added" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_volume_changed ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let volume =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (App_info_cycle_64c425a0.Volume.gtype ())
        in
        callback ~volume)
  in
  Gobject.Signal.connect obj ~name:"volume-changed" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_volume_removed ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let volume =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (App_info_cycle_64c425a0.Volume.gtype ())
        in
        callback ~volume)
  in
  Gobject.Signal.connect obj ~name:"volume-removed" ~callback:closure
    ~after:(Option.value after ~default:false)
