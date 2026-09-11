(* GENERATED CODE - DO NOT EDIT *)
(* TreeStore: TreeStore *)

type t = [ `tree_store | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_tree_store_get_type"

external newv : int -> Gobject.Type.t array -> t = "ml_gtk_tree_store_newv"
(** Create a new TreeStore *)

(* Methods *)

external swap : t -> Tree_iter.t -> Tree_iter.t -> unit
  = "ml_gtk_tree_store_swap"
(** Swaps @a and @b in the same level of @tree_store.

Note that this function only works with unsorted stores. *)

external set_valuesv :
  t -> Tree_iter.t -> int array -> Gobject.Value.t array -> int -> unit
  = "ml_gtk_tree_store_set_valuesv"
(** A variant of gtk_tree_store_set_valist() which takes the columns and values
    as two arrays, instead of using variadic arguments.

    This function is mainly intended for language bindings or in case the number
    of columns to change is not known until run-time. *)

external set_value : t -> Tree_iter.t -> int -> Gobject.Value.t -> unit
  = "ml_gtk_tree_store_set_value"
(** Sets the data in the cell specified by @iter and @column.

The type of @value must be convertible to the type of the
column. *)

external set_column_types : t -> int -> Gobject.Type.t array -> unit
  = "ml_gtk_tree_store_set_column_types"
(** Sets the type of the columns in a tree store.

    This function is meant primarily for types that inherit from `GtkTreeStore`,
    and should only be used when constructing a new `GtkTreeStore`.

    This functions cannot be called after a row has been added, or a method on
    the `GtkTreeModel` interface is called on the tree store. *)

external remove : t -> Tree_iter.t -> bool = "ml_gtk_tree_store_remove"
(** Removes @iter from @tree_store.

After being removed, @iter is set to the next valid row at that level, or
invalidated if it previously pointed to the last one. *)

external prepend : t -> Tree_iter.t option -> Tree_iter.t
  = "ml_gtk_tree_store_prepend"
(** Prepends a new row to @tree_store.

If @parent is non-%NULL, then it will prepend the new row before the first
child of @parent, otherwise it will prepend a row to the top level. The
`iter` parameter will be changed to point to this new row.  The row will
be empty after this function is called. To fill in values, you need to
call gtk_tree_store_set() or gtk_tree_store_set_value(). *)

external move_before : t -> Tree_iter.t -> Tree_iter.t option -> unit
  = "ml_gtk_tree_store_move_before"
(** Moves @iter in @tree_store to the position before @position.

@iter and @position should be in the same level.

Note that this function only works with unsorted stores.

If @position is %NULL, @iter will be moved to the end of the level. *)

external move_after : t -> Tree_iter.t -> Tree_iter.t option -> unit
  = "ml_gtk_tree_store_move_after"
(** Moves @iter in @tree_store to the position after @position.

@iter and @position should be in the same level.

Note that this function only works with unsorted stores.

If @position is %NULL, @iter will be moved to the start of the level. *)

external iter_is_valid : t -> Tree_iter.t -> bool
  = "ml_gtk_tree_store_iter_is_valid"
(** Checks if the given iter is a valid iter for this `GtkTreeStore`.

    This function is slow. Only use it for debugging and/or testing purposes. *)

external iter_depth : t -> Tree_iter.t -> int = "ml_gtk_tree_store_iter_depth"
(** Returns the depth of the position pointed by the iterator

    The depth will be 0 for anything on the root level, 1 for anything down a
    level, etc. *)

external is_ancestor : t -> Tree_iter.t -> Tree_iter.t -> bool
  = "ml_gtk_tree_store_is_ancestor"
(** Checks if @iter is an ancestor of @descendant. *)

external insert_with_valuesv :
  t ->
  Tree_iter.t option ->
  int ->
  int array ->
  Gobject.Value.t array ->
  int ->
  Tree_iter.t
  = "ml_gtk_tree_store_insert_with_valuesv_bytecode"
    "ml_gtk_tree_store_insert_with_valuesv_native"
(** A variant of gtk_tree_store_insert_with_values() which takes the columns and
    values as two arrays, instead of varargs.

    This function is mainly intended for language bindings. *)

external insert_before :
  t -> Tree_iter.t option -> Tree_iter.t option -> Tree_iter.t
  = "ml_gtk_tree_store_insert_before"
(** Inserts a new row before @sibling.

If @sibling is %NULL, then the row will be appended to @parent’s children.

If @parent and @sibling are %NULL, then the row will be appended to the
toplevel.

If both @sibling and @parent are set, then @parent must be the parent
of @sibling. When @sibling is set, @parent is optional.

The @iter parameter will be changed to point to this new row. The row will
be empty after this function is called. To fill in values, you need to call
gtk_tree_store_set() or gtk_tree_store_set_value(). *)

external insert_after :
  t -> Tree_iter.t option -> Tree_iter.t option -> Tree_iter.t
  = "ml_gtk_tree_store_insert_after"
(** Inserts a new row after @sibling.

If @sibling is %NULL, then the row will be prepended to @parent’s children.

If @parent and @sibling are %NULL, then the row will be prepended to the
toplevel.

If both @sibling and @parent are set, then @parent must be the parent
of @sibling. When @sibling is set, @parent is optional.

The @iter parameter will be changed to point to this new row. The row will
be empty after this function is called. To fill in values, you need to call
gtk_tree_store_set() or gtk_tree_store_set_value(). *)

external insert : t -> Tree_iter.t option -> int -> Tree_iter.t
  = "ml_gtk_tree_store_insert"
(** Creates a new row at @position.

If parent is non-%NULL, then the row will be made a child of @parent.
Otherwise, the row will be created at the toplevel.

If @position is `-1` or is larger than the number of rows at that level,
then the new row will be inserted to the end of the list.

The @iter parameter will be changed to point to this new row. The row
will be empty after this function is called. To fill in values, you
need to call gtk_tree_store_set() or gtk_tree_store_set_value(). *)

external clear : t -> unit = "ml_gtk_tree_store_clear"
(** Removes all rows from @tree_store *)

external append : t -> Tree_iter.t option -> Tree_iter.t
  = "ml_gtk_tree_store_append"
(** Appends a new row to @tree_store.

If @parent is non-%NULL, then it will append the new row after the last
child of @parent, otherwise it will append a row to the top level.

The @iter parameter will be changed to point to this new row. The row will
be empty after this function is called. To fill in values, you need to call
gtk_tree_store_set() or gtk_tree_store_set_value(). *)
