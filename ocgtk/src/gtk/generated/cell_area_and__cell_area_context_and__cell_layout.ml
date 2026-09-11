(* GENERATED CODE - DO NOT EDIT *)
(* Combined modules for cyclic dependencies *)

module rec Cell_area : sig
  type t = [ `cell_area | `initially_unowned | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gtk_cell_area_get_type"

  (* Methods *)

  external stop_editing : t -> bool -> unit = "ml_gtk_cell_area_stop_editing"
  (** Explicitly stops the editing of the currently edited cell.

  If @canceled is %TRUE, the currently edited cell renderer
  will emit the ::editing-canceled signal, otherwise the
  the ::editing-done signal will be emitted on the current
  edit widget.

  See gtk_cell_area_get_edited_cell() and gtk_cell_area_get_edit_widget(). *)

  external snapshot :
    t ->
    Cell_area_context.t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    Snapshot.t ->
    Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
    Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
    Gtk_enums.cellrendererstate ->
    bool ->
    unit
    = "ml_gtk_cell_area_snapshot_bytecode" "ml_gtk_cell_area_snapshot_native"
  (** Snapshots @area’s cells according to @area’s layout onto at
  the given coordinates. *)

  external set_focus_cell : t -> Cell_renderer.t option -> unit
    = "ml_gtk_cell_area_set_focus_cell"
  (** Explicitly sets the currently focused cell to @renderer.

  This is generally called by implementations of
  `GtkCellAreaClass.focus()` or `GtkCellAreaClass.event()`,
  however it can also be used to implement functions such
  as gtk_tree_view_set_cursor_on_cell(). *)

  external request_renderer :
    t ->
    Cell_renderer.t ->
    Gtk_enums.orientation ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    int ->
    int * int = "ml_gtk_cell_area_request_renderer"
  (** This is a convenience function for `GtkCellArea` implementations to
      request size for cell renderers. It’s important to use this function to
      request size and then use gtk_cell_area_inner_cell_area() at render and
      event time since this function will add padding around the cell for focus
      painting. *)

  external remove_focus_sibling :
    t -> Cell_renderer.t -> Cell_renderer.t -> unit
    = "ml_gtk_cell_area_remove_focus_sibling"
  (** Removes @sibling from @renderer’s focus sibling list
  (see gtk_cell_area_add_focus_sibling()). *)

  external remove : t -> Cell_renderer.t -> unit = "ml_gtk_cell_area_remove"
  (** Removes @renderer from @area. *)

  external is_focus_sibling : t -> Cell_renderer.t -> Cell_renderer.t -> bool
    = "ml_gtk_cell_area_is_focus_sibling"
  (** Returns whether @sibling is one of @renderer’s focus siblings
  (see gtk_cell_area_add_focus_sibling()). *)

  external is_activatable : t -> bool = "ml_gtk_cell_area_is_activatable"
  (** Returns whether the area can do anything when activated,
  after applying new attributes to @area. *)

  external inner_cell_area :
    t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
    Ocgtk_gdk.Gdk.Wrappers.Rectangle.t = "ml_gtk_cell_area_inner_cell_area"
  (** This is a convenience function for `GtkCellArea` implementations to get
      the inner area where a given `GtkCellRenderer` will be rendered. It
      removes any padding previously added by gtk_cell_area_request_renderer().
  *)

  external has_renderer : t -> Cell_renderer.t -> bool
    = "ml_gtk_cell_area_has_renderer"
  (** Checks if @area contains @renderer. *)

  external get_request_mode : t -> Gtk_enums.sizerequestmode
    = "ml_gtk_cell_area_get_request_mode"
  (** Gets whether the area prefers a height-for-width layout or a
      width-for-height layout. *)

  external get_preferred_width_for_height :
    t ->
    Cell_area_context.t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    int ->
    int * int = "ml_gtk_cell_area_get_preferred_width_for_height"
  (** Retrieves a cell area’s minimum and natural width if it would be given
  the specified @height.

  @area stores some geometrical information in @context along the way
  while calling gtk_cell_area_get_preferred_height(). It’s important to
  perform a series of gtk_cell_area_get_preferred_height() requests with
  @context first and then call gtk_cell_area_get_preferred_width_for_height()
  on each cell area individually to get the height for width of each
  fully requested row.

  If at some point, the height of a single row changes, it should be
  requested with gtk_cell_area_get_preferred_height() again and then
  the full height of the requested rows checked again with
  gtk_cell_area_context_get_preferred_height(). *)

  external get_preferred_width :
    t ->
    Cell_area_context.t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    int * int = "ml_gtk_cell_area_get_preferred_width"
  (** Retrieves a cell area’s initial minimum and natural width.

  @area will store some geometrical information in @context along the way;
  when requesting sizes over an arbitrary number of rows, it’s not important
  to check the @minimum_width and @natural_width of this call but rather to
  consult gtk_cell_area_context_get_preferred_width() after a series of
  requests. *)

  external get_preferred_height_for_width :
    t ->
    Cell_area_context.t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    int ->
    int * int = "ml_gtk_cell_area_get_preferred_height_for_width"
  (** Retrieves a cell area’s minimum and natural height if it would be given
  the specified @width.

  @area stores some geometrical information in @context along the way
  while calling gtk_cell_area_get_preferred_width(). It’s important to
  perform a series of gtk_cell_area_get_preferred_width() requests with
  @context first and then call gtk_cell_area_get_preferred_height_for_width()
  on each cell area individually to get the height for width of each
  fully requested row.

  If at some point, the width of a single row changes, it should be
  requested with gtk_cell_area_get_preferred_width() again and then
  the full width of the requested rows checked again with
  gtk_cell_area_context_get_preferred_width(). *)

  external get_preferred_height :
    t ->
    Cell_area_context.t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    int * int = "ml_gtk_cell_area_get_preferred_height"
  (** Retrieves a cell area’s initial minimum and natural height.

  @area will store some geometrical information in @context along the way;
  when requesting sizes over an arbitrary number of rows, it’s not important
  to check the @minimum_height and @natural_height of this call but rather to
  consult gtk_cell_area_context_get_preferred_height() after a series of
  requests. *)

  external get_focus_siblings : t -> Cell_renderer.t -> Cell_renderer.t list
    = "ml_gtk_cell_area_get_focus_siblings"
  (** Gets the focus sibling cell renderers for @renderer. *)

  external get_focus_from_sibling :
    t -> Cell_renderer.t -> Cell_renderer.t option
    = "ml_gtk_cell_area_get_focus_from_sibling"
  (** Gets the `GtkCellRenderer` which is expected to be focusable
  for which @renderer is, or may be a sibling.

  This is handy for `GtkCellArea` subclasses when handling events,
  after determining the renderer at the event location it can
  then chose to activate the focus cell for which the event
  cell may have been a sibling. *)

  external get_focus_cell : t -> Cell_renderer.t option
    = "ml_gtk_cell_area_get_focus_cell"
  (** Retrieves the currently focused cell for @area *)

  external get_edited_cell : t -> Cell_renderer.t option
    = "ml_gtk_cell_area_get_edited_cell"
  (** Gets the `GtkCellRenderer` in @area that is currently
  being edited. *)

  external get_edit_widget : t -> Cell_editable.t option
    = "ml_gtk_cell_area_get_edit_widget"
  (** Gets the `GtkCellEditable` widget currently used to edit the currently
      edited cell. *)

  external get_current_path_string : t -> string
    = "ml_gtk_cell_area_get_current_path_string"
  (** Gets the current `GtkTreePath` string for the currently applied
      `GtkTreeIter`, this is implicitly updated when
      gtk_cell_area_apply_attributes() is called and can be used to interact
      with renderers from `GtkCellArea` subclasses. *)

  external get_cell_at_position :
    t ->
    Cell_area_context.t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
    int ->
    int ->
    Cell_renderer.t * Ocgtk_gdk.Gdk.Wrappers.Rectangle.t
    = "ml_gtk_cell_area_get_cell_at_position_bytecode"
      "ml_gtk_cell_area_get_cell_at_position_native"
  (** Gets the `GtkCellRenderer` at @x and @y coordinates inside @area and optionally
  returns the full cell allocation for it inside @cell_area. *)

  external get_cell_allocation :
    t ->
    Cell_area_context.t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    Cell_renderer.t ->
    Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
    Ocgtk_gdk.Gdk.Wrappers.Rectangle.t = "ml_gtk_cell_area_get_cell_allocation"
  (** Derives the allocation of @renderer inside @area if @area
  were to be rendered in @cell_area. *)

  external focus : t -> Gtk_enums.directiontype -> bool
    = "ml_gtk_cell_area_focus"
  (** This should be called by the @area’s owning layout widget
  when focus is to be passed to @area, or moved within @area
  for a given @direction and row data.

  Implementing `GtkCellArea` classes should implement this
  method to receive and navigate focus in its own way particular
  to how it lays out cells. *)

  external event :
    t ->
    Cell_area_context.t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    Ocgtk_gdk.Gdk.Wrappers.Event.t ->
    Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
    Gtk_enums.cellrendererstate ->
    int = "ml_gtk_cell_area_event_bytecode" "ml_gtk_cell_area_event_native"
  (** Delegates event handling to a `GtkCellArea`. *)

  external create_context : t -> Cell_area_context.t
    = "ml_gtk_cell_area_create_context"
  (** Creates a `GtkCellArea`Context to be used with @area for
  all purposes. `GtkCellArea`Context stores geometry information
  for rows for which it was operated on, it is important to use
  the same context for the same row of data at all times (i.e.
  one should render and handle events with the same `GtkCellArea`Context
  which was used to request the size of those rows of data). *)

  external copy_context : t -> Cell_area_context.t -> Cell_area_context.t
    = "ml_gtk_cell_area_copy_context"
  (** This is sometimes needed for cases where rows need to share alignments in
      one orientation but may be separately grouped in the opposing orientation.

      For instance, `GtkIconView` creates all icons (rows) to have the same
      width and the cells theirin to have the same horizontal alignments.
      However each row of icons may have a separate collective height.
      `GtkIconView` uses this to request the heights of each row based on a
      context which was already used to request all the row widths that are to
      be displayed. *)

  external cell_set_property :
    t -> Cell_renderer.t -> string -> Gobject.Value.t -> unit
    = "ml_gtk_cell_area_cell_set_property"
  (** Sets a cell property for @renderer in @area. *)

  external cell_get_property :
    t -> Cell_renderer.t -> string -> Gobject.Value.t -> unit
    = "ml_gtk_cell_area_cell_get_property"
  (** Gets the value of a cell property for @renderer in @area. *)

  external attribute_get_column : t -> Cell_renderer.t -> string -> int
    = "ml_gtk_cell_area_attribute_get_column"
  (** Returns the model column that an attribute has been mapped to, or -1 if
      the attribute is not mapped. *)

  external attribute_disconnect : t -> Cell_renderer.t -> string -> unit
    = "ml_gtk_cell_area_attribute_disconnect"
  (** Disconnects @attribute for the @renderer in @area so that
  attribute will no longer be updated with values from the
  model. *)

  external attribute_connect : t -> Cell_renderer.t -> string -> int -> unit
    = "ml_gtk_cell_area_attribute_connect"
  (** Connects an @attribute to apply values from @column for the
  `GtkTreeModel` in use. *)

  external apply_attributes :
    t -> Tree_model.t -> Tree_iter.t -> bool -> bool -> unit
    = "ml_gtk_cell_area_apply_attributes"
  (** Applies any connected attributes to the renderers in
  @area by pulling the values from @tree_model. *)

  external add_focus_sibling : t -> Cell_renderer.t -> Cell_renderer.t -> unit
    = "ml_gtk_cell_area_add_focus_sibling"
  (** Adds @sibling to @renderer’s focusable area, focus will be drawn
  around @renderer and all of its siblings if @renderer can
  focus for a given row.

  Events handled by focus siblings can also activate the given
  focusable @renderer. *)

  external add : t -> Cell_renderer.t -> unit = "ml_gtk_cell_area_add"
  (** Adds @renderer to @area with the default child cell properties. *)

  external activate_cell :
    t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    Cell_renderer.t ->
    Ocgtk_gdk.Gdk.Wrappers.Event.t ->
    Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
    Gtk_enums.cellrendererstate ->
    bool
    = "ml_gtk_cell_area_activate_cell_bytecode"
      "ml_gtk_cell_area_activate_cell_native"
  (** This is used by `GtkCellArea` subclasses when handling events to activate
      cells, the base `GtkCellArea` class activates cells for keyboard events
      for free in its own GtkCellArea->activate() implementation. *)

  external activate :
    t ->
    Cell_area_context.t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
    Gtk_enums.cellrendererstate ->
    bool ->
    bool
    = "ml_gtk_cell_area_activate_bytecode" "ml_gtk_cell_area_activate_native"
  (** Activates @area, usually by activating the currently focused
  cell, however some subclasses which embed widgets in the area
  can also activate a widget if it currently has the focus. *)

  (* Properties *)

  val on_focus_changed :
    ?after:bool ->
    t ->
    callback:(renderer:Cell_renderer.t -> path:string -> unit) ->
    Gobject.Signal.handler_id

  val on_remove_editable :
    ?after:bool ->
    t ->
    callback:(renderer:Cell_renderer.t -> editable:Cell_editable.t -> unit) ->
    Gobject.Signal.handler_id
end = struct
  type t = [ `cell_area | `initially_unowned | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gtk_cell_area_get_type"

  (* Methods *)

  external stop_editing : t -> bool -> unit = "ml_gtk_cell_area_stop_editing"
  (** Explicitly stops the editing of the currently edited cell.

  If @canceled is %TRUE, the currently edited cell renderer
  will emit the ::editing-canceled signal, otherwise the
  the ::editing-done signal will be emitted on the current
  edit widget.

  See gtk_cell_area_get_edited_cell() and gtk_cell_area_get_edit_widget(). *)

  external snapshot :
    t ->
    Cell_area_context.t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    Snapshot.t ->
    Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
    Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
    Gtk_enums.cellrendererstate ->
    bool ->
    unit
    = "ml_gtk_cell_area_snapshot_bytecode" "ml_gtk_cell_area_snapshot_native"
  (** Snapshots @area’s cells according to @area’s layout onto at
  the given coordinates. *)

  external set_focus_cell : t -> Cell_renderer.t option -> unit
    = "ml_gtk_cell_area_set_focus_cell"
  (** Explicitly sets the currently focused cell to @renderer.

  This is generally called by implementations of
  `GtkCellAreaClass.focus()` or `GtkCellAreaClass.event()`,
  however it can also be used to implement functions such
  as gtk_tree_view_set_cursor_on_cell(). *)

  external request_renderer :
    t ->
    Cell_renderer.t ->
    Gtk_enums.orientation ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    int ->
    int * int = "ml_gtk_cell_area_request_renderer"
  (** This is a convenience function for `GtkCellArea` implementations to
      request size for cell renderers. It’s important to use this function to
      request size and then use gtk_cell_area_inner_cell_area() at render and
      event time since this function will add padding around the cell for focus
      painting. *)

  external remove_focus_sibling :
    t -> Cell_renderer.t -> Cell_renderer.t -> unit
    = "ml_gtk_cell_area_remove_focus_sibling"
  (** Removes @sibling from @renderer’s focus sibling list
  (see gtk_cell_area_add_focus_sibling()). *)

  external remove : t -> Cell_renderer.t -> unit = "ml_gtk_cell_area_remove"
  (** Removes @renderer from @area. *)

  external is_focus_sibling : t -> Cell_renderer.t -> Cell_renderer.t -> bool
    = "ml_gtk_cell_area_is_focus_sibling"
  (** Returns whether @sibling is one of @renderer’s focus siblings
  (see gtk_cell_area_add_focus_sibling()). *)

  external is_activatable : t -> bool = "ml_gtk_cell_area_is_activatable"
  (** Returns whether the area can do anything when activated,
  after applying new attributes to @area. *)

  external inner_cell_area :
    t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
    Ocgtk_gdk.Gdk.Wrappers.Rectangle.t = "ml_gtk_cell_area_inner_cell_area"
  (** This is a convenience function for `GtkCellArea` implementations to get
      the inner area where a given `GtkCellRenderer` will be rendered. It
      removes any padding previously added by gtk_cell_area_request_renderer().
  *)

  external has_renderer : t -> Cell_renderer.t -> bool
    = "ml_gtk_cell_area_has_renderer"
  (** Checks if @area contains @renderer. *)

  external get_request_mode : t -> Gtk_enums.sizerequestmode
    = "ml_gtk_cell_area_get_request_mode"
  (** Gets whether the area prefers a height-for-width layout or a
      width-for-height layout. *)

  external get_preferred_width_for_height :
    t ->
    Cell_area_context.t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    int ->
    int * int = "ml_gtk_cell_area_get_preferred_width_for_height"
  (** Retrieves a cell area’s minimum and natural width if it would be given
  the specified @height.

  @area stores some geometrical information in @context along the way
  while calling gtk_cell_area_get_preferred_height(). It’s important to
  perform a series of gtk_cell_area_get_preferred_height() requests with
  @context first and then call gtk_cell_area_get_preferred_width_for_height()
  on each cell area individually to get the height for width of each
  fully requested row.

  If at some point, the height of a single row changes, it should be
  requested with gtk_cell_area_get_preferred_height() again and then
  the full height of the requested rows checked again with
  gtk_cell_area_context_get_preferred_height(). *)

  external get_preferred_width :
    t ->
    Cell_area_context.t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    int * int = "ml_gtk_cell_area_get_preferred_width"
  (** Retrieves a cell area’s initial minimum and natural width.

  @area will store some geometrical information in @context along the way;
  when requesting sizes over an arbitrary number of rows, it’s not important
  to check the @minimum_width and @natural_width of this call but rather to
  consult gtk_cell_area_context_get_preferred_width() after a series of
  requests. *)

  external get_preferred_height_for_width :
    t ->
    Cell_area_context.t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    int ->
    int * int = "ml_gtk_cell_area_get_preferred_height_for_width"
  (** Retrieves a cell area’s minimum and natural height if it would be given
  the specified @width.

  @area stores some geometrical information in @context along the way
  while calling gtk_cell_area_get_preferred_width(). It’s important to
  perform a series of gtk_cell_area_get_preferred_width() requests with
  @context first and then call gtk_cell_area_get_preferred_height_for_width()
  on each cell area individually to get the height for width of each
  fully requested row.

  If at some point, the width of a single row changes, it should be
  requested with gtk_cell_area_get_preferred_width() again and then
  the full width of the requested rows checked again with
  gtk_cell_area_context_get_preferred_width(). *)

  external get_preferred_height :
    t ->
    Cell_area_context.t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    int * int = "ml_gtk_cell_area_get_preferred_height"
  (** Retrieves a cell area’s initial minimum and natural height.

  @area will store some geometrical information in @context along the way;
  when requesting sizes over an arbitrary number of rows, it’s not important
  to check the @minimum_height and @natural_height of this call but rather to
  consult gtk_cell_area_context_get_preferred_height() after a series of
  requests. *)

  external get_focus_siblings : t -> Cell_renderer.t -> Cell_renderer.t list
    = "ml_gtk_cell_area_get_focus_siblings"
  (** Gets the focus sibling cell renderers for @renderer. *)

  external get_focus_from_sibling :
    t -> Cell_renderer.t -> Cell_renderer.t option
    = "ml_gtk_cell_area_get_focus_from_sibling"
  (** Gets the `GtkCellRenderer` which is expected to be focusable
  for which @renderer is, or may be a sibling.

  This is handy for `GtkCellArea` subclasses when handling events,
  after determining the renderer at the event location it can
  then chose to activate the focus cell for which the event
  cell may have been a sibling. *)

  external get_focus_cell : t -> Cell_renderer.t option
    = "ml_gtk_cell_area_get_focus_cell"
  (** Retrieves the currently focused cell for @area *)

  external get_edited_cell : t -> Cell_renderer.t option
    = "ml_gtk_cell_area_get_edited_cell"
  (** Gets the `GtkCellRenderer` in @area that is currently
  being edited. *)

  external get_edit_widget : t -> Cell_editable.t option
    = "ml_gtk_cell_area_get_edit_widget"
  (** Gets the `GtkCellEditable` widget currently used to edit the currently
      edited cell. *)

  external get_current_path_string : t -> string
    = "ml_gtk_cell_area_get_current_path_string"
  (** Gets the current `GtkTreePath` string for the currently applied
      `GtkTreeIter`, this is implicitly updated when
      gtk_cell_area_apply_attributes() is called and can be used to interact
      with renderers from `GtkCellArea` subclasses. *)

  external get_cell_at_position :
    t ->
    Cell_area_context.t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
    int ->
    int ->
    Cell_renderer.t * Ocgtk_gdk.Gdk.Wrappers.Rectangle.t
    = "ml_gtk_cell_area_get_cell_at_position_bytecode"
      "ml_gtk_cell_area_get_cell_at_position_native"
  (** Gets the `GtkCellRenderer` at @x and @y coordinates inside @area and optionally
  returns the full cell allocation for it inside @cell_area. *)

  external get_cell_allocation :
    t ->
    Cell_area_context.t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    Cell_renderer.t ->
    Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
    Ocgtk_gdk.Gdk.Wrappers.Rectangle.t = "ml_gtk_cell_area_get_cell_allocation"
  (** Derives the allocation of @renderer inside @area if @area
  were to be rendered in @cell_area. *)

  external focus : t -> Gtk_enums.directiontype -> bool
    = "ml_gtk_cell_area_focus"
  (** This should be called by the @area’s owning layout widget
  when focus is to be passed to @area, or moved within @area
  for a given @direction and row data.

  Implementing `GtkCellArea` classes should implement this
  method to receive and navigate focus in its own way particular
  to how it lays out cells. *)

  external event :
    t ->
    Cell_area_context.t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    Ocgtk_gdk.Gdk.Wrappers.Event.t ->
    Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
    Gtk_enums.cellrendererstate ->
    int = "ml_gtk_cell_area_event_bytecode" "ml_gtk_cell_area_event_native"
  (** Delegates event handling to a `GtkCellArea`. *)

  external create_context : t -> Cell_area_context.t
    = "ml_gtk_cell_area_create_context"
  (** Creates a `GtkCellArea`Context to be used with @area for
  all purposes. `GtkCellArea`Context stores geometry information
  for rows for which it was operated on, it is important to use
  the same context for the same row of data at all times (i.e.
  one should render and handle events with the same `GtkCellArea`Context
  which was used to request the size of those rows of data). *)

  external copy_context : t -> Cell_area_context.t -> Cell_area_context.t
    = "ml_gtk_cell_area_copy_context"
  (** This is sometimes needed for cases where rows need to share alignments in
      one orientation but may be separately grouped in the opposing orientation.

      For instance, `GtkIconView` creates all icons (rows) to have the same
      width and the cells theirin to have the same horizontal alignments.
      However each row of icons may have a separate collective height.
      `GtkIconView` uses this to request the heights of each row based on a
      context which was already used to request all the row widths that are to
      be displayed. *)

  external cell_set_property :
    t -> Cell_renderer.t -> string -> Gobject.Value.t -> unit
    = "ml_gtk_cell_area_cell_set_property"
  (** Sets a cell property for @renderer in @area. *)

  external cell_get_property :
    t -> Cell_renderer.t -> string -> Gobject.Value.t -> unit
    = "ml_gtk_cell_area_cell_get_property"
  (** Gets the value of a cell property for @renderer in @area. *)

  external attribute_get_column : t -> Cell_renderer.t -> string -> int
    = "ml_gtk_cell_area_attribute_get_column"
  (** Returns the model column that an attribute has been mapped to, or -1 if
      the attribute is not mapped. *)

  external attribute_disconnect : t -> Cell_renderer.t -> string -> unit
    = "ml_gtk_cell_area_attribute_disconnect"
  (** Disconnects @attribute for the @renderer in @area so that
  attribute will no longer be updated with values from the
  model. *)

  external attribute_connect : t -> Cell_renderer.t -> string -> int -> unit
    = "ml_gtk_cell_area_attribute_connect"
  (** Connects an @attribute to apply values from @column for the
  `GtkTreeModel` in use. *)

  external apply_attributes :
    t -> Tree_model.t -> Tree_iter.t -> bool -> bool -> unit
    = "ml_gtk_cell_area_apply_attributes"
  (** Applies any connected attributes to the renderers in
  @area by pulling the values from @tree_model. *)

  external add_focus_sibling : t -> Cell_renderer.t -> Cell_renderer.t -> unit
    = "ml_gtk_cell_area_add_focus_sibling"
  (** Adds @sibling to @renderer’s focusable area, focus will be drawn
  around @renderer and all of its siblings if @renderer can
  focus for a given row.

  Events handled by focus siblings can also activate the given
  focusable @renderer. *)

  external add : t -> Cell_renderer.t -> unit = "ml_gtk_cell_area_add"
  (** Adds @renderer to @area with the default child cell properties. *)

  external activate_cell :
    t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    Cell_renderer.t ->
    Ocgtk_gdk.Gdk.Wrappers.Event.t ->
    Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
    Gtk_enums.cellrendererstate ->
    bool
    = "ml_gtk_cell_area_activate_cell_bytecode"
      "ml_gtk_cell_area_activate_cell_native"
  (** This is used by `GtkCellArea` subclasses when handling events to activate
      cells, the base `GtkCellArea` class activates cells for keyboard events
      for free in its own GtkCellArea->activate() implementation. *)

  external activate :
    t ->
    Cell_area_context.t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t ->
    Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
    Gtk_enums.cellrendererstate ->
    bool ->
    bool
    = "ml_gtk_cell_area_activate_bytecode" "ml_gtk_cell_area_activate_native"
  (** Activates @area, usually by activating the currently focused
  cell, however some subclasses which embed widgets in the area
  can also activate a widget if it currently has the focus. *)

  (* Properties *)

  let on_focus_changed ?after obj ~callback =
    let closure =
      Gobject.Closure.create (fun argv ->
          let renderer =
            let v = Gobject.Closure.nth argv ~pos:1 in
            Gobject.Value.get_object_exn v (Cell_renderer.gtype ())
          in
          let path =
            let v = Gobject.Closure.nth argv ~pos:2 in
            Gobject.Value.get_string v
          in
          callback ~renderer ~path)
    in
    Gobject.Signal.connect obj ~name:"focus-changed" ~callback:closure
      ~after:(Option.value after ~default:false)

  let on_remove_editable ?after obj ~callback =
    let closure =
      Gobject.Closure.create (fun argv ->
          let renderer =
            let v = Gobject.Closure.nth argv ~pos:1 in
            Gobject.Value.get_object_exn v (Cell_renderer.gtype ())
          in
          let editable =
            let v = Gobject.Closure.nth argv ~pos:2 in
            Gobject.Value.get_object_exn v (Cell_editable.gtype ())
          in
          callback ~renderer ~editable)
    in
    Gobject.Signal.connect obj ~name:"remove-editable" ~callback:closure
      ~after:(Option.value after ~default:false)
end

and Cell_area_context : sig
  type t = [ `cell_area_context | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gtk_cell_area_context_get_type"

  (* Methods *)

  external reset : t -> unit = "ml_gtk_cell_area_context_reset"
  (** Resets any previously cached request and allocation data.

      When underlying `GtkTreeModel` data changes its important to reset the
      context if the content size is allowed to shrink. If the content size is
      only allowed to grow (this is usually an option for views rendering large
      data stores as a measure of optimization), then only the row that changed
      or was inserted needs to be (re)requested with
      gtk_cell_area_get_preferred_width().

      When the new overall size of the context requires that the allocated size
      changes (or whenever this allocation changes at all), the variable row
      sizes need to be re-requested for every row.

      For instance, if the rows are displayed all with the same width from top
      to bottom then a change in the allocated width necessitates a
      recalculation of all the displayed row heights using
      gtk_cell_area_get_preferred_height_for_width(). *)

  external push_preferred_width : t -> int -> int -> unit
    = "ml_gtk_cell_area_context_push_preferred_width"
  (** Causes the minimum and/or natural width to grow if the new proposed sizes
      exceed the current minimum and natural width.

      This is used by `GtkCellAreaContext` implementations during the request
      process over a series of `GtkTreeModel` rows to progressively push the
      requested width over a series of gtk_cell_area_get_preferred_width()
      requests. *)

  external push_preferred_height : t -> int -> int -> unit
    = "ml_gtk_cell_area_context_push_preferred_height"
  (** Causes the minimum and/or natural height to grow if the new proposed sizes
      exceed the current minimum and natural height.

      This is used by `GtkCellAreaContext` implementations during the request
      process over a series of `GtkTreeModel` rows to progressively push the
      requested height over a series of gtk_cell_area_get_preferred_height()
      requests. *)

  external get_preferred_width_for_height : t -> int -> int * int
    = "ml_gtk_cell_area_context_get_preferred_width_for_height"
  (** Gets the accumulative preferred width for @height for all rows which
  have been requested for the same said @height with this context.

  After gtk_cell_area_context_reset() is called and/or before ever
  requesting the size of a `GtkCellArea`, the returned values are -1. *)

  external get_preferred_width : t -> int * int
    = "ml_gtk_cell_area_context_get_preferred_width"
  (** Gets the accumulative preferred width for all rows which have been
      requested with this context.

      After gtk_cell_area_context_reset() is called and/or before ever
      requesting the size of a `GtkCellArea`, the returned values are 0. *)

  external get_preferred_height_for_width : t -> int -> int * int
    = "ml_gtk_cell_area_context_get_preferred_height_for_width"
  (** Gets the accumulative preferred height for @width for all rows
  which have been requested for the same said @width with this context.

  After gtk_cell_area_context_reset() is called and/or before ever
  requesting the size of a `GtkCellArea`, the returned values are -1. *)

  external get_preferred_height : t -> int * int
    = "ml_gtk_cell_area_context_get_preferred_height"
  (** Gets the accumulative preferred height for all rows which have been
      requested with this context.

      After gtk_cell_area_context_reset() is called and/or before ever
      requesting the size of a `GtkCellArea`, the returned values are 0. *)

  external get_area : t -> Cell_area.t = "ml_gtk_cell_area_context_get_area"
  (** Fetches the `GtkCellArea` this @context was created by.

  This is generally unneeded by layouting widgets; however,
  it is important for the context implementation itself to
  fetch information about the area it is being used for.

  For instance at `GtkCellAreaContextClass.allocate()` time
  it’s important to know details about any cell spacing
  that the `GtkCellArea` is configured with in order to
  compute a proper allocation. *)

  external get_allocation : t -> int * int
    = "ml_gtk_cell_area_context_get_allocation"
  (** Fetches the current allocation size for @context.

  If the context was not allocated in width or height, or if the
  context was recently reset with gtk_cell_area_context_reset(),
  the returned value will be -1. *)

  external allocate : t -> int -> int -> unit
    = "ml_gtk_cell_area_context_allocate"
  (** Allocates a width and/or a height for all rows which are to be
  rendered with @context.

  Usually allocation is performed only horizontally or sometimes
  vertically since a group of rows are usually rendered side by
  side vertically or horizontally and share either the same width
  or the same height. Sometimes they are allocated in both horizontal
  and vertical orientations producing a homogeneous effect of the
  rows. This is generally the case for `GtkTreeView` when
  `GtkTreeView:fixed-height-mode` is enabled. *)

  (* Properties *)

  external get_minimum_height : t -> int
    = "ml_gtk_cell_area_context_get_minimum_height"
  (** Get property: minimum-height *)

  external get_minimum_width : t -> int
    = "ml_gtk_cell_area_context_get_minimum_width"
  (** Get property: minimum-width *)

  external get_natural_height : t -> int
    = "ml_gtk_cell_area_context_get_natural_height"
  (** Get property: natural-height *)

  external get_natural_width : t -> int
    = "ml_gtk_cell_area_context_get_natural_width"
  (** Get property: natural-width *)
end = struct
  type t = [ `cell_area_context | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gtk_cell_area_context_get_type"

  (* Methods *)

  external reset : t -> unit = "ml_gtk_cell_area_context_reset"
  (** Resets any previously cached request and allocation data.

      When underlying `GtkTreeModel` data changes its important to reset the
      context if the content size is allowed to shrink. If the content size is
      only allowed to grow (this is usually an option for views rendering large
      data stores as a measure of optimization), then only the row that changed
      or was inserted needs to be (re)requested with
      gtk_cell_area_get_preferred_width().

      When the new overall size of the context requires that the allocated size
      changes (or whenever this allocation changes at all), the variable row
      sizes need to be re-requested for every row.

      For instance, if the rows are displayed all with the same width from top
      to bottom then a change in the allocated width necessitates a
      recalculation of all the displayed row heights using
      gtk_cell_area_get_preferred_height_for_width(). *)

  external push_preferred_width : t -> int -> int -> unit
    = "ml_gtk_cell_area_context_push_preferred_width"
  (** Causes the minimum and/or natural width to grow if the new proposed sizes
      exceed the current minimum and natural width.

      This is used by `GtkCellAreaContext` implementations during the request
      process over a series of `GtkTreeModel` rows to progressively push the
      requested width over a series of gtk_cell_area_get_preferred_width()
      requests. *)

  external push_preferred_height : t -> int -> int -> unit
    = "ml_gtk_cell_area_context_push_preferred_height"
  (** Causes the minimum and/or natural height to grow if the new proposed sizes
      exceed the current minimum and natural height.

      This is used by `GtkCellAreaContext` implementations during the request
      process over a series of `GtkTreeModel` rows to progressively push the
      requested height over a series of gtk_cell_area_get_preferred_height()
      requests. *)

  external get_preferred_width_for_height : t -> int -> int * int
    = "ml_gtk_cell_area_context_get_preferred_width_for_height"
  (** Gets the accumulative preferred width for @height for all rows which
  have been requested for the same said @height with this context.

  After gtk_cell_area_context_reset() is called and/or before ever
  requesting the size of a `GtkCellArea`, the returned values are -1. *)

  external get_preferred_width : t -> int * int
    = "ml_gtk_cell_area_context_get_preferred_width"
  (** Gets the accumulative preferred width for all rows which have been
      requested with this context.

      After gtk_cell_area_context_reset() is called and/or before ever
      requesting the size of a `GtkCellArea`, the returned values are 0. *)

  external get_preferred_height_for_width : t -> int -> int * int
    = "ml_gtk_cell_area_context_get_preferred_height_for_width"
  (** Gets the accumulative preferred height for @width for all rows
  which have been requested for the same said @width with this context.

  After gtk_cell_area_context_reset() is called and/or before ever
  requesting the size of a `GtkCellArea`, the returned values are -1. *)

  external get_preferred_height : t -> int * int
    = "ml_gtk_cell_area_context_get_preferred_height"
  (** Gets the accumulative preferred height for all rows which have been
      requested with this context.

      After gtk_cell_area_context_reset() is called and/or before ever
      requesting the size of a `GtkCellArea`, the returned values are 0. *)

  external get_area : t -> Cell_area.t = "ml_gtk_cell_area_context_get_area"
  (** Fetches the `GtkCellArea` this @context was created by.

  This is generally unneeded by layouting widgets; however,
  it is important for the context implementation itself to
  fetch information about the area it is being used for.

  For instance at `GtkCellAreaContextClass.allocate()` time
  it’s important to know details about any cell spacing
  that the `GtkCellArea` is configured with in order to
  compute a proper allocation. *)

  external get_allocation : t -> int * int
    = "ml_gtk_cell_area_context_get_allocation"
  (** Fetches the current allocation size for @context.

  If the context was not allocated in width or height, or if the
  context was recently reset with gtk_cell_area_context_reset(),
  the returned value will be -1. *)

  external allocate : t -> int -> int -> unit
    = "ml_gtk_cell_area_context_allocate"
  (** Allocates a width and/or a height for all rows which are to be
  rendered with @context.

  Usually allocation is performed only horizontally or sometimes
  vertically since a group of rows are usually rendered side by
  side vertically or horizontally and share either the same width
  or the same height. Sometimes they are allocated in both horizontal
  and vertical orientations producing a homogeneous effect of the
  rows. This is generally the case for `GtkTreeView` when
  `GtkTreeView:fixed-height-mode` is enabled. *)

  (* Properties *)

  external get_minimum_height : t -> int
    = "ml_gtk_cell_area_context_get_minimum_height"
  (** Get property: minimum-height *)

  external get_minimum_width : t -> int
    = "ml_gtk_cell_area_context_get_minimum_width"
  (** Get property: minimum-width *)

  external get_natural_height : t -> int
    = "ml_gtk_cell_area_context_get_natural_height"
  (** Get property: natural-height *)

  external get_natural_width : t -> int
    = "ml_gtk_cell_area_context_get_natural_width"
  (** Get property: natural-width *)
end

and Cell_layout : sig
  type t = [ `cell_layout ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gtk_cell_layout_get_type"

  external from_gobject : 'a Gobject.obj -> t
    = "ml_gtk_cell_layout_from_gobject"

  (* Methods *)

  external reorder : t -> Cell_renderer.t -> int -> unit
    = "ml_gtk_cell_layout_reorder"
  (** Re-inserts @cell at @position.

  Note that @cell has already to be packed into @cell_layout
  for this to function properly. *)

  external pack_start : t -> Cell_renderer.t -> bool -> unit
    = "ml_gtk_cell_layout_pack_start"
  (** Packs the @cell into the beginning of @cell_layout. If @expand is %FALSE,
  then the @cell is allocated no more space than it needs. Any unused space
  is divided evenly between cells for which @expand is %TRUE.

  Note that reusing the same cell renderer is not supported. *)

  external pack_end : t -> Cell_renderer.t -> bool -> unit
    = "ml_gtk_cell_layout_pack_end"
  (** Adds the @cell to the end of @cell_layout. If @expand is %FALSE, then the
  @cell is allocated no more space than it needs. Any unused space is
  divided evenly between cells for which @expand is %TRUE.

  Note that reusing the same cell renderer is not supported. *)

  external get_cells : t -> Cell_renderer.t list
    = "ml_gtk_cell_layout_get_cells"
  (** Returns the cell renderers which have been added to @cell_layout. *)

  external get_area : t -> Cell_area.t option = "ml_gtk_cell_layout_get_area"
  (** Returns the underlying `GtkCellArea` which might be @cell_layout
  if called on a `GtkCellArea` or might be %NULL if no `GtkCellArea`
  is used by @cell_layout. *)

  external clear_attributes : t -> Cell_renderer.t -> unit
    = "ml_gtk_cell_layout_clear_attributes"
  (** Clears all existing attributes previously set with
      gtk_cell_layout_set_attributes(). *)

  external clear : t -> unit = "ml_gtk_cell_layout_clear"
  (** Unsets all the mappings on all renderers on @cell_layout and
  removes all renderers from @cell_layout. *)

  external add_attribute : t -> Cell_renderer.t -> string -> int -> unit
    = "ml_gtk_cell_layout_add_attribute"
  (** Adds an attribute mapping to the list in @cell_layout.

  The @column is the column of the model to get a value from, and the
  @attribute is the property on @cell to be set from that value. So for
  example if column 2 of the model contains strings, you could have the
  “text” attribute of a `GtkCellRendererText` get its values from column 2.
  In this context "attribute" and "property" are used interchangeably. *)
end = struct
  type t = [ `cell_layout ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gtk_cell_layout_get_type"

  external from_gobject : 'a Gobject.obj -> t
    = "ml_gtk_cell_layout_from_gobject"

  (* Methods *)

  external reorder : t -> Cell_renderer.t -> int -> unit
    = "ml_gtk_cell_layout_reorder"
  (** Re-inserts @cell at @position.

  Note that @cell has already to be packed into @cell_layout
  for this to function properly. *)

  external pack_start : t -> Cell_renderer.t -> bool -> unit
    = "ml_gtk_cell_layout_pack_start"
  (** Packs the @cell into the beginning of @cell_layout. If @expand is %FALSE,
  then the @cell is allocated no more space than it needs. Any unused space
  is divided evenly between cells for which @expand is %TRUE.

  Note that reusing the same cell renderer is not supported. *)

  external pack_end : t -> Cell_renderer.t -> bool -> unit
    = "ml_gtk_cell_layout_pack_end"
  (** Adds the @cell to the end of @cell_layout. If @expand is %FALSE, then the
  @cell is allocated no more space than it needs. Any unused space is
  divided evenly between cells for which @expand is %TRUE.

  Note that reusing the same cell renderer is not supported. *)

  external get_cells : t -> Cell_renderer.t list
    = "ml_gtk_cell_layout_get_cells"
  (** Returns the cell renderers which have been added to @cell_layout. *)

  external get_area : t -> Cell_area.t option = "ml_gtk_cell_layout_get_area"
  (** Returns the underlying `GtkCellArea` which might be @cell_layout
  if called on a `GtkCellArea` or might be %NULL if no `GtkCellArea`
  is used by @cell_layout. *)

  external clear_attributes : t -> Cell_renderer.t -> unit
    = "ml_gtk_cell_layout_clear_attributes"
  (** Clears all existing attributes previously set with
      gtk_cell_layout_set_attributes(). *)

  external clear : t -> unit = "ml_gtk_cell_layout_clear"
  (** Unsets all the mappings on all renderers on @cell_layout and
  removes all renderers from @cell_layout. *)

  external add_attribute : t -> Cell_renderer.t -> string -> int -> unit
    = "ml_gtk_cell_layout_add_attribute"
  (** Adds an attribute mapping to the list in @cell_layout.

  The @column is the column of the model to get a value from, and the
  @attribute is the property on @cell to be set from that value. So for
  example if column 2 of the model contains strings, you could have the
  “text” attribute of a `GtkCellRendererText` get its values from column 2.
  In this context "attribute" and "property" are used interchangeably. *)
end
