(* GENERATED CODE - DO NOT EDIT *)
(* AssistantPage: AssistantPage *)

type t = [ `assistant_page | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_assistant_page_get_type"

(* Methods *)

external get_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t = "ml_gtk_assistant_page_get_child"
(** Returns the child to which @page belongs. *)

(* Properties *)

external get_complete : t -> bool = "ml_gtk_assistant_page_get_complete"
(** Get property: complete *)

external set_complete : t -> bool -> unit = "ml_gtk_assistant_page_set_complete"
(** Set property: complete *)

external get_page_type : t -> Gtk_enums.assistantpagetype
  = "ml_gtk_assistant_page_get_page_type"
(** Get property: page-type *)

external set_page_type : t -> Gtk_enums.assistantpagetype -> unit
  = "ml_gtk_assistant_page_set_page_type"
(** Set property: page-type *)

external get_title : t -> string = "ml_gtk_assistant_page_get_title"
(** Get property: title *)

external set_title : t -> string -> unit = "ml_gtk_assistant_page_set_title"
(** Set property: title *)
