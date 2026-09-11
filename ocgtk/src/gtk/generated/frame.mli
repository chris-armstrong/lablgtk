(* GENERATED CODE - DO NOT EDIT *)
(* Frame: Frame *)

type t = [ `frame | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_frame_get_type"

external new_ : string option -> t = "ml_gtk_frame_new"
(** Create a new Frame *)

(* Methods *)

external set_label_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_frame_set_label_widget"
(** Sets the label widget for the frame.

    This is the widget that will appear embedded in the top edge of the frame as
    a title. *)

external set_label_align : t -> float -> unit = "ml_gtk_frame_set_label_align"
(** Sets the X alignment of the frame widget’s label.

    The default value for a newly created frame is 0.0. *)

external set_label : t -> string option -> unit = "ml_gtk_frame_set_label"
(** Creates a new `GtkLabel` with the @label and sets it as the frame's
label widget. *)

external set_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_frame_set_child"
(** Sets the child widget of @frame. *)

external get_label_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_frame_get_label_widget"
(** Retrieves the label widget for the frame. *)

external get_label_align : t -> float = "ml_gtk_frame_get_label_align"
(** Retrieves the X alignment of the frame’s label. *)

external get_label : t -> string option = "ml_gtk_frame_get_label"
(** Returns the frame labels text.

    If the frame's label widget is not a `GtkLabel`, %NULL is returned. *)

external get_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_frame_get_child"
(** Gets the child widget of @frame. *)

(* Properties *)
