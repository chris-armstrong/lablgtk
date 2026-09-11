(* GENERATED CODE - DO NOT EDIT *)
(* RemoteActionGroup: RemoteActionGroup *)

type t = [ `remote_action_group ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_remote_action_group_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gio_remote_action_group_from_gobject"

(* Methods *)

external change_action_state_full :
  t -> string -> Gvariant.t -> Gvariant.t -> unit
  = "ml_g_remote_action_group_change_action_state_full"
(** Changes the state of a remote action.

This is the same as g_action_group_change_action_state() except that
it allows for provision of "platform data" to be sent along with the
state change request.  This typically contains details such as the
user interaction timestamp or startup notification information.

@platform_data must be non-%NULL and must have the type
%G_VARIANT_TYPE_VARDICT.  If it is floating, it will be consumed. *)

external activate_action_full :
  t -> string -> Gvariant.t option -> Gvariant.t -> unit
  = "ml_g_remote_action_group_activate_action_full"
(** Activates the remote action.

This is the same as g_action_group_activate_action() except that it
allows for provision of "platform data" to be sent along with the
activation request.  This typically contains details such as the user
interaction timestamp or startup notification information.

@platform_data must be non-%NULL and must have the type
%G_VARIANT_TYPE_VARDICT.  If it is floating, it will be consumed. *)
