(* GENERATED CODE - DO NOT EDIT *)
(* CellEditable: CellEditable *)

type t = [ `cell_editable ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_cell_editable_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gtk_cell_editable_from_gobject"

(* Methods *)

external start_editing : t -> Ocgtk_gdk.Gdk.Wrappers.Event.t option -> unit
  = "ml_gtk_cell_editable_start_editing"
(** Begins editing on a @cell_editable.

The `GtkCellRenderer` for the cell creates and returns a `GtkCellEditable` from
gtk_cell_renderer_start_editing(), configured for the `GtkCellRenderer` type.

gtk_cell_editable_start_editing() can then set up @cell_editable suitably for
editing a cell, e.g. making the Esc key emit `GtkCellEditable::editing-done`.

Note that the @cell_editable is created on-demand for the current edit; its
lifetime is temporary and does not persist across other edits and/or cells. *)

external remove_widget : t -> unit = "ml_gtk_cell_editable_remove_widget"
(** Emits the `GtkCellEditable::remove-widget` signal. *)

external editing_done : t -> unit = "ml_gtk_cell_editable_editing_done"
(** Emits the `GtkCellEditable::editing-done` signal. *)

(* Properties *)

external get_editing_canceled : t -> bool
  = "ml_gtk_cell_editable_get_editing_canceled"
(** Get property: editing-canceled *)

external set_editing_canceled : t -> bool -> unit
  = "ml_gtk_cell_editable_set_editing_canceled"
(** Set property: editing-canceled *)

val on_editing_done :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_remove_widget :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
