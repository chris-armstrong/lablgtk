(* GENERATED CODE - DO NOT EDIT *)
(* ActionGroup: ActionGroup *)

type t = [ `action_group ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_action_group_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gio_action_group_from_gobject"

(* Methods *)

external list_actions : t -> string array = "ml_g_action_group_list_actions"
(** Lists the actions contained within @action_group.

The caller is responsible for freeing the list with [func@GLib.strfreev] when
it is no longer required. *)

external has_action : t -> string -> bool = "ml_g_action_group_has_action"
(** Checks if the named action exists within @action_group. *)

external get_action_state_type : t -> string -> Gvariant_type.t option
  = "ml_g_action_group_get_action_state_type"
(** Queries the type of the state of the named action within
@action_group.

If the action is stateful then this function returns the
[type@GLib.VariantType] of the state.  All calls to
[method@Gio.ActionGroup.change_action_state] must give a [type@GLib.Variant] of this
type and [method@Gio.ActionGroup.get_action_state] will return a [type@GLib.Variant]
of the same type.

If the action is not stateful then this function will return `NULL`.
In that case, [method@Gio.ActionGroup.get_action_state] will return `NULL`
and you must not call [method@Gio.ActionGroup.change_action_state].

The state type of a particular action will never change but it is
possible for an action to be removed and for a new action to be added
with the same name but a different state type. *)

external get_action_state_hint : t -> string -> Gvariant.t option
  = "ml_g_action_group_get_action_state_hint"
(** Requests a hint about the valid range of values for the state of the
named action within @action_group.

If `NULL` is returned it either means that the action is not stateful
or that there is no hint about the valid range of values for the
state of the action.

If a [type@GLib.Variant] array is returned then each item in the array is a
possible value for the state.  If a [type@GLib.Variant] pair (ie: two-tuple) is
returned then the tuple specifies the inclusive lower and upper bound
of valid values for the state.

In any case, the information is merely a hint.  It may be possible to
have a state value outside of the hinted range and setting a value
within the range may fail.

The return value (if non-`NULL`) should be freed with
[method@GLib.Variant.unref] when it is no longer required. *)

external get_action_state : t -> string -> Gvariant.t option
  = "ml_g_action_group_get_action_state"
(** Queries the current state of the named action within @action_group.

If the action is not stateful then `NULL` will be returned.  If the
action is stateful then the type of the return value is the type
given by [method@Gio.ActionGroup.get_action_state_type].

The return value (if non-`NULL`) should be freed with
[method@GLib.Variant.unref] when it is no longer required. *)

external get_action_parameter_type : t -> string -> Gvariant_type.t option
  = "ml_g_action_group_get_action_parameter_type"
(** Queries the type of the parameter that must be given when activating
the named action within @action_group.

When activating the action using [method@Gio.ActionGroup.activate_action],
the [type@GLib.Variant] given to that function must be of the type returned
by this function.

In the case that this function returns `NULL`, you must not give any
[type@GLib.Variant], but `NULL` instead.

The parameter type of a particular action will never change but it is
possible for an action to be removed and for a new action to be added
with the same name but a different parameter type. *)

external get_action_enabled : t -> string -> bool
  = "ml_g_action_group_get_action_enabled"
(** Checks if the named action within @action_group is currently enabled.

An action must be enabled in order to be activated or in order to
have its state changed from outside callers. *)

external change_action_state : t -> string -> Gvariant.t -> unit
  = "ml_g_action_group_change_action_state"
(** Request for the state of the named action within @action_group to be
changed to @value.

The action must be stateful and @value must be of the correct type.
See [method@Gio.ActionGroup.get_action_state_type].

This call merely requests a change.  The action may refuse to change
its state or may change its state to something other than @value.
See [method@Gio.ActionGroup.get_action_state_hint].

If the @value GVariant is floating, it is consumed. *)

external activate_action : t -> string -> Gvariant.t option -> unit
  = "ml_g_action_group_activate_action"
(** Activate the named action within @action_group.

If the action is expecting a parameter, then the correct type of
parameter must be given as @parameter.  If the action is expecting no
parameters then @parameter must be `NULL`.  See
[method@Gio.ActionGroup.get_action_parameter_type].

If the [type@Gio.ActionGroup] implementation supports asynchronous remote
activation over D-Bus, this call may return before the relevant
D-Bus traffic has been sent, or any replies have been received. In
order to block on such asynchronous activation calls,
[method@Gio.DBusConnection.flush] should be called prior to the code, which
depends on the result of the action activation. Without flushing
the D-Bus connection, there is no guarantee that the action would
have been activated.

The following code which runs in a remote app instance, shows an
example of a ‘quit’ action being activated on the primary app
instance over D-Bus. Here [method@Gio.DBusConnection.flush] is called
before `exit()`. Without `g_dbus_connection_flush()`, the ‘quit’ action
may fail to be activated on the primary instance.

```c
// call ‘quit’ action on primary instance
g_action_group_activate_action (G_ACTION_GROUP (app), "quit", NULL);

// make sure the action is activated now
g_dbus_connection_flush (…);

g_debug ("Application has been terminated. Exiting.");

exit (0);
``` *)

external action_state_changed : t -> string -> Gvariant.t -> unit
  = "ml_g_action_group_action_state_changed"
(** Emits the [signal@Gio.ActionGroup::action-state-changed] signal on @action_group.

This function should only be called by [type@Gio.ActionGroup] implementations. *)

external action_removed : t -> string -> unit
  = "ml_g_action_group_action_removed"
(** Emits the [signal@Gio.ActionGroup::action-removed] signal on @action_group.

This function should only be called by [type@Gio.ActionGroup] implementations. *)

external action_enabled_changed : t -> string -> bool -> unit
  = "ml_g_action_group_action_enabled_changed"
(** Emits the [signal@Gio.ActionGroup::action-enabled-changed] signal on @action_group.

This function should only be called by [type@Gio.ActionGroup] implementations. *)

external action_added : t -> string -> unit = "ml_g_action_group_action_added"
(** Emits the [signal@Gio.ActionGroup::action-added] signal on @action_group.

This function should only be called by [type@Gio.ActionGroup] implementations. *)

val on_action_added :
  ?after:bool ->
  t ->
  callback:(action_name:string -> unit) ->
  Gobject.Signal.handler_id

val on_action_enabled_changed :
  ?after:bool ->
  t ->
  callback:(action_name:string -> enabled:bool -> unit) ->
  Gobject.Signal.handler_id

val on_action_removed :
  ?after:bool ->
  t ->
  callback:(action_name:string -> unit) ->
  Gobject.Signal.handler_id

val on_action_state_changed :
  ?after:bool ->
  t ->
  callback:(action_name:string -> value:Gvariant.t -> unit) ->
  Gobject.Signal.handler_id
