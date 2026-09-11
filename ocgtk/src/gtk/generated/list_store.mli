(* GENERATED CODE - DO NOT EDIT *)
(* ListStore: ListStore *)

type t = [ `list_store | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_list_store_get_type"

external newv : int -> Gobject.Type.t array -> t = "ml_gtk_list_store_newv"
(** Create a new ListStore *)

(* Methods *)

external swap : t -> Tree_iter.t -> Tree_iter.t -> unit
  = "ml_gtk_list_store_swap"
(** Swaps @a and @b in @store. Note that this function only works with
unsorted stores. *)

external set_valuesv :
  t -> Tree_iter.t -> int array -> Gobject.Value.t array -> int -> unit
  = "ml_gtk_list_store_set_valuesv"
(** A variant of gtk_list_store_set_valist() which takes the columns and values
    as two arrays, instead of varargs. This function is mainly intended for
    language-bindings and in case the number of columns to change is not known
    until run-time. *)

external set_value : t -> Tree_iter.t -> int -> Gobject.Value.t -> unit
  = "ml_gtk_list_store_set_value"
(** Sets the data in the cell specified by @iter and @column.
The type of @value must be convertible to the type of the
column. *)

external set_column_types : t -> int -> Gobject.Type.t array -> unit
  = "ml_gtk_list_store_set_column_types"
(** Sets the types of the columns of a list store.

    This function is meant primarily for objects that inherit from
    `GtkListStore`, and should only be used when constructing a new instance.

    This function cannot be called after a row has been added, or a method on
    the `GtkTreeModel` interface is called. *)

external remove : t -> Tree_iter.t -> bool = "ml_gtk_list_store_remove"
(** Removes the given row from the list store.  After being removed,
@iter is set to be the next valid row, or invalidated if it pointed
to the last row in @list_store. *)

external prepend : t -> Tree_iter.t = "ml_gtk_list_store_prepend"
(** Prepends a new row to @list_store. @iter will be changed to point to this new
row. The row will be empty after this function is called. To fill in
values, you need to call gtk_list_store_set() or gtk_list_store_set_value(). *)

external move_before : t -> Tree_iter.t -> Tree_iter.t option -> unit
  = "ml_gtk_list_store_move_before"
(** Moves @iter in @store to the position before @position. Note that this
function only works with unsorted stores. If @position is %NULL, @iter
will be moved to the end of the list. *)

external move_after : t -> Tree_iter.t -> Tree_iter.t option -> unit
  = "ml_gtk_list_store_move_after"
(** Moves @iter in @store to the position after @position. Note that this
function only works with unsorted stores. If @position is %NULL, @iter
will be moved to the start of the list. *)

external iter_is_valid : t -> Tree_iter.t -> bool
  = "ml_gtk_list_store_iter_is_valid"
(** Checks if the given iter is a valid iter for this `GtkListStore`.

    This function is slow. Only use it for debugging and/or testing purposes. *)

external insert_with_valuesv :
  t -> int -> int array -> Gobject.Value.t array -> int -> Tree_iter.t
  = "ml_gtk_list_store_insert_with_valuesv"
(** A variant of gtk_list_store_insert_with_values() which takes the columns and
    values as two arrays, instead of varargs.

    This function is mainly intended for language-bindings. *)

external insert_before : t -> Tree_iter.t option -> Tree_iter.t
  = "ml_gtk_list_store_insert_before"
(** Inserts a new row before @sibling. If @sibling is %NULL, then the row will
be appended to the end of the list. @iter will be changed to point to this
new row. The row will be empty after this function is called. To fill in
values, you need to call gtk_list_store_set() or gtk_list_store_set_value(). *)

external insert_after : t -> Tree_iter.t option -> Tree_iter.t
  = "ml_gtk_list_store_insert_after"
(** Inserts a new row after @sibling. If @sibling is %NULL, then the row will be
prepended to the beginning of the list. @iter will be changed to point to
this new row. The row will be empty after this function is called. To fill
in values, you need to call gtk_list_store_set() or gtk_list_store_set_value(). *)

external insert : t -> int -> Tree_iter.t = "ml_gtk_list_store_insert"
(** Creates a new row at @position.  @iter will be changed to point to this new
row.  If @position is -1 or is larger than the number of rows on the list,
then the new row will be appended to the list. The row will be empty after
this function is called.  To fill in values, you need to call
gtk_list_store_set() or gtk_list_store_set_value(). *)

external clear : t -> unit = "ml_gtk_list_store_clear"
(** Removes all rows from the list store. *)

external append : t -> Tree_iter.t = "ml_gtk_list_store_append"
(** Appends a new row to @list_store.  @iter will be changed to point to this new
row.  The row will be empty after this function is called.  To fill in
values, you need to call gtk_list_store_set() or gtk_list_store_set_value(). *)
