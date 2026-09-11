(* GENERATED CODE - DO NOT EDIT *)
(* WindowHandle: WindowHandle *)

type t =
  [ `window_handle | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_window_handle_get_type"

external new_ : unit -> t = "ml_gtk_window_handle_new"
(** Create a new WindowHandle *)

(* Methods *)

external set_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_window_handle_set_child"
(** Sets the child widget of @self. *)

external get_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_window_handle_get_child"
(** Gets the child widget of @self. *)

(* Properties *)
