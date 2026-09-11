(* GENERATED CODE - DO NOT EDIT *)
(* ShortcutsGroup: ShortcutsGroup *)

type t =
  [ `shortcuts_group | `box | `widget | `initially_unowned | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_shortcuts_group_get_type"

(* Methods *)

external add_shortcut : t -> Shortcuts_shortcut.t -> unit
  = "ml_gtk_shortcuts_group_add_shortcut"
(** Adds a shortcut to the shortcuts group.

    This is the programmatic equivalent to using [class@Gtk.Builder] and a
    `<child>` tag to add the child. Adding children with other API is not
    appropriate as `GtkShortcutsGroup` manages its children internally. *)

(* Properties *)

external set_accel_size_group : t -> Size_group.t -> unit
  = "ml_gtk_shortcuts_group_set_accel_size_group"
(** Set property: accel-size-group *)

external get_height : t -> int = "ml_gtk_shortcuts_group_get_height"
(** Get property: height *)

external get_title : t -> string = "ml_gtk_shortcuts_group_get_title"
(** Get property: title *)

external set_title : t -> string -> unit = "ml_gtk_shortcuts_group_set_title"
(** Set property: title *)

external set_title_size_group : t -> Size_group.t -> unit
  = "ml_gtk_shortcuts_group_set_title_size_group"
(** Set property: title-size-group *)

external get_view : t -> string = "ml_gtk_shortcuts_group_get_view"
(** Get property: view *)

external set_view : t -> string -> unit = "ml_gtk_shortcuts_group_set_view"
(** Set property: view *)
