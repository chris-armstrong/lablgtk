(* GENERATED CODE - DO NOT EDIT *)
(* MountOperation: MountOperation *)

type t = [ `mount_operation | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_mount_operation_get_type"

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

val on_aborted :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_ask_password :
  ?after:bool ->
  t ->
  callback:
    (message:string ->
    default_user:string ->
    default_domain:string ->
    flags:Gio_enums.askpasswordflags ->
    unit) ->
  Gobject.Signal.handler_id

val on_reply :
  ?after:bool ->
  t ->
  callback:(result:Gio_enums.mountoperationresult -> unit) ->
  Gobject.Signal.handler_id

val on_show_unmount_progress :
  ?after:bool ->
  t ->
  callback:(message:string -> time_left:Int64.t -> bytes_left:Int64.t -> unit) ->
  Gobject.Signal.handler_id
