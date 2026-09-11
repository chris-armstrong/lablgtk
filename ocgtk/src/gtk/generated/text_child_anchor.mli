(* GENERATED CODE - DO NOT EDIT *)
(* TextChildAnchor: TextChildAnchor *)

type t = [ `text_child_anchor | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_text_child_anchor_get_type"

external new_ : unit -> t = "ml_gtk_text_child_anchor_new"
(** Create a new TextChildAnchor *)

external new_with_replacement : string -> t
  = "ml_gtk_text_child_anchor_new_with_replacement"
(** Create a new TextChildAnchor *)

(* Methods *)

external get_widgets :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  array
  * int = "ml_gtk_text_child_anchor_get_widgets"
(** Gets a list of all widgets anchored at this child anchor.

    The order in which the widgets are returned is not defined. *)

external get_deleted : t -> bool = "ml_gtk_text_child_anchor_get_deleted"
(** Determines whether a child anchor has been deleted from the buffer.

    Keep in mind that the child anchor will be unreferenced when removed from
    the buffer, so you need to hold your own reference (with g_object_ref()) if
    you plan to use this function — otherwise all deleted child anchors will
    also be finalized. *)
