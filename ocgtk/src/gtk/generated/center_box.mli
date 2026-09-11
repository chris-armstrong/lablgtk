(* GENERATED CODE - DO NOT EDIT *)
(* CenterBox: CenterBox *)

type t = [ `center_box | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_center_box_get_type"

external new_ : unit -> t = "ml_gtk_center_box_new"
(** Create a new CenterBox *)

(* Methods *)

external set_start_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_center_box_set_start_widget"
(** Sets the start widget.

    To remove the existing start widget, pass `NULL`. *)

external set_shrink_center_last : t -> bool -> unit
  = "ml_gtk_center_box_set_shrink_center_last"
(** Sets whether to shrink the center widget after other children.

By default, when there's no space to give all three children their
natural widths, the start and end widgets start shrinking and the
center child keeps natural width until they reach minimum width.

If @shrink_center_last is false, start and end widgets keep natural
width and the center widget starts shrinking instead. *)

external set_end_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_center_box_set_end_widget"
(** Sets the end widget.

    To remove the existing end widget, pass `NULL`. *)

external set_center_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_center_box_set_center_widget"
(** Sets the center widget.

    To remove the existing center widget, pass `NULL`. *)

external set_baseline_position : t -> Gtk_enums.baselineposition -> unit
  = "ml_gtk_center_box_set_baseline_position"
(** Sets the baseline position of a center box.

This affects only horizontal boxes with at least one baseline
aligned child. If there is more vertical space available than
requested, and the baseline is not allocated by the parent then
@position is used to allocate the baseline with respect to the
extra space available. *)

external get_start_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_center_box_get_start_widget"
(** Gets the start widget. *)

external get_shrink_center_last : t -> bool
  = "ml_gtk_center_box_get_shrink_center_last"
(** Gets whether the center widget shrinks after other children. *)

external get_end_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_center_box_get_end_widget"
(** Gets the end widget. *)

external get_center_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_center_box_get_center_widget"
(** Gets the center widget. *)

external get_baseline_position : t -> Gtk_enums.baselineposition
  = "ml_gtk_center_box_get_baseline_position"
(** Gets the baseline position of the center box.

    See [method@Gtk.CenterBox.set_baseline_position]. *)

(* Properties *)
