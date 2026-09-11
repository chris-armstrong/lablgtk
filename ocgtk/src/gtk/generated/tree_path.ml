(* GENERATED CODE - DO NOT EDIT *)
(* TreePath: TreePath *)

type t = [ `tree_path ] Gobject.obj
(** An opaque structure representing a path to a row in a model. *)

external gtype : unit -> Gobject.Type.t = "ml_gtk_tree_path_get_type"

external new_ : unit -> t = "ml_gtk_tree_path_new"
(** Create a new TreePath *)

external new_first : unit -> t = "ml_gtk_tree_path_new_first"
(** Create a new TreePath *)

external new_from_indicesv : int array -> Gsize.t -> t
  = "ml_gtk_tree_path_new_from_indicesv"
(** Create a new TreePath *)

external new_from_string : string -> t = "ml_gtk_tree_path_new_from_string"
(** Create a new TreePath *)

(* Methods *)

external up : t -> bool = "ml_gtk_tree_path_up"
(** Moves the @path to point to its parent node, if it has a parent. *)

external to_string : t -> string option = "ml_gtk_tree_path_to_string"
(** Generates a string representation of the path.

    This string is a “:” separated list of numbers. For example, “4:10:0:3”
    would be an acceptable return value for this string. If the path has depth
    0, %NULL is returned. *)

external prev : t -> bool = "ml_gtk_tree_path_prev"
(** Moves the @path to point to the previous node at the
current depth, if it exists. *)

external prepend_index : t -> int -> unit = "ml_gtk_tree_path_prepend_index"
(** Prepends a new index to a path.

    As a result, the depth of the path is increased. *)

external next : t -> unit = "ml_gtk_tree_path_next"
(** Moves the @path to point to the next node at the current depth. *)

external is_descendant : t -> t -> bool = "ml_gtk_tree_path_is_descendant"
(** Returns %TRUE if @path is a descendant of @ancestor. *)

external is_ancestor : t -> t -> bool = "ml_gtk_tree_path_is_ancestor"
(** Returns %TRUE if @descendant is a descendant of @path. *)

external get_indices_with_depth : t -> int array option * int
  = "ml_gtk_tree_path_get_indices_with_depth"
(** Returns the current indices of @path.

This is an array of integers, each representing a node in a tree.
It also returns the number of elements in the array.
The array should not be freed. *)

external get_depth : t -> int = "ml_gtk_tree_path_get_depth"
(** Returns the current depth of @path. *)

external down : t -> unit = "ml_gtk_tree_path_down"
(** Moves @path to point to the first child of the current path. *)

external compare : t -> t -> int = "ml_gtk_tree_path_compare"
(** Compares two paths.

If @a appears before @b in a tree, then -1 is returned.
If @b appears before @a, then 1 is returned.
If the two nodes are equal, then 0 is returned. *)

external append_index : t -> int -> unit = "ml_gtk_tree_path_append_index"
(** Appends a new index to a path.

    As a result, the depth of the path is increased. *)
