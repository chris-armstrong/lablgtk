(* GENERATED CODE - DO NOT EDIT *)
(* TreeModel: TreeModel *)

type t = [ `tree_model ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_tree_model_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gtk_tree_model_from_gobject"

(* Methods *)

external unref_node : t -> Tree_iter.t -> unit = "ml_gtk_tree_model_unref_node"
(** Lets the tree unref the node.

    This is an optional method for models to implement. To be more specific,
    models may ignore this call as it exists primarily for performance reasons.
    For more information on what this means, see gtk_tree_model_ref_node().

    Please note that nodes that are deleted are not unreffed. *)

external rows_reordered_with_length :
  t -> Tree_path.t -> Tree_iter.t option -> int array -> int -> unit
  = "ml_gtk_tree_model_rows_reordered_with_length"
(** Emits the ::rows-reordered signal on @tree_model.

See [signal@Gtk.TreeModel::rows-reordered].

This should be called by models when their rows have been
reordered. *)

external row_inserted : t -> Tree_path.t -> Tree_iter.t -> unit
  = "ml_gtk_tree_model_row_inserted"
(** Emits the ::row-inserted signal on @tree_model.

See [signal@Gtk.TreeModel::row-inserted]. *)

external row_has_child_toggled : t -> Tree_path.t -> Tree_iter.t -> unit
  = "ml_gtk_tree_model_row_has_child_toggled"
(** Emits the ::row-has-child-toggled signal on @tree_model.

See [signal@Gtk.TreeModel::row-has-child-toggled].

This should be called by models after the child
state of a node changes. *)

external row_deleted : t -> Tree_path.t -> unit
  = "ml_gtk_tree_model_row_deleted"
(** Emits the ::row-deleted signal on @tree_model.

See [signal@Gtk.TreeModel::row-deleted].

This should be called by models after a row has been removed.
The location pointed to by @path should be the location that
the row previously was at. It may not be a valid location anymore.

Nodes that are deleted are not unreffed, this means that any
outstanding references on the deleted node should not be released. *)

external row_changed : t -> Tree_path.t -> Tree_iter.t -> unit
  = "ml_gtk_tree_model_row_changed"
(** Emits the ::row-changed signal on @tree_model.

See [signal@Gtk.TreeModel::row-changed]. *)

external ref_node : t -> Tree_iter.t -> unit = "ml_gtk_tree_model_ref_node"
(** Lets the tree ref the node.

    This is an optional method for models to implement. To be more specific,
    models may ignore this call as it exists primarily for performance reasons.

    This function is primarily meant as a way for views to let caching models
    know when nodes are being displayed (and hence, whether or not to cache that
    node). Being displayed means a node is in an expanded branch, regardless of
    whether the node is currently visible in the viewport. For example, a
    file-system based model would not want to keep the entire file-hierarchy in
    memory, just the sections that are currently being displayed by every
    current view.

    A model should be expected to be able to get an iter independent of its
    reffed state. *)

external iter_previous : t -> Tree_iter.t -> bool
  = "ml_gtk_tree_model_iter_previous"
(** Sets @iter to point to the previous node at the current level.

If there is no previous @iter, %FALSE is returned and @iter is
set to be invalid. *)

external iter_parent : t -> Tree_iter.t -> bool * Tree_iter.t
  = "ml_gtk_tree_model_iter_parent"
(** Sets @iter to be the parent of @child.

If @child is at the toplevel, and doesn’t have a parent, then
@iter is set to an invalid iterator and %FALSE is returned.
@child will remain a valid node after this function has been
called.

@iter will be initialized before the lookup is performed, so @child
and @iter cannot point to the same memory location. *)

external iter_nth_child : t -> Tree_iter.t option -> int -> bool * Tree_iter.t
  = "ml_gtk_tree_model_iter_nth_child"
(** Sets @iter to be the child of @parent, using the given index.

The first index is 0. If @n is too big, or @parent has no children,
@iter is set to an invalid iterator and %FALSE is returned. @parent
will remain a valid node after this function has been called. As a
special case, if @parent is %NULL, then the @n-th root node
is set. *)

external iter_next : t -> Tree_iter.t -> bool = "ml_gtk_tree_model_iter_next"
(** Sets @iter to point to the node following it at the current level.

If there is no next @iter, %FALSE is returned and @iter is set
to be invalid. *)

external iter_n_children : t -> Tree_iter.t option -> int
  = "ml_gtk_tree_model_iter_n_children"
(** Returns the number of children that @iter has.

As a special case, if @iter is %NULL, then the number
of toplevel nodes is returned. *)

external iter_has_child : t -> Tree_iter.t -> bool
  = "ml_gtk_tree_model_iter_has_child"
(** Returns %TRUE if @iter has children, %FALSE otherwise. *)

external iter_children : t -> Tree_iter.t option -> bool * Tree_iter.t
  = "ml_gtk_tree_model_iter_children"
(** Sets @iter to point to the first child of @parent.

If @parent has no children, %FALSE is returned and @iter is
set to be invalid. @parent will remain a valid node after this
function has been called.

If @parent is %NULL returns the first node, equivalent to
`gtk_tree_model_get_iter_first (tree_model, iter);` *)

external get_value : t -> Tree_iter.t -> int -> Gobject.Value.t
  = "ml_gtk_tree_model_get_value"
(** Initializes and sets @value to that at @column.

When done with @value, g_value_unset() needs to be called
to free any allocated memory. *)

external get_string_from_iter : t -> Tree_iter.t -> string option
  = "ml_gtk_tree_model_get_string_from_iter"
(** Generates a string representation of the iter.

    This string is a “:” separated list of numbers. For example, “4:10:0:3”
    would be an acceptable return value for this string. *)

external get_path : t -> Tree_iter.t -> Tree_path.t
  = "ml_gtk_tree_model_get_path"
(** Returns a newly-created `GtkTreePath` referenced by @iter.

This path should be freed with gtk_tree_path_free(). *)

external get_n_columns : t -> int = "ml_gtk_tree_model_get_n_columns"
(** Returns the number of columns supported by @tree_model. *)

external get_iter_from_string : t -> string -> bool * Tree_iter.t
  = "ml_gtk_tree_model_get_iter_from_string"
(** Sets @iter to a valid iterator pointing to @path_string, if it
exists.

Otherwise, @iter is left invalid and %FALSE is returned. *)

external get_iter_first : t -> bool * Tree_iter.t
  = "ml_gtk_tree_model_get_iter_first"
(** Initializes @iter with the first iterator in the tree
(the one at the path "0").

Returns %FALSE if the tree is empty, %TRUE otherwise. *)

external get_iter : t -> Tree_path.t -> bool * Tree_iter.t
  = "ml_gtk_tree_model_get_iter"
(** Sets @iter to a valid iterator pointing to @path.

If @path does not exist, @iter is set to an invalid
iterator and %FALSE is returned. *)

external get_flags : t -> Gtk_enums.treemodelflags
  = "ml_gtk_tree_model_get_flags"
(** Returns a set of flags supported by this interface.

The flags are a bitwise combination of `GtkTreeModel`Flags.
The flags supported should not change during the lifetime
of the @tree_model. *)

external get_column_type : t -> int -> Gobject.Type.t
  = "ml_gtk_tree_model_get_column_type"
(** Returns the type of the column. *)

external filter_new : t -> Tree_path.t option -> t
  = "ml_gtk_tree_model_filter_new"
(** Creates a new `GtkTreeModel`, with @child_model as the child_model
and @root as the virtual root. *)
