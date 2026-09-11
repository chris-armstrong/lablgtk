(* GENERATED CODE - DO NOT EDIT *)
(* ShortcutsWindow: ShortcutsWindow *)

type t =
  [ `shortcuts_window | `window | `widget | `initially_unowned | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_shortcuts_window_get_type"

(* Methods *)

external add_section : t -> Shortcuts_section.t -> unit
  = "ml_gtk_shortcuts_window_add_section"
(** Adds a section to the shortcuts window.

    This is the programmatic equivalent to using [class@Gtk.Builder] and a
    `<child>` tag to add the child.

    Using [method@Gtk.Window.set_child] is not appropriate as the shortcuts
    window manages its children internally. *)

(* Properties *)

external get_section_name : t -> string
  = "ml_gtk_shortcuts_window_get_section_name"
(** Get property: section-name *)

external set_section_name : t -> string -> unit
  = "ml_gtk_shortcuts_window_set_section_name"
(** Set property: section-name *)

external get_view_name : t -> string = "ml_gtk_shortcuts_window_get_view_name"
(** Get property: view-name *)

external set_view_name : t -> string -> unit
  = "ml_gtk_shortcuts_window_set_view_name"
(** Set property: view-name *)

val on_close :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_search :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
