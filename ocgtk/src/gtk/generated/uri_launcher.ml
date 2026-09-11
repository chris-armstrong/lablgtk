(* GENERATED CODE - DO NOT EDIT *)
(* UriLauncher: UriLauncher *)

type t = [ `uri_launcher | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_uri_launcher_get_type"

external new_ : string option -> t = "ml_gtk_uri_launcher_new"
(** Create a new UriLauncher *)

(* Methods *)

external set_uri : t -> string option -> unit = "ml_gtk_uri_launcher_set_uri"
(** Sets the uri that will be opened. *)

external launch_finish :
  t -> Ocgtk_gio.Gio.Wrappers.Async_result.t -> (bool, GError.t) result
  = "ml_gtk_uri_launcher_launch_finish"
(** Finishes the [method@Gtk.UriLauncher.launch] call and returns the result. *)

external get_uri : t -> string option = "ml_gtk_uri_launcher_get_uri"
(** Gets the uri that will be opened. *)

external can_launch :
  t -> Application_and__window_and__window_group.Window.t option -> bool
  = "ml_gtk_uri_launcher_can_launch"
(** Returns whether the launcher is likely to succeed in launching an
    application for its uri.

    This can be used to disable controls that trigger the launcher when they are
    known not to work. *)

(* Properties *)
