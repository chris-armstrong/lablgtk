(* GENERATED CODE - DO NOT EDIT *)
(* ShortcutController: ShortcutController *)

type t = [ `shortcut_controller | `event_controller | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_shortcut_controller_get_type"

external new_ : unit -> t = "ml_gtk_shortcut_controller_new"
(** Create a new ShortcutController *)

external new_for_model : Ocgtk_gio.Gio.Wrappers.List_model.t -> t
  = "ml_gtk_shortcut_controller_new_for_model"
(** Create a new ShortcutController *)

(* Methods *)

external set_scope : t -> Gtk_enums.shortcutscope -> unit
  = "ml_gtk_shortcut_controller_set_scope"
(** Sets the controller to have the given @scope.

The scope allows shortcuts to be activated outside of the normal
event propagation. In particular, it allows installing global
keyboard shortcuts that can be activated even when a widget does
not have focus.

With %GTK_SHORTCUT_SCOPE_LOCAL, shortcuts will only be activated
when the widget has focus. *)

external set_mnemonics_modifiers : t -> Ocgtk_gdk.Gdk.modifiertype -> unit
  = "ml_gtk_shortcut_controller_set_mnemonics_modifiers"
(** Sets the controller to use the given modifier for mnemonics.

    The mnemonics modifiers determines which modifiers need to be pressed to
    allow activation of shortcuts with mnemonics triggers.

    GTK normally uses the Alt modifier for mnemonics, except in
    `GtkPopoverMenu`s, where mnemonics can be triggered without any modifiers.
    It should be very rarely necessary to change this, and doing so is likely to
    interfere with other shortcuts.

    This value is only relevant for local shortcut controllers. Global and
    managed shortcut controllers will have their shortcuts activated from other
    places which have their own modifiers for activating mnemonics. *)

external remove_shortcut : t -> Shortcut.t -> unit
  = "ml_gtk_shortcut_controller_remove_shortcut"
(** Removes @shortcut from the list of shortcuts handled by @self.

If @shortcut had not been added to @controller or this controller
uses an external shortcut list, this function does nothing. *)

external get_scope : t -> Gtk_enums.shortcutscope
  = "ml_gtk_shortcut_controller_get_scope"
(** Gets the scope for when this controller activates its shortcuts.

    See [method@Gtk.ShortcutController.set_scope] for details. *)

external get_mnemonics_modifiers : t -> Ocgtk_gdk.Gdk.modifiertype
  = "ml_gtk_shortcut_controller_get_mnemonics_modifiers"
(** Gets the mnemonics modifiers for when this controller activates its
    shortcuts. *)

external add_shortcut : t -> Shortcut.t -> unit
  = "ml_gtk_shortcut_controller_add_shortcut"
(** Adds @shortcut to the list of shortcuts handled by @self.

If this controller uses an external shortcut list, this
function does nothing. *)

(* Properties *)

external get_item_type : t -> Gobject.Type.t
  = "ml_gtk_shortcut_controller_get_item_type"
(** Get property: item-type *)

external get_n_items : t -> int = "ml_gtk_shortcut_controller_get_n_items"
(** Get property: n-items *)
