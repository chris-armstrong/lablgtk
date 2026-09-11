(* GENERATED CODE - DO NOT EDIT *)
(* TreeSortable: TreeSortable *)

type t = [ `tree_sortable ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_tree_sortable_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gtk_tree_sortable_from_gobject"

(* Methods *)

external sort_column_changed : t -> unit
  = "ml_gtk_tree_sortable_sort_column_changed"
(** Emits a `GtkTreeSortable::sort-column-changed` signal on @sortable. *)

external set_sort_column_id : t -> int -> Gtk_enums.sorttype -> unit
  = "ml_gtk_tree_sortable_set_sort_column_id"
(** Sets the current sort column to be @sort_column_id. The @sortable will
resort itself to reflect this change, after emitting a
`GtkTreeSortable::sort-column-changed` signal. @sort_column_id may either be
a regular column id, or one of the following special values:

- %GTK_TREE_SORTABLE_DEFAULT_SORT_COLUMN_ID: the default sort function
  will be used, if it is set

- %GTK_TREE_SORTABLE_UNSORTED_SORT_COLUMN_ID: no sorting will occur *)

external has_default_sort_func : t -> bool
  = "ml_gtk_tree_sortable_has_default_sort_func"
(** Returns %TRUE if the model has a default sort function. This is used
    primarily by GtkTreeViewColumns in order to determine if a model can go back
    to the default state, or not. *)

external get_sort_column_id : t -> bool * int * Gtk_enums.sorttype
  = "ml_gtk_tree_sortable_get_sort_column_id"
(** Fills in @sort_column_id and @order with the current sort column and the
order. It returns %TRUE unless the @sort_column_id is
%GTK_TREE_SORTABLE_DEFAULT_SORT_COLUMN_ID or
%GTK_TREE_SORTABLE_UNSORTED_SORT_COLUMN_ID. *)

val on_sort_column_changed :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
