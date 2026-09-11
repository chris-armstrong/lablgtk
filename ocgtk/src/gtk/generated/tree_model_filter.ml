(* GENERATED CODE - DO NOT EDIT *)
(* TreeModelFilter: TreeModelFilter *)

type t = [ `tree_model_filter | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_tree_model_filter_get_type"

(* Methods *)

external set_visible_column : t -> int -> unit
  = "ml_gtk_tree_model_filter_set_visible_column"
(** Sets @column of the child_model to be the column where @filter should
look for visibility information. @columns should be a column of type
%G_TYPE_BOOLEAN, where %TRUE means that a row is visible, and %FALSE
if not.

Note that gtk_tree_model_filter_set_visible_func() or
gtk_tree_model_filter_set_visible_column() can only be called
once for a given filter model. *)

external refilter : t -> unit = "ml_gtk_tree_model_filter_refilter"
(** Emits ::row_changed for each row in the child model, which causes the filter
    to re-evaluate whether a row is visible or not. *)

external get_model : t -> Tree_model.t = "ml_gtk_tree_model_filter_get_model"
(** Returns a pointer to the child model of @filter. *)

external convert_path_to_child_path : t -> Tree_path.t -> Tree_path.t option
  = "ml_gtk_tree_model_filter_convert_path_to_child_path"
(** Converts @filter_path to a path on the child model of @filter. That is,
@filter_path points to a location in @filter. The returned path will
point to the same location in the model not being filtered. If @filter_path
does not point to a location in the child model, %NULL is returned. *)

external convert_iter_to_child_iter : t -> Tree_iter.t -> Tree_iter.t
  = "ml_gtk_tree_model_filter_convert_iter_to_child_iter"
(** Sets @child_iter to point to the row pointed to by @filter_iter. *)

external convert_child_path_to_path : t -> Tree_path.t -> Tree_path.t option
  = "ml_gtk_tree_model_filter_convert_child_path_to_path"
(** Converts @child_path to a path relative to @filter. That is, @child_path
points to a path in the child model. The rerturned path will point to the
same row in the filtered model. If @child_path isn’t a valid path on the
child model or points to a row which is not visible in @filter, then %NULL
is returned. *)

external convert_child_iter_to_iter : t -> Tree_iter.t -> bool * Tree_iter.t
  = "ml_gtk_tree_model_filter_convert_child_iter_to_iter"
(** Sets @filter_iter to point to the row in @filter that corresponds to the
row pointed at by @child_iter.  If @filter_iter was not set, %FALSE is
returned. *)

external clear_cache : t -> unit = "ml_gtk_tree_model_filter_clear_cache"
(** This function should almost never be called. It clears the @filter
of any cached iterators that haven’t been reffed with
gtk_tree_model_ref_node(). This might be useful if the child model
being filtered is static (and doesn’t change often) and there has been
a lot of unreffed access to nodes. As a side effect of this function,
all unreffed iters will be invalid. *)

(* Properties *)

external get_child_model : t -> Tree_model.t
  = "ml_gtk_tree_model_filter_get_child_model"
(** Get property: child-model *)

external get_virtual_root : t -> Tree_path.t
  = "ml_gtk_tree_model_filter_get_virtual_root"
(** Get property: virtual-root *)
