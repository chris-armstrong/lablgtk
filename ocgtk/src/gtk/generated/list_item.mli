(* GENERATED CODE - DO NOT EDIT *)
(* ListItem: ListItem *)

type t = [ `list_item | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_list_item_get_type"

(* Methods *)

external set_selectable : t -> bool -> unit = "ml_gtk_list_item_set_selectable"
(** Sets @self to be selectable.

If an item is selectable, clicking on the item or using the keyboard
will try to select or unselect the item. If this succeeds is up to
the model to determine, as it is managing the selected state.

Note that this means that making an item non-selectable has no
influence on the selected state at all. A non-selectable item
may still be selected.

By default, listitems are selectable. When rebinding them to
a new item, they will also be reset to be selectable by GTK. *)

external set_focusable : t -> bool -> unit = "ml_gtk_list_item_set_focusable"
(** Sets @self to be focusable.

If an item is focusable, it can be focused using the keyboard.
This works similar to [method@Gtk.Widget.set_focusable].

Note that if items are not focusable, the keyboard cannot be used to activate
them and selecting only works if one of the listitem's children is focusable.

By default, listitems are focusable. *)

external set_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_list_item_set_child"
(** Sets the child to be used for this listitem.

    This function is typically called by applications when setting up a listitem
    so that the widget can be reused when binding it multiple times. *)

external set_activatable : t -> bool -> unit
  = "ml_gtk_list_item_set_activatable"
(** Sets @self to be activatable.

If an item is activatable, double-clicking on the item, using
the Return key or calling [method@Gtk.Widget.activate] will activate
the item. Activating instructs the containing view to handle
activation. `GtkListView` for example will be emitting the
[signal@Gtk.ListView::activate] signal.

By default, listitems are activatable. *)

external set_accessible_label : t -> string -> unit
  = "ml_gtk_list_item_set_accessible_label"
(** Sets the accessible label for the listitem.

    The accessible label may be used by e.g. screen readers. *)

external set_accessible_description : t -> string -> unit
  = "ml_gtk_list_item_set_accessible_description"
(** Sets the accessible description for the listitem.

    The accessible description may be used by e.g. screen readers. *)

external get_selected : t -> bool = "ml_gtk_list_item_get_selected"
(** Checks if the item is displayed as selected.

    The selected state is maintained by the list widget and its model and cannot
    be set otherwise. *)

external get_selectable : t -> bool = "ml_gtk_list_item_get_selectable"
(** Checks if a listitem has been set to be selectable via
    [method@Gtk.ListItem.set_selectable].

    Do not confuse this function with [method@Gtk.ListItem.get_selected]. *)

external get_position : t -> int = "ml_gtk_list_item_get_position"
(** Gets the position in the model that @self currently displays.

If @self is unbound, `GTK_INVALID_LIST_POSITION` is returned. *)

external get_item : t -> [ `object_ ] Gobject.obj option
  = "ml_gtk_list_item_get_item"
(** Gets the model item that associated with @self.

If @self is unbound, this function returns `NULL`. *)

external get_focusable : t -> bool = "ml_gtk_list_item_get_focusable"
(** Checks if a listitem has been set to be focusable via
    [method@Gtk.ListItem.set_focusable]. *)

external get_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_list_item_get_child"
(** Gets the child previously set via [method@Gtk.ListItem.set_child] or `NULL`
    if none was set. *)

external get_activatable : t -> bool = "ml_gtk_list_item_get_activatable"
(** Checks if a listitem has been set to be activatable via
    [method@Gtk.ListItem.set_activatable]. *)

external get_accessible_label : t -> string
  = "ml_gtk_list_item_get_accessible_label"
(** Gets the accessible label of @self. *)

external get_accessible_description : t -> string
  = "ml_gtk_list_item_get_accessible_description"
(** Gets the accessible description of @self. *)

(* Properties *)
