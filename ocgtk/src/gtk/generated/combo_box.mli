(* GENERATED CODE - DO NOT EDIT *)
(* ComboBox: ComboBox *)

type t = [ `combo_box | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_combo_box_get_type"

external new_ : unit -> t = "ml_gtk_combo_box_new"
(** Create a new ComboBox *)

external new_with_entry : unit -> t = "ml_gtk_combo_box_new_with_entry"
(** Create a new ComboBox *)

external new_with_model : Tree_model.t -> t = "ml_gtk_combo_box_new_with_model"
(** Create a new ComboBox *)

external new_with_model_and_entry : Tree_model.t -> t
  = "ml_gtk_combo_box_new_with_model_and_entry"
(** Create a new ComboBox *)

(* Methods *)

external set_popup_fixed_width : t -> bool -> unit
  = "ml_gtk_combo_box_set_popup_fixed_width"
(** Specifies whether the popup’s width should be a fixed width.

If @fixed is %TRUE, the popup's width is set to match the
allocated width of the combo box. *)

external set_model : t -> Tree_model.t option -> unit
  = "ml_gtk_combo_box_set_model"
(** Sets the model used by @combo_box to be @model.

Will unset a previously set model (if applicable). If model is %NULL,
then it will unset the model.

Note that this function does not clear the cell renderers, you have to
call [method@Gtk.CellLayout.clear] yourself if you need to set up different
cell renderers for the new model. *)

external set_id_column : t -> int -> unit = "ml_gtk_combo_box_set_id_column"
(** Sets the model column which @combo_box should use to get string IDs
for values from.

The column @id_column in the model of @combo_box must be of type
%G_TYPE_STRING. *)

external set_entry_text_column : t -> int -> unit
  = "ml_gtk_combo_box_set_entry_text_column"
(** Sets the model column which @combo_box should use to get strings
from to be @text_column.

For this column no separate
[class@Gtk.CellRenderer] is needed.

The column @text_column in the model of @combo_box must be of
type %G_TYPE_STRING.

This is only relevant if @combo_box has been created with
[property@Gtk.ComboBox:has-entry] as %TRUE. *)

external set_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_combo_box_set_child"
(** Sets the child widget of @combo_box. *)

external set_button_sensitivity : t -> Gtk_enums.sensitivitytype -> unit
  = "ml_gtk_combo_box_set_button_sensitivity"
(** Sets whether the dropdown button of the combo box should update its
    sensitivity depending on the model contents. *)

external set_active_iter : t -> Tree_iter.t option -> unit
  = "ml_gtk_combo_box_set_active_iter"
(** Sets the current active item to be the one referenced by @iter.

If @iter is %NULL, the active item is unset. *)

external set_active_id : t -> string option -> bool
  = "ml_gtk_combo_box_set_active_id"
(** Changes the active row of @combo_box to the one that has an ID equal to
@active_id.

If @active_id is %NULL, the active row is unset. Rows having
a %NULL ID string cannot be made active by this function.

If the [property@Gtk.ComboBox:id-column] property of @combo_box is
unset or if no row has the given ID then the function does nothing
and returns %FALSE. *)

external set_active : t -> int -> unit = "ml_gtk_combo_box_set_active"
(** Sets the active item of @combo_box to be the item at @index. *)

external popup_for_device : t -> Ocgtk_gdk.Gdk.Wrappers.Device.t -> unit
  = "ml_gtk_combo_box_popup_for_device"
(** Pops up the menu of @combo_box.

Note that currently this does not do anything with the device, as it was
previously only used for list-mode combo boxes, and those were removed
in GTK 4. However, it is retained in case similar functionality is added
back later. *)

external popup : t -> unit = "ml_gtk_combo_box_popup"
(** Pops up the menu or dropdown list of @combo_box.

This function is mostly intended for use by accessibility technologies;
applications should have little use for it.

Before calling this, @combo_box must be mapped, or nothing will happen. *)

external popdown : t -> unit = "ml_gtk_combo_box_popdown"
(** Hides the menu or dropdown list of @combo_box.

This function is mostly intended for use by accessibility technologies;
applications should have little use for it. *)

external get_popup_fixed_width : t -> bool
  = "ml_gtk_combo_box_get_popup_fixed_width"
(** Gets whether the popup uses a fixed width. *)

external get_model : t -> Tree_model.t option = "ml_gtk_combo_box_get_model"
(** Returns the `GtkTreeModel` of @combo_box. *)

external get_id_column : t -> int = "ml_gtk_combo_box_get_id_column"
(** Returns the column which @combo_box is using to get string IDs
for values from. *)

external get_has_entry : t -> bool = "ml_gtk_combo_box_get_has_entry"
(** Returns whether the combo box has an entry. *)

external get_entry_text_column : t -> int
  = "ml_gtk_combo_box_get_entry_text_column"
(** Returns the column which @combo_box is using to get the strings
from to display in the internal entry. *)

external get_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_combo_box_get_child"
(** Gets the child widget of @combo_box. *)

external get_button_sensitivity : t -> Gtk_enums.sensitivitytype
  = "ml_gtk_combo_box_get_button_sensitivity"
(** Returns whether the combo box sets the dropdown button sensitive or not when
    there are no items in the model. *)

external get_active_iter : t -> bool * Tree_iter.t
  = "ml_gtk_combo_box_get_active_iter"
(** Sets @iter to point to the currently active item.

If no item is active, @iter is left unchanged. *)

external get_active_id : t -> string option = "ml_gtk_combo_box_get_active_id"
(** Returns the ID of the active row of @combo_box.

This value is taken from the active row and the column specified
by the [property@Gtk.ComboBox:id-column] property of @combo_box
(see [method@Gtk.ComboBox.set_id_column]).

The returned value is an interned string which means that you can
compare the pointer by value to other interned strings and that you
must not free it.

If the [property@Gtk.ComboBox:id-column] property of @combo_box is
not set, or if no row is active, or if the active row has a %NULL
ID value, then %NULL is returned. *)

external get_active : t -> int = "ml_gtk_combo_box_get_active"
(** Returns the index of the currently active item.

    If the model is a non-flat treemodel, and the active item is not an
    immediate child of the root of the tree, this function returns
    `gtk_tree_path_get_indices (path)[0]`, where `path` is the
    [struct@Gtk.TreePath] of the active item. *)

(* Properties *)

external get_has_frame : t -> bool = "ml_gtk_combo_box_get_has_frame"
(** Get property: has-frame *)

external set_has_frame : t -> bool -> unit = "ml_gtk_combo_box_set_has_frame"
(** Set property: has-frame *)

external get_popup_shown : t -> bool = "ml_gtk_combo_box_get_popup_shown"
(** Get property: popup-shown *)

val on_activate :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_changed :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_format_entry_text :
  ?after:bool ->
  t ->
  callback:(path:string -> string) ->
  Gobject.Signal.handler_id

val on_move_active :
  ?after:bool ->
  t ->
  callback:(scroll_type:Gtk_enums.scrolltype -> unit) ->
  Gobject.Signal.handler_id

val on_popdown :
  ?after:bool -> t -> callback:(unit -> bool) -> Gobject.Signal.handler_id

val on_popup :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
