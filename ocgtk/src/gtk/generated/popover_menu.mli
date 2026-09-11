(* GENERATED CODE - DO NOT EDIT *)
(* PopoverMenu: PopoverMenu *)

type t =
  [ `popover_menu | `popover | `widget | `initially_unowned | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_popover_menu_get_type"

external new_from_model : Ocgtk_gio.Gio.Wrappers.Menu_model.t option -> t
  = "ml_gtk_popover_menu_new_from_model"
(** Create a new PopoverMenu *)

external new_from_model_full :
  Ocgtk_gio.Gio.Wrappers.Menu_model.t -> Gtk_enums.popovermenuflags -> t
  = "ml_gtk_popover_menu_new_from_model_full"
(** Create a new PopoverMenu *)

(* Methods *)

external set_menu_model :
  t -> Ocgtk_gio.Gio.Wrappers.Menu_model.t option -> unit
  = "ml_gtk_popover_menu_set_menu_model"
(** Sets a new menu model on @popover.

The existing contents of @popover are removed, and
the @popover is populated with new contents according
to @model. *)

external set_flags : t -> Gtk_enums.popovermenuflags -> unit
  = "ml_gtk_popover_menu_set_flags"
(** Sets the flags that @popover uses to create/display a menu from its model.

If a model is set and the flags change, contents are rebuilt, so if setting
properties individually, set flags before model to avoid a redundant rebuild. *)

external remove_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  bool = "ml_gtk_popover_menu_remove_child"
(** Removes a widget that has previously been added with
    [method@Gtk.PopoverMenu.add_child] *)

external get_menu_model : t -> Ocgtk_gio.Gio.Wrappers.Menu_model.t option
  = "ml_gtk_popover_menu_get_menu_model"
(** Returns the menu model used to populate the popover. *)

external get_flags : t -> Gtk_enums.popovermenuflags
  = "ml_gtk_popover_menu_get_flags"
(** Returns the flags that @popover uses to create/display a menu from its model. *)

external add_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  string ->
  bool = "ml_gtk_popover_menu_add_child"
(** Adds a custom widget to a generated menu.

For this to work, the menu model of @popover must have
an item with a `custom` attribute that matches @id. *)

(* Properties *)

external get_visible_submenu : t -> string
  = "ml_gtk_popover_menu_get_visible_submenu"
(** Get property: visible-submenu *)

external set_visible_submenu : t -> string -> unit
  = "ml_gtk_popover_menu_set_visible_submenu"
(** Set property: visible-submenu *)
