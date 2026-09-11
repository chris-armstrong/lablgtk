(* GENERATED CODE - DO NOT EDIT *)
(* ColumnViewCell: ColumnViewCell *)

type t = [ `column_view_cell | `list_item | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_column_view_cell_get_type"

(* Methods *)

external set_focusable : t -> bool -> unit
  = "ml_gtk_column_view_cell_set_focusable"
(** Sets @self to be focusable.

If an item is focusable, it can be focused using the keyboard.
This works similar to [method@Gtk.Widget.set_focusable].

Note that if items are not focusable, the keyboard cannot be used to activate
them and selecting only works if one of the listitem's children is focusable.

By default, list items are focusable. *)

external set_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_column_view_cell_set_child"
(** Sets the child to be used for this listitem.

    This function is typically called by applications when setting up a listitem
    so that the widget can be reused when binding it multiple times. *)

external get_selected : t -> bool = "ml_gtk_column_view_cell_get_selected"
(** Checks if the item is displayed as selected.

    The selected state is maintained by the list widget and its model and cannot
    be set otherwise. *)

external get_position : t -> int = "ml_gtk_column_view_cell_get_position"
(** Gets the position in the model that @self currently displays.

If @self is unbound, %GTK_INVALID_LIST_POSITION is returned. *)

external get_item : t -> [ `object_ ] Gobject.obj option
  = "ml_gtk_column_view_cell_get_item"
(** Gets the model item that associated with @self.

If @self is unbound, this function returns %NULL. *)

external get_focusable : t -> bool = "ml_gtk_column_view_cell_get_focusable"
(** Checks if a list item has been set to be focusable via
    gtk_column_view_cell_set_focusable(). *)

external get_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_column_view_cell_get_child"
(** Gets the child previously set via gtk_column_view_cell_set_child() or %NULL
    if none was set. *)

(* Properties *)
