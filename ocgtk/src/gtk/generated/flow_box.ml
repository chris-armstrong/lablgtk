(* GENERATED CODE - DO NOT EDIT *)
(* FlowBox: FlowBox *)

type t = [ `flow_box | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_flow_box_get_type"

external new_ : unit -> t = "ml_gtk_flow_box_new"
(** Create a new FlowBox *)

(* Methods *)

external unselect_child : t -> Flow_box_child.t -> unit
  = "ml_gtk_flow_box_unselect_child"
(** Unselects a single child of @box, if the selection
mode allows it. *)

external unselect_all : t -> unit = "ml_gtk_flow_box_unselect_all"
(** Unselect all children of @box, if the selection
mode allows it. *)

external set_vadjustment : t -> Adjustment.t -> unit
  = "ml_gtk_flow_box_set_vadjustment"
(** Hooks up an adjustment to focus handling in @box.

The adjustment is also used for autoscrolling during
rubberband selection. See [method@Gtk.ScrolledWindow.get_vadjustment]
for a typical way of obtaining the adjustment, and
[method@Gtk.FlowBox.set_hadjustment] for setting the horizontal
adjustment.

The adjustments have to be in pixel units and in the same
coordinate system as the allocation for immediate children
of the box. *)

external set_selection_mode : t -> Gtk_enums.selectionmode -> unit
  = "ml_gtk_flow_box_set_selection_mode"
(** Sets how selection works in @box. *)

external set_row_spacing : t -> int -> unit = "ml_gtk_flow_box_set_row_spacing"
(** Sets the vertical space to add between children. *)

external set_min_children_per_line : t -> int -> unit
  = "ml_gtk_flow_box_set_min_children_per_line"
(** Sets the minimum number of children to line up
in @box’s orientation before flowing. *)

external set_max_children_per_line : t -> int -> unit
  = "ml_gtk_flow_box_set_max_children_per_line"
(** Sets the maximum number of children to request and
allocate space for in @box’s orientation.

Setting the maximum number of children per line
limits the overall natural size request to be no more
than @n_children children long in the given orientation. *)

external set_homogeneous : t -> bool -> unit = "ml_gtk_flow_box_set_homogeneous"
(** Sets whether or not all children of @box are given
equal space in the box. *)

external set_hadjustment : t -> Adjustment.t -> unit
  = "ml_gtk_flow_box_set_hadjustment"
(** Hooks up an adjustment to focus handling in @box.

The adjustment is also used for autoscrolling during
rubberband selection. See [method@Gtk.ScrolledWindow.get_hadjustment]
for a typical way of obtaining the adjustment, and
[method@Gtk.FlowBox.set_vadjustment] for setting the vertical
adjustment.

The adjustments have to be in pixel units and in the same
coordinate system as the allocation for immediate children
of the box. *)

external set_column_spacing : t -> int -> unit
  = "ml_gtk_flow_box_set_column_spacing"
(** Sets the horizontal space to add between children. *)

external set_activate_on_single_click : t -> bool -> unit
  = "ml_gtk_flow_box_set_activate_on_single_click"
(** If @single is %TRUE, children will be activated when you click
on them, otherwise you need to double-click. *)

external select_child : t -> Flow_box_child.t -> unit
  = "ml_gtk_flow_box_select_child"
(** Selects a single child of @box, if the selection
mode allows it. *)

external select_all : t -> unit = "ml_gtk_flow_box_select_all"
(** Select all children of @box, if the selection
mode allows it. *)

external remove_all : t -> unit = "ml_gtk_flow_box_remove_all"
(** Removes all children from @box.

This function does nothing if @box is backed by a model. *)

external remove :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  unit = "ml_gtk_flow_box_remove"
(** Removes a child from @box. *)

external prepend :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  unit = "ml_gtk_flow_box_prepend"
(** Adds @child to the start of @self.

If a sort function is set, the widget will
actually be inserted at the calculated position.

See also: [method@Gtk.FlowBox.insert]. *)

external invalidate_sort : t -> unit = "ml_gtk_flow_box_invalidate_sort"
(** Updates the sorting for all children.

Call this when the result of the sort function on
@box is changed due to an external factor. *)

external invalidate_filter : t -> unit = "ml_gtk_flow_box_invalidate_filter"
(** Updates the filtering for all children.

Call this function when the result of the filter
function on the @box is changed due to an external
factor. For instance, this would be used if the
filter function just looked for a specific search
term, and the entry with the string has changed. *)

external insert :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  int ->
  unit = "ml_gtk_flow_box_insert"
(** Inserts the @widget into @box at @position.

If a sort function is set, the widget will actually be inserted
at the calculated position.

If @position is -1, or larger than the total number of children
in the @box, then the @widget will be appended to the end. *)

external get_selection_mode : t -> Gtk_enums.selectionmode
  = "ml_gtk_flow_box_get_selection_mode"
(** Gets the selection mode of @box. *)

external get_selected_children : t -> Flow_box_child.t list
  = "ml_gtk_flow_box_get_selected_children"
(** Creates a list of all selected children. *)

external get_row_spacing : t -> int = "ml_gtk_flow_box_get_row_spacing"
(** Gets the vertical spacing. *)

external get_min_children_per_line : t -> int
  = "ml_gtk_flow_box_get_min_children_per_line"
(** Gets the minimum number of children per line. *)

external get_max_children_per_line : t -> int
  = "ml_gtk_flow_box_get_max_children_per_line"
(** Gets the maximum number of children per line. *)

external get_homogeneous : t -> bool = "ml_gtk_flow_box_get_homogeneous"
(** Returns whether the box is homogeneous. *)

external get_column_spacing : t -> int = "ml_gtk_flow_box_get_column_spacing"
(** Gets the horizontal spacing. *)

external get_child_at_pos : t -> int -> int -> Flow_box_child.t option
  = "ml_gtk_flow_box_get_child_at_pos"
(** Gets the child in the (@x, @y) position.

Both @x and @y are assumed to be relative to the origin of @box. *)

external get_child_at_index : t -> int -> Flow_box_child.t option
  = "ml_gtk_flow_box_get_child_at_index"
(** Gets the nth child in the @box. *)

external get_activate_on_single_click : t -> bool
  = "ml_gtk_flow_box_get_activate_on_single_click"
(** Returns whether children activate on single clicks. *)

external append :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  unit = "ml_gtk_flow_box_append"
(** Adds @child to the end of @self.

If a sort function is set, the widget will
actually be inserted at the calculated position.

See also: [method@Gtk.FlowBox.insert]. *)

(* Properties *)

external get_accept_unpaired_release : t -> bool
  = "ml_gtk_flow_box_get_accept_unpaired_release"
(** Get property: accept-unpaired-release *)

external set_accept_unpaired_release : t -> bool -> unit
  = "ml_gtk_flow_box_set_accept_unpaired_release"
(** Set property: accept-unpaired-release *)

let on_activate_cursor_child ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"activate-cursor-child" ~callback
    ~after:(Option.value after ~default:false)

let on_child_activated ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let child =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v (Flow_box_child.gtype ())
        in
        callback ~child)
  in
  Gobject.Signal.connect obj ~name:"child-activated" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_move_cursor ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let step =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gtk_enums.movementstep_of_int (Gobject.Value.get_enum_int v)
        in
        let count =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_int v
        in
        let extend =
          let v = Gobject.Closure.nth argv ~pos:3 in
          Gobject.Value.get_boolean v
        in
        let modify =
          let v = Gobject.Closure.nth argv ~pos:4 in
          Gobject.Value.get_boolean v
        in
        let result = callback ~step ~count ~extend ~modify in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"move-cursor" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_select_all ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"select-all" ~callback
    ~after:(Option.value after ~default:false)

let on_selected_children_changed ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"selected-children-changed" ~callback
    ~after:(Option.value after ~default:false)

let on_toggle_cursor_child ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"toggle-cursor-child" ~callback
    ~after:(Option.value after ~default:false)

let on_unselect_all ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"unselect-all" ~callback
    ~after:(Option.value after ~default:false)
