(* GENERATED CODE - DO NOT EDIT *)
(* TreeModelSort: TreeModelSort *)

type t = [ `tree_model_sort | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_tree_model_sort_get_type"

external new_with_model : Tree_model.t -> t
  = "ml_gtk_tree_model_sort_new_with_model"
(** Create a new TreeModelSort *)

(* Methods *)

external reset_default_sort_func : t -> unit
  = "ml_gtk_tree_model_sort_reset_default_sort_func"
(** This resets the default sort function to be in the “unsorted” state. That
    is, it is in the same order as the child model. It will re-sort the model to
    be in the same order as the child model only if the `GtkTreeModelSort` is in
    “unsorted” state. *)

external iter_is_valid : t -> Tree_iter.t -> bool
  = "ml_gtk_tree_model_sort_iter_is_valid"
(** > This function is slow. Only use it for debugging and/or testing >
    purposes.

    Checks if the given iter is a valid iter for this `GtkTreeModelSort`. *)

external get_model : t -> Tree_model.t = "ml_gtk_tree_model_sort_get_model"
(** Returns the model the `GtkTreeModelSort` is sorting. *)

external convert_path_to_child_path : t -> Tree_path.t -> Tree_path.t option
  = "ml_gtk_tree_model_sort_convert_path_to_child_path"
(** Converts @sorted_path to a path on the child model of @tree_model_sort.
That is, @sorted_path points to a location in @tree_model_sort.  The
returned path will point to the same location in the model not being
sorted.  If @sorted_path does not point to a location in the child model,
%NULL is returned. *)

external convert_iter_to_child_iter : t -> Tree_iter.t -> Tree_iter.t
  = "ml_gtk_tree_model_sort_convert_iter_to_child_iter"
(** Sets @child_iter to point to the row pointed to by @sorted_iter. *)

external convert_child_path_to_path : t -> Tree_path.t -> Tree_path.t option
  = "ml_gtk_tree_model_sort_convert_child_path_to_path"
(** Converts @child_path to a path relative to @tree_model_sort.  That is,
@child_path points to a path in the child model.  The returned path will
point to the same row in the sorted model.  If @child_path isn’t a valid
path on the child model, then %NULL is returned. *)

external convert_child_iter_to_iter : t -> Tree_iter.t -> bool * Tree_iter.t
  = "ml_gtk_tree_model_sort_convert_child_iter_to_iter"
(** Sets @sort_iter to point to the row in @tree_model_sort that corresponds to
the row pointed at by @child_iter.  If @sort_iter was not set, %FALSE
is returned.  Note: a boolean is only returned since 2.14. *)

external clear_cache : t -> unit = "ml_gtk_tree_model_sort_clear_cache"
(** This function should almost never be called.  It clears the @tree_model_sort
of any cached iterators that haven’t been reffed with
gtk_tree_model_ref_node().  This might be useful if the child model being
sorted is static (and doesn’t change often) and there has been a lot of
unreffed access to nodes.  As a side effect of this function, all unreffed
iters will be invalid. *)

(* Properties *)
