(* GENERATED CODE - DO NOT EDIT *)
(* ActionMap: ActionMap *)

type t = [ `action_map ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_action_map_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gio_action_map_from_gobject"

(* Methods *)

external remove_action_entries : t -> Action_entry.t array -> int -> unit
  = "ml_g_action_map_remove_action_entries"
(** Remove actions from a [iface@Gio.ActionMap]. This is meant as the reverse of
[method@Gio.ActionMap.add_action_entries].


```c
static const GActionEntry entries[] = {
    { "quit",         activate_quit              },
    { "print-string", activate_print_string, "s" }
};

void
add_actions (GActionMap *map)
{
  g_action_map_add_action_entries (map, entries, G_N_ELEMENTS (entries), NULL);
}

void
remove_actions (GActionMap *map)
{
  g_action_map_remove_action_entries (map, entries, G_N_ELEMENTS (entries));
}
``` *)

external remove_action : t -> string -> unit = "ml_g_action_map_remove_action"
(** Removes the named action from the action map.

    If no action of this name is in the map then nothing happens. *)

external lookup_action : t -> string -> Action.t option
  = "ml_g_action_map_lookup_action"
(** Looks up the action with the name @action_name in @action_map.

If no such action exists, returns `NULL`. *)

external add_action : t -> Action.t -> unit = "ml_g_action_map_add_action"
(** Adds an action to the @action_map.

If the action map already contains an action with the same name
as @action then the old action is dropped from the action map.

The action map takes its own reference on @action. *)
