(* GENERATED CODE - DO NOT EDIT *)
(* ColorChooser: ColorChooser *)

type t = [ `color_chooser ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_color_chooser_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gtk_color_chooser_from_gobject"

(* Methods *)

external set_use_alpha : t -> bool -> unit
  = "ml_gtk_color_chooser_set_use_alpha"
(** Sets whether or not the color chooser should use the alpha channel. *)

external set_rgba : t -> Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t -> unit
  = "ml_gtk_color_chooser_set_rgba"
(** Sets the color. *)

external get_use_alpha : t -> bool = "ml_gtk_color_chooser_get_use_alpha"
(** Returns whether the color chooser shows the alpha channel. *)

external get_rgba : t -> Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t
  = "ml_gtk_color_chooser_get_rgba"
(** Gets the currently-selected color. *)

external add_palette :
  t ->
  Gtk_enums.orientation ->
  int ->
  int ->
  Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t array option ->
  unit = "ml_gtk_color_chooser_add_palette"
(** Adds a palette to the color chooser.

If @orientation is horizontal, the colors are grouped in rows,
with @colors_per_line colors in each row. If @horizontal is %FALSE,
the colors are grouped in columns instead.

The default color palette of [class@Gtk.ColorChooserWidget] has
45 colors, organized in columns of 5 colors (this includes some
grays).

The layout of the color chooser widget works best when the
palettes have 9-10 columns.

Calling this function for the first time has the side effect
of removing the default color palette from the color chooser.

If @colors is %NULL, removes all previously added palettes. *)

(* Properties *)
