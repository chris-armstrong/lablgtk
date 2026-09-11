(* GENERATED CODE - DO NOT EDIT *)
(* FlowBoxChild: FlowBoxChild *)

type t =
  [ `flow_box_child | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_flow_box_child_get_type"

external new_ : unit -> t = "ml_gtk_flow_box_child_new"
(** Create a new FlowBoxChild *)

(* Methods *)

external set_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_flow_box_child_set_child"
(** Sets the child widget of @self. *)

external is_selected : t -> bool = "ml_gtk_flow_box_child_is_selected"
(** Returns whether the @child is currently selected in its
`GtkFlowBox` container. *)

external get_index : t -> int = "ml_gtk_flow_box_child_get_index"
(** Gets the current index of the @child in its `GtkFlowBox` container. *)

external get_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_flow_box_child_get_child"
(** Gets the child widget of @self. *)

external changed : t -> unit = "ml_gtk_flow_box_child_changed"
(** Marks @child as changed, causing any state that depends on this
to be updated.

This affects sorting and filtering.

Note that calls to this method must be in sync with the data
used for the sorting and filtering functions. For instance, if
the list is mirroring some external data set, and *two* children
changed in the external data set when you call
gtk_flow_box_child_changed() on the first child, the sort function
must only read the new data for the first of the two changed
children, otherwise the resorting of the children will be wrong.

This generally means that if you don’t fully control the data
model, you have to duplicate the data that affects the sorting
and filtering functions into the widgets themselves.

Another alternative is to call [method@Gtk.FlowBox.invalidate_sort]
on any model change, but that is more expensive. *)

(* Properties *)

val on_activate :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
