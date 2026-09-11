(* GENERATED CODE - DO NOT EDIT *)
(* Calendar: Calendar *)

type t = [ `calendar | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_calendar_get_type"

external new_ : unit -> t = "ml_gtk_calendar_new"
(** Create a new Calendar *)

(* Methods *)

external unmark_day : t -> int -> unit = "ml_gtk_calendar_unmark_day"
(** Removes the visual marker from a particular day. *)

external set_year : t -> int -> unit = "ml_gtk_calendar_set_year"
(** Sets the year for the selected date.

    The new date must be valid. For example, setting the year to 2023 when the
    date is February 29 will fail. *)

external set_show_week_numbers : t -> bool -> unit
  = "ml_gtk_calendar_set_show_week_numbers"
(** Sets whether week numbers are shown in the calendar. *)

external set_show_heading : t -> bool -> unit
  = "ml_gtk_calendar_set_show_heading"
(** Sets whether the calendar should show a heading.

    The heading contains the current year and month as well as buttons for
    changing both. *)

external set_show_day_names : t -> bool -> unit
  = "ml_gtk_calendar_set_show_day_names"
(** Sets whether the calendar shows day names. *)

external set_month : t -> int -> unit = "ml_gtk_calendar_set_month"
(** Sets the month for the selected date.

    The new date must be valid. For example, setting the month to 1 (February)
    when the day is 31 will fail. *)

external set_day : t -> int -> unit = "ml_gtk_calendar_set_day"
(** Sets the day for the selected date.

    The new date must be valid. For example, setting the day to 31 when the
    month is February will fail. *)

external mark_day : t -> int -> unit = "ml_gtk_calendar_mark_day"
(** Places a visual marker on a particular day of the current month. *)

external get_year : t -> int = "ml_gtk_calendar_get_year"
(** Gets the year of the selected date. *)

external get_show_week_numbers : t -> bool
  = "ml_gtk_calendar_get_show_week_numbers"
(** Returns whether @self is showing week numbers right
now.

This is the value of the [property@Gtk.Calendar:show-week-numbers]
property. *)

external get_show_heading : t -> bool = "ml_gtk_calendar_get_show_heading"
(** Returns whether @self is currently showing the heading.

This is the value of the [property@Gtk.Calendar:show-heading]
property. *)

external get_show_day_names : t -> bool = "ml_gtk_calendar_get_show_day_names"
(** Returns whether @self is currently showing the names
of the week days.

This is the value of the [property@Gtk.Calendar:show-day-names]
property. *)

external get_month : t -> int = "ml_gtk_calendar_get_month"
(** Gets the month of the selected date. *)

external get_day_is_marked : t -> int -> bool
  = "ml_gtk_calendar_get_day_is_marked"
(** Returns if the @day of the @calendar is already marked. *)

external get_day : t -> int = "ml_gtk_calendar_get_day"
(** Gets the day of the selected date. *)

external clear_marks : t -> unit = "ml_gtk_calendar_clear_marks"
(** Remove all visual markers. *)

(* Properties *)

val on_day_selected :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_next_month :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_next_year :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_prev_month :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_prev_year :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
