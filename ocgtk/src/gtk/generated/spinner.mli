(* GENERATED CODE - DO NOT EDIT *)
(* Spinner: Spinner *)

type t = [ `spinner | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_spinner_get_type"

external new_ : unit -> t = "ml_gtk_spinner_new"
(** Create a new Spinner *)

(* Methods *)

external stop : t -> unit = "ml_gtk_spinner_stop"
(** Stops the animation of the spinner. *)

external start : t -> unit = "ml_gtk_spinner_start"
(** Starts the animation of the spinner. *)

external set_spinning : t -> bool -> unit = "ml_gtk_spinner_set_spinning"
(** Sets the activity of the spinner. *)

external get_spinning : t -> bool = "ml_gtk_spinner_get_spinning"
(** Returns whether the spinner is spinning. *)

(* Properties *)
