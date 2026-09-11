(* GENERATED CODE - DO NOT EDIT *)
(* CenterLayout: CenterLayout *)

type t = [ `center_layout | `layout_manager | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_center_layout_get_type"

external new_ : unit -> t = "ml_gtk_center_layout_new"
(** Create a new CenterLayout *)

(* Methods *)

external set_start_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_center_layout_set_start_widget"
(** Sets the new start widget of @self.

To remove the existing start widget, pass %NULL. *)

external set_shrink_center_last : t -> bool -> unit
  = "ml_gtk_center_layout_set_shrink_center_last"
(** Sets whether to shrink the center widget after other children.

    By default, when there's no space to give all three children their natural
    widths, the start and end widgets start shrinking and the center child keeps
    natural width until they reach minimum width.

    If set to `FALSE`, start and end widgets keep natural width and the center
    widget starts shrinking instead. *)

external set_orientation : t -> Gtk_enums.orientation -> unit
  = "ml_gtk_center_layout_set_orientation"
(** Sets the orientation of @self. *)

external set_end_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_center_layout_set_end_widget"
(** Sets the new end widget of @self.

To remove the existing center widget, pass %NULL. *)

external set_center_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_center_layout_set_center_widget"
(** Sets the new center widget of @self.

To remove the existing center widget, pass %NULL. *)

external set_baseline_position : t -> Gtk_enums.baselineposition -> unit
  = "ml_gtk_center_layout_set_baseline_position"
(** Sets the new baseline position of @self *)

external get_start_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_center_layout_get_start_widget"
(** Returns the start widget of the layout. *)

external get_shrink_center_last : t -> bool
  = "ml_gtk_center_layout_get_shrink_center_last"
(** Gets whether @self shrinks the center widget after other children. *)

external get_orientation : t -> Gtk_enums.orientation
  = "ml_gtk_center_layout_get_orientation"
(** Gets the current orienration of the layout manager. *)

external get_end_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_center_layout_get_end_widget"
(** Returns the end widget of the layout. *)

external get_center_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_center_layout_get_center_widget"
(** Returns the center widget of the layout. *)

external get_baseline_position : t -> Gtk_enums.baselineposition
  = "ml_gtk_center_layout_get_baseline_position"
(** Returns the baseline position of the layout. *)

(* Properties *)
