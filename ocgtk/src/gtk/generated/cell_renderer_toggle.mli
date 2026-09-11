(* GENERATED CODE - DO NOT EDIT *)
(* CellRendererToggle: CellRendererToggle *)

type t =
  [ `cell_renderer_toggle | `cell_renderer | `initially_unowned | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_cell_renderer_toggle_get_type"

external new_ : unit -> t = "ml_gtk_cell_renderer_toggle_new"
(** Create a new CellRendererToggle *)

(* Methods *)

external set_radio : t -> bool -> unit = "ml_gtk_cell_renderer_toggle_set_radio"
(** If @radio is %TRUE, the cell renderer renders a radio toggle
(i.e. a toggle in a group of mutually-exclusive toggles).
If %FALSE, it renders a check toggle (a standalone boolean option).
This can be set globally for the cell renderer, or changed just
before rendering each cell in the model (for `GtkTreeView`, you set
up a per-row setting using `GtkTreeViewColumn` to associate model
columns with cell renderer properties). *)

external set_active : t -> bool -> unit
  = "ml_gtk_cell_renderer_toggle_set_active"
(** Activates or deactivates a cell renderer. *)

external set_activatable : t -> bool -> unit
  = "ml_gtk_cell_renderer_toggle_set_activatable"
(** Makes the cell renderer activatable. *)

external get_radio : t -> bool = "ml_gtk_cell_renderer_toggle_get_radio"
(** Returns whether we’re rendering radio toggles rather than checkboxes. *)

external get_active : t -> bool = "ml_gtk_cell_renderer_toggle_get_active"
(** Returns whether the cell renderer is active. See
    gtk_cell_renderer_toggle_set_active(). *)

external get_activatable : t -> bool
  = "ml_gtk_cell_renderer_toggle_get_activatable"
(** Returns whether the cell renderer is activatable. See
    gtk_cell_renderer_toggle_set_activatable(). *)

(* Properties *)

external get_inconsistent : t -> bool
  = "ml_gtk_cell_renderer_toggle_get_inconsistent"
(** Get property: inconsistent *)

external set_inconsistent : t -> bool -> unit
  = "ml_gtk_cell_renderer_toggle_set_inconsistent"
(** Set property: inconsistent *)

val on_toggled :
  ?after:bool ->
  t ->
  callback:(path:string -> unit) ->
  Gobject.Signal.handler_id
