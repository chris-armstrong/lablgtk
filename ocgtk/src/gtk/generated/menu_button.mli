(* GENERATED CODE - DO NOT EDIT *)
(* MenuButton: MenuButton *)

type t = [ `menu_button | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_menu_button_get_type"

external new_ : unit -> t = "ml_gtk_menu_button_new"
(** Create a new MenuButton *)

(* Methods *)

external set_use_underline : t -> bool -> unit
  = "ml_gtk_menu_button_set_use_underline"
(** If true, an underline in the text indicates a mnemonic. *)

external set_primary : t -> bool -> unit = "ml_gtk_menu_button_set_primary"
(** Sets whether menu button acts as a primary menu.

    Primary menus can be opened with the <kbd>F10</kbd> key. *)

external set_popover : t -> Popover.t option -> unit
  = "ml_gtk_menu_button_set_popover"
(** Sets the `GtkPopover` that will be popped up when the @menu_button is clicked.

If @popover is %NULL, the button is disabled.

If [property@Gtk.MenuButton:menu-model] is set, the menu model is dissociated
from the @menu_button, and the property is set to %NULL. *)

external set_menu_model :
  t -> Ocgtk_gio.Gio.Wrappers.Menu_model.t option -> unit
  = "ml_gtk_menu_button_set_menu_model"
(** Sets the `GMenuModel` from which the popup will be constructed.

If @menu_model is %NULL, the button is disabled.

A [class@Gtk.Popover] will be created from the menu model with
[ctor@Gtk.PopoverMenu.new_from_model]. Actions will be connected
as documented for this function.

If [property@Gtk.MenuButton:popover] is already set, it will be
dissociated from the @menu_button, and the property is set to %NULL. *)

external set_label : t -> string -> unit = "ml_gtk_menu_button_set_label"
(** Sets the label to show inside the menu button.

    Setting a label resets [property@Gtk.MenuButton:icon-name] and
    [property@Gtk.MenuButton:child].

    If [property@Gtk.MenuButton:direction] is not `GTK_ARROW_NONE`, a dropdown
    arrow will be shown next to the label. *)

external set_icon_name : t -> string -> unit
  = "ml_gtk_menu_button_set_icon_name"
(** Sets the name of an icon to show inside the menu button.

    Setting icon name resets [property@Gtk.MenuButton:label] and
    [property@Gtk.MenuButton:child].

    If [property@Gtk.MenuButton:always-show-arrow] is set to `TRUE` and
    [property@Gtk.MenuButton:direction] is not `GTK_ARROW_NONE`, a dropdown
    arrow will be shown next to the icon. *)

external set_has_frame : t -> bool -> unit = "ml_gtk_menu_button_set_has_frame"
(** Sets the style of the button. *)

external set_direction : t -> Gtk_enums.arrowtype -> unit
  = "ml_gtk_menu_button_set_direction"
(** Sets the direction in which the popup will be popped up.

If the button is automatically populated with an arrow icon,
its direction will be changed to match.

If the does not fit in the available space in the given direction,
GTK will its best to keep it inside the screen and fully visible.

If you pass %GTK_ARROW_NONE for a @direction, the popup will behave
as if you passed %GTK_ARROW_DOWN (although you won’t see any arrows). *)

external set_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_menu_button_set_child"
(** Sets the child widget of @menu_button.

Setting a child resets [property@Gtk.MenuButton:label] and
[property@Gtk.MenuButton:icon-name].

If [property@Gtk.MenuButton:always-show-arrow] is set to `TRUE` and
[property@Gtk.MenuButton:direction] is not `GTK_ARROW_NONE`, a dropdown arrow
will be shown next to the child. *)

external set_can_shrink : t -> bool -> unit
  = "ml_gtk_menu_button_set_can_shrink"
(** Sets whether the button size can be smaller than the natural size of
its contents.

For text buttons, setting @can_shrink to true will ellipsize the label.

For icon buttons, this function has no effect. *)

external set_always_show_arrow : t -> bool -> unit
  = "ml_gtk_menu_button_set_always_show_arrow"
(** Sets whether to show a dropdown arrow even when using an icon or a custom
    child. *)

external set_active : t -> bool -> unit = "ml_gtk_menu_button_set_active"
(** Sets whether the menu button is active. *)

external popup : t -> unit = "ml_gtk_menu_button_popup"
(** Pop up the menu. *)

external popdown : t -> unit = "ml_gtk_menu_button_popdown"
(** Dismiss the menu. *)

external get_use_underline : t -> bool = "ml_gtk_menu_button_get_use_underline"
(** Returns whether an embedded underline in the text indicates a mnemonic. *)

external get_primary : t -> bool = "ml_gtk_menu_button_get_primary"
(** Returns whether the menu button acts as a primary menu. *)

external get_popover : t -> Popover.t option = "ml_gtk_menu_button_get_popover"
(** Returns the `GtkPopover` that pops out of the button.

    If the button is not using a `GtkPopover`, this function returns %NULL. *)

external get_menu_model : t -> Ocgtk_gio.Gio.Wrappers.Menu_model.t option
  = "ml_gtk_menu_button_get_menu_model"
(** Returns the `GMenuModel` used to generate the popup. *)

external get_label : t -> string option = "ml_gtk_menu_button_get_label"
(** Gets the label shown in the button *)

external get_icon_name : t -> string option = "ml_gtk_menu_button_get_icon_name"
(** Gets the name of the icon shown in the button. *)

external get_has_frame : t -> bool = "ml_gtk_menu_button_get_has_frame"
(** Returns whether the button has a frame. *)

external get_direction : t -> Gtk_enums.arrowtype
  = "ml_gtk_menu_button_get_direction"
(** Returns the direction the popup will be pointing at when popped up. *)

external get_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_menu_button_get_child"
(** Gets the child widget of @menu_button. *)

external get_can_shrink : t -> bool = "ml_gtk_menu_button_get_can_shrink"
(** Retrieves whether the button can be smaller than the natural size of its
    contents. *)

external get_always_show_arrow : t -> bool
  = "ml_gtk_menu_button_get_always_show_arrow"
(** Gets whether to show a dropdown arrow even when using an icon or a custom
    child. *)

external get_active : t -> bool = "ml_gtk_menu_button_get_active"
(** Returns whether the menu button is active. *)

(* Properties *)

val on_activate :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
