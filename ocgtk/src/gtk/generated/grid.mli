(* GENERATED CODE - DO NOT EDIT *)
(* Grid: Grid *)

type t = [ `grid | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_grid_get_type"

external new_ : unit -> t = "ml_gtk_grid_new"
(** Create a new Grid *)

(* Methods *)

external set_row_spacing : t -> int -> unit = "ml_gtk_grid_set_row_spacing"
(** Sets the amount of space between rows of @grid. *)

external set_row_homogeneous : t -> bool -> unit
  = "ml_gtk_grid_set_row_homogeneous"
(** Sets whether all rows of @grid will have the same height. *)

external set_row_baseline_position :
  t -> int -> Gtk_enums.baselineposition -> unit
  = "ml_gtk_grid_set_row_baseline_position"
(** Sets how the baseline should be positioned on @row of the
grid, in case that row is assigned more space than is requested.

The default baseline position is %GTK_BASELINE_POSITION_CENTER. *)

external set_column_spacing : t -> int -> unit
  = "ml_gtk_grid_set_column_spacing"
(** Sets the amount of space between columns of @grid. *)

external set_column_homogeneous : t -> bool -> unit
  = "ml_gtk_grid_set_column_homogeneous"
(** Sets whether all columns of @grid will have the same width. *)

external set_baseline_row : t -> int -> unit = "ml_gtk_grid_set_baseline_row"
(** Sets which row defines the global baseline for the entire grid.

Each row in the grid can have its own local baseline, but only
one of those is global, meaning it will be the baseline in the
parent of the @grid. *)

external remove_row : t -> int -> unit = "ml_gtk_grid_remove_row"
(** Removes a row from the grid.

    Children that are placed in this row are removed, spanning children that
    overlap this row have their height reduced by one, and children below the
    row are moved up. *)

external remove_column : t -> int -> unit = "ml_gtk_grid_remove_column"
(** Removes a column from the grid.

    Children that are placed in this column are removed, spanning children that
    overlap this column have their width reduced by one, and children after the
    column are moved to the left. *)

external remove :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  unit = "ml_gtk_grid_remove"
(** Removes a child from @grid.

The child must have been added with
[method@Gtk.Grid.attach] or [method@Gtk.Grid.attach_next_to]. *)

external query_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  int * int * int * int = "ml_gtk_grid_query_child"
(** Queries the attach points and spans of @child inside the given `GtkGrid`. *)

external insert_row : t -> int -> unit = "ml_gtk_grid_insert_row"
(** Inserts a row at the specified position.

    Children which are attached at or below this position are moved one row
    down. Children which span across this position are grown to span the new
    row. *)

external insert_next_to :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Gtk_enums.positiontype ->
  unit = "ml_gtk_grid_insert_next_to"
(** Inserts a row or column at the specified position.

The new row or column is placed next to @sibling, on the side
determined by @side. If @side is %GTK_POS_TOP or %GTK_POS_BOTTOM,
a row is inserted. If @side is %GTK_POS_LEFT of %GTK_POS_RIGHT,
a column is inserted. *)

external insert_column : t -> int -> unit = "ml_gtk_grid_insert_column"
(** Inserts a column at the specified position.

    Children which are attached at or to the right of this position are moved
    one column to the right. Children which span across this position are grown
    to span the new column. *)

external get_row_spacing : t -> int = "ml_gtk_grid_get_row_spacing"
(** Returns the amount of space between the rows of @grid. *)

external get_row_homogeneous : t -> bool = "ml_gtk_grid_get_row_homogeneous"
(** Returns whether all rows of @grid have the same height. *)

external get_row_baseline_position : t -> int -> Gtk_enums.baselineposition
  = "ml_gtk_grid_get_row_baseline_position"
(** Returns the baseline position of @row.

See [method@Gtk.Grid.set_row_baseline_position]. *)

external get_column_spacing : t -> int = "ml_gtk_grid_get_column_spacing"
(** Returns the amount of space between the columns of @grid. *)

external get_column_homogeneous : t -> bool
  = "ml_gtk_grid_get_column_homogeneous"
(** Returns whether all columns of @grid have the same width. *)

external get_child_at :
  t ->
  int ->
  int ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_grid_get_child_at"
(** Gets the child of @grid whose area covers the grid
cell at @column, @row. *)

external get_baseline_row : t -> int = "ml_gtk_grid_get_baseline_row"
(** Returns which row defines the global baseline of @grid. *)

external attach_next_to :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  Gtk_enums.positiontype ->
  int ->
  int ->
  unit
  = "ml_gtk_grid_attach_next_to_bytecode" "ml_gtk_grid_attach_next_to_native"
(** Adds a widget to the grid.

The widget is placed next to @sibling, on the side determined by
@side. When @sibling is %NULL, the widget is placed in row (for
left or right placement) or column 0 (for top or bottom placement),
at the end indicated by @side.

Attaching widgets labeled `[1]`, `[2]`, `[3]` with `@sibling == %NULL` and
`@side == %GTK_POS_LEFT` yields a layout of `[3][2][1]`. *)

external attach :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  int ->
  int ->
  int ->
  int ->
  unit = "ml_gtk_grid_attach_bytecode" "ml_gtk_grid_attach_native"
(** Adds a widget to the grid.

The position of @child is determined by @column and @row.
The number of “cells” that @child will occupy is determined
by @width and @height. *)

(* Properties *)
