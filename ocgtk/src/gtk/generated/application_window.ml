(* GENERATED CODE - DO NOT EDIT *)
(* ApplicationWindow: ApplicationWindow *)

type t =
  [ `application_window | `window | `widget | `initially_unowned | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_application_window_get_type"

external new_ : Application_and__window_and__window_group.Application.t -> t
  = "ml_gtk_application_window_new"
(** Create a new ApplicationWindow *)

(* Methods *)

external set_show_menubar : t -> bool -> unit
  = "ml_gtk_application_window_set_show_menubar"
(** Sets whether the window will display a menubar for the app menu and menubar
    as needed. *)

external set_help_overlay : t -> Shortcuts_window.t option -> unit
  = "ml_gtk_application_window_set_help_overlay"
(** Associates a shortcuts window with the application window.

    Additionally, sets up an action with the name `win.show-help-overlay` to
    present it.

    The window takes responsibility for destroying the help overlay. *)

external get_show_menubar : t -> bool
  = "ml_gtk_application_window_get_show_menubar"
(** Returns whether the window will display a menubar for the app menu and
    menubar as needed. *)

external get_id : t -> int = "ml_gtk_application_window_get_id"
(** Returns the unique ID of the window.

    If the window has not yet been added to a `GtkApplication`, returns `0`. *)

external get_help_overlay : t -> Shortcuts_window.t option
  = "ml_gtk_application_window_get_help_overlay"
(** Gets the `GtkShortcutsWindow` that is associated with @window.

See [method@Gtk.ApplicationWindow.set_help_overlay]. *)

(* Properties *)
