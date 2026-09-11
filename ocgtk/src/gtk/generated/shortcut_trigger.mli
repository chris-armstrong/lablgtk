(* GENERATED CODE - DO NOT EDIT *)
(* ShortcutTrigger: ShortcutTrigger *)

type t = [ `shortcut_trigger | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_shortcut_trigger_get_type"

external parse_string : string -> t = "ml_gtk_shortcut_trigger_parse_string"
(** Create a new ShortcutTrigger *)

(* Methods *)

external trigger :
  t -> Ocgtk_gdk.Gdk.Wrappers.Event.t -> bool -> Ocgtk_gdk.Gdk.keymatch
  = "ml_gtk_shortcut_trigger_trigger"
(** Checks if the given @event triggers @self. *)

external to_string : t -> string = "ml_gtk_shortcut_trigger_to_string"
(** Prints the given trigger into a human-readable string.

    This is a small wrapper around [method@Gtk.ShortcutTrigger.print] to help
    when debugging. *)

external to_label : t -> Ocgtk_gdk.Gdk.Wrappers.Display.t -> string
  = "ml_gtk_shortcut_trigger_to_label"
(** Gets textual representation for the given trigger.

This function is returning a translated string for
presentation to end users for example in menu items
or in help texts.

The @display in use may influence the resulting string in
various forms, such as resolving hardware keycodes or by
causing display-specific modifier names.

The form of the representation may change at any time and is
not guaranteed to stay identical. *)

external hash : t -> int = "ml_gtk_shortcut_trigger_hash"
(** Generates a hash value for a `GtkShortcutTrigger`.

The output of this function is guaranteed to be the same for a given
value only per-process. It may change between different processor
architectures or even different versions of GTK. Do not use this
function as a basis for building protocols or file formats.

The types of @trigger is `gconstpointer` only to allow use of this
function with `GHashTable`. They must each be a `GtkShortcutTrigger`. *)

external equal : t -> t -> bool = "ml_gtk_shortcut_trigger_equal"
(** Checks if @trigger1 and @trigger2 trigger under the same conditions.

The types of @one and @two are `gconstpointer` only to allow use of this
function with `GHashTable`. They must each be a `GtkShortcutTrigger`. *)

external compare : t -> t -> int = "ml_gtk_shortcut_trigger_compare"
(** The types of @trigger1 and @trigger2 are `gconstpointer` only to allow
use of this function as a `GCompareFunc`.

They must each be a `GtkShortcutTrigger`. *)
