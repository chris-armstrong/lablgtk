(** Helpers for gating GTK tests by runtime version *)

module GVersion = Ocgtk_gtk.GVersion
module GMain = Ocgtk_gtk.GMain

val gtk_available : bool
(** True if GTK initialised successfully on this system. *)

val require_gtk : (unit -> unit) -> unit -> unit
(** [require_gtk f ()] runs [f ()] only when GTK is available, otherwise skips.
*)

val require_gtk_version : int -> int -> int -> (unit -> unit) -> unit -> unit
(** [require_gtk_version major minor micro f ()] runs [f ()] only when the
    runtime GTK is at least [(major, minor, micro)]; otherwise skips the test.
*)
