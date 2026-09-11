(* GENERATED CODE - DO NOT EDIT *)
(* TreeDragDest: TreeDragDest *)

type t = [ `tree_drag_dest ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_tree_drag_dest_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gtk_tree_drag_dest_from_gobject"

(* Methods *)

external row_drop_possible : t -> Tree_path.t -> Gobject.Value.t -> bool
  = "ml_gtk_tree_drag_dest_row_drop_possible"
(** Determines whether a drop is possible before the given @dest_path,
at the same depth as @dest_path. i.e., can we drop the data in
@value at that location. @dest_path does not have to
exist; the return value will almost certainly be %FALSE if the
parent of @dest_path doesn’t exist, though. *)

external drag_data_received : t -> Tree_path.t -> Gobject.Value.t -> bool
  = "ml_gtk_tree_drag_dest_drag_data_received"
(** Asks the `GtkTreeDragDest` to insert a row before the path @dest,
deriving the contents of the row from @value. If @dest is
outside the tree so that inserting before it is impossible, %FALSE
will be returned. Also, %FALSE may be returned if the new row is
not created for some model-specific reason.  Should robustly handle
a @dest no longer found in the model! *)
