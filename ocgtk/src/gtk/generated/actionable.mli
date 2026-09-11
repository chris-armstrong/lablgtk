(* GENERATED CODE - DO NOT EDIT *)
(* Actionable: Actionable *)

type t = [ `actionable ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_actionable_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gtk_actionable_from_gobject"

(* Methods *)

external set_detailed_action_name : t -> string -> unit
  = "ml_gtk_actionable_set_detailed_action_name"
(** Sets the action-name and associated string target value of an
actionable widget.

@detailed_action_name is a string in the format accepted by
[func@Gio.Action.parse_detailed_name]. *)

external set_action_target_value : t -> Gvariant.t option -> unit
  = "ml_gtk_actionable_set_action_target_value"
(** Sets the target value of an actionable widget.

If @target_value is %NULL then the target value is unset.

The target value has two purposes. First, it is used as the parameter
to activation of the action associated with the `GtkActionable` widget.
Second, it is used to determine if the widget should be rendered as
“active” — the widget is active if the state is equal to the given target.

Consider the example of associating a set of buttons with a [iface@Gio.Action]
with string state in a typical “radio button” situation. Each button
will be associated with the same action, but with a different target
value for that action. Clicking on a particular button will activate
the action with the target of that button, which will typically cause
the action’s state to change to that value. Since the action’s state
is now equal to the target value of the button, the button will now
be rendered as active (and the other buttons, with different targets,
rendered inactive). *)

external set_action_name : t -> string option -> unit
  = "ml_gtk_actionable_set_action_name"
(** Specifies the name of the action with which this widget should be
associated.

If @action_name is %NULL then the widget will be unassociated from
any previous action.

Usually this function is used when the widget is located (or will be
located) within the hierarchy of a `GtkApplicationWindow`.

Names are of the form “win.save” or “app.quit” for actions on the
containing [class@ApplicationWindow] or its associated [class@Application],
respectively. This is the same form used for actions in the [class@Gio.Menu]
associated with the window. *)

external get_action_target_value : t -> Gvariant.t option
  = "ml_gtk_actionable_get_action_target_value"
(** Gets the current target value of @actionable. *)

external get_action_name : t -> string option
  = "ml_gtk_actionable_get_action_name"
(** Gets the action name for @actionable. *)

(* Properties *)
