(* GENERATED CODE - DO NOT EDIT *)
(* PopoverMenuBar: PopoverMenuBar *)

type t =
  [ `popover_menu_bar | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_popover_menu_bar_get_type"

external new_from_model : Ocgtk_gio.Gio.Wrappers.Menu_model.t option -> t
  = "ml_gtk_popover_menu_bar_new_from_model"
(** Create a new PopoverMenuBar *)

(* Methods *)

external set_menu_model :
  t -> Ocgtk_gio.Gio.Wrappers.Menu_model.t option -> unit
  = "ml_gtk_popover_menu_bar_set_menu_model"
(** Sets a menu model from which @bar should take
its contents. *)

external remove_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  bool = "ml_gtk_popover_menu_bar_remove_child"
(** Removes a widget that has previously been added with
    gtk_popover_menu_bar_add_child(). *)

external get_menu_model : t -> Ocgtk_gio.Gio.Wrappers.Menu_model.t option
  = "ml_gtk_popover_menu_bar_get_menu_model"
(** Returns the model from which the contents of @bar are taken. *)

external add_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  string ->
  bool = "ml_gtk_popover_menu_bar_add_child"
(** Adds a custom widget to a generated menubar.

For this to work, the menu model of @bar must have an
item with a `custom` attribute that matches @id. *)

(* Properties *)
