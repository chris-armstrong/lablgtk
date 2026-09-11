(* GENERATED CODE - DO NOT EDIT *)
(* DragIcon: DragIcon *)

type t = [ `drag_icon | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_drag_icon_get_type"

external get_for_drag : Ocgtk_gdk.Gdk.Wrappers.Drag.t -> t
  = "ml_gtk_drag_icon_get_for_drag"
(** Create a new DragIcon *)

(* Methods *)

external set_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_drag_icon_set_child"
(** Sets the widget to display as the drag icon. *)

external get_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_drag_icon_get_child"
(** Gets the widget currently used as drag icon. *)

(* Properties *)
