(* GENERATED CODE - DO NOT EDIT *)
(* Box: Box *)

type t = [ `box | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_box_get_type"

external new_ : Gtk_enums.orientation -> int -> t = "ml_gtk_box_new"
(** Create a new Box *)

(* Methods *)

external set_spacing : t -> int -> unit = "ml_gtk_box_set_spacing"
(** Sets the number of pixels to place between children. *)

external set_homogeneous : t -> bool -> unit = "ml_gtk_box_set_homogeneous"
(** Sets whether or not all children are given equal space in the box. *)

external set_baseline_position : t -> Gtk_enums.baselineposition -> unit
  = "ml_gtk_box_set_baseline_position"
(** Sets the baseline position of a box.

This affects only horizontal boxes with at least one baseline
aligned child. If there is more vertical space available than
requested, and the baseline is not allocated by the parent then
@position is used to allocate the baseline with respect to the
extra space available. *)

external set_baseline_child : t -> int -> unit = "ml_gtk_box_set_baseline_child"
(** Sets the baseline child of a box.

    This affects only vertical boxes. *)

external reorder_child_after :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_box_reorder_child_after"
(** Moves a child to a different position.

The child is moved to the position after @sibling in the list
of @box children.

If @sibling is `NULL`, the child is placed at the beginning. *)

external remove :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  unit = "ml_gtk_box_remove"
(** Removes a child widget from the box.

    The child must have been added before with [method@Gtk.Box.append],
    [method@Gtk.Box.prepend], or [method@Gtk.Box.insert_child_after]. *)

external prepend :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  unit = "ml_gtk_box_prepend"
(** Adds a child at the beginning. *)

external insert_child_after :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_box_insert_child_after"
(** Inserts a child at a specific position.

The child is added after @sibling in the list of @box children.

If @sibling is `NULL`, the @child is placed at the beginning. *)

external get_spacing : t -> int = "ml_gtk_box_get_spacing"
(** Gets the value set by [method@Gtk.Box.set_spacing]. *)

external get_homogeneous : t -> bool = "ml_gtk_box_get_homogeneous"
(** Returns whether the box is homogeneous.

    In a homogeneous box all children are the same size. *)

external get_baseline_position : t -> Gtk_enums.baselineposition
  = "ml_gtk_box_get_baseline_position"
(** Gets the value set by [method@Gtk.Box.set_baseline_position]. *)

external get_baseline_child : t -> int = "ml_gtk_box_get_baseline_child"
(** Gets the value set by [method@Gtk.Box.set_baseline_child]. *)

external append :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  unit = "ml_gtk_box_append"
(** Adds a child at the end. *)

(* Properties *)
