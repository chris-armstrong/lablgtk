(* GENERATED CODE - DO NOT EDIT *)
(* FileLauncher: FileLauncher *)

type t = [ `file_launcher | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_file_launcher_get_type"

external new_ : Ocgtk_gio.Gio.Wrappers.File.t option -> t
  = "ml_gtk_file_launcher_new"
(** Create a new FileLauncher *)

(* Methods *)

external set_writable : t -> bool -> unit = "ml_gtk_file_launcher_set_writable"
(** Sets whether to make the file writable for the handler. *)

external set_file : t -> Ocgtk_gio.Gio.Wrappers.File.t option -> unit
  = "ml_gtk_file_launcher_set_file"
(** Sets the file that will be opened. *)

external set_always_ask : t -> bool -> unit
  = "ml_gtk_file_launcher_set_always_ask"
(** Sets whether to always ask the user which app to use.

    If false, the file might be opened with a default app or the previous
    choice. *)

external open_containing_folder_finish :
  t -> Ocgtk_gio.Gio.Wrappers.Async_result.t -> (bool, GError.t) result
  = "ml_gtk_file_launcher_open_containing_folder_finish"
(** Finishes the [method@Gtk.FileLauncher.open_containing_folder] call and
    returns the result. *)

external launch_finish :
  t -> Ocgtk_gio.Gio.Wrappers.Async_result.t -> (bool, GError.t) result
  = "ml_gtk_file_launcher_launch_finish"
(** Finishes the [method@Gtk.FileLauncher.launch] call and returns the result.
*)

external get_writable : t -> bool = "ml_gtk_file_launcher_get_writable"
(** Returns whether to make the file writable for the handler. *)

external get_file : t -> Ocgtk_gio.Gio.Wrappers.File.t option
  = "ml_gtk_file_launcher_get_file"
(** Gets the file that will be opened. *)

external get_always_ask : t -> bool = "ml_gtk_file_launcher_get_always_ask"
(** Returns whether to ask the user which app to use. *)

(* Properties *)
