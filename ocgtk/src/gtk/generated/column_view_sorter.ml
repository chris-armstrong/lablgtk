(* GENERATED CODE - DO NOT EDIT *)
(* ColumnViewSorter: ColumnViewSorter *)

type t = [ `column_view_sorter | `sorter | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_column_view_sorter_get_type"

(* Methods *)

external get_primary_sort_order : t -> Gtk_enums.sorttype
  = "ml_gtk_column_view_sorter_get_primary_sort_order"
(** Returns the primary sort order.

    The primary sort order determines whether the triangle displayed in the
    column view header of the primary sort column points upwards or downwards.

    If there is no primary sort column, then this function returns
    `GTK_SORT_ASCENDING`. *)

external get_primary_sort_column :
  t -> Column_view_and__column_view_column.Column_view_column.t option
  = "ml_gtk_column_view_sorter_get_primary_sort_column"
(** Returns the primary sort column.

    The primary sort column is the one that displays the triangle in a column
    view header. *)

external get_nth_sort_column :
  t ->
  int ->
  Column_view_and__column_view_column.Column_view_column.t option
  * Gtk_enums.sorttype = "ml_gtk_column_view_sorter_get_nth_sort_column"
(** Gets the @position'th sort column and its associated sort order.

Use the [signal@Gtk.Sorter::changed] signal to get notified
when sort columns change. *)

external get_n_sort_columns : t -> int
  = "ml_gtk_column_view_sorter_get_n_sort_columns"
(** Returns the number of columns by which the sorter sorts.

    If the sorter of the primary sort column does not determine a total order,
    then the secondary sorters are consulted to break the ties.

    Use the [signal@Gtk.Sorter::changed] signal to get notified when the number
    of sort columns changes. *)

(* Properties *)
