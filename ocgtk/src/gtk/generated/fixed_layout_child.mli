(* GENERATED CODE - DO NOT EDIT *)
(* FixedLayoutChild: FixedLayoutChild *)

type t = [ `fixed_layout_child | `layout_child | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_fixed_layout_child_get_type"

(* Methods *)

external set_transform : t -> Ocgtk_gsk.Gsk.Wrappers.Transform.t -> unit
  = "ml_gtk_fixed_layout_child_set_transform"
(** Sets the transformation of the child of a `GtkFixedLayout`. *)

external get_transform : t -> Ocgtk_gsk.Gsk.Wrappers.Transform.t option
  = "ml_gtk_fixed_layout_child_get_transform"
(** Retrieves the transformation of the child. *)

(* Properties *)
