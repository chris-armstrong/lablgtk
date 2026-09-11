(* GENERATED CODE - DO NOT EDIT *)
(* GridView: GridView *)

type t =
  [ `grid_view | `list_base | `widget | `initially_unowned | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_grid_view_get_type"

external new_ : Selection_model.t option -> List_item_factory.t option -> t
  = "ml_gtk_grid_view_new"
(** Create a new GridView *)

(* Methods *)

external set_tab_behavior : t -> Gtk_enums.listtabbehavior -> unit
  = "ml_gtk_grid_view_set_tab_behavior"
(** Sets the behavior of the <kbd>Tab</kbd> and <kbd>Shift</kbd>+<kbd>Tab</kbd>
    keys. *)

external set_single_click_activate : t -> bool -> unit
  = "ml_gtk_grid_view_set_single_click_activate"
(** Sets whether items should be activated on single click and selected on
    hover. *)

external set_model : t -> Selection_model.t option -> unit
  = "ml_gtk_grid_view_set_model"
(** Sets the model to use.

    This must be a [iface@Gtk.SelectionModel]. *)

external set_min_columns : t -> int -> unit = "ml_gtk_grid_view_set_min_columns"
(** Sets the minimum number of columns to use.

This number must be at least 1.

If @min_columns is smaller than the minimum set via
[method@Gtk.GridView.set_max_columns], that value is ignored. *)

external set_max_columns : t -> int -> unit = "ml_gtk_grid_view_set_max_columns"
(** Sets the maximum number of columns to use.

This number must be at least 1.

If @max_columns is smaller than the minimum set via
[method@Gtk.GridView.set_min_columns], that value is used instead. *)

external set_factory : t -> List_item_factory.t option -> unit
  = "ml_gtk_grid_view_set_factory"
(** Sets the `GtkListItemFactory` to use for populating list items. *)

external set_enable_rubberband : t -> bool -> unit
  = "ml_gtk_grid_view_set_enable_rubberband"
(** Sets whether selections can be changed by dragging with the mouse. *)

external scroll_to :
  t -> int -> Gtk_enums.listscrollflags -> Scroll_info.t option -> unit
  = "ml_gtk_grid_view_scroll_to"
(** Scrolls to the item at the given position and performs the actions
specified in @flags.

This function works no matter if the gridview is shown or focused.
If it isn't, then the changes will take effect once that happens. *)

external get_tab_behavior : t -> Gtk_enums.listtabbehavior
  = "ml_gtk_grid_view_get_tab_behavior"
(** Gets the behavior set for the <kbd>Tab</kbd> key. *)

external get_single_click_activate : t -> bool
  = "ml_gtk_grid_view_get_single_click_activate"
(** Returns whether items will be activated on single click and selected on
    hover. *)

external get_model : t -> Selection_model.t option
  = "ml_gtk_grid_view_get_model"
(** Gets the model that's currently used to read the items displayed. *)

external get_min_columns : t -> int = "ml_gtk_grid_view_get_min_columns"
(** Gets the minimum number of columns that the grid will use. *)

external get_max_columns : t -> int = "ml_gtk_grid_view_get_max_columns"
(** Gets the maximum number of columns that the grid will use. *)

external get_factory : t -> List_item_factory.t option
  = "ml_gtk_grid_view_get_factory"
(** Gets the factory that's currently used to populate list items. *)

external get_enable_rubberband : t -> bool
  = "ml_gtk_grid_view_get_enable_rubberband"
(** Returns whether rows can be selected by dragging with the mouse. *)

(* Properties *)

val on_activate :
  ?after:bool ->
  t ->
  callback:(position:int -> unit) ->
  Gobject.Signal.handler_id
