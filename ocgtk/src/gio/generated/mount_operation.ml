(* GENERATED CODE - DO NOT EDIT *)
(* MountOperation: MountOperation *)

type t = [ `mount_operation | `object_ ] Gobject.obj

external new_ : unit -> t = "ml_g_mount_operation_new"
(** Create a new MountOperation *)

(* Methods *)

external set_username : t -> string option -> unit
  = "ml_g_mount_operation_set_username"
(** Sets the user name within @op to @username. *)

external set_pim : t -> int -> unit = "ml_g_mount_operation_set_pim"
(** Sets the mount operation's PIM to @pim. *)

external set_password_save : t -> Gio_enums.passwordsave -> unit
  = "ml_g_mount_operation_set_password_save"
(** Sets the state of saving passwords for the mount operation. *)

external set_password : t -> string option -> unit
  = "ml_g_mount_operation_set_password"
(** Sets the mount operation's password to @password. *)

external set_is_tcrypt_system_volume : t -> bool -> unit
  = "ml_g_mount_operation_set_is_tcrypt_system_volume"
(** Sets the mount operation to use a system volume if @system_volume is %TRUE. *)

external set_is_tcrypt_hidden_volume : t -> bool -> unit
  = "ml_g_mount_operation_set_is_tcrypt_hidden_volume"
(** Sets the mount operation to use a hidden volume if @hidden_volume is %TRUE. *)

external set_domain : t -> string option -> unit
  = "ml_g_mount_operation_set_domain"
(** Sets the mount operation's domain. *)

external set_choice : t -> int -> unit = "ml_g_mount_operation_set_choice"
(** Sets a default choice for the mount operation. *)

external set_anonymous : t -> bool -> unit
  = "ml_g_mount_operation_set_anonymous"
(** Sets the mount operation to use an anonymous user if @anonymous is %TRUE. *)

external reply : t -> Gio_enums.mountoperationresult -> unit
  = "ml_g_mount_operation_reply"
(** Emits the #GMountOperation::reply signal. *)

external get_username : t -> string option = "ml_g_mount_operation_get_username"
(** Get the user name from the mount operation. *)

external get_pim : t -> int = "ml_g_mount_operation_get_pim"
(** Gets a PIM from the mount operation. *)

external get_password_save : t -> Gio_enums.passwordsave
  = "ml_g_mount_operation_get_password_save"
(** Gets the state of saving passwords for the mount operation. *)

external get_password : t -> string option = "ml_g_mount_operation_get_password"
(** Gets a password from the mount operation. *)

external get_is_tcrypt_system_volume : t -> bool
  = "ml_g_mount_operation_get_is_tcrypt_system_volume"
(** Check to see whether the mount operation is being used for a TCRYPT system
    volume. *)

external get_is_tcrypt_hidden_volume : t -> bool
  = "ml_g_mount_operation_get_is_tcrypt_hidden_volume"
(** Check to see whether the mount operation is being used for a TCRYPT hidden
    volume. *)

external get_domain : t -> string option = "ml_g_mount_operation_get_domain"
(** Gets the domain of the mount operation. *)

external get_choice : t -> int = "ml_g_mount_operation_get_choice"
(** Gets a choice from the mount operation. *)

external get_anonymous : t -> bool = "ml_g_mount_operation_get_anonymous"
(** Check to see whether the mount operation is being used for an anonymous
    user. *)

(* Properties *)

let on_aborted ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"aborted" ~callback
    ~after:(Option.value after ~default:false)

let on_ask_password ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let message =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_string_exn v
        in
        let default_user =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_string_exn v
        in
        let default_domain =
          let v = Gobject.Closure.nth argv ~pos:3 in
          Gobject.Value.get_string_exn v
        in
        let flags =
          let v = Gobject.Closure.nth argv ~pos:4 in
          Gio_enums.askpasswordflags_of_int (Gobject.Value.get_flags_int v)
        in
        callback ~message ~default_user ~default_domain ~flags)
  in
  Gobject.Signal.connect obj ~name:"ask-password" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_reply ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let result =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gio_enums.mountoperationresult_of_int (Gobject.Value.get_enum_int v)
        in
        callback ~result)
  in
  Gobject.Signal.connect obj ~name:"reply" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_show_unmount_progress ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let message =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_string_exn v
        in
        let time_left =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_int64 v
        in
        let bytes_left =
          let v = Gobject.Closure.nth argv ~pos:3 in
          Gobject.Value.get_int64 v
        in
        callback ~message ~time_left ~bytes_left)
  in
  Gobject.Signal.connect obj ~name:"show-unmount-progress" ~callback:closure
    ~after:(Option.value after ~default:false)
