(* GENERATED CODE - DO NOT EDIT *)
(* PadController: PadController *)

type t = [ `pad_controller | `event_controller | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_pad_controller_get_type"

external new_ :
  Ocgtk_gio.Gio.Wrappers.Action_group.t ->
  Ocgtk_gdk.Gdk.Wrappers.Device.t option ->
  t = "ml_gtk_pad_controller_new"
(** Create a new PadController *)

(* Methods *)

external set_action_entries : t -> Pad_action_entry.t array -> int -> unit
  = "ml_gtk_pad_controller_set_action_entries"
(** A convenience function to add a group of action entries on
@controller.

See [struct@Gtk.PadActionEntry] and [method@Gtk.PadController.set_action]. *)

external set_action :
  t -> Gtk_enums.padactiontype -> int -> int -> string -> string -> unit
  = "ml_gtk_pad_controller_set_action_bytecode"
    "ml_gtk_pad_controller_set_action_native"
(** Adds an individual action to @controller.

This action will only be activated if the given button/ring/strip number
in @index is interacted while the current mode is @mode. -1 may be used
for simple cases, so the action is triggered on all modes.

The given @label should be considered user-visible, so internationalization
rules apply. Some windowing systems may be able to use those for user
feedback. *)

(* Properties *)

external get_action_group : t -> Ocgtk_gio.Gio.Wrappers.Action_group.t
  = "ml_gtk_pad_controller_get_action_group"
(** Get property: action-group *)

external get_pad : t -> Ocgtk_gdk.Gdk.Wrappers.Device.t
  = "ml_gtk_pad_controller_get_pad"
(** Get property: pad *)
