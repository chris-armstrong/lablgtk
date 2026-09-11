(* GENERATED CODE - DO NOT EDIT *)
(* ShortcutAction: ShortcutAction *)

type t = [ `shortcut_action | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_shortcut_action_get_type"

external parse_string : string -> t = "ml_gtk_shortcut_action_parse_string"
(** Create a new ShortcutAction *)

(* Methods *)

external to_string : t -> string = "ml_gtk_shortcut_action_to_string"
(** Prints the given action into a human-readable string.

    This is a small wrapper around [method@Gtk.ShortcutAction.print] to help
    when debugging. *)

external activate :
  t ->
  Gtk_enums.shortcutactionflags ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Gvariant.t option ->
  bool = "ml_gtk_shortcut_action_activate"
(** Activates the action on the @widget with the given @args.

Note that some actions ignore the passed in @flags, @widget or @args.

Activation of an action can fail for various reasons. If the action
is not supported by the @widget, if the @args don't match the action
or if the activation otherwise had no effect, %FALSE will be returned. *)
