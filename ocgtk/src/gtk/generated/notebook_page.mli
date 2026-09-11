(* GENERATED CODE - DO NOT EDIT *)
(* NotebookPage: NotebookPage *)

type t = [ `notebook_page | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_notebook_page_get_type"

(* Methods *)

external get_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t = "ml_gtk_notebook_page_get_child"
(** Returns the notebook child to which @page belongs. *)

(* Properties *)

external get_detachable : t -> bool = "ml_gtk_notebook_page_get_detachable"
(** Get property: detachable *)

external set_detachable : t -> bool -> unit
  = "ml_gtk_notebook_page_set_detachable"
(** Set property: detachable *)

external get_menu :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t = "ml_gtk_notebook_page_get_menu"
(** Get property: menu *)

external get_menu_label : t -> string = "ml_gtk_notebook_page_get_menu_label"
(** Get property: menu-label *)

external set_menu_label : t -> string -> unit
  = "ml_gtk_notebook_page_set_menu_label"
(** Set property: menu-label *)

external get_position : t -> int = "ml_gtk_notebook_page_get_position"
(** Get property: position *)

external set_position : t -> int -> unit = "ml_gtk_notebook_page_set_position"
(** Set property: position *)

external get_reorderable : t -> bool = "ml_gtk_notebook_page_get_reorderable"
(** Get property: reorderable *)

external set_reorderable : t -> bool -> unit
  = "ml_gtk_notebook_page_set_reorderable"
(** Set property: reorderable *)

external get_tab :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t = "ml_gtk_notebook_page_get_tab"
(** Get property: tab *)

external get_tab_expand : t -> bool = "ml_gtk_notebook_page_get_tab_expand"
(** Get property: tab-expand *)

external set_tab_expand : t -> bool -> unit
  = "ml_gtk_notebook_page_set_tab_expand"
(** Set property: tab-expand *)

external get_tab_fill : t -> bool = "ml_gtk_notebook_page_get_tab_fill"
(** Get property: tab-fill *)

external set_tab_fill : t -> bool -> unit = "ml_gtk_notebook_page_set_tab_fill"
(** Set property: tab-fill *)

external get_tab_label : t -> string = "ml_gtk_notebook_page_get_tab_label"
(** Get property: tab-label *)

external set_tab_label : t -> string -> unit
  = "ml_gtk_notebook_page_set_tab_label"
(** Set property: tab-label *)
