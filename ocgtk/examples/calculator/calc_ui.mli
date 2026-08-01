open Ocgtk_gtk.Gtk

(** Calculator UI builder.

    The UI handle {!t} is opaque; the calculator executable only needs to
    construct it with {!build} and let the installed signal handlers drive it.
*)

type t

val build : Window.window_t -> t
(** [build window] constructs the calculator UI inside [window], wiring up
    button and keyboard handlers, and returns the UI handle. *)
