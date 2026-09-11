(* GENERATED CODE - DO NOT EDIT *)
(* TreeViewColumn: TreeViewColumn *)

type t = [ `tree_view_column | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_tree_view_column_get_type"

external new_ : unit -> t = "ml_gtk_tree_view_column_new"
(** Create a new TreeViewColumn *)

external new_with_area :
  Cell_area_and__cell_area_context_and__cell_layout.Cell_area.t -> t
  = "ml_gtk_tree_view_column_new_with_area"
(** Create a new TreeViewColumn *)

(* Methods *)

external set_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_tree_view_column_set_widget"
(** Sets the widget in the header to be @widget.  If widget is %NULL, then the
header button is set with a `GtkLabel` set to the title of @tree_column. *)

external set_visible : t -> bool -> unit = "ml_gtk_tree_view_column_set_visible"
(** Sets the visibility of @tree_column. *)

external set_title : t -> string -> unit = "ml_gtk_tree_view_column_set_title"
(** Sets the title of the @tree_column.  If a custom widget has been set, then
this value is ignored. *)

external set_spacing : t -> int -> unit = "ml_gtk_tree_view_column_set_spacing"
(** Sets the spacing field of @tree_column, which is the number of pixels to
place between cell renderers packed into it. *)

external set_sort_order : t -> Gtk_enums.sorttype -> unit
  = "ml_gtk_tree_view_column_set_sort_order"
(** Changes the appearance of the sort indicator.

    This does not actually sort the model. Use
    gtk_tree_view_column_set_sort_column_id() if you want automatic sorting
    support. This function is primarily for custom sorting behavior, and should
    be used in conjunction with gtk_tree_sortable_set_sort_column_id() to do
    that. For custom models, the mechanism will vary.

    The sort indicator changes direction to indicate normal sort or reverse
    sort. Note that you must have the sort indicator enabled to see anything
    when calling this function; see gtk_tree_view_column_set_sort_indicator().
*)

external set_sort_indicator : t -> bool -> unit
  = "ml_gtk_tree_view_column_set_sort_indicator"
(** Call this function with a @setting of %TRUE to display an arrow in
the header button indicating the column is sorted. Call
gtk_tree_view_column_set_sort_order() to change the direction of
the arrow. *)

external set_sort_column_id : t -> int -> unit
  = "ml_gtk_tree_view_column_set_sort_column_id"
(** Sets the logical @sort_column_id that this column sorts on when this column
is selected for sorting.  Doing so makes the column header clickable. *)

external set_sizing : t -> Gtk_enums.treeviewcolumnsizing -> unit
  = "ml_gtk_tree_view_column_set_sizing"
(** Sets the growth behavior of @tree_column to @type. *)

external set_resizable : t -> bool -> unit
  = "ml_gtk_tree_view_column_set_resizable"
(** If @resizable is %TRUE, then the user can explicitly resize the column by
grabbing the outer edge of the column button.

If resizable is %TRUE and
sizing mode of the column is %GTK_TREE_VIEW_COLUMN_AUTOSIZE, then the sizing
mode is changed to %GTK_TREE_VIEW_COLUMN_GROW_ONLY. *)

external set_reorderable : t -> bool -> unit
  = "ml_gtk_tree_view_column_set_reorderable"
(** If @reorderable is %TRUE, then the column can be reordered by the end user
dragging the header. *)

external set_min_width : t -> int -> unit
  = "ml_gtk_tree_view_column_set_min_width"
(** Sets the minimum width of the @tree_column.  If @min_width is -1, then the
minimum width is unset. *)

external set_max_width : t -> int -> unit
  = "ml_gtk_tree_view_column_set_max_width"
(** Sets the maximum width of the @tree_column.  If @max_width is -1, then the
maximum width is unset.  Note, the column can actually be wider than max
width if it’s the last column in a view.  In this case, the column expands to
fill any extra space. *)

external set_fixed_width : t -> int -> unit
  = "ml_gtk_tree_view_column_set_fixed_width"
(** If @fixed_width is not -1, sets the fixed width of @tree_column; otherwise
unsets it.  The effective value of @fixed_width is clamped between the
minimum and maximum width of the column; however, the value stored in the
“fixed-width” property is not clamped.  If the column sizing is
%GTK_TREE_VIEW_COLUMN_GROW_ONLY or %GTK_TREE_VIEW_COLUMN_AUTOSIZE, setting
a fixed width overrides the automatically calculated width.  Note that
@fixed_width is only a hint to GTK; the width actually allocated to the
column may be greater or less than requested.

Along with “expand”, the “fixed-width” property changes when the column is
resized by the user. *)

external set_expand : t -> bool -> unit = "ml_gtk_tree_view_column_set_expand"
(** Sets the column to take available extra space. This space is shared equally
    amongst all columns that have the expand set to %TRUE. If no column has this
    option set, then the last column gets all extra space. By default, every
    column is created with this %FALSE.

    Along with “fixed-width”, the “expand” property changes when the column is
    resized by the user. *)

external set_clickable : t -> bool -> unit
  = "ml_gtk_tree_view_column_set_clickable"
(** Sets the header to be active if @clickable is %TRUE.  When the header is
active, then it can take keyboard focus, and can be clicked. *)

external set_alignment : t -> float -> unit
  = "ml_gtk_tree_view_column_set_alignment"
(** Sets the alignment of the title or custom widget inside the column header.
    The alignment determines its location inside the button -- 0.0 for left, 0.5
    for center, 1.0 for right. *)

external queue_resize : t -> unit = "ml_gtk_tree_view_column_queue_resize"
(** Flags the column, and the cell renderers added to this column, to have their
    sizes renegotiated. *)

external pack_start : t -> Cell_renderer.t -> bool -> unit
  = "ml_gtk_tree_view_column_pack_start"
(** Packs the @cell into the beginning of the column. If @expand is %FALSE, then
the @cell is allocated no more space than it needs. Any unused space is divided
evenly between cells for which @expand is %TRUE. *)

external pack_end : t -> Cell_renderer.t -> bool -> unit
  = "ml_gtk_tree_view_column_pack_end"
(** Adds the @cell to end of the column. If @expand is %FALSE, then the @cell
is allocated no more space than it needs. Any unused space is divided
evenly between cells for which @expand is %TRUE. *)

external get_x_offset : t -> int = "ml_gtk_tree_view_column_get_x_offset"
(** Returns the current X offset of @tree_column in pixels. *)

external get_width : t -> int = "ml_gtk_tree_view_column_get_width"
(** Returns the current size of @tree_column in pixels. *)

external get_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_tree_view_column_get_widget"
(** Returns the `GtkWidget` in the button on the column header.

    If a custom widget has not been set then %NULL is returned. *)

external get_visible : t -> bool = "ml_gtk_tree_view_column_get_visible"
(** Returns %TRUE if @tree_column is visible. *)

external get_tree_view :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_tree_view_column_get_tree_view"
(** Returns the `GtkTreeView` wherein @tree_column has been inserted.
If @column is currently not inserted in any tree view, %NULL is
returned. *)

external get_title : t -> string = "ml_gtk_tree_view_column_get_title"
(** Returns the title of the widget. *)

external get_spacing : t -> int = "ml_gtk_tree_view_column_get_spacing"
(** Returns the spacing of @tree_column. *)

external get_sort_order : t -> Gtk_enums.sorttype
  = "ml_gtk_tree_view_column_get_sort_order"
(** Gets the value set by gtk_tree_view_column_set_sort_order(). *)

external get_sort_indicator : t -> bool
  = "ml_gtk_tree_view_column_get_sort_indicator"
(** Gets the value set by gtk_tree_view_column_set_sort_indicator(). *)

external get_sort_column_id : t -> int
  = "ml_gtk_tree_view_column_get_sort_column_id"
(** Gets the logical @sort_column_id that the model sorts on
when this column is selected for sorting.

See [method@Gtk.TreeViewColumn.set_sort_column_id]. *)

external get_sizing : t -> Gtk_enums.treeviewcolumnsizing
  = "ml_gtk_tree_view_column_get_sizing"
(** Returns the current type of @tree_column. *)

external get_resizable : t -> bool = "ml_gtk_tree_view_column_get_resizable"
(** Returns %TRUE if the @tree_column can be resized by the end user. *)

external get_reorderable : t -> bool = "ml_gtk_tree_view_column_get_reorderable"
(** Returns %TRUE if the @tree_column can be reordered by the user. *)

external get_min_width : t -> int = "ml_gtk_tree_view_column_get_min_width"
(** Returns the minimum width in pixels of the @tree_column, or -1 if no minimum
width is set. *)

external get_max_width : t -> int = "ml_gtk_tree_view_column_get_max_width"
(** Returns the maximum width in pixels of the @tree_column, or -1 if no maximum
width is set. *)

external get_fixed_width : t -> int = "ml_gtk_tree_view_column_get_fixed_width"
(** Gets the fixed width of the column. This may not be the actual displayed
    width of the column; for that, use gtk_tree_view_column_get_width(). *)

external get_expand : t -> bool = "ml_gtk_tree_view_column_get_expand"
(** Returns %TRUE if the column expands to fill available space. *)

external get_clickable : t -> bool = "ml_gtk_tree_view_column_get_clickable"
(** Returns %TRUE if the user can click on the header for the column. *)

external get_button :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t = "ml_gtk_tree_view_column_get_button"
(** Returns the button used in the treeview column header *)

external get_alignment : t -> float = "ml_gtk_tree_view_column_get_alignment"
(** Returns the current x alignment of @tree_column.  This value can range
between 0.0 and 1.0. *)

external focus_cell : t -> Cell_renderer.t -> unit
  = "ml_gtk_tree_view_column_focus_cell"
(** Sets the current keyboard focus to be at @cell, if the column contains
2 or more editable and activatable cells. *)

external clicked : t -> unit = "ml_gtk_tree_view_column_clicked"
(** Emits the “clicked” signal on the column.  This function will only work if
@tree_column is clickable. *)

external clear_attributes : t -> Cell_renderer.t -> unit
  = "ml_gtk_tree_view_column_clear_attributes"
(** Clears all existing attributes previously set with
    gtk_tree_view_column_set_attributes(). *)

external clear : t -> unit = "ml_gtk_tree_view_column_clear"
(** Unsets all the mappings on all renderers on the @tree_column. *)

external cell_set_cell_data :
  t -> Tree_model.t -> Tree_iter.t -> bool -> bool -> unit
  = "ml_gtk_tree_view_column_cell_set_cell_data"
(** Sets the cell renderer based on the @tree_model and @iter.  That is, for
every attribute mapping in @tree_column, it will get a value from the set
column on the @iter, and use that value to set the attribute on the cell
renderer.  This is used primarily by the `GtkTreeView`. *)

external cell_is_visible : t -> bool = "ml_gtk_tree_view_column_cell_is_visible"
(** Returns %TRUE if any of the cells packed into the @tree_column are visible.
For this to be meaningful, you must first initialize the cells with
gtk_tree_view_column_cell_set_cell_data() *)

external cell_get_size : t -> int * int * int * int
  = "ml_gtk_tree_view_column_cell_get_size"
(** Obtains the width and height needed to render the column. This is used
    primarily by the `GtkTreeView`. *)

external cell_get_position : t -> Cell_renderer.t -> bool * int * int
  = "ml_gtk_tree_view_column_cell_get_position"
(** Obtains the horizontal position and size of a cell in a column.

If the  cell is not found in the column, @start_pos and @width
are not changed and %FALSE is returned. *)

external add_attribute : t -> Cell_renderer.t -> string -> int -> unit
  = "ml_gtk_tree_view_column_add_attribute"
(** Adds an attribute mapping to the list in @tree_column.

The @column is the
column of the model to get a value from, and the @attribute is the
parameter on @cell_renderer to be set from the value. So for example
if column 2 of the model contains strings, you could have the
“text” attribute of a `GtkCellRendererText` get its values from
column 2. *)

(* Properties *)

external get_cell_area :
  t -> Cell_area_and__cell_area_context_and__cell_layout.Cell_area.t
  = "ml_gtk_tree_view_column_get_cell_area"
(** Get property: cell-area *)

val on_clicked :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
