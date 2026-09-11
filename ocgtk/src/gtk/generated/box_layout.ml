(* GENERATED CODE - DO NOT EDIT *)
(* BoxLayout: BoxLayout *)

type t = [ `box_layout | `layout_manager | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_box_layout_get_type"

external new_ : Gtk_enums.orientation -> t = "ml_gtk_box_layout_new"
(** Create a new BoxLayout *)

(* Methods *)

external set_spacing : t -> int -> unit = "ml_gtk_box_layout_set_spacing"
(** Sets how much spacing to put between children. *)

external set_homogeneous : t -> bool -> unit
  = "ml_gtk_box_layout_set_homogeneous"
(** Sets whether the box layout will allocate the same size to all children. *)

external set_baseline_position : t -> Gtk_enums.baselineposition -> unit
  = "ml_gtk_box_layout_set_baseline_position"
(** Sets the baseline position of a box layout.

The baseline position affects only horizontal boxes with at least one
baseline aligned child. If there is more vertical space available than
requested, and the baseline is not allocated by the parent then the
given @position is used to allocate the baseline within the extra
space available. *)

external set_baseline_child : t -> int -> unit
  = "ml_gtk_box_layout_set_baseline_child"
(** Sets the index of the child that determines the baseline in vertical layout.
*)

external get_spacing : t -> int = "ml_gtk_box_layout_get_spacing"
(** Returns the space that @box_layout puts between children. *)

external get_homogeneous : t -> bool = "ml_gtk_box_layout_get_homogeneous"
(** Returns whether the layout is set to be homogeneous. *)

external get_baseline_position : t -> Gtk_enums.baselineposition
  = "ml_gtk_box_layout_get_baseline_position"
(** Gets the value set by gtk_box_layout_set_baseline_position(). *)

external get_baseline_child : t -> int = "ml_gtk_box_layout_get_baseline_child"
(** Gets the value set by gtk_box_layout_set_baseline_child(). *)

(* Properties *)
