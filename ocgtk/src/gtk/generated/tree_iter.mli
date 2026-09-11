(* GENERATED CODE - DO NOT EDIT *)
(* TreeIter: TreeIter *)

type t = [ `tree_iter ] Gobject.obj
(** The `GtkTreeIter` is the primary structure
for accessing a `GtkTreeModel`. Models are expected to put a unique
integer in the @stamp member, and put
model-specific data in the three @user_data
members. *)

external gtype : unit -> Gobject.Type.t = "ml_gtk_tree_iter_get_type"

(* Methods *)
