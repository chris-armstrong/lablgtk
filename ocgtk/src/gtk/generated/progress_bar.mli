(* GENERATED CODE - DO NOT EDIT *)
(* ProgressBar: ProgressBar *)

type t = [ `progress_bar | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_progress_bar_get_type"

external new_ : unit -> t = "ml_gtk_progress_bar_new"
(** Create a new ProgressBar *)

(* Methods *)

external set_text : t -> string option -> unit = "ml_gtk_progress_bar_set_text"
(** Causes the given @text to appear next to the progress bar.

If @text is %NULL and [property@Gtk.ProgressBar:show-text] is %TRUE,
the current value of [property@Gtk.ProgressBar:fraction] will be displayed
as a percentage.

If @text is non-%NULL and [property@Gtk.ProgressBar:show-text] is %TRUE,
the text will be displayed. In this case, it will not display the progress
percentage. If @text is the empty string, the progress bar will still
be styled and sized suitably for containing text, as long as
[property@Gtk.ProgressBar:show-text] is %TRUE. *)

external set_show_text : t -> bool -> unit = "ml_gtk_progress_bar_set_show_text"
(** Sets whether the progress bar will show text next to the bar.

    The shown text is either the value of the [property@Gtk.ProgressBar:text]
    property or, if that is %NULL, the [property@Gtk.ProgressBar:fraction]
    value, as a percentage.

    To make a progress bar that is styled and sized suitably for containing text
    (even if the actual text is blank), set [property@Gtk.ProgressBar:show-text]
    to %TRUE and [property@Gtk.ProgressBar:text] to the empty string (not
    %NULL). *)

external set_pulse_step : t -> float -> unit
  = "ml_gtk_progress_bar_set_pulse_step"
(** Sets the fraction of total progress bar length to move the bouncing block.

    The bouncing block is moved when [method@Gtk.ProgressBar.pulse] is called.
*)

external set_inverted : t -> bool -> unit = "ml_gtk_progress_bar_set_inverted"
(** Sets whether the progress bar is inverted.

    Progress bars normally grow from top to bottom or left to right. Inverted
    progress bars grow in the opposite direction. *)

external set_fraction : t -> float -> unit = "ml_gtk_progress_bar_set_fraction"
(** Causes the progress bar to “fill in” the given fraction of the bar.

    The fraction should be between 0.0 and 1.0, inclusive. *)

external set_ellipsize : t -> Ocgtk_pango.Pango.ellipsizemode -> unit
  = "ml_gtk_progress_bar_set_ellipsize"
(** Sets the mode used to ellipsize the text.

    The text is ellipsized if there is not enough space to render the entire
    string. *)

external pulse : t -> unit = "ml_gtk_progress_bar_pulse"
(** Indicates that some progress has been made, but you don’t know how much.

    Causes the progress bar to enter “activity mode,” where a block bounces back
    and forth. Each call to [method@Gtk.ProgressBar.pulse] causes the block to
    move by a little bit (the amount of movement per pulse is determined by
    [method@Gtk.ProgressBar.set_pulse_step]). *)

external get_text : t -> string option = "ml_gtk_progress_bar_get_text"
(** Retrieves the text that is displayed with the progress bar.

    The return value is a reference to the text, not a copy of it, so will
    become invalid if you change the text in the progress bar. *)

external get_show_text : t -> bool = "ml_gtk_progress_bar_get_show_text"
(** Returns whether the `GtkProgressBar` shows text.

    See [method@Gtk.ProgressBar.set_show_text]. *)

external get_pulse_step : t -> float = "ml_gtk_progress_bar_get_pulse_step"
(** Retrieves the pulse step.

    See [method@Gtk.ProgressBar.set_pulse_step]. *)

external get_inverted : t -> bool = "ml_gtk_progress_bar_get_inverted"
(** Returns whether the progress bar is inverted. *)

external get_fraction : t -> float = "ml_gtk_progress_bar_get_fraction"
(** Returns the current fraction of the task that’s been completed. *)

external get_ellipsize : t -> Ocgtk_pango.Pango.ellipsizemode
  = "ml_gtk_progress_bar_get_ellipsize"
(** Returns the ellipsizing position of the progress bar.

    See [method@Gtk.ProgressBar.set_ellipsize]. *)

(* Properties *)
