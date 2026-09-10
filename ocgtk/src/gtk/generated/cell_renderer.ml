(* GENERATED CODE - DO NOT EDIT *)
(* CellRenderer: CellRenderer *)

type t = [ `cell_renderer | `initially_unowned | `object_ ] Gobject.obj

(* Methods *)

external stop_editing : t -> bool -> unit = "ml_gtk_cell_renderer_stop_editing"
(** Informs the cell renderer that the editing is stopped.
If @canceled is %TRUE, the cell renderer will emit the
`GtkCellRenderer`::editing-canceled signal.

This function should be called by cell renderer implementations
in response to the `GtkCellEditable::editing-done` signal of
`GtkCellEditable`. *)

external start_editing :
  t ->
  Ocgtk_gdk.Gdk.Wrappers.Event.t option ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  string ->
  Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
  Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
  Gtk_enums.cellrendererstate ->
  Cell_editable.t option
  = "ml_gtk_cell_renderer_start_editing_bytecode"
    "ml_gtk_cell_renderer_start_editing_native"
(** Starts editing the contents of this @cell, through a new `GtkCellEditable`
widget created by the `GtkCellRenderer`Class.start_editing virtual function. *)

external snapshot :
  t ->
  Snapshot.t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
  Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
  Gtk_enums.cellrendererstate ->
  unit
  = "ml_gtk_cell_renderer_snapshot_bytecode"
    "ml_gtk_cell_renderer_snapshot_native"
(** Invokes the virtual render function of the `GtkCellRenderer`. The three
passed-in rectangles are areas in @cr. Most renderers will draw within
@cell_area; the xalign, yalign, xpad, and ypad fields of the `GtkCellRenderer`
should be honored with respect to @cell_area. @background_area includes the
blank space around the cell, and also the area containing the tree expander;
so the @background_area rectangles for all cells tile to cover the entire
@window. *)

external set_visible : t -> bool -> unit = "ml_gtk_cell_renderer_set_visible"
(** Sets the cell renderer’s visibility. *)

external set_sensitive : t -> bool -> unit
  = "ml_gtk_cell_renderer_set_sensitive"
(** Sets the cell renderer’s sensitivity. *)

external set_padding : t -> int -> int -> unit
  = "ml_gtk_cell_renderer_set_padding"
(** Sets the renderer’s padding. *)

external set_is_expander : t -> bool -> unit
  = "ml_gtk_cell_renderer_set_is_expander"
(** Sets whether the given `GtkCellRenderer` is an expander. *)

external set_is_expanded : t -> bool -> unit
  = "ml_gtk_cell_renderer_set_is_expanded"
(** Sets whether the given `GtkCellRenderer` is expanded. *)

external set_fixed_size : t -> int -> int -> unit
  = "ml_gtk_cell_renderer_set_fixed_size"
(** Sets the renderer size to be explicit, independent of the properties set. *)

external set_alignment : t -> float -> float -> unit
  = "ml_gtk_cell_renderer_set_alignment"
(** Sets the renderer’s alignment within its available space. *)

external is_activatable : t -> bool = "ml_gtk_cell_renderer_is_activatable"
(** Checks whether the cell renderer can do something when activated. *)

external get_visible : t -> bool = "ml_gtk_cell_renderer_get_visible"
(** Returns the cell renderer’s visibility. *)

external get_state :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  Gtk_enums.cellrendererstate ->
  Gtk_enums.stateflags = "ml_gtk_cell_renderer_get_state"
(** Translates the cell renderer state to `GtkStateFlags`, based on the cell
    renderer and widget sensitivity, and the given `GtkCellRenderer`State. *)

external get_sensitive : t -> bool = "ml_gtk_cell_renderer_get_sensitive"
(** Returns the cell renderer’s sensitivity. *)

external get_request_mode : t -> Gtk_enums.sizerequestmode
  = "ml_gtk_cell_renderer_get_request_mode"
(** Gets whether the cell renderer prefers a height-for-width layout or a
    width-for-height layout. *)

external get_preferred_width_for_height :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  int ->
  int * int = "ml_gtk_cell_renderer_get_preferred_width_for_height"
(** Retrieves a cell renderers’s minimum and natural width if it were rendered to
@widget with the specified @height. *)

external get_preferred_width :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  int * int = "ml_gtk_cell_renderer_get_preferred_width"
(** Retrieves a renderer’s natural size when rendered to @widget. *)

external get_preferred_size :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Requisition.t * Requisition.t = "ml_gtk_cell_renderer_get_preferred_size"
(** Retrieves the minimum and natural size of a cell taking into account the
    widget’s preference for height-for-width management. *)

external get_preferred_height_for_width :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  int ->
  int * int = "ml_gtk_cell_renderer_get_preferred_height_for_width"
(** Retrieves a cell renderers’s minimum and natural height if it were rendered to
@widget with the specified @width. *)

external get_preferred_height :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  int * int = "ml_gtk_cell_renderer_get_preferred_height"
(** Retrieves a renderer’s natural size when rendered to @widget. *)

external get_padding : t -> int * int = "ml_gtk_cell_renderer_get_padding"
(** Fills in @xpad and @ypad with the appropriate values of @cell. *)

external get_is_expander : t -> bool = "ml_gtk_cell_renderer_get_is_expander"
(** Checks whether the given `GtkCellRenderer` is an expander. *)

external get_is_expanded : t -> bool = "ml_gtk_cell_renderer_get_is_expanded"
(** Checks whether the given `GtkCellRenderer` is expanded. *)

external get_fixed_size : t -> int * int = "ml_gtk_cell_renderer_get_fixed_size"
(** Fills in @width and @height with the appropriate size of @cell. *)

external get_alignment : t -> float * float
  = "ml_gtk_cell_renderer_get_alignment"
(** Fills in @xalign and @yalign with the appropriate values of @cell. *)

external get_aligned_area :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Gtk_enums.cellrendererstate ->
  Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
  Ocgtk_gdk.Gdk.Wrappers.Rectangle.t = "ml_gtk_cell_renderer_get_aligned_area"
(** Gets the aligned area used by @cell inside @cell_area. Used for finding
the appropriate edit and focus rectangle. *)

external activate :
  t ->
  Ocgtk_gdk.Gdk.Wrappers.Event.t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  string ->
  Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
  Ocgtk_gdk.Gdk.Wrappers.Rectangle.t ->
  Gtk_enums.cellrendererstate ->
  bool
  = "ml_gtk_cell_renderer_activate_bytecode"
    "ml_gtk_cell_renderer_activate_native"
(** Passes an activate event to the cell renderer for possible processing. Some
    cell renderers may use events; for example, `GtkCellRendererToggle` toggles
    when it gets a mouse click. *)

(* Properties *)

external set_cell_background : t -> string -> unit
  = "ml_gtk_cell_renderer_set_cell_background"
(** Set property: cell-background *)

external get_cell_background_rgba : t -> Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t
  = "ml_gtk_cell_renderer_get_cell_background_rgba"
(** Get property: cell-background-rgba *)

external set_cell_background_rgba : t -> Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t -> unit
  = "ml_gtk_cell_renderer_set_cell_background_rgba"
(** Set property: cell-background-rgba *)

external get_cell_background_set : t -> bool
  = "ml_gtk_cell_renderer_get_cell_background_set"
(** Get property: cell-background-set *)

external set_cell_background_set : t -> bool -> unit
  = "ml_gtk_cell_renderer_set_cell_background_set"
(** Set property: cell-background-set *)

external get_editing : t -> bool = "ml_gtk_cell_renderer_get_editing"
(** Get property: editing *)

external get_height : t -> int = "ml_gtk_cell_renderer_get_height"
(** Get property: height *)

external set_height : t -> int -> unit = "ml_gtk_cell_renderer_set_height"
(** Set property: height *)

external get_mode : t -> Gtk_enums.cellrenderermode
  = "ml_gtk_cell_renderer_get_mode"
(** Get property: mode *)

external set_mode : t -> Gtk_enums.cellrenderermode -> unit
  = "ml_gtk_cell_renderer_set_mode"
(** Set property: mode *)

external get_width : t -> int = "ml_gtk_cell_renderer_get_width"
(** Get property: width *)

external set_width : t -> int -> unit = "ml_gtk_cell_renderer_set_width"
(** Set property: width *)

external get_xalign : t -> float = "ml_gtk_cell_renderer_get_xalign"
(** Get property: xalign *)

external set_xalign : t -> float -> unit = "ml_gtk_cell_renderer_set_xalign"
(** Set property: xalign *)

external get_xpad : t -> int = "ml_gtk_cell_renderer_get_xpad"
(** Get property: xpad *)

external set_xpad : t -> int -> unit = "ml_gtk_cell_renderer_set_xpad"
(** Set property: xpad *)

external get_yalign : t -> float = "ml_gtk_cell_renderer_get_yalign"
(** Get property: yalign *)

external set_yalign : t -> float -> unit = "ml_gtk_cell_renderer_set_yalign"
(** Set property: yalign *)

external get_ypad : t -> int = "ml_gtk_cell_renderer_get_ypad"
(** Get property: ypad *)

external set_ypad : t -> int -> unit = "ml_gtk_cell_renderer_set_ypad"
(** Set property: ypad *)

let on_editing_canceled ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"editing-canceled" ~callback
    ~after:(Option.value after ~default:false)

let on_editing_started ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let editable =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
        in
        let path =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_string_exn v
        in
        callback ~editable ~path)
  in
  Gobject.Signal.connect obj ~name:"editing-started" ~callback:closure
    ~after:(Option.value after ~default:false)
