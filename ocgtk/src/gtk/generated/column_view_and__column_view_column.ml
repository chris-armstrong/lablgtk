(* GENERATED CODE - DO NOT EDIT *)
(* Combined modules for cyclic dependencies *)

module rec Column_view : sig
  type t =
    [ `column_view | `widget | `initially_unowned | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gtk_column_view_get_type"

  external new_ : Selection_model.t option -> t = "ml_gtk_column_view_new"
  (** Create a new ColumnView *)

  (* Methods *)

  external sort_by_column :
    t -> Column_view_column.t option -> Gtk_enums.sorttype -> unit
    = "ml_gtk_column_view_sort_by_column"
  (** Sets the sorting of the view.

  This function should be used to set up the initial sorting.
  At runtime, users can change the sorting of a column view
  by clicking on the list headers.

  This call only has an effect if the sorter returned by
  [method@Gtk.ColumnView.get_sorter] is set on a sort model,
  and [method@Gtk.ColumnViewColumn.set_sorter] has been called
  on @column to associate a sorter with the column.

  If @column is unset, the view will be unsorted. *)

  external set_tab_behavior : t -> Gtk_enums.listtabbehavior -> unit
    = "ml_gtk_column_view_set_tab_behavior"
  (** Sets the <kbd>Tab</kbd> key behavior.

      This influences how the <kbd>Tab</kbd> and <kbd>Shift</kbd>+<kbd>Tab</kbd>
      keys move the focus in the columnview. *)

  external set_single_click_activate : t -> bool -> unit
    = "ml_gtk_column_view_set_single_click_activate"
  (** Sets whether rows should be activated on single click and selected on
      hover. *)

  external set_show_row_separators : t -> bool -> unit
    = "ml_gtk_column_view_set_show_row_separators"
  (** Sets whether the list should show separators between rows. *)

  external set_show_column_separators : t -> bool -> unit
    = "ml_gtk_column_view_set_show_column_separators"
  (** Sets whether the list should show separators between columns. *)

  external set_row_factory : t -> List_item_factory.t option -> unit
    = "ml_gtk_column_view_set_row_factory"
  (** Sets the factory used for configuring rows.

      The factory must be for configuring [class@Gtk.ColumnViewRow] objects.

      If this factory is not set - which is the default - then the defaults will
      be used.

      This factory is not used to set the widgets displayed in the individual
      cells. For that see [method@GtkColumnViewColumn.set_factory] and
      [class@GtkColumnViewCell]. *)

  external set_reorderable : t -> bool -> unit
    = "ml_gtk_column_view_set_reorderable"
  (** Sets whether columns should be reorderable by dragging. *)

  external set_model : t -> Selection_model.t option -> unit
    = "ml_gtk_column_view_set_model"
  (** Sets the model to use.

      This must be a [iface@Gtk.SelectionModel]. *)

  external set_header_factory : t -> List_item_factory.t option -> unit
    = "ml_gtk_column_view_set_header_factory"
  (** Sets the factory to use for populating the [class@Gtk.ListHeader] objects
      used in section headers.

      If this factory is set to `NULL`, the list will not show section headers.
  *)

  external set_enable_rubberband : t -> bool -> unit
    = "ml_gtk_column_view_set_enable_rubberband"
  (** Sets whether selections can be changed by dragging with the mouse. *)

  external scroll_to :
    t ->
    int ->
    Column_view_column.t option ->
    Gtk_enums.listscrollflags ->
    Scroll_info.t option ->
    unit = "ml_gtk_column_view_scroll_to"
  (** Scroll to the row at the given position - or cell if a column is
  given - and performs the actions specified in @flags.

  This function works no matter if the columnview is shown or focused.
  If it isn't, then the changes will take effect once that happens. *)

  external remove_column : t -> Column_view_column.t -> unit
    = "ml_gtk_column_view_remove_column"
  (** Removes the @column from the list of columns of @self. *)

  external insert_column : t -> int -> Column_view_column.t -> unit
    = "ml_gtk_column_view_insert_column"
  (** Inserts a column at the given position in the columns of @self.

  If @column is already a column of @self, it will be repositioned. *)

  external get_tab_behavior : t -> Gtk_enums.listtabbehavior
    = "ml_gtk_column_view_get_tab_behavior"
  (** Gets the behavior set for the <kbd>Tab</kbd> key. *)

  external get_sorter : t -> Sorter.t option = "ml_gtk_column_view_get_sorter"
  (** Returns a special sorter that reflects the users sorting choices in the
      column view.

      To allow users to customizable sorting by clicking on column headers, this
      sorter needs to be set on the sort model underneath the model that is
      displayed by the view.

      See [method@Gtk.ColumnViewColumn.set_sorter] for setting up per-column
      sorting.

      Here is an example: ```c gtk_column_view_column_set_sorter (column,
      sorter); gtk_column_view_append_column (view, column); sorter =
      g_object_ref (gtk_column_view_get_sorter (view))); model =
      gtk_sort_list_model_new (store, sorter); selection = gtk_no_selection_new
      (model); gtk_column_view_set_model (view, selection); ``` *)

  external get_single_click_activate : t -> bool
    = "ml_gtk_column_view_get_single_click_activate"
  (** Returns whether rows will be activated on single click and selected on
      hover. *)

  external get_show_row_separators : t -> bool
    = "ml_gtk_column_view_get_show_row_separators"
  (** Returns whether the list should show separators between rows. *)

  external get_show_column_separators : t -> bool
    = "ml_gtk_column_view_get_show_column_separators"
  (** Returns whether the list should show separators between columns. *)

  external get_row_factory : t -> List_item_factory.t option
    = "ml_gtk_column_view_get_row_factory"
  (** Gets the factory set via [method@Gtk.ColumnView.set_row_factory]. *)

  external get_reorderable : t -> bool = "ml_gtk_column_view_get_reorderable"
  (** Returns whether columns are reorderable. *)

  external get_model : t -> Selection_model.t option
    = "ml_gtk_column_view_get_model"
  (** Gets the model that's currently used to read the items displayed. *)

  external get_header_factory : t -> List_item_factory.t option
    = "ml_gtk_column_view_get_header_factory"
  (** Gets the factory that's currently used to populate section headers. *)

  external get_enable_rubberband : t -> bool
    = "ml_gtk_column_view_get_enable_rubberband"
  (** Returns whether rows can be selected by dragging with the mouse. *)

  external get_columns : t -> Ocgtk_gio.Gio.Wrappers.List_model.t
    = "ml_gtk_column_view_get_columns"
  (** Gets the list of columns in this column view.

  This list is constant over the lifetime of @self and can be used to
  monitor changes to the columns of @self by connecting to the
  [signal@Gio.ListModel::items-changed] signal. *)

  external append_column : t -> Column_view_column.t -> unit
    = "ml_gtk_column_view_append_column"
  (** Appends the @column to the end of the columns in @self. *)

  (* Properties *)

  val on_activate :
    ?after:bool ->
    t ->
    callback:(position:int -> unit) ->
    Gobject.Signal.handler_id
end = struct
  type t =
    [ `column_view | `widget | `initially_unowned | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gtk_column_view_get_type"

  external new_ : Selection_model.t option -> t = "ml_gtk_column_view_new"
  (** Create a new ColumnView *)

  (* Methods *)

  external sort_by_column :
    t -> Column_view_column.t option -> Gtk_enums.sorttype -> unit
    = "ml_gtk_column_view_sort_by_column"
  (** Sets the sorting of the view.

  This function should be used to set up the initial sorting.
  At runtime, users can change the sorting of a column view
  by clicking on the list headers.

  This call only has an effect if the sorter returned by
  [method@Gtk.ColumnView.get_sorter] is set on a sort model,
  and [method@Gtk.ColumnViewColumn.set_sorter] has been called
  on @column to associate a sorter with the column.

  If @column is unset, the view will be unsorted. *)

  external set_tab_behavior : t -> Gtk_enums.listtabbehavior -> unit
    = "ml_gtk_column_view_set_tab_behavior"
  (** Sets the <kbd>Tab</kbd> key behavior.

      This influences how the <kbd>Tab</kbd> and <kbd>Shift</kbd>+<kbd>Tab</kbd>
      keys move the focus in the columnview. *)

  external set_single_click_activate : t -> bool -> unit
    = "ml_gtk_column_view_set_single_click_activate"
  (** Sets whether rows should be activated on single click and selected on
      hover. *)

  external set_show_row_separators : t -> bool -> unit
    = "ml_gtk_column_view_set_show_row_separators"
  (** Sets whether the list should show separators between rows. *)

  external set_show_column_separators : t -> bool -> unit
    = "ml_gtk_column_view_set_show_column_separators"
  (** Sets whether the list should show separators between columns. *)

  external set_row_factory : t -> List_item_factory.t option -> unit
    = "ml_gtk_column_view_set_row_factory"
  (** Sets the factory used for configuring rows.

      The factory must be for configuring [class@Gtk.ColumnViewRow] objects.

      If this factory is not set - which is the default - then the defaults will
      be used.

      This factory is not used to set the widgets displayed in the individual
      cells. For that see [method@GtkColumnViewColumn.set_factory] and
      [class@GtkColumnViewCell]. *)

  external set_reorderable : t -> bool -> unit
    = "ml_gtk_column_view_set_reorderable"
  (** Sets whether columns should be reorderable by dragging. *)

  external set_model : t -> Selection_model.t option -> unit
    = "ml_gtk_column_view_set_model"
  (** Sets the model to use.

      This must be a [iface@Gtk.SelectionModel]. *)

  external set_header_factory : t -> List_item_factory.t option -> unit
    = "ml_gtk_column_view_set_header_factory"
  (** Sets the factory to use for populating the [class@Gtk.ListHeader] objects
      used in section headers.

      If this factory is set to `NULL`, the list will not show section headers.
  *)

  external set_enable_rubberband : t -> bool -> unit
    = "ml_gtk_column_view_set_enable_rubberband"
  (** Sets whether selections can be changed by dragging with the mouse. *)

  external scroll_to :
    t ->
    int ->
    Column_view_column.t option ->
    Gtk_enums.listscrollflags ->
    Scroll_info.t option ->
    unit = "ml_gtk_column_view_scroll_to"
  (** Scroll to the row at the given position - or cell if a column is
  given - and performs the actions specified in @flags.

  This function works no matter if the columnview is shown or focused.
  If it isn't, then the changes will take effect once that happens. *)

  external remove_column : t -> Column_view_column.t -> unit
    = "ml_gtk_column_view_remove_column"
  (** Removes the @column from the list of columns of @self. *)

  external insert_column : t -> int -> Column_view_column.t -> unit
    = "ml_gtk_column_view_insert_column"
  (** Inserts a column at the given position in the columns of @self.

  If @column is already a column of @self, it will be repositioned. *)

  external get_tab_behavior : t -> Gtk_enums.listtabbehavior
    = "ml_gtk_column_view_get_tab_behavior"
  (** Gets the behavior set for the <kbd>Tab</kbd> key. *)

  external get_sorter : t -> Sorter.t option = "ml_gtk_column_view_get_sorter"
  (** Returns a special sorter that reflects the users sorting choices in the
      column view.

      To allow users to customizable sorting by clicking on column headers, this
      sorter needs to be set on the sort model underneath the model that is
      displayed by the view.

      See [method@Gtk.ColumnViewColumn.set_sorter] for setting up per-column
      sorting.

      Here is an example: ```c gtk_column_view_column_set_sorter (column,
      sorter); gtk_column_view_append_column (view, column); sorter =
      g_object_ref (gtk_column_view_get_sorter (view))); model =
      gtk_sort_list_model_new (store, sorter); selection = gtk_no_selection_new
      (model); gtk_column_view_set_model (view, selection); ``` *)

  external get_single_click_activate : t -> bool
    = "ml_gtk_column_view_get_single_click_activate"
  (** Returns whether rows will be activated on single click and selected on
      hover. *)

  external get_show_row_separators : t -> bool
    = "ml_gtk_column_view_get_show_row_separators"
  (** Returns whether the list should show separators between rows. *)

  external get_show_column_separators : t -> bool
    = "ml_gtk_column_view_get_show_column_separators"
  (** Returns whether the list should show separators between columns. *)

  external get_row_factory : t -> List_item_factory.t option
    = "ml_gtk_column_view_get_row_factory"
  (** Gets the factory set via [method@Gtk.ColumnView.set_row_factory]. *)

  external get_reorderable : t -> bool = "ml_gtk_column_view_get_reorderable"
  (** Returns whether columns are reorderable. *)

  external get_model : t -> Selection_model.t option
    = "ml_gtk_column_view_get_model"
  (** Gets the model that's currently used to read the items displayed. *)

  external get_header_factory : t -> List_item_factory.t option
    = "ml_gtk_column_view_get_header_factory"
  (** Gets the factory that's currently used to populate section headers. *)

  external get_enable_rubberband : t -> bool
    = "ml_gtk_column_view_get_enable_rubberband"
  (** Returns whether rows can be selected by dragging with the mouse. *)

  external get_columns : t -> Ocgtk_gio.Gio.Wrappers.List_model.t
    = "ml_gtk_column_view_get_columns"
  (** Gets the list of columns in this column view.

  This list is constant over the lifetime of @self and can be used to
  monitor changes to the columns of @self by connecting to the
  [signal@Gio.ListModel::items-changed] signal. *)

  external append_column : t -> Column_view_column.t -> unit
    = "ml_gtk_column_view_append_column"
  (** Appends the @column to the end of the columns in @self. *)

  (* Properties *)

  let on_activate ?after obj ~callback =
    let closure =
      Gobject.Closure.create (fun argv ->
          let position =
            let v = Gobject.Closure.nth argv ~pos:1 in
            Gobject.Value.get_uint v
          in
          callback ~position)
    in
    Gobject.Signal.connect obj ~name:"activate" ~callback:closure
      ~after:(Option.value after ~default:false)
end

and Column_view_column : sig
  type t = [ `column_view_column | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gtk_column_view_column_get_type"

  external new_ : string option -> List_item_factory.t option -> t
    = "ml_gtk_column_view_column_new"
  (** Create a new ColumnViewColumn *)

  (* Methods *)

  external set_visible : t -> bool -> unit
    = "ml_gtk_column_view_column_set_visible"
  (** Sets whether this column should be visible in views. *)

  external set_title : t -> string option -> unit
    = "ml_gtk_column_view_column_set_title"
  (** Sets the title of this column.

      The title is displayed in the header of a `GtkColumnView` for this column
      and is therefore user-facing text that should be translated. *)

  external set_sorter : t -> Sorter.t option -> unit
    = "ml_gtk_column_view_column_set_sorter"
  (** Associates a sorter with the column.

  If @sorter is unset, the column will not let users change
  the sorting by clicking on its header.

  This sorter can be made active by clicking on the column
  header, or by calling [method@Gtk.ColumnView.sort_by_column].

  See [method@Gtk.ColumnView.get_sorter] for the necessary steps
  for setting up customizable sorting for [class@Gtk.ColumnView]. *)

  external set_resizable : t -> bool -> unit
    = "ml_gtk_column_view_column_set_resizable"
  (** Sets whether this column should be resizable by dragging. *)

  external set_id : t -> string option -> unit
    = "ml_gtk_column_view_column_set_id"
  (** Sets the id of this column.

      GTK makes no use of this, but applications can use it when storing column
      view configuration.

      It is up to callers to ensure uniqueness of IDs. *)

  external set_header_menu :
    t -> Ocgtk_gio.Gio.Wrappers.Menu_model.t option -> unit
    = "ml_gtk_column_view_column_set_header_menu"
  (** Sets the menu model that is used to create the context menu for the column
      header. *)

  external set_fixed_width : t -> int -> unit
    = "ml_gtk_column_view_column_set_fixed_width"
  (** Sets the fixed width of the column.

  If @fixed_width is -1, the fixed width of the column is unset.

  Setting a fixed width overrides the automatically calculated
  width. Interactive resizing also sets the “fixed-width” property. *)

  external set_factory : t -> List_item_factory.t option -> unit
    = "ml_gtk_column_view_column_set_factory"
  (** Sets the `GtkListItemFactory` to use for populating list items for this
      column. *)

  external set_expand : t -> bool -> unit
    = "ml_gtk_column_view_column_set_expand"
  (** Sets the column to take available extra space.

      The extra space is shared equally amongst all columns that have are set to
      expand. *)

  external get_visible : t -> bool = "ml_gtk_column_view_column_get_visible"
  (** Returns whether this column is visible. *)

  external get_title : t -> string option
    = "ml_gtk_column_view_column_get_title"
  (** Returns the title set with [method@Gtk.ColumnViewColumn.set_title]. *)

  external get_sorter : t -> Sorter.t option
    = "ml_gtk_column_view_column_get_sorter"
  (** Returns the sorter that is associated with the column. *)

  external get_resizable : t -> bool = "ml_gtk_column_view_column_get_resizable"
  (** Returns whether this column is resizable. *)

  external get_id : t -> string option = "ml_gtk_column_view_column_get_id"
  (** Returns the ID set with [method@Gtk.ColumnViewColumn.set_id]. *)

  external get_header_menu : t -> Ocgtk_gio.Gio.Wrappers.Menu_model.t option
    = "ml_gtk_column_view_column_get_header_menu"
  (** Gets the menu model that is used to create the context menu for the column
      header. *)

  external get_fixed_width : t -> int
    = "ml_gtk_column_view_column_get_fixed_width"
  (** Gets the fixed width of the column. *)

  external get_factory : t -> List_item_factory.t option
    = "ml_gtk_column_view_column_get_factory"
  (** Gets the factory that's currently used to populate list items for this
      column. *)

  external get_expand : t -> bool = "ml_gtk_column_view_column_get_expand"
  (** Returns whether this column should expand. *)

  external get_column_view : t -> Column_view.t option
    = "ml_gtk_column_view_column_get_column_view"
  (** Gets the column view that's currently displaying this column.

  If @self has not been added to a column view yet, `NULL` is returned. *)

  (* Properties *)
end = struct
  type t = [ `column_view_column | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gtk_column_view_column_get_type"

  external new_ : string option -> List_item_factory.t option -> t
    = "ml_gtk_column_view_column_new"
  (** Create a new ColumnViewColumn *)

  (* Methods *)

  external set_visible : t -> bool -> unit
    = "ml_gtk_column_view_column_set_visible"
  (** Sets whether this column should be visible in views. *)

  external set_title : t -> string option -> unit
    = "ml_gtk_column_view_column_set_title"
  (** Sets the title of this column.

      The title is displayed in the header of a `GtkColumnView` for this column
      and is therefore user-facing text that should be translated. *)

  external set_sorter : t -> Sorter.t option -> unit
    = "ml_gtk_column_view_column_set_sorter"
  (** Associates a sorter with the column.

  If @sorter is unset, the column will not let users change
  the sorting by clicking on its header.

  This sorter can be made active by clicking on the column
  header, or by calling [method@Gtk.ColumnView.sort_by_column].

  See [method@Gtk.ColumnView.get_sorter] for the necessary steps
  for setting up customizable sorting for [class@Gtk.ColumnView]. *)

  external set_resizable : t -> bool -> unit
    = "ml_gtk_column_view_column_set_resizable"
  (** Sets whether this column should be resizable by dragging. *)

  external set_id : t -> string option -> unit
    = "ml_gtk_column_view_column_set_id"
  (** Sets the id of this column.

      GTK makes no use of this, but applications can use it when storing column
      view configuration.

      It is up to callers to ensure uniqueness of IDs. *)

  external set_header_menu :
    t -> Ocgtk_gio.Gio.Wrappers.Menu_model.t option -> unit
    = "ml_gtk_column_view_column_set_header_menu"
  (** Sets the menu model that is used to create the context menu for the column
      header. *)

  external set_fixed_width : t -> int -> unit
    = "ml_gtk_column_view_column_set_fixed_width"
  (** Sets the fixed width of the column.

  If @fixed_width is -1, the fixed width of the column is unset.

  Setting a fixed width overrides the automatically calculated
  width. Interactive resizing also sets the “fixed-width” property. *)

  external set_factory : t -> List_item_factory.t option -> unit
    = "ml_gtk_column_view_column_set_factory"
  (** Sets the `GtkListItemFactory` to use for populating list items for this
      column. *)

  external set_expand : t -> bool -> unit
    = "ml_gtk_column_view_column_set_expand"
  (** Sets the column to take available extra space.

      The extra space is shared equally amongst all columns that have are set to
      expand. *)

  external get_visible : t -> bool = "ml_gtk_column_view_column_get_visible"
  (** Returns whether this column is visible. *)

  external get_title : t -> string option
    = "ml_gtk_column_view_column_get_title"
  (** Returns the title set with [method@Gtk.ColumnViewColumn.set_title]. *)

  external get_sorter : t -> Sorter.t option
    = "ml_gtk_column_view_column_get_sorter"
  (** Returns the sorter that is associated with the column. *)

  external get_resizable : t -> bool = "ml_gtk_column_view_column_get_resizable"
  (** Returns whether this column is resizable. *)

  external get_id : t -> string option = "ml_gtk_column_view_column_get_id"
  (** Returns the ID set with [method@Gtk.ColumnViewColumn.set_id]. *)

  external get_header_menu : t -> Ocgtk_gio.Gio.Wrappers.Menu_model.t option
    = "ml_gtk_column_view_column_get_header_menu"
  (** Gets the menu model that is used to create the context menu for the column
      header. *)

  external get_fixed_width : t -> int
    = "ml_gtk_column_view_column_get_fixed_width"
  (** Gets the fixed width of the column. *)

  external get_factory : t -> List_item_factory.t option
    = "ml_gtk_column_view_column_get_factory"
  (** Gets the factory that's currently used to populate list items for this
      column. *)

  external get_expand : t -> bool = "ml_gtk_column_view_column_get_expand"
  (** Returns whether this column should expand. *)

  external get_column_view : t -> Column_view.t option
    = "ml_gtk_column_view_column_get_column_view"
  (** Gets the column view that's currently displaying this column.

  If @self has not been added to a column view yet, `NULL` is returned. *)

  (* Properties *)
end
