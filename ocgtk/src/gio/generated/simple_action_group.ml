(* GENERATED CODE - DO NOT EDIT *)
(* SimpleActionGroup: SimpleActionGroup *)

type t = [ `simple_action_group | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_simple_action_group_get_type"

external new_ : unit -> t = "ml_g_simple_action_group_new"
(** Create a new SimpleActionGroup *)

(* Methods *)

external remove : t -> string -> unit = "ml_g_simple_action_group_remove"
(** Removes the named action from the action group.

    If no action of this name is in the group then nothing happens. *)

external lookup : t -> string -> Action.t = "ml_g_simple_action_group_lookup"
(** Looks up the action with the name @action_name in the group.

If no such action exists, returns %NULL. *)

external insert : t -> Action.t -> unit = "ml_g_simple_action_group_insert"
(** Adds an action to the action group.

If the action group already contains an action with the same name as
@action then the old action is dropped from the group.

The action group takes its own reference on @action. *)
