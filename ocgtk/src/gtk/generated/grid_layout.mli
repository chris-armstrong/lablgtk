(* GENERATED CODE - DO NOT EDIT *)
(* GridLayout: GridLayout *)

type t = [ `grid_layout | `layout_manager | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_grid_layout_get_type"

external new_ : unit -> t = "ml_gtk_grid_layout_new"
(** Create a new GridLayout *)

(* Methods *)

external set_row_spacing : t -> int -> unit
  = "ml_gtk_grid_layout_set_row_spacing"
(** Sets the amount of space to insert between consecutive rows. *)

external set_row_homogeneous : t -> bool -> unit
  = "ml_gtk_grid_layout_set_row_homogeneous"
(** Sets whether all rows of @grid should have the same height. *)

external set_row_baseline_position :
  t -> int -> Gtk_enums.baselineposition -> unit
  = "ml_gtk_grid_layout_set_row_baseline_position"
(** Sets how the baseline should be positioned on @row of the
grid, in case that row is assigned more space than is requested. *)

external set_column_spacing : t -> int -> unit
  = "ml_gtk_grid_layout_set_column_spacing"
(** Sets the amount of space to insert between consecutive columns. *)

external set_column_homogeneous : t -> bool -> unit
  = "ml_gtk_grid_layout_set_column_homogeneous"
(** Sets whether all columns of @grid should have the same width. *)

external set_baseline_row : t -> int -> unit
  = "ml_gtk_grid_layout_set_baseline_row"
(** Sets which row defines the global baseline for the entire grid.

Each row in the grid can have its own local baseline, but only
one of those is global, meaning it will be the baseline in the
parent of the @grid. *)

external get_row_spacing : t -> int = "ml_gtk_grid_layout_get_row_spacing"
(** Retrieves the spacing set with gtk_grid_layout_set_row_spacing(). *)

external get_row_homogeneous : t -> bool
  = "ml_gtk_grid_layout_get_row_homogeneous"
(** Checks whether all rows of @grid should have the same height. *)

external get_row_baseline_position : t -> int -> Gtk_enums.baselineposition
  = "ml_gtk_grid_layout_get_row_baseline_position"
(** Returns the baseline position of @row.

If no value has been set with
[method@Gtk.GridLayout.set_row_baseline_position],
the default value of %GTK_BASELINE_POSITION_CENTER
is returned. *)

external get_column_spacing : t -> int = "ml_gtk_grid_layout_get_column_spacing"
(** Retrieves the spacing set with gtk_grid_layout_set_column_spacing(). *)

external get_column_homogeneous : t -> bool
  = "ml_gtk_grid_layout_get_column_homogeneous"
(** Checks whether all columns of @grid should have the same width. *)

external get_baseline_row : t -> int = "ml_gtk_grid_layout_get_baseline_row"
(** Retrieves the row set with gtk_grid_layout_set_baseline_row(). *)

(* Properties *)
