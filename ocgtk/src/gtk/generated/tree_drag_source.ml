(* GENERATED CODE - DO NOT EDIT *)
(* TreeDragSource: TreeDragSource *)

type t = [ `tree_drag_source ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_tree_drag_source_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gtk_tree_drag_source_from_gobject"

(* Methods *)

external row_draggable : t -> Tree_path.t -> bool
  = "ml_gtk_tree_drag_source_row_draggable"
(** Asks the `GtkTreeDragSource` whether a particular row can be used as the
    source of a DND operation. If the source doesn’t implement this interface,
    the row is assumed draggable. *)

external drag_data_get :
  t -> Tree_path.t -> Ocgtk_gdk.Gdk.Wrappers.Content_provider.t option
  = "ml_gtk_tree_drag_source_drag_data_get"
(** Asks the `GtkTreeDragSource` to return a `GdkContentProvider` representing
the row at @path. Should robustly handle a @path no
longer found in the model! *)

external drag_data_delete : t -> Tree_path.t -> bool
  = "ml_gtk_tree_drag_source_drag_data_delete"
(** Asks the `GtkTreeDragSource` to delete the row at @path, because
it was moved somewhere else via drag-and-drop. Returns %FALSE
if the deletion fails because @path no longer exists, or for
some model-specific reason. Should robustly handle a @path no
longer found in the model! *)
