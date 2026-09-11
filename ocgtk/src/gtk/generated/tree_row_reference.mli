(* GENERATED CODE - DO NOT EDIT *)
(* TreeRowReference: TreeRowReference *)

type t = [ `tree_row_reference ] Gobject.obj
(** A GtkTreeRowReference tracks model changes so that it always refers to the
    same row (a `GtkTreePath` refers to a position, not a fixed row). Create a
    new GtkTreeRowReference with gtk_tree_row_reference_new(). *)

external gtype : unit -> Gobject.Type.t = "ml_gtk_tree_row_reference_get_type"

external new_ : Tree_model.t -> Tree_path.t -> t
  = "ml_gtk_tree_row_reference_new"
(** Create a new TreeRowReference *)

external new_proxy :
  [ `object_ ] Gobject.obj -> Tree_model.t -> Tree_path.t -> t
  = "ml_gtk_tree_row_reference_new_proxy"
(** Create a new TreeRowReference *)

(* Methods *)

external valid : t -> bool = "ml_gtk_tree_row_reference_valid"
(** Returns %TRUE if the @reference is non-%NULL and refers to
a current valid path. *)

external get_path : t -> Tree_path.t option
  = "ml_gtk_tree_row_reference_get_path"
(** Returns a path that the row reference currently points to, or %NULL if the
    path pointed to is no longer valid. *)

external get_model : t -> Tree_model.t = "ml_gtk_tree_row_reference_get_model"
(** Returns the model that the row reference is monitoring. *)
